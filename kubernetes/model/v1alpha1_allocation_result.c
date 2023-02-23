#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_allocation_result.h"



v1alpha1_allocation_result_t *v1alpha1_allocation_result_create(
    v1_node_selector_t *available_on_nodes,
    char *resource_handle,
    int shareable
    ) {
    v1alpha1_allocation_result_t *v1alpha1_allocation_result_local_var = malloc(sizeof(v1alpha1_allocation_result_t));
    if (!v1alpha1_allocation_result_local_var) {
        return NULL;
    }
    v1alpha1_allocation_result_local_var->available_on_nodes = available_on_nodes;
    v1alpha1_allocation_result_local_var->resource_handle = resource_handle;
    v1alpha1_allocation_result_local_var->shareable = shareable;

    return v1alpha1_allocation_result_local_var;
}


void v1alpha1_allocation_result_free(v1alpha1_allocation_result_t *v1alpha1_allocation_result) {
    if(NULL == v1alpha1_allocation_result){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_allocation_result->available_on_nodes) {
        v1_node_selector_free(v1alpha1_allocation_result->available_on_nodes);
        v1alpha1_allocation_result->available_on_nodes = NULL;
    }
    if (v1alpha1_allocation_result->resource_handle) {
        free(v1alpha1_allocation_result->resource_handle);
        v1alpha1_allocation_result->resource_handle = NULL;
    }
    free(v1alpha1_allocation_result);
}

cJSON *v1alpha1_allocation_result_convertToJSON(v1alpha1_allocation_result_t *v1alpha1_allocation_result) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_allocation_result->available_on_nodes
    if(v1alpha1_allocation_result->available_on_nodes) {
    cJSON *available_on_nodes_local_JSON = v1_node_selector_convertToJSON(v1alpha1_allocation_result->available_on_nodes);
    if(available_on_nodes_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "availableOnNodes", available_on_nodes_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha1_allocation_result->resource_handle
    if(v1alpha1_allocation_result->resource_handle) {
    if(cJSON_AddStringToObject(item, "resourceHandle", v1alpha1_allocation_result->resource_handle) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_allocation_result->shareable
    if(v1alpha1_allocation_result->shareable) {
    if(cJSON_AddBoolToObject(item, "shareable", v1alpha1_allocation_result->shareable) == NULL) {
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

v1alpha1_allocation_result_t *v1alpha1_allocation_result_parseFromJSON(cJSON *v1alpha1_allocation_resultJSON){

    v1alpha1_allocation_result_t *v1alpha1_allocation_result_local_var = NULL;

    // define the local variable for v1alpha1_allocation_result->available_on_nodes
    v1_node_selector_t *available_on_nodes_local_nonprim = NULL;

    // v1alpha1_allocation_result->available_on_nodes
    cJSON *available_on_nodes = cJSON_GetObjectItemCaseSensitive(v1alpha1_allocation_resultJSON, "availableOnNodes");
    if (available_on_nodes) { 
    available_on_nodes_local_nonprim = v1_node_selector_parseFromJSON(available_on_nodes); //nonprimitive
    }

    // v1alpha1_allocation_result->resource_handle
    cJSON *resource_handle = cJSON_GetObjectItemCaseSensitive(v1alpha1_allocation_resultJSON, "resourceHandle");
    if (resource_handle) { 
    if(!cJSON_IsString(resource_handle) && !cJSON_IsNull(resource_handle))
    {
    goto end; //String
    }
    }

    // v1alpha1_allocation_result->shareable
    cJSON *shareable = cJSON_GetObjectItemCaseSensitive(v1alpha1_allocation_resultJSON, "shareable");
    if (shareable) { 
    if(!cJSON_IsBool(shareable))
    {
    goto end; //Bool
    }
    }


    v1alpha1_allocation_result_local_var = v1alpha1_allocation_result_create (
        available_on_nodes ? available_on_nodes_local_nonprim : NULL,
        resource_handle && !cJSON_IsNull(resource_handle) ? strdup(resource_handle->valuestring) : NULL,
        shareable ? shareable->valueint : 0
        );

    return v1alpha1_allocation_result_local_var;
end:
    if (available_on_nodes_local_nonprim) {
        v1_node_selector_free(available_on_nodes_local_nonprim);
        available_on_nodes_local_nonprim = NULL;
    }
    return NULL;

}
