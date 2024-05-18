#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha2_structured_resource_handle.h"



v1alpha2_structured_resource_handle_t *v1alpha2_structured_resource_handle_create(
    char *node_name,
    list_t *results,
    object_t *vendor_claim_parameters,
    object_t *vendor_class_parameters
    ) {
    v1alpha2_structured_resource_handle_t *v1alpha2_structured_resource_handle_local_var = malloc(sizeof(v1alpha2_structured_resource_handle_t));
    if (!v1alpha2_structured_resource_handle_local_var) {
        return NULL;
    }
    v1alpha2_structured_resource_handle_local_var->node_name = node_name;
    v1alpha2_structured_resource_handle_local_var->results = results;
    v1alpha2_structured_resource_handle_local_var->vendor_claim_parameters = vendor_claim_parameters;
    v1alpha2_structured_resource_handle_local_var->vendor_class_parameters = vendor_class_parameters;

    return v1alpha2_structured_resource_handle_local_var;
}


void v1alpha2_structured_resource_handle_free(v1alpha2_structured_resource_handle_t *v1alpha2_structured_resource_handle) {
    if(NULL == v1alpha2_structured_resource_handle){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha2_structured_resource_handle->node_name) {
        free(v1alpha2_structured_resource_handle->node_name);
        v1alpha2_structured_resource_handle->node_name = NULL;
    }
    if (v1alpha2_structured_resource_handle->results) {
        list_ForEach(listEntry, v1alpha2_structured_resource_handle->results) {
            v1alpha2_driver_allocation_result_free(listEntry->data);
        }
        list_freeList(v1alpha2_structured_resource_handle->results);
        v1alpha2_structured_resource_handle->results = NULL;
    }
    if (v1alpha2_structured_resource_handle->vendor_claim_parameters) {
        object_free(v1alpha2_structured_resource_handle->vendor_claim_parameters);
        v1alpha2_structured_resource_handle->vendor_claim_parameters = NULL;
    }
    if (v1alpha2_structured_resource_handle->vendor_class_parameters) {
        object_free(v1alpha2_structured_resource_handle->vendor_class_parameters);
        v1alpha2_structured_resource_handle->vendor_class_parameters = NULL;
    }
    free(v1alpha2_structured_resource_handle);
}

cJSON *v1alpha2_structured_resource_handle_convertToJSON(v1alpha2_structured_resource_handle_t *v1alpha2_structured_resource_handle) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha2_structured_resource_handle->node_name
    if(v1alpha2_structured_resource_handle->node_name) {
    if(cJSON_AddStringToObject(item, "nodeName", v1alpha2_structured_resource_handle->node_name) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha2_structured_resource_handle->results
    if (!v1alpha2_structured_resource_handle->results) {
        goto fail;
    }
    cJSON *results = cJSON_AddArrayToObject(item, "results");
    if(results == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resultsListEntry;
    if (v1alpha2_structured_resource_handle->results) {
    list_ForEach(resultsListEntry, v1alpha2_structured_resource_handle->results) {
    cJSON *itemLocal = v1alpha2_driver_allocation_result_convertToJSON(resultsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(results, itemLocal);
    }
    }


    // v1alpha2_structured_resource_handle->vendor_claim_parameters
    if(v1alpha2_structured_resource_handle->vendor_claim_parameters) {
    cJSON *vendor_claim_parameters_object = object_convertToJSON(v1alpha2_structured_resource_handle->vendor_claim_parameters);
    if(vendor_claim_parameters_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "vendorClaimParameters", vendor_claim_parameters_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha2_structured_resource_handle->vendor_class_parameters
    if(v1alpha2_structured_resource_handle->vendor_class_parameters) {
    cJSON *vendor_class_parameters_object = object_convertToJSON(v1alpha2_structured_resource_handle->vendor_class_parameters);
    if(vendor_class_parameters_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "vendorClassParameters", vendor_class_parameters_object);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha2_structured_resource_handle_t *v1alpha2_structured_resource_handle_parseFromJSON(cJSON *v1alpha2_structured_resource_handleJSON){

    v1alpha2_structured_resource_handle_t *v1alpha2_structured_resource_handle_local_var = NULL;

    // define the local list for v1alpha2_structured_resource_handle->results
    list_t *resultsList = NULL;

    // v1alpha2_structured_resource_handle->node_name
    cJSON *node_name = cJSON_GetObjectItemCaseSensitive(v1alpha2_structured_resource_handleJSON, "nodeName");
    if (node_name) { 
    if(!cJSON_IsString(node_name) && !cJSON_IsNull(node_name))
    {
    goto end; //String
    }
    }

    // v1alpha2_structured_resource_handle->results
    cJSON *results = cJSON_GetObjectItemCaseSensitive(v1alpha2_structured_resource_handleJSON, "results");
    if (!results) {
        goto end;
    }

    
    cJSON *results_local_nonprimitive = NULL;
    if(!cJSON_IsArray(results)){
        goto end; //nonprimitive container
    }

    resultsList = list_createList();

    cJSON_ArrayForEach(results_local_nonprimitive,results )
    {
        if(!cJSON_IsObject(results_local_nonprimitive)){
            goto end;
        }
        v1alpha2_driver_allocation_result_t *resultsItem = v1alpha2_driver_allocation_result_parseFromJSON(results_local_nonprimitive);

        list_addElement(resultsList, resultsItem);
    }

    // v1alpha2_structured_resource_handle->vendor_claim_parameters
    cJSON *vendor_claim_parameters = cJSON_GetObjectItemCaseSensitive(v1alpha2_structured_resource_handleJSON, "vendorClaimParameters");
    object_t *vendor_claim_parameters_local_object = NULL;
    if (vendor_claim_parameters) { 
    vendor_claim_parameters_local_object = object_parseFromJSON(vendor_claim_parameters); //object
    }

    // v1alpha2_structured_resource_handle->vendor_class_parameters
    cJSON *vendor_class_parameters = cJSON_GetObjectItemCaseSensitive(v1alpha2_structured_resource_handleJSON, "vendorClassParameters");
    object_t *vendor_class_parameters_local_object = NULL;
    if (vendor_class_parameters) { 
    vendor_class_parameters_local_object = object_parseFromJSON(vendor_class_parameters); //object
    }


    v1alpha2_structured_resource_handle_local_var = v1alpha2_structured_resource_handle_create (
        node_name && !cJSON_IsNull(node_name) ? strdup(node_name->valuestring) : NULL,
        resultsList,
        vendor_claim_parameters ? vendor_claim_parameters_local_object : NULL,
        vendor_class_parameters ? vendor_class_parameters_local_object : NULL
        );

    return v1alpha2_structured_resource_handle_local_var;
end:
    if (resultsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resultsList) {
            v1alpha2_driver_allocation_result_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resultsList);
        resultsList = NULL;
    }
    return NULL;

}
