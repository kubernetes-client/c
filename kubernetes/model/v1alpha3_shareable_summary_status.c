#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_shareable_summary_status.h"



static v1alpha3_shareable_summary_status_t *v1alpha3_shareable_summary_status_create_internal(
    list_t *capacity,
    int *fully_available_devices,
    int *partially_available_devices
    ) {
    v1alpha3_shareable_summary_status_t *v1alpha3_shareable_summary_status_local_var = malloc(sizeof(v1alpha3_shareable_summary_status_t));
    if (!v1alpha3_shareable_summary_status_local_var) {
        return NULL;
    }
    memset(v1alpha3_shareable_summary_status_local_var, 0, sizeof(v1alpha3_shareable_summary_status_t));
    v1alpha3_shareable_summary_status_local_var->_library_owned = 1;
    v1alpha3_shareable_summary_status_local_var->capacity = capacity;
    v1alpha3_shareable_summary_status_local_var->fully_available_devices = fully_available_devices;
    v1alpha3_shareable_summary_status_local_var->partially_available_devices = partially_available_devices;
    return v1alpha3_shareable_summary_status_local_var;
}

__attribute__((deprecated)) v1alpha3_shareable_summary_status_t *v1alpha3_shareable_summary_status_create(
    list_t *capacity,
    int *fully_available_devices,
    int *partially_available_devices
    ) {
    int *fully_available_devices_copy = NULL;
    if (fully_available_devices) {
        fully_available_devices_copy = malloc(sizeof(int));
        if (fully_available_devices_copy) *fully_available_devices_copy = *fully_available_devices;
    }
    int *partially_available_devices_copy = NULL;
    if (partially_available_devices) {
        partially_available_devices_copy = malloc(sizeof(int));
        if (partially_available_devices_copy) *partially_available_devices_copy = *partially_available_devices;
    }
    v1alpha3_shareable_summary_status_t *result = v1alpha3_shareable_summary_status_create_internal (
        capacity,
        fully_available_devices_copy,
        partially_available_devices_copy
        );
    if (!result) {
        free(fully_available_devices_copy);
        free(partially_available_devices_copy);
    }
    return result;
}

void v1alpha3_shareable_summary_status_free(v1alpha3_shareable_summary_status_t *v1alpha3_shareable_summary_status) {
    if(NULL == v1alpha3_shareable_summary_status){
        return ;
    }
    if(v1alpha3_shareable_summary_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha3_shareable_summary_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_shareable_summary_status->capacity) {
        list_ForEach(listEntry, v1alpha3_shareable_summary_status->capacity) {
            v1alpha3_shareable_capacity_status_free(listEntry->data);
        }
        list_freeList(v1alpha3_shareable_summary_status->capacity);
        v1alpha3_shareable_summary_status->capacity = NULL;
    }
    if (v1alpha3_shareable_summary_status->fully_available_devices) {
        free(v1alpha3_shareable_summary_status->fully_available_devices);
        v1alpha3_shareable_summary_status->fully_available_devices = NULL;
    }
    if (v1alpha3_shareable_summary_status->partially_available_devices) {
        free(v1alpha3_shareable_summary_status->partially_available_devices);
        v1alpha3_shareable_summary_status->partially_available_devices = NULL;
    }
    free(v1alpha3_shareable_summary_status);
}

