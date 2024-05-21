#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha2_resource_request.h"



v1alpha2_resource_request_t *v1alpha2_resource_request_create(
    v1alpha2_named_resources_request_t *named_resources,
    object_t *vendor_parameters
    ) {
    v1alpha2_resource_request_t *v1alpha2_resource_request_local_var = malloc(sizeof(v1alpha2_resource_request_t));
    if (!v1alpha2_resource_request_local_var) {
        return NULL;
    }
    v1alpha2_resource_request_local_var->named_resources = named_resources;
    v1alpha2_resource_request_local_var->vendor_parameters = vendor_parameters;

    return v1alpha2_resource_request_local_var;
}


void v1alpha2_resource_request_free(v1alpha2_resource_request_t *v1alpha2_resource_request) {
    if(NULL == v1alpha2_resource_request){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha2_resource_request->named_resources) {
        v1alpha2_named_resources_request_free(v1alpha2_resource_request->named_resources);
        v1alpha2_resource_request->named_resources = NULL;
    }
    if (v1alpha2_resource_request->vendor_parameters) {
        object_free(v1alpha2_resource_request->vendor_parameters);
        v1alpha2_resource_request->vendor_parameters = NULL;
    }
    free(v1alpha2_resource_request);
}

cJSON *v1alpha2_resource_request_convertToJSON(v1alpha2_resource_request_t *v1alpha2_resource_request) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha2_resource_request->named_resources
    if(v1alpha2_resource_request->named_resources) {
    cJSON *named_resources_local_JSON = v1alpha2_named_resources_request_convertToJSON(v1alpha2_resource_request->named_resources);
    if(named_resources_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "namedResources", named_resources_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha2_resource_request->vendor_parameters
    if(v1alpha2_resource_request->vendor_parameters) {
    cJSON *vendor_parameters_object = object_convertToJSON(v1alpha2_resource_request->vendor_parameters);
    if(vendor_parameters_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "vendorParameters", vendor_parameters_object);
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

v1alpha2_resource_request_t *v1alpha2_resource_request_parseFromJSON(cJSON *v1alpha2_resource_requestJSON){

    v1alpha2_resource_request_t *v1alpha2_resource_request_local_var = NULL;

    // define the local variable for v1alpha2_resource_request->named_resources
    v1alpha2_named_resources_request_t *named_resources_local_nonprim = NULL;

    // v1alpha2_resource_request->named_resources
    cJSON *named_resources = cJSON_GetObjectItemCaseSensitive(v1alpha2_resource_requestJSON, "namedResources");
    if (named_resources) { 
    named_resources_local_nonprim = v1alpha2_named_resources_request_parseFromJSON(named_resources); //nonprimitive
    }

    // v1alpha2_resource_request->vendor_parameters
    cJSON *vendor_parameters = cJSON_GetObjectItemCaseSensitive(v1alpha2_resource_requestJSON, "vendorParameters");
    object_t *vendor_parameters_local_object = NULL;
    if (vendor_parameters) { 
    vendor_parameters_local_object = object_parseFromJSON(vendor_parameters); //object
    }


    v1alpha2_resource_request_local_var = v1alpha2_resource_request_create (
        named_resources ? named_resources_local_nonprim : NULL,
        vendor_parameters ? vendor_parameters_local_object : NULL
        );

    return v1alpha2_resource_request_local_var;
end:
    if (named_resources_local_nonprim) {
        v1alpha2_named_resources_request_free(named_resources_local_nonprim);
        named_resources_local_nonprim = NULL;
    }
    return NULL;

}
