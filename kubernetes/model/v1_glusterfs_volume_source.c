#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_glusterfs_volume_source.h"



static v1_glusterfs_volume_source_t *v1_glusterfs_volume_source_create_internal(
    char *endpoints,
    char *path,
    int read_only
    ) {
    v1_glusterfs_volume_source_t *v1_glusterfs_volume_source_local_var = malloc(sizeof(v1_glusterfs_volume_source_t));
    if (!v1_glusterfs_volume_source_local_var) {
        return NULL;
    }
    v1_glusterfs_volume_source_local_var->endpoints = endpoints;
    v1_glusterfs_volume_source_local_var->path = path;
    v1_glusterfs_volume_source_local_var->read_only = read_only;

    v1_glusterfs_volume_source_local_var->_library_owned = 1;
    return v1_glusterfs_volume_source_local_var;
}

__attribute__((deprecated)) v1_glusterfs_volume_source_t *v1_glusterfs_volume_source_create(
    char *endpoints,
    char *path,
    int read_only
    ) {
    return v1_glusterfs_volume_source_create_internal (
        endpoints,
        path,
        read_only
        );
}

void v1_glusterfs_volume_source_free(v1_glusterfs_volume_source_t *v1_glusterfs_volume_source) {
    if(NULL == v1_glusterfs_volume_source){
        return ;
    }
    if(v1_glusterfs_volume_source->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_glusterfs_volume_source_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_glusterfs_volume_source->endpoints) {
        free(v1_glusterfs_volume_source->endpoints);
        v1_glusterfs_volume_source->endpoints = NULL;
    }
    if (v1_glusterfs_volume_source->path) {
        free(v1_glusterfs_volume_source->path);
        v1_glusterfs_volume_source->path = NULL;
    }
    free(v1_glusterfs_volume_source);
}

cJSON *v1_glusterfs_volume_source_convertToJSON(v1_glusterfs_volume_source_t *v1_glusterfs_volume_source) {
    cJSON *item = cJSON_CreateObject();

    // v1_glusterfs_volume_source->endpoints
    if (!v1_glusterfs_volume_source->endpoints) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "endpoints", v1_glusterfs_volume_source->endpoints) == NULL) {
    goto fail; //String
    }


    // v1_glusterfs_volume_source->path
    if (!v1_glusterfs_volume_source->path) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "path", v1_glusterfs_volume_source->path) == NULL) {
    goto fail; //String
    }


    // v1_glusterfs_volume_source->read_only
    if(v1_glusterfs_volume_source->read_only) {
    if(cJSON_AddBoolToObject(item, "readOnly", v1_glusterfs_volume_source->read_only) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_glusterfs_volume_source_t *v1_glusterfs_volume_source_parseFromJSON(cJSON *v1_glusterfs_volume_sourceJSON){

    v1_glusterfs_volume_source_t *v1_glusterfs_volume_source_local_var = NULL;

    // v1_glusterfs_volume_source->endpoints
    cJSON *endpoints = cJSON_GetObjectItemCaseSensitive(v1_glusterfs_volume_sourceJSON, "endpoints");
    if (cJSON_IsNull(endpoints)) {
        endpoints = NULL;
    }
    if (!endpoints) {
        goto end;
    }

    
    if(!cJSON_IsString(endpoints))
    {
    goto end; //String
    }

    // v1_glusterfs_volume_source->path
    cJSON *path = cJSON_GetObjectItemCaseSensitive(v1_glusterfs_volume_sourceJSON, "path");
    if (cJSON_IsNull(path)) {
        path = NULL;
    }
    if (!path) {
        goto end;
    }

    
    if(!cJSON_IsString(path))
    {
    goto end; //String
    }

    // v1_glusterfs_volume_source->read_only
    cJSON *read_only = cJSON_GetObjectItemCaseSensitive(v1_glusterfs_volume_sourceJSON, "readOnly");
    if (cJSON_IsNull(read_only)) {
        read_only = NULL;
    }
    if (read_only) { 
    if(!cJSON_IsBool(read_only))
    {
    goto end; //Bool
    }
    }


    v1_glusterfs_volume_source_local_var = v1_glusterfs_volume_source_create_internal (
        strdup(endpoints->valuestring),
        strdup(path->valuestring),
        read_only ? read_only->valueint : 0
        );

    return v1_glusterfs_volume_source_local_var;
end:
    return NULL;

}
