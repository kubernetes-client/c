#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha2_driver_allocation_result.h"



v1alpha2_driver_allocation_result_t *v1alpha2_driver_allocation_result_create(
    v1alpha2_named_resources_allocation_result_t *named_resources,
    object_t *vendor_request_parameters
    ) {
    v1alpha2_driver_allocation_result_t *v1alpha2_driver_allocation_result_local_var = malloc(sizeof(v1alpha2_driver_allocation_result_t));
    if (!v1alpha2_driver_allocation_result_local_var) {
        return NULL;
    }
    v1alpha2_driver_allocation_result_local_var->named_resources = named_resources;
    v1alpha2_driver_allocation_result_local_var->vendor_request_parameters = vendor_request_parameters;

    return v1alpha2_driver_allocation_result_local_var;
}


void v1alpha2_driver_allocation_result_free(v1alpha2_driver_allocation_result_t *v1alpha2_driver_allocation_result) {
    if(NULL == v1alpha2_driver_allocation_result){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha2_driver_allocation_result->named_resources) {
        v1alpha2_named_resources_allocation_result_free(v1alpha2_driver_allocation_result->named_resources);
        v1alpha2_driver_allocation_result->named_resources = NULL;
    }
    if (v1alpha2_driver_allocation_result->vendor_request_parameters) {
        object_free(v1alpha2_driver_allocation_result->vendor_request_parameters);
        v1alpha2_driver_allocation_result->vendor_request_parameters = NULL;
    }
    free(v1alpha2_driver_allocation_result);
}

cJSON *v1alpha2_driver_allocation_result_convertToJSON(v1alpha2_driver_allocation_result_t *v1alpha2_driver_allocation_result) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha2_driver_allocation_result->named_resources
    if(v1alpha2_driver_allocation_result->named_resources) {
    cJSON *named_resources_local_JSON = v1alpha2_named_resources_allocation_result_convertToJSON(v1alpha2_driver_allocation_result->named_resources);
    if(named_resources_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "namedResources", named_resources_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha2_driver_allocation_result->vendor_request_parameters
    if(v1alpha2_driver_allocation_result->vendor_request_parameters) {
    cJSON *vendor_request_parameters_object = object_convertToJSON(v1alpha2_driver_allocation_result->vendor_request_parameters);
    if(vendor_request_parameters_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "vendorRequestParameters", vendor_request_parameters_object);
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

v1alpha2_driver_allocation_result_t *v1alpha2_driver_allocation_result_parseFromJSON(cJSON *v1alpha2_driver_allocation_resultJSON){

    v1alpha2_driver_allocation_result_t *v1alpha2_driver_allocation_result_local_var = NULL;

    // define the local variable for v1alpha2_driver_allocation_result->named_resources
    v1alpha2_named_resources_allocation_result_t *named_resources_local_nonprim = NULL;

    // v1alpha2_driver_allocation_result->named_resources
    cJSON *named_resources = cJSON_GetObjectItemCaseSensitive(v1alpha2_driver_allocation_resultJSON, "namedResources");
    if (named_resources) { 
    named_resources_local_nonprim = v1alpha2_named_resources_allocation_result_parseFromJSON(named_resources); //nonprimitive
    }

    // v1alpha2_driver_allocation_result->vendor_request_parameters
    cJSON *vendor_request_parameters = cJSON_GetObjectItemCaseSensitive(v1alpha2_driver_allocation_resultJSON, "vendorRequestParameters");
    object_t *vendor_request_parameters_local_object = NULL;
    if (vendor_request_parameters) { 
    vendor_request_parameters_local_object = object_parseFromJSON(vendor_request_parameters); //object
    }


    v1alpha2_driver_allocation_result_local_var = v1alpha2_driver_allocation_result_create (
        named_resources ? named_resources_local_nonprim : NULL,
        vendor_request_parameters ? vendor_request_parameters_local_object : NULL
        );

    return v1alpha2_driver_allocation_result_local_var;
end:
    if (named_resources_local_nonprim) {
        v1alpha2_named_resources_allocation_result_free(named_resources_local_nonprim);
        named_resources_local_nonprim = NULL;
    }
    return NULL;

}
