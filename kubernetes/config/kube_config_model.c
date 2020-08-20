#include "kube_config_model.h"
#include <stdlib.h>

void kubeconfig_free_string_list(char **string_list, int count)
{
    if (string_list && count > 0) {
        for (int i = 0; i < count; i++) {
            if (string_list[i]) {
                free(string_list[i]);
                string_list[i] = NULL;
            }
        }
        free(string_list);
    }
}

void kubeconfig_free_string_map_list(keyValuePair_t ** map_list, int count)
{
    if (map_list && count > 0) {
        keyValuePair_t *pair = NULL;
        for (int i = 0; i < count; i++) {
            pair = map_list[i];
            if (pair) {
                if (pair->key) {
                    free(pair->key);
                    pair->key = NULL;
                }
                if (pair->value) {
                    free(pair->value);
                    pair->value = NULL;
                }
                free(pair);
                pair = NULL;
            }
        }
        free(map_list);
    }
}

kubeconfig_property_t *kubeconfig_property_create(kubeconfig_property_type_t type)
{
    kubeconfig_property_t *property = calloc(1, sizeof(kubeconfig_property_t));
    property->type = type;
    return property;
}

void kubeconfig_property_free(kubeconfig_property_t * property)
{
    if (!property) {
        return;
    }

    if (property->name) {
        free(property->name);
        property->name = NULL;
    }

    if (KUBECONFIG_PROPERTY_TYPE_CLUSTER == property->type) {
        if (property->server) {
            free(property->server);
            property->server = NULL;
        }
        if (property->certificate_authority_data) {
            free(property->certificate_authority_data);
            property->certificate_authority_data = NULL;
        }
    }

    if (KUBECONFIG_PROPERTY_TYPE_USER == property->type) {
        if (property->client_certificate_data) {
            free(property->client_certificate_data);
            property->client_certificate_data = NULL;
        }
        if (property->client_key_data) {
            free(property->client_key_data);
            property->client_key_data = NULL;
        }
        if (property->username) {
            free(property->username);
            property->username = NULL;
        }
        if (property->password) {
            free(property->password);
            property->password = NULL;
        }
        if (property->token) {
            free(property->token);
            property->token = NULL;
        }
        if (property->auth_provider) {
            kubeconfig_property_free(property->auth_provider);
            property->auth_provider = NULL;
        }
        if (property->exec) {
            kubeconfig_property_free(property->exec);
            property->exec = NULL;
        }
    }

    if (KUBECONFIG_PROPERTY_TYPE_CONTEXT == property->type) {
        if (property->cluster) {
            free(property->cluster);
            property->cluster = NULL;
        }
        if (property->namespace) {
            free(property->namespace);
            property->namespace = NULL;
        }
        if (property->user) {
            free(property->user);
            property->user = NULL;
        }
    }

    if (KUBECONFIG_PROPERTY_TYPE_USER_EXEC == property->type) {
        if (property->command) {
            free(property->command);
            property->command = NULL;
        }
        if (property->apiVersion) {
            free(property->apiVersion);
            property->apiVersion = NULL;
        }
        if (property->envs && property->envs_count > 0) {
            kubeconfig_free_string_map_list(property->envs, property->envs_count);
            property->envs = NULL;
            property->envs_count = 0;
        }
        if (property->args && property->args_count > 0) {
            kubeconfig_free_string_list(property->args, property->args_count);
            property->args = NULL;
            property->args_count = 0;
        }
    }

    if (KUBECONFIG_PROPERTY_TYPE_USER_AUTH_PROVIDER == property->type) {
        if (property->id_token) {
            free(property->id_token);
            property->id_token = NULL;
        }
        if (property->cmd_path) {
            free(property->cmd_path);
            property->cmd_path = NULL;
        }
        if (property->access_token) {
            free(property->access_token);
            property->access_token = NULL;
        }
        if (property->expires_on) {
            free(property->expires_on);
            property->expires_on = NULL;
        }
        if (property->expiry) {
            free(property->expiry);
            property->expiry = NULL;
        }
        if (property->idp_certificate_authority) {
            free(property->idp_certificate_authority);
            property->idp_certificate_authority = NULL;
        }
        if (property->idp_certificate_authority_data) {
            free(property->idp_certificate_authority_data);
            property->idp_certificate_authority_data = NULL;
        }
        if (property->client_id) {
            free(property->client_id);
            property->client_id = NULL;
        }
        if (property->client_secret) {
            free(property->client_secret);
            property->client_secret = NULL;
        }
        if (property->idp_issuer_url) {
            free(property->idp_issuer_url);
            property->idp_issuer_url = NULL;
        }
        if (property->refresh_token) {
            free(property->refresh_token);
            property->refresh_token = NULL;
        }
    }

    free(property);
}

