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
#define KEY_PREFERENCES "preferences"
#define KEY_CLUSTERS "clusters"
#define KEY_CLUSTER "cluster"
#define KEY_CONTEXTS "contexts"
#define KEY_CONTEXT "context"
#define KEY_NAMESPACE "namespace"
#define KEY_USERS "users"
#define KEY_USER "user"
#define KEY_NAME "name"
#define KEY_USER_EXEC "exec"
#define KEY_USER_EXEC_COMMAND "command"
#define KEY_USER_EXEC_ENV "env"
#define KEY_USER_EXEC_ENV_KEY "name"
#define KEY_USER_EXEC_ENV_VALUE "value"
#define KEY_USER_EXEC_ARGS "args"
#define KEY_USER_AUTH_PROVIDER "auth-provider"
#define KEY_USER_AUTH_PROVIDER_CONFIG "config"
#define KEY_USER_AUTH_PROVIDER_CONFIG_ACCESS_TOKEN "access-token"
#define KEY_USER_AUTH_PROVIDER_CONFIG_CLIENT_ID "client-id"
#define KEY_USER_AUTH_PROVIDER_CONFIG_CLIENT_SECRET "client-secret"
#define KEY_USER_AUTH_PROVIDER_CONFIG_CMD_PATH "cmd-path"
#define KEY_USER_AUTH_PROVIDER_CONFIG_EXPIRES_ON "expires-on"
#define KEY_USER_AUTH_PROVIDER_CONFIG_EXPIRY "expiry"
#define KEY_USER_AUTH_PROVIDER_CONFIG_ID_TOKEN "id-token"
#define KEY_USER_AUTH_PROVIDER_CONFIG_IDP_CERTIFICATE_AUTHORITY "idp-certificate-authority"
#define KEY_USER_AUTH_PROVIDER_CONFIG_IDP_CERTIFICATE_AUTHORITY_DATA "idp-certificate-authority-data"
#define KEY_USER_AUTH_PROVIDER_CONFIG_IDP_ISSUE_URL "idp-issuer-url"
#define KEY_USER_AUTH_PROVIDER_CONFIG_REFRESH_TOKEN "refresh-token"
#define KEY_CERTIFICATE_AUTHORITY_DATA "certificate-authority-data"
#define KEY_INSECURE_SKIP_TLS_VERIFY "insecure-skip-tls-verify"
#define KEY_SERVER "server"
#define KEY_CLIENT_CERTIFICATE_DATA "client-certificate-data"
#define KEY_CLIENT_KEY_DATA "client-key-data"
#define KEY_STAUTS "status"
#define KEY_TOKEN "token"
#define KEY_CLIENT_CERTIFICATE_DATA2 "clientCertificateData"
#define KEY_CLIENT_KEY_DATA2 "clientKeyData"

