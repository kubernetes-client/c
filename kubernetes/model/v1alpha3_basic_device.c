#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_basic_device.h"



static v1alpha3_basic_device_t *v1alpha3_basic_device_create_internal(
    int all_nodes,
    list_t* attributes,
    list_t* capacity,
    list_t *consumes_counters,
    char *node_name,
    v1_node_selector_t *node_selector,
    list_t *taints
    ) {
    v1alpha3_basic_device_t *v1alpha3_basic_device_local_var = malloc(sizeof(v1alpha3_basic_device_t));
    if (!v1alpha3_basic_device_local_var) {
        return NULL;
    }
    v1alpha3_basic_device_local_var->all_nodes = all_nodes;
    v1alpha3_basic_device_local_var->attributes = attributes;
    v1alpha3_basic_device_local_var->capacity = capacity;
    v1alpha3_basic_device_local_var->consumes_counters = consumes_counters;
    v1alpha3_basic_device_local_var->node_name = node_name;
    v1alpha3_basic_device_local_var->node_selector = node_selector;
    v1alpha3_basic_device_local_var->taints = taints;

    v1alpha3_basic_device_local_var->_library_owned = 1;
    return v1alpha3_basic_device_local_var;
}

__attribute__((deprecated)) v1alpha3_basic_device_t *v1alpha3_basic_device_create(
    int all_nodes,
    list_t* attributes,
    list_t* capacity,
    list_t *consumes_counters,
    char *node_name,
    v1_node_selector_t *node_selector,
    list_t *taints
    ) {
    return v1alpha3_basic_device_create_internal (
        all_nodes,
        attributes,
        capacity,
        consumes_counters,
        node_name,
        node_selector,
        taints
        );
}

void v1alpha3_basic_device_free(v1alpha3_basic_device_t *v1alpha3_basic_device) {
    if(NULL == v1alpha3_basic_device){
        return ;
    }
    if(v1alpha3_basic_device->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha3_basic_device_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_basic_device->attributes) {
        list_ForEach(listEntry, v1alpha3_basic_device->attributes) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1alpha3_basic_device->attributes);
        v1alpha3_basic_device->attributes = NULL;
    }
    if (v1alpha3_basic_device->capacity) {
        list_ForEach(listEntry, v1alpha3_basic_device->capacity) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1alpha3_basic_device->capacity);
        v1alpha3_basic_device->capacity = NULL;
    }
    if (v1alpha3_basic_device->consumes_counters) {
        list_ForEach(listEntry, v1alpha3_basic_device->consumes_counters) {
            v1alpha3_device_counter_consumption_free(listEntry->data);
        }
        list_freeList(v1alpha3_basic_device->consumes_counters);
        v1alpha3_basic_device->consumes_counters = NULL;
    }
    if (v1alpha3_basic_device->node_name) {
        free(v1alpha3_basic_device->node_name);
        v1alpha3_basic_device->node_name = NULL;
    }
    if (v1alpha3_basic_device->node_selector) {
        v1_node_selector_free(v1alpha3_basic_device->node_selector);
        v1alpha3_basic_device->node_selector = NULL;
    }
    if (v1alpha3_basic_device->taints) {
        list_ForEach(listEntry, v1alpha3_basic_device->taints) {
            v1alpha3_device_taint_free(listEntry->data);
        }
        list_freeList(v1alpha3_basic_device->taints);
        v1alpha3_basic_device->taints = NULL;
    }
    free(v1alpha3_basic_device);
}

