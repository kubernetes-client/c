#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_empty_dir_volume_source.h"



static v1_empty_dir_volume_source_t *v1_empty_dir_volume_source_create_internal(
    char *medium,
    int *mode,
    char *size_limit
    ) {
    v1_empty_dir_volume_source_t *v1_empty_dir_volume_source_local_var = malloc(sizeof(v1_empty_dir_volume_source_t));
    if (!v1_empty_dir_volume_source_local_var) {
        return NULL;
    }
    memset(v1_empty_dir_volume_source_local_var, 0, sizeof(v1_empty_dir_volume_source_t));
    v1_empty_dir_volume_source_local_var->_library_owned = 1;
    v1_empty_dir_volume_source_local_var->medium = medium;
    v1_empty_dir_volume_source_local_var->mode = mode;
    v1_empty_dir_volume_source_local_var->size_limit = size_limit;
    return v1_empty_dir_volume_source_local_var;
}

__attribute__((deprecated)) v1_empty_dir_volume_source_t *v1_empty_dir_volume_source_create(
    char *medium,
    int *mode,
    char *size_limit
    ) {
    int *mode_copy = NULL;
    if (mode) {
        mode_copy = malloc(sizeof(int));
        if (mode_copy) *mode_copy = *mode;
    }
    v1_empty_dir_volume_source_t *result = v1_empty_dir_volume_source_create_internal (
        medium,
        mode_copy,
        size_limit
        );
    if (!result) {
        free(mode_copy);
    }
    return result;
}

void v1_empty_dir_volume_source_free(v1_empty_dir_volume_source_t *v1_empty_dir_volume_source) {
    if(NULL == v1_empty_dir_volume_source){
        return ;
    }
    if(v1_empty_dir_volume_source->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_empty_dir_volume_source_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_empty_dir_volume_source->medium) {
        free(v1_empty_dir_volume_source->medium);
        v1_empty_dir_volume_source->medium = NULL;
    }
    if (v1_empty_dir_volume_source->mode) {
        free(v1_empty_dir_volume_source->mode);
        v1_empty_dir_volume_source->mode = NULL;
    }
    if (v1_empty_dir_volume_source->size_limit) {
        free(v1_empty_dir_volume_source->size_limit);
        v1_empty_dir_volume_source->size_limit = NULL;
    }
    free(v1_empty_dir_volume_source);
}

cJSON *v1_empty_dir_volume_source_convertToJSON(v1_empty_dir_volume_source_t *v1_empty_dir_volume_source) {
    cJSON *item = cJSON_CreateObject();

    // v1_empty_dir_volume_source->medium
    if(v1_empty_dir_volume_source->medium) {
    if(cJSON_AddStringToObject(item, "medium", v1_empty_dir_volume_source->medium) == NULL) {
    goto fail; //String
    }
    }


    // v1_empty_dir_volume_source->mode
    if(v1_empty_dir_volume_source->mode) {
    if(cJSON_AddNumberToObject(item, "mode", *v1_empty_dir_volume_source->mode) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_empty_dir_volume_source->size_limit
    if(v1_empty_dir_volume_source->size_limit) {
    if(cJSON_AddStringToObject(item, "sizeLimit", v1_empty_dir_volume_source->size_limit) == NULL) {
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

v1_empty_dir_volume_source_t *v1_empty_dir_volume_source_parseFromJSON(cJSON *v1_empty_dir_volume_sourceJSON){

    v1_empty_dir_volume_source_t *v1_empty_dir_volume_source_local_var = NULL;

    char *medium_local_str = NULL;

    // define the local variable for v1_empty_dir_volume_source->mode
    int *mode_local_var = NULL;

    char *size_limit_local_str = NULL;

    // v1_empty_dir_volume_source->medium
    cJSON *medium = cJSON_GetObjectItemCaseSensitive(v1_empty_dir_volume_sourceJSON, "medium");
    if (cJSON_IsNull(medium)) {
        medium = NULL;
    }
    if (medium) { 
    if(!cJSON_IsString(medium) && !cJSON_IsNull(medium))
    {
    goto end; //String
    }
    }

    // v1_empty_dir_volume_source->mode
    cJSON *mode = cJSON_GetObjectItemCaseSensitive(v1_empty_dir_volume_sourceJSON, "mode");
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

    // v1_empty_dir_volume_source->size_limit
    cJSON *size_limit = cJSON_GetObjectItemCaseSensitive(v1_empty_dir_volume_sourceJSON, "sizeLimit");
    if (cJSON_IsNull(size_limit)) {
        size_limit = NULL;
    }
    if (size_limit) { 
    if(!cJSON_IsString(size_limit) && !cJSON_IsNull(size_limit))
    {
    goto end; //String
    }
    }


    if (medium && !cJSON_IsNull(medium)) medium_local_str = strdup(medium->valuestring);
    if (size_limit && !cJSON_IsNull(size_limit)) size_limit_local_str = strdup(size_limit->valuestring);

    v1_empty_dir_volume_source_local_var = v1_empty_dir_volume_source_create_internal (
        medium_local_str,
        mode_local_var,
        size_limit_local_str
        );

    if (!v1_empty_dir_volume_source_local_var) {
        goto end;
    }

    return v1_empty_dir_volume_source_local_var;
end:
    if (medium_local_str) {
        free(medium_local_str);
        medium_local_str = NULL;
    }
    if (mode_local_var) {
        free(mode_local_var);
        mode_local_var = NULL;
    }
    if (size_limit_local_str) {
        free(size_limit_local_str);
        size_limit_local_str = NULL;
    }
    return NULL;

}