kubeconfig_property_t **kubeconfig_properties_create(int contexts_count, kubeconfig_property_type_t type)
{
    kubeconfig_property_t **properties = (kubeconfig_property_t **) calloc(contexts_count, sizeof(kubeconfig_property_t *));
    int i = 0;
    for (i = 0; i < contexts_count; i++) {
        properties[i] = kubeconfig_property_create(type);
    }
    return properties;
}

void kubeconfig_properties_free(kubeconfig_property_t ** properties, int properties_count)
{
    if (!properties) {
        return;
    }

    for (int i = 0; i < properties_count; i++) {
        if (properties[i]) {
            kubeconfig_property_free(properties[i]);
            properties[i] = NULL;
        }
    }
    free(properties);
}

kubeconfig_t *kubeconfig_create()
{
    kubeconfig_t *config = calloc(1, sizeof(kubeconfig_t));
    return config;
}

void kubeconfig_free(kubeconfig_t * kubeconfig)
{
    if (!kubeconfig) {
        return;
    }

    if (kubeconfig->fileName) {
        free(kubeconfig->fileName);
        kubeconfig->fileName = NULL;
    }
    if (kubeconfig->apiVersion) {
        free(kubeconfig->apiVersion);
        kubeconfig->apiVersion = NULL;
    }
    if (kubeconfig->kind) {
        free(kubeconfig->kind);
        kubeconfig->kind = NULL;
    }
    if (kubeconfig->preferences) {
        free(kubeconfig->preferences);
        kubeconfig->preferences = NULL;
    }
    if (kubeconfig->current_context) {
        free(kubeconfig->current_context);
        kubeconfig->current_context = NULL;
    }
    if (kubeconfig->clusters) {
        kubeconfig_properties_free(kubeconfig->clusters, kubeconfig->clusters_count);
        kubeconfig->clusters = NULL;
    }
    if (kubeconfig->users) {
        kubeconfig_properties_free(kubeconfig->users, kubeconfig->users_count);
        kubeconfig->users = NULL;
    }
    if (kubeconfig->contexts) {
        kubeconfig_properties_free(kubeconfig->contexts, kubeconfig->contexts_count);
        kubeconfig->contexts = NULL;
    }

    free(kubeconfig);
}

ExecCredential_status_t *exec_credential_status_create()
{
    ExecCredential_status_t *exec_credential_status = calloc(1, sizeof(ExecCredential_status_t));
    return exec_credential_status;
}

void exec_credential_status_free(ExecCredential_status_t * exec_credential_status)
{
    if (!exec_credential_status) {
        return;
    }

    if (exec_credential_status->token) {
        free(exec_credential_status->token);
        exec_credential_status->token = NULL;
    }
    if (exec_credential_status->clientCertificateData) {
        free(exec_credential_status->clientCertificateData);
        exec_credential_status->clientCertificateData = NULL;
    }
    if (exec_credential_status->clientKeyData) {
        free(exec_credential_status->clientKeyData);
        exec_credential_status->clientKeyData = NULL;
    }

    free(exec_credential_status);
}

ExecCredential_t *exec_credential_create()
{
    ExecCredential_t *exec_credential = calloc(1, sizeof(ExecCredential_t));
    return exec_credential;
}

void exec_credential_free(ExecCredential_t * exec_credential)
{
    if (!exec_credential) {
        return;
    }

    if (exec_credential->apiVersion) {
        free(exec_credential->apiVersion);
        exec_credential->apiVersion = NULL;
    }
    if (exec_credential->kind) {
        free(exec_credential->kind);
        exec_credential->kind = NULL;
    }
    if (exec_credential->status) {
        exec_credential_status_free(exec_credential->status);
        exec_credential->status = NULL;
    }

    free(exec_credential);
}
