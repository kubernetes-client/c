#include "kube_config_model.h"
#include <stdlib.h>

kubeconfig_auth_provider_t *kubeconfig_auth_provider_create()
{
    kubeconfig_auth_provider_t *provider = calloc(1, sizeof(kubeconfig_auth_provider_t));
    return provider;
}

void kubeconfig_auth_provider_free(kubeconfig_auth_provider_t * provider)
{
    if (!provider) {
        return;
    }

    if (provider->name) {
        free(provider->name);
        provider->name = NULL;
    }
    if (provider->id_token) {
        free(provider->id_token);
        provider->id_token = NULL;
    }
    if (provider->cmd_path) {
        free(provider->cmd_path);
        provider->cmd_path = NULL;
    }
    if (provider->access_token) {
        free(provider->access_token);
        provider->access_token = NULL;
    }
    if (provider->expires_on) {
        free(provider->expires_on);
        provider->expires_on = NULL;
    }
    if (provider->expiry) {
        free(provider->expiry);
        provider->expiry = NULL;
    }
    if (provider->idp_certificate_authority_data) {
        free(provider->idp_certificate_authority_data);
        provider->idp_certificate_authority_data = NULL;
    }

    free(provider);
}

kubeconfig_exec_t *kubeconfig_exec_create()
{
    kubeconfig_exec_t *exec = calloc(1, sizeof(kubeconfig_exec_t));
    return exec;
}

void kubeconfig_exec_free(kubeconfig_exec_t * exec)
{
    if (!exec) {
        return;
    }

    if (exec->command) {
        free(exec->command);
        exec->command = NULL;
    }

    free(exec);
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
        if (property->auth_provider) {
            kubeconfig_auth_provider_free(property->auth_provider);
            property->auth_provider = NULL;
        }
        if (property->exec) {
            kubeconfig_exec_free(property->exec);
            property->exec = NULL;
        }
    }

    if (KUBECONFIG_PROPERTY_TYPE_CONTEXT == property->type) {
        if (property->cluster) {
            free(property->cluster);
            property->cluster = NULL;
        }
        if (property->user) {
            free(property->user);
            property->user = NULL;
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
