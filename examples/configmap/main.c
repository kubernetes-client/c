#include <kube_config.h>
#include <apiClient.h>
#include <CoreV1API.h>
#include <malloc.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

void create_configmap(apiClient_t * apiClient, const char *name, const char *namespace_)
{ 
    char *api_version = strdup("v1");
    char *kind = strdup("ConfigMap");

    list_t *data = list_create();
    keyValuePair_t *kv = keyValuePair_create(strdup("worker1"), strdup("1"));
    list_addElement(data, kv);
    kv = keyValuePair_create(strdup("worker2"), strdup("2"));
    list_addElement(data, kv);

    v1_object_meta_t *meta = v1_object_meta_create(NULL,
                                                   NULL,
                                                   NULL,
                                                   0,
                                                   NULL,
                                                   NULL,
                                                   NULL,
                                                   0,
                                                   NULL,
                                                   NULL,
                                                   strdup(name),
                                                   strdup(namespace_),
                                                   NULL,
                                                   NULL,
                                                   NULL,
                                                   NULL);

    v1_config_map_t *body = v1_config_map_create(api_version,
                                                 NULL,
                                                 data,
                                                 kind,
                                                 meta);

    v1_config_map_t *ret_config_map = CoreV1API_createNamespacedConfigMap(apiClient,
                                                                        namespace_,
                                                                        body,
                                                                        NULL,
                                                                        NULL,
                                                                        NULL);

    printf("%s: The return code of HTTP request=%ld\n", __func__, apiClient->response_code);

    if (201 == apiClient->response_code) {
        printf("%s: Create the config map successfully.\n", __func__);
    } else {
        fprintf(stderr, "%s: Failed to create the config map.\n", __func__);
        return;
    }

    if (ret_config_map) {
        v1_config_map_free(ret_config_map);
        ret_config_map = NULL;
    }
    if (body) {
        v1_config_map_free(body);
        body = NULL;
    }
}

void list_configmap(apiClient_t * apiClient, const char *namespace_)
{
    v1_config_map_list_t *config_map_list = CoreV1API_listNamespacedConfigMap(apiClient,
                                                                              namespace_,    // char *namespace
                                                                              "true",   // char *pretty
                                                                              0,    // int allowWatchBookmarks
                                                                              NULL, // char * _continue
                                                                              NULL, // char * fieldSelector
                                                                              NULL, // char * labelSelector
                                                                              0,    // int limit
                                                                              NULL, // char * resourceVersion
                                                                              0,    // int timeoutSeconds
                                                                              0 //int watch
        );

    printf("%s: The return code of HTTP request=%ld\n", __func__, apiClient->response_code);

    if (200 == apiClient->response_code) {
        printf("%s: List the config maps successfully.\n", __func__);
    } else {
        fprintf(stderr, "%s: Failed to list the config maps.\n", __func__);
        return;
    }

    if (config_map_list && config_map_list->items) {
        listEntry_t *config_map_list_entry = NULL;
        v1_config_map_t *config_map = NULL;
        list_ForEach(config_map_list_entry, config_map_list->items) {
            config_map = config_map_list_entry->data;
            printf("\tThe config map name: %s\n", config_map->metadata->name);

            listEntry_t *data_entry = NULL;
            keyValuePair_t *pair = NULL;
            list_ForEach(data_entry, config_map->data) {
                pair = data_entry->data;
                printf("\tkey=%s, value=%s\n", pair->key, (char *) pair->value);
            }
        }
        v1_config_map_list_free(config_map_list);
        config_map_list = NULL;
    } else {
        fprintf(stderr, "%s: The config map list is invalid.\n", __func__);
    }
}

void delete_configmap(apiClient_t * apiClient, const char *name, const char *namespace_)
{
    v1_status_t *status = CoreV1API_deleteNamespacedConfigMap(apiClient,
                                                        name,   // char *name
                                                        namespace_,  // char *namespace
                                                        NULL,   // char *pretty
                                                        NULL,   // char *dryRun
                                                        0,  // int gracePeriodSeconds
                                                        0,  // int orphanDependents
                                                        NULL,   // char *propagationPolicy
                                                        NULL    // v1_delete_options_t *body
        );

    printf("The return code of HTTP request=%ld\n", apiClient->response_code);

    if (200 == apiClient->response_code || 202 == apiClient->response_code) {
        printf("The config map is deleted successfully.\n");
    } else {
        if (status && status->message) {
            printf("Failed to delete the config map. The error message: %s\n", status->message);
        }
    }

    if (status) {
        v1_status_free(status);
        status = NULL;
    }
}

int main(int argc, char *argv[])
{
    char *basePath = NULL;
    sslConfig_t *sslConfig = NULL;
    list_t *apiKeys = NULL;
    int rc = load_kube_config(&basePath, &sslConfig, &apiKeys, NULL);   /* NULL means loading configuration from $HOME/.kube/config */
    if (rc != 0) {
        fprintf(stderr, "Cannot load kubernetes configuration.\n");
        return -1;
    }
    apiClient_t *apiClient = apiClient_create_with_base_path(basePath, sslConfig, apiKeys);
    if (!apiClient) {
        fprintf(stderr, "Cannot create a kubernetes client.\n");
        return -1;
    }

    char *config_map_name = "cm1";
    char *namespace_ = "default";
    create_configmap(apiClient, config_map_name, namespace_);
    sleep(5);
    list_configmap(apiClient, namespace_);
    sleep(5);
    delete_configmap(apiClient, config_map_name, namespace_);

    apiClient_free(apiClient);
    apiClient = NULL;
    free_client_config(basePath, sslConfig, apiKeys);
    basePath = NULL;
    sslConfig = NULL;
    apiKeys = NULL;
    apiClient_unsetupGlobalEnv();

    return 0;
}
