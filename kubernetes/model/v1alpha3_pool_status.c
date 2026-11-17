#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_pool_status.h"



static v1alpha3_pool_status_t *v1alpha3_pool_status_create_internal(
    int *allocated_devices,
    int *available_devices,
    char *driver,
    long *generation,
    char *node_name,
    list_t *partition_summary,
    char *pool_name,
    int *resource_slice_count,
    v1alpha3_shareable_summary_status_t *shareable_summary,
    int *total_devices,
    int *unavailable_devices,
    char *validation_error
    ) {
    v1alpha3_pool_status_t *v1alpha3_pool_status_local_var = malloc(sizeof(v1alpha3_pool_status_t));
    if (!v1alpha3_pool_status_local_var) {
        return NULL;
    }
    memset(v1alpha3_pool_status_local_var, 0, sizeof(v1alpha3_pool_status_t));
    v1alpha3_pool_status_local_var->_library_owned = 1;
    v1alpha3_pool_status_local_var->allocated_devices = allocated_devices;
    v1alpha3_pool_status_local_var->available_devices = available_devices;
    v1alpha3_pool_status_local_var->driver = driver;
    v1alpha3_pool_status_local_var->generation = generation;
    v1alpha3_pool_status_local_var->node_name = node_name;
    v1alpha3_pool_status_local_var->partition_summary = partition_summary;
    v1alpha3_pool_status_local_var->pool_name = pool_name;
    v1alpha3_pool_status_local_var->resource_slice_count = resource_slice_count;
    v1alpha3_pool_status_local_var->shareable_summary = shareable_summary;
    v1alpha3_pool_status_local_var->total_devices = total_devices;
    v1alpha3_pool_status_local_var->unavailable_devices = unavailable_devices;
    v1alpha3_pool_status_local_var->validation_error = validation_error;
    return v1alpha3_pool_status_local_var;
}

__attribute__((deprecated)) v1alpha3_pool_status_t *v1alpha3_pool_status_create(
    int *allocated_devices,
    int *available_devices,
    char *driver,
    long *generation,
    char *node_name,
    list_t *partition_summary,
    char *pool_name,
    int *resource_slice_count,
    v1alpha3_shareable_summary_status_t *shareable_summary,
    int *total_devices,
    int *unavailable_devices,
    char *validation_error
    ) {
    int *allocated_devices_copy = NULL;
    if (allocated_devices) {
        allocated_devices_copy = malloc(sizeof(int));
        if (allocated_devices_copy) *allocated_devices_copy = *allocated_devices;
    }
    int *available_devices_copy = NULL;
    if (available_devices) {
        available_devices_copy = malloc(sizeof(int));
        if (available_devices_copy) *available_devices_copy = *available_devices;
    }
    long *generation_copy = NULL;
    if (generation) {
        generation_copy = malloc(sizeof(long));
        if (generation_copy) *generation_copy = *generation;
    }
    int *resource_slice_count_copy = NULL;
    if (resource_slice_count) {
        resource_slice_count_copy = malloc(sizeof(int));
        if (resource_slice_count_copy) *resource_slice_count_copy = *resource_slice_count;
    }
    int *total_devices_copy = NULL;
    if (total_devices) {
        total_devices_copy = malloc(sizeof(int));
        if (total_devices_copy) *total_devices_copy = *total_devices;
    }
    int *unavailable_devices_copy = NULL;
    if (unavailable_devices) {
        unavailable_devices_copy = malloc(sizeof(int));
        if (unavailable_devices_copy) *unavailable_devices_copy = *unavailable_devices;
    }
    v1alpha3_pool_status_t *result = v1alpha3_pool_status_create_internal (
        allocated_devices_copy,
        available_devices_copy,
        driver,
        generation_copy,
        node_name,
        partition_summary,
        pool_name,
        resource_slice_count_copy,
        shareable_summary,
        total_devices_copy,
        unavailable_devices_copy,
        validation_error
        );
    if (!result) {
        free(allocated_devices_copy);
        free(available_devices_copy);
        free(generation_copy);
        free(resource_slice_count_copy);
        free(total_devices_copy);
        free(unavailable_devices_copy);
    }
    return result;
}

