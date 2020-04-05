#include <yaml.h>
#include <errno.h>
#include "kube_config_yaml.h"

/*
A valid sequence of events should obey the grammar :

stream :: = STREAM - START document * STREAM - END
document :: = DOCUMENT - START node DOCUMENT - END
node :: = ALIAS | SCALAR | sequence | mapping
sequence :: = SEQUENCE - START node * SEQUENCE - END
mapping :: = MAPPING - START(node node) * MAPPING - END
*/

#define KEY_APIVERSION "apiVersion"
#define KEY_KIND "kind"
#define KEY_CURRENT_CONTEXT "current-context"
#define KEY_CLUSTERS "clusters"
#define KEY_CLUSTER "cluster"
#define KEY_CONTEXTS "contexts"
#define KEY_USERS "users"
#define KEY_USER "user"
#define KEY_NAME "name"
#define KEY_CERTIFICATE_AUTHORITY_DATA "certificate-authority-data"
#define KEY_SERVER "server"
#define KEY_CLIENT_CERTIFICATE_DATA "client-certificate-data"
#define KEY_CLIENT_KEY_DATA "client-key-data"

static int parse_kubeconfig_yaml_userinfo_mapping(kubeconfig_user_t * user, yaml_document_t * document, yaml_node_t * node)
{
    static char fname[] = "parse_kubeconfig_yaml_userinfo_mapping()";

    yaml_node_pair_t *pair = NULL;
    yaml_node_t *key = NULL;
    yaml_node_t *value = NULL;

    for (pair = node->data.mapping.pairs.start; pair < node->data.mapping.pairs.top; pair++) {
        key = yaml_document_get_node(document, pair->key);
        value = yaml_document_get_node(document, pair->value);

        if (key->type != YAML_SCALAR_NODE) {
            fprintf(stderr, "%s: The key node is not YAML_SCALAR_NODE.\n", fname);
            return -1;
        }

        if (value->type == YAML_SCALAR_NODE) {
            if (0 == strcmp(key->data.scalar.value, KEY_CLIENT_CERTIFICATE_DATA)) {
                user->client_certificate_data = strdup(value->data.scalar.value);
            } else if (0 == strcmp(key->data.scalar.value, KEY_CLIENT_KEY_DATA)) {
                user->client_key_data = strdup(value->data.scalar.value);
            }
        }
    }

    return 0;
}

static int parse_kubeconfig_yaml_user_mapping(kubeconfig_user_t * user, yaml_document_t * document, yaml_node_t * node)
{
    static char fname[] = "parse_kubeconfig_yaml_user_mapping()";
    int rc = 0;

    yaml_node_pair_t *pair = NULL;
    yaml_node_t *key = NULL;
    yaml_node_t *value = NULL;

    for (pair = node->data.mapping.pairs.start; pair < node->data.mapping.pairs.top; pair++) {
        key = yaml_document_get_node(document, pair->key);
        value = yaml_document_get_node(document, pair->value);

        if (key->type != YAML_SCALAR_NODE) {
            fprintf(stderr, "%s: The key node is not YAML_SCALAR_NODE.\n", fname);
            return -1;
        }

        if (value->type == YAML_SCALAR_NODE) {
            if (0 == strcmp(key->data.scalar.value, KEY_NAME)) {
                user->name = strdup(value->data.scalar.value);
            }
        } else if (value->type == YAML_MAPPING_NODE) {
            rc = parse_kubeconfig_yaml_userinfo_mapping(user, document, value);
        }
    }

    return rc;
}

static int parse_kubeconfig_yaml_users_sequence(kubeconfig_t * kubeconfig, yaml_document_t * document, yaml_node_t * node)
{
    int rc = 0;

    yaml_node_item_t *item = NULL;
    yaml_node_t *value = NULL;
    int item_count = 0;
    int i = 0;

    // Get the count of users
    for (item = node->data.sequence.items.start, item_count = 0; item < node->data.sequence.items.top; item++, item_count++) {
        ;
    }

    kubeconfig->users_count = item_count;
    kubeconfig->users = kubeconfig_users_create(kubeconfig->users_count);

    for (item = node->data.sequence.items.start, i = 0; item < node->data.sequence.items.top; item++, i++) {
        value = yaml_document_get_node(document, *item);
        rc = parse_kubeconfig_yaml_user_mapping(kubeconfig->users[i], document, value);
    }

    return rc;

}

static int parse_kubeconfig_yaml_contextinfo_mapping(kubeconfig_context_t * context, yaml_document_t * document, yaml_node_t * node)
{
    static char fname[] = "parse_kubeconfig_yaml_contextinfo_mapping()";

    yaml_node_pair_t *pair = NULL;
    yaml_node_t *key = NULL;
    yaml_node_t *value = NULL;

    for (pair = node->data.mapping.pairs.start; pair < node->data.mapping.pairs.top; pair++) {
        key = yaml_document_get_node(document, pair->key);
        value = yaml_document_get_node(document, pair->value);

        if (key->type != YAML_SCALAR_NODE) {
            fprintf(stderr, "%s: The key node is not YAML_SCALAR_NODE.\n", fname);
            return -1;
        }

        if (value->type == YAML_SCALAR_NODE) {
            if (0 == strcmp(key->data.scalar.value, KEY_CLUSTER)) {
                context->cluster = strdup(value->data.scalar.value);
            } else if (0 == strcmp(key->data.scalar.value, KEY_USER)) {
                context->user = strdup(value->data.scalar.value);
            }
        }
    }

    return 0;
}

