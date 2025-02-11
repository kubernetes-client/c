#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_env_from_source.h"



static v1_env_from_source_t *v1_env_from_source_create_internal(
    v1_config_map_env_source_t *config_map_ref,
    char *prefix,
    v1_secret_env_source_t *secret_ref
    ) {
    v1_env_from_source_t *v1_env_from_source_local_var = malloc(sizeof(v1_env_from_source_t));
    if (!v1_env_from_source_local_var) {
        return NULL;
    }
    v1_env_from_source_local_var->config_map_ref = config_map_ref;
    v1_env_from_source_local_var->prefix = prefix;
    v1_env_from_source_local_var->secret_ref = secret_ref;

    v1_env_from_source_local_var->_library_owned = 1;
    return v1_env_from_source_local_var;
}

__attribute__((deprecated)) v1_env_from_source_t *v1_env_from_source_create(
    v1_config_map_env_source_t *config_map_ref,
    char *prefix,
    v1_secret_env_source_t *secret_ref
    ) {
    return v1_env_from_source_create_internal (
        config_map_ref,
        prefix,
        secret_ref
        );
}

void v1_env_from_source_free(v1_env_from_source_t *v1_env_from_source) {
    if(NULL == v1_env_from_source){
        return ;
    }
    if(v1_env_from_source->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_env_from_source_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_env_from_source->config_map_ref) {
        v1_config_map_env_source_free(v1_env_from_source->config_map_ref);
        v1_env_from_source->config_map_ref = NULL;
    }
    if (v1_env_from_source->prefix) {
        free(v1_env_from_source->prefix);
        v1_env_from_source->prefix = NULL;
    }
    if (v1_env_from_source->secret_ref) {
        v1_secret_env_source_free(v1_env_from_source->secret_ref);
        v1_env_from_source->secret_ref = NULL;
    }
    free(v1_env_from_source);
}

cJSON *v1_env_from_source_convertToJSON(v1_env_from_source_t *v1_env_from_source) {
    cJSON *item = cJSON_CreateObject();

    // v1_env_from_source->config_map_ref
    if(v1_env_from_source->config_map_ref) {
    cJSON *config_map_ref_local_JSON = v1_config_map_env_source_convertToJSON(v1_env_from_source->config_map_ref);
    if(config_map_ref_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "configMapRef", config_map_ref_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_env_from_source->prefix
    if(v1_env_from_source->prefix) {
    if(cJSON_AddStringToObject(item, "prefix", v1_env_from_source->prefix) == NULL) {
    goto fail; //String
    }
    }


    // v1_env_from_source->secret_ref
    if(v1_env_from_source->secret_ref) {
    cJSON *secret_ref_local_JSON = v1_secret_env_source_convertToJSON(v1_env_from_source->secret_ref);
    if(secret_ref_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "secretRef", secret_ref_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_env_from_source_t *v1_env_from_source_parseFromJSON(cJSON *v1_env_from_sourceJSON){

    v1_env_from_source_t *v1_env_from_source_local_var = NULL;

    // define the local variable for v1_env_from_source->config_map_ref
    v1_config_map_env_source_t *config_map_ref_local_nonprim = NULL;

    // define the local variable for v1_env_from_source->secret_ref
    v1_secret_env_source_t *secret_ref_local_nonprim = NULL;

    // v1_env_from_source->config_map_ref
    cJSON *config_map_ref = cJSON_GetObjectItemCaseSensitive(v1_env_from_sourceJSON, "configMapRef");
    if (cJSON_IsNull(config_map_ref)) {
        config_map_ref = NULL;
    }
    if (config_map_ref) { 
    config_map_ref_local_nonprim = v1_config_map_env_source_parseFromJSON(config_map_ref); //nonprimitive
    }

    // v1_env_from_source->prefix
    cJSON *prefix = cJSON_GetObjectItemCaseSensitive(v1_env_from_sourceJSON, "prefix");
    if (cJSON_IsNull(prefix)) {
        prefix = NULL;
    }
    if (prefix) { 
    if(!cJSON_IsString(prefix) && !cJSON_IsNull(prefix))
    {
    goto end; //String
    }
    }

    // v1_env_from_source->secret_ref
    cJSON *secret_ref = cJSON_GetObjectItemCaseSensitive(v1_env_from_sourceJSON, "secretRef");
    if (cJSON_IsNull(secret_ref)) {
        secret_ref = NULL;
    }
    if (secret_ref) { 
    secret_ref_local_nonprim = v1_secret_env_source_parseFromJSON(secret_ref); //nonprimitive
    }


    v1_env_from_source_local_var = v1_env_from_source_create_internal (
        config_map_ref ? config_map_ref_local_nonprim : NULL,
        prefix && !cJSON_IsNull(prefix) ? strdup(prefix->valuestring) : NULL,
        secret_ref ? secret_ref_local_nonprim : NULL
        );

    return v1_env_from_source_local_var;
end:
    if (config_map_ref_local_nonprim) {
        v1_config_map_env_source_free(config_map_ref_local_nonprim);
        config_map_ref_local_nonprim = NULL;
    }
    if (secret_ref_local_nonprim) {
        v1_secret_env_source_free(secret_ref_local_nonprim);
        secret_ref_local_nonprim = NULL;
    }
    return NULL;

}