void v1alpha3_pool_status_free(v1alpha3_pool_status_t *v1alpha3_pool_status) {
    if(NULL == v1alpha3_pool_status){
        return ;
    }
    if(v1alpha3_pool_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha3_pool_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_pool_status->allocated_devices) {
        free(v1alpha3_pool_status->allocated_devices);
        v1alpha3_pool_status->allocated_devices = NULL;
    }
    if (v1alpha3_pool_status->available_devices) {
        free(v1alpha3_pool_status->available_devices);
        v1alpha3_pool_status->available_devices = NULL;
    }
    if (v1alpha3_pool_status->driver) {
        free(v1alpha3_pool_status->driver);
        v1alpha3_pool_status->driver = NULL;
    }
    if (v1alpha3_pool_status->generation) {
        free(v1alpha3_pool_status->generation);
        v1alpha3_pool_status->generation = NULL;
    }
    if (v1alpha3_pool_status->node_name) {
        free(v1alpha3_pool_status->node_name);
        v1alpha3_pool_status->node_name = NULL;
    }
    if (v1alpha3_pool_status->partition_summary) {
        list_ForEach(listEntry, v1alpha3_pool_status->partition_summary) {
            v1alpha3_partition_type_status_free(listEntry->data);
        }
        list_freeList(v1alpha3_pool_status->partition_summary);
        v1alpha3_pool_status->partition_summary = NULL;
    }
    if (v1alpha3_pool_status->pool_name) {
        free(v1alpha3_pool_status->pool_name);
        v1alpha3_pool_status->pool_name = NULL;
    }
    if (v1alpha3_pool_status->resource_slice_count) {
        free(v1alpha3_pool_status->resource_slice_count);
        v1alpha3_pool_status->resource_slice_count = NULL;
    }
    if (v1alpha3_pool_status->shareable_summary) {
        v1alpha3_shareable_summary_status_free(v1alpha3_pool_status->shareable_summary);
        v1alpha3_pool_status->shareable_summary = NULL;
    }
    if (v1alpha3_pool_status->total_devices) {
        free(v1alpha3_pool_status->total_devices);
        v1alpha3_pool_status->total_devices = NULL;
    }
    if (v1alpha3_pool_status->unavailable_devices) {
        free(v1alpha3_pool_status->unavailable_devices);
        v1alpha3_pool_status->unavailable_devices = NULL;
    }
    if (v1alpha3_pool_status->validation_error) {
        free(v1alpha3_pool_status->validation_error);
        v1alpha3_pool_status->validation_error = NULL;
    }
    free(v1alpha3_pool_status);
}

