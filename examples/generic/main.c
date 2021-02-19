#include <kube_config.h>
#include <apiClient.h>
#include <generic.h>
#include <malloc.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    char *basePath = NULL;
    sslConfig_t *sslConfig = NULL;
    list_t *apiKeys = NULL;
    int rc = load_kube_config(&basePath, &sslConfig, &apiKeys, NULL);   /* NULL means loading configuration from $HOME/.kube/config */
    if (rc != 0) {
        printf("Cannot load kubernetes configuration.\n");
        return -1;
    }
    apiClient_t *apiClient = apiClient_create_with_base_path(basePath, sslConfig, apiKeys);
    if (!apiClient) {
        printf("Cannot create a kubernetes client.\n");
        return -1;
    }

    genericClient_t *genericClient = genericClient_create(apiClient, "apps", "v1", "deployments");

    char *list = Generic_listNamespaced(genericClient, "default");
    printf("%s\n", list);
    free(list);

    char *result = Generic_readNamespacedResource(genericClient, "default", "camera-gc");
    printf("%s\n", result);
    free(result);

    genericClient_free(genericClient);
    genericClient = NULL;

    genericClient = genericClient_create(apiClient, "", "v1", "namespaces");

    const char *body = "{\"apiVersion\": \"v1\", \"kind\": \"Namespace\", \"metadata\": { \"name\": \"test\" } }";
    char *create = Generic_createResource(genericClient, body);
    printf("%s\n", create);
    free(create);

    const char *updateBody = "{\"apiVersion\": \"v1\", \"kind\": \"Namespace\", \"metadata\": { \"name\": \"test\", \"labels\": { \"foo\": \"bar\" } } }";
    char *update = Generic_replaceResource(genericClient, "test", updateBody);
    printf("%s\n", update);
    free(update);

    const char *patchBody = "[{\"op\": \"replace\", \"path\": \"/metadata/labels/foo\", \"value\": \"qux\" }]";
    list_t *contentType = list_create();
    // Kubernetes supports multiple content types:
    list_addElement(contentType, "application/json-patch+json");
    // list_addElement(contentType, "application/merge-patch+json");
    // list_addElement(contentType, "application/strategic-merge-patch+json");
    // list_addElement(contentType, "application/apply-patch+yaml");
    char *patch = Generic_patchResource(genericClient, "test", patchBody, NULL, NULL, NULL, NULL, contentType);
    printf("%s\n", patch);
    list_free(contentType);
    free(patch);

    char *del = Generic_deleteResource(genericClient, "test");
    printf("%s\n", del);
    free(del);

    genericClient_free(genericClient);
    genericClient = NULL;

    apiClient_free(apiClient);
    apiClient = NULL;
    free_client_config(basePath, sslConfig, apiKeys);
    basePath = NULL;
    sslConfig = NULL;
    apiKeys = NULL;
    apiClient_unsetupGlobalEnv();

    return 0;
}
