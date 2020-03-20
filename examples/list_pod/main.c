#include <apiClient.h>
#include <CoreV1API.h>
#include <malloc.h>
#include <stdio.h>
#include <errno.h>

#define K8S_APISERVER_BASEPATH "https://your.server.here"
#define K8S_TOKEN_FILE_IN_CLUSTER "/var/run/secrets/kubernetes.io/serviceaccount/token"
#define K8S_TOKEN_BUF_SIZE 1024
#define K8S_AUTH_KEY "Authorization"
#define K8S_AUTH_VALUE_TEMPLATE "Bearer %s"

apiClient_t *g_k8sAPIConnector;

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
    printf("return code=%ld\n", apiClient->response_code);
    if (pod_list) {
        printf("Get pod list.\n");
        listEntry_t *listEntry = NULL;
        v1_pod_t *pod = NULL;
        list_ForEach(listEntry, pod_list->items) {
            pod = listEntry->data;
            printf("pod name=%s\n", pod->metadata->name);
        }
    } else {
        printf("Cannot list any pod.\n");
    }
}

int loadK8sConfigInCluster(char *token, int token_buf_size)
{
    static char fname[] = "loadK8sConfigInCluster()";

    FILE *fp;
    fp = fopen(K8S_TOKEN_FILE_IN_CLUSTER, "r");

    if (fp == NULL) {
        if (errno == ENOENT) {
            printf("%s: The file %s does not exist.", fname, K8S_TOKEN_FILE_IN_CLUSTER);
            return (-1);
        } else {
            printf("%s: Failed to open file %s.", fname, K8S_TOKEN_FILE_IN_CLUSTER);
            return (-1);
        }
    }

    while (fgets(token, token_buf_size, fp) != NULL) {
        ;
    }

    printf("%s\n", token);

    fclose(fp);

    return 0;
}

int init_k8s_connector(const char *token_out_of_cluster)
{
    list_t *apiKeys;
    apiKeys = list_create();

    char *keyToken = strdup(K8S_AUTH_KEY);

    char valueToken[K8S_TOKEN_BUF_SIZE];
    memset(valueToken, 0, sizeof(valueToken));

    sprintf(valueToken, K8S_AUTH_VALUE_TEMPLATE, token_out_of_cluster);

    keyValuePair_t *keyPairToken = keyValuePair_create(keyToken, valueToken);
    list_addElement(apiKeys, keyPairToken);

    g_k8sAPIConnector = apiClient_create_with_base_path(K8S_APISERVER_BASEPATH, NULL, apiKeys);
}

int main(int argc, char *argv[])
{
    init_k8s_connector(argv[1]);

    list_pod(g_k8sAPIConnector);

    apiClient_free(g_k8sAPIConnector);
}
