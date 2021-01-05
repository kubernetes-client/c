#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_host_path_volume_source.h"



v1_host_path_volume_source_t *v1_host_path_volume_source_create(
    char *path,
    char *type
    ) {
    v1_host_path_volume_source_t *v1_host_path_volume_source_local_var = malloc(sizeof(v1_host_path_volume_source_t));
    if (!v1_host_path_volume_source_local_var) {
        return NULL;
    }
    v1_host_path_volume_source_local_var->path = path;
    v1_host_path_volume_source_local_var->type = type;

    return v1_host_path_volume_source_local_var;
}


void v1_host_path_volume_source_free(v1_host_path_volume_source_t *v1_host_path_volume_source) {
    if(NULL == v1_host_path_volume_source){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_host_path_volume_source->path) {
        free(v1_host_path_volume_source->path);
        v1_host_path_volume_source->path = NULL;
    }
    if (v1_host_path_volume_source->type) {
        free(v1_host_path_volume_source->type);
        v1_host_path_volume_source->type = NULL;
    }
    free(v1_host_path_volume_source);
}

cJSON *v1_host_path_volume_source_convertToJSON(v1_host_path_volume_source_t *v1_host_path_volume_source) {
    cJSON *item = cJSON_CreateObject();

    // v1_host_path_volume_source->path
    if (!v1_host_path_volume_source->path) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "path", v1_host_path_volume_source->path) == NULL) {
    goto fail; //String
    }


    // v1_host_path_volume_source->type
    if(v1_host_path_volume_source->type) { 
    if(cJSON_AddStringToObject(item, "type", v1_host_path_volume_source->type) == NULL) {
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

v1_host_path_volume_source_t *v1_host_path_volume_source_parseFromJSON(cJSON *v1_host_path_volume_sourceJSON){

    v1_host_path_volume_source_t *v1_host_path_volume_source_local_var = NULL;

    // v1_host_path_volume_source->path
    cJSON *path = cJSON_GetObjectItemCaseSensitive(v1_host_path_volume_sourceJSON, "path");
    if (!path) {
        goto end;
    }

    
    if(!cJSON_IsString(path))
    {
    goto end; //String
    }

    // v1_host_path_volume_source->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1_host_path_volume_sourceJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }
    }


    v1_host_path_volume_source_local_var = v1_host_path_volume_source_create (
        strdup(path->valuestring),
        type ? strdup(type->valuestring) : NULL
        );

    return v1_host_path_volume_source_local_var;
end:
    return NULL;

}
