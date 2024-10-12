#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_device_request_allocation_result.h"



v1alpha3_device_request_allocation_result_t *v1alpha3_device_request_allocation_result_create(
    char *device,
    char *driver,
    char *pool,
    char *request
    ) {
    v1alpha3_device_request_allocation_result_t *v1alpha3_device_request_allocation_result_local_var = malloc(sizeof(v1alpha3_device_request_allocation_result_t));
    if (!v1alpha3_device_request_allocation_result_local_var) {
        return NULL;
    }
    v1alpha3_device_request_allocation_result_local_var->device = device;
    v1alpha3_device_request_allocation_result_local_var->driver = driver;
    v1alpha3_device_request_allocation_result_local_var->pool = pool;
    v1alpha3_device_request_allocation_result_local_var->request = request;

    return v1alpha3_device_request_allocation_result_local_var;
}


void v1alpha3_device_request_allocation_result_free(v1alpha3_device_request_allocation_result_t *v1alpha3_device_request_allocation_result) {
    if(NULL == v1alpha3_device_request_allocation_result){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_device_request_allocation_result->device) {
        free(v1alpha3_device_request_allocation_result->device);
        v1alpha3_device_request_allocation_result->device = NULL;
    }
    if (v1alpha3_device_request_allocation_result->driver) {
        free(v1alpha3_device_request_allocation_result->driver);
        v1alpha3_device_request_allocation_result->driver = NULL;
    }
    if (v1alpha3_device_request_allocation_result->pool) {
        free(v1alpha3_device_request_allocation_result->pool);
        v1alpha3_device_request_allocation_result->pool = NULL;
    }
    if (v1alpha3_device_request_allocation_result->request) {
        free(v1alpha3_device_request_allocation_result->request);
        v1alpha3_device_request_allocation_result->request = NULL;
    }
    free(v1alpha3_device_request_allocation_result);
}

cJSON *v1alpha3_device_request_allocation_result_convertToJSON(v1alpha3_device_request_allocation_result_t *v1alpha3_device_request_allocation_result) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_device_request_allocation_result->device
    if (!v1alpha3_device_request_allocation_result->device) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "device", v1alpha3_device_request_allocation_result->device) == NULL) {
    goto fail; //String
    }


    // v1alpha3_device_request_allocation_result->driver
    if (!v1alpha3_device_request_allocation_result->driver) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "driver", v1alpha3_device_request_allocation_result->driver) == NULL) {
    goto fail; //String
    }


    // v1alpha3_device_request_allocation_result->pool
    if (!v1alpha3_device_request_allocation_result->pool) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "pool", v1alpha3_device_request_allocation_result->pool) == NULL) {
    goto fail; //String
    }


    // v1alpha3_device_request_allocation_result->request
    if (!v1alpha3_device_request_allocation_result->request) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "request", v1alpha3_device_request_allocation_result->request) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha3_device_request_allocation_result_t *v1alpha3_device_request_allocation_result_parseFromJSON(cJSON *v1alpha3_device_request_allocation_resultJSON){

    v1alpha3_device_request_allocation_result_t *v1alpha3_device_request_allocation_result_local_var = NULL;

    // v1alpha3_device_request_allocation_result->device
    cJSON *device = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_request_allocation_resultJSON, "device");
    if (!device) {
        goto end;
    }

    
    if(!cJSON_IsString(device))
    {
    goto end; //String
    }

    // v1alpha3_device_request_allocation_result->driver
    cJSON *driver = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_request_allocation_resultJSON, "driver");
    if (!driver) {
        goto end;
    }

    
    if(!cJSON_IsString(driver))
    {
    goto end; //String
    }

    // v1alpha3_device_request_allocation_result->pool
    cJSON *pool = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_request_allocation_resultJSON, "pool");
    if (!pool) {
        goto end;
    }

    
    if(!cJSON_IsString(pool))
    {
    goto end; //String
    }

    // v1alpha3_device_request_allocation_result->request
    cJSON *request = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_request_allocation_resultJSON, "request");
    if (!request) {
        goto end;
    }

    
    if(!cJSON_IsString(request))
    {
    goto end; //String
    }


    v1alpha3_device_request_allocation_result_local_var = v1alpha3_device_request_allocation_result_create (
        strdup(device->valuestring),
        strdup(driver->valuestring),
        strdup(pool->valuestring),
        strdup(request->valuestring)
        );

    return v1alpha3_device_request_allocation_result_local_var;
end:
    return NULL;

}
