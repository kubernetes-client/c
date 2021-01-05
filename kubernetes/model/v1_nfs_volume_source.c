#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_nfs_volume_source.h"



v1_nfs_volume_source_t *v1_nfs_volume_source_create(
    char *path,
    int read_only,
    char *server
    ) {
    v1_nfs_volume_source_t *v1_nfs_volume_source_local_var = malloc(sizeof(v1_nfs_volume_source_t));
    if (!v1_nfs_volume_source_local_var) {
        return NULL;
    }
    v1_nfs_volume_source_local_var->path = path;
    v1_nfs_volume_source_local_var->read_only = read_only;
    v1_nfs_volume_source_local_var->server = server;

    return v1_nfs_volume_source_local_var;
}


void v1_nfs_volume_source_free(v1_nfs_volume_source_t *v1_nfs_volume_source) {
    if(NULL == v1_nfs_volume_source){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_nfs_volume_source->path) {
        free(v1_nfs_volume_source->path);
        v1_nfs_volume_source->path = NULL;
    }
    if (v1_nfs_volume_source->server) {
        free(v1_nfs_volume_source->server);
        v1_nfs_volume_source->server = NULL;
    }
    free(v1_nfs_volume_source);
}

cJSON *v1_nfs_volume_source_convertToJSON(v1_nfs_volume_source_t *v1_nfs_volume_source) {
    cJSON *item = cJSON_CreateObject();

    // v1_nfs_volume_source->path
    if (!v1_nfs_volume_source->path) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "path", v1_nfs_volume_source->path) == NULL) {
    goto fail; //String
    }


    // v1_nfs_volume_source->read_only
    if(v1_nfs_volume_source->read_only) { 
    if(cJSON_AddBoolToObject(item, "readOnly", v1_nfs_volume_source->read_only) == NULL) {
    goto fail; //Bool
    }
     } 


    // v1_nfs_volume_source->server
    if (!v1_nfs_volume_source->server) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "server", v1_nfs_volume_source->server) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_nfs_volume_source_t *v1_nfs_volume_source_parseFromJSON(cJSON *v1_nfs_volume_sourceJSON){

    v1_nfs_volume_source_t *v1_nfs_volume_source_local_var = NULL;

    // v1_nfs_volume_source->path
    cJSON *path = cJSON_GetObjectItemCaseSensitive(v1_nfs_volume_sourceJSON, "path");
    if (!path) {
        goto end;
    }

    
    if(!cJSON_IsString(path))
    {
    goto end; //String
    }

    // v1_nfs_volume_source->read_only
    cJSON *read_only = cJSON_GetObjectItemCaseSensitive(v1_nfs_volume_sourceJSON, "readOnly");
    if (read_only) { 
    if(!cJSON_IsBool(read_only))
    {
    goto end; //Bool
    }
    }

    // v1_nfs_volume_source->server
    cJSON *server = cJSON_GetObjectItemCaseSensitive(v1_nfs_volume_sourceJSON, "server");
    if (!server) {
        goto end;
    }

    
    if(!cJSON_IsString(server))
    {
    goto end; //String
    }


    v1_nfs_volume_source_local_var = v1_nfs_volume_source_create (
        strdup(path->valuestring),
        read_only ? read_only->valueint : 0,
        strdup(server->valuestring)
        );

    return v1_nfs_volume_source_local_var;
end:
    return NULL;

}
