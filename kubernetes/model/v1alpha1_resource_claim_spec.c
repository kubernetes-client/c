#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_resource_claim_spec.h"



v1alpha1_resource_claim_spec_t *v1alpha1_resource_claim_spec_create(
    char *allocation_mode,
    v1alpha1_resource_claim_parameters_reference_t *parameters_ref,
    char *resource_class_name
    ) {
    v1alpha1_resource_claim_spec_t *v1alpha1_resource_claim_spec_local_var = malloc(sizeof(v1alpha1_resource_claim_spec_t));
    if (!v1alpha1_resource_claim_spec_local_var) {
        return NULL;
    }
    v1alpha1_resource_claim_spec_local_var->allocation_mode = allocation_mode;
    v1alpha1_resource_claim_spec_local_var->parameters_ref = parameters_ref;
    v1alpha1_resource_claim_spec_local_var->resource_class_name = resource_class_name;

    return v1alpha1_resource_claim_spec_local_var;
}


void v1alpha1_resource_claim_spec_free(v1alpha1_resource_claim_spec_t *v1alpha1_resource_claim_spec) {
    if(NULL == v1alpha1_resource_claim_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_resource_claim_spec->allocation_mode) {
        free(v1alpha1_resource_claim_spec->allocation_mode);
        v1alpha1_resource_claim_spec->allocation_mode = NULL;
    }
    if (v1alpha1_resource_claim_spec->parameters_ref) {
        v1alpha1_resource_claim_parameters_reference_free(v1alpha1_resource_claim_spec->parameters_ref);
        v1alpha1_resource_claim_spec->parameters_ref = NULL;
    }
    if (v1alpha1_resource_claim_spec->resource_class_name) {
        free(v1alpha1_resource_claim_spec->resource_class_name);
        v1alpha1_resource_claim_spec->resource_class_name = NULL;
    }
    free(v1alpha1_resource_claim_spec);
}

cJSON *v1alpha1_resource_claim_spec_convertToJSON(v1alpha1_resource_claim_spec_t *v1alpha1_resource_claim_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_resource_claim_spec->allocation_mode
    if(v1alpha1_resource_claim_spec->allocation_mode) {
    if(cJSON_AddStringToObject(item, "allocationMode", v1alpha1_resource_claim_spec->allocation_mode) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_resource_claim_spec->parameters_ref
    if(v1alpha1_resource_claim_spec->parameters_ref) {
    cJSON *parameters_ref_local_JSON = v1alpha1_resource_claim_parameters_reference_convertToJSON(v1alpha1_resource_claim_spec->parameters_ref);
    if(parameters_ref_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "parametersRef", parameters_ref_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha1_resource_claim_spec->resource_class_name
    if (!v1alpha1_resource_claim_spec->resource_class_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "resourceClassName", v1alpha1_resource_claim_spec->resource_class_name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha1_resource_claim_spec_t *v1alpha1_resource_claim_spec_parseFromJSON(cJSON *v1alpha1_resource_claim_specJSON){

    v1alpha1_resource_claim_spec_t *v1alpha1_resource_claim_spec_local_var = NULL;

    // define the local variable for v1alpha1_resource_claim_spec->parameters_ref
    v1alpha1_resource_claim_parameters_reference_t *parameters_ref_local_nonprim = NULL;

    // v1alpha1_resource_claim_spec->allocation_mode
    cJSON *allocation_mode = cJSON_GetObjectItemCaseSensitive(v1alpha1_resource_claim_specJSON, "allocationMode");
    if (allocation_mode) { 
    if(!cJSON_IsString(allocation_mode) && !cJSON_IsNull(allocation_mode))
    {
    goto end; //String
    }
    }

    // v1alpha1_resource_claim_spec->parameters_ref
    cJSON *parameters_ref = cJSON_GetObjectItemCaseSensitive(v1alpha1_resource_claim_specJSON, "parametersRef");
    if (parameters_ref) { 
    parameters_ref_local_nonprim = v1alpha1_resource_claim_parameters_reference_parseFromJSON(parameters_ref); //nonprimitive
    }

    // v1alpha1_resource_claim_spec->resource_class_name
    cJSON *resource_class_name = cJSON_GetObjectItemCaseSensitive(v1alpha1_resource_claim_specJSON, "resourceClassName");
    if (!resource_class_name) {
        goto end;
    }

    
    if(!cJSON_IsString(resource_class_name))
    {
    goto end; //String
    }


    v1alpha1_resource_claim_spec_local_var = v1alpha1_resource_claim_spec_create (
        allocation_mode && !cJSON_IsNull(allocation_mode) ? strdup(allocation_mode->valuestring) : NULL,
        parameters_ref ? parameters_ref_local_nonprim : NULL,
        strdup(resource_class_name->valuestring)
        );

    return v1alpha1_resource_claim_spec_local_var;
end:
    if (parameters_ref_local_nonprim) {
        v1alpha1_resource_claim_parameters_reference_free(parameters_ref_local_nonprim);
        parameters_ref_local_nonprim = NULL;
    }
    return NULL;

}
