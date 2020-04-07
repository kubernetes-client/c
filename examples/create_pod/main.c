#include <kube_config.h>
#include <apiClient.h>
#include <CoreV1API.h>
#include <malloc.h>
#include <stdio.h>
#include <errno.h>

void create_a_pod(apiClient_t * apiClient)
{
    char *namespace = "default";

    v1_pod_t *podinfo = calloc(1, sizeof(v1_pod_t));
    podinfo->api_version = strdup("v1");
    podinfo->kind = strdup("Pod");
    podinfo->spec = calloc(1, sizeof(v1_pod_spec_t));

    podinfo->metadata = calloc(1, sizeof(v1_object_meta_t));
    podinfo->metadata->name = strdup("test-pod-6");

    list_t *containerlist = list_create();
    v1_container_t *con = calloc(1, sizeof(v1_container_t));
    con->name = strdup("my-container");
    con->image = strdup("ubuntu:16.04");
    con->image_pull_policy = strdup("IfNotPresent");

    list_t *commandlist = list_create();
    char *cmd = strdup("sleep");
    list_addElement(commandlist, cmd);
    con->command = commandlist;

    list_t *arglist = list_create();
    char *arg1 = strdup("3600");
    list_addElement(arglist, arg1);
    con->args = arglist;

    list_addElement(containerlist, con);
    podinfo->spec->containers = containerlist;

    v1_pod_t *apod = CoreV1API_createNamespacedPod(apiClient, namespace, podinfo, NULL, NULL, NULL);
    printf("code=%ld\n", apiClient->response_code);

    v1_pod_free(apod);
}

int main(int argc, char *argv[])
{

    int rc = 0;

    char *baseName = NULL;
    sslConfig_t *sslConfig = NULL;
    list_t *apiKeys = NULL;
    apiClient_t *k8sApiClient = NULL;

    rc = load_kube_config(&baseName, &sslConfig, &apiKeys, NULL);
    if (0 == rc) {
        k8sApiClient = apiClient_create_with_base_path(baseName, sslConfig, apiKeys);
    } else {
        printf("Cannot load kubernetes configuration.\n");
        return -1;
    }

    if (k8sApiClient) {
        create_a_pod(k8sApiClient);
    }

    free_client_config(baseName, sslConfig, apiKeys);
    baseName = NULL;
    sslConfig = NULL;
    apiKeys = NULL;

    apiClient_free(k8sApiClient);
    k8sApiClient = NULL;

}
