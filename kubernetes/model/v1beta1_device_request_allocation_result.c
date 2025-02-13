#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_device_request_allocation_result.h"



static v1beta1_device_request_allocation_result_t *v1beta1_device_request_allocation_result_create_internal(
    int admin_access,
    char *device,
    char *driver,
    char *pool,
    char *request
    ) {
    v1beta1_device_request_allocation_result_t *v1beta1_device_request_allocation_result_local_var = malloc(sizeof(v1beta1_device_request_allocation_result_t));
    if (!v1beta1_device_request_allocation_result_local_var) {
        return NULL;
    }
    v1beta1_device_request_allocation_result_local_var->admin_access = admin_access;
    v1beta1_device_request_allocation_result_local_var->device = device;
    v1beta1_device_request_allocation_result_local_var->driver = driver;
    v1beta1_device_request_allocation_result_local_var->pool = pool;
    v1beta1_device_request_allocation_result_local_var->request = request;

    v1beta1_device_request_allocation_result_local_var->_library_owned = 1;
    return v1beta1_device_request_allocation_result_local_var;
}

__attribute__((deprecated)) v1beta1_device_request_allocation_result_t *v1beta1_device_request_allocation_result_create(
    int admin_access,
    char *device,
    char *driver,
    char *pool,
    char *request
    ) {
    return v1beta1_device_request_allocation_result_create_internal (
        admin_access,
        device,
        driver,
        pool,
        request
        );
}

void v1beta1_device_request_allocation_result_free(v1beta1_device_request_allocation_result_t *v1beta1_device_request_allocation_result) {
    if(NULL == v1beta1_device_request_allocation_result){
        return ;
    }
    if(v1beta1_device_request_allocation_result->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta1_device_request_allocation_result_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_device_request_allocation_result->device) {
        free(v1beta1_device_request_allocation_result->device);
        v1beta1_device_request_allocation_result->device = NULL;
    }
    if (v1beta1_device_request_allocation_result->driver) {
        free(v1beta1_device_request_allocation_result->driver);
        v1beta1_device_request_allocation_result->driver = NULL;
    }
    if (v1beta1_device_request_allocation_result->pool) {
        free(v1beta1_device_request_allocation_result->pool);
        v1beta1_device_request_allocation_result->pool = NULL;
    }
    if (v1beta1_device_request_allocation_result->request) {
        free(v1beta1_device_request_allocation_result->request);
        v1beta1_device_request_allocation_result->request = NULL;
    }
    free(v1beta1_device_request_allocation_result);
}

cJSON *v1beta1_device_request_allocation_result_convertToJSON(v1beta1_device_request_allocation_result_t *v1beta1_device_request_allocation_result) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_device_request_allocation_result->admin_access
    if(v1beta1_device_request_allocation_result->admin_access) {
    if(cJSON_AddBoolToObject(item, "adminAccess", v1beta1_device_request_allocation_result->admin_access) == NULL) {
    goto fail; //Bool
    }
    }


    // v1beta1_device_request_allocation_result->device
    if (!v1beta1_device_request_allocation_result->device) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "device", v1beta1_device_request_allocation_result->device) == NULL) {
    goto fail; //String
    }


    // v1beta1_device_request_allocation_result->driver
    if (!v1beta1_device_request_allocation_result->driver) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "driver", v1beta1_device_request_allocation_result->driver) == NULL) {
    goto fail; //String
    }


    // v1beta1_device_request_allocation_result->pool
    if (!v1beta1_device_request_allocation_result->pool) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "pool", v1beta1_device_request_allocation_result->pool) == NULL) {
    goto fail; //String
    }


    // v1beta1_device_request_allocation_result->request
    if (!v1beta1_device_request_allocation_result->request) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "request", v1beta1_device_request_allocation_result->request) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta1_device_request_allocation_result_t *v1beta1_device_request_allocation_result_parseFromJSON(cJSON *v1beta1_device_request_allocation_resultJSON){

    v1beta1_device_request_allocation_result_t *v1beta1_device_request_allocation_result_local_var = NULL;

    // v1beta1_device_request_allocation_result->admin_access
    cJSON *admin_access = cJSON_GetObjectItemCaseSensitive(v1beta1_device_request_allocation_resultJSON, "adminAccess");
    if (cJSON_IsNull(admin_access)) {
        admin_access = NULL;
    }
    if (admin_access) { 
    if(!cJSON_IsBool(admin_access))
    {
    goto end; //Bool
    }
    }

    // v1beta1_device_request_allocation_result->device
    cJSON *device = cJSON_GetObjectItemCaseSensitive(v1beta1_device_request_allocation_resultJSON, "device");
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

    // v1beta1_device_request_allocation_result->driver
    cJSON *driver = cJSON_GetObjectItemCaseSensitive(v1beta1_device_request_allocation_resultJSON, "driver");
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

    // v1beta1_device_request_allocation_result->pool
    cJSON *pool = cJSON_GetObjectItemCaseSensitive(v1beta1_device_request_allocation_resultJSON, "pool");
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

    // v1beta1_device_request_allocation_result->request
    cJSON *request = cJSON_GetObjectItemCaseSensitive(v1beta1_device_request_allocation_resultJSON, "request");
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


    v1beta1_device_request_allocation_result_local_var = v1beta1_device_request_allocation_result_create_internal (
        admin_access ? admin_access->valueint : 0,
        strdup(device->valuestring),
        strdup(driver->valuestring),
        strdup(pool->valuestring),
        strdup(request->valuestring)
        );

    return v1beta1_device_request_allocation_result_local_var;
end:
    return NULL;

}
