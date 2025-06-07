#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_device_taint_selector.h"



static v1alpha3_device_taint_selector_t *v1alpha3_device_taint_selector_create_internal(
    char *device,
    char *device_class_name,
    char *driver,
    char *pool,
    list_t *selectors
    ) {
    v1alpha3_device_taint_selector_t *v1alpha3_device_taint_selector_local_var = malloc(sizeof(v1alpha3_device_taint_selector_t));
    if (!v1alpha3_device_taint_selector_local_var) {
        return NULL;
    }
    v1alpha3_device_taint_selector_local_var->device = device;
    v1alpha3_device_taint_selector_local_var->device_class_name = device_class_name;
    v1alpha3_device_taint_selector_local_var->driver = driver;
    v1alpha3_device_taint_selector_local_var->pool = pool;
    v1alpha3_device_taint_selector_local_var->selectors = selectors;

    v1alpha3_device_taint_selector_local_var->_library_owned = 1;
    return v1alpha3_device_taint_selector_local_var;
}

__attribute__((deprecated)) v1alpha3_device_taint_selector_t *v1alpha3_device_taint_selector_create(
    char *device,
    char *device_class_name,
    char *driver,
    char *pool,
    list_t *selectors
    ) {
    return v1alpha3_device_taint_selector_create_internal (
        device,
        device_class_name,
        driver,
        pool,
        selectors
        );
}

void v1alpha3_device_taint_selector_free(v1alpha3_device_taint_selector_t *v1alpha3_device_taint_selector) {
    if(NULL == v1alpha3_device_taint_selector){
        return ;
    }
    if(v1alpha3_device_taint_selector->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha3_device_taint_selector_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_device_taint_selector->device) {
        free(v1alpha3_device_taint_selector->device);
        v1alpha3_device_taint_selector->device = NULL;
    }
    if (v1alpha3_device_taint_selector->device_class_name) {
        free(v1alpha3_device_taint_selector->device_class_name);
        v1alpha3_device_taint_selector->device_class_name = NULL;
    }
    if (v1alpha3_device_taint_selector->driver) {
        free(v1alpha3_device_taint_selector->driver);
        v1alpha3_device_taint_selector->driver = NULL;
    }
    if (v1alpha3_device_taint_selector->pool) {
        free(v1alpha3_device_taint_selector->pool);
        v1alpha3_device_taint_selector->pool = NULL;
    }
    if (v1alpha3_device_taint_selector->selectors) {
        list_ForEach(listEntry, v1alpha3_device_taint_selector->selectors) {
            v1alpha3_device_selector_free(listEntry->data);
        }
        list_freeList(v1alpha3_device_taint_selector->selectors);
        v1alpha3_device_taint_selector->selectors = NULL;
    }
    free(v1alpha3_device_taint_selector);
}

cJSON *v1alpha3_device_taint_selector_convertToJSON(v1alpha3_device_taint_selector_t *v1alpha3_device_taint_selector) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_device_taint_selector->device
    if(v1alpha3_device_taint_selector->device) {
    if(cJSON_AddStringToObject(item, "device", v1alpha3_device_taint_selector->device) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha3_device_taint_selector->device_class_name
    if(v1alpha3_device_taint_selector->device_class_name) {
    if(cJSON_AddStringToObject(item, "deviceClassName", v1alpha3_device_taint_selector->device_class_name) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha3_device_taint_selector->driver
    if(v1alpha3_device_taint_selector->driver) {
    if(cJSON_AddStringToObject(item, "driver", v1alpha3_device_taint_selector->driver) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha3_device_taint_selector->pool
    if(v1alpha3_device_taint_selector->pool) {
    if(cJSON_AddStringToObject(item, "pool", v1alpha3_device_taint_selector->pool) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha3_device_taint_selector->selectors
    if(v1alpha3_device_taint_selector->selectors) {
    cJSON *selectors = cJSON_AddArrayToObject(item, "selectors");
    if(selectors == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *selectorsListEntry;
    if (v1alpha3_device_taint_selector->selectors) {
    list_ForEach(selectorsListEntry, v1alpha3_device_taint_selector->selectors) {
    cJSON *itemLocal = v1alpha3_device_selector_convertToJSON(selectorsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(selectors, itemLocal);
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

v1alpha3_device_taint_selector_t *v1alpha3_device_taint_selector_parseFromJSON(cJSON *v1alpha3_device_taint_selectorJSON){

    v1alpha3_device_taint_selector_t *v1alpha3_device_taint_selector_local_var = NULL;

    // define the local list for v1alpha3_device_taint_selector->selectors
    list_t *selectorsList = NULL;

    // v1alpha3_device_taint_selector->device
    cJSON *device = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_taint_selectorJSON, "device");
    if (cJSON_IsNull(device)) {
        device = NULL;
    }
    if (device) { 
    if(!cJSON_IsString(device) && !cJSON_IsNull(device))
    {
    goto end; //String
    }
    }

    // v1alpha3_device_taint_selector->device_class_name
    cJSON *device_class_name = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_taint_selectorJSON, "deviceClassName");
    if (cJSON_IsNull(device_class_name)) {
        device_class_name = NULL;
    }
    if (device_class_name) { 
    if(!cJSON_IsString(device_class_name) && !cJSON_IsNull(device_class_name))
    {
    goto end; //String
    }
    }

    // v1alpha3_device_taint_selector->driver
    cJSON *driver = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_taint_selectorJSON, "driver");
    if (cJSON_IsNull(driver)) {
        driver = NULL;
    }
    if (driver) { 
    if(!cJSON_IsString(driver) && !cJSON_IsNull(driver))
    {
    goto end; //String
    }
    }

    // v1alpha3_device_taint_selector->pool
    cJSON *pool = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_taint_selectorJSON, "pool");
    if (cJSON_IsNull(pool)) {
        pool = NULL;
    }
    if (pool) { 
    if(!cJSON_IsString(pool) && !cJSON_IsNull(pool))
    {
    goto end; //String
    }
    }

    // v1alpha3_device_taint_selector->selectors
    cJSON *selectors = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_taint_selectorJSON, "selectors");
    if (cJSON_IsNull(selectors)) {
        selectors = NULL;
    }
    if (selectors) { 
    cJSON *selectors_local_nonprimitive = NULL;
    if(!cJSON_IsArray(selectors)){
        goto end; //nonprimitive container
    }

    selectorsList = list_createList();

    cJSON_ArrayForEach(selectors_local_nonprimitive,selectors )
    {
        if(!cJSON_IsObject(selectors_local_nonprimitive)){
            goto end;
        }
        v1alpha3_device_selector_t *selectorsItem = v1alpha3_device_selector_parseFromJSON(selectors_local_nonprimitive);

        list_addElement(selectorsList, selectorsItem);
    }
    }


    v1alpha3_device_taint_selector_local_var = v1alpha3_device_taint_selector_create_internal (
        device && !cJSON_IsNull(device) ? strdup(device->valuestring) : NULL,
        device_class_name && !cJSON_IsNull(device_class_name) ? strdup(device_class_name->valuestring) : NULL,
        driver && !cJSON_IsNull(driver) ? strdup(driver->valuestring) : NULL,
        pool && !cJSON_IsNull(pool) ? strdup(pool->valuestring) : NULL,
        selectors ? selectorsList : NULL
        );

    return v1alpha3_device_taint_selector_local_var;
end:
    if (selectorsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, selectorsList) {
            v1alpha3_device_selector_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(selectorsList);
        selectorsList = NULL;
    }
    return NULL;

}
