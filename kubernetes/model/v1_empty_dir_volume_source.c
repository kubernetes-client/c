#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_empty_dir_volume_source.h"



v1_empty_dir_volume_source_t *v1_empty_dir_volume_source_create(
    char *medium,
    char *size_limit
    ) {
    v1_empty_dir_volume_source_t *v1_empty_dir_volume_source_local_var = malloc(sizeof(v1_empty_dir_volume_source_t));
    if (!v1_empty_dir_volume_source_local_var) {
        return NULL;
    }
    v1_empty_dir_volume_source_local_var->medium = medium;
    v1_empty_dir_volume_source_local_var->size_limit = size_limit;

    return v1_empty_dir_volume_source_local_var;
}


void v1_empty_dir_volume_source_free(v1_empty_dir_volume_source_t *v1_empty_dir_volume_source) {
    if(NULL == v1_empty_dir_volume_source){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_empty_dir_volume_source->medium) {
        free(v1_empty_dir_volume_source->medium);
        v1_empty_dir_volume_source->medium = NULL;
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

    // v1_empty_dir_volume_source->medium
    cJSON *medium = cJSON_GetObjectItemCaseSensitive(v1_empty_dir_volume_sourceJSON, "medium");
    if (medium) { 
    if(!cJSON_IsString(medium))
    {
    goto end; //String
    }
    }

    // v1_empty_dir_volume_source->size_limit
    cJSON *size_limit = cJSON_GetObjectItemCaseSensitive(v1_empty_dir_volume_sourceJSON, "sizeLimit");
    if (size_limit) { 
    if(!cJSON_IsString(size_limit))
    {
    goto end; //String
    }
    }


    v1_empty_dir_volume_source_local_var = v1_empty_dir_volume_source_create (
        medium ? strdup(medium->valuestring) : NULL,
        size_limit ? strdup(size_limit->valuestring) : NULL
        );

    return v1_empty_dir_volume_source_local_var;
end:
    return NULL;

}
