#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_node_address.h"


char* typev1_node_address_ToString(kubernetes_v1_node_address_TYPE_e type) {
    char* typeArray[] =  { "NULL", "ExternalDNS", "ExternalIP", "Hostname", "InternalDNS", "InternalIP" };
	return typeArray[type];
}

kubernetes_v1_node_address_TYPE_e typev1_node_address_FromString(char* type){
    int stringToReturn = 0;
    char *typeArray[] =  { "NULL", "ExternalDNS", "ExternalIP", "Hostname", "InternalDNS", "InternalIP" };
    size_t sizeofArray = sizeof(typeArray) / sizeof(typeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(type, typeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

v1_node_address_t *v1_node_address_create(
    char *address,
    kubernetes_v1_node_address_TYPE_e type
    ) {
    v1_node_address_t *v1_node_address_local_var = malloc(sizeof(v1_node_address_t));
    if (!v1_node_address_local_var) {
        return NULL;
    }
    v1_node_address_local_var->address = address;
    v1_node_address_local_var->type = type;

    return v1_node_address_local_var;
}


void v1_node_address_free(v1_node_address_t *v1_node_address) {
    if(NULL == v1_node_address){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_node_address->address) {
        free(v1_node_address->address);
        v1_node_address->address = NULL;
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
    
    if(cJSON_AddStringToObject(item, "type", typev1_node_address_ToString(v1_node_address->type)) == NULL)
    {
    goto fail; //Enum
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
    if (!address) {
        goto end;
    }

    
    if(!cJSON_IsString(address))
    {
    goto end; //String
    }

    // v1_node_address->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1_node_addressJSON, "type");
    if (!type) {
        goto end;
    }

    kubernetes_v1_node_address_TYPE_e typeVariable;
    
    if(!cJSON_IsString(type))
    {
    goto end; //Enum
    }
    typeVariable = typev1_node_address_FromString(type->valuestring);


    v1_node_address_local_var = v1_node_address_create (
        strdup(address->valuestring),
        typeVariable
        );

    return v1_node_address_local_var;
end:
    return NULL;

}
