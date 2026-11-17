#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_file_key_selector.h"



static v1_file_key_selector_t *v1_file_key_selector_create_internal(
    char *key,
    int *optional,
    char *path,
    char *volume_name
    ) {
    v1_file_key_selector_t *v1_file_key_selector_local_var = malloc(sizeof(v1_file_key_selector_t));
    if (!v1_file_key_selector_local_var) {
        return NULL;
    }
    memset(v1_file_key_selector_local_var, 0, sizeof(v1_file_key_selector_t));
    v1_file_key_selector_local_var->_library_owned = 1;
    v1_file_key_selector_local_var->key = key;
    v1_file_key_selector_local_var->optional = optional;
    v1_file_key_selector_local_var->path = path;
    v1_file_key_selector_local_var->volume_name = volume_name;
    return v1_file_key_selector_local_var;
}

__attribute__((deprecated)) v1_file_key_selector_t *v1_file_key_selector_create(
    char *key,
    int *optional,
    char *path,
    char *volume_name
    ) {
    int *optional_copy = NULL;
    if (optional) {
        optional_copy = malloc(sizeof(int));
        if (optional_copy) *optional_copy = *optional;
    }
    v1_file_key_selector_t *result = v1_file_key_selector_create_internal (
        key,
        optional_copy,
        path,
        volume_name
        );
    if (!result) {
        free(optional_copy);
    }
    return result;
}

void v1_file_key_selector_free(v1_file_key_selector_t *v1_file_key_selector) {
    if(NULL == v1_file_key_selector){
        return ;
    }
    if(v1_file_key_selector->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_file_key_selector_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_file_key_selector->key) {
        free(v1_file_key_selector->key);
        v1_file_key_selector->key = NULL;
    }
    if (v1_file_key_selector->optional) {
        free(v1_file_key_selector->optional);
        v1_file_key_selector->optional = NULL;
    }
    if (v1_file_key_selector->path) {
        free(v1_file_key_selector->path);
        v1_file_key_selector->path = NULL;
    }
    if (v1_file_key_selector->volume_name) {
        free(v1_file_key_selector->volume_name);
        v1_file_key_selector->volume_name = NULL;
    }
    free(v1_file_key_selector);
}

cJSON *v1_file_key_selector_convertToJSON(v1_file_key_selector_t *v1_file_key_selector) {
    cJSON *item = cJSON_CreateObject();

    // v1_file_key_selector->key
    if (!v1_file_key_selector->key) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "key", v1_file_key_selector->key) == NULL) {
    goto fail; //String
    }


    // v1_file_key_selector->optional
    if(v1_file_key_selector->optional) {
    if(cJSON_AddBoolToObject(item, "optional", *v1_file_key_selector->optional) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_file_key_selector->path
    if (!v1_file_key_selector->path) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "path", v1_file_key_selector->path) == NULL) {
    goto fail; //String
    }


    // v1_file_key_selector->volume_name
    if (!v1_file_key_selector->volume_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "volumeName", v1_file_key_selector->volume_name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_file_key_selector_t *v1_file_key_selector_parseFromJSON(cJSON *v1_file_key_selectorJSON){

    v1_file_key_selector_t *v1_file_key_selector_local_var = NULL;

    char *key_local_str = NULL;

    // define the local variable for v1_file_key_selector->optional
    int *optional_local_var = NULL;

    char *path_local_str = NULL;

    char *volume_name_local_str = NULL;

    // v1_file_key_selector->key
    cJSON *key = cJSON_GetObjectItemCaseSensitive(v1_file_key_selectorJSON, "key");
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

    // v1_file_key_selector->optional
    cJSON *optional = cJSON_GetObjectItemCaseSensitive(v1_file_key_selectorJSON, "optional");
    if (cJSON_IsNull(optional)) {
        optional = NULL;
    }
    if (optional) { 
    if(!cJSON_IsBool(optional))
    {
    goto end; //Bool
    }
    optional_local_var = malloc(sizeof(int));
    if(!optional_local_var)
    {
        goto end;
    }
    *optional_local_var = optional->valueint;
    }

    // v1_file_key_selector->path
    cJSON *path = cJSON_GetObjectItemCaseSensitive(v1_file_key_selectorJSON, "path");
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

    // v1_file_key_selector->volume_name
    cJSON *volume_name = cJSON_GetObjectItemCaseSensitive(v1_file_key_selectorJSON, "volumeName");
    if (cJSON_IsNull(volume_name)) {
        volume_name = NULL;
    }
    if (!volume_name) {
        goto end;
    }

    
    if(!cJSON_IsString(volume_name))
    {
    goto end; //String
    }


    if (key && !cJSON_IsNull(key)) key_local_str = strdup(key->valuestring);
    if (path && !cJSON_IsNull(path)) path_local_str = strdup(path->valuestring);
    if (volume_name && !cJSON_IsNull(volume_name)) volume_name_local_str = strdup(volume_name->valuestring);

    v1_file_key_selector_local_var = v1_file_key_selector_create_internal (
        key_local_str,
        optional_local_var,
        path_local_str,
        volume_name_local_str
        );

    if (!v1_file_key_selector_local_var) {
        goto end;
    }

    return v1_file_key_selector_local_var;
end:
    if (key_local_str) {
        free(key_local_str);
        key_local_str = NULL;
    }
    if (optional_local_var) {
        free(optional_local_var);
        optional_local_var = NULL;
    }
    if (path_local_str) {
        free(path_local_str);
        path_local_str = NULL;
    }
    if (volume_name_local_str) {
        free(volume_name_local_str);
        volume_name_local_str = NULL;
    }
    return NULL;

}
