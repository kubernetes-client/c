#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_allowed_host_path.h"



v1beta1_allowed_host_path_t *v1beta1_allowed_host_path_create(
    char *path_prefix,
    int read_only
    ) {
    v1beta1_allowed_host_path_t *v1beta1_allowed_host_path_local_var = malloc(sizeof(v1beta1_allowed_host_path_t));
    if (!v1beta1_allowed_host_path_local_var) {
        return NULL;
    }
    v1beta1_allowed_host_path_local_var->path_prefix = path_prefix;
    v1beta1_allowed_host_path_local_var->read_only = read_only;

    return v1beta1_allowed_host_path_local_var;
}


void v1beta1_allowed_host_path_free(v1beta1_allowed_host_path_t *v1beta1_allowed_host_path) {
    if(NULL == v1beta1_allowed_host_path){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_allowed_host_path->path_prefix) {
        free(v1beta1_allowed_host_path->path_prefix);
        v1beta1_allowed_host_path->path_prefix = NULL;
    }
    free(v1beta1_allowed_host_path);
}

cJSON *v1beta1_allowed_host_path_convertToJSON(v1beta1_allowed_host_path_t *v1beta1_allowed_host_path) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_allowed_host_path->path_prefix
    if(v1beta1_allowed_host_path->path_prefix) {
    if(cJSON_AddStringToObject(item, "pathPrefix", v1beta1_allowed_host_path->path_prefix) == NULL) {
    goto fail; //String
    }
    }


    // v1beta1_allowed_host_path->read_only
    if(v1beta1_allowed_host_path->read_only) {
    if(cJSON_AddBoolToObject(item, "readOnly", v1beta1_allowed_host_path->read_only) == NULL) {
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

v1beta1_allowed_host_path_t *v1beta1_allowed_host_path_parseFromJSON(cJSON *v1beta1_allowed_host_pathJSON){

    v1beta1_allowed_host_path_t *v1beta1_allowed_host_path_local_var = NULL;

    // v1beta1_allowed_host_path->path_prefix
    cJSON *path_prefix = cJSON_GetObjectItemCaseSensitive(v1beta1_allowed_host_pathJSON, "pathPrefix");
    if (path_prefix) { 
    if(!cJSON_IsString(path_prefix))
    {
    goto end; //String
    }
    }

    // v1beta1_allowed_host_path->read_only
    cJSON *read_only = cJSON_GetObjectItemCaseSensitive(v1beta1_allowed_host_pathJSON, "readOnly");
    if (read_only) { 
    if(!cJSON_IsBool(read_only))
    {
    goto end; //Bool
    }
    }


    v1beta1_allowed_host_path_local_var = v1beta1_allowed_host_path_create (
        path_prefix ? strdup(path_prefix->valuestring) : NULL,
        read_only ? read_only->valueint : 0
        );

    return v1beta1_allowed_host_path_local_var;
end:
    return NULL;

}
