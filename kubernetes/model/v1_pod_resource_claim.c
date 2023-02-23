#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_resource_claim.h"



v1_pod_resource_claim_t *v1_pod_resource_claim_create(
    char *name,
    v1_claim_source_t *source
    ) {
    v1_pod_resource_claim_t *v1_pod_resource_claim_local_var = malloc(sizeof(v1_pod_resource_claim_t));
    if (!v1_pod_resource_claim_local_var) {
        return NULL;
    }
    v1_pod_resource_claim_local_var->name = name;
    v1_pod_resource_claim_local_var->source = source;

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
    if (v1_pod_resource_claim->source) {
        v1_claim_source_free(v1_pod_resource_claim->source);
        v1_pod_resource_claim->source = NULL;
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


    // v1_pod_resource_claim->source
    if(v1_pod_resource_claim->source) {
    cJSON *source_local_JSON = v1_claim_source_convertToJSON(v1_pod_resource_claim->source);
    if(source_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "source", source_local_JSON);
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

v1_pod_resource_claim_t *v1_pod_resource_claim_parseFromJSON(cJSON *v1_pod_resource_claimJSON){

    v1_pod_resource_claim_t *v1_pod_resource_claim_local_var = NULL;

    // define the local variable for v1_pod_resource_claim->source
    v1_claim_source_t *source_local_nonprim = NULL;

    // v1_pod_resource_claim->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_pod_resource_claimJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_pod_resource_claim->source
    cJSON *source = cJSON_GetObjectItemCaseSensitive(v1_pod_resource_claimJSON, "source");
    if (source) { 
    source_local_nonprim = v1_claim_source_parseFromJSON(source); //nonprimitive
    }


    v1_pod_resource_claim_local_var = v1_pod_resource_claim_create (
        strdup(name->valuestring),
        source ? source_local_nonprim : NULL
        );

    return v1_pod_resource_claim_local_var;
end:
    if (source_local_nonprim) {
        v1_claim_source_free(source_local_nonprim);
        source_local_nonprim = NULL;
    }
    return NULL;

}
