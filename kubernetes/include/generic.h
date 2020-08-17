#ifndef __GENERIC_H__
#define __GENERIC_H__

#include "../include/apiClient.h"

#ifdef  __cplusplus
extern "C" {
#endif

typedef struct genericClient_t {
    apiClient_t *client;
    char *apiGroup;
    char *apiVersion;
    char *resourcePlural; 
} genericClient_t;

genericClient_t* genericClient_create(apiClient_t *client, const char *apiGroup, const char* apiVersion, const char* resourcePlural);
void genericClient_free(genericClient_t* client);

char* Generic_readNamespacedResource(genericClient_t *client, const char *ns, const char *name);
char* Generic_readResource(genericClient_t *client, const char *name);

char* Generic_listNamespaced(genericClient_t *client, const char *ns);
char* Generic_list(genericClient_t *client);

char* Generic_deleteNamespacedResource(genericClient_t *client, const char *ns, const char *name);
char* Generic_deleteResource(genericClient_t *client, const char* name);

char* Generic_createNamespacedResource(genericClient_t *client, const char *ns, const char* body);
char* Generic_createResource(genericClient_t *client, const char* body);

char* Generic_replaceNamespacedResource(genericClient_t *client, const char *ns, const char *name, const char* body);
char* Generic_replaceResource(genericClient_t *client, const char *name, const char* body);

#ifdef  __cplusplus
}
#endif

#endif // __GENERIC_H__