#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_volume_mount_status.h"



v1_volume_mount_status_t *v1_volume_mount_status_create(
    char *mount_path,
    char *name,
    int read_only,
    char *recursive_read_only
    ) {
    v1_volume_mount_status_t *v1_volume_mount_status_local_var = malloc(sizeof(v1_volume_mount_status_t));
    if (!v1_volume_mount_status_local_var) {
        return NULL;
    }
    v1_volume_mount_status_local_var->mount_path = mount_path;
    v1_volume_mount_status_local_var->name = name;
    v1_volume_mount_status_local_var->read_only = read_only;
    v1_volume_mount_status_local_var->recursive_read_only = recursive_read_only;

    return v1_volume_mount_status_local_var;
}


void v1_volume_mount_status_free(v1_volume_mount_status_t *v1_volume_mount_status) {
    if(NULL == v1_volume_mount_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_volume_mount_status->mount_path) {
        free(v1_volume_mount_status->mount_path);
        v1_volume_mount_status->mount_path = NULL;
    }
    if (v1_volume_mount_status->name) {
        free(v1_volume_mount_status->name);
        v1_volume_mount_status->name = NULL;
    }
    if (v1_volume_mount_status->recursive_read_only) {
        free(v1_volume_mount_status->recursive_read_only);
        v1_volume_mount_status->recursive_read_only = NULL;
    }
    free(v1_volume_mount_status);
}

cJSON *v1_volume_mount_status_convertToJSON(v1_volume_mount_status_t *v1_volume_mount_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_volume_mount_status->mount_path
    if (!v1_volume_mount_status->mount_path) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "mountPath", v1_volume_mount_status->mount_path) == NULL) {
    goto fail; //String
    }


    // v1_volume_mount_status->name
    if (!v1_volume_mount_status->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1_volume_mount_status->name) == NULL) {
    goto fail; //String
    }


    // v1_volume_mount_status->read_only
    if(v1_volume_mount_status->read_only) {
    if(cJSON_AddBoolToObject(item, "readOnly", v1_volume_mount_status->read_only) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_volume_mount_status->recursive_read_only
    if(v1_volume_mount_status->recursive_read_only) {
    if(cJSON_AddStringToObject(item, "recursiveReadOnly", v1_volume_mount_status->recursive_read_only) == NULL) {
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

v1_volume_mount_status_t *v1_volume_mount_status_parseFromJSON(cJSON *v1_volume_mount_statusJSON){

    v1_volume_mount_status_t *v1_volume_mount_status_local_var = NULL;

    // v1_volume_mount_status->mount_path
    cJSON *mount_path = cJSON_GetObjectItemCaseSensitive(v1_volume_mount_statusJSON, "mountPath");
    if (!mount_path) {
        goto end;
    }

    
    if(!cJSON_IsString(mount_path))
    {
    goto end; //String
    }

    // v1_volume_mount_status->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_volume_mount_statusJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_volume_mount_status->read_only
    cJSON *read_only = cJSON_GetObjectItemCaseSensitive(v1_volume_mount_statusJSON, "readOnly");
    if (read_only) { 
    if(!cJSON_IsBool(read_only))
    {
    goto end; //Bool
    }
    }

    // v1_volume_mount_status->recursive_read_only
    cJSON *recursive_read_only = cJSON_GetObjectItemCaseSensitive(v1_volume_mount_statusJSON, "recursiveReadOnly");
    if (recursive_read_only) { 
    if(!cJSON_IsString(recursive_read_only) && !cJSON_IsNull(recursive_read_only))
    {
    goto end; //String
    }
    }


    v1_volume_mount_status_local_var = v1_volume_mount_status_create (
        strdup(mount_path->valuestring),
        strdup(name->valuestring),
        read_only ? read_only->valueint : 0,
        recursive_read_only && !cJSON_IsNull(recursive_read_only) ? strdup(recursive_read_only->valuestring) : NULL
        );

    return v1_volume_mount_status_local_var;
end:
    return NULL;

}
