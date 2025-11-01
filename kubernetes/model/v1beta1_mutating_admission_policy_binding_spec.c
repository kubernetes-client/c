#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_mutating_admission_policy_binding_spec.h"



static v1beta1_mutating_admission_policy_binding_spec_t *v1beta1_mutating_admission_policy_binding_spec_create_internal(
    v1beta1_match_resources_t *match_resources,
    v1beta1_param_ref_t *param_ref,
    char *policy_name
    ) {
    v1beta1_mutating_admission_policy_binding_spec_t *v1beta1_mutating_admission_policy_binding_spec_local_var = malloc(sizeof(v1beta1_mutating_admission_policy_binding_spec_t));
    if (!v1beta1_mutating_admission_policy_binding_spec_local_var) {
        return NULL;
    }
    v1beta1_mutating_admission_policy_binding_spec_local_var->match_resources = match_resources;
    v1beta1_mutating_admission_policy_binding_spec_local_var->param_ref = param_ref;
    v1beta1_mutating_admission_policy_binding_spec_local_var->policy_name = policy_name;

    v1beta1_mutating_admission_policy_binding_spec_local_var->_library_owned = 1;
    return v1beta1_mutating_admission_policy_binding_spec_local_var;
}

__attribute__((deprecated)) v1beta1_mutating_admission_policy_binding_spec_t *v1beta1_mutating_admission_policy_binding_spec_create(
    v1beta1_match_resources_t *match_resources,
    v1beta1_param_ref_t *param_ref,
    char *policy_name
    ) {
    return v1beta1_mutating_admission_policy_binding_spec_create_internal (
        match_resources,
        param_ref,
        policy_name
        );
}

void v1beta1_mutating_admission_policy_binding_spec_free(v1beta1_mutating_admission_policy_binding_spec_t *v1beta1_mutating_admission_policy_binding_spec) {
    if(NULL == v1beta1_mutating_admission_policy_binding_spec){
        return ;
    }
    if(v1beta1_mutating_admission_policy_binding_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta1_mutating_admission_policy_binding_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_mutating_admission_policy_binding_spec->match_resources) {
        v1beta1_match_resources_free(v1beta1_mutating_admission_policy_binding_spec->match_resources);
        v1beta1_mutating_admission_policy_binding_spec->match_resources = NULL;
    }
    if (v1beta1_mutating_admission_policy_binding_spec->param_ref) {
        v1beta1_param_ref_free(v1beta1_mutating_admission_policy_binding_spec->param_ref);
        v1beta1_mutating_admission_policy_binding_spec->param_ref = NULL;
    }
    if (v1beta1_mutating_admission_policy_binding_spec->policy_name) {
        free(v1beta1_mutating_admission_policy_binding_spec->policy_name);
        v1beta1_mutating_admission_policy_binding_spec->policy_name = NULL;
    }
    free(v1beta1_mutating_admission_policy_binding_spec);
}

cJSON *v1beta1_mutating_admission_policy_binding_spec_convertToJSON(v1beta1_mutating_admission_policy_binding_spec_t *v1beta1_mutating_admission_policy_binding_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_mutating_admission_policy_binding_spec->match_resources
    if(v1beta1_mutating_admission_policy_binding_spec->match_resources) {
    cJSON *match_resources_local_JSON = v1beta1_match_resources_convertToJSON(v1beta1_mutating_admission_policy_binding_spec->match_resources);
    if(match_resources_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "matchResources", match_resources_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1beta1_mutating_admission_policy_binding_spec->param_ref
    if(v1beta1_mutating_admission_policy_binding_spec->param_ref) {
    cJSON *param_ref_local_JSON = v1beta1_param_ref_convertToJSON(v1beta1_mutating_admission_policy_binding_spec->param_ref);
    if(param_ref_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "paramRef", param_ref_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1beta1_mutating_admission_policy_binding_spec->policy_name
    if(v1beta1_mutating_admission_policy_binding_spec->policy_name) {
    if(cJSON_AddStringToObject(item, "policyName", v1beta1_mutating_admission_policy_binding_spec->policy_name) == NULL) {
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

v1beta1_mutating_admission_policy_binding_spec_t *v1beta1_mutating_admission_policy_binding_spec_parseFromJSON(cJSON *v1beta1_mutating_admission_policy_binding_specJSON){

    v1beta1_mutating_admission_policy_binding_spec_t *v1beta1_mutating_admission_policy_binding_spec_local_var = NULL;

    // define the local variable for v1beta1_mutating_admission_policy_binding_spec->match_resources
    v1beta1_match_resources_t *match_resources_local_nonprim = NULL;

    // define the local variable for v1beta1_mutating_admission_policy_binding_spec->param_ref
    v1beta1_param_ref_t *param_ref_local_nonprim = NULL;

    // v1beta1_mutating_admission_policy_binding_spec->match_resources
    cJSON *match_resources = cJSON_GetObjectItemCaseSensitive(v1beta1_mutating_admission_policy_binding_specJSON, "matchResources");
    if (cJSON_IsNull(match_resources)) {
        match_resources = NULL;
    }
    if (match_resources) { 
    match_resources_local_nonprim = v1beta1_match_resources_parseFromJSON(match_resources); //nonprimitive
    }

    // v1beta1_mutating_admission_policy_binding_spec->param_ref
    cJSON *param_ref = cJSON_GetObjectItemCaseSensitive(v1beta1_mutating_admission_policy_binding_specJSON, "paramRef");
    if (cJSON_IsNull(param_ref)) {
        param_ref = NULL;
    }
    if (param_ref) { 
    param_ref_local_nonprim = v1beta1_param_ref_parseFromJSON(param_ref); //nonprimitive
    }

    // v1beta1_mutating_admission_policy_binding_spec->policy_name
    cJSON *policy_name = cJSON_GetObjectItemCaseSensitive(v1beta1_mutating_admission_policy_binding_specJSON, "policyName");
    if (cJSON_IsNull(policy_name)) {
        policy_name = NULL;
    }
    if (policy_name) { 
    if(!cJSON_IsString(policy_name) && !cJSON_IsNull(policy_name))
    {
    goto end; //String
    }
    }


    v1beta1_mutating_admission_policy_binding_spec_local_var = v1beta1_mutating_admission_policy_binding_spec_create_internal (
        match_resources ? match_resources_local_nonprim : NULL,
        param_ref ? param_ref_local_nonprim : NULL,
        policy_name && !cJSON_IsNull(policy_name) ? strdup(policy_name->valuestring) : NULL
        );

    return v1beta1_mutating_admission_policy_binding_spec_local_var;
end:
    if (match_resources_local_nonprim) {
        v1beta1_match_resources_free(match_resources_local_nonprim);
        match_resources_local_nonprim = NULL;
    }
    if (param_ref_local_nonprim) {
        v1beta1_param_ref_free(param_ref_local_nonprim);
        param_ref_local_nonprim = NULL;
    }
    return NULL;

}
