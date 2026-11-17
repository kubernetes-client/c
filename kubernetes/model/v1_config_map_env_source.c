#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_config_map_env_source.h"



static v1_config_map_env_source_t *v1_config_map_env_source_create_internal(
    char *name,
    int *optional
    ) {
    v1_config_map_env_source_t *v1_config_map_env_source_local_var = malloc(sizeof(v1_config_map_env_source_t));
    if (!v1_config_map_env_source_local_var) {
        return NULL;
    }
    memset(v1_config_map_env_source_local_var, 0, sizeof(v1_config_map_env_source_t));
    v1_config_map_env_source_local_var->_library_owned = 1;
    v1_config_map_env_source_local_var->name = name;
    v1_config_map_env_source_local_var->optional = optional;
    return v1_config_map_env_source_local_var;
}

__attribute__((deprecated)) v1_config_map_env_source_t *v1_config_map_env_source_create(
    char *name,
    int *optional
    ) {
    int *optional_copy = NULL;
    if (optional) {
        optional_copy = malloc(sizeof(int));
        if (optional_copy) *optional_copy = *optional;
    }
    v1_config_map_env_source_t *result = v1_config_map_env_source_create_internal (
        name,
        optional_copy
        );
    if (!result) {
        free(optional_copy);
    }
    return result;
}

void v1_config_map_env_source_free(v1_config_map_env_source_t *v1_config_map_env_source) {
    if(NULL == v1_config_map_env_source){
        return ;
    }
    if(v1_config_map_env_source->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_config_map_env_source_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_config_map_env_source->name) {
        free(v1_config_map_env_source->name);
        v1_config_map_env_source->name = NULL;
    }
    if (v1_config_map_env_source->optional) {
        free(v1_config_map_env_source->optional);
        v1_config_map_env_source->optional = NULL;
    }
    free(v1_config_map_env_source);
}

cJSON *v1_config_map_env_source_convertToJSON(v1_config_map_env_source_t *v1_config_map_env_source) {
    cJSON *item = cJSON_CreateObject();

    // v1_config_map_env_source->name
    if(v1_config_map_env_source->name) {
    if(cJSON_AddStringToObject(item, "name", v1_config_map_env_source->name) == NULL) {
    goto fail; //String
    }
    }


    // v1_config_map_env_source->optional
    if(v1_config_map_env_source->optional) {
    if(cJSON_AddBoolToObject(item, "optional", *v1_config_map_env_source->optional) == NULL) {
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

v1_config_map_env_source_t *v1_config_map_env_source_parseFromJSON(cJSON *v1_config_map_env_sourceJSON){

    v1_config_map_env_source_t *v1_config_map_env_source_local_var = NULL;

    char *name_local_str = NULL;

    // define the local variable for v1_config_map_env_source->optional
    int *optional_local_var = NULL;

    // v1_config_map_env_source->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_config_map_env_sourceJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (name) { 
    if(!cJSON_IsString(name) && !cJSON_IsNull(name))
    {
    goto end; //String
    }
    }

    // v1_config_map_env_source->optional
    cJSON *optional = cJSON_GetObjectItemCaseSensitive(v1_config_map_env_sourceJSON, "optional");
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


    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);

    v1_config_map_env_source_local_var = v1_config_map_env_source_create_internal (
        name_local_str,
        optional_local_var
        );

    if (!v1_config_map_env_source_local_var) {
        goto end;
    }

    return v1_config_map_env_source_local_var;
end:
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (optional_local_var) {
        free(optional_local_var);
        optional_local_var = NULL;
    }
    return NULL;

}
