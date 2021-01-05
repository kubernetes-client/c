#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extensions_v1beta1_allowed_host_path.h"



extensions_v1beta1_allowed_host_path_t *extensions_v1beta1_allowed_host_path_create(
    char *path_prefix,
    int read_only
    ) {
    extensions_v1beta1_allowed_host_path_t *extensions_v1beta1_allowed_host_path_local_var = malloc(sizeof(extensions_v1beta1_allowed_host_path_t));
    if (!extensions_v1beta1_allowed_host_path_local_var) {
        return NULL;
    }
    extensions_v1beta1_allowed_host_path_local_var->path_prefix = path_prefix;
    extensions_v1beta1_allowed_host_path_local_var->read_only = read_only;

    return extensions_v1beta1_allowed_host_path_local_var;
}


void extensions_v1beta1_allowed_host_path_free(extensions_v1beta1_allowed_host_path_t *extensions_v1beta1_allowed_host_path) {
    if(NULL == extensions_v1beta1_allowed_host_path){
        return ;
    }
    listEntry_t *listEntry;
    if (extensions_v1beta1_allowed_host_path->path_prefix) {
        free(extensions_v1beta1_allowed_host_path->path_prefix);
        extensions_v1beta1_allowed_host_path->path_prefix = NULL;
    }
    free(extensions_v1beta1_allowed_host_path);
}

cJSON *extensions_v1beta1_allowed_host_path_convertToJSON(extensions_v1beta1_allowed_host_path_t *extensions_v1beta1_allowed_host_path) {
    cJSON *item = cJSON_CreateObject();

    // extensions_v1beta1_allowed_host_path->path_prefix
    if(extensions_v1beta1_allowed_host_path->path_prefix) { 
    if(cJSON_AddStringToObject(item, "pathPrefix", extensions_v1beta1_allowed_host_path->path_prefix) == NULL) {
    goto fail; //String
    }
     } 


    // extensions_v1beta1_allowed_host_path->read_only
    if(extensions_v1beta1_allowed_host_path->read_only) { 
    if(cJSON_AddBoolToObject(item, "readOnly", extensions_v1beta1_allowed_host_path->read_only) == NULL) {
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

extensions_v1beta1_allowed_host_path_t *extensions_v1beta1_allowed_host_path_parseFromJSON(cJSON *extensions_v1beta1_allowed_host_pathJSON){

    extensions_v1beta1_allowed_host_path_t *extensions_v1beta1_allowed_host_path_local_var = NULL;

    // extensions_v1beta1_allowed_host_path->path_prefix
    cJSON *path_prefix = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_allowed_host_pathJSON, "pathPrefix");
    if (path_prefix) { 
    if(!cJSON_IsString(path_prefix))
    {
    goto end; //String
    }
    }

    // extensions_v1beta1_allowed_host_path->read_only
    cJSON *read_only = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_allowed_host_pathJSON, "readOnly");
    if (read_only) { 
    if(!cJSON_IsBool(read_only))
    {
    goto end; //Bool
    }
    }


    extensions_v1beta1_allowed_host_path_local_var = extensions_v1beta1_allowed_host_path_create (
        path_prefix ? strdup(path_prefix->valuestring) : NULL,
        read_only ? read_only->valueint : 0
        );

    return extensions_v1beta1_allowed_host_path_local_var;
end:
    return NULL;

}
