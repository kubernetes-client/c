#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_node_address.h"



static v1_node_address_t *v1_node_address_create_internal(
    char *address,
    char *type
    ) {
    v1_node_address_t *v1_node_address_local_var = malloc(sizeof(v1_node_address_t));
    if (!v1_node_address_local_var) {
        return NULL;
    }
    v1_node_address_local_var->address = address;
    v1_node_address_local_var->type = type;

    v1_node_address_local_var->_library_owned = 1;
    return v1_node_address_local_var;
}

__attribute__((deprecated)) v1_node_address_t *v1_node_address_create(
    char *address,
    char *type
    ) {
    return v1_node_address_create_internal (
        address,
        type
        );
}

void v1_node_address_free(v1_node_address_t *v1_node_address) {
    if(NULL == v1_node_address){
        return ;
    }
    if(v1_node_address->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_node_address_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_node_address->address) {
        free(v1_node_address->address);
        v1_node_address->address = NULL;
    }
    if (v1_node_address->type) {
        free(v1_node_address->type);
        v1_node_address->type = NULL;
    }
    free(v1_node_address);
}

cJSON *v1_node_address_convertToJSON(v1_node_address_t *v1_node_address) {
    cJSON *item = cJSON_CreateObject();

    // v1_node_address->address
    if (!v1_node_address->address) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "address", v1_node_address->address) == NULL) {
    goto fail; //String
    }


    // v1_node_address->type
    if (!v1_node_address->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", v1_node_address->type) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_node_address_t *v1_node_address_parseFromJSON(cJSON *v1_node_addressJSON){

    v1_node_address_t *v1_node_address_local_var = NULL;

    // v1_node_address->address
    cJSON *address = cJSON_GetObjectItemCaseSensitive(v1_node_addressJSON, "address");
    if (cJSON_IsNull(address)) {
        address = NULL;
    }
    if (!address) {
        goto end;
    }

    
    if(!cJSON_IsString(address))
    {
    goto end; //String
    }

    // v1_node_address->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1_node_addressJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }


    v1_node_address_local_var = v1_node_address_create_internal (
        strdup(address->valuestring),
        strdup(type->valuestring)
        );

    return v1_node_address_local_var;
end:
    return NULL;

}
