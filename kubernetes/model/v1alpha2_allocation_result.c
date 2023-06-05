#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha2_allocation_result.h"



v1alpha2_allocation_result_t *v1alpha2_allocation_result_create(
    v1_node_selector_t *available_on_nodes,
    list_t *resource_handles,
    int shareable
    ) {
    v1alpha2_allocation_result_t *v1alpha2_allocation_result_local_var = malloc(sizeof(v1alpha2_allocation_result_t));
    if (!v1alpha2_allocation_result_local_var) {
        return NULL;
    }
    v1alpha2_allocation_result_local_var->available_on_nodes = available_on_nodes;
    v1alpha2_allocation_result_local_var->resource_handles = resource_handles;
    v1alpha2_allocation_result_local_var->shareable = shareable;

    return v1alpha2_allocation_result_local_var;
}


void v1alpha2_allocation_result_free(v1alpha2_allocation_result_t *v1alpha2_allocation_result) {
    if(NULL == v1alpha2_allocation_result){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha2_allocation_result->available_on_nodes) {
        v1_node_selector_free(v1alpha2_allocation_result->available_on_nodes);
        v1alpha2_allocation_result->available_on_nodes = NULL;
    }
    if (v1alpha2_allocation_result->resource_handles) {
        list_ForEach(listEntry, v1alpha2_allocation_result->resource_handles) {
            v1alpha2_resource_handle_free(listEntry->data);
        }
        list_freeList(v1alpha2_allocation_result->resource_handles);
        v1alpha2_allocation_result->resource_handles = NULL;
    }
    free(v1alpha2_allocation_result);
}

cJSON *v1alpha2_allocation_result_convertToJSON(v1alpha2_allocation_result_t *v1alpha2_allocation_result) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha2_allocation_result->available_on_nodes
    if(v1alpha2_allocation_result->available_on_nodes) {
    cJSON *available_on_nodes_local_JSON = v1_node_selector_convertToJSON(v1alpha2_allocation_result->available_on_nodes);
    if(available_on_nodes_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "availableOnNodes", available_on_nodes_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha2_allocation_result->resource_handles
    if(v1alpha2_allocation_result->resource_handles) {
    cJSON *resource_handles = cJSON_AddArrayToObject(item, "resourceHandles");
    if(resource_handles == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *resource_handlesListEntry;
    if (v1alpha2_allocation_result->resource_handles) {
    list_ForEach(resource_handlesListEntry, v1alpha2_allocation_result->resource_handles) {
    cJSON *itemLocal = v1alpha2_resource_handle_convertToJSON(resource_handlesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(resource_handles, itemLocal);
    }
    }
    }


    // v1alpha2_allocation_result->shareable
    if(v1alpha2_allocation_result->shareable) {
    if(cJSON_AddBoolToObject(item, "shareable", v1alpha2_allocation_result->shareable) == NULL) {
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

v1alpha2_allocation_result_t *v1alpha2_allocation_result_parseFromJSON(cJSON *v1alpha2_allocation_resultJSON){

    v1alpha2_allocation_result_t *v1alpha2_allocation_result_local_var = NULL;

    // define the local variable for v1alpha2_allocation_result->available_on_nodes
    v1_node_selector_t *available_on_nodes_local_nonprim = NULL;

    // define the local list for v1alpha2_allocation_result->resource_handles
    list_t *resource_handlesList = NULL;

    // v1alpha2_allocation_result->available_on_nodes
    cJSON *available_on_nodes = cJSON_GetObjectItemCaseSensitive(v1alpha2_allocation_resultJSON, "availableOnNodes");
    if (available_on_nodes) { 
    available_on_nodes_local_nonprim = v1_node_selector_parseFromJSON(available_on_nodes); //nonprimitive
    }

    // v1alpha2_allocation_result->resource_handles
    cJSON *resource_handles = cJSON_GetObjectItemCaseSensitive(v1alpha2_allocation_resultJSON, "resourceHandles");
    if (resource_handles) { 
    cJSON *resource_handles_local_nonprimitive = NULL;
    if(!cJSON_IsArray(resource_handles)){
        goto end; //nonprimitive container
    }

    resource_handlesList = list_createList();

    cJSON_ArrayForEach(resource_handles_local_nonprimitive,resource_handles )
    {
        if(!cJSON_IsObject(resource_handles_local_nonprimitive)){
            goto end;
        }
        v1alpha2_resource_handle_t *resource_handlesItem = v1alpha2_resource_handle_parseFromJSON(resource_handles_local_nonprimitive);

        list_addElement(resource_handlesList, resource_handlesItem);
    }
    }

    // v1alpha2_allocation_result->shareable
    cJSON *shareable = cJSON_GetObjectItemCaseSensitive(v1alpha2_allocation_resultJSON, "shareable");
    if (shareable) { 
    if(!cJSON_IsBool(shareable))
    {
    goto end; //Bool
    }
    }


    v1alpha2_allocation_result_local_var = v1alpha2_allocation_result_create (
        available_on_nodes ? available_on_nodes_local_nonprim : NULL,
        resource_handles ? resource_handlesList : NULL,
        shareable ? shareable->valueint : 0
        );

    return v1alpha2_allocation_result_local_var;
end:
    if (available_on_nodes_local_nonprim) {
        v1_node_selector_free(available_on_nodes_local_nonprim);
        available_on_nodes_local_nonprim = NULL;
    }
    if (resource_handlesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, resource_handlesList) {
            v1alpha2_resource_handle_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(resource_handlesList);
        resource_handlesList = NULL;
    }
    return NULL;

}
