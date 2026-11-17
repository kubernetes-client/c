#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_resource_slice_spec.h"



static v1_resource_slice_spec_t *v1_resource_slice_spec_create_internal(
    int *all_nodes,
    list_t *devices,
    char *driver,
    char *node_name,
    v1_node_selector_t *node_selector,
    char *partition_type_attribute,
    int *per_device_node_selection,
    v1_resource_pool_t *pool,
    list_t *shared_counters,
    list_t *skip_node_operations
    ) {
    v1_resource_slice_spec_t *v1_resource_slice_spec_local_var = malloc(sizeof(v1_resource_slice_spec_t));
    if (!v1_resource_slice_spec_local_var) {
        return NULL;
    }
    memset(v1_resource_slice_spec_local_var, 0, sizeof(v1_resource_slice_spec_t));
    v1_resource_slice_spec_local_var->_library_owned = 1;
    v1_resource_slice_spec_local_var->all_nodes = all_nodes;
    v1_resource_slice_spec_local_var->devices = devices;
    v1_resource_slice_spec_local_var->driver = driver;
    v1_resource_slice_spec_local_var->node_name = node_name;
    v1_resource_slice_spec_local_var->node_selector = node_selector;
    v1_resource_slice_spec_local_var->partition_type_attribute = partition_type_attribute;
    v1_resource_slice_spec_local_var->per_device_node_selection = per_device_node_selection;
    v1_resource_slice_spec_local_var->pool = pool;
    v1_resource_slice_spec_local_var->shared_counters = shared_counters;
    v1_resource_slice_spec_local_var->skip_node_operations = skip_node_operations;
    return v1_resource_slice_spec_local_var;
}

__attribute__((deprecated)) v1_resource_slice_spec_t *v1_resource_slice_spec_create(
    int *all_nodes,
    list_t *devices,
    char *driver,
    char *node_name,
    v1_node_selector_t *node_selector,
    char *partition_type_attribute,
    int *per_device_node_selection,
    v1_resource_pool_t *pool,
    list_t *shared_counters,
    list_t *skip_node_operations
    ) {
    int *all_nodes_copy = NULL;
    if (all_nodes) {
        all_nodes_copy = malloc(sizeof(int));
        if (all_nodes_copy) *all_nodes_copy = *all_nodes;
    }
    int *per_device_node_selection_copy = NULL;
    if (per_device_node_selection) {
        per_device_node_selection_copy = malloc(sizeof(int));
        if (per_device_node_selection_copy) *per_device_node_selection_copy = *per_device_node_selection;
    }
    v1_resource_slice_spec_t *result = v1_resource_slice_spec_create_internal (
        all_nodes_copy,
        devices,
        driver,
        node_name,
        node_selector,
        partition_type_attribute,
        per_device_node_selection_copy,
        pool,
        shared_counters,
        skip_node_operations
        );
    if (!result) {
        free(all_nodes_copy);
        free(per_device_node_selection_copy);
    }
    return result;
}

void v1_resource_slice_spec_free(v1_resource_slice_spec_t *v1_resource_slice_spec) {
    if(NULL == v1_resource_slice_spec){
        return ;
    }
    if(v1_resource_slice_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_resource_slice_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_resource_slice_spec->all_nodes) {
        free(v1_resource_slice_spec->all_nodes);
        v1_resource_slice_spec->all_nodes = NULL;
    }
    if (v1_resource_slice_spec->devices) {
        list_ForEach(listEntry, v1_resource_slice_spec->devices) {
            v1_device_free(listEntry->data);
        }
        list_freeList(v1_resource_slice_spec->devices);
        v1_resource_slice_spec->devices = NULL;
    }
    if (v1_resource_slice_spec->driver) {
        free(v1_resource_slice_spec->driver);
        v1_resource_slice_spec->driver = NULL;
    }
    if (v1_resource_slice_spec->node_name) {
        free(v1_resource_slice_spec->node_name);
        v1_resource_slice_spec->node_name = NULL;
    }
    if (v1_resource_slice_spec->node_selector) {
        v1_node_selector_free(v1_resource_slice_spec->node_selector);
        v1_resource_slice_spec->node_selector = NULL;
    }
    if (v1_resource_slice_spec->partition_type_attribute) {
        free(v1_resource_slice_spec->partition_type_attribute);
        v1_resource_slice_spec->partition_type_attribute = NULL;
    }
    if (v1_resource_slice_spec->per_device_node_selection) {
        free(v1_resource_slice_spec->per_device_node_selection);
        v1_resource_slice_spec->per_device_node_selection = NULL;
    }
    if (v1_resource_slice_spec->pool) {
        v1_resource_pool_free(v1_resource_slice_spec->pool);
        v1_resource_slice_spec->pool = NULL;
    }
    if (v1_resource_slice_spec->shared_counters) {
        list_ForEach(listEntry, v1_resource_slice_spec->shared_counters) {
            v1_counter_set_free(listEntry->data);
        }
        list_freeList(v1_resource_slice_spec->shared_counters);
        v1_resource_slice_spec->shared_counters = NULL;
    }
    if (v1_resource_slice_spec->skip_node_operations) {
        list_ForEach(listEntry, v1_resource_slice_spec->skip_node_operations) {
            free(listEntry->data);
        }
        list_freeList(v1_resource_slice_spec->skip_node_operations);
        v1_resource_slice_spec->skip_node_operations = NULL;
    }
    free(v1_resource_slice_spec);
}