static int parse_kubeconfig_yaml_context_mapping(kubeconfig_context_t * context, yaml_document_t * document, yaml_node_t * node)
{
    static char fname[] = "parse_kubeconfig_yaml_context_mapping()";
    int rc = 0;

    yaml_node_pair_t *pair = NULL;
    yaml_node_t *key = NULL;
    yaml_node_t *value = NULL;

    for (pair = node->data.mapping.pairs.start; pair < node->data.mapping.pairs.top; pair++) {
        key = yaml_document_get_node(document, pair->key);
        value = yaml_document_get_node(document, pair->value);

        if (key->type != YAML_SCALAR_NODE) {
            fprintf(stderr, "%s: The key node is not YAML_SCALAR_NODE.\n", fname);
            return -1;
        }

        if (value->type == YAML_SCALAR_NODE) {
            if (0 == strcmp(key->data.scalar.value, KEY_NAME)) {
                context->name = strdup(value->data.scalar.value);
            }
        } else if (value->type == YAML_MAPPING_NODE) {
            rc = parse_kubeconfig_yaml_contextinfo_mapping(context, document, value);
        }
    }

    return rc;
}

static int parse_kubeconfig_yaml_contexts_sequence(kubeconfig_t * kubeconfig, yaml_document_t * document, yaml_node_t * node)
{
    int rc = 0;
    yaml_node_item_t *item = NULL;
    yaml_node_t *value = NULL;
    int item_count = 0;
    int i = 0;

    // Get the count of contexts
    for (item = node->data.sequence.items.start, item_count = 0; item < node->data.sequence.items.top; item++, item_count++) {
        ;
    }

    kubeconfig->contexts_count = item_count;
    kubeconfig->contexts = kubeconfig_contexts_create(kubeconfig->contexts_count);

    for (item = node->data.sequence.items.start, i = 0; item < node->data.sequence.items.top; item++, i++) {
        value = yaml_document_get_node(document, *item);
        rc = parse_kubeconfig_yaml_context_mapping(kubeconfig->contexts[i], document, value);
    }

    return rc;

}

static int parse_kubeconfig_yaml_clusterinfo_mapping(kubeconfig_cluster_t * cluster, yaml_document_t * document, yaml_node_t * node)
{
    static char fname[] = "parse_kubeconfig_yaml_clusterinfo_mapping()";

    yaml_node_pair_t *pair = NULL;
    yaml_node_t *key = NULL;
    yaml_node_t *value = NULL;

    for (pair = node->data.mapping.pairs.start; pair < node->data.mapping.pairs.top; pair++) {
        key = yaml_document_get_node(document, pair->key);
        value = yaml_document_get_node(document, pair->value);

        if (key->type != YAML_SCALAR_NODE) {
            fprintf(stderr, "%s: The key node is not YAML_SCALAR_NODE.\n", fname);
            return -1;
        }

        if (value->type == YAML_SCALAR_NODE) {
            if (0 == strcmp(key->data.scalar.value, KEY_CERTIFICATE_AUTHORITY_DATA)) {
                cluster->certificate_authority_data = strdup(value->data.scalar.value);
            } else if (0 == strcmp(key->data.scalar.value, KEY_SERVER)) {
                cluster->server = strdup(value->data.scalar.value);
            }
        }
    }

    return 0;
}

static int parse_kubeconfig_yaml_cluster_mapping(kubeconfig_cluster_t * cluster, yaml_document_t * document, yaml_node_t * node)
{
    static char fname[] = "parse_kubeconfig_yaml_cluster_mapping()";
    int rc = 0;

    yaml_node_pair_t *pair = NULL;
    yaml_node_t *key = NULL;
    yaml_node_t *value = NULL;

    for (pair = node->data.mapping.pairs.start; pair < node->data.mapping.pairs.top; pair++) {
        key = yaml_document_get_node(document, pair->key);
        value = yaml_document_get_node(document, pair->value);

        if (key->type != YAML_SCALAR_NODE) {
            fprintf(stderr, "%s: The key node is not YAML_SCALAR_NODE.\n", fname);
            return -1;
        }

        if (value->type == YAML_SCALAR_NODE) {
            if (0 == strcmp(key->data.scalar.value, KEY_NAME)) {
                cluster->name = strdup(value->data.scalar.value);
            }
        } else if (value->type == YAML_MAPPING_NODE) {
            rc = parse_kubeconfig_yaml_clusterinfo_mapping(cluster, document, value);
        }
    }

    return rc;
}

