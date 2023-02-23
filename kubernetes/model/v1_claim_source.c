#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_claim_source.h"



v1_claim_source_t *v1_claim_source_create(
    char *resource_claim_name,
    char *resource_claim_template_name
    ) {
    v1_claim_source_t *v1_claim_source_local_var = malloc(sizeof(v1_claim_source_t));
    if (!v1_claim_source_local_var) {
        return NULL;
    }
    v1_claim_source_local_var->resource_claim_name = resource_claim_name;
    v1_claim_source_local_var->resource_claim_template_name = resource_claim_template_name;

    return v1_claim_source_local_var;
}


void v1_claim_source_free(v1_claim_source_t *v1_claim_source) {
    if(NULL == v1_claim_source){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_claim_source->resource_claim_name) {
        free(v1_claim_source->resource_claim_name);
        v1_claim_source->resource_claim_name = NULL;
    }
    if (v1_claim_source->resource_claim_template_name) {
        free(v1_claim_source->resource_claim_template_name);
        v1_claim_source->resource_claim_template_name = NULL;
    }
    free(v1_claim_source);
}

cJSON *v1_claim_source_convertToJSON(v1_claim_source_t *v1_claim_source) {
    cJSON *item = cJSON_CreateObject();

    // v1_claim_source->resource_claim_name
    if(v1_claim_source->resource_claim_name) {
    if(cJSON_AddStringToObject(item, "resourceClaimName", v1_claim_source->resource_claim_name) == NULL) {
    goto fail; //String
    }
    }


    // v1_claim_source->resource_claim_template_name
    if(v1_claim_source->resource_claim_template_name) {
    if(cJSON_AddStringToObject(item, "resourceClaimTemplateName", v1_claim_source->resource_claim_template_name) == NULL) {
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

v1_claim_source_t *v1_claim_source_parseFromJSON(cJSON *v1_claim_sourceJSON){

    v1_claim_source_t *v1_claim_source_local_var = NULL;

    // v1_claim_source->resource_claim_name
    cJSON *resource_claim_name = cJSON_GetObjectItemCaseSensitive(v1_claim_sourceJSON, "resourceClaimName");
    if (resource_claim_name) { 
    if(!cJSON_IsString(resource_claim_name) && !cJSON_IsNull(resource_claim_name))
    {
    goto end; //String
    }
    }

    // v1_claim_source->resource_claim_template_name
    cJSON *resource_claim_template_name = cJSON_GetObjectItemCaseSensitive(v1_claim_sourceJSON, "resourceClaimTemplateName");
    if (resource_claim_template_name) { 
    if(!cJSON_IsString(resource_claim_template_name) && !cJSON_IsNull(resource_claim_template_name))
    {
    goto end; //String
    }
    }


    v1_claim_source_local_var = v1_claim_source_create (
        resource_claim_name && !cJSON_IsNull(resource_claim_name) ? strdup(resource_claim_name->valuestring) : NULL,
        resource_claim_template_name && !cJSON_IsNull(resource_claim_template_name) ? strdup(resource_claim_template_name->valuestring) : NULL
        );

    return v1_claim_source_local_var;
end:
    return NULL;

}
