#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_device_request_allocation_result.h"



static v1_device_request_allocation_result_t *v1_device_request_allocation_result_create_internal(
    int *admin_access,
    list_t *binding_conditions,
    list_t *binding_failure_conditions,
    list_t* consumed_capacity,
    char *device,
    char *driver,
    char *pool,
    char *request,
    char *share_id,
    list_t *skip_node_operations,
    list_t *tolerations
    ) {
    v1_device_request_allocation_result_t *v1_device_request_allocation_result_local_var = malloc(sizeof(v1_device_request_allocation_result_t));
    if (!v1_device_request_allocation_result_local_var) {
        return NULL;
    }
    memset(v1_device_request_allocation_result_local_var, 0, sizeof(v1_device_request_allocation_result_t));
    v1_device_request_allocation_result_local_var->_library_owned = 1;
    v1_device_request_allocation_result_local_var->admin_access = admin_access;
    v1_device_request_allocation_result_local_var->binding_conditions = binding_conditions;
    v1_device_request_allocation_result_local_var->binding_failure_conditions = binding_failure_conditions;
    v1_device_request_allocation_result_local_var->consumed_capacity = consumed_capacity;
    v1_device_request_allocation_result_local_var->device = device;
    v1_device_request_allocation_result_local_var->driver = driver;
    v1_device_request_allocation_result_local_var->pool = pool;
    v1_device_request_allocation_result_local_var->request = request;
    v1_device_request_allocation_result_local_var->share_id = share_id;
    v1_device_request_allocation_result_local_var->skip_node_operations = skip_node_operations;
    v1_device_request_allocation_result_local_var->tolerations = tolerations;
    return v1_device_request_allocation_result_local_var;
}

__attribute__((deprecated)) v1_device_request_allocation_result_t *v1_device_request_allocation_result_create(
    int *admin_access,
    list_t *binding_conditions,
    list_t *binding_failure_conditions,
    list_t* consumed_capacity,
    char *device,
    char *driver,
    char *pool,
    char *request,
    char *share_id,
    list_t *skip_node_operations,
    list_t *tolerations
    ) {
    int *admin_access_copy = NULL;
    if (admin_access) {
        admin_access_copy = malloc(sizeof(int));
        if (admin_access_copy) *admin_access_copy = *admin_access;
    }
    v1_device_request_allocation_result_t *result = v1_device_request_allocation_result_create_internal (
        admin_access_copy,
        binding_conditions,
        binding_failure_conditions,
        consumed_capacity,
        device,
        driver,
        pool,
        request,
        share_id,
        skip_node_operations,
        tolerations
        );
    if (!result) {
        free(admin_access_copy);
    }
    return result;
}

void v1_device_request_allocation_result_free(v1_device_request_allocation_result_t *v1_device_request_allocation_result) {
    if(NULL == v1_device_request_allocation_result){
        return ;
    }
    if(v1_device_request_allocation_result->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_device_request_allocation_result_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_device_request_allocation_result->admin_access) {
        free(v1_device_request_allocation_result->admin_access);
        v1_device_request_allocation_result->admin_access = NULL;
    }
    if (v1_device_request_allocation_result->binding_conditions) {
        list_ForEach(listEntry, v1_device_request_allocation_result->binding_conditions) {
            free(listEntry->data);
        }
        list_freeList(v1_device_request_allocation_result->binding_conditions);
        v1_device_request_allocation_result->binding_conditions = NULL;
    }
    if (v1_device_request_allocation_result->binding_failure_conditions) {
        list_ForEach(listEntry, v1_device_request_allocation_result->binding_failure_conditions) {
            free(listEntry->data);
        }
        list_freeList(v1_device_request_allocation_result->binding_failure_conditions);
        v1_device_request_allocation_result->binding_failure_conditions = NULL;
    }
    if (v1_device_request_allocation_result->consumed_capacity) {
        list_ForEach(listEntry, v1_device_request_allocation_result->consumed_capacity) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_device_request_allocation_result->consumed_capacity);
        v1_device_request_allocation_result->consumed_capacity = NULL;
    }
    if (v1_device_request_allocation_result->device) {
        free(v1_device_request_allocation_result->device);
        v1_device_request_allocation_result->device = NULL;
    }
    if (v1_device_request_allocation_result->driver) {
        free(v1_device_request_allocation_result->driver);
        v1_device_request_allocation_result->driver = NULL;
    }
    if (v1_device_request_allocation_result->pool) {
        free(v1_device_request_allocation_result->pool);
        v1_device_request_allocation_result->pool = NULL;
    }
    if (v1_device_request_allocation_result->request) {
        free(v1_device_request_allocation_result->request);
        v1_device_request_allocation_result->request = NULL;
    }
    if (v1_device_request_allocation_result->share_id) {
        free(v1_device_request_allocation_result->share_id);
        v1_device_request_allocation_result->share_id = NULL;
    }
    if (v1_device_request_allocation_result->skip_node_operations) {
        list_ForEach(listEntry, v1_device_request_allocation_result->skip_node_operations) {
            free(listEntry->data);
        }
        list_freeList(v1_device_request_allocation_result->skip_node_operations);
        v1_device_request_allocation_result->skip_node_operations = NULL;
    }
    if (v1_device_request_allocation_result->tolerations) {
        list_ForEach(listEntry, v1_device_request_allocation_result->tolerations) {
            v1_device_toleration_free(listEntry->data);
        }
        list_freeList(v1_device_request_allocation_result->tolerations);
        v1_device_request_allocation_result->tolerations = NULL;
    }
    free(v1_device_request_allocation_result);
}

