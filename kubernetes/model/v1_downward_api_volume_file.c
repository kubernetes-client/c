#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_downward_api_volume_file.h"



static v1_downward_api_volume_file_t *v1_downward_api_volume_file_create_internal(
    v1_object_field_selector_t *field_ref,
    int *mode,
    char *path,
    v1_resource_field_selector_t *resource_field_ref,
    long *user
    ) {
    v1_downward_api_volume_file_t *v1_downward_api_volume_file_local_var = malloc(sizeof(v1_downward_api_volume_file_t));
    if (!v1_downward_api_volume_file_local_var) {
        return NULL;
    }
    memset(v1_downward_api_volume_file_local_var, 0, sizeof(v1_downward_api_volume_file_t));
    v1_downward_api_volume_file_local_var->_library_owned = 1;
    v1_downward_api_volume_file_local_var->field_ref = field_ref;
    v1_downward_api_volume_file_local_var->mode = mode;
    v1_downward_api_volume_file_local_var->path = path;
    v1_downward_api_volume_file_local_var->resource_field_ref = resource_field_ref;
    v1_downward_api_volume_file_local_var->user = user;
    return v1_downward_api_volume_file_local_var;
}

__attribute__((deprecated)) v1_downward_api_volume_file_t *v1_downward_api_volume_file_create(
    v1_object_field_selector_t *field_ref,
    int *mode,
    char *path,
    v1_resource_field_selector_t *resource_field_ref,
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
    v1_downward_api_volume_file_t *result = v1_downward_api_volume_file_create_internal (
        field_ref,
        mode_copy,
        path,
        resource_field_ref,
        user_copy
        );
    if (!result) {
        free(mode_copy);
        free(user_copy);
    }
    return result;
}

void v1_downward_api_volume_file_free(v1_downward_api_volume_file_t *v1_downward_api_volume_file) {
    if(NULL == v1_downward_api_volume_file){
        return ;
    }
    if(v1_downward_api_volume_file->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_downward_api_volume_file_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_downward_api_volume_file->field_ref) {
        v1_object_field_selector_free(v1_downward_api_volume_file->field_ref);
        v1_downward_api_volume_file->field_ref = NULL;
    }
    if (v1_downward_api_volume_file->mode) {
        free(v1_downward_api_volume_file->mode);
        v1_downward_api_volume_file->mode = NULL;
    }
    if (v1_downward_api_volume_file->path) {
        free(v1_downward_api_volume_file->path);
        v1_downward_api_volume_file->path = NULL;
    }
    if (v1_downward_api_volume_file->resource_field_ref) {
        v1_resource_field_selector_free(v1_downward_api_volume_file->resource_field_ref);
        v1_downward_api_volume_file->resource_field_ref = NULL;
    }
    if (v1_downward_api_volume_file->user) {
        free(v1_downward_api_volume_file->user);
        v1_downward_api_volume_file->user = NULL;
    }
    free(v1_downward_api_volume_file);
}

