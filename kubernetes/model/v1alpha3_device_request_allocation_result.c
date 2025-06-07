#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_device_request_allocation_result.h"



static v1alpha3_device_request_allocation_result_t *v1alpha3_device_request_allocation_result_create_internal(
    int admin_access,
    char *device,
    char *driver,
    char *pool,
    char *request,
    list_t *tolerations
    ) {
    v1alpha3_device_request_allocation_result_t *v1alpha3_device_request_allocation_result_local_var = malloc(sizeof(v1alpha3_device_request_allocation_result_t));
    if (!v1alpha3_device_request_allocation_result_local_var) {
        return NULL;
    }
    v1alpha3_device_request_allocation_result_local_var->admin_access = admin_access;
    v1alpha3_device_request_allocation_result_local_var->device = device;
    v1alpha3_device_request_allocation_result_local_var->driver = driver;
    v1alpha3_device_request_allocation_result_local_var->pool = pool;
    v1alpha3_device_request_allocation_result_local_var->request = request;
    v1alpha3_device_request_allocation_result_local_var->tolerations = tolerations;

    v1alpha3_device_request_allocation_result_local_var->_library_owned = 1;
    return v1alpha3_device_request_allocation_result_local_var;
}

__attribute__((deprecated)) v1alpha3_device_request_allocation_result_t *v1alpha3_device_request_allocation_result_create(
    int admin_access,
    char *device,
    char *driver,
    char *pool,
    char *request,
    list_t *tolerations
    ) {
    return v1alpha3_device_request_allocation_result_create_internal (
        admin_access,
        device,
        driver,
        pool,
        request,
        tolerations
        );
}

void v1alpha3_device_request_allocation_result_free(v1alpha3_device_request_allocation_result_t *v1alpha3_device_request_allocation_result) {
    if(NULL == v1alpha3_device_request_allocation_result){
        return ;
    }
    if(v1alpha3_device_request_allocation_result->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha3_device_request_allocation_result_free");
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
    if (v1alpha3_device_request_allocation_result->tolerations) {
        list_ForEach(listEntry, v1alpha3_device_request_allocation_result->tolerations) {
            v1alpha3_device_toleration_free(listEntry->data);
        }
        list_freeList(v1alpha3_device_request_allocation_result->tolerations);
        v1alpha3_device_request_allocation_result->tolerations = NULL;
    }
    free(v1alpha3_device_request_allocation_result);
}

cJSON *v1alpha3_device_request_allocation_result_convertToJSON(v1alpha3_device_request_allocation_result_t *v1alpha3_device_request_allocation_result) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_device_request_allocation_result->admin_access
    if(v1alpha3_device_request_allocation_result->admin_access) {
    if(cJSON_AddBoolToObject(item, "adminAccess", v1alpha3_device_request_allocation_result->admin_access) == NULL) {
    goto fail; //Bool
    }
    }


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


    // v1alpha3_device_request_allocation_result->tolerations
    if(v1alpha3_device_request_allocation_result->tolerations) {
    cJSON *tolerations = cJSON_AddArrayToObject(item, "tolerations");
    if(tolerations == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *tolerationsListEntry;
    if (v1alpha3_device_request_allocation_result->tolerations) {
    list_ForEach(tolerationsListEntry, v1alpha3_device_request_allocation_result->tolerations) {
    cJSON *itemLocal = v1alpha3_device_toleration_convertToJSON(tolerationsListEntry->data);
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

v1alpha3_device_request_allocation_result_t *v1alpha3_device_request_allocation_result_parseFromJSON(cJSON *v1alpha3_device_request_allocation_resultJSON){

    v1alpha3_device_request_allocation_result_t *v1alpha3_device_request_allocation_result_local_var = NULL;

    // define the local list for v1alpha3_device_request_allocation_result->tolerations
    list_t *tolerationsList = NULL;

    // v1alpha3_device_request_allocation_result->admin_access
    cJSON *admin_access = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_request_allocation_resultJSON, "adminAccess");
    if (cJSON_IsNull(admin_access)) {
        admin_access = NULL;
    }
    if (admin_access) { 
    if(!cJSON_IsBool(admin_access))
    {
    goto end; //Bool
    }
    }

    // v1alpha3_device_request_allocation_result->device
    cJSON *device = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_request_allocation_resultJSON, "device");
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

    // v1alpha3_device_request_allocation_result->driver
    cJSON *driver = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_request_allocation_resultJSON, "driver");
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

    // v1alpha3_device_request_allocation_result->pool
    cJSON *pool = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_request_allocation_resultJSON, "pool");
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

    // v1alpha3_device_request_allocation_result->request
    cJSON *request = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_request_allocation_resultJSON, "request");
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

    // v1alpha3_device_request_allocation_result->tolerations
    cJSON *tolerations = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_request_allocation_resultJSON, "tolerations");
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
        v1alpha3_device_toleration_t *tolerationsItem = v1alpha3_device_toleration_parseFromJSON(tolerations_local_nonprimitive);

        list_addElement(tolerationsList, tolerationsItem);
    }
    }


    v1alpha3_device_request_allocation_result_local_var = v1alpha3_device_request_allocation_result_create_internal (
        admin_access ? admin_access->valueint : 0,
        strdup(device->valuestring),
        strdup(driver->valuestring),
        strdup(pool->valuestring),
        strdup(request->valuestring),
        tolerations ? tolerationsList : NULL
        );

    return v1alpha3_device_request_allocation_result_local_var;
end:
    if (tolerationsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, tolerationsList) {
            v1alpha3_device_toleration_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(tolerationsList);
        tolerationsList = NULL;
    }
    return NULL;

}
