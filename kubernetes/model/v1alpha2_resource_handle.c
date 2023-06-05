#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha2_resource_handle.h"



v1alpha2_resource_handle_t *v1alpha2_resource_handle_create(
    char *data,
    char *driver_name
    ) {
    v1alpha2_resource_handle_t *v1alpha2_resource_handle_local_var = malloc(sizeof(v1alpha2_resource_handle_t));
    if (!v1alpha2_resource_handle_local_var) {
        return NULL;
    }
    v1alpha2_resource_handle_local_var->data = data;
    v1alpha2_resource_handle_local_var->driver_name = driver_name;

    return v1alpha2_resource_handle_local_var;
}


void v1alpha2_resource_handle_free(v1alpha2_resource_handle_t *v1alpha2_resource_handle) {
    if(NULL == v1alpha2_resource_handle){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha2_resource_handle->data) {
        free(v1alpha2_resource_handle->data);
        v1alpha2_resource_handle->data = NULL;
    }
    if (v1alpha2_resource_handle->driver_name) {
        free(v1alpha2_resource_handle->driver_name);
        v1alpha2_resource_handle->driver_name = NULL;
    }
    free(v1alpha2_resource_handle);
}

cJSON *v1alpha2_resource_handle_convertToJSON(v1alpha2_resource_handle_t *v1alpha2_resource_handle) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha2_resource_handle->data
    if(v1alpha2_resource_handle->data) {
    if(cJSON_AddStringToObject(item, "data", v1alpha2_resource_handle->data) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha2_resource_handle->driver_name
    if(v1alpha2_resource_handle->driver_name) {
    if(cJSON_AddStringToObject(item, "driverName", v1alpha2_resource_handle->driver_name) == NULL) {
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

v1alpha2_resource_handle_t *v1alpha2_resource_handle_parseFromJSON(cJSON *v1alpha2_resource_handleJSON){

    v1alpha2_resource_handle_t *v1alpha2_resource_handle_local_var = NULL;

    // v1alpha2_resource_handle->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(v1alpha2_resource_handleJSON, "data");
    if (data) { 
    if(!cJSON_IsString(data) && !cJSON_IsNull(data))
    {
    goto end; //String
    }
    }

    // v1alpha2_resource_handle->driver_name
    cJSON *driver_name = cJSON_GetObjectItemCaseSensitive(v1alpha2_resource_handleJSON, "driverName");
    if (driver_name) { 
    if(!cJSON_IsString(driver_name) && !cJSON_IsNull(driver_name))
    {
    goto end; //String
    }
    }


    v1alpha2_resource_handle_local_var = v1alpha2_resource_handle_create (
        data && !cJSON_IsNull(data) ? strdup(data->valuestring) : NULL,
        driver_name && !cJSON_IsNull(driver_name) ? strdup(driver_name->valuestring) : NULL
        );

    return v1alpha2_resource_handle_local_var;
end:
    return NULL;

}