cJSON *v1_downward_api_volume_file_convertToJSON(v1_downward_api_volume_file_t *v1_downward_api_volume_file) {
    cJSON *item = cJSON_CreateObject();

    // v1_downward_api_volume_file->field_ref
    if(v1_downward_api_volume_file->field_ref) {
    cJSON *field_ref_local_JSON = v1_object_field_selector_convertToJSON(v1_downward_api_volume_file->field_ref);
    if(field_ref_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "fieldRef", field_ref_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_downward_api_volume_file->mode
    if(v1_downward_api_volume_file->mode) {
    if(cJSON_AddNumberToObject(item, "mode", *v1_downward_api_volume_file->mode) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_downward_api_volume_file->path
    if (!v1_downward_api_volume_file->path) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "path", v1_downward_api_volume_file->path) == NULL) {
    goto fail; //String
    }


    // v1_downward_api_volume_file->resource_field_ref
    if(v1_downward_api_volume_file->resource_field_ref) {
    cJSON *resource_field_ref_local_JSON = v1_resource_field_selector_convertToJSON(v1_downward_api_volume_file->resource_field_ref);
    if(resource_field_ref_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "resourceFieldRef", resource_field_ref_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_downward_api_volume_file->user
    if(v1_downward_api_volume_file->user) {
    if(cJSON_AddNumberToObject(item, "user", *v1_downward_api_volume_file->user) == NULL) {
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

v1_downward_api_volume_file_t *v1_downward_api_volume_file_parseFromJSON(cJSON *v1_downward_api_volume_fileJSON){

    v1_downward_api_volume_file_t *v1_downward_api_volume_file_local_var = NULL;

    // define the local variable for v1_downward_api_volume_file->field_ref
    v1_object_field_selector_t *field_ref_local_nonprim = NULL;

    // define the local variable for v1_downward_api_volume_file->mode
    int *mode_local_var = NULL;

    char *path_local_str = NULL;

    // define the local variable for v1_downward_api_volume_file->resource_field_ref
    v1_resource_field_selector_t *resource_field_ref_local_nonprim = NULL;

    // define the local variable for v1_downward_api_volume_file->user
    long *user_local_var = NULL;

    // v1_downward_api_volume_file->field_ref
    cJSON *field_ref = cJSON_GetObjectItemCaseSensitive(v1_downward_api_volume_fileJSON, "fieldRef");
    if (cJSON_IsNull(field_ref)) {
        field_ref = NULL;
    }
    if (field_ref) { 
    field_ref_local_nonprim = v1_object_field_selector_parseFromJSON(field_ref); //nonprimitive
    }

    // v1_downward_api_volume_file->mode
    cJSON *mode = cJSON_GetObjectItemCaseSensitive(v1_downward_api_volume_fileJSON, "mode");
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

    // v1_downward_api_volume_file->path
    cJSON *path = cJSON_GetObjectItemCaseSensitive(v1_downward_api_volume_fileJSON, "path");
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

    // v1_downward_api_volume_file->resource_field_ref
    cJSON *resource_field_ref = cJSON_GetObjectItemCaseSensitive(v1_downward_api_volume_fileJSON, "resourceFieldRef");
    if (cJSON_IsNull(resource_field_ref)) {
        resource_field_ref = NULL;
    }
    if (resource_field_ref) { 
    resource_field_ref_local_nonprim = v1_resource_field_selector_parseFromJSON(resource_field_ref); //nonprimitive
    }

    // v1_downward_api_volume_file->user
    cJSON *user = cJSON_GetObjectItemCaseSensitive(v1_downward_api_volume_fileJSON, "user");
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


    if (path && !cJSON_IsNull(path)) path_local_str = strdup(path->valuestring);

    v1_downward_api_volume_file_local_var = v1_downward_api_volume_file_create_internal (
        field_ref ? field_ref_local_nonprim : NULL,
        mode_local_var,
        path_local_str,
        resource_field_ref ? resource_field_ref_local_nonprim : NULL,
        user_local_var
        );

    if (!v1_downward_api_volume_file_local_var) {
        goto end;
    }

    return v1_downward_api_volume_file_local_var;
end:
    if (field_ref_local_nonprim) {
        v1_object_field_selector_free(field_ref_local_nonprim);
        field_ref_local_nonprim = NULL;
    }
    if (mode_local_var) {
        free(mode_local_var);
        mode_local_var = NULL;
    }
    if (path_local_str) {
        free(path_local_str);
        path_local_str = NULL;
    }
    if (resource_field_ref_local_nonprim) {
        v1_resource_field_selector_free(resource_field_ref_local_nonprim);
        resource_field_ref_local_nonprim = NULL;
    }
    if (user_local_var) {
        free(user_local_var);
        user_local_var = NULL;
    }
    return NULL;

}
