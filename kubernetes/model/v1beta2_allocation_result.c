#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_allocation_result.h"



static v1beta2_allocation_result_t *v1beta2_allocation_result_create_internal(
    char *allocation_timestamp,
    v1beta2_device_allocation_result_t *devices,
    v1_node_selector_t *node_selector
    ) {
    v1beta2_allocation_result_t *v1beta2_allocation_result_local_var = malloc(sizeof(v1beta2_allocation_result_t));
    if (!v1beta2_allocation_result_local_var) {
        return NULL;
    }
    v1beta2_allocation_result_local_var->allocation_timestamp = allocation_timestamp;
    v1beta2_allocation_result_local_var->devices = devices;
    v1beta2_allocation_result_local_var->node_selector = node_selector;

    v1beta2_allocation_result_local_var->_library_owned = 1;
    return v1beta2_allocation_result_local_var;
}

__attribute__((deprecated)) v1beta2_allocation_result_t *v1beta2_allocation_result_create(
    char *allocation_timestamp,
    v1beta2_device_allocation_result_t *devices,
    v1_node_selector_t *node_selector
    ) {
    return v1beta2_allocation_result_create_internal (
        allocation_timestamp,
        devices,
        node_selector
        );
}

void v1beta2_allocation_result_free(v1beta2_allocation_result_t *v1beta2_allocation_result) {
    if(NULL == v1beta2_allocation_result){
        return ;
    }
    if(v1beta2_allocation_result->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta2_allocation_result_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta2_allocation_result->allocation_timestamp) {
        free(v1beta2_allocation_result->allocation_timestamp);
        v1beta2_allocation_result->allocation_timestamp = NULL;
    }
    if (v1beta2_allocation_result->devices) {
        v1beta2_device_allocation_result_free(v1beta2_allocation_result->devices);
        v1beta2_allocation_result->devices = NULL;
    }
    if (v1beta2_allocation_result->node_selector) {
        v1_node_selector_free(v1beta2_allocation_result->node_selector);
        v1beta2_allocation_result->node_selector = NULL;
    }
    free(v1beta2_allocation_result);
}

cJSON *v1beta2_allocation_result_convertToJSON(v1beta2_allocation_result_t *v1beta2_allocation_result) {
    cJSON *item = cJSON_CreateObject();

    // v1beta2_allocation_result->allocation_timestamp
    if(v1beta2_allocation_result->allocation_timestamp) {
    if(cJSON_AddStringToObject(item, "allocationTimestamp", v1beta2_allocation_result->allocation_timestamp) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v1beta2_allocation_result->devices
    if(v1beta2_allocation_result->devices) {
    cJSON *devices_local_JSON = v1beta2_device_allocation_result_convertToJSON(v1beta2_allocation_result->devices);
    if(devices_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "devices", devices_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1beta2_allocation_result->node_selector
    if(v1beta2_allocation_result->node_selector) {
    cJSON *node_selector_local_JSON = v1_node_selector_convertToJSON(v1beta2_allocation_result->node_selector);
    if(node_selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "nodeSelector", node_selector_local_JSON);
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

v1beta2_allocation_result_t *v1beta2_allocation_result_parseFromJSON(cJSON *v1beta2_allocation_resultJSON){

    v1beta2_allocation_result_t *v1beta2_allocation_result_local_var = NULL;

    // define the local variable for v1beta2_allocation_result->devices
    v1beta2_device_allocation_result_t *devices_local_nonprim = NULL;

    // define the local variable for v1beta2_allocation_result->node_selector
    v1_node_selector_t *node_selector_local_nonprim = NULL;

    // v1beta2_allocation_result->allocation_timestamp
    cJSON *allocation_timestamp = cJSON_GetObjectItemCaseSensitive(v1beta2_allocation_resultJSON, "allocationTimestamp");
    if (cJSON_IsNull(allocation_timestamp)) {
        allocation_timestamp = NULL;
    }
    if (allocation_timestamp) { 
    if(!cJSON_IsString(allocation_timestamp) && !cJSON_IsNull(allocation_timestamp))
    {
    goto end; //DateTime
    }
    }

    // v1beta2_allocation_result->devices
    cJSON *devices = cJSON_GetObjectItemCaseSensitive(v1beta2_allocation_resultJSON, "devices");
    if (cJSON_IsNull(devices)) {
        devices = NULL;
    }
    if (devices) { 
    devices_local_nonprim = v1beta2_device_allocation_result_parseFromJSON(devices); //nonprimitive
    }

    // v1beta2_allocation_result->node_selector
    cJSON *node_selector = cJSON_GetObjectItemCaseSensitive(v1beta2_allocation_resultJSON, "nodeSelector");
    if (cJSON_IsNull(node_selector)) {
        node_selector = NULL;
    }
    if (node_selector) { 
    node_selector_local_nonprim = v1_node_selector_parseFromJSON(node_selector); //nonprimitive
    }


    v1beta2_allocation_result_local_var = v1beta2_allocation_result_create_internal (
        allocation_timestamp && !cJSON_IsNull(allocation_timestamp) ? strdup(allocation_timestamp->valuestring) : NULL,
        devices ? devices_local_nonprim : NULL,
        node_selector ? node_selector_local_nonprim : NULL
        );

    return v1beta2_allocation_result_local_var;
end:
    if (devices_local_nonprim) {
        v1beta2_device_allocation_result_free(devices_local_nonprim);
        devices_local_nonprim = NULL;
    }
    if (node_selector_local_nonprim) {
        v1_node_selector_free(node_selector_local_nonprim);
        node_selector_local_nonprim = NULL;
    }
    return NULL;

}
