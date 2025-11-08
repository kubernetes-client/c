#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_file_key_selector.h"



static v1_file_key_selector_t *v1_file_key_selector_create_internal(
    char *key,
    int optional,
    char *path,
    char *volume_name
    ) {
    v1_file_key_selector_t *v1_file_key_selector_local_var = malloc(sizeof(v1_file_key_selector_t));
    if (!v1_file_key_selector_local_var) {
        return NULL;
    }
    v1_file_key_selector_local_var->key = key;
    v1_file_key_selector_local_var->optional = optional;
    v1_file_key_selector_local_var->path = path;
    v1_file_key_selector_local_var->volume_name = volume_name;

    v1_file_key_selector_local_var->_library_owned = 1;
    return v1_file_key_selector_local_var;
}

__attribute__((deprecated)) v1_file_key_selector_t *v1_file_key_selector_create(
    char *key,
    int optional,
    char *path,
    char *volume_name
    ) {
    return v1_file_key_selector_create_internal (
        key,
        optional,
        path,
        volume_name
        );
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
    if(cJSON_AddBoolToObject(item, "optional", v1_file_key_selector->optional) == NULL) {
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


    v1_file_key_selector_local_var = v1_file_key_selector_create_internal (
        strdup(key->valuestring),
        optional ? optional->valueint : 0,
        strdup(path->valuestring),
        strdup(volume_name->valuestring)
        );

    return v1_file_key_selector_local_var;
end:
    return NULL;

}