cJSON *v1alpha3_pool_status_convertToJSON(v1alpha3_pool_status_t *v1alpha3_pool_status) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_pool_status->allocated_devices
    if(v1alpha3_pool_status->allocated_devices) {
    if(cJSON_AddNumberToObject(item, "allocatedDevices", *v1alpha3_pool_status->allocated_devices) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1alpha3_pool_status->available_devices
    if(v1alpha3_pool_status->available_devices) {
    if(cJSON_AddNumberToObject(item, "availableDevices", *v1alpha3_pool_status->available_devices) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1alpha3_pool_status->driver
    if (!v1alpha3_pool_status->driver) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "driver", v1alpha3_pool_status->driver) == NULL) {
    goto fail; //String
    }


    // v1alpha3_pool_status->generation
    if (!v1alpha3_pool_status->generation) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "generation", *v1alpha3_pool_status->generation) == NULL) {
    goto fail; //Numeric
    }


    // v1alpha3_pool_status->node_name
    if(v1alpha3_pool_status->node_name) {
    if(cJSON_AddStringToObject(item, "nodeName", v1alpha3_pool_status->node_name) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha3_pool_status->partition_summary
    if(v1alpha3_pool_status->partition_summary) {
    cJSON *partition_summary = cJSON_AddArrayToObject(item, "partitionSummary");
    if(partition_summary == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *partition_summaryListEntry;
    if (v1alpha3_pool_status->partition_summary) {
    list_ForEach(partition_summaryListEntry, v1alpha3_pool_status->partition_summary) {
    cJSON *itemLocal = v1alpha3_partition_type_status_convertToJSON(partition_summaryListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(partition_summary, itemLocal);
    }
    }
    }


    // v1alpha3_pool_status->pool_name
    if (!v1alpha3_pool_status->pool_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "poolName", v1alpha3_pool_status->pool_name) == NULL) {
    goto fail; //String
    }


    // v1alpha3_pool_status->resource_slice_count
    if(v1alpha3_pool_status->resource_slice_count) {
    if(cJSON_AddNumberToObject(item, "resourceSliceCount", *v1alpha3_pool_status->resource_slice_count) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1alpha3_pool_status->shareable_summary
    if(v1alpha3_pool_status->shareable_summary) {
    cJSON *shareable_summary_local_JSON = v1alpha3_shareable_summary_status_convertToJSON(v1alpha3_pool_status->shareable_summary);
    if(shareable_summary_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "shareableSummary", shareable_summary_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha3_pool_status->total_devices
    if(v1alpha3_pool_status->total_devices) {
    if(cJSON_AddNumberToObject(item, "totalDevices", *v1alpha3_pool_status->total_devices) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1alpha3_pool_status->unavailable_devices
    if(v1alpha3_pool_status->unavailable_devices) {
    if(cJSON_AddNumberToObject(item, "unavailableDevices", *v1alpha3_pool_status->unavailable_devices) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1alpha3_pool_status->validation_error
    if(v1alpha3_pool_status->validation_error) {
    if(cJSON_AddStringToObject(item, "validationError", v1alpha3_pool_status->validation_error) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha3_pool_status_t *v1alpha3_pool_status_parseFromJSON(cJSON *v1alpha3_pool_statusJSON){

    v1alpha3_pool_status_t *v1alpha3_pool_status_local_var = NULL;

    // define the local variable for v1alpha3_pool_status->allocated_devices
    int *allocated_devices_local_var = NULL;

    // define the local variable for v1alpha3_pool_status->available_devices
    int *available_devices_local_var = NULL;

    char *driver_local_str = NULL;

    // define the local variable for v1alpha3_pool_status->generation
    long *generation_local_var = NULL;

    char *node_name_local_str = NULL;

    // define the local list for v1alpha3_pool_status->partition_summary
    list_t *partition_summaryList = NULL;

    char *pool_name_local_str = NULL;

    // define the local variable for v1alpha3_pool_status->resource_slice_count
    int *resource_slice_count_local_var = NULL;

    // define the local variable for v1alpha3_pool_status->shareable_summary
    v1alpha3_shareable_summary_status_t *shareable_summary_local_nonprim = NULL;

    // define the local variable for v1alpha3_pool_status->total_devices
    int *total_devices_local_var = NULL;

    // define the local variable for v1alpha3_pool_status->unavailable_devices
    int *unavailable_devices_local_var = NULL;

    char *validation_error_local_str = NULL;

    // v1alpha3_pool_status->allocated_devices
    cJSON *allocated_devices = cJSON_GetObjectItemCaseSensitive(v1alpha3_pool_statusJSON, "allocatedDevices");
    if (cJSON_IsNull(allocated_devices)) {
        allocated_devices = NULL;
    }
    if (allocated_devices) { 
    if(!cJSON_IsNumber(allocated_devices))
    {
    goto end; //Numeric
    }
    allocated_devices_local_var = malloc(sizeof(int));
    if(!allocated_devices_local_var)
    {
        goto end;
    }
    *allocated_devices_local_var = allocated_devices->valuedouble;
    }

    // v1alpha3_pool_status->available_devices
    cJSON *available_devices = cJSON_GetObjectItemCaseSensitive(v1alpha3_pool_statusJSON, "availableDevices");
    if (cJSON_IsNull(available_devices)) {
        available_devices = NULL;
    }
    if (available_devices) { 
    if(!cJSON_IsNumber(available_devices))
    {
    goto end; //Numeric
    }
    available_devices_local_var = malloc(sizeof(int));
    if(!available_devices_local_var)
    {
        goto end;
    }
    *available_devices_local_var = available_devices->valuedouble;
    }

    // v1alpha3_pool_status->driver
    cJSON *driver = cJSON_GetObjectItemCaseSensitive(v1alpha3_pool_statusJSON, "driver");
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

    // v1alpha3_pool_status->generation
    cJSON *generation = cJSON_GetObjectItemCaseSensitive(v1alpha3_pool_statusJSON, "generation");
    if (cJSON_IsNull(generation)) {
        generation = NULL;
    }
    if (!generation) {
        goto end;
    }

    
    if(!cJSON_IsNumber(generation))
    {
    goto end; //Numeric
    }
    generation_local_var = malloc(sizeof(long));
    if(!generation_local_var)
    {
        goto end;
    }
    *generation_local_var = generation->valuedouble;

    // v1alpha3_pool_status->node_name
    cJSON *node_name = cJSON_GetObjectItemCaseSensitive(v1alpha3_pool_statusJSON, "nodeName");
    if (cJSON_IsNull(node_name)) {
        node_name = NULL;
    }
    if (node_name) { 
    if(!cJSON_IsString(node_name) && !cJSON_IsNull(node_name))
    {
    goto end; //String
    }
    }

    // v1alpha3_pool_status->partition_summary
    cJSON *partition_summary = cJSON_GetObjectItemCaseSensitive(v1alpha3_pool_statusJSON, "partitionSummary");
    if (cJSON_IsNull(partition_summary)) {
        partition_summary = NULL;
    }
    if (partition_summary) { 
    cJSON *partition_summary_local_nonprimitive = NULL;
    if(!cJSON_IsArray(partition_summary)){
        goto end; //nonprimitive container
    }

    partition_summaryList = list_createList();

    cJSON_ArrayForEach(partition_summary_local_nonprimitive,partition_summary )
    {
        if(!cJSON_IsObject(partition_summary_local_nonprimitive)){
            goto end;
        }
        v1alpha3_partition_type_status_t *partition_summaryItem = v1alpha3_partition_type_status_parseFromJSON(partition_summary_local_nonprimitive);

        list_addElement(partition_summaryList, partition_summaryItem);
    }
    }

    // v1alpha3_pool_status->pool_name
    cJSON *pool_name = cJSON_GetObjectItemCaseSensitive(v1alpha3_pool_statusJSON, "poolName");
    if (cJSON_IsNull(pool_name)) {
        pool_name = NULL;
    }
    if (!pool_name) {
        goto end;
    }

    
    if(!cJSON_IsString(pool_name))
    {
    goto end; //String
    }

    // v1alpha3_pool_status->resource_slice_count
    cJSON *resource_slice_count = cJSON_GetObjectItemCaseSensitive(v1alpha3_pool_statusJSON, "resourceSliceCount");
    if (cJSON_IsNull(resource_slice_count)) {
        resource_slice_count = NULL;
    }
    if (resource_slice_count) { 
    if(!cJSON_IsNumber(resource_slice_count))
    {
    goto end; //Numeric
    }
    resource_slice_count_local_var = malloc(sizeof(int));
    if(!resource_slice_count_local_var)
    {
        goto end;
    }
    *resource_slice_count_local_var = resource_slice_count->valuedouble;
    }

    // v1alpha3_pool_status->shareable_summary
    cJSON *shareable_summary = cJSON_GetObjectItemCaseSensitive(v1alpha3_pool_statusJSON, "shareableSummary");
    if (cJSON_IsNull(shareable_summary)) {
        shareable_summary = NULL;
    }
    if (shareable_summary) { 
    shareable_summary_local_nonprim = v1alpha3_shareable_summary_status_parseFromJSON(shareable_summary); //nonprimitive
    }

    // v1alpha3_pool_status->total_devices
    cJSON *total_devices = cJSON_GetObjectItemCaseSensitive(v1alpha3_pool_statusJSON, "totalDevices");
    if (cJSON_IsNull(total_devices)) {
        total_devices = NULL;
    }
    if (total_devices) { 
    if(!cJSON_IsNumber(total_devices))
    {
    goto end; //Numeric
    }
    total_devices_local_var = malloc(sizeof(int));
    if(!total_devices_local_var)
    {
        goto end;
    }
    *total_devices_local_var = total_devices->valuedouble;
    }

    // v1alpha3_pool_status->unavailable_devices
    cJSON *unavailable_devices = cJSON_GetObjectItemCaseSensitive(v1alpha3_pool_statusJSON, "unavailableDevices");
    if (cJSON_IsNull(unavailable_devices)) {
        unavailable_devices = NULL;
    }
    if (unavailable_devices) { 
    if(!cJSON_IsNumber(unavailable_devices))
    {
    goto end; //Numeric
    }
    unavailable_devices_local_var = malloc(sizeof(int));
    if(!unavailable_devices_local_var)
    {
        goto end;
    }
    *unavailable_devices_local_var = unavailable_devices->valuedouble;
    }

    // v1alpha3_pool_status->validation_error
    cJSON *validation_error = cJSON_GetObjectItemCaseSensitive(v1alpha3_pool_statusJSON, "validationError");
    if (cJSON_IsNull(validation_error)) {
        validation_error = NULL;
    }
    if (validation_error) { 
    if(!cJSON_IsString(validation_error) && !cJSON_IsNull(validation_error))
    {
    goto end; //String
    }
    }


    if (driver && !cJSON_IsNull(driver)) driver_local_str = strdup(driver->valuestring);
    if (node_name && !cJSON_IsNull(node_name)) node_name_local_str = strdup(node_name->valuestring);
    if (pool_name && !cJSON_IsNull(pool_name)) pool_name_local_str = strdup(pool_name->valuestring);
    if (validation_error && !cJSON_IsNull(validation_error)) validation_error_local_str = strdup(validation_error->valuestring);

    v1alpha3_pool_status_local_var = v1alpha3_pool_status_create_internal (
        allocated_devices_local_var,
        available_devices_local_var,
        driver_local_str,
        generation_local_var,
        node_name_local_str,
        partition_summary ? partition_summaryList : NULL,
        pool_name_local_str,
        resource_slice_count_local_var,
        shareable_summary ? shareable_summary_local_nonprim : NULL,
        total_devices_local_var,
        unavailable_devices_local_var,
        validation_error_local_str
        );

    if (!v1alpha3_pool_status_local_var) {
        goto end;
    }

    return v1alpha3_pool_status_local_var;
end:
    if (allocated_devices_local_var) {
        free(allocated_devices_local_var);
        allocated_devices_local_var = NULL;
    }
    if (available_devices_local_var) {
        free(available_devices_local_var);
        available_devices_local_var = NULL;
    }
    if (driver_local_str) {
        free(driver_local_str);
        driver_local_str = NULL;
    }
    if (generation_local_var) {
        free(generation_local_var);
        generation_local_var = NULL;
    }
    if (node_name_local_str) {
        free(node_name_local_str);
        node_name_local_str = NULL;
    }
    if (partition_summaryList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, partition_summaryList) {
            v1alpha3_partition_type_status_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(partition_summaryList);
        partition_summaryList = NULL;
    }
    if (pool_name_local_str) {
        free(pool_name_local_str);
        pool_name_local_str = NULL;
    }
    if (resource_slice_count_local_var) {
        free(resource_slice_count_local_var);
        resource_slice_count_local_var = NULL;
    }
    if (shareable_summary_local_nonprim) {
        v1alpha3_shareable_summary_status_free(shareable_summary_local_nonprim);
        shareable_summary_local_nonprim = NULL;
    }
    if (total_devices_local_var) {
        free(total_devices_local_var);
        total_devices_local_var = NULL;
    }
    if (unavailable_devices_local_var) {
        free(unavailable_devices_local_var);
        unavailable_devices_local_var = NULL;
    }
    if (validation_error_local_str) {
        free(validation_error_local_str);
        validation_error_local_str = NULL;
    }
    return NULL;

}
