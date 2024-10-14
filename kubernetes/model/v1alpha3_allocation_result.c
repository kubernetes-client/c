#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_allocation_result.h"



v1alpha3_allocation_result_t *v1alpha3_allocation_result_create(
    char *controller,
    v1alpha3_device_allocation_result_t *devices,
    v1_node_selector_t *node_selector
    ) {
    v1alpha3_allocation_result_t *v1alpha3_allocation_result_local_var = malloc(sizeof(v1alpha3_allocation_result_t));
    if (!v1alpha3_allocation_result_local_var) {
        return NULL;
    }
    v1alpha3_allocation_result_local_var->controller = controller;
    v1alpha3_allocation_result_local_var->devices = devices;
    v1alpha3_allocation_result_local_var->node_selector = node_selector;

    return v1alpha3_allocation_result_local_var;
}


void v1alpha3_allocation_result_free(v1alpha3_allocation_result_t *v1alpha3_allocation_result) {
    if(NULL == v1alpha3_allocation_result){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_allocation_result->controller) {
        free(v1alpha3_allocation_result->controller);
        v1alpha3_allocation_result->controller = NULL;
    }
    if (v1alpha3_allocation_result->devices) {
        v1alpha3_device_allocation_result_free(v1alpha3_allocation_result->devices);
        v1alpha3_allocation_result->devices = NULL;
    }
    if (v1alpha3_allocation_result->node_selector) {
        v1_node_selector_free(v1alpha3_allocation_result->node_selector);
        v1alpha3_allocation_result->node_selector = NULL;
    }
    free(v1alpha3_allocation_result);
}

cJSON *v1alpha3_allocation_result_convertToJSON(v1alpha3_allocation_result_t *v1alpha3_allocation_result) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_allocation_result->controller
    if(v1alpha3_allocation_result->controller) {
    if(cJSON_AddStringToObject(item, "controller", v1alpha3_allocation_result->controller) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha3_allocation_result->devices
    if(v1alpha3_allocation_result->devices) {
    cJSON *devices_local_JSON = v1alpha3_device_allocation_result_convertToJSON(v1alpha3_allocation_result->devices);
    if(devices_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "devices", devices_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha3_allocation_result->node_selector
    if(v1alpha3_allocation_result->node_selector) {
    cJSON *node_selector_local_JSON = v1_node_selector_convertToJSON(v1alpha3_allocation_result->node_selector);
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

v1alpha3_allocation_result_t *v1alpha3_allocation_result_parseFromJSON(cJSON *v1alpha3_allocation_resultJSON){

    v1alpha3_allocation_result_t *v1alpha3_allocation_result_local_var = NULL;

    // define the local variable for v1alpha3_allocation_result->devices
    v1alpha3_device_allocation_result_t *devices_local_nonprim = NULL;

    // define the local variable for v1alpha3_allocation_result->node_selector
    v1_node_selector_t *node_selector_local_nonprim = NULL;

    // v1alpha3_allocation_result->controller
    cJSON *controller = cJSON_GetObjectItemCaseSensitive(v1alpha3_allocation_resultJSON, "controller");
    if (controller) { 
    if(!cJSON_IsString(controller) && !cJSON_IsNull(controller))
    {
    goto end; //String
    }
    }

    // v1alpha3_allocation_result->devices
    cJSON *devices = cJSON_GetObjectItemCaseSensitive(v1alpha3_allocation_resultJSON, "devices");
    if (devices) { 
    devices_local_nonprim = v1alpha3_device_allocation_result_parseFromJSON(devices); //nonprimitive
    }

    // v1alpha3_allocation_result->node_selector
    cJSON *node_selector = cJSON_GetObjectItemCaseSensitive(v1alpha3_allocation_resultJSON, "nodeSelector");
    if (node_selector) { 
    node_selector_local_nonprim = v1_node_selector_parseFromJSON(node_selector); //nonprimitive
    }


    v1alpha3_allocation_result_local_var = v1alpha3_allocation_result_create (
        controller && !cJSON_IsNull(controller) ? strdup(controller->valuestring) : NULL,
        devices ? devices_local_nonprim : NULL,
        node_selector ? node_selector_local_nonprim : NULL
        );

    return v1alpha3_allocation_result_local_var;
end:
    if (devices_local_nonprim) {
        v1alpha3_device_allocation_result_free(devices_local_nonprim);
        devices_local_nonprim = NULL;
    }
    if (node_selector_local_nonprim) {
        v1_node_selector_free(node_selector_local_nonprim);
        node_selector_local_nonprim = NULL;
    }
    return NULL;

}
