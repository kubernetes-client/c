#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha2_resource_claim_parameters.h"



v1alpha2_resource_claim_parameters_t *v1alpha2_resource_claim_parameters_create(
    char *api_version,
    list_t *driver_requests,
    v1alpha2_resource_claim_parameters_reference_t *generated_from,
    char *kind,
    v1_object_meta_t *metadata,
    int shareable
    ) {
    v1alpha2_resource_claim_parameters_t *v1alpha2_resource_claim_parameters_local_var = malloc(sizeof(v1alpha2_resource_claim_parameters_t));
    if (!v1alpha2_resource_claim_parameters_local_var) {
        return NULL;
    }
    v1alpha2_resource_claim_parameters_local_var->api_version = api_version;
    v1alpha2_resource_claim_parameters_local_var->driver_requests = driver_requests;
    v1alpha2_resource_claim_parameters_local_var->generated_from = generated_from;
    v1alpha2_resource_claim_parameters_local_var->kind = kind;
    v1alpha2_resource_claim_parameters_local_var->metadata = metadata;
    v1alpha2_resource_claim_parameters_local_var->shareable = shareable;

    return v1alpha2_resource_claim_parameters_local_var;
}


void v1alpha2_resource_claim_parameters_free(v1alpha2_resource_claim_parameters_t *v1alpha2_resource_claim_parameters) {
    if(NULL == v1alpha2_resource_claim_parameters){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha2_resource_claim_parameters->api_version) {
        free(v1alpha2_resource_claim_parameters->api_version);
        v1alpha2_resource_claim_parameters->api_version = NULL;
    }
    if (v1alpha2_resource_claim_parameters->driver_requests) {
        list_ForEach(listEntry, v1alpha2_resource_claim_parameters->driver_requests) {
            v1alpha2_driver_requests_free(listEntry->data);
        }
        list_freeList(v1alpha2_resource_claim_parameters->driver_requests);
        v1alpha2_resource_claim_parameters->driver_requests = NULL;
    }
    if (v1alpha2_resource_claim_parameters->generated_from) {
        v1alpha2_resource_claim_parameters_reference_free(v1alpha2_resource_claim_parameters->generated_from);
        v1alpha2_resource_claim_parameters->generated_from = NULL;
    }
    if (v1alpha2_resource_claim_parameters->kind) {
        free(v1alpha2_resource_claim_parameters->kind);
        v1alpha2_resource_claim_parameters->kind = NULL;
    }
    if (v1alpha2_resource_claim_parameters->metadata) {
        v1_object_meta_free(v1alpha2_resource_claim_parameters->metadata);
        v1alpha2_resource_claim_parameters->metadata = NULL;
    }
    free(v1alpha2_resource_claim_parameters);
}

cJSON *v1alpha2_resource_claim_parameters_convertToJSON(v1alpha2_resource_claim_parameters_t *v1alpha2_resource_claim_parameters) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha2_resource_claim_parameters->api_version
    if(v1alpha2_resource_claim_parameters->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1alpha2_resource_claim_parameters->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha2_resource_claim_parameters->driver_requests
    if(v1alpha2_resource_claim_parameters->driver_requests) {
    cJSON *driver_requests = cJSON_AddArrayToObject(item, "driverRequests");
    if(driver_requests == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *driver_requestsListEntry;
    if (v1alpha2_resource_claim_parameters->driver_requests) {
    list_ForEach(driver_requestsListEntry, v1alpha2_resource_claim_parameters->driver_requests) {
    cJSON *itemLocal = v1alpha2_driver_requests_convertToJSON(driver_requestsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(driver_requests, itemLocal);
    }
    }
    }


    // v1alpha2_resource_claim_parameters->generated_from
    if(v1alpha2_resource_claim_parameters->generated_from) {
    cJSON *generated_from_local_JSON = v1alpha2_resource_claim_parameters_reference_convertToJSON(v1alpha2_resource_claim_parameters->generated_from);
    if(generated_from_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "generatedFrom", generated_from_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha2_resource_claim_parameters->kind
    if(v1alpha2_resource_claim_parameters->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1alpha2_resource_claim_parameters->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha2_resource_claim_parameters->metadata
    if(v1alpha2_resource_claim_parameters->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1alpha2_resource_claim_parameters->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha2_resource_claim_parameters->shareable
    if(v1alpha2_resource_claim_parameters->shareable) {
    if(cJSON_AddBoolToObject(item, "shareable", v1alpha2_resource_claim_parameters->shareable) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha2_resource_claim_parameters_t *v1alpha2_resource_claim_parameters_parseFromJSON(cJSON *v1alpha2_resource_claim_parametersJSON){

    v1alpha2_resource_claim_parameters_t *v1alpha2_resource_claim_parameters_local_var = NULL;

    // define the local list for v1alpha2_resource_claim_parameters->driver_requests
    list_t *driver_requestsList = NULL;

    // define the local variable for v1alpha2_resource_claim_parameters->generated_from
    v1alpha2_resource_claim_parameters_reference_t *generated_from_local_nonprim = NULL;

    // define the local variable for v1alpha2_resource_claim_parameters->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // v1alpha2_resource_claim_parameters->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1alpha2_resource_claim_parametersJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1alpha2_resource_claim_parameters->driver_requests
    cJSON *driver_requests = cJSON_GetObjectItemCaseSensitive(v1alpha2_resource_claim_parametersJSON, "driverRequests");
    if (driver_requests) { 
    cJSON *driver_requests_local_nonprimitive = NULL;
    if(!cJSON_IsArray(driver_requests)){
        goto end; //nonprimitive container
    }

    driver_requestsList = list_createList();

    cJSON_ArrayForEach(driver_requests_local_nonprimitive,driver_requests )
    {
        if(!cJSON_IsObject(driver_requests_local_nonprimitive)){
            goto end;
        }
        v1alpha2_driver_requests_t *driver_requestsItem = v1alpha2_driver_requests_parseFromJSON(driver_requests_local_nonprimitive);

        list_addElement(driver_requestsList, driver_requestsItem);
    }
    }

    // v1alpha2_resource_claim_parameters->generated_from
    cJSON *generated_from = cJSON_GetObjectItemCaseSensitive(v1alpha2_resource_claim_parametersJSON, "generatedFrom");
    if (generated_from) { 
    generated_from_local_nonprim = v1alpha2_resource_claim_parameters_reference_parseFromJSON(generated_from); //nonprimitive
    }

    // v1alpha2_resource_claim_parameters->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1alpha2_resource_claim_parametersJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1alpha2_resource_claim_parameters->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1alpha2_resource_claim_parametersJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1alpha2_resource_claim_parameters->shareable
    cJSON *shareable = cJSON_GetObjectItemCaseSensitive(v1alpha2_resource_claim_parametersJSON, "shareable");
    if (shareable) { 
    if(!cJSON_IsBool(shareable))
    {
    goto end; //Bool
    }
    }


    v1alpha2_resource_claim_parameters_local_var = v1alpha2_resource_claim_parameters_create (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        driver_requests ? driver_requestsList : NULL,
        generated_from ? generated_from_local_nonprim : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        shareable ? shareable->valueint : 0
        );

    return v1alpha2_resource_claim_parameters_local_var;
end:
    if (driver_requestsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, driver_requestsList) {
            v1alpha2_driver_requests_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(driver_requestsList);
        driver_requestsList = NULL;
    }
    if (generated_from_local_nonprim) {
        v1alpha2_resource_claim_parameters_reference_free(generated_from_local_nonprim);
        generated_from_local_nonprim = NULL;
    }
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    return NULL;

}
