#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_key_to_path.h"



static v1_key_to_path_t *v1_key_to_path_create_internal(
    char *key,
    int *mode,
    char *path,
    long *user
    ) {
    v1_key_to_path_t *v1_key_to_path_local_var = malloc(sizeof(v1_key_to_path_t));
    if (!v1_key_to_path_local_var) {
        return NULL;
    }
    memset(v1_key_to_path_local_var, 0, sizeof(v1_key_to_path_t));
    v1_key_to_path_local_var->_library_owned = 1;
    v1_key_to_path_local_var->key = key;
    v1_key_to_path_local_var->mode = mode;
    v1_key_to_path_local_var->path = path;
    v1_key_to_path_local_var->user = user;
    return v1_key_to_path_local_var;
}

__attribute__((deprecated)) v1_key_to_path_t *v1_key_to_path_create(
    char *key,
    int *mode,
    char *path,
    long *user
    ) {
    int *mode_copy = NULL;
    if (mode) {
        mode_copy = malloc(sizeof(int));
        if (mode_copy) *mode_copy = *mode;
    }
    long *user_copy = NULL;
    if (user) {
        user_copy = malloc(sizeof(long));
        if (user_copy) *user_copy = *user;
    }
    v1_key_to_path_t *result = v1_key_to_path_create_internal (
        key,
        mode_copy,
        path,
        user_copy
        );
    if (!result) {
        free(mode_copy);
        free(user_copy);
    }
    return result;
}

void v1_key_to_path_free(v1_key_to_path_t *v1_key_to_path) {
    if(NULL == v1_key_to_path){
        return ;
    }
    if(v1_key_to_path->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_key_to_path_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_key_to_path->key) {
        free(v1_key_to_path->key);
        v1_key_to_path->key = NULL;
    }
    if (v1_key_to_path->mode) {
        free(v1_key_to_path->mode);
        v1_key_to_path->mode = NULL;
    }
    if (v1_key_to_path->path) {
        free(v1_key_to_path->path);
        v1_key_to_path->path = NULL;
    }
    if (v1_key_to_path->user) {
        free(v1_key_to_path->user);
        v1_key_to_path->user = NULL;
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
    if(cJSON_AddNumberToObject(item, "mode", *v1_key_to_path->mode) == NULL) {
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


    // v1_key_to_path->user
    if(v1_key_to_path->user) {
    if(cJSON_AddNumberToObject(item, "user", *v1_key_to_path->user) == NULL) {
    goto fail; //Numeric
    }
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

    char *key_local_str = NULL;

    // define the local variable for v1_key_to_path->mode
    int *mode_local_var = NULL;

    char *path_local_str = NULL;

    // define the local variable for v1_key_to_path->user
    long *user_local_var = NULL;

    // v1_key_to_path->key
    cJSON *key = cJSON_GetObjectItemCaseSensitive(v1_key_to_pathJSON, "key");
    if (cJSON_IsNull(key)) {
        key = NULL;
    }
    if (!key) {
        goto end;
    }

    
    if(!cJSON_IsString(key))
    {
    goto end; //String
    }

    // v1_key_to_path->mode
    cJSON *mode = cJSON_GetObjectItemCaseSensitive(v1_key_to_pathJSON, "mode");
    if (cJSON_IsNull(mode)) {
        mode = NULL;
    }
    if (mode) { 
    if(!cJSON_IsNumber(mode))
    {
    goto end; //Numeric
    }
    mode_local_var = malloc(sizeof(int));
    if(!mode_local_var)
    {
        goto end;
    }
    *mode_local_var = mode->valuedouble;
    }

    // v1_key_to_path->path
    cJSON *path = cJSON_GetObjectItemCaseSensitive(v1_key_to_pathJSON, "path");
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

    // v1_key_to_path->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(v1_key_to_pathJSON, "user");
    if (cJSON_IsNull(user)) {
        user = NULL;
    }
    if (user) { 
    if(!cJSON_IsNumber(user))
    {
    goto end; //Numeric
    }
    user_local_var = malloc(sizeof(long));
    if(!user_local_var)
    {
        goto end;
    }
    *user_local_var = user->valuedouble;
    }


    if (key && !cJSON_IsNull(key)) key_local_str = strdup(key->valuestring);
    if (path && !cJSON_IsNull(path)) path_local_str = strdup(path->valuestring);

    v1_key_to_path_local_var = v1_key_to_path_create_internal (
        key_local_str,
        mode_local_var,
        path_local_str,
        user_local_var
        );

    if (!v1_key_to_path_local_var) {
        goto end;
    }

    return v1_key_to_path_local_var;
end:
    if (key_local_str) {
        free(key_local_str);
        key_local_str = NULL;
    }
    if (mode_local_var) {
        free(mode_local_var);
        mode_local_var = NULL;
    }
    if (path_local_str) {
        free(path_local_str);
        path_local_str = NULL;
    }
    if (user_local_var) {
        free(user_local_var);
        user_local_var = NULL;
    }
    return NULL;

}
