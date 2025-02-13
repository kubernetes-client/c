#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_resource_claim_status.h"



static v1alpha3_resource_claim_status_t *v1alpha3_resource_claim_status_create_internal(
    v1alpha3_allocation_result_t *allocation,
    list_t *devices,
    list_t *reserved_for
    ) {
    v1alpha3_resource_claim_status_t *v1alpha3_resource_claim_status_local_var = malloc(sizeof(v1alpha3_resource_claim_status_t));
    if (!v1alpha3_resource_claim_status_local_var) {
        return NULL;
    }
    v1alpha3_resource_claim_status_local_var->allocation = allocation;
    v1alpha3_resource_claim_status_local_var->devices = devices;
    v1alpha3_resource_claim_status_local_var->reserved_for = reserved_for;

    v1alpha3_resource_claim_status_local_var->_library_owned = 1;
    return v1alpha3_resource_claim_status_local_var;
}

__attribute__((deprecated)) v1alpha3_resource_claim_status_t *v1alpha3_resource_claim_status_create(
    v1alpha3_allocation_result_t *allocation,
    list_t *devices,
    list_t *reserved_for
    ) {
    return v1alpha3_resource_claim_status_create_internal (
        allocation,
        devices,
        reserved_for
        );
}

void v1alpha3_resource_claim_status_free(v1alpha3_resource_claim_status_t *v1alpha3_resource_claim_status) {
    if(NULL == v1alpha3_resource_claim_status){
        return ;
    }
    if(v1alpha3_resource_claim_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha3_resource_claim_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_resource_claim_status->allocation) {
        v1alpha3_allocation_result_free(v1alpha3_resource_claim_status->allocation);
        v1alpha3_resource_claim_status->allocation = NULL;
    }
    if (v1alpha3_resource_claim_status->devices) {
        list_ForEach(listEntry, v1alpha3_resource_claim_status->devices) {
            v1alpha3_allocated_device_status_free(listEntry->data);
        }
        list_freeList(v1alpha3_resource_claim_status->devices);
        v1alpha3_resource_claim_status->devices = NULL;
    }
    if (v1alpha3_resource_claim_status->reserved_for) {
        list_ForEach(listEntry, v1alpha3_resource_claim_status->reserved_for) {
            v1alpha3_resource_claim_consumer_reference_free(listEntry->data);
        }
        list_freeList(v1alpha3_resource_claim_status->reserved_for);
        v1alpha3_resource_claim_status->reserved_for = NULL;
    }
    free(v1alpha3_resource_claim_status);
}

cJSON *v1alpha3_resource_claim_status_convertToJSON(v1alpha3_resource_claim_status_t *v1alpha3_resource_claim_status) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_resource_claim_status->allocation
    if(v1alpha3_resource_claim_status->allocation) {
    cJSON *allocation_local_JSON = v1alpha3_allocation_result_convertToJSON(v1alpha3_resource_claim_status->allocation);
    if(allocation_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "allocation", allocation_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha3_resource_claim_status->devices
    if(v1alpha3_resource_claim_status->devices) {
    cJSON *devices = cJSON_AddArrayToObject(item, "devices");
    if(devices == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *devicesListEntry;
    if (v1alpha3_resource_claim_status->devices) {
    list_ForEach(devicesListEntry, v1alpha3_resource_claim_status->devices) {
    cJSON *itemLocal = v1alpha3_allocated_device_status_convertToJSON(devicesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(devices, itemLocal);
    }
    }
    }


    // v1alpha3_resource_claim_status->reserved_for
    if(v1alpha3_resource_claim_status->reserved_for) {
    cJSON *reserved_for = cJSON_AddArrayToObject(item, "reservedFor");
    if(reserved_for == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *reserved_forListEntry;
    if (v1alpha3_resource_claim_status->reserved_for) {
    list_ForEach(reserved_forListEntry, v1alpha3_resource_claim_status->reserved_for) {
    cJSON *itemLocal = v1alpha3_resource_claim_consumer_reference_convertToJSON(reserved_forListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(reserved_for, itemLocal);
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

v1alpha3_resource_claim_status_t *v1alpha3_resource_claim_status_parseFromJSON(cJSON *v1alpha3_resource_claim_statusJSON){

    v1alpha3_resource_claim_status_t *v1alpha3_resource_claim_status_local_var = NULL;

    // define the local variable for v1alpha3_resource_claim_status->allocation
    v1alpha3_allocation_result_t *allocation_local_nonprim = NULL;

    // define the local list for v1alpha3_resource_claim_status->devices
    list_t *devicesList = NULL;

    // define the local list for v1alpha3_resource_claim_status->reserved_for
    list_t *reserved_forList = NULL;

    // v1alpha3_resource_claim_status->allocation
    cJSON *allocation = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_claim_statusJSON, "allocation");
    if (cJSON_IsNull(allocation)) {
        allocation = NULL;
    }
    if (allocation) { 
    allocation_local_nonprim = v1alpha3_allocation_result_parseFromJSON(allocation); //nonprimitive
    }

    // v1alpha3_resource_claim_status->devices
    cJSON *devices = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_claim_statusJSON, "devices");
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
        v1alpha3_allocated_device_status_t *devicesItem = v1alpha3_allocated_device_status_parseFromJSON(devices_local_nonprimitive);

        list_addElement(devicesList, devicesItem);
    }
    }

    // v1alpha3_resource_claim_status->reserved_for
    cJSON *reserved_for = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_claim_statusJSON, "reservedFor");
    if (cJSON_IsNull(reserved_for)) {
        reserved_for = NULL;
    }
    if (reserved_for) { 
    cJSON *reserved_for_local_nonprimitive = NULL;
    if(!cJSON_IsArray(reserved_for)){
        goto end; //nonprimitive container
    }

    reserved_forList = list_createList();

    cJSON_ArrayForEach(reserved_for_local_nonprimitive,reserved_for )
    {
        if(!cJSON_IsObject(reserved_for_local_nonprimitive)){
            goto end;
        }
        v1alpha3_resource_claim_consumer_reference_t *reserved_forItem = v1alpha3_resource_claim_consumer_reference_parseFromJSON(reserved_for_local_nonprimitive);

        list_addElement(reserved_forList, reserved_forItem);
    }
    }


    v1alpha3_resource_claim_status_local_var = v1alpha3_resource_claim_status_create_internal (
        allocation ? allocation_local_nonprim : NULL,
        devices ? devicesList : NULL,
        reserved_for ? reserved_forList : NULL
        );

    return v1alpha3_resource_claim_status_local_var;
end:
    if (allocation_local_nonprim) {
        v1alpha3_allocation_result_free(allocation_local_nonprim);
        allocation_local_nonprim = NULL;
    }
    if (devicesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, devicesList) {
            v1alpha3_allocated_device_status_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(devicesList);
        devicesList = NULL;
    }
    if (reserved_forList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, reserved_forList) {
            v1alpha3_resource_claim_consumer_reference_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(reserved_forList);
        reserved_forList = NULL;
    }
    return NULL;

}
