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
#define KEY_USER_EXEC "exec"
#define KEY_USER_EXEC_COMMAND "command"
#define KEY_USER_EXEC_ENV "env"
#define KEY_USER_EXEC_ENV_KEY "name"
#define KEY_USER_EXEC_ENV_VALUE "value"
#define KEY_USER_EXEC_ARGS "args"
#define KEY_CERTIFICATE_AUTHORITY_DATA "certificate-authority-data"
#define KEY_SERVER "server"
#define KEY_CLIENT_CERTIFICATE_DATA "client-certificate-data"
#define KEY_CLIENT_KEY_DATA "client-key-data"
#define KEY_STAUTS "status"
#define KEY_TOKEN "token"
#define KEY_CLIENT_CERTIFICATE_DATA2 "clientCertificateData"
#define KEY_CLIENT_KEY_DATA2 "clientKeyData"

static int parse_kubeconfig_yaml_string_sequence(char ***p_strings, int *p_strings_count, yaml_document_t * document, yaml_node_t * node)
{
    static char fname[] = "parse_kubeconfig_yaml_string_sequence()";

    yaml_node_item_t *item = NULL;
    yaml_node_t *value = NULL;
    int item_count = 0;
    int i = 0;
    int rc = 0;

    for (item = node->data.sequence.items.start, item_count = 0; item < node->data.sequence.items.top; item++, item_count++) {
        ;
    }

    int strings_count = item_count;
    char **strings = (char **) calloc(strings_count, sizeof(char *));
    if (!strings) {
        fprintf(stderr, "%s: Cannot allocate memory for string sequence.\n", fname);
        return -1;
    }

    for (item = node->data.sequence.items.start, i = 0; item < node->data.sequence.items.top; item++, i++) {
        value = yaml_document_get_node(document, *item);
        strings[i] = strdup(value->data.scalar.value);
    }

    *p_strings = strings;
    *p_strings_count = strings_count;

    return 0;
}

static int parse_kubeconfig_yaml_string_mapping(keyValuePair_t * string_mapping, yaml_document_t * document, yaml_node_t * node)
{
    static char fname[] = "parse_kubeconfig_yaml_string_mapping()";

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
            if (0 == strcmp(key->data.scalar.value, KEY_USER_EXEC_ENV_KEY)) {
                string_mapping->key = strdup(value->data.scalar.value);
            } else if (0 == strcmp(key->data.scalar.value, KEY_USER_EXEC_ENV_VALUE)) {
                string_mapping->value = strdup(value->data.scalar.value);
            } else {
                fprintf(stderr, "%s: The key of node is invalid: %s\n", fname, key->data.scalar.value);
                return -1;
            }
        }
    }

    return 0;
}

static int parse_kubeconfig_yaml_string_mapping_sequence(keyValuePair_t *** p_string_mappings, int *p_mappings_count, yaml_document_t * document, yaml_node_t * node)
{
    static char fname[] = "parse_kubeconfig_yaml_string_mapping_sequence()";

    yaml_node_item_t *item = NULL;
    yaml_node_t *value = NULL;
    int item_count = 0;
    int i = 0;
    int rc = 0;

    for (item = node->data.sequence.items.start, item_count = 0; item < node->data.sequence.items.top; item++, item_count++) {
        ;
    }

    int mappings_count = item_count;
    keyValuePair_t **string_mappings = (keyValuePair_t **) calloc(mappings_count, sizeof(keyValuePair_t *));
    if (!string_mappings) {
        fprintf(stderr, "%s: Cannot allocate memory for string mappings.\n", fname);
        return -1;
    }
    for (int j = 0; j < mappings_count; j++) {
        string_mappings[j] = calloc(1, sizeof(keyValuePair_t));
        if (!string_mappings[j]) {
            fprintf(stderr, "%s: Cannot allocate memory for string mapping.\n", fname);
            return -1;
        }
    }

    for (item = node->data.sequence.items.start, i = 0; item < node->data.sequence.items.top; item++, i++) {
        value = yaml_document_get_node(document, *item);

        rc = parse_kubeconfig_yaml_string_mapping(string_mappings[i], document, value);
        if (0 != rc) {
            fprintf(stderr, "%s: Cannot parse kubeconfig string mapping.\n", fname);
            return -1;
        }
    }

    *p_string_mappings = string_mappings;
    *p_mappings_count = mappings_count;

    return 0;
}