cJSON *v1_resource_slice_spec_convertToJSON(v1_resource_slice_spec_t *v1_resource_slice_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_resource_slice_spec->all_nodes
    if(v1_resource_slice_spec->all_nodes) {
    if(cJSON_AddBoolToObject(item, "allNodes", *v1_resource_slice_spec->all_nodes) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_resource_slice_spec->devices
    if(v1_resource_slice_spec->devices) {
    cJSON *devices = cJSON_AddArrayToObject(item, "devices");
    if(devices == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *devicesListEntry;
    if (v1_resource_slice_spec->devices) {
    list_ForEach(devicesListEntry, v1_resource_slice_spec->devices) {
    cJSON *itemLocal = v1_device_convertToJSON(devicesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(devices, itemLocal);
    }
    }
    }


    // v1_resource_slice_spec->driver
    if (!v1_resource_slice_spec->driver) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "driver", v1_resource_slice_spec->driver) == NULL) {
    goto fail; //String
    }


    // v1_resource_slice_spec->node_name
    if(v1_resource_slice_spec->node_name) {
    if(cJSON_AddStringToObject(item, "nodeName", v1_resource_slice_spec->node_name) == NULL) {
    goto fail; //String
    }
    }


    // v1_resource_slice_spec->node_selector
    if(v1_resource_slice_spec->node_selector) {
    cJSON *node_selector_local_JSON = v1_node_selector_convertToJSON(v1_resource_slice_spec->node_selector);
    if(node_selector_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "nodeSelector", node_selector_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_resource_slice_spec->partition_type_attribute
    if(v1_resource_slice_spec->partition_type_attribute) {
    if(cJSON_AddStringToObject(item, "partitionTypeAttribute", v1_resource_slice_spec->partition_type_attribute) == NULL) {
    goto fail; //String
    }
    }


    // v1_resource_slice_spec->per_device_node_selection
    if(v1_resource_slice_spec->per_device_node_selection) {
    if(cJSON_AddBoolToObject(item, "perDeviceNodeSelection", *v1_resource_slice_spec->per_device_node_selection) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_resource_slice_spec->pool
    if (!v1_resource_slice_spec->pool) {
        goto fail;
    }
    cJSON *pool_local_JSON = v1_resource_pool_convertToJSON(v1_resource_slice_spec->pool);
    if(pool_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "pool", pool_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1_resource_slice_spec->shared_counters
    if(v1_resource_slice_spec->shared_counters) {
    cJSON *shared_counters = cJSON_AddArrayToObject(item, "sharedCounters");
    if(shared_counters == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *shared_countersListEntry;
    if (v1_resource_slice_spec->shared_counters) {
    list_ForEach(shared_countersListEntry, v1_resource_slice_spec->shared_counters) {
    cJSON *itemLocal = v1_counter_set_convertToJSON(shared_countersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(shared_counters, itemLocal);
    }
    }
    }


    // v1_resource_slice_spec->skip_node_operations
    if(v1_resource_slice_spec->skip_node_operations) {
    cJSON *skip_node_operations = cJSON_AddArrayToObject(item, "skipNodeOperations");
    if(skip_node_operations == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *skip_node_operationsListEntry;
    list_ForEach(skip_node_operationsListEntry, v1_resource_slice_spec->skip_node_operations) {
    if(cJSON_AddStringToObject(skip_node_operations, "", skip_node_operationsListEntry->data) == NULL)
    {
        goto fail;
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

v1_resource_slice_spec_t *v1_resource_slice_spec_parseFromJSON(cJSON *v1_resource_slice_specJSON){

    v1_resource_slice_spec_t *v1_resource_slice_spec_local_var = NULL;

    // define the local variable for v1_resource_slice_spec->all_nodes
    int *all_nodes_local_var = NULL;

    // define the local list for v1_resource_slice_spec->devices
    list_t *devicesList = NULL;

    char *driver_local_str = NULL;

    char *node_name_local_str = NULL;

    // define the local variable for v1_resource_slice_spec->node_selector
    v1_node_selector_t *node_selector_local_nonprim = NULL;

    char *partition_type_attribute_local_str = NULL;

    // define the local variable for v1_resource_slice_spec->per_device_node_selection
    int *per_device_node_selection_local_var = NULL;

    // define the local variable for v1_resource_slice_spec->pool
    v1_resource_pool_t *pool_local_nonprim = NULL;

    // define the local list for v1_resource_slice_spec->shared_counters
    list_t *shared_countersList = NULL;

    // define the local list for v1_resource_slice_spec->skip_node_operations
    list_t *skip_node_operationsList = NULL;

    // v1_resource_slice_spec->all_nodes
    cJSON *all_nodes = cJSON_GetObjectItemCaseSensitive(v1_resource_slice_specJSON, "allNodes");
    if (cJSON_IsNull(all_nodes)) {
        all_nodes = NULL;
    }
    if (all_nodes) { 
    if(!cJSON_IsBool(all_nodes))
    {
    goto end; //Bool
    }
    all_nodes_local_var = malloc(sizeof(int));
    if(!all_nodes_local_var)
    {
        goto end;
    }
    *all_nodes_local_var = all_nodes->valueint;
    }

    // v1_resource_slice_spec->devices
    cJSON *devices = cJSON_GetObjectItemCaseSensitive(v1_resource_slice_specJSON, "devices");
    if (cJSON_IsNull(devices)) {
        devices = NULL;
    }
    if (devices) { 
    cJSON *devices_local_nonprimitive = NULL;
    if(!cJSON_IsArray(devices)){
        goto end; //nonprimitive container
    }

    devicesList = list_createList();

    cJSON_ArrayForEach(devices_local_nonprimitive,devices )
    {
        if(!cJSON_IsObject(devices_local_nonprimitive)){
            goto end;
        }
        v1_device_t *devicesItem = v1_device_parseFromJSON(devices_local_nonprimitive);

        list_addElement(devicesList, devicesItem);
    }
    }

    // v1_resource_slice_spec->driver
    cJSON *driver = cJSON_GetObjectItemCaseSensitive(v1_resource_slice_specJSON, "driver");
    if (cJSON_IsNull(driver)) {
        driver = NULL;
    }
    if (!driver) {
        goto end;
    }

    
    if(!cJSON_IsString(driver))
    {
    goto end; //String
    }

    // v1_resource_slice_spec->node_name
    cJSON *node_name = cJSON_GetObjectItemCaseSensitive(v1_resource_slice_specJSON, "nodeName");
    if (cJSON_IsNull(node_name)) {
        node_name = NULL;
    }
    if (node_name) { 
    if(!cJSON_IsString(node_name) && !cJSON_IsNull(node_name))
    {
    goto end; //String
    }
    }

    // v1_resource_slice_spec->node_selector
    cJSON *node_selector = cJSON_GetObjectItemCaseSensitive(v1_resource_slice_specJSON, "nodeSelector");
    if (cJSON_IsNull(node_selector)) {
        node_selector = NULL;
    }
    if (node_selector) { 
    node_selector_local_nonprim = v1_node_selector_parseFromJSON(node_selector); //nonprimitive
    }

    // v1_resource_slice_spec->partition_type_attribute
    cJSON *partition_type_attribute = cJSON_GetObjectItemCaseSensitive(v1_resource_slice_specJSON, "partitionTypeAttribute");
    if (cJSON_IsNull(partition_type_attribute)) {
        partition_type_attribute = NULL;
    }
    if (partition_type_attribute) { 
    if(!cJSON_IsString(partition_type_attribute) && !cJSON_IsNull(partition_type_attribute))
    {
    goto end; //String
    }
    }

    // v1_resource_slice_spec->per_device_node_selection
    cJSON *per_device_node_selection = cJSON_GetObjectItemCaseSensitive(v1_resource_slice_specJSON, "perDeviceNodeSelection");
    if (cJSON_IsNull(per_device_node_selection)) {
        per_device_node_selection = NULL;
    }
    if (per_device_node_selection) { 
    if(!cJSON_IsBool(per_device_node_selection))
    {
    goto end; //Bool
    }
    per_device_node_selection_local_var = malloc(sizeof(int));
    if(!per_device_node_selection_local_var)
    {
        goto end;
    }
    *per_device_node_selection_local_var = per_device_node_selection->valueint;
    }

    // v1_resource_slice_spec->pool
    cJSON *pool = cJSON_GetObjectItemCaseSensitive(v1_resource_slice_specJSON, "pool");
    if (cJSON_IsNull(pool)) {
        pool = NULL;
    }
    if (!pool) {
        goto end;
    }

    
    pool_local_nonprim = v1_resource_pool_parseFromJSON(pool); //nonprimitive

    // v1_resource_slice_spec->shared_counters
    cJSON *shared_counters = cJSON_GetObjectItemCaseSensitive(v1_resource_slice_specJSON, "sharedCounters");
    if (cJSON_IsNull(shared_counters)) {
        shared_counters = NULL;
    }
    if (shared_counters) { 
    cJSON *shared_counters_local_nonprimitive = NULL;
    if(!cJSON_IsArray(shared_counters)){
        goto end; //nonprimitive container
    }

    shared_countersList = list_createList();

    cJSON_ArrayForEach(shared_counters_local_nonprimitive,shared_counters )
    {
        if(!cJSON_IsObject(shared_counters_local_nonprimitive)){
            goto end;
        }
        v1_counter_set_t *shared_countersItem = v1_counter_set_parseFromJSON(shared_counters_local_nonprimitive);

        list_addElement(shared_countersList, shared_countersItem);
    }
    }

    // v1_resource_slice_spec->skip_node_operations
    cJSON *skip_node_operations = cJSON_GetObjectItemCaseSensitive(v1_resource_slice_specJSON, "skipNodeOperations");
    if (cJSON_IsNull(skip_node_operations)) {
        skip_node_operations = NULL;
    }
    if (skip_node_operations) { 
    cJSON *skip_node_operations_local = NULL;
    if(!cJSON_IsArray(skip_node_operations)) {
        goto end;//primitive container
    }
    skip_node_operationsList = list_createList();

    cJSON_ArrayForEach(skip_node_operations_local, skip_node_operations)
    {
        if(!cJSON_IsString(skip_node_operations_local))
        {
            goto end;
        }
        list_addElement(skip_node_operationsList , strdup(skip_node_operations_local->valuestring));
    }
    }


    if (driver && !cJSON_IsNull(driver)) driver_local_str = strdup(driver->valuestring);
    if (node_name && !cJSON_IsNull(node_name)) node_name_local_str = strdup(node_name->valuestring);
    if (partition_type_attribute && !cJSON_IsNull(partition_type_attribute)) partition_type_attribute_local_str = strdup(partition_type_attribute->valuestring);

    v1_resource_slice_spec_local_var = v1_resource_slice_spec_create_internal (
        all_nodes_local_var,
        devices ? devicesList : NULL,
        driver_local_str,
        node_name_local_str,
        node_selector ? node_selector_local_nonprim : NULL,
        partition_type_attribute_local_str,
        per_device_node_selection_local_var,
        pool_local_nonprim,
        shared_counters ? shared_countersList : NULL,
        skip_node_operations ? skip_node_operationsList : NULL
        );

    if (!v1_resource_slice_spec_local_var) {
        goto end;
    }

    return v1_resource_slice_spec_local_var;
end:
    if (all_nodes_local_var) {
        free(all_nodes_local_var);
        all_nodes_local_var = NULL;
    }
    if (devicesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, devicesList) {
            v1_device_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(devicesList);
        devicesList = NULL;
    }
    if (driver_local_str) {
        free(driver_local_str);
        driver_local_str = NULL;
    }
    if (node_name_local_str) {
        free(node_name_local_str);
        node_name_local_str = NULL;
    }
    if (node_selector_local_nonprim) {
        v1_node_selector_free(node_selector_local_nonprim);
        node_selector_local_nonprim = NULL;
    }
    if (partition_type_attribute_local_str) {
        free(partition_type_attribute_local_str);
        partition_type_attribute_local_str = NULL;
    }
    if (per_device_node_selection_local_var) {
        free(per_device_node_selection_local_var);
        per_device_node_selection_local_var = NULL;
    }
    if (pool_local_nonprim) {
        v1_resource_pool_free(pool_local_nonprim);
        pool_local_nonprim = NULL;
    }
    if (shared_countersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, shared_countersList) {
            v1_counter_set_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(shared_countersList);
        shared_countersList = NULL;
    }
    if (skip_node_operationsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, skip_node_operationsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(skip_node_operationsList);
        skip_node_operationsList = NULL;
    }
    return NULL;

}
