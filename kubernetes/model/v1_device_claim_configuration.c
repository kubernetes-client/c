#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_device_claim_configuration.h"



static v1_device_claim_configuration_t *v1_device_claim_configuration_create_internal(
    v1_opaque_device_configuration_t *opaque,
    list_t *requests
    ) {
    v1_device_claim_configuration_t *v1_device_claim_configuration_local_var = malloc(sizeof(v1_device_claim_configuration_t));
    if (!v1_device_claim_configuration_local_var) {
        return NULL;
    }
    v1_device_claim_configuration_local_var->opaque = opaque;
    v1_device_claim_configuration_local_var->requests = requests;

    v1_device_claim_configuration_local_var->_library_owned = 1;
    return v1_device_claim_configuration_local_var;
}

__attribute__((deprecated)) v1_device_claim_configuration_t *v1_device_claim_configuration_create(
    v1_opaque_device_configuration_t *opaque,
    list_t *requests
    ) {
    return v1_device_claim_configuration_create_internal (
        opaque,
        requests
        );
}

void v1_device_claim_configuration_free(v1_device_claim_configuration_t *v1_device_claim_configuration) {
    if(NULL == v1_device_claim_configuration){
        return ;
    }
    if(v1_device_claim_configuration->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_device_claim_configuration_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_device_claim_configuration->opaque) {
        v1_opaque_device_configuration_free(v1_device_claim_configuration->opaque);
        v1_device_claim_configuration->opaque = NULL;
    }
    if (v1_device_claim_configuration->requests) {
        list_ForEach(listEntry, v1_device_claim_configuration->requests) {
            free(listEntry->data);
        }
        list_freeList(v1_device_claim_configuration->requests);
        v1_device_claim_configuration->requests = NULL;
    }
    free(v1_device_claim_configuration);
}

cJSON *v1_device_claim_configuration_convertToJSON(v1_device_claim_configuration_t *v1_device_claim_configuration) {
    cJSON *item = cJSON_CreateObject();

    // v1_device_claim_configuration->opaque
    if(v1_device_claim_configuration->opaque) {
    cJSON *opaque_local_JSON = v1_opaque_device_configuration_convertToJSON(v1_device_claim_configuration->opaque);
    if(opaque_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "opaque", opaque_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_device_claim_configuration->requests
    if(v1_device_claim_configuration->requests) {
    cJSON *requests = cJSON_AddArrayToObject(item, "requests");
    if(requests == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *requestsListEntry;
    list_ForEach(requestsListEntry, v1_device_claim_configuration->requests) {
    if(cJSON_AddStringToObject(requests, "", requestsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_device_claim_configuration_t *v1_device_claim_configuration_parseFromJSON(cJSON *v1_device_claim_configurationJSON){

    v1_device_claim_configuration_t *v1_device_claim_configuration_local_var = NULL;

    // define the local variable for v1_device_claim_configuration->opaque
    v1_opaque_device_configuration_t *opaque_local_nonprim = NULL;

    // define the local list for v1_device_claim_configuration->requests
    list_t *requestsList = NULL;

    // v1_device_claim_configuration->opaque
    cJSON *opaque = cJSON_GetObjectItemCaseSensitive(v1_device_claim_configurationJSON, "opaque");
    if (cJSON_IsNull(opaque)) {
        opaque = NULL;
    }
    if (opaque) { 
    opaque_local_nonprim = v1_opaque_device_configuration_parseFromJSON(opaque); //nonprimitive
    }

    // v1_device_claim_configuration->requests
    cJSON *requests = cJSON_GetObjectItemCaseSensitive(v1_device_claim_configurationJSON, "requests");
    if (cJSON_IsNull(requests)) {
        requests = NULL;
    }
    if (requests) { 
    cJSON *requests_local = NULL;
    if(!cJSON_IsArray(requests)) {
        goto end;//primitive container
    }
    requestsList = list_createList();

    cJSON_ArrayForEach(requests_local, requests)
    {
        if(!cJSON_IsString(requests_local))
        {
            goto end;
        }
        list_addElement(requestsList , strdup(requests_local->valuestring));
    }
    }


    v1_device_claim_configuration_local_var = v1_device_claim_configuration_create_internal (
        opaque ? opaque_local_nonprim : NULL,
        requests ? requestsList : NULL
        );

    return v1_device_claim_configuration_local_var;
end:
    if (opaque_local_nonprim) {
        v1_opaque_device_configuration_free(opaque_local_nonprim);
        opaque_local_nonprim = NULL;
    }
    if (requestsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, requestsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(requestsList);
        requestsList = NULL;
    }
    return NULL;

}
