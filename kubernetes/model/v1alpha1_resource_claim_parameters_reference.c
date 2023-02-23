#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_resource_claim_parameters_reference.h"



v1alpha1_resource_claim_parameters_reference_t *v1alpha1_resource_claim_parameters_reference_create(
    char *api_group,
    char *kind,
    char *name
    ) {
    v1alpha1_resource_claim_parameters_reference_t *v1alpha1_resource_claim_parameters_reference_local_var = malloc(sizeof(v1alpha1_resource_claim_parameters_reference_t));
    if (!v1alpha1_resource_claim_parameters_reference_local_var) {
        return NULL;
    }
    v1alpha1_resource_claim_parameters_reference_local_var->api_group = api_group;
    v1alpha1_resource_claim_parameters_reference_local_var->kind = kind;
    v1alpha1_resource_claim_parameters_reference_local_var->name = name;

    return v1alpha1_resource_claim_parameters_reference_local_var;
}


void v1alpha1_resource_claim_parameters_reference_free(v1alpha1_resource_claim_parameters_reference_t *v1alpha1_resource_claim_parameters_reference) {
    if(NULL == v1alpha1_resource_claim_parameters_reference){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_resource_claim_parameters_reference->api_group) {
        free(v1alpha1_resource_claim_parameters_reference->api_group);
        v1alpha1_resource_claim_parameters_reference->api_group = NULL;
    }
    if (v1alpha1_resource_claim_parameters_reference->kind) {
        free(v1alpha1_resource_claim_parameters_reference->kind);
        v1alpha1_resource_claim_parameters_reference->kind = NULL;
    }
    if (v1alpha1_resource_claim_parameters_reference->name) {
        free(v1alpha1_resource_claim_parameters_reference->name);
        v1alpha1_resource_claim_parameters_reference->name = NULL;
    }
    free(v1alpha1_resource_claim_parameters_reference);
}

cJSON *v1alpha1_resource_claim_parameters_reference_convertToJSON(v1alpha1_resource_claim_parameters_reference_t *v1alpha1_resource_claim_parameters_reference) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_resource_claim_parameters_reference->api_group
    if(v1alpha1_resource_claim_parameters_reference->api_group) {
    if(cJSON_AddStringToObject(item, "apiGroup", v1alpha1_resource_claim_parameters_reference->api_group) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_resource_claim_parameters_reference->kind
    if (!v1alpha1_resource_claim_parameters_reference->kind) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "kind", v1alpha1_resource_claim_parameters_reference->kind) == NULL) {
    goto fail; //String
    }


    // v1alpha1_resource_claim_parameters_reference->name
    if (!v1alpha1_resource_claim_parameters_reference->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1alpha1_resource_claim_parameters_reference->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha1_resource_claim_parameters_reference_t *v1alpha1_resource_claim_parameters_reference_parseFromJSON(cJSON *v1alpha1_resource_claim_parameters_referenceJSON){

    v1alpha1_resource_claim_parameters_reference_t *v1alpha1_resource_claim_parameters_reference_local_var = NULL;

    // v1alpha1_resource_claim_parameters_reference->api_group
    cJSON *api_group = cJSON_GetObjectItemCaseSensitive(v1alpha1_resource_claim_parameters_referenceJSON, "apiGroup");
    if (api_group) { 
    if(!cJSON_IsString(api_group) && !cJSON_IsNull(api_group))
    {
    goto end; //String
    }
    }

    // v1alpha1_resource_claim_parameters_reference->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1alpha1_resource_claim_parameters_referenceJSON, "kind");
    if (!kind) {
        goto end;
    }

    
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }

    // v1alpha1_resource_claim_parameters_reference->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1alpha1_resource_claim_parameters_referenceJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }


    v1alpha1_resource_claim_parameters_reference_local_var = v1alpha1_resource_claim_parameters_reference_create (
        api_group && !cJSON_IsNull(api_group) ? strdup(api_group->valuestring) : NULL,
        strdup(kind->valuestring),
        strdup(name->valuestring)
        );

    return v1alpha1_resource_claim_parameters_reference_local_var;
end:
    return NULL;

}
