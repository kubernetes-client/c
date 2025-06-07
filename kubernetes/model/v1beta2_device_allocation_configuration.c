#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_device_allocation_configuration.h"



static v1beta2_device_allocation_configuration_t *v1beta2_device_allocation_configuration_create_internal(
    v1beta2_opaque_device_configuration_t *opaque,
    list_t *requests,
    char *source
    ) {
    v1beta2_device_allocation_configuration_t *v1beta2_device_allocation_configuration_local_var = malloc(sizeof(v1beta2_device_allocation_configuration_t));
    if (!v1beta2_device_allocation_configuration_local_var) {
        return NULL;
    }
    v1beta2_device_allocation_configuration_local_var->opaque = opaque;
    v1beta2_device_allocation_configuration_local_var->requests = requests;
    v1beta2_device_allocation_configuration_local_var->source = source;

    v1beta2_device_allocation_configuration_local_var->_library_owned = 1;
    return v1beta2_device_allocation_configuration_local_var;
}

__attribute__((deprecated)) v1beta2_device_allocation_configuration_t *v1beta2_device_allocation_configuration_create(
    v1beta2_opaque_device_configuration_t *opaque,
    list_t *requests,
    char *source
    ) {
    return v1beta2_device_allocation_configuration_create_internal (
        opaque,
        requests,
        source
        );
}

void v1beta2_device_allocation_configuration_free(v1beta2_device_allocation_configuration_t *v1beta2_device_allocation_configuration) {
    if(NULL == v1beta2_device_allocation_configuration){
        return ;
    }
    if(v1beta2_device_allocation_configuration->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta2_device_allocation_configuration_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta2_device_allocation_configuration->opaque) {
        v1beta2_opaque_device_configuration_free(v1beta2_device_allocation_configuration->opaque);
        v1beta2_device_allocation_configuration->opaque = NULL;
    }
    if (v1beta2_device_allocation_configuration->requests) {
        list_ForEach(listEntry, v1beta2_device_allocation_configuration->requests) {
            free(listEntry->data);
        }
        list_freeList(v1beta2_device_allocation_configuration->requests);
        v1beta2_device_allocation_configuration->requests = NULL;
    }
    if (v1beta2_device_allocation_configuration->source) {
        free(v1beta2_device_allocation_configuration->source);
        v1beta2_device_allocation_configuration->source = NULL;
    }
    free(v1beta2_device_allocation_configuration);
}

cJSON *v1beta2_device_allocation_configuration_convertToJSON(v1beta2_device_allocation_configuration_t *v1beta2_device_allocation_configuration) {
    cJSON *item = cJSON_CreateObject();

    // v1beta2_device_allocation_configuration->opaque
    if(v1beta2_device_allocation_configuration->opaque) {
    cJSON *opaque_local_JSON = v1beta2_opaque_device_configuration_convertToJSON(v1beta2_device_allocation_configuration->opaque);
    if(opaque_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "opaque", opaque_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1beta2_device_allocation_configuration->requests
    if(v1beta2_device_allocation_configuration->requests) {
    cJSON *requests = cJSON_AddArrayToObject(item, "requests");
    if(requests == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *requestsListEntry;
    list_ForEach(requestsListEntry, v1beta2_device_allocation_configuration->requests) {
    if(cJSON_AddStringToObject(requests, "", requestsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1beta2_device_allocation_configuration->source
    if (!v1beta2_device_allocation_configuration->source) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "source", v1beta2_device_allocation_configuration->source) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta2_device_allocation_configuration_t *v1beta2_device_allocation_configuration_parseFromJSON(cJSON *v1beta2_device_allocation_configurationJSON){

    v1beta2_device_allocation_configuration_t *v1beta2_device_allocation_configuration_local_var = NULL;

    // define the local variable for v1beta2_device_allocation_configuration->opaque
    v1beta2_opaque_device_configuration_t *opaque_local_nonprim = NULL;

    // define the local list for v1beta2_device_allocation_configuration->requests
    list_t *requestsList = NULL;

    // v1beta2_device_allocation_configuration->opaque
    cJSON *opaque = cJSON_GetObjectItemCaseSensitive(v1beta2_device_allocation_configurationJSON, "opaque");
    if (cJSON_IsNull(opaque)) {
        opaque = NULL;
    }
    if (opaque) { 
    opaque_local_nonprim = v1beta2_opaque_device_configuration_parseFromJSON(opaque); //nonprimitive
    }

    // v1beta2_device_allocation_configuration->requests
    cJSON *requests = cJSON_GetObjectItemCaseSensitive(v1beta2_device_allocation_configurationJSON, "requests");
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

    // v1beta2_device_allocation_configuration->source
    cJSON *source = cJSON_GetObjectItemCaseSensitive(v1beta2_device_allocation_configurationJSON, "source");
    if (cJSON_IsNull(source)) {
        source = NULL;
    }
    if (!source) {
        goto end;
    }

    
    if(!cJSON_IsString(source))
    {
    goto end; //String
    }


    v1beta2_device_allocation_configuration_local_var = v1beta2_device_allocation_configuration_create_internal (
        opaque ? opaque_local_nonprim : NULL,
        requests ? requestsList : NULL,
        strdup(source->valuestring)
        );

    return v1beta2_device_allocation_configuration_local_var;
end:
    if (opaque_local_nonprim) {
        v1beta2_opaque_device_configuration_free(opaque_local_nonprim);
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
