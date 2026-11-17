#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_volume_mount_status.h"



static v1_volume_mount_status_t *v1_volume_mount_status_create_internal(
    char *mount_path,
    char *name,
    int *read_only,
    char *recursive_read_only,
    v1_volume_status_t *volume_status
    ) {
    v1_volume_mount_status_t *v1_volume_mount_status_local_var = malloc(sizeof(v1_volume_mount_status_t));
    if (!v1_volume_mount_status_local_var) {
        return NULL;
    }
    memset(v1_volume_mount_status_local_var, 0, sizeof(v1_volume_mount_status_t));
    v1_volume_mount_status_local_var->_library_owned = 1;
    v1_volume_mount_status_local_var->mount_path = mount_path;
    v1_volume_mount_status_local_var->name = name;
    v1_volume_mount_status_local_var->read_only = read_only;
    v1_volume_mount_status_local_var->recursive_read_only = recursive_read_only;
    v1_volume_mount_status_local_var->volume_status = volume_status;
    return v1_volume_mount_status_local_var;
}

__attribute__((deprecated)) v1_volume_mount_status_t *v1_volume_mount_status_create(
    char *mount_path,
    char *name,
    int *read_only,
    char *recursive_read_only,
    v1_volume_status_t *volume_status
    ) {
    int *read_only_copy = NULL;
    if (read_only) {
        read_only_copy = malloc(sizeof(int));
        if (read_only_copy) *read_only_copy = *read_only;
    }
    v1_volume_mount_status_t *result = v1_volume_mount_status_create_internal (
        mount_path,
        name,
        read_only_copy,
        recursive_read_only,
        volume_status
        );
    if (!result) {
        free(read_only_copy);
    }
    return result;
}

void v1_volume_mount_status_free(v1_volume_mount_status_t *v1_volume_mount_status) {
    if(NULL == v1_volume_mount_status){
        return ;
    }
    if(v1_volume_mount_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_volume_mount_status_free");
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
    if (v1_volume_mount_status->read_only) {
        free(v1_volume_mount_status->read_only);
        v1_volume_mount_status->read_only = NULL;
    }
    if (v1_volume_mount_status->recursive_read_only) {
        free(v1_volume_mount_status->recursive_read_only);
        v1_volume_mount_status->recursive_read_only = NULL;
    }
    if (v1_volume_mount_status->volume_status) {
        v1_volume_status_free(v1_volume_mount_status->volume_status);
        v1_volume_mount_status->volume_status = NULL;
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
    if(cJSON_AddBoolToObject(item, "readOnly", *v1_volume_mount_status->read_only) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_volume_mount_status->recursive_read_only
    if(v1_volume_mount_status->recursive_read_only) {
    if(cJSON_AddStringToObject(item, "recursiveReadOnly", v1_volume_mount_status->recursive_read_only) == NULL) {
    goto fail; //String
    }
    }


    // v1_volume_mount_status->volume_status
    if(v1_volume_mount_status->volume_status) {
    cJSON *volume_status_local_JSON = v1_volume_status_convertToJSON(v1_volume_mount_status->volume_status);
    if(volume_status_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "volumeStatus", volume_status_local_JSON);
    if(item->child == NULL) {
    goto fail;
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

    char *mount_path_local_str = NULL;

    char *name_local_str = NULL;

    // define the local variable for v1_volume_mount_status->read_only
    int *read_only_local_var = NULL;

    char *recursive_read_only_local_str = NULL;

    // define the local variable for v1_volume_mount_status->volume_status
    v1_volume_status_t *volume_status_local_nonprim = NULL;

    // v1_volume_mount_status->mount_path
    cJSON *mount_path = cJSON_GetObjectItemCaseSensitive(v1_volume_mount_statusJSON, "mountPath");
    if (cJSON_IsNull(mount_path)) {
        mount_path = NULL;
    }
    if (!mount_path) {
        goto end;
    }

    
    if(!cJSON_IsString(mount_path))
    {
    goto end; //String
    }

    // v1_volume_mount_status->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_volume_mount_statusJSON, "name");
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

    // v1_volume_mount_status->read_only
    cJSON *read_only = cJSON_GetObjectItemCaseSensitive(v1_volume_mount_statusJSON, "readOnly");
    if (cJSON_IsNull(read_only)) {
        read_only = NULL;
    }
    if (read_only) { 
    if(!cJSON_IsBool(read_only))
    {
    goto end; //Bool
    }
    read_only_local_var = malloc(sizeof(int));
    if(!read_only_local_var)
    {
        goto end;
    }
    *read_only_local_var = read_only->valueint;
    }

    // v1_volume_mount_status->recursive_read_only
    cJSON *recursive_read_only = cJSON_GetObjectItemCaseSensitive(v1_volume_mount_statusJSON, "recursiveReadOnly");
    if (cJSON_IsNull(recursive_read_only)) {
        recursive_read_only = NULL;
    }
    if (recursive_read_only) { 
    if(!cJSON_IsString(recursive_read_only) && !cJSON_IsNull(recursive_read_only))
    {
    goto end; //String
    }
    }

    // v1_volume_mount_status->volume_status
    cJSON *volume_status = cJSON_GetObjectItemCaseSensitive(v1_volume_mount_statusJSON, "volumeStatus");
    if (cJSON_IsNull(volume_status)) {
        volume_status = NULL;
    }
    if (volume_status) { 
    volume_status_local_nonprim = v1_volume_status_parseFromJSON(volume_status); //nonprimitive
    }


    if (mount_path && !cJSON_IsNull(mount_path)) mount_path_local_str = strdup(mount_path->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (recursive_read_only && !cJSON_IsNull(recursive_read_only)) recursive_read_only_local_str = strdup(recursive_read_only->valuestring);

    v1_volume_mount_status_local_var = v1_volume_mount_status_create_internal (
        mount_path_local_str,
        name_local_str,
        read_only_local_var,
        recursive_read_only_local_str,
        volume_status ? volume_status_local_nonprim : NULL
        );

    if (!v1_volume_mount_status_local_var) {
        goto end;
    }

    return v1_volume_mount_status_local_var;
end:
    if (mount_path_local_str) {
        free(mount_path_local_str);
        mount_path_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (read_only_local_var) {
        free(read_only_local_var);
        read_only_local_var = NULL;
    }
    if (recursive_read_only_local_str) {
        free(recursive_read_only_local_str);
        recursive_read_only_local_str = NULL;
    }
    if (volume_status_local_nonprim) {
        v1_volume_status_free(volume_status_local_nonprim);
        volume_status_local_nonprim = NULL;
    }
    return NULL;

}