cJSON *v1alpha3_shareable_summary_status_convertToJSON(v1alpha3_shareable_summary_status_t *v1alpha3_shareable_summary_status) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_shareable_summary_status->capacity
    if(v1alpha3_shareable_summary_status->capacity) {
    cJSON *capacity = cJSON_AddArrayToObject(item, "capacity");
    if(capacity == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *capacityListEntry;
    if (v1alpha3_shareable_summary_status->capacity) {
    list_ForEach(capacityListEntry, v1alpha3_shareable_summary_status->capacity) {
    cJSON *itemLocal = v1alpha3_shareable_capacity_status_convertToJSON(capacityListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(capacity, itemLocal);
    }
    }
    }


    // v1alpha3_shareable_summary_status->fully_available_devices
    if (!v1alpha3_shareable_summary_status->fully_available_devices) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "fullyAvailableDevices", *v1alpha3_shareable_summary_status->fully_available_devices) == NULL) {
    goto fail; //Numeric
    }


    // v1alpha3_shareable_summary_status->partially_available_devices
    if (!v1alpha3_shareable_summary_status->partially_available_devices) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "partiallyAvailableDevices", *v1alpha3_shareable_summary_status->partially_available_devices) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha3_shareable_summary_status_t *v1alpha3_shareable_summary_status_parseFromJSON(cJSON *v1alpha3_shareable_summary_statusJSON){

    v1alpha3_shareable_summary_status_t *v1alpha3_shareable_summary_status_local_var = NULL;

    // define the local list for v1alpha3_shareable_summary_status->capacity
    list_t *capacityList = NULL;

    // define the local variable for v1alpha3_shareable_summary_status->fully_available_devices
    int *fully_available_devices_local_var = NULL;

    // define the local variable for v1alpha3_shareable_summary_status->partially_available_devices
    int *partially_available_devices_local_var = NULL;

    // v1alpha3_shareable_summary_status->capacity
    cJSON *capacity = cJSON_GetObjectItemCaseSensitive(v1alpha3_shareable_summary_statusJSON, "capacity");
    if (cJSON_IsNull(capacity)) {
        capacity = NULL;
    }
    if (capacity) { 
    cJSON *capacity_local_nonprimitive = NULL;
    if(!cJSON_IsArray(capacity)){
        goto end; //nonprimitive container
    }

    capacityList = list_createList();

    cJSON_ArrayForEach(capacity_local_nonprimitive,capacity )
    {
        if(!cJSON_IsObject(capacity_local_nonprimitive)){
            goto end;
        }
        v1alpha3_shareable_capacity_status_t *capacityItem = v1alpha3_shareable_capacity_status_parseFromJSON(capacity_local_nonprimitive);

        list_addElement(capacityList, capacityItem);
    }
    }

    // v1alpha3_shareable_summary_status->fully_available_devices
    cJSON *fully_available_devices = cJSON_GetObjectItemCaseSensitive(v1alpha3_shareable_summary_statusJSON, "fullyAvailableDevices");
    if (cJSON_IsNull(fully_available_devices)) {
        fully_available_devices = NULL;
    }
    if (!fully_available_devices) {
        goto end;
    }

    
    if(!cJSON_IsNumber(fully_available_devices))
    {
    goto end; //Numeric
    }
    fully_available_devices_local_var = malloc(sizeof(int));
    if(!fully_available_devices_local_var)
    {
        goto end;
    }
    *fully_available_devices_local_var = fully_available_devices->valuedouble;

    // v1alpha3_shareable_summary_status->partially_available_devices
    cJSON *partially_available_devices = cJSON_GetObjectItemCaseSensitive(v1alpha3_shareable_summary_statusJSON, "partiallyAvailableDevices");
    if (cJSON_IsNull(partially_available_devices)) {
        partially_available_devices = NULL;
    }
    if (!partially_available_devices) {
        goto end;
    }

    
    if(!cJSON_IsNumber(partially_available_devices))
    {
    goto end; //Numeric
    }
    partially_available_devices_local_var = malloc(sizeof(int));
    if(!partially_available_devices_local_var)
    {
        goto end;
    }
    *partially_available_devices_local_var = partially_available_devices->valuedouble;



    v1alpha3_shareable_summary_status_local_var = v1alpha3_shareable_summary_status_create_internal (
        capacity ? capacityList : NULL,
        fully_available_devices_local_var,
        partially_available_devices_local_var
        );

    if (!v1alpha3_shareable_summary_status_local_var) {
        goto end;
    }

    return v1alpha3_shareable_summary_status_local_var;
end:
    if (capacityList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, capacityList) {
            v1alpha3_shareable_capacity_status_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(capacityList);
        capacityList = NULL;
    }
    if (fully_available_devices_local_var) {
        free(fully_available_devices_local_var);
        fully_available_devices_local_var = NULL;
    }
    if (partially_available_devices_local_var) {
        free(partially_available_devices_local_var);
        partially_available_devices_local_var = NULL;
    }
    return NULL;

}
