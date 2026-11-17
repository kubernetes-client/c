#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_nfs_volume_source.h"



static v1_nfs_volume_source_t *v1_nfs_volume_source_create_internal(
    char *path,
    int *read_only,
    char *server
    ) {
    v1_nfs_volume_source_t *v1_nfs_volume_source_local_var = malloc(sizeof(v1_nfs_volume_source_t));
    if (!v1_nfs_volume_source_local_var) {
        return NULL;
    }
    memset(v1_nfs_volume_source_local_var, 0, sizeof(v1_nfs_volume_source_t));
    v1_nfs_volume_source_local_var->_library_owned = 1;
    v1_nfs_volume_source_local_var->path = path;
    v1_nfs_volume_source_local_var->read_only = read_only;
    v1_nfs_volume_source_local_var->server = server;
    return v1_nfs_volume_source_local_var;
}

__attribute__((deprecated)) v1_nfs_volume_source_t *v1_nfs_volume_source_create(
    char *path,
    int *read_only,
    char *server
    ) {
    int *read_only_copy = NULL;
    if (read_only) {
        read_only_copy = malloc(sizeof(int));
        if (read_only_copy) *read_only_copy = *read_only;
    }
    v1_nfs_volume_source_t *result = v1_nfs_volume_source_create_internal (
        path,
        read_only_copy,
        server
        );
    if (!result) {
        free(read_only_copy);
    }
    return result;
}

void v1_nfs_volume_source_free(v1_nfs_volume_source_t *v1_nfs_volume_source) {
    if(NULL == v1_nfs_volume_source){
        return ;
    }
    if(v1_nfs_volume_source->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_nfs_volume_source_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_nfs_volume_source->path) {
        free(v1_nfs_volume_source->path);
        v1_nfs_volume_source->path = NULL;
    }
    if (v1_nfs_volume_source->read_only) {
        free(v1_nfs_volume_source->read_only);
        v1_nfs_volume_source->read_only = NULL;
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
    if(cJSON_AddBoolToObject(item, "readOnly", *v1_nfs_volume_source->read_only) == NULL) {
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

    char *path_local_str = NULL;

    // define the local variable for v1_nfs_volume_source->read_only
    int *read_only_local_var = NULL;

    char *server_local_str = NULL;

    // v1_nfs_volume_source->path
    cJSON *path = cJSON_GetObjectItemCaseSensitive(v1_nfs_volume_sourceJSON, "path");
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

    // v1_nfs_volume_source->read_only
    cJSON *read_only = cJSON_GetObjectItemCaseSensitive(v1_nfs_volume_sourceJSON, "readOnly");
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

    // v1_nfs_volume_source->server
    cJSON *server = cJSON_GetObjectItemCaseSensitive(v1_nfs_volume_sourceJSON, "server");
    if (cJSON_IsNull(server)) {
        server = NULL;
    }
    if (!server) {
        goto end;
    }

    
    if(!cJSON_IsString(server))
    {
    goto end; //String
    }


    if (path && !cJSON_IsNull(path)) path_local_str = strdup(path->valuestring);
    if (server && !cJSON_IsNull(server)) server_local_str = strdup(server->valuestring);

    v1_nfs_volume_source_local_var = v1_nfs_volume_source_create_internal (
        path_local_str,
        read_only_local_var,
        server_local_str
        );

    if (!v1_nfs_volume_source_local_var) {
        goto end;
    }

    return v1_nfs_volume_source_local_var;
end:
    if (path_local_str) {
        free(path_local_str);
        path_local_str = NULL;
    }
    if (read_only_local_var) {
        free(read_only_local_var);
        read_only_local_var = NULL;
    }
    if (server_local_str) {
        free(server_local_str);
        server_local_str = NULL;
    }
    return NULL;

}
