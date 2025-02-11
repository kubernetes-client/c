#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_attached_volume.h"



static v1_attached_volume_t *v1_attached_volume_create_internal(
    char *device_path,
    char *name
    ) {
    v1_attached_volume_t *v1_attached_volume_local_var = malloc(sizeof(v1_attached_volume_t));
    if (!v1_attached_volume_local_var) {
        return NULL;
    }
    v1_attached_volume_local_var->device_path = device_path;
    v1_attached_volume_local_var->name = name;

    v1_attached_volume_local_var->_library_owned = 1;
    return v1_attached_volume_local_var;
}

__attribute__((deprecated)) v1_attached_volume_t *v1_attached_volume_create(
    char *device_path,
    char *name
    ) {
    return v1_attached_volume_create_internal (
        device_path,
        name
        );
}

void v1_attached_volume_free(v1_attached_volume_t *v1_attached_volume) {
    if(NULL == v1_attached_volume){
        return ;
    }
    if(v1_attached_volume->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_attached_volume_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_attached_volume->device_path) {
        free(v1_attached_volume->device_path);
        v1_attached_volume->device_path = NULL;
    }
    if (v1_attached_volume->name) {
        free(v1_attached_volume->name);
        v1_attached_volume->name = NULL;
    }
    free(v1_attached_volume);
}

cJSON *v1_attached_volume_convertToJSON(v1_attached_volume_t *v1_attached_volume) {
    cJSON *item = cJSON_CreateObject();

    // v1_attached_volume->device_path
    if (!v1_attached_volume->device_path) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "devicePath", v1_attached_volume->device_path) == NULL) {
    goto fail; //String
    }


    // v1_attached_volume->name
    if (!v1_attached_volume->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1_attached_volume->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_attached_volume_t *v1_attached_volume_parseFromJSON(cJSON *v1_attached_volumeJSON){

    v1_attached_volume_t *v1_attached_volume_local_var = NULL;

    // v1_attached_volume->device_path
    cJSON *device_path = cJSON_GetObjectItemCaseSensitive(v1_attached_volumeJSON, "devicePath");
    if (cJSON_IsNull(device_path)) {
        device_path = NULL;
    }
    if (!device_path) {
        goto end;
    }

    
    if(!cJSON_IsString(device_path))
    {
    goto end; //String
    }

    // v1_attached_volume->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_attached_volumeJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }


    v1_attached_volume_local_var = v1_attached_volume_create_internal (
        strdup(device_path->valuestring),
        strdup(name->valuestring)
        );

    return v1_attached_volume_local_var;
end:
    return NULL;

}
