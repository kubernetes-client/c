#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_device.h"



static v1beta2_device_t *v1beta2_device_create_internal(
    int all_nodes,
    list_t* attributes,
    list_t* capacity,
    list_t *consumes_counters,
    char *name,
    char *node_name,
    v1_node_selector_t *node_selector,
    list_t *taints
    ) {
    v1beta2_device_t *v1beta2_device_local_var = malloc(sizeof(v1beta2_device_t));
    if (!v1beta2_device_local_var) {
        return NULL;
    }
    v1beta2_device_local_var->all_nodes = all_nodes;
    v1beta2_device_local_var->attributes = attributes;
    v1beta2_device_local_var->capacity = capacity;
    v1beta2_device_local_var->consumes_counters = consumes_counters;
    v1beta2_device_local_var->name = name;
    v1beta2_device_local_var->node_name = node_name;
    v1beta2_device_local_var->node_selector = node_selector;
    v1beta2_device_local_var->taints = taints;

    v1beta2_device_local_var->_library_owned = 1;
    return v1beta2_device_local_var;
}

__attribute__((deprecated)) v1beta2_device_t *v1beta2_device_create(
    int all_nodes,
    list_t* attributes,
    list_t* capacity,
    list_t *consumes_counters,
    char *name,
    char *node_name,
    v1_node_selector_t *node_selector,
    list_t *taints
    ) {
    return v1beta2_device_create_internal (
        all_nodes,
        attributes,
        capacity,
        consumes_counters,
        name,
        node_name,
        node_selector,
        taints
        );
}

void v1beta2_device_free(v1beta2_device_t *v1beta2_device) {
    if(NULL == v1beta2_device){
        return ;
    }
    if(v1beta2_device->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta2_device_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta2_device->attributes) {
        list_ForEach(listEntry, v1beta2_device->attributes) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1beta2_device->attributes);
        v1beta2_device->attributes = NULL;
    }
    if (v1beta2_device->capacity) {
        list_ForEach(listEntry, v1beta2_device->capacity) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1beta2_device->capacity);
        v1beta2_device->capacity = NULL;
    }
    if (v1beta2_device->consumes_counters) {
        list_ForEach(listEntry, v1beta2_device->consumes_counters) {
            v1beta2_device_counter_consumption_free(listEntry->data);
        }
        list_freeList(v1beta2_device->consumes_counters);
        v1beta2_device->consumes_counters = NULL;
    }
    if (v1beta2_device->name) {
        free(v1beta2_device->name);
        v1beta2_device->name = NULL;
    }
    if (v1beta2_device->node_name) {
        free(v1beta2_device->node_name);
        v1beta2_device->node_name = NULL;
    }
    if (v1beta2_device->node_selector) {
        v1_node_selector_free(v1beta2_device->node_selector);
        v1beta2_device->node_selector = NULL;
    }
    if (v1beta2_device->taints) {
        list_ForEach(listEntry, v1beta2_device->taints) {
            v1beta2_device_taint_free(listEntry->data);
        }
        list_freeList(v1beta2_device->taints);
        v1beta2_device->taints = NULL;
    }
    free(v1beta2_device);
}