static int parse_kubeconfig_yaml_property_mapping(kubeconfig_property_t * property, yaml_document_t * document, yaml_node_t * node)
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
            if (0 == strcmp(key->data.scalar.value, KEY_NAME)) {
                property->name = strdup(value->data.scalar.value);
            }
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
            } else if (KUBECONFIG_PROPERTY_TYPE_USER_EXEC == property->type) {
                if (0 == strcmp(key->data.scalar.value, KEY_APIVERSION)) {
                    property->apiVersion = strdup(value->data.scalar.value);
                } else if (0 == strcmp(key->data.scalar.value, KEY_USER_EXEC_COMMAND)) {
                    property->command = strdup(value->data.scalar.value);
                }
            }
        } else if (value->type == YAML_MAPPING_NODE) {
            if ((KUBECONFIG_PROPERTY_TYPE_USER == property->type) && (0 == strcmp(key->data.scalar.value, KEY_USER_EXEC))) {
                property->exec = kubeconfig_property_create(KUBECONFIG_PROPERTY_TYPE_USER_EXEC);
                if (property->exec) {
                    int rc = parse_kubeconfig_yaml_property_mapping(property->exec, document, value);
                    if (0 != rc) {
                        fprintf(stderr, "Cannot parse kubeconfig exec for user %s.\n", property->name);
                        return -1;
                    }
                } else {
                    fprintf(stderr, "Cannot allocate memory for kubeconfig exec for user %s.\n", property->name);
                    return -1;
                }
            } else {
                parse_kubeconfig_yaml_property_mapping(property, document, value);
            }
        } else if (value->type == YAML_SEQUENCE_NODE) {
            if (KUBECONFIG_PROPERTY_TYPE_USER_EXEC == property->type) {
                if (0 == strcmp(key->data.scalar.value, KEY_USER_EXEC_ENV)) {
                    parse_kubeconfig_yaml_string_mapping_sequence(&(property->envs), &(property->envs_count), document, value);
                } else if (0 == strcmp(key->data.scalar.value, KEY_USER_EXEC_ARGS)) {
                    parse_kubeconfig_yaml_string_sequence(&(property->args), &(property->args_count), document, value);
                }
            }
        }
    }

    return 0;
}