cJSON *v1alpha3_basic_device_convertToJSON(v1alpha3_basic_device_t *v1alpha3_basic_device) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_basic_device->all_nodes
    if(v1alpha3_basic_device->all_nodes) {
    if(cJSON_AddBoolToObject(item, "allNodes", v1alpha3_basic_device->all_nodes) == NULL) {
    goto fail; //Bool
    }
    }


    // v1alpha3_basic_device->attributes
    if(v1alpha3_basic_device->attributes) {
    cJSON *attributes = cJSON_AddObjectToObject(item, "attributes");
    if(attributes == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = attributes;
    listEntry_t *attributesListEntry;
    if (v1alpha3_basic_device->attributes) {
    list_ForEach(attributesListEntry, v1alpha3_basic_device->attributes) {
        keyValuePair_t *localKeyValue = attributesListEntry->data;
    }
    }
    }


    // v1alpha3_basic_device->capacity
    if(v1alpha3_basic_device->capacity) {
    cJSON *capacity = cJSON_AddObjectToObject(item, "capacity");
    if(capacity == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = capacity;
    listEntry_t *capacityListEntry;
    if (v1alpha3_basic_device->capacity) {
    list_ForEach(capacityListEntry, v1alpha3_basic_device->capacity) {
        keyValuePair_t *localKeyValue = capacityListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
    }


    // v1alpha3_basic_device->consumes_counters
    if(v1alpha3_basic_device->consumes_counters) {
    cJSON *consumes_counters = cJSON_AddArrayToObject(item, "consumesCounters");
    if(consumes_counters == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *consumes_countersListEntry;
    if (v1alpha3_basic_device->consumes_counters) {
    list_ForEach(consumes_countersListEntry, v1alpha3_basic_device->consumes_counters) {
    cJSON *itemLocal = v1alpha3_device_counter_consumption_convertToJSON(consumes_countersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(consumes_counters, itemLocal);
    }
    }
    }


    // v1alpha3_basic_device->node_name
    if(v1alpha3_basic_device->node_name) {
    if(cJSON_AddStringToObject(item, "nodeName", v1alpha3_basic_device->node_name) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha3_basic_device->node_selector
    if(v1alpha3_basic_device->node_selector) {
    cJSON *node_selector_local_JSON = v1_node_selector_convertToJSON(v1alpha3_basic_device->node_selector);
    if(node_selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "nodeSelector", node_selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha3_basic_device->taints
    if(v1alpha3_basic_device->taints) {
    cJSON *taints = cJSON_AddArrayToObject(item, "taints");
    if(taints == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *taintsListEntry;
    if (v1alpha3_basic_device->taints) {
    list_ForEach(taintsListEntry, v1alpha3_basic_device->taints) {
    cJSON *itemLocal = v1alpha3_device_taint_convertToJSON(taintsListEntry->data);
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

v1alpha3_basic_device_t *v1alpha3_basic_device_parseFromJSON(cJSON *v1alpha3_basic_deviceJSON){

    v1alpha3_basic_device_t *v1alpha3_basic_device_local_var = NULL;

    // define the local map for v1alpha3_basic_device->attributes
    list_t *attributesList = NULL;

    // define the local map for v1alpha3_basic_device->capacity
    list_t *capacityList = NULL;

    // define the local list for v1alpha3_basic_device->consumes_counters
    list_t *consumes_countersList = NULL;

    // define the local variable for v1alpha3_basic_device->node_selector
    v1_node_selector_t *node_selector_local_nonprim = NULL;

    // define the local list for v1alpha3_basic_device->taints
    list_t *taintsList = NULL;

    // v1alpha3_basic_device->all_nodes
    cJSON *all_nodes = cJSON_GetObjectItemCaseSensitive(v1alpha3_basic_deviceJSON, "allNodes");
    if (cJSON_IsNull(all_nodes)) {
        all_nodes = NULL;
    }
    if (all_nodes) { 
    if(!cJSON_IsBool(all_nodes))
    {
    goto end; //Bool
    }
    }

    // v1alpha3_basic_device->attributes
    cJSON *attributes = cJSON_GetObjectItemCaseSensitive(v1alpha3_basic_deviceJSON, "attributes");
    if (cJSON_IsNull(attributes)) {
        attributes = NULL;
    }
    if (attributes) { 

    // The data type of the elements in v1alpha3_basic_device->attributes is currently not supported.

    }

    // v1alpha3_basic_device->capacity
    cJSON *capacity = cJSON_GetObjectItemCaseSensitive(v1alpha3_basic_deviceJSON, "capacity");
    if (cJSON_IsNull(capacity)) {
        capacity = NULL;
    }
    if (capacity) { 
    cJSON *capacity_local_map = NULL;
    if(!cJSON_IsObject(capacity) && !cJSON_IsNull(capacity))
    {
        goto end;//primitive map container
    }
    if(cJSON_IsObject(capacity))
    {
        capacityList = list_createList();
        keyValuePair_t *localMapKeyPair;
        cJSON_ArrayForEach(capacity_local_map, capacity)
        {
            cJSON *localMapObject = capacity_local_map;
            if(!cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(capacityList , localMapKeyPair);
        }
    }
    }

    // v1alpha3_basic_device->consumes_counters
    cJSON *consumes_counters = cJSON_GetObjectItemCaseSensitive(v1alpha3_basic_deviceJSON, "consumesCounters");
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
        v1alpha3_device_counter_consumption_t *consumes_countersItem = v1alpha3_device_counter_consumption_parseFromJSON(consumes_counters_local_nonprimitive);

        list_addElement(consumes_countersList, consumes_countersItem);
    }
    }

    // v1alpha3_basic_device->node_name
    cJSON *node_name = cJSON_GetObjectItemCaseSensitive(v1alpha3_basic_deviceJSON, "nodeName");
    if (cJSON_IsNull(node_name)) {
        node_name = NULL;
    }
    if (node_name) { 
    if(!cJSON_IsString(node_name) && !cJSON_IsNull(node_name))
    {
    goto end; //String
    }
    }

    // v1alpha3_basic_device->node_selector
    cJSON *node_selector = cJSON_GetObjectItemCaseSensitive(v1alpha3_basic_deviceJSON, "nodeSelector");
    if (cJSON_IsNull(node_selector)) {
        node_selector = NULL;
    }
    if (node_selector) { 
    node_selector_local_nonprim = v1_node_selector_parseFromJSON(node_selector); //nonprimitive
    }

    // v1alpha3_basic_device->taints
    cJSON *taints = cJSON_GetObjectItemCaseSensitive(v1alpha3_basic_deviceJSON, "taints");
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
        v1alpha3_device_taint_t *taintsItem = v1alpha3_device_taint_parseFromJSON(taints_local_nonprimitive);

        list_addElement(taintsList, taintsItem);
    }
    }


    v1alpha3_basic_device_local_var = v1alpha3_basic_device_create_internal (
        all_nodes ? all_nodes->valueint : 0,
        attributes ? attributesList : NULL,
        capacity ? capacityList : NULL,
        consumes_counters ? consumes_countersList : NULL,
        node_name && !cJSON_IsNull(node_name) ? strdup(node_name->valuestring) : NULL,
        node_selector ? node_selector_local_nonprim : NULL,
        taints ? taintsList : NULL
        );

    return v1alpha3_basic_device_local_var;
end:

    // The data type of the elements in v1alpha3_basic_device->attributes is currently not supported.

    if (capacityList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, capacityList) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(capacityList);
        capacityList = NULL;
    }
    if (consumes_countersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, consumes_countersList) {
            v1alpha3_device_counter_consumption_free(listEntry->data);
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
            v1alpha3_device_taint_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(taintsList);
        taintsList = NULL;
    }
    return NULL;

}