static int parse_kubeconfig_yaml_clusters_sequence(kubeconfig_t * kubeconfig, yaml_document_t * document, yaml_node_t * node)
{
    int rc = 0;
    yaml_node_item_t *item = NULL;
    yaml_node_t *value = NULL;
    int item_count = 0;
    int i = 0;

    // Get the count of clusters
    for (item = node->data.sequence.items.start, item_count = 0; item < node->data.sequence.items.top; item++, item_count++) {
        ;
    }

    kubeconfig->clusters_count = item_count;
    kubeconfig->clusters = kubeconfig_clusters_create(kubeconfig->clusters_count);

    for (item = node->data.sequence.items.start, i = 0; item < node->data.sequence.items.top; item++, i++) {
        value = yaml_document_get_node(document, *item);
        rc = parse_kubeconfig_yaml_cluster_mapping(kubeconfig->clusters[i], document, value);
    }

    return rc;

}

static int parse_kubeconfig_yaml_top_mapping(kubeconfig_t * kubeconfig, yaml_document_t * document, yaml_node_t * node)
{
    static char fname[] = "parse_kubeconfig_yaml_top_mapping()";
    int rc = 0;

    yaml_node_pair_t *pair = NULL;
    yaml_node_t *key = NULL;
    yaml_node_t *value = NULL;

    for (pair = node->data.mapping.pairs.start; pair < node->data.mapping.pairs.top; pair++) {
        key = yaml_document_get_node(document, pair->key);
        value = yaml_document_get_node(document, pair->value);

        if (key->type != YAML_SCALAR_NODE) {
            fprintf(stderr, "%s: The key node is not YAML_SCALAR_NODE.\n", fname);
            return -1;
        }

        if (value->type == YAML_SCALAR_NODE) {
            if (0 == strcmp(key->data.scalar.value, KEY_APIVERSION)) {
                kubeconfig->apiVersion = strdup(value->data.scalar.value);
            } else if (0 == strcmp(key->data.scalar.value, KEY_KIND)) {
                kubeconfig->kind = strdup(value->data.scalar.value);
            } else if (0 == strcmp(key->data.scalar.value, KEY_CURRENT_CONTEXT)) {
                kubeconfig->current_context = strdup(value->data.scalar.value);
            }
        } else {
            if (0 == strcmp(key->data.scalar.value, KEY_CLUSTERS)) {
                rc = parse_kubeconfig_yaml_clusters_sequence(kubeconfig, document, value);
            } else if (0 == strcmp(key->data.scalar.value, KEY_CONTEXTS)) {
                rc = parse_kubeconfig_yaml_contexts_sequence(kubeconfig, document, value);
            } else if (0 == strcmp(key->data.scalar.value, KEY_USERS)) {
                rc = parse_kubeconfig_yaml_users_sequence(kubeconfig, document, value);
            }
        }
    }

    return rc;

}

static int parse_kubeconfig_yaml_node(kubeconfig_t * kubeconfig, yaml_document_t * document, yaml_node_t * node)
{
    static char fname[] = "parse_kubeconfig_yaml_node()";
    int rc = 0;

    if (YAML_MAPPING_NODE == node->type) {
        rc = parse_kubeconfig_yaml_top_mapping(kubeconfig, document, node);
    } else {
        fprintf(stderr, "%s: %s is not a valid kubeconfig file.\n", fname, kubeconfig->fileName);
        rc = -1;
    }

    return rc;
}

static int parse_kubeconfig_yaml_document(kubeconfig_t * kubeconfig, yaml_document_t * document)
{
    static char fname[] = "parse_kubeconfig_yaml_document()";
    int rc = 0;

    yaml_node_t *root;
    root = yaml_document_get_root_node(document);
    if (NULL == root) {
        fprintf(stderr, "%s: The document is null\n", fname);
        return -1;
    }

    rc = parse_kubeconfig_yaml_node(kubeconfig, document, root);

    return rc;
}

int kubeyaml_load_kubeconfig(kubeconfig_t * kubeconfig)
{
    static char fname[] = "kubeyaml_load_kubeconfig()";

    yaml_parser_t parser;
    yaml_document_t document;

    int done = 0;

    /* Create the Parser object. */
    yaml_parser_initialize(&parser);

    /* Set a file input. */
    FILE *input = NULL;
    if (kubeconfig->fileName) {
        input = fopen(kubeconfig->fileName, "rb");
        if (!input) {
            fprintf(stderr, "%s: Cannot open the file %s.[%s]\n", fname, kubeconfig->fileName, strerror(errno));
            return -1;
        }
    } else {
        fprintf(stderr, "%s: The kubeconf file name needs be set by kubeconfig->fileName .\n", fname);
        return -1;
    }

    yaml_parser_set_input_file(&parser, input);

    while (!done) {

        if (!yaml_parser_load(&parser, &document)) {
            goto error;
        }

        done = (!yaml_document_get_root_node(&document));

        if (!done) {
            parse_kubeconfig_yaml_document(kubeconfig, &document);
        }

        yaml_document_delete(&document);

    }

    /* Cleanup */
    yaml_parser_delete(&parser);
    fclose(input);
    return 0;

  error:
    yaml_parser_delete(&parser);
    fclose(input);
    return -1;
}