cJSON *v1beta2_device_convertToJSON(v1beta2_device_t *v1beta2_device) {
    cJSON *item = cJSON_CreateObject();

    // v1beta2_device->all_nodes
    if(v1beta2_device->all_nodes) {
    if(cJSON_AddBoolToObject(item, "allNodes", v1beta2_device->all_nodes) == NULL) {
    goto fail; //Bool
    }
    }


    // v1beta2_device->attributes
    if(v1beta2_device->attributes) {
    cJSON *attributes = cJSON_AddObjectToObject(item, "attributes");
    if(attributes == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = attributes;
    listEntry_t *attributesListEntry;
    if (v1beta2_device->attributes) {
    list_ForEach(attributesListEntry, v1beta2_device->attributes) {
        keyValuePair_t *localKeyValue = attributesListEntry->data;
    }
    }
    }


    // v1beta2_device->capacity
    if(v1beta2_device->capacity) {
    cJSON *capacity = cJSON_AddObjectToObject(item, "capacity");
    if(capacity == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = capacity;
    listEntry_t *capacityListEntry;
    if (v1beta2_device->capacity) {
    list_ForEach(capacityListEntry, v1beta2_device->capacity) {
        keyValuePair_t *localKeyValue = capacityListEntry->data;
    }
    }
    }


    // v1beta2_device->consumes_counters
    if(v1beta2_device->consumes_counters) {
    cJSON *consumes_counters = cJSON_AddArrayToObject(item, "consumesCounters");
    if(consumes_counters == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *consumes_countersListEntry;
    if (v1beta2_device->consumes_counters) {
    list_ForEach(consumes_countersListEntry, v1beta2_device->consumes_counters) {
    cJSON *itemLocal = v1beta2_device_counter_consumption_convertToJSON(consumes_countersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(consumes_counters, itemLocal);
    }
    }
    }


    // v1beta2_device->name
    if (!v1beta2_device->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1beta2_device->name) == NULL) {
    goto fail; //String
    }


    // v1beta2_device->node_name
    if(v1beta2_device->node_name) {
    if(cJSON_AddStringToObject(item, "nodeName", v1beta2_device->node_name) == NULL) {
    goto fail; //String
    }
    }


    // v1beta2_device->node_selector
    if(v1beta2_device->node_selector) {
    cJSON *node_selector_local_JSON = v1_node_selector_convertToJSON(v1beta2_device->node_selector);
    if(node_selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "nodeSelector", node_selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1beta2_device->taints
    if(v1beta2_device->taints) {
    cJSON *taints = cJSON_AddArrayToObject(item, "taints");
    if(taints == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *taintsListEntry;
    if (v1beta2_device->taints) {
    list_ForEach(taintsListEntry, v1beta2_device->taints) {
    cJSON *itemLocal = v1beta2_device_taint_convertToJSON(taintsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(taints, itemLocal);
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta2_device_t *v1beta2_device_parseFromJSON(cJSON *v1beta2_deviceJSON){

    v1beta2_device_t *v1beta2_device_local_var = NULL;

    // define the local map for v1beta2_device->attributes
    list_t *attributesList = NULL;

    // define the local map for v1beta2_device->capacity
    list_t *capacityList = NULL;

    // define the local list for v1beta2_device->consumes_counters
    list_t *consumes_countersList = NULL;

    // define the local variable for v1beta2_device->node_selector
    v1_node_selector_t *node_selector_local_nonprim = NULL;

    // define the local list for v1beta2_device->taints
    list_t *taintsList = NULL;

    // v1beta2_device->all_nodes
    cJSON *all_nodes = cJSON_GetObjectItemCaseSensitive(v1beta2_deviceJSON, "allNodes");
    if (cJSON_IsNull(all_nodes)) {
        all_nodes = NULL;
    }
    if (all_nodes) { 
    if(!cJSON_IsBool(all_nodes))
    {
    goto end; //Bool
    }
    }

    // v1beta2_device->attributes
    cJSON *attributes = cJSON_GetObjectItemCaseSensitive(v1beta2_deviceJSON, "attributes");
    if (cJSON_IsNull(attributes)) {
        attributes = NULL;
    }
    if (attributes) { 

    // The data type of the elements in v1beta2_device->attributes is currently not supported.

    }

    // v1beta2_device->capacity
    cJSON *capacity = cJSON_GetObjectItemCaseSensitive(v1beta2_deviceJSON, "capacity");
    if (cJSON_IsNull(capacity)) {
        capacity = NULL;
    }
    if (capacity) { 

    // The data type of the elements in v1beta2_device->capacity is currently not supported.

    }

    // v1beta2_device->consumes_counters
    cJSON *consumes_counters = cJSON_GetObjectItemCaseSensitive(v1beta2_deviceJSON, "consumesCounters");
    if (cJSON_IsNull(consumes_counters)) {
        consumes_counters = NULL;
    }
    if (consumes_counters) { 
    cJSON *consumes_counters_local_nonprimitive = NULL;
    if(!cJSON_IsArray(consumes_counters)){
        goto end; //nonprimitive container
    }

    consumes_countersList = list_createList();

    cJSON_ArrayForEach(consumes_counters_local_nonprimitive,consumes_counters )
    {
        if(!cJSON_IsObject(consumes_counters_local_nonprimitive)){
            goto end;
        }
        v1beta2_device_counter_consumption_t *consumes_countersItem = v1beta2_device_counter_consumption_parseFromJSON(consumes_counters_local_nonprimitive);

        list_addElement(consumes_countersList, consumes_countersItem);
    }
    }

    // v1beta2_device->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1beta2_deviceJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1beta2_device->node_name
    cJSON *node_name = cJSON_GetObjectItemCaseSensitive(v1beta2_deviceJSON, "nodeName");
    if (cJSON_IsNull(node_name)) {
        node_name = NULL;
    }
    if (node_name) { 
    if(!cJSON_IsString(node_name) && !cJSON_IsNull(node_name))
    {
    goto end; //String
    }
    }

    // v1beta2_device->node_selector
    cJSON *node_selector = cJSON_GetObjectItemCaseSensitive(v1beta2_deviceJSON, "nodeSelector");
    if (cJSON_IsNull(node_selector)) {
        node_selector = NULL;
    }
    if (node_selector) { 
    node_selector_local_nonprim = v1_node_selector_parseFromJSON(node_selector); //nonprimitive
    }

    // v1beta2_device->taints
    cJSON *taints = cJSON_GetObjectItemCaseSensitive(v1beta2_deviceJSON, "taints");
    if (cJSON_IsNull(taints)) {
        taints = NULL;
    }
    if (taints) { 
    cJSON *taints_local_nonprimitive = NULL;
    if(!cJSON_IsArray(taints)){
        goto end; //nonprimitive container
    }

    taintsList = list_createList();

    cJSON_ArrayForEach(taints_local_nonprimitive,taints )
    {
        if(!cJSON_IsObject(taints_local_nonprimitive)){
            goto end;
        }
        v1beta2_device_taint_t *taintsItem = v1beta2_device_taint_parseFromJSON(taints_local_nonprimitive);

        list_addElement(taintsList, taintsItem);
    }
    }


    v1beta2_device_local_var = v1beta2_device_create_internal (
        all_nodes ? all_nodes->valueint : 0,
        attributes ? attributesList : NULL,
        capacity ? capacityList : NULL,
        consumes_counters ? consumes_countersList : NULL,
        strdup(name->valuestring),
        node_name && !cJSON_IsNull(node_name) ? strdup(node_name->valuestring) : NULL,
        node_selector ? node_selector_local_nonprim : NULL,
        taints ? taintsList : NULL
        );

    return v1beta2_device_local_var;
end:

    // The data type of the elements in v1beta2_device->attributes is currently not supported.


    // The data type of the elements in v1beta2_device->capacity is currently not supported.

    if (consumes_countersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, consumes_countersList) {
            v1beta2_device_counter_consumption_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(consumes_countersList);
        consumes_countersList = NULL;
    }
    if (node_selector_local_nonprim) {
        v1_node_selector_free(node_selector_local_nonprim);
        node_selector_local_nonprim = NULL;
    }
    if (taintsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, taintsList) {
            v1beta2_device_taint_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(taintsList);
        taintsList = NULL;
    }
    return NULL;

}
