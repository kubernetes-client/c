#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha2_driver_requests.h"



v1alpha2_driver_requests_t *v1alpha2_driver_requests_create(
    char *driver_name,
    list_t *requests,
    object_t *vendor_parameters
    ) {
    v1alpha2_driver_requests_t *v1alpha2_driver_requests_local_var = malloc(sizeof(v1alpha2_driver_requests_t));
    if (!v1alpha2_driver_requests_local_var) {
        return NULL;
    }
    v1alpha2_driver_requests_local_var->driver_name = driver_name;
    v1alpha2_driver_requests_local_var->requests = requests;
    v1alpha2_driver_requests_local_var->vendor_parameters = vendor_parameters;

    return v1alpha2_driver_requests_local_var;
}


void v1alpha2_driver_requests_free(v1alpha2_driver_requests_t *v1alpha2_driver_requests) {
    if(NULL == v1alpha2_driver_requests){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha2_driver_requests->driver_name) {
        free(v1alpha2_driver_requests->driver_name);
        v1alpha2_driver_requests->driver_name = NULL;
    }
    if (v1alpha2_driver_requests->requests) {
        list_ForEach(listEntry, v1alpha2_driver_requests->requests) {
            v1alpha2_resource_request_free(listEntry->data);
        }
        list_freeList(v1alpha2_driver_requests->requests);
        v1alpha2_driver_requests->requests = NULL;
    }
    if (v1alpha2_driver_requests->vendor_parameters) {
        object_free(v1alpha2_driver_requests->vendor_parameters);
        v1alpha2_driver_requests->vendor_parameters = NULL;
    }
    free(v1alpha2_driver_requests);
}

cJSON *v1alpha2_driver_requests_convertToJSON(v1alpha2_driver_requests_t *v1alpha2_driver_requests) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha2_driver_requests->driver_name
    if(v1alpha2_driver_requests->driver_name) {
    if(cJSON_AddStringToObject(item, "driverName", v1alpha2_driver_requests->driver_name) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha2_driver_requests->requests
    if(v1alpha2_driver_requests->requests) {
    cJSON *requests = cJSON_AddArrayToObject(item, "requests");
    if(requests == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *requestsListEntry;
    if (v1alpha2_driver_requests->requests) {
    list_ForEach(requestsListEntry, v1alpha2_driver_requests->requests) {
    cJSON *itemLocal = v1alpha2_resource_request_convertToJSON(requestsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(requests, itemLocal);
    }
    }
    }


    // v1alpha2_driver_requests->vendor_parameters
    if(v1alpha2_driver_requests->vendor_parameters) {
    cJSON *vendor_parameters_object = object_convertToJSON(v1alpha2_driver_requests->vendor_parameters);
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

v1alpha2_driver_requests_t *v1alpha2_driver_requests_parseFromJSON(cJSON *v1alpha2_driver_requestsJSON){

    v1alpha2_driver_requests_t *v1alpha2_driver_requests_local_var = NULL;

    // define the local list for v1alpha2_driver_requests->requests
    list_t *requestsList = NULL;

    // v1alpha2_driver_requests->driver_name
    cJSON *driver_name = cJSON_GetObjectItemCaseSensitive(v1alpha2_driver_requestsJSON, "driverName");
    if (driver_name) { 
    if(!cJSON_IsString(driver_name) && !cJSON_IsNull(driver_name))
    {
    goto end; //String
    }
    }

    // v1alpha2_driver_requests->requests
    cJSON *requests = cJSON_GetObjectItemCaseSensitive(v1alpha2_driver_requestsJSON, "requests");
    if (requests) { 
    cJSON *requests_local_nonprimitive = NULL;
    if(!cJSON_IsArray(requests)){
        goto end; //nonprimitive container
    }

    requestsList = list_createList();

    cJSON_ArrayForEach(requests_local_nonprimitive,requests )
    {
        if(!cJSON_IsObject(requests_local_nonprimitive)){
            goto end;
        }
        v1alpha2_resource_request_t *requestsItem = v1alpha2_resource_request_parseFromJSON(requests_local_nonprimitive);

        list_addElement(requestsList, requestsItem);
    }
    }

    // v1alpha2_driver_requests->vendor_parameters
    cJSON *vendor_parameters = cJSON_GetObjectItemCaseSensitive(v1alpha2_driver_requestsJSON, "vendorParameters");
    object_t *vendor_parameters_local_object = NULL;
    if (vendor_parameters) { 
    vendor_parameters_local_object = object_parseFromJSON(vendor_parameters); //object
    }


    v1alpha2_driver_requests_local_var = v1alpha2_driver_requests_create (
        driver_name && !cJSON_IsNull(driver_name) ? strdup(driver_name->valuestring) : NULL,
        requests ? requestsList : NULL,
        vendor_parameters ? vendor_parameters_local_object : NULL
        );

    return v1alpha2_driver_requests_local_var;
end:
    if (requestsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, requestsList) {
            v1alpha2_resource_request_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(requestsList);
        requestsList = NULL;
    }
    return NULL;

}
