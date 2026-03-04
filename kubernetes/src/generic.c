#include "../include/apiClient.h"
#include "../include/generic.h"
#include "../include/utils.h"

void makeNamespacedResourcePath(char* path, genericClient_t *client, const char* namespace, const char* name);
void makeResourcePath(char* path, genericClient_t *client, const char* name);
char* callInternal(genericClient_t *client,
                   const char *path, list_t *queryParameters, list_t *headerParameters, list_t *formParameters, list_t *headerType, list_t *contentType, const char *body, const char *method);
char *callSimplifiedInternal(genericClient_t *client, const char *path, const char *method, const char *body, list_t *queryParameters);

genericClient_t* genericClient_create(apiClient_t *client, const char *apiGroup, const char* apiVersion, const char* resourcePlural) {
    genericClient_t *result = malloc(sizeof(genericClient_t));
    result->client = client;
    result->apiGroup = apiGroup ? strdup(apiGroup) : NULL;
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
    if (!client->apiGroup || strlen(client->apiGroup) == 0) {
        snprintf(path, 128, "/api/%s/namespaces/%s/%s/%s",
                 client->apiVersion, namespace, client->resourcePlural, name);
    } else {
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
}

void makeResourcePath(char* path, genericClient_t *client, const char* name) {
    if (!client->apiGroup || strlen(client->apiGroup) == 0) {
        snprintf(path, 128, "/api/%s/%s/%s", client->apiVersion, client->resourcePlural, name);
    } else {
        snprintf(
            path, 128,
            "/apis/%s/%s/%s/%s",
            client->apiGroup,
            client->apiVersion,
            client->resourcePlural,
            name
        );
    }
}

char* callInternal(genericClient_t *client,
                   const char *path, list_t *queryParameters, list_t *headerParameters, list_t *formParameters, list_t *headerType, list_t *contentType, const char *body, const char *method)
{
    size_t len = 0;
    if (body != NULL) {
        len = strlen(body);
    }
    apiClient_invoke(client->client, path, queryParameters, headerParameters, formParameters, headerType, contentType, body, len, method);

    if (client->client->response_code == 401) {
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

char *callSimplifiedInternal(genericClient_t *client, const char *path, const char *method, const char *body, list_t *queryParameters)
{
    return callInternal(client, path, queryParameters, NULL, NULL, NULL, NULL, body, method);
}

char* Generic_readNamespacedResource(genericClient_t *client, const char *namespace, const char *name) {
    char path[128];

    makeNamespacedResourcePath(path, client, namespace, name);
    return callSimplifiedInternal(client, path, "GET", NULL, NULL);
}

char* Generic_readResource(genericClient_t *client, const char *name) {
    char path[128];

    makeResourcePath(path, client, name);
    return callSimplifiedInternal(client, path, "GET", NULL, NULL);
}

char *Generic_listNamespaced(genericClient_t *client, const char *namespace, list_t *queryParameters) {
    char path[128];
    if (client->apiGroup && strlen(client->apiGroup)) {
        snprintf(path, 128, "/apis/%s/%s/namespaces/%s/%s",
                 client->apiGroup, client->apiVersion, namespace, client->resourcePlural);
    } else {
        snprintf(path, 128, "/api/%s/namespaces/%s/%s",
                 client->apiVersion, namespace, client->resourcePlural);
    }
    return callSimplifiedInternal(client, path, "GET", NULL, queryParameters);
}

char *Generic_list(genericClient_t *client, list_t *queryParameters) {
    char path[128];
    if (client->apiGroup && strlen(client->apiGroup)) {
        snprintf(path, 128, "/apis/%s/%s/%s",
                 client->apiGroup, client->apiVersion, client->resourcePlural);
    } else {
        snprintf(path, 128, "/api/%s/%s",
                 client->apiVersion, client->resourcePlural);
    }
    return callSimplifiedInternal(client, path, "GET", NULL, queryParameters);
}

char* Generic_deleteNamespacedResource(genericClient_t *client, const char *namespace, const char *name, const char* body) {
    char path[128];
    makeNamespacedResourcePath(path, client, namespace, name);
    return callSimplifiedInternal(client, path, "DELETE", body, NULL);
}

char* Generic_deleteResource(genericClient_t *client, const char* name, const char* body) {
    char path[128];
    makeResourcePath(path, client, name);
    return callSimplifiedInternal(client, path, "DELETE", body, NULL);
}

char* Generic_createNamespacedResource(genericClient_t *client, const char *ns, const char* body) {
    char path[128];
    makeNamespacedResourcePath(path, client, ns, "");
    return callSimplifiedInternal(client, path, "POST", body, NULL);
}

char* Generic_createResource(genericClient_t *client, const char* body) {
    char path[128];
    makeResourcePath(path, client, "");
    return callSimplifiedInternal(client, path, "POST", body, NULL);
}

char* Generic_replaceNamespacedResource(genericClient_t *client, const char *ns, const char *name, const char* body) {
    char path[128];
    makeNamespacedResourcePath(path, client, ns, name);
    return callSimplifiedInternal(client, path, "PUT", body, NULL);
}

char* Generic_replaceResource(genericClient_t *client, const char *name, const char* body) {
    char path[128];
    makeResourcePath(path, client, name);
    return callSimplifiedInternal(client, path, "PUT", body, NULL);
}

char* Generic_patchNamespacedResource(genericClient_t * client,
                                      const char *ns,
                                      const char *name, const char *body, list_t *queryParameters, list_t *headerParameters, list_t *formParameters, list_t *headerType, list_t *contentType)
{
    char path[128];
    makeNamespacedResourcePath(path, client, ns, name);
    return callInternal(client, path, queryParameters, headerParameters, formParameters, headerType, contentType, body, "PATCH");
}

char* Generic_patchResource(genericClient_t * client,
                            const char *name, const char *body, list_t *queryParameters, list_t *headerParameters, list_t *formParameters, list_t *headerType, list_t *contentType)
{
    char path[128];
    makeResourcePath(path, client, name);
    return callInternal(client, path, queryParameters, headerParameters, formParameters, headerType, contentType, body, "PATCH");
}