static int parse_kubeconfig_yaml_property_sequence(kubeconfig_property_t *** p_properties, int *p_properties_count, kubeconfig_property_type_t type, yaml_document_t * document, yaml_node_t * node)
{
    yaml_node_item_t *item = NULL;
    yaml_node_t *value = NULL;
    int item_count = 0;
    int i = 0;
    int rc = 0;

    // Get the count of data (e.g. cluster, context, user, user_exec )
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
            fprintf(stderr, "Cannot parse kubeconfig properties.\n");
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
                rc = parse_kubeconfig_yaml_property_sequence(&(kubeconfig->clusters), &(kubeconfig->clusters_count), KUBECONFIG_PROPERTY_TYPE_CLUSTER, document, value);
            } else if (0 == strcmp(key->data.scalar.value, KEY_CONTEXTS)) {
                rc = parse_kubeconfig_yaml_property_sequence(&(kubeconfig->contexts), &(kubeconfig->contexts_count), KUBECONFIG_PROPERTY_TYPE_CONTEXT, document, value);
            } else if (0 == strcmp(key->data.scalar.value, KEY_USERS)) {
                rc = parse_kubeconfig_yaml_property_sequence(&(kubeconfig->users), &(kubeconfig->users_count), KUBECONFIG_PROPERTY_TYPE_USER, document, value);
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

static int parse_exec_credential_yaml_status_mapping(ExecCredential_status_t ** p_status, yaml_document_t * document, yaml_node_t * node)
{
    static char fname[] = "parse_exec_credential_yaml_status_mapping()";
    int rc = 0;

    yaml_node_pair_t *pair = NULL;
    yaml_node_t *key = NULL;
    yaml_node_t *value = NULL;

    ExecCredential_status_t *status = exec_credential_status_create();
    if (!status) {
        fprintf(stderr, "Cannot allocate memory for kubeconfig exec credentail status.\n");
        return -1;
    }

    for (pair = node->data.mapping.pairs.start; pair < node->data.mapping.pairs.top; pair++) {
        key = yaml_document_get_node(document, pair->key);
        value = yaml_document_get_node(document, pair->value);

        if (key->type != YAML_SCALAR_NODE) {
            fprintf(stderr, "%s: The key node is not YAML_SCALAR_NODE.\n", fname);
            return -1;
        }

        if (value->type == YAML_SCALAR_NODE) {
            if (0 == strcmp(key->data.scalar.value, KEY_TOKEN)) {
                status->token = strdup(value->data.scalar.value);
                status->type = EXEC_CREDENTIAL_TYPE_TOKEN;
            } else if (0 == strcmp(key->data.scalar.value, KEY_CLIENT_CERTIFICATE_DATA2)) {
                status->clientCertificateData = strdup(value->data.scalar.value);
                status->type = EXEC_CREDENTIAL_TYPE_CLIENT_CERT;
            } else if (0 == strcmp(key->data.scalar.value, KEY_CLIENT_KEY_DATA2)) {
                status->clientKeyData = strdup(value->data.scalar.value);
                status->type = EXEC_CREDENTIAL_TYPE_CLIENT_CERT;
            }
        }
    }

    *p_status = status;

    return rc;
}

static int parse_exec_credential_yaml_top_mapping(ExecCredential_t * exec_credential, yaml_document_t * document, yaml_node_t * node)
{
    static char fname[] = "parse_exec_credential_yaml_top_mapping()";
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
                exec_credential->apiVersion = strdup(value->data.scalar.value);
            } else if (0 == strcmp(key->data.scalar.value, KEY_KIND)) {
                exec_credential->kind = strdup(value->data.scalar.value);
            }
        } else {
            if (0 == strcmp(key->data.scalar.value, KEY_STAUTS)) {
                rc = parse_exec_credential_yaml_status_mapping(&(exec_credential->status), document, value);
            }
        }
    }

    return rc;
}

static int parse_exec_credential_yaml_node(ExecCredential_t * exec_credential, yaml_document_t * document, yaml_node_t * node)
{
    static char fname[] = "parse_exec_credential_yaml_node()";
    int rc = 0;

    if (YAML_MAPPING_NODE == node->type) {
        rc = parse_exec_credential_yaml_top_mapping(exec_credential, document, node);
    } else {
        fprintf(stderr, "%s: This is not a valid exec credential string.\n", fname);
        rc = -1;
    }

    return rc;
}

static int parse_exec_credential_yaml_document(ExecCredential_t * exec_credential, yaml_document_t * document)
{
    static char fname[] = "parse_exec_credential_yaml_document()";
    int rc = 0;

    yaml_node_t *root;
    root = yaml_document_get_root_node(document);
    if (NULL == root) {
        fprintf(stderr, "%s: The document is null\n", fname);
        return -1;
    }

    rc = parse_exec_credential_yaml_node(exec_credential, document, root);

    return rc;
}

int kubeyaml_parse_exec_crendential(ExecCredential_t * exec_credential, const char *exec_credential_string)
{
    static char fname[] = "kubeyaml_parse_ExecCrendentail()";

    yaml_parser_t parser;
    yaml_document_t document;

    int done = 0;

    /* Create the Parser object. */
    yaml_parser_initialize(&parser);

    /* Set a string input. */
    yaml_parser_set_input_string(&parser, exec_credential_string, strlen(exec_credential_string));

    while (!done) {

        if (!yaml_parser_load(&parser, &document)) {
            goto error;
        }

        done = (!yaml_document_get_root_node(&document));

        if (!done) {
            parse_exec_credential_yaml_document(exec_credential, &document);
        }

        yaml_document_delete(&document);

    }

    /* Cleanup */
    yaml_parser_delete(&parser);
    return 0;

  error:
    yaml_parser_delete(&parser);
    return -1;
}
