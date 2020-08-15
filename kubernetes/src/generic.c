#include "../include/apiClient.h"
#include "../include/generic.h"

genericClient_t* genericClient_create(apiClient_t *client, const char *apiGroup, const char* apiVersion, const char* resourcePlural) {
    genericClient_t *result = malloc(sizeof(genericClient_t));
    result->client = client;
    result->apiGroup = strdup(apiGroup);
    result->apiVersion = strdup(apiVersion);
    result->resourcePlural = strdup(resourcePlural);

    return result;
}

void genericClient_free(genericClient_t* client) {
    free(client->apiGroup);
    free(client->apiVersion);
    free(client->resourcePlural);
    free(client);
}

void makeNamespacedResourcePath(char* path, genericClient_t *client, const char* namespace, const char* name) {
    snprintf(
        path, 128,
        "/apis/%s/%s/namespaces/%s/%s/%s",
        client->apiGroup,
        client->apiVersion,
        namespace,
        client->resourcePlural,
        name
    );
}

void makeResourcePath(char* path, genericClient_t *client, const char* name) {
    snprintf(
        path, 128,
        "/apis/%s/%s/%s/%s",
        client->apiGroup,
        client->apiVersion,
        client->resourcePlural,
        name
    );
}

char* readInternal(genericClient_t *client, const char* path) {
    apiClient_invoke(client->client, path, NULL, NULL, NULL, NULL, NULL, NULL, "GET");

    if (client->client->response_code == 200) {
        printf("%s\n","OK");
    }
    if (client->client->response_code == 401) {
        printf("%s\n","Unauthorized");
        return NULL;
    }
    char* elementToReturn =  strndup((char*)client->client->dataReceived, client->client->dataReceivedLen);

    if (client->client->dataReceived) {
        free(client->client->dataReceived);
        client->client->dataReceived = NULL;
        client->client->dataReceivedLen = 0;
    }

    return elementToReturn;
}

char* Generic_readNamespacedResource(genericClient_t *client, const char *namespace, const char *name) {
    char path[128];

    makeNamespacedResourcePath(path, client, namespace, name);
    return readInternal(client, path);
}

char* Generic_readResource(genericClient_t *client, const char *name) {
    char path[128];

    makeResourcePath(path, client, name);
    return readInternal(client, path);
}

char *Generic_listNamespaced(genericClient_t *client, const char *namespace) {
    char path[128];
    snprintf(path, 128, "/apis/%s/%s/namespaces/%s/%s",
             client->apiGroup, client->apiVersion, namespace, client->resourcePlural);
    readInternal(client, path);
}

char *Generic_list(genericClient_t *client) {
    char path[128];
    snprintf(path, 128, "/apis/%s/%s", client->apiGroup, client->apiVersion, client->resourcePlural);
    readInternal(client, path);
}

