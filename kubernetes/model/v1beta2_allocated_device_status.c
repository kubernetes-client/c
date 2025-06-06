#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_allocated_device_status.h"



static v1beta2_allocated_device_status_t *v1beta2_allocated_device_status_create_internal(
    list_t *conditions,
    object_t *data,
    char *device,
    char *driver,
    v1beta2_network_device_data_t *network_data,
    char *pool
    ) {
    v1beta2_allocated_device_status_t *v1beta2_allocated_device_status_local_var = malloc(sizeof(v1beta2_allocated_device_status_t));
    if (!v1beta2_allocated_device_status_local_var) {
        return NULL;
    }
    v1beta2_allocated_device_status_local_var->conditions = conditions;
    v1beta2_allocated_device_status_local_var->data = data;
    v1beta2_allocated_device_status_local_var->device = device;
    v1beta2_allocated_device_status_local_var->driver = driver;
    v1beta2_allocated_device_status_local_var->network_data = network_data;
    v1beta2_allocated_device_status_local_var->pool = pool;

    v1beta2_allocated_device_status_local_var->_library_owned = 1;
    return v1beta2_allocated_device_status_local_var;
}

__attribute__((deprecated)) v1beta2_allocated_device_status_t *v1beta2_allocated_device_status_create(
    list_t *conditions,
    object_t *data,
    char *device,
    char *driver,
    v1beta2_network_device_data_t *network_data,
    char *pool
    ) {
    return v1beta2_allocated_device_status_create_internal (
        conditions,
        data,
        device,
        driver,
        network_data,
        pool
        );
}

void v1beta2_allocated_device_status_free(v1beta2_allocated_device_status_t *v1beta2_allocated_device_status) {
    if(NULL == v1beta2_allocated_device_status){
        return ;
    }
    if(v1beta2_allocated_device_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta2_allocated_device_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta2_allocated_device_status->conditions) {
        list_ForEach(listEntry, v1beta2_allocated_device_status->conditions) {
            v1_condition_free(listEntry->data);
        }
        list_freeList(v1beta2_allocated_device_status->conditions);
        v1beta2_allocated_device_status->conditions = NULL;
    }
    if (v1beta2_allocated_device_status->data) {
        object_free(v1beta2_allocated_device_status->data);
        v1beta2_allocated_device_status->data = NULL;
    }
    if (v1beta2_allocated_device_status->device) {
        free(v1beta2_allocated_device_status->device);
        v1beta2_allocated_device_status->device = NULL;
    }
    if (v1beta2_allocated_device_status->driver) {
        free(v1beta2_allocated_device_status->driver);
        v1beta2_allocated_device_status->driver = NULL;
    }
    if (v1beta2_allocated_device_status->network_data) {
        v1beta2_network_device_data_free(v1beta2_allocated_device_status->network_data);
        v1beta2_allocated_device_status->network_data = NULL;
    }
    if (v1beta2_allocated_device_status->pool) {
        free(v1beta2_allocated_device_status->pool);
        v1beta2_allocated_device_status->pool = NULL;
    }
    free(v1beta2_allocated_device_status);
}

cJSON *v1beta2_allocated_device_status_convertToJSON(v1beta2_allocated_device_status_t *v1beta2_allocated_device_status) {
    cJSON *item = cJSON_CreateObject();

    // v1beta2_allocated_device_status->conditions
    if(v1beta2_allocated_device_status->conditions) {
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v1beta2_allocated_device_status->conditions) {
    list_ForEach(conditionsListEntry, v1beta2_allocated_device_status->conditions) {
    cJSON *itemLocal = v1_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
    }


    // v1beta2_allocated_device_status->data
    if(v1beta2_allocated_device_status->data) {
    cJSON *data_object = object_convertToJSON(v1beta2_allocated_device_status->data);
    if(data_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "data", data_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1beta2_allocated_device_status->device
    if (!v1beta2_allocated_device_status->device) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "device", v1beta2_allocated_device_status->device) == NULL) {
    goto fail; //String
    }


    // v1beta2_allocated_device_status->driver
    if (!v1beta2_allocated_device_status->driver) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "driver", v1beta2_allocated_device_status->driver) == NULL) {
    goto fail; //String
    }


    // v1beta2_allocated_device_status->network_data
    if(v1beta2_allocated_device_status->network_data) {
    cJSON *network_data_local_JSON = v1beta2_network_device_data_convertToJSON(v1beta2_allocated_device_status->network_data);
    if(network_data_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "networkData", network_data_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1beta2_allocated_device_status->pool
    if (!v1beta2_allocated_device_status->pool) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "pool", v1beta2_allocated_device_status->pool) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta2_allocated_device_status_t *v1beta2_allocated_device_status_parseFromJSON(cJSON *v1beta2_allocated_device_statusJSON){

    v1beta2_allocated_device_status_t *v1beta2_allocated_device_status_local_var = NULL;

    // define the local list for v1beta2_allocated_device_status->conditions
    list_t *conditionsList = NULL;

    // define the local variable for v1beta2_allocated_device_status->network_data
    v1beta2_network_device_data_t *network_data_local_nonprim = NULL;

    // v1beta2_allocated_device_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v1beta2_allocated_device_statusJSON, "conditions");
    if (cJSON_IsNull(conditions)) {
        conditions = NULL;
    }
    if (conditions) { 
    cJSON *conditions_local_nonprimitive = NULL;
    if(!cJSON_IsArray(conditions)){
        goto end; //nonprimitive container
    }

    conditionsList = list_createList();

    cJSON_ArrayForEach(conditions_local_nonprimitive,conditions )
    {
        if(!cJSON_IsObject(conditions_local_nonprimitive)){
            goto end;
        }
        v1_condition_t *conditionsItem = v1_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }

    // v1beta2_allocated_device_status->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(v1beta2_allocated_device_statusJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    object_t *data_local_object = NULL;
    if (data) { 
    data_local_object = object_parseFromJSON(data); //object
    }

    // v1beta2_allocated_device_status->device
    cJSON *device = cJSON_GetObjectItemCaseSensitive(v1beta2_allocated_device_statusJSON, "device");
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

    // v1beta2_allocated_device_status->driver
    cJSON *driver = cJSON_GetObjectItemCaseSensitive(v1beta2_allocated_device_statusJSON, "driver");
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

    // v1beta2_allocated_device_status->network_data
    cJSON *network_data = cJSON_GetObjectItemCaseSensitive(v1beta2_allocated_device_statusJSON, "networkData");
    if (cJSON_IsNull(network_data)) {
        network_data = NULL;
    }
    if (network_data) { 
    network_data_local_nonprim = v1beta2_network_device_data_parseFromJSON(network_data); //nonprimitive
    }

    // v1beta2_allocated_device_status->pool
    cJSON *pool = cJSON_GetObjectItemCaseSensitive(v1beta2_allocated_device_statusJSON, "pool");
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


    v1beta2_allocated_device_status_local_var = v1beta2_allocated_device_status_create_internal (
        conditions ? conditionsList : NULL,
        data ? data_local_object : NULL,
        strdup(device->valuestring),
        strdup(driver->valuestring),
        network_data ? network_data_local_nonprim : NULL,
        strdup(pool->valuestring)
        );

    return v1beta2_allocated_device_status_local_var;
end:
    if (conditionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, conditionsList) {
            v1_condition_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(conditionsList);
        conditionsList = NULL;
    }
    if (network_data_local_nonprim) {
        v1beta2_network_device_data_free(network_data_local_nonprim);
        network_data_local_nonprim = NULL;
    }
    return NULL;

}
