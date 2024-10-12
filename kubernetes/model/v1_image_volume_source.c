#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_image_volume_source.h"



v1_image_volume_source_t *v1_image_volume_source_create(
    char *pull_policy,
    char *reference
    ) {
    v1_image_volume_source_t *v1_image_volume_source_local_var = malloc(sizeof(v1_image_volume_source_t));
    if (!v1_image_volume_source_local_var) {
        return NULL;
    }
    v1_image_volume_source_local_var->pull_policy = pull_policy;
    v1_image_volume_source_local_var->reference = reference;

    return v1_image_volume_source_local_var;
}


void v1_image_volume_source_free(v1_image_volume_source_t *v1_image_volume_source) {
    if(NULL == v1_image_volume_source){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_image_volume_source->pull_policy) {
        free(v1_image_volume_source->pull_policy);
        v1_image_volume_source->pull_policy = NULL;
    }
    if (v1_image_volume_source->reference) {
        free(v1_image_volume_source->reference);
        v1_image_volume_source->reference = NULL;
    }
    free(v1_image_volume_source);
}

cJSON *v1_image_volume_source_convertToJSON(v1_image_volume_source_t *v1_image_volume_source) {
    cJSON *item = cJSON_CreateObject();

    // v1_image_volume_source->pull_policy
    if(v1_image_volume_source->pull_policy) {
    if(cJSON_AddStringToObject(item, "pullPolicy", v1_image_volume_source->pull_policy) == NULL) {
    goto fail; //String
    }
    }


    // v1_image_volume_source->reference
    if(v1_image_volume_source->reference) {
    if(cJSON_AddStringToObject(item, "reference", v1_image_volume_source->reference) == NULL) {
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

v1_image_volume_source_t *v1_image_volume_source_parseFromJSON(cJSON *v1_image_volume_sourceJSON){

    v1_image_volume_source_t *v1_image_volume_source_local_var = NULL;

    // v1_image_volume_source->pull_policy
    cJSON *pull_policy = cJSON_GetObjectItemCaseSensitive(v1_image_volume_sourceJSON, "pullPolicy");
    if (pull_policy) { 
    if(!cJSON_IsString(pull_policy) && !cJSON_IsNull(pull_policy))
    {
    goto end; //String
    }
    }

    // v1_image_volume_source->reference
    cJSON *reference = cJSON_GetObjectItemCaseSensitive(v1_image_volume_sourceJSON, "reference");
    if (reference) { 
    if(!cJSON_IsString(reference) && !cJSON_IsNull(reference))
    {
    goto end; //String
    }
    }


    v1_image_volume_source_local_var = v1_image_volume_source_create (
        pull_policy && !cJSON_IsNull(pull_policy) ? strdup(pull_policy->valuestring) : NULL,
        reference && !cJSON_IsNull(reference) ? strdup(reference->valuestring) : NULL
        );

    return v1_image_volume_source_local_var;
end:
    return NULL;

}
