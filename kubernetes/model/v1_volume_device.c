#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_volume_device.h"



v1_volume_device_t *v1_volume_device_create(
    char *device_path,
    char *name
    ) {
    v1_volume_device_t *v1_volume_device_local_var = malloc(sizeof(v1_volume_device_t));
    if (!v1_volume_device_local_var) {
        return NULL;
    }
    v1_volume_device_local_var->device_path = device_path;
    v1_volume_device_local_var->name = name;

    return v1_volume_device_local_var;
}


void v1_volume_device_free(v1_volume_device_t *v1_volume_device) {
    if(NULL == v1_volume_device){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_volume_device->device_path) {
        free(v1_volume_device->device_path);
        v1_volume_device->device_path = NULL;
    }
    if (v1_volume_device->name) {
        free(v1_volume_device->name);
        v1_volume_device->name = NULL;
    }
    free(v1_volume_device);
}

cJSON *v1_volume_device_convertToJSON(v1_volume_device_t *v1_volume_device) {
    cJSON *item = cJSON_CreateObject();

    // v1_volume_device->device_path
    if (!v1_volume_device->device_path) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "devicePath", v1_volume_device->device_path) == NULL) {
    goto fail; //String
    }


    // v1_volume_device->name
    if (!v1_volume_device->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v1_volume_device->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_volume_device_t *v1_volume_device_parseFromJSON(cJSON *v1_volume_deviceJSON){

    v1_volume_device_t *v1_volume_device_local_var = NULL;

    // v1_volume_device->device_path
    cJSON *device_path = cJSON_GetObjectItemCaseSensitive(v1_volume_deviceJSON, "devicePath");
    if (!device_path) {
        goto end;
    }

    
    if(!cJSON_IsString(device_path))
    {
    goto end; //String
    }

    // v1_volume_device->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_volume_deviceJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }


    v1_volume_device_local_var = v1_volume_device_create (
        strdup(device_path->valuestring),
        strdup(name->valuestring)
        );

    return v1_volume_device_local_var;
end:
    return NULL;

}
