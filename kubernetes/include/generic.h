#ifndef __GENERIC_H__
#define __GENERIC_H__

#include "../include/apiClient.h"

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

#endif