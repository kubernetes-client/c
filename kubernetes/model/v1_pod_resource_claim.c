#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_resource_claim.h"



v1_pod_resource_claim_t *v1_pod_resource_claim_create(
    char *name,
    char *resource_claim_name,
    char *resource_claim_template_name
    ) {
    v1_pod_resource_claim_t *v1_pod_resource_claim_local_var = malloc(sizeof(v1_pod_resource_claim_t));
    if (!v1_pod_resource_claim_local_var) {
        return NULL;
    }
    v1_pod_resource_claim_local_var->name = name;
    v1_pod_resource_claim_local_var->resource_claim_name = resource_claim_name;
    v1_pod_resource_claim_local_var->resource_claim_template_name = resource_claim_template_name;

    return v1_pod_resource_claim_local_var;
}


void v1_pod_resource_claim_free(v1_pod_resource_claim_t *v1_pod_resource_claim) {
    if(NULL == v1_pod_resource_claim){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_pod_resource_claim->name) {
        free(v1_pod_resource_claim->name);
        v1_pod_resource_claim->name = NULL;
    }
    if (v1_pod_resource_claim->resource_claim_name) {
        free(v1_pod_resource_claim->resource_claim_name);
        v1_pod_resource_claim->resource_claim_name = NULL;
    }
    if (v1_pod_resource_claim->resource_claim_template_name) {
        free(v1_pod_resource_claim->resource_claim_template_name);
        v1_pod_resource_claim->resource_claim_template_name = NULL;
    }
    free(v1_pod_resource_claim);
}

cJSON *v1_pod_resource_claim_convertToJSON(v1_pod_resource_claim_t *v1_pod_resource_claim) {
    cJSON *item = cJSON_CreateObject();

    // v1_pod_resource_claim->name
    if (!v1_pod_resource_claim->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1_pod_resource_claim->name) == NULL) {
    goto fail; //String
    }


    // v1_pod_resource_claim->resource_claim_name
    if(v1_pod_resource_claim->resource_claim_name) {
    if(cJSON_AddStringToObject(item, "resourceClaimName", v1_pod_resource_claim->resource_claim_name) == NULL) {
    goto fail; //String
    }
    }


    // v1_pod_resource_claim->resource_claim_template_name
    if(v1_pod_resource_claim->resource_claim_template_name) {
    if(cJSON_AddStringToObject(item, "resourceClaimTemplateName", v1_pod_resource_claim->resource_claim_template_name) == NULL) {
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

v1_pod_resource_claim_t *v1_pod_resource_claim_parseFromJSON(cJSON *v1_pod_resource_claimJSON){

    v1_pod_resource_claim_t *v1_pod_resource_claim_local_var = NULL;

    // v1_pod_resource_claim->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_pod_resource_claimJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_pod_resource_claim->resource_claim_name
    cJSON *resource_claim_name = cJSON_GetObjectItemCaseSensitive(v1_pod_resource_claimJSON, "resourceClaimName");
    if (resource_claim_name) { 
    if(!cJSON_IsString(resource_claim_name) && !cJSON_IsNull(resource_claim_name))
    {
    goto end; //String
    }
    }

    // v1_pod_resource_claim->resource_claim_template_name
    cJSON *resource_claim_template_name = cJSON_GetObjectItemCaseSensitive(v1_pod_resource_claimJSON, "resourceClaimTemplateName");
    if (resource_claim_template_name) { 
    if(!cJSON_IsString(resource_claim_template_name) && !cJSON_IsNull(resource_claim_template_name))
    {
    goto end; //String
    }
    }


    v1_pod_resource_claim_local_var = v1_pod_resource_claim_create (
        strdup(name->valuestring),
        resource_claim_name && !cJSON_IsNull(resource_claim_name) ? strdup(resource_claim_name->valuestring) : NULL,
        resource_claim_template_name && !cJSON_IsNull(resource_claim_template_name) ? strdup(resource_claim_template_name->valuestring) : NULL
        );

    return v1_pod_resource_claim_local_var;
end:
    return NULL;

}
