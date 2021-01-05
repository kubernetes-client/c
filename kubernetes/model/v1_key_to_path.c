#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_key_to_path.h"



v1_key_to_path_t *v1_key_to_path_create(
    char *key,
    int mode,
    char *path
    ) {
    v1_key_to_path_t *v1_key_to_path_local_var = malloc(sizeof(v1_key_to_path_t));
    if (!v1_key_to_path_local_var) {
        return NULL;
    }
    v1_key_to_path_local_var->key = key;
    v1_key_to_path_local_var->mode = mode;
    v1_key_to_path_local_var->path = path;

    return v1_key_to_path_local_var;
}


void v1_key_to_path_free(v1_key_to_path_t *v1_key_to_path) {
    if(NULL == v1_key_to_path){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_key_to_path->key) {
        free(v1_key_to_path->key);
        v1_key_to_path->key = NULL;
    }
    if (v1_key_to_path->path) {
        free(v1_key_to_path->path);
        v1_key_to_path->path = NULL;
    }
    free(v1_key_to_path);
}

cJSON *v1_key_to_path_convertToJSON(v1_key_to_path_t *v1_key_to_path) {
    cJSON *item = cJSON_CreateObject();

    // v1_key_to_path->key
    if (!v1_key_to_path->key) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "key", v1_key_to_path->key) == NULL) {
    goto fail; //String
    }


    // v1_key_to_path->mode
    if(v1_key_to_path->mode) { 
    if(cJSON_AddNumberToObject(item, "mode", v1_key_to_path->mode) == NULL) {
    goto fail; //Numeric
    }
     } 


    // v1_key_to_path->path
    if (!v1_key_to_path->path) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "path", v1_key_to_path->path) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_key_to_path_t *v1_key_to_path_parseFromJSON(cJSON *v1_key_to_pathJSON){

    v1_key_to_path_t *v1_key_to_path_local_var = NULL;

    // v1_key_to_path->key
    cJSON *key = cJSON_GetObjectItemCaseSensitive(v1_key_to_pathJSON, "key");
    if (!key) {
        goto end;
    }

    
    if(!cJSON_IsString(key))
    {
    goto end; //String
    }

    // v1_key_to_path->mode
    cJSON *mode = cJSON_GetObjectItemCaseSensitive(v1_key_to_pathJSON, "mode");
    if (mode) { 
    if(!cJSON_IsNumber(mode))
    {
    goto end; //Numeric
    }
    }

    // v1_key_to_path->path
    cJSON *path = cJSON_GetObjectItemCaseSensitive(v1_key_to_pathJSON, "path");
    if (!path) {
        goto end;
    }

    
    if(!cJSON_IsString(path))
    {
    goto end; //String
    }


    v1_key_to_path_local_var = v1_key_to_path_create (
        strdup(key->valuestring),
        mode ? mode->valuedouble : 0,
        strdup(path->valuestring)
        );

    return v1_key_to_path_local_var;
end:
    return NULL;

}
