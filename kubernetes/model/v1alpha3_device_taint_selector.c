#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_device_taint_selector.h"



static v1alpha3_device_taint_selector_t *v1alpha3_device_taint_selector_create_internal(
    char *device,
    char *driver,
    char *pool
    ) {
    v1alpha3_device_taint_selector_t *v1alpha3_device_taint_selector_local_var = malloc(sizeof(v1alpha3_device_taint_selector_t));
    if (!v1alpha3_device_taint_selector_local_var) {
        return NULL;
    }
    memset(v1alpha3_device_taint_selector_local_var, 0, sizeof(v1alpha3_device_taint_selector_t));
    v1alpha3_device_taint_selector_local_var->_library_owned = 1;
    v1alpha3_device_taint_selector_local_var->device = device;
    v1alpha3_device_taint_selector_local_var->driver = driver;
    v1alpha3_device_taint_selector_local_var->pool = pool;
    return v1alpha3_device_taint_selector_local_var;
}

__attribute__((deprecated)) v1alpha3_device_taint_selector_t *v1alpha3_device_taint_selector_create(
    char *device,
    char *driver,
    char *pool
    ) {
    v1alpha3_device_taint_selector_t *result = v1alpha3_device_taint_selector_create_internal (
        device,
        driver,
        pool
        );
    if (!result) {
    }
    return result;
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
    if (v1alpha3_device_taint_selector->driver) {
        free(v1alpha3_device_taint_selector->driver);
        v1alpha3_device_taint_selector->driver = NULL;
    }
    if (v1alpha3_device_taint_selector->pool) {
        free(v1alpha3_device_taint_selector->pool);
        v1alpha3_device_taint_selector->pool = NULL;
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

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha3_device_taint_selector_t *v1alpha3_device_taint_selector_parseFromJSON(cJSON *v1alpha3_device_taint_selectorJSON){

    v1alpha3_device_taint_selector_t *v1alpha3_device_taint_selector_local_var = NULL;

    char *device_local_str = NULL;

    char *driver_local_str = NULL;

    char *pool_local_str = NULL;

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


    if (device && !cJSON_IsNull(device)) device_local_str = strdup(device->valuestring);
    if (driver && !cJSON_IsNull(driver)) driver_local_str = strdup(driver->valuestring);
    if (pool && !cJSON_IsNull(pool)) pool_local_str = strdup(pool->valuestring);

    v1alpha3_device_taint_selector_local_var = v1alpha3_device_taint_selector_create_internal (
        device_local_str,
        driver_local_str,
        pool_local_str
        );

    if (!v1alpha3_device_taint_selector_local_var) {
        goto end;
    }

    return v1alpha3_device_taint_selector_local_var;
end:
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
    return NULL;

}
