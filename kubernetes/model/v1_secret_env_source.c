#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_secret_env_source.h"



v1_secret_env_source_t *v1_secret_env_source_create(
    char *name,
    int optional
    ) {
    v1_secret_env_source_t *v1_secret_env_source_local_var = malloc(sizeof(v1_secret_env_source_t));
    if (!v1_secret_env_source_local_var) {
        return NULL;
    }
    v1_secret_env_source_local_var->name = name;
    v1_secret_env_source_local_var->optional = optional;

    return v1_secret_env_source_local_var;
}


void v1_secret_env_source_free(v1_secret_env_source_t *v1_secret_env_source) {
    if(NULL == v1_secret_env_source){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_secret_env_source->name) {
        free(v1_secret_env_source->name);
        v1_secret_env_source->name = NULL;
    }
    free(v1_secret_env_source);
}

cJSON *v1_secret_env_source_convertToJSON(v1_secret_env_source_t *v1_secret_env_source) {
    cJSON *item = cJSON_CreateObject();

    // v1_secret_env_source->name
    if(v1_secret_env_source->name) { 
    if(cJSON_AddStringToObject(item, "name", v1_secret_env_source->name) == NULL) {
    goto fail; //String
    }
     } 


    // v1_secret_env_source->optional
    if(v1_secret_env_source->optional) { 
    if(cJSON_AddBoolToObject(item, "optional", v1_secret_env_source->optional) == NULL) {
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

v1_secret_env_source_t *v1_secret_env_source_parseFromJSON(cJSON *v1_secret_env_sourceJSON){

    v1_secret_env_source_t *v1_secret_env_source_local_var = NULL;

    // v1_secret_env_source->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_secret_env_sourceJSON, "name");
    if (name) { 
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }
    }

    // v1_secret_env_source->optional
    cJSON *optional = cJSON_GetObjectItemCaseSensitive(v1_secret_env_sourceJSON, "optional");
    if (optional) { 
    if(!cJSON_IsBool(optional))
    {
    goto end; //Bool
    }
    }


    v1_secret_env_source_local_var = v1_secret_env_source_create (
        name ? strdup(name->valuestring) : NULL,
        optional ? optional->valueint : 0
        );

    return v1_secret_env_source_local_var;
end:
    return NULL;

}