cJSON *v1_device_request_allocation_result_convertToJSON(v1_device_request_allocation_result_t *v1_device_request_allocation_result) {
    cJSON *item = cJSON_CreateObject();

    // v1_device_request_allocation_result->admin_access
    if(v1_device_request_allocation_result->admin_access) {
    if(cJSON_AddBoolToObject(item, "adminAccess", *v1_device_request_allocation_result->admin_access) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_device_request_allocation_result->binding_conditions
    if(v1_device_request_allocation_result->binding_conditions) {
    cJSON *binding_conditions = cJSON_AddArrayToObject(item, "bindingConditions");
    if(binding_conditions == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *binding_conditionsListEntry;
    list_ForEach(binding_conditionsListEntry, v1_device_request_allocation_result->binding_conditions) {
    if(cJSON_AddStringToObject(binding_conditions, "", binding_conditionsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_device_request_allocation_result->binding_failure_conditions
    if(v1_device_request_allocation_result->binding_failure_conditions) {
    cJSON *binding_failure_conditions = cJSON_AddArrayToObject(item, "bindingFailureConditions");
    if(binding_failure_conditions == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *binding_failure_conditionsListEntry;
    list_ForEach(binding_failure_conditionsListEntry, v1_device_request_allocation_result->binding_failure_conditions) {
    if(cJSON_AddStringToObject(binding_failure_conditions, "", binding_failure_conditionsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_device_request_allocation_result->consumed_capacity
    if(v1_device_request_allocation_result->consumed_capacity) {
    cJSON *consumed_capacity = cJSON_AddObjectToObject(item, "consumedCapacity");
    if(consumed_capacity == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = consumed_capacity;
    listEntry_t *consumed_capacityListEntry;
    if (v1_device_request_allocation_result->consumed_capacity) {
    list_ForEach(consumed_capacityListEntry, v1_device_request_allocation_result->consumed_capacity) {
        keyValuePair_t *localKeyValue = consumed_capacityListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
    }


    // v1_device_request_allocation_result->device
    if (!v1_device_request_allocation_result->device) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "device", v1_device_request_allocation_result->device) == NULL) {
    goto fail; //String
    }


    // v1_device_request_allocation_result->driver
    if (!v1_device_request_allocation_result->driver) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "driver", v1_device_request_allocation_result->driver) == NULL) {
    goto fail; //String
    }


    // v1_device_request_allocation_result->pool
    if (!v1_device_request_allocation_result->pool) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "pool", v1_device_request_allocation_result->pool) == NULL) {
    goto fail; //String
    }


    // v1_device_request_allocation_result->request
    if (!v1_device_request_allocation_result->request) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "request", v1_device_request_allocation_result->request) == NULL) {
    goto fail; //String
    }


    // v1_device_request_allocation_result->share_id
    if(v1_device_request_allocation_result->share_id) {
    if(cJSON_AddStringToObject(item, "shareID", v1_device_request_allocation_result->share_id) == NULL) {
    goto fail; //String
    }
    }


    // v1_device_request_allocation_result->skip_node_operations
    if(v1_device_request_allocation_result->skip_node_operations) {
    cJSON *skip_node_operations = cJSON_AddArrayToObject(item, "skipNodeOperations");
    if(skip_node_operations == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *skip_node_operationsListEntry;
    list_ForEach(skip_node_operationsListEntry, v1_device_request_allocation_result->skip_node_operations) {
    if(cJSON_AddStringToObject(skip_node_operations, "", skip_node_operationsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_device_request_allocation_result->tolerations
    if(v1_device_request_allocation_result->tolerations) {
    cJSON *tolerations = cJSON_AddArrayToObject(item, "tolerations");
    if(tolerations == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *tolerationsListEntry;
    if (v1_device_request_allocation_result->tolerations) {
    list_ForEach(tolerationsListEntry, v1_device_request_allocation_result->tolerations) {
    cJSON *itemLocal = v1_device_toleration_convertToJSON(tolerationsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(tolerations, itemLocal);
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

v1_device_request_allocation_result_t *v1_device_request_allocation_result_parseFromJSON(cJSON *v1_device_request_allocation_resultJSON){

    v1_device_request_allocation_result_t *v1_device_request_allocation_result_local_var = NULL;

    // define the local variable for v1_device_request_allocation_result->admin_access
    int *admin_access_local_var = NULL;

    // define the local list for v1_device_request_allocation_result->binding_conditions
    list_t *binding_conditionsList = NULL;

    // define the local list for v1_device_request_allocation_result->binding_failure_conditions
    list_t *binding_failure_conditionsList = NULL;

    // define the local map for v1_device_request_allocation_result->consumed_capacity
    list_t *consumed_capacityList = NULL;

    char *device_local_str = NULL;

    char *driver_local_str = NULL;

    char *pool_local_str = NULL;

    char *request_local_str = NULL;

    char *share_id_local_str = NULL;

    // define the local list for v1_device_request_allocation_result->skip_node_operations
    list_t *skip_node_operationsList = NULL;

    // define the local list for v1_device_request_allocation_result->tolerations
    list_t *tolerationsList = NULL;

    // v1_device_request_allocation_result->admin_access
    cJSON *admin_access = cJSON_GetObjectItemCaseSensitive(v1_device_request_allocation_resultJSON, "adminAccess");
    if (cJSON_IsNull(admin_access)) {
        admin_access = NULL;
    }
    if (admin_access) { 
    if(!cJSON_IsBool(admin_access))
    {
    goto end; //Bool
    }
    admin_access_local_var = malloc(sizeof(int));
    if(!admin_access_local_var)
    {
        goto end;
    }
    *admin_access_local_var = admin_access->valueint;
    }

    // v1_device_request_allocation_result->binding_conditions
    cJSON *binding_conditions = cJSON_GetObjectItemCaseSensitive(v1_device_request_allocation_resultJSON, "bindingConditions");
    if (cJSON_IsNull(binding_conditions)) {
        binding_conditions = NULL;
    }
    if (binding_conditions) { 
    cJSON *binding_conditions_local = NULL;
    if(!cJSON_IsArray(binding_conditions)) {
        goto end;//primitive container
    }
    binding_conditionsList = list_createList();

    cJSON_ArrayForEach(binding_conditions_local, binding_conditions)
    {
        if(!cJSON_IsString(binding_conditions_local))
        {
            goto end;
        }
        list_addElement(binding_conditionsList , strdup(binding_conditions_local->valuestring));
    }
    }

    // v1_device_request_allocation_result->binding_failure_conditions
    cJSON *binding_failure_conditions = cJSON_GetObjectItemCaseSensitive(v1_device_request_allocation_resultJSON, "bindingFailureConditions");
    if (cJSON_IsNull(binding_failure_conditions)) {
        binding_failure_conditions = NULL;
    }
    if (binding_failure_conditions) { 
    cJSON *binding_failure_conditions_local = NULL;
    if(!cJSON_IsArray(binding_failure_conditions)) {
        goto end;//primitive container
    }
    binding_failure_conditionsList = list_createList();

    cJSON_ArrayForEach(binding_failure_conditions_local, binding_failure_conditions)
    {
        if(!cJSON_IsString(binding_failure_conditions_local))
        {
            goto end;
        }
        list_addElement(binding_failure_conditionsList , strdup(binding_failure_conditions_local->valuestring));
    }
    }

    // v1_device_request_allocation_result->consumed_capacity
    cJSON *consumed_capacity = cJSON_GetObjectItemCaseSensitive(v1_device_request_allocation_resultJSON, "consumedCapacity");
    if (cJSON_IsNull(consumed_capacity)) {
        consumed_capacity = NULL;
    }
    if (consumed_capacity) { 
    cJSON *consumed_capacity_local_map = NULL;
    if(!cJSON_IsObject(consumed_capacity) && !cJSON_IsNull(consumed_capacity))
    {
        goto end;//primitive map container
    }
    if(cJSON_IsObject(consumed_capacity))
    {
        consumed_capacityList = list_createList();
        keyValuePair_t *localMapKeyPair;
        cJSON_ArrayForEach(consumed_capacity_local_map, consumed_capacity)
        {
            cJSON *localMapObject = consumed_capacity_local_map;
            if(!cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(consumed_capacityList , localMapKeyPair);
        }
    }
    }

    // v1_device_request_allocation_result->device
    cJSON *device = cJSON_GetObjectItemCaseSensitive(v1_device_request_allocation_resultJSON, "device");
    if (cJSON_IsNull(device)) {
        device = NULL;
    }
    if (!device) {
        goto end;
    }

    
    if(!cJSON_IsString(device))
    {
    goto end; //String
    }

    // v1_device_request_allocation_result->driver
    cJSON *driver = cJSON_GetObjectItemCaseSensitive(v1_device_request_allocation_resultJSON, "driver");
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

    // v1_device_request_allocation_result->pool
    cJSON *pool = cJSON_GetObjectItemCaseSensitive(v1_device_request_allocation_resultJSON, "pool");
    if (cJSON_IsNull(pool)) {
        pool = NULL;
    }
    if (!pool) {
        goto end;
    }

    
    if(!cJSON_IsString(pool))
    {
    goto end; //String
    }

    // v1_device_request_allocation_result->request
    cJSON *request = cJSON_GetObjectItemCaseSensitive(v1_device_request_allocation_resultJSON, "request");
    if (cJSON_IsNull(request)) {
        request = NULL;
    }
    if (!request) {
        goto end;
    }

    
    if(!cJSON_IsString(request))
    {
    goto end; //String
    }

    // v1_device_request_allocation_result->share_id
    cJSON *share_id = cJSON_GetObjectItemCaseSensitive(v1_device_request_allocation_resultJSON, "shareID");
    if (cJSON_IsNull(share_id)) {
        share_id = NULL;
    }
    if (share_id) { 
    if(!cJSON_IsString(share_id) && !cJSON_IsNull(share_id))
    {
    goto end; //String
    }
    }

    // v1_device_request_allocation_result->skip_node_operations
    cJSON *skip_node_operations = cJSON_GetObjectItemCaseSensitive(v1_device_request_allocation_resultJSON, "skipNodeOperations");
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

    // v1_device_request_allocation_result->tolerations
    cJSON *tolerations = cJSON_GetObjectItemCaseSensitive(v1_device_request_allocation_resultJSON, "tolerations");
    if (cJSON_IsNull(tolerations)) {
        tolerations = NULL;
    }
    if (tolerations) { 
    cJSON *tolerations_local_nonprimitive = NULL;
    if(!cJSON_IsArray(tolerations)){
        goto end; //nonprimitive container
    }

    tolerationsList = list_createList();

    cJSON_ArrayForEach(tolerations_local_nonprimitive,tolerations )
    {
        if(!cJSON_IsObject(tolerations_local_nonprimitive)){
            goto end;
        }
        v1_device_toleration_t *tolerationsItem = v1_device_toleration_parseFromJSON(tolerations_local_nonprimitive);

        list_addElement(tolerationsList, tolerationsItem);
    }
    }


    if (device && !cJSON_IsNull(device)) device_local_str = strdup(device->valuestring);
    if (driver && !cJSON_IsNull(driver)) driver_local_str = strdup(driver->valuestring);
    if (pool && !cJSON_IsNull(pool)) pool_local_str = strdup(pool->valuestring);
    if (request && !cJSON_IsNull(request)) request_local_str = strdup(request->valuestring);
    if (share_id && !cJSON_IsNull(share_id)) share_id_local_str = strdup(share_id->valuestring);

    v1_device_request_allocation_result_local_var = v1_device_request_allocation_result_create_internal (
        admin_access_local_var,
        binding_conditions ? binding_conditionsList : NULL,
        binding_failure_conditions ? binding_failure_conditionsList : NULL,
        consumed_capacity ? consumed_capacityList : NULL,
        device_local_str,
        driver_local_str,
        pool_local_str,
        request_local_str,
        share_id_local_str,
        skip_node_operations ? skip_node_operationsList : NULL,
        tolerations ? tolerationsList : NULL
        );

    if (!v1_device_request_allocation_result_local_var) {
        goto end;
    }

    return v1_device_request_allocation_result_local_var;
end:
    if (admin_access_local_var) {
        free(admin_access_local_var);
        admin_access_local_var = NULL;
    }
    if (binding_conditionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, binding_conditionsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(binding_conditionsList);
        binding_conditionsList = NULL;
    }
    if (binding_failure_conditionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, binding_failure_conditionsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(binding_failure_conditionsList);
        binding_failure_conditionsList = NULL;
    }
    if (consumed_capacityList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, consumed_capacityList) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(consumed_capacityList);
        consumed_capacityList = NULL;
    }
    if (device_local_str) {
        free(device_local_str);
        device_local_str = NULL;
    }
    if (driver_local_str) {
        free(driver_local_str);
        driver_local_str = NULL;
    }
    if (pool_local_str) {
        free(pool_local_str);
        pool_local_str = NULL;
    }
    if (request_local_str) {
        free(request_local_str);
        request_local_str = NULL;
    }
    if (share_id_local_str) {
        free(share_id_local_str);
        share_id_local_str = NULL;
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
    if (tolerationsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, tolerationsList) {
            v1_device_toleration_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(tolerationsList);
        tolerationsList = NULL;
    }
    return NULL;

}