#define VALUE_TRUE_LOWERCASE_STRING "true"

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
                } else if (0 == strcmp(key->data.scalar.value, KEY_INSECURE_SKIP_TLS_VERIFY)) {
                    property->insecure_skip_tls_verify = (0 == strcmp(value->data.scalar.value, VALUE_TRUE_LOWERCASE_STRING)); //libyaml fails to parse true, but it can parse "true"!
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
                } else if (0 == strcmp(key->data.scalar.value, KEY_NAMESPACE)) {
                    property->namespace = strdup(value->data.scalar.value);
                } else if (0 == strcmp(key->data.scalar.value, KEY_USER)) {
                    property->user = strdup(value->data.scalar.value);
                }
            } else if (KUBECONFIG_PROPERTY_TYPE_USER_EXEC == property->type) {
                if (0 == strcmp(key->data.scalar.value, KEY_APIVERSION)) {
                    property->apiVersion = strdup(value->data.scalar.value);
                } else if (0 == strcmp(key->data.scalar.value, KEY_USER_EXEC_COMMAND)) {
                    property->command = strdup(value->data.scalar.value);
                }
            } else if (KUBECONFIG_PROPERTY_TYPE_USER_AUTH_PROVIDER == property->type) {
                if (0 == strcmp(key->data.scalar.value, KEY_USER_AUTH_PROVIDER_CONFIG_ACCESS_TOKEN)) {
                    property->access_token = strdup(value->data.scalar.value);
                } else if (0 == strcmp(key->data.scalar.value, KEY_USER_AUTH_PROVIDER_CONFIG_CLIENT_ID)) {
                    property->client_id = strdup(value->data.scalar.value);
                } else if (0 == strcmp(key->data.scalar.value, KEY_USER_AUTH_PROVIDER_CONFIG_CLIENT_SECRET)) {
                    property->client_secret = strdup(value->data.scalar.value);
                } else if (0 == strcmp(key->data.scalar.value, KEY_USER_AUTH_PROVIDER_CONFIG_CMD_PATH)) {
                    property->cmd_path = strdup(value->data.scalar.value);
                } else if (0 == strcmp(key->data.scalar.value, KEY_USER_AUTH_PROVIDER_CONFIG_EXPIRES_ON)) {
                    property->expires_on = strdup(value->data.scalar.value);
                } else if (0 == strcmp(key->data.scalar.value, KEY_USER_AUTH_PROVIDER_CONFIG_EXPIRY)) {
                    property->expiry = strdup(value->data.scalar.value);
                } else if (0 == strcmp(key->data.scalar.value, KEY_USER_AUTH_PROVIDER_CONFIG_ID_TOKEN)) {
                    property->id_token = strdup(value->data.scalar.value);
                } else if (0 == strcmp(key->data.scalar.value, KEY_USER_AUTH_PROVIDER_CONFIG_IDP_CERTIFICATE_AUTHORITY)) {
                    property->idp_certificate_authority = strdup(value->data.scalar.value);
                } else if (0 == strcmp(key->data.scalar.value, KEY_USER_AUTH_PROVIDER_CONFIG_IDP_CERTIFICATE_AUTHORITY_DATA)) {
                    property->idp_certificate_authority_data = strdup(value->data.scalar.value);
                } else if (0 == strcmp(key->data.scalar.value, KEY_USER_AUTH_PROVIDER_CONFIG_IDP_ISSUE_URL)) {
                    property->idp_issuer_url = strdup(value->data.scalar.value);
                } else if (0 == strcmp(key->data.scalar.value, KEY_USER_AUTH_PROVIDER_CONFIG_REFRESH_TOKEN)) {
                    property->refresh_token = strdup(value->data.scalar.value);
                }
            }
        } else if (value->type == YAML_MAPPING_NODE) {
            if (KUBECONFIG_PROPERTY_TYPE_USER == property->type) {
                int rc = 0;
                if (0 == strcmp(key->data.scalar.value, KEY_USER_EXEC)) {
                    property->exec = kubeconfig_property_create(KUBECONFIG_PROPERTY_TYPE_USER_EXEC);
                    if (!property->exec) {
                        fprintf(stderr, "Cannot allocate memory for kubeconfig exec for user %s.\n", property->name);
                        return -1;
                    }
                    rc = parse_kubeconfig_yaml_property_mapping(property->exec, document, value);
                    if (0 != rc) {
                        fprintf(stderr, "Cannot parse kubeconfig exec for user %s.\n", property->name);
                        return -1;
                    }
                } else if (0 == strcmp(key->data.scalar.value, KEY_USER_AUTH_PROVIDER)) {
                    property->auth_provider = kubeconfig_property_create(KUBECONFIG_PROPERTY_TYPE_USER_AUTH_PROVIDER);
                    if (!property->auth_provider) {
                        fprintf(stderr, "Cannot allocate memory for kubeconfig auth provider for user %s.\n", property->name);
                        return -1;
                    }
                    rc = parse_kubeconfig_yaml_property_mapping(property->auth_provider, document, value);
                    if (0 != rc) {
                        fprintf(stderr, "Cannot parse kubeconfig auth provider for user %s.\n", property->name);
                        return -1;
                    }
                } else {
                    parse_kubeconfig_yaml_property_mapping(property, document, value);
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

static int append_key_stringvalue_to_mapping_node(yaml_document_t * output_document, int parent_node, const char *key_string, const char *value_string)
{
    int key = yaml_document_add_scalar(output_document, NULL, (yaml_char_t *) key_string, -1, YAML_PLAIN_SCALAR_STYLE);
    if (!key) {
        return -1;
    }
    int value = yaml_document_add_scalar(output_document, NULL, (yaml_char_t *) value_string, -1, YAML_PLAIN_SCALAR_STYLE);
    if (!value) {
        return -1;
    }
    if (!yaml_document_append_mapping_pair(output_document, parent_node, key, value)) {
        return -1;
    }
    return 0;
}

int append_key_stringseq_to_mapping_node(yaml_document_t * output_document, int parent_node, const char *key_string, char **strings, int strings_count)
{
    int key = yaml_document_add_scalar(output_document, NULL, (yaml_char_t *) key_string, -1, YAML_PLAIN_SCALAR_STYLE);
    if (!key) {
        return -1;
    }
    int seq = yaml_document_add_sequence(output_document, NULL, YAML_BLOCK_SEQUENCE_STYLE);
    if (!seq) {
        return -1;
    }
    if (!yaml_document_append_mapping_pair(output_document, parent_node, key, seq)) {
        return -1;
    }

    for (int i = 0; i < strings_count; i++) {
        int value = yaml_document_add_scalar(output_document, NULL, (yaml_char_t *) strings[i], -1, YAML_PLAIN_SCALAR_STYLE);
        if (!value) {
            return -1;
        }
        if (!yaml_document_append_sequence_item(output_document, seq, value)) {
            return -1;
        }
    }

    return 0;
}

int append_auth_provider_config_to_mapping_node(yaml_document_t * output_document, int parent_node, const kubeconfig_property_t * auth_provider_config)
{
    /* Add 'name': '' */
    if (auth_provider_config->name) {
        if (-1 == append_key_stringvalue_to_mapping_node(output_document, parent_node, KEY_NAME, auth_provider_config->name)) {
            return -1;
        }
    }

    /* Add 'config': {} */
    int key = yaml_document_add_scalar(output_document, NULL, (yaml_char_t *) KEY_USER_AUTH_PROVIDER_CONFIG, -1, YAML_PLAIN_SCALAR_STYLE);
    if (!key) {
        return -1;
    }
    int map = yaml_document_add_mapping(output_document, NULL, YAML_BLOCK_MAPPING_STYLE);
    if (!map) {
        return -1;
    }
    if (!yaml_document_append_mapping_pair(output_document, parent_node, key, map)) {
        return -1;
    }

    /* Add 'access-token': '' */
    if (auth_provider_config->access_token) {
        if (-1 == append_key_stringvalue_to_mapping_node(output_document, map, KEY_USER_AUTH_PROVIDER_CONFIG_ACCESS_TOKEN, auth_provider_config->access_token)) {
            return -1;
        }
    }

    /* Add 'client-id': '' */
    if (auth_provider_config->client_id) {
        if (-1 == append_key_stringvalue_to_mapping_node(output_document, map, KEY_USER_AUTH_PROVIDER_CONFIG_CLIENT_ID, auth_provider_config->client_id)) {
            return -1;
        }
    }

    /* Add 'client-secret': '' */
    if (auth_provider_config->client_secret) {
        if (-1 == append_key_stringvalue_to_mapping_node(output_document, map, KEY_USER_AUTH_PROVIDER_CONFIG_CLIENT_SECRET, auth_provider_config->client_secret)) {
            return -1;
        }
    }

    /* Add 'cmd-path': '' */
    if (auth_provider_config->cmd_path) {
        if (-1 == append_key_stringvalue_to_mapping_node(output_document, map, KEY_USER_AUTH_PROVIDER_CONFIG_CMD_PATH, auth_provider_config->cmd_path)) {
            return -1;
        }
    }

    /* Add 'expires-on': '' */
    if (auth_provider_config->expires_on) {
        if (-1 == append_key_stringvalue_to_mapping_node(output_document, map, KEY_USER_AUTH_PROVIDER_CONFIG_EXPIRES_ON, auth_provider_config->expires_on)) {
            return -1;
        }
    }

    /* Add 'expiry': '' */
    if (auth_provider_config->expiry) {
        if (-1 == append_key_stringvalue_to_mapping_node(output_document, map, KEY_USER_AUTH_PROVIDER_CONFIG_EXPIRY, auth_provider_config->expiry)) {
            return -1;
        }
    }

    /* Add 'id-token': '' */
    if (auth_provider_config->id_token) {
        if (-1 == append_key_stringvalue_to_mapping_node(output_document, map, KEY_USER_AUTH_PROVIDER_CONFIG_ID_TOKEN, auth_provider_config->id_token)) {
            return -1;
        }
    }

    /* Add 'idp-certificate-authority': '' */
    if (auth_provider_config->idp_certificate_authority) {
        if (-1 == append_key_stringvalue_to_mapping_node(output_document, map, KEY_USER_AUTH_PROVIDER_CONFIG_IDP_CERTIFICATE_AUTHORITY, auth_provider_config->idp_certificate_authority)) {
            return -1;
        }
    }

    /* Add 'idp-certificate-authority-data': '' */
    if (auth_provider_config->idp_certificate_authority_data) {
        if (-1 == append_key_stringvalue_to_mapping_node(output_document, map, KEY_USER_AUTH_PROVIDER_CONFIG_IDP_CERTIFICATE_AUTHORITY_DATA, auth_provider_config->idp_certificate_authority_data)) {
            return -1;
        }
    }

    /* Add 'idp-issuer-url': '' */
    if (auth_provider_config->idp_issuer_url) {
        if (-1 == append_key_stringvalue_to_mapping_node(output_document, map, KEY_USER_AUTH_PROVIDER_CONFIG_IDP_ISSUE_URL, auth_provider_config->idp_issuer_url)) {
            return -1;
        }
    }

    /* Add 'refresh-token': '' */
    if (auth_provider_config->refresh_token) {
        if (-1 == append_key_stringvalue_to_mapping_node(output_document, map, KEY_USER_AUTH_PROVIDER_CONFIG_REFRESH_TOKEN, auth_provider_config->refresh_token)) {
            return -1;
        }
    }

    return 0;
}

int append_key_kvpseq_to_mapping_node(yaml_document_t * output_document, int parent_node, const char *key_string, keyValuePair_t ** kvps, int kvps_count)
{
    int key = yaml_document_add_scalar(output_document, NULL, (yaml_char_t *) key_string, -1, YAML_PLAIN_SCALAR_STYLE);
    if (!key) {
        return -1;
    }
    int seq = yaml_document_add_sequence(output_document, NULL, YAML_BLOCK_SEQUENCE_STYLE);
    if (!seq) {
        return -1;
    }
    if (!yaml_document_append_mapping_pair(output_document, parent_node, key, seq)) {
        return -1;
    }

    for (int i = 0; i < kvps_count; i++) {
        int map = yaml_document_add_mapping(output_document, NULL, YAML_BLOCK_MAPPING_STYLE);
        if (!map) {
            return -1;
        }
        if (!yaml_document_append_sequence_item(output_document, seq, map)) {
            return -1;
        }

        /* Add 'name': '' */
        if (-1 == append_key_stringvalue_to_mapping_node(output_document, map, KEY_USER_EXEC_ENV_KEY, kvps[i]->key)) {
            return -1;
        }

        /* Add 'value': '' */
        if (-1 == append_key_stringvalue_to_mapping_node(output_document, map, KEY_USER_EXEC_ENV_VALUE, kvps[i]->value)) {
            return -1;
        }
    }

    return 0;
}

static int append_key_map_to_mapping_node(yaml_document_t * output_document, int parent_node, const char *key_string, const kubeconfig_property_t * property)
{
    int key = yaml_document_add_scalar(output_document, NULL, (yaml_char_t *) key_string, -1, YAML_PLAIN_SCALAR_STYLE);
    if (!key) {
        return -1;
    }
    int map = yaml_document_add_mapping(output_document, NULL, YAML_BLOCK_MAPPING_STYLE);
    if (!map) {
        return -1;
    }
    if (!yaml_document_append_mapping_pair(output_document, parent_node, key, map)) {
        return -1;
    }

    if (!property) {
        return 0;
    }

    if (KUBECONFIG_PROPERTY_TYPE_CONTEXT == property->type) {
        /* Add 'cluster': '' */
        if (property->cluster) {
            if (-1 == append_key_stringvalue_to_mapping_node(output_document, map, KEY_CLUSTER, property->cluster)) {
                return -1;
            }
        }

        /* Add 'namespace': '' */
        if (property->namespace) {
            if (-1 == append_key_stringvalue_to_mapping_node(output_document, map, KEY_NAMESPACE, property->namespace)) {
                return -1;
            }
        }

        /* Add 'user': '' */
        if (property->user) {
            if (-1 == append_key_stringvalue_to_mapping_node(output_document, map, KEY_USER, property->user)) {
                return -1;
            }
        }
    } else if (KUBECONFIG_PROPERTY_TYPE_CLUSTER == property->type) {
        /* Add 'certificate-authority-data': '' */
        if (property->certificate_authority_data) {
            if (-1 == append_key_stringvalue_to_mapping_node(output_document, map, KEY_CERTIFICATE_AUTHORITY_DATA, property->certificate_authority_data)) {
                return -1;
            }
        }

        /* Add 'server': '' */
        if (property->server) {
            if (-1 == append_key_stringvalue_to_mapping_node(output_document, map, KEY_SERVER, property->server)) {
                return -1;
            }
        }
    } else if (KUBECONFIG_PROPERTY_TYPE_USER == property->type) {
        /* Add 'auth-provider': {} */
        if (property->auth_provider) {
            if (-1 == append_key_map_to_mapping_node(output_document, map, KEY_USER_AUTH_PROVIDER, property->auth_provider)) {
                return -1;
            }
        }

        /* Add 'client-certificate-data': '' */
        if (property->client_certificate_data) {
            if (-1 == append_key_stringvalue_to_mapping_node(output_document, map, KEY_CLIENT_CERTIFICATE_DATA, property->client_certificate_data)) {
                return -1;
            }
        }

        /* Add 'client-key-data': '' */
        if (property->client_key_data) {
            if (-1 == append_key_stringvalue_to_mapping_node(output_document, map, KEY_CLIENT_KEY_DATA, property->client_key_data)) {
                return -1;
            }
        }

        /* Add 'exec': {} */
        if (property->exec) {
            if (-1 == append_key_map_to_mapping_node(output_document, map, KEY_USER_EXEC, property->exec)) {
                return -1;
            }
        }
    } else if (KUBECONFIG_PROPERTY_TYPE_USER_EXEC == property->type) {
        /* Add 'apiVersion': '' */
        if (property->apiVersion) {
            if (-1 == append_key_stringvalue_to_mapping_node(output_document, map, KEY_APIVERSION, property->apiVersion)) {
                return -1;
            }
        }

        /* Add 'args': [] */
        if (property->args && property->args_count > 0) {
            if (-1 == append_key_stringseq_to_mapping_node(output_document, map, KEY_USER_EXEC_ARGS, property->args, property->args_count)) {
                return -1;
            }
        }

        /* Add 'command': '' */
        if (property->command) {
            if (-1 == append_key_stringvalue_to_mapping_node(output_document, map, KEY_USER_EXEC_COMMAND, property->command)) {
                return -1;
            }
        }

        /* Add 'env': [] */
        if (property->envs && property->envs_count > 0) {
            if (-1 == append_key_kvpseq_to_mapping_node(output_document, map, KEY_USER_EXEC_ENV, property->envs, property->envs_count)) {
                return -1;
            }
        }
    } else if (KUBECONFIG_PROPERTY_TYPE_USER_AUTH_PROVIDER == property->type) {
        if (-1 == append_auth_provider_config_to_mapping_node(output_document, map, property)) {
            return -1;
        }
    }

    return 0;
}

static int append_key_seq_to_top_mapping_node(yaml_document_t * output_document, int parent_node, const char *first_level_key_string, const char *second_level_key_string,
                                              kubeconfig_property_t ** properites, int properites_count)
{
    int key = yaml_document_add_scalar(output_document, NULL, (yaml_char_t *) first_level_key_string, -1, YAML_PLAIN_SCALAR_STYLE);
    if (!key) {
        return -1;
    }
    int seq = yaml_document_add_sequence(output_document, NULL, YAML_BLOCK_SEQUENCE_STYLE);
    if (!seq) {
        return -1;
    }
    if (!yaml_document_append_mapping_pair(output_document, parent_node, key, seq)) {
        return -1;
    }

    for (int i = 0; i < properites_count; i++) {
        /* Add {}. */
        int map = yaml_document_add_mapping(output_document, NULL, YAML_BLOCK_MAPPING_STYLE);
        if (!map) {
            return -1;
        }
        if (!yaml_document_append_sequence_item(output_document, seq, map)) {
            return -1;
        }

        if (NULL != strstr(second_level_key_string, KEY_CLUSTER) || NULL != strstr(second_level_key_string, KEY_CONTEXT)) {
            /* Add 'cluster/context': {} */
            if (-1 == append_key_map_to_mapping_node(output_document, map, second_level_key_string, properites[i])) {
                return -1;
            }
        }

        /* Add 'name': '' */
        if (-1 == append_key_stringvalue_to_mapping_node(output_document, map, KEY_NAME, properites[i]->name)) {
            return -1;
        }

        if (NULL != strstr(second_level_key_string, KEY_USER)) {
            /* Add 'user': {} */
            if (-1 == append_key_map_to_mapping_node(output_document, map, second_level_key_string, properites[i])) {
                return -1;
            }
        }
    }

    return 0;
}

static int fill_yaml_document(yaml_document_t * output_document, const kubeconfig_t * kubeconfig)
{
    int root = yaml_document_add_mapping(output_document, NULL, YAML_BLOCK_MAPPING_STYLE);
    if (!root) {
        return -1;
    }

    /* Add 'apiVersion': '' */
    if (-1 == append_key_stringvalue_to_mapping_node(output_document, root, KEY_APIVERSION, kubeconfig->apiVersion)) {
        return -1;
    }

    /* Add 'clusters': {} */
    if (-1 == append_key_seq_to_top_mapping_node(output_document, root, KEY_CLUSTERS, KEY_CLUSTER, kubeconfig->clusters, kubeconfig->clusters_count)) {
        return -1;
    }

    /* Add 'contexts': {} */
    if (-1 == append_key_seq_to_top_mapping_node(output_document, root, KEY_CONTEXTS, KEY_CONTEXT, kubeconfig->contexts, kubeconfig->contexts_count)) {
        return -1;
    }

    /* Add 'current-context': '' */
    if (-1 == append_key_stringvalue_to_mapping_node(output_document, root, KEY_CURRENT_CONTEXT, kubeconfig->current_context)) {
        return -1;
    }

    /* Add 'kind': 'Config' */
    if (-1 == append_key_stringvalue_to_mapping_node(output_document, root, KEY_KIND, kubeconfig->kind)) {
        return -1;
    }

    /* Add 'preferences': {} */
    if (-1 == append_key_map_to_mapping_node(output_document, root, KEY_PREFERENCES, NULL)) {
        return -1;
    }

    /* Add 'users': {} */
    if (-1 == append_key_seq_to_top_mapping_node(output_document, root, KEY_USERS, KEY_USER, kubeconfig->users, kubeconfig->users_count)) {
        return -1;
    }

    return 0;
}

int kubeyaml_save_kubeconfig(const kubeconfig_t * kubeconfig)
{
    static char fname[] = "kubeyaml_save_kubeconfig()";

    if (!kubeconfig) {
        return 0;
    }

    /* Set a file output. */
    FILE *output = NULL;
    if (kubeconfig->fileName) {
        output = fopen(kubeconfig->fileName, "wb");
        if (!output) {
            fprintf(stderr, "%s: Cannot open the file %s.[%s]\n", fname, kubeconfig->fileName, strerror(errno));
            return -1;
        }
    } else {
        fprintf(stderr, "%s: The kubeconf file name needs be set by kubeconfig->fileName .\n", fname);
        return -1;
    }

    yaml_emitter_t emitter;
    yaml_document_t output_document;

    memset(&emitter, 0, sizeof(emitter));
    memset(&output_document, 0, sizeof(output_document));

    /* Initialize the emitter object. */
    if (!yaml_emitter_initialize(&emitter)) {
        fprintf(stderr, "%s: Could not initialize the emitter object\n", fname);
        return -1;
    }

    /* Set the emitter parameters. */
    yaml_emitter_set_canonical(&emitter, 0);
    yaml_emitter_set_unicode(&emitter, 1);
    yaml_emitter_set_output_file(&emitter, output);

    /* Create and emit the STREAM-START event. */
    if (!yaml_emitter_open(&emitter)) {
        goto emitter_error;
    }

    /* Create a output_document object. */
    if (!yaml_document_initialize(&output_document, NULL, NULL, NULL, 0, 0)) {
        goto document_error;
    }

    if (-1 == fill_yaml_document(&output_document, kubeconfig)) {
        goto document_error;
    }

    /* Emit the event. */
    if (!yaml_emitter_dump(&emitter, &output_document)) {
        goto emitter_error;
    }
    yaml_emitter_flush(&emitter);

    if (!yaml_emitter_close(&emitter)) {
        goto emitter_error;
    }

    yaml_emitter_delete(&emitter);
    yaml_document_delete(&output_document);
    fclose(output);

    return 0;

  emitter_error:

    switch (emitter.error) {
    case YAML_MEMORY_ERROR:
        fprintf(stderr, "%s: Memory error: Not enough memory for emitting\n", fname);
        break;

    case YAML_WRITER_ERROR:
        fprintf(stderr, "%s: Writer error: %s\n", fname, emitter.problem);
        break;

    case YAML_EMITTER_ERROR:
        fprintf(stderr, "%s: Emitter error: %s\n", fname, emitter.problem);
        break;

    default:
        /* Couldn't happen. */
        fprintf(stderr, "%s: Internal error\n", fname);
        break;
    }

    yaml_document_delete(&output_document);
    yaml_emitter_delete(&emitter);
    fclose(output);

    return -1;

  document_error:

    fprintf(stderr, "%s: Memory error: Not enough memory for creating a document\n", fname);
    yaml_document_delete(&output_document);
    yaml_emitter_delete(&emitter);
    fclose(output);

    return -1;
}
