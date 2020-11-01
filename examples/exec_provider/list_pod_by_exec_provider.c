#include <kube_config.h>
#include <apiClient.h>
#include <CoreV1API.h>
#include <malloc.h>
#include <stdio.h>
#include <errno.h>

void list_pod(apiClient_t * apiClient)
{
    v1_pod_list_t *pod_list = NULL;
    pod_list = CoreV1API_listNamespacedPod(apiClient, "default",    /*namespace */
                                           NULL,    /* pretty */
                                           0,   /* allowWatchBookmarks */
                                           NULL,    /* continue */
                                           NULL,    /* fieldSelector */
                                           NULL,    /* labelSelector */
                                           0,   /* limit */
                                           NULL,    /* resourceVersion */
                                           0,   /* timeoutSeconds */
                                           0    /* watch */
        );
    printf("The return code of HTTP request=%ld\n", apiClient->response_code);
    if (pod_list) {
        printf("Get pod list:\n");
        listEntry_t *listEntry = NULL;
        v1_pod_t *pod = NULL;
        list_ForEach(listEntry, pod_list->items) {
            pod = listEntry->data;
            printf("\tThe pod name: %s\n", pod->metadata->name);
        }
        v1_pod_list_free(pod_list);
        pod_list = NULL;
    } else {
        printf("Cannot get any pod.\n");
    }
}

int main(int argc, char *argv[])
{
    int rc = 0;

    char *baseName = NULL;
    sslConfig_t *sslConfig = NULL;
    list_t *apiKeys = NULL;
    apiClient_t *k8sApiClient = NULL;

    rc = load_kube_config(&baseName, &sslConfig, &apiKeys, "./config_with_exec_provider");
    if (0 == rc) {
        k8sApiClient = apiClient_create_with_base_path(baseName, sslConfig, apiKeys);
    } else {
        printf("Cannot load kubernetes configuration.\n");
        return -1;
    }

    if (k8sApiClient) {
        list_pod(k8sApiClient);
    }

    free_client_config(baseName, sslConfig, apiKeys);
    baseName = NULL;
    sslConfig = NULL;
    apiKeys = NULL;

    apiClient_free(k8sApiClient);
    k8sApiClient = NULL;
    apiClient_unsetupGlobalEnv();

    return rc;
}
