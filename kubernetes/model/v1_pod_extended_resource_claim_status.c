#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_extended_resource_claim_status.h"



static v1_pod_extended_resource_claim_status_t *v1_pod_extended_resource_claim_status_create_internal(
    list_t *request_mappings,
    char *resource_claim_name
    ) {
    v1_pod_extended_resource_claim_status_t *v1_pod_extended_resource_claim_status_local_var = malloc(sizeof(v1_pod_extended_resource_claim_status_t));
    if (!v1_pod_extended_resource_claim_status_local_var) {
        return NULL;
    }
    v1_pod_extended_resource_claim_status_local_var->request_mappings = request_mappings;
    v1_pod_extended_resource_claim_status_local_var->resource_claim_name = resource_claim_name;

    v1_pod_extended_resource_claim_status_local_var->_library_owned = 1;
    return v1_pod_extended_resource_claim_status_local_var;
}

__attribute__((deprecated)) v1_pod_extended_resource_claim_status_t *v1_pod_extended_resource_claim_status_create(
    list_t *request_mappings,
    char *resource_claim_name
    ) {
    return v1_pod_extended_resource_claim_status_create_internal (
        request_mappings,
        resource_claim_name
        );
}

void v1_pod_extended_resource_claim_status_free(v1_pod_extended_resource_claim_status_t *v1_pod_extended_resource_claim_status) {
    if(NULL == v1_pod_extended_resource_claim_status){
        return ;
    }
    if(v1_pod_extended_resource_claim_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_pod_extended_resource_claim_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_pod_extended_resource_claim_status->request_mappings) {
        list_ForEach(listEntry, v1_pod_extended_resource_claim_status->request_mappings) {
            v1_container_extended_resource_request_free(listEntry->data);
        }
        list_freeList(v1_pod_extended_resource_claim_status->request_mappings);
        v1_pod_extended_resource_claim_status->request_mappings = NULL;
    }
    if (v1_pod_extended_resource_claim_status->resource_claim_name) {
        free(v1_pod_extended_resource_claim_status->resource_claim_name);
        v1_pod_extended_resource_claim_status->resource_claim_name = NULL;
    }
    free(v1_pod_extended_resource_claim_status);
}

cJSON *v1_pod_extended_resource_claim_status_convertToJSON(v1_pod_extended_resource_claim_status_t *v1_pod_extended_resource_claim_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_pod_extended_resource_claim_status->request_mappings
    if (!v1_pod_extended_resource_claim_status->request_mappings) {
        goto fail;
    }
    cJSON *request_mappings = cJSON_AddArrayToObject(item, "requestMappings");
    if(request_mappings == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *request_mappingsListEntry;
    if (v1_pod_extended_resource_claim_status->request_mappings) {
    list_ForEach(request_mappingsListEntry, v1_pod_extended_resource_claim_status->request_mappings) {
    cJSON *itemLocal = v1_container_extended_resource_request_convertToJSON(request_mappingsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(request_mappings, itemLocal);
    }
    }


    // v1_pod_extended_resource_claim_status->resource_claim_name
    if (!v1_pod_extended_resource_claim_status->resource_claim_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "resourceClaimName", v1_pod_extended_resource_claim_status->resource_claim_name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_pod_extended_resource_claim_status_t *v1_pod_extended_resource_claim_status_parseFromJSON(cJSON *v1_pod_extended_resource_claim_statusJSON){

    v1_pod_extended_resource_claim_status_t *v1_pod_extended_resource_claim_status_local_var = NULL;

    // define the local list for v1_pod_extended_resource_claim_status->request_mappings
    list_t *request_mappingsList = NULL;

    // v1_pod_extended_resource_claim_status->request_mappings
    cJSON *request_mappings = cJSON_GetObjectItemCaseSensitive(v1_pod_extended_resource_claim_statusJSON, "requestMappings");
    if (cJSON_IsNull(request_mappings)) {
        request_mappings = NULL;
    }
    if (!request_mappings) {
        goto end;
    }

    
    cJSON *request_mappings_local_nonprimitive = NULL;
    if(!cJSON_IsArray(request_mappings)){
        goto end; //nonprimitive container
    }

    request_mappingsList = list_createList();

    cJSON_ArrayForEach(request_mappings_local_nonprimitive,request_mappings )
    {
        if(!cJSON_IsObject(request_mappings_local_nonprimitive)){
            goto end;
        }
        v1_container_extended_resource_request_t *request_mappingsItem = v1_container_extended_resource_request_parseFromJSON(request_mappings_local_nonprimitive);

        list_addElement(request_mappingsList, request_mappingsItem);
    }

    // v1_pod_extended_resource_claim_status->resource_claim_name
    cJSON *resource_claim_name = cJSON_GetObjectItemCaseSensitive(v1_pod_extended_resource_claim_statusJSON, "resourceClaimName");
    if (cJSON_IsNull(resource_claim_name)) {
        resource_claim_name = NULL;
    }
    if (!resource_claim_name) {
        goto end;
    }

    
    if(!cJSON_IsString(resource_claim_name))
    {
    goto end; //String
    }


    v1_pod_extended_resource_claim_status_local_var = v1_pod_extended_resource_claim_status_create_internal (
        request_mappingsList,
        strdup(resource_claim_name->valuestring)
        );

    return v1_pod_extended_resource_claim_status_local_var;
end:
    if (request_mappingsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, request_mappingsList) {
            v1_container_extended_resource_request_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(request_mappingsList);
        request_mappingsList = NULL;
    }
    return NULL;

}
