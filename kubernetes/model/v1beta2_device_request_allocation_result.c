#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_device_request_allocation_result.h"



static v1beta2_device_request_allocation_result_t *v1beta2_device_request_allocation_result_create_internal(
    int admin_access,
    list_t *binding_conditions,
    list_t *binding_failure_conditions,
    list_t* consumed_capacity,
    char *device,
    char *driver,
    char *pool,
    char *request,
    char *share_id,
    list_t *tolerations
    ) {
    v1beta2_device_request_allocation_result_t *v1beta2_device_request_allocation_result_local_var = malloc(sizeof(v1beta2_device_request_allocation_result_t));
    if (!v1beta2_device_request_allocation_result_local_var) {
        return NULL;
    }
    v1beta2_device_request_allocation_result_local_var->admin_access = admin_access;
    v1beta2_device_request_allocation_result_local_var->binding_conditions = binding_conditions;
    v1beta2_device_request_allocation_result_local_var->binding_failure_conditions = binding_failure_conditions;
    v1beta2_device_request_allocation_result_local_var->consumed_capacity = consumed_capacity;
    v1beta2_device_request_allocation_result_local_var->device = device;
    v1beta2_device_request_allocation_result_local_var->driver = driver;
    v1beta2_device_request_allocation_result_local_var->pool = pool;
    v1beta2_device_request_allocation_result_local_var->request = request;
    v1beta2_device_request_allocation_result_local_var->share_id = share_id;
    v1beta2_device_request_allocation_result_local_var->tolerations = tolerations;

    v1beta2_device_request_allocation_result_local_var->_library_owned = 1;
    return v1beta2_device_request_allocation_result_local_var;
}

__attribute__((deprecated)) v1beta2_device_request_allocation_result_t *v1beta2_device_request_allocation_result_create(
    int admin_access,
    list_t *binding_conditions,
    list_t *binding_failure_conditions,
    list_t* consumed_capacity,
    char *device,
    char *driver,
    char *pool,
    char *request,
    char *share_id,
    list_t *tolerations
    ) {
    return v1beta2_device_request_allocation_result_create_internal (
        admin_access,
        binding_conditions,
        binding_failure_conditions,
        consumed_capacity,
        device,
        driver,
        pool,
        request,
        share_id,
        tolerations
        );
}

void v1beta2_device_request_allocation_result_free(v1beta2_device_request_allocation_result_t *v1beta2_device_request_allocation_result) {
    if(NULL == v1beta2_device_request_allocation_result){
        return ;
    }
    if(v1beta2_device_request_allocation_result->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta2_device_request_allocation_result_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta2_device_request_allocation_result->binding_conditions) {
        list_ForEach(listEntry, v1beta2_device_request_allocation_result->binding_conditions) {
            free(listEntry->data);
        }
        list_freeList(v1beta2_device_request_allocation_result->binding_conditions);
        v1beta2_device_request_allocation_result->binding_conditions = NULL;
    }
    if (v1beta2_device_request_allocation_result->binding_failure_conditions) {
        list_ForEach(listEntry, v1beta2_device_request_allocation_result->binding_failure_conditions) {
            free(listEntry->data);
        }
        list_freeList(v1beta2_device_request_allocation_result->binding_failure_conditions);
        v1beta2_device_request_allocation_result->binding_failure_conditions = NULL;
    }
    if (v1beta2_device_request_allocation_result->consumed_capacity) {
        list_ForEach(listEntry, v1beta2_device_request_allocation_result->consumed_capacity) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1beta2_device_request_allocation_result->consumed_capacity);
        v1beta2_device_request_allocation_result->consumed_capacity = NULL;
    }
    if (v1beta2_device_request_allocation_result->device) {
        free(v1beta2_device_request_allocation_result->device);
        v1beta2_device_request_allocation_result->device = NULL;
    }
    if (v1beta2_device_request_allocation_result->driver) {
        free(v1beta2_device_request_allocation_result->driver);
        v1beta2_device_request_allocation_result->driver = NULL;
    }
    if (v1beta2_device_request_allocation_result->pool) {
        free(v1beta2_device_request_allocation_result->pool);
        v1beta2_device_request_allocation_result->pool = NULL;
    }
    if (v1beta2_device_request_allocation_result->request) {
        free(v1beta2_device_request_allocation_result->request);
        v1beta2_device_request_allocation_result->request = NULL;
    }
    if (v1beta2_device_request_allocation_result->share_id) {
        free(v1beta2_device_request_allocation_result->share_id);
        v1beta2_device_request_allocation_result->share_id = NULL;
    }
    if (v1beta2_device_request_allocation_result->tolerations) {
        list_ForEach(listEntry, v1beta2_device_request_allocation_result->tolerations) {
            v1beta2_device_toleration_free(listEntry->data);
        }
        list_freeList(v1beta2_device_request_allocation_result->tolerations);
        v1beta2_device_request_allocation_result->tolerations = NULL;
    }
    free(v1beta2_device_request_allocation_result);
}

