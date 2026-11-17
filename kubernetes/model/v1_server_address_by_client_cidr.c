#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_server_address_by_client_cidr.h"



static v1_server_address_by_client_cidr_t *v1_server_address_by_client_cidr_create_internal(
    char *client_cidr,
    char *server_address
    ) {
    v1_server_address_by_client_cidr_t *v1_server_address_by_client_cidr_local_var = malloc(sizeof(v1_server_address_by_client_cidr_t));
    if (!v1_server_address_by_client_cidr_local_var) {
        return NULL;
    }
    memset(v1_server_address_by_client_cidr_local_var, 0, sizeof(v1_server_address_by_client_cidr_t));
    v1_server_address_by_client_cidr_local_var->_library_owned = 1;
    v1_server_address_by_client_cidr_local_var->client_cidr = client_cidr;
    v1_server_address_by_client_cidr_local_var->server_address = server_address;
    return v1_server_address_by_client_cidr_local_var;
}

__attribute__((deprecated)) v1_server_address_by_client_cidr_t *v1_server_address_by_client_cidr_create(
    char *client_cidr,
    char *server_address
    ) {
    v1_server_address_by_client_cidr_t *result = v1_server_address_by_client_cidr_create_internal (
        client_cidr,
        server_address
        );
    if (!result) {
    }
    return result;
}

void v1_server_address_by_client_cidr_free(v1_server_address_by_client_cidr_t *v1_server_address_by_client_cidr) {
    if(NULL == v1_server_address_by_client_cidr){
        return ;
    }
    if(v1_server_address_by_client_cidr->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_server_address_by_client_cidr_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_server_address_by_client_cidr->client_cidr) {
        free(v1_server_address_by_client_cidr->client_cidr);
        v1_server_address_by_client_cidr->client_cidr = NULL;
    }
    if (v1_server_address_by_client_cidr->server_address) {
        free(v1_server_address_by_client_cidr->server_address);
        v1_server_address_by_client_cidr->server_address = NULL;
    }
    free(v1_server_address_by_client_cidr);
}

cJSON *v1_server_address_by_client_cidr_convertToJSON(v1_server_address_by_client_cidr_t *v1_server_address_by_client_cidr) {
    cJSON *item = cJSON_CreateObject();

    // v1_server_address_by_client_cidr->client_cidr
    if (!v1_server_address_by_client_cidr->client_cidr) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "clientCIDR", v1_server_address_by_client_cidr->client_cidr) == NULL) {
    goto fail; //String
    }


    // v1_server_address_by_client_cidr->server_address
    if (!v1_server_address_by_client_cidr->server_address) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "serverAddress", v1_server_address_by_client_cidr->server_address) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_server_address_by_client_cidr_t *v1_server_address_by_client_cidr_parseFromJSON(cJSON *v1_server_address_by_client_cidrJSON){

    v1_server_address_by_client_cidr_t *v1_server_address_by_client_cidr_local_var = NULL;

    char *client_cidr_local_str = NULL;

    char *server_address_local_str = NULL;

    // v1_server_address_by_client_cidr->client_cidr
    cJSON *client_cidr = cJSON_GetObjectItemCaseSensitive(v1_server_address_by_client_cidrJSON, "clientCIDR");
    if (cJSON_IsNull(client_cidr)) {
        client_cidr = NULL;
    }
    if (!client_cidr) {
        goto end;
    }

    
    if(!cJSON_IsString(client_cidr))
    {
    goto end; //String
    }

    // v1_server_address_by_client_cidr->server_address
    cJSON *server_address = cJSON_GetObjectItemCaseSensitive(v1_server_address_by_client_cidrJSON, "serverAddress");
    if (cJSON_IsNull(server_address)) {
        server_address = NULL;
    }
    if (!server_address) {
        goto end;
    }

    
    if(!cJSON_IsString(server_address))
    {
    goto end; //String
    }


    if (client_cidr && !cJSON_IsNull(client_cidr)) client_cidr_local_str = strdup(client_cidr->valuestring);
    if (server_address && !cJSON_IsNull(server_address)) server_address_local_str = strdup(server_address->valuestring);

    v1_server_address_by_client_cidr_local_var = v1_server_address_by_client_cidr_create_internal (
        client_cidr_local_str,
        server_address_local_str
        );

    if (!v1_server_address_by_client_cidr_local_var) {
        goto end;
    }

    return v1_server_address_by_client_cidr_local_var;
end:
    if (client_cidr_local_str) {
        free(client_cidr_local_str);
        client_cidr_local_str = NULL;
    }
    if (server_address_local_str) {
        free(server_address_local_str);
        server_address_local_str = NULL;
    }
    return NULL;

}
