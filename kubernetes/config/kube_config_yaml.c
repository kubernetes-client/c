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

static int parse_kubeconfig_yaml_property_info_mapping(kubeconfig_property_t * property, yaml_document_t * document, yaml_node_t * node)
{
    static char fname[] = "parse_kubeconfig_yaml_property_info_mapping()";

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
            if (KUBECONFIG_PROPERTY_TYPE_CLUSTER == property->type) {
                if (0 == strcmp(key->data.scalar.value, KEY_CERTIFICATE_AUTHORITY_DATA)) {
                    property->certificate_authority_data = strdup(value->data.scalar.value);
                } else if (0 == strcmp(key->data.scalar.value, KEY_SERVER)) {
                    property->server = strdup(value->data.scalar.value);
                }
            } else if (KUBECONFIG_PROPERTY_TYPE_USER == property->type) {
                if (0 == strcmp(key->data.scalar.value, KEY_CLIENT_CERTIFICATE_DATA)) {
                    property->client_certificate_data = strdup(value->data.scalar.value);
                } else if (0 == strcmp(key->data.scalar.value, KEY_CLIENT_KEY_DATA)) {
                    property->client_key_data = strdup(value->data.scalar.value);
                }
            } else if (KUBECONFIG_PROPERTY_TYPE_CONTEXT == property->type) {
                if (0 == strcmp(key->data.scalar.value, KEY_CLUSTER)) {
                    property->cluster = strdup(value->data.scalar.value);
                } else if (0 == strcmp(key->data.scalar.value, KEY_USER)) {
                    property->user = strdup(value->data.scalar.value);
                }
            }
        }
    }

    return 0;
}

static int parse_kubeconfig_yaml_property_mapping(kubeconfig_property_t * property, yaml_document_t * document, yaml_node_t * node)
{
    static char fname[] = "parse_kubeconfig_yaml_property_mapping()";
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
                property->name = strdup(value->data.scalar.value);
            }
        } else if (value->type == YAML_MAPPING_NODE) {
            rc = parse_kubeconfig_yaml_property_info_mapping(property, document, value);
        }
    }

    return rc;
}

static int parse_kubeconfig_yaml_sequence(kubeconfig_property_t *** p_properties, int *p_properties_count, kubeconfig_property_type_t type, yaml_document_t * document, yaml_node_t * node)
{
    yaml_node_item_t *item = NULL;
    yaml_node_t *value = NULL;
    int item_count = 0;
    int i = 0;
    int rc = 0;

    // Get the count of data (e.g. cluster, context, user)
    for (item = node->data.sequence.items.start, item_count = 0; item < node->data.sequence.items.top; item++, item_count++) {
        ;
    }

    int properties_count = item_count;
    kubeconfig_property_t **properties = kubeconfig_properties_create(properties_count, type);
    if (!properties) {
        fprintf(stderr, "Cannot allocate memory for kubeconfig properties.\n");
        return -1;
    }

    for (item = node->data.sequence.items.start, i = 0; item < node->data.sequence.items.top; item++, i++) {
        value = yaml_document_get_node(document, *item);
        rc = parse_kubeconfig_yaml_property_mapping(properties[i], document, value);
        if (0 != rc) {
            fprintf(stderr, "Cannot parse kubeconfi properties.\n");
            return -1;
        }
    }

    *p_properties = properties;
    *p_properties_count = properties_count;

    return 0;

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
                rc = parse_kubeconfig_yaml_sequence(&(kubeconfig->clusters), &(kubeconfig->clusters_count), KUBECONFIG_PROPERTY_TYPE_CLUSTER, document, value);
            } else if (0 == strcmp(key->data.scalar.value, KEY_CONTEXTS)) {
                rc = parse_kubeconfig_yaml_sequence(&(kubeconfig->contexts), &(kubeconfig->contexts_count), KUBECONFIG_PROPERTY_TYPE_CONTEXT, document, value);
            } else if (0 == strcmp(key->data.scalar.value, KEY_USERS)) {
                rc = parse_kubeconfig_yaml_sequence(&(kubeconfig->users), &(kubeconfig->users_count), KUBECONFIG_PROPERTY_TYPE_USER, document, value);
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