cJSON *v1beta2_device_request_allocation_result_convertToJSON(v1beta2_device_request_allocation_result_t *v1beta2_device_request_allocation_result) {
    cJSON *item = cJSON_CreateObject();

    // v1beta2_device_request_allocation_result->admin_access
    if(v1beta2_device_request_allocation_result->admin_access) {
    if(cJSON_AddBoolToObject(item, "adminAccess", v1beta2_device_request_allocation_result->admin_access) == NULL) {
    goto fail; //Bool
    }
    }


    // v1beta2_device_request_allocation_result->binding_conditions
    if(v1beta2_device_request_allocation_result->binding_conditions) {
    cJSON *binding_conditions = cJSON_AddArrayToObject(item, "bindingConditions");
    if(binding_conditions == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *binding_conditionsListEntry;
    list_ForEach(binding_conditionsListEntry, v1beta2_device_request_allocation_result->binding_conditions) {
    if(cJSON_AddStringToObject(binding_conditions, "", binding_conditionsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1beta2_device_request_allocation_result->binding_failure_conditions
    if(v1beta2_device_request_allocation_result->binding_failure_conditions) {
    cJSON *binding_failure_conditions = cJSON_AddArrayToObject(item, "bindingFailureConditions");
    if(binding_failure_conditions == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *binding_failure_conditionsListEntry;
    list_ForEach(binding_failure_conditionsListEntry, v1beta2_device_request_allocation_result->binding_failure_conditions) {
    if(cJSON_AddStringToObject(binding_failure_conditions, "", binding_failure_conditionsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1beta2_device_request_allocation_result->consumed_capacity
    if(v1beta2_device_request_allocation_result->consumed_capacity) {
    cJSON *consumed_capacity = cJSON_AddObjectToObject(item, "consumedCapacity");
    if(consumed_capacity == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = consumed_capacity;
    listEntry_t *consumed_capacityListEntry;
    if (v1beta2_device_request_allocation_result->consumed_capacity) {
    list_ForEach(consumed_capacityListEntry, v1beta2_device_request_allocation_result->consumed_capacity) {
        keyValuePair_t *localKeyValue = consumed_capacityListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
    }


    // v1beta2_device_request_allocation_result->device
    if (!v1beta2_device_request_allocation_result->device) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "device", v1beta2_device_request_allocation_result->device) == NULL) {
    goto fail; //String
    }


    // v1beta2_device_request_allocation_result->driver
    if (!v1beta2_device_request_allocation_result->driver) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "driver", v1beta2_device_request_allocation_result->driver) == NULL) {
    goto fail; //String
    }


    // v1beta2_device_request_allocation_result->pool
    if (!v1beta2_device_request_allocation_result->pool) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "pool", v1beta2_device_request_allocation_result->pool) == NULL) {
    goto fail; //String
    }


    // v1beta2_device_request_allocation_result->request
    if (!v1beta2_device_request_allocation_result->request) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "request", v1beta2_device_request_allocation_result->request) == NULL) {
    goto fail; //String
    }


    // v1beta2_device_request_allocation_result->share_id
    if(v1beta2_device_request_allocation_result->share_id) {
    if(cJSON_AddStringToObject(item, "shareID", v1beta2_device_request_allocation_result->share_id) == NULL) {
    goto fail; //String
    }
    }


    // v1beta2_device_request_allocation_result->tolerations
    if(v1beta2_device_request_allocation_result->tolerations) {
    cJSON *tolerations = cJSON_AddArrayToObject(item, "tolerations");
    if(tolerations == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *tolerationsListEntry;
    if (v1beta2_device_request_allocation_result->tolerations) {
    list_ForEach(tolerationsListEntry, v1beta2_device_request_allocation_result->tolerations) {
    cJSON *itemLocal = v1beta2_device_toleration_convertToJSON(tolerationsListEntry->data);
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

v1beta2_device_request_allocation_result_t *v1beta2_device_request_allocation_result_parseFromJSON(cJSON *v1beta2_device_request_allocation_resultJSON){

    v1beta2_device_request_allocation_result_t *v1beta2_device_request_allocation_result_local_var = NULL;

    // define the local list for v1beta2_device_request_allocation_result->binding_conditions
    list_t *binding_conditionsList = NULL;

    // define the local list for v1beta2_device_request_allocation_result->binding_failure_conditions
    list_t *binding_failure_conditionsList = NULL;

    // define the local map for v1beta2_device_request_allocation_result->consumed_capacity
    list_t *consumed_capacityList = NULL;

    // define the local list for v1beta2_device_request_allocation_result->tolerations
    list_t *tolerationsList = NULL;

    // v1beta2_device_request_allocation_result->admin_access
    cJSON *admin_access = cJSON_GetObjectItemCaseSensitive(v1beta2_device_request_allocation_resultJSON, "adminAccess");
    if (cJSON_IsNull(admin_access)) {
        admin_access = NULL;
    }
    if (admin_access) { 
    if(!cJSON_IsBool(admin_access))
    {
    goto end; //Bool
    }
    }

    // v1beta2_device_request_allocation_result->binding_conditions
    cJSON *binding_conditions = cJSON_GetObjectItemCaseSensitive(v1beta2_device_request_allocation_resultJSON, "bindingConditions");
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

    // v1beta2_device_request_allocation_result->binding_failure_conditions
    cJSON *binding_failure_conditions = cJSON_GetObjectItemCaseSensitive(v1beta2_device_request_allocation_resultJSON, "bindingFailureConditions");
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

    // v1beta2_device_request_allocation_result->consumed_capacity
    cJSON *consumed_capacity = cJSON_GetObjectItemCaseSensitive(v1beta2_device_request_allocation_resultJSON, "consumedCapacity");
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

    // v1beta2_device_request_allocation_result->device
    cJSON *device = cJSON_GetObjectItemCaseSensitive(v1beta2_device_request_allocation_resultJSON, "device");
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

    // v1beta2_device_request_allocation_result->driver
    cJSON *driver = cJSON_GetObjectItemCaseSensitive(v1beta2_device_request_allocation_resultJSON, "driver");
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

    // v1beta2_device_request_allocation_result->pool
    cJSON *pool = cJSON_GetObjectItemCaseSensitive(v1beta2_device_request_allocation_resultJSON, "pool");
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

    // v1beta2_device_request_allocation_result->request
    cJSON *request = cJSON_GetObjectItemCaseSensitive(v1beta2_device_request_allocation_resultJSON, "request");
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

    // v1beta2_device_request_allocation_result->share_id
    cJSON *share_id = cJSON_GetObjectItemCaseSensitive(v1beta2_device_request_allocation_resultJSON, "shareID");
    if (cJSON_IsNull(share_id)) {
        share_id = NULL;
    }
    if (share_id) { 
    if(!cJSON_IsString(share_id) && !cJSON_IsNull(share_id))
    {
    goto end; //String
    }
    }

    // v1beta2_device_request_allocation_result->tolerations
    cJSON *tolerations = cJSON_GetObjectItemCaseSensitive(v1beta2_device_request_allocation_resultJSON, "tolerations");
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
        v1beta2_device_toleration_t *tolerationsItem = v1beta2_device_toleration_parseFromJSON(tolerations_local_nonprimitive);

        list_addElement(tolerationsList, tolerationsItem);
    }
    }


    v1beta2_device_request_allocation_result_local_var = v1beta2_device_request_allocation_result_create_internal (
        admin_access ? admin_access->valueint : 0,
        binding_conditions ? binding_conditionsList : NULL,
        binding_failure_conditions ? binding_failure_conditionsList : NULL,
        consumed_capacity ? consumed_capacityList : NULL,
        strdup(device->valuestring),
        strdup(driver->valuestring),
        strdup(pool->valuestring),
        strdup(request->valuestring),
        share_id && !cJSON_IsNull(share_id) ? strdup(share_id->valuestring) : NULL,
        tolerations ? tolerationsList : NULL
        );

    return v1beta2_device_request_allocation_result_local_var;
end:
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
    if (tolerationsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, tolerationsList) {
            v1beta2_device_toleration_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(tolerationsList);
        tolerationsList = NULL;
    }
    return NULL;

}
