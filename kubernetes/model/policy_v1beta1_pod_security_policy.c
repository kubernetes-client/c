#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "policy_v1beta1_pod_security_policy.h"



policy_v1beta1_pod_security_policy_t *policy_v1beta1_pod_security_policy_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    policy_v1beta1_pod_security_policy_spec_t *spec
    ) {
    policy_v1beta1_pod_security_policy_t *policy_v1beta1_pod_security_policy_local_var = malloc(sizeof(policy_v1beta1_pod_security_policy_t));
    if (!policy_v1beta1_pod_security_policy_local_var) {
        return NULL;
    }
    policy_v1beta1_pod_security_policy_local_var->api_version = api_version;
    policy_v1beta1_pod_security_policy_local_var->kind = kind;
    policy_v1beta1_pod_security_policy_local_var->metadata = metadata;
    policy_v1beta1_pod_security_policy_local_var->spec = spec;

    return policy_v1beta1_pod_security_policy_local_var;
}


void policy_v1beta1_pod_security_policy_free(policy_v1beta1_pod_security_policy_t *policy_v1beta1_pod_security_policy) {
    if(NULL == policy_v1beta1_pod_security_policy){
        return ;
    }
    listEntry_t *listEntry;
    if (policy_v1beta1_pod_security_policy->api_version) {
        free(policy_v1beta1_pod_security_policy->api_version);
        policy_v1beta1_pod_security_policy->api_version = NULL;
    }
    if (policy_v1beta1_pod_security_policy->kind) {
        free(policy_v1beta1_pod_security_policy->kind);
        policy_v1beta1_pod_security_policy->kind = NULL;
    }
    if (policy_v1beta1_pod_security_policy->metadata) {
        v1_object_meta_free(policy_v1beta1_pod_security_policy->metadata);
        policy_v1beta1_pod_security_policy->metadata = NULL;
    }
    if (policy_v1beta1_pod_security_policy->spec) {
        policy_v1beta1_pod_security_policy_spec_free(policy_v1beta1_pod_security_policy->spec);
        policy_v1beta1_pod_security_policy->spec = NULL;
    }
    free(policy_v1beta1_pod_security_policy);
}

cJSON *policy_v1beta1_pod_security_policy_convertToJSON(policy_v1beta1_pod_security_policy_t *policy_v1beta1_pod_security_policy) {
    cJSON *item = cJSON_CreateObject();

    // policy_v1beta1_pod_security_policy->api_version
    if(policy_v1beta1_pod_security_policy->api_version) { 
    if(cJSON_AddStringToObject(item, "apiVersion", policy_v1beta1_pod_security_policy->api_version) == NULL) {
    goto fail; //String
    }
     } 


    // policy_v1beta1_pod_security_policy->kind
    if(policy_v1beta1_pod_security_policy->kind) { 
    if(cJSON_AddStringToObject(item, "kind", policy_v1beta1_pod_security_policy->kind) == NULL) {
    goto fail; //String
    }
     } 


    // policy_v1beta1_pod_security_policy->metadata
    if(policy_v1beta1_pod_security_policy->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(policy_v1beta1_pod_security_policy->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // policy_v1beta1_pod_security_policy->spec
    if(policy_v1beta1_pod_security_policy->spec) { 
    cJSON *spec_local_JSON = policy_v1beta1_pod_security_policy_spec_convertToJSON(policy_v1beta1_pod_security_policy->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
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

policy_v1beta1_pod_security_policy_t *policy_v1beta1_pod_security_policy_parseFromJSON(cJSON *policy_v1beta1_pod_security_policyJSON){

    policy_v1beta1_pod_security_policy_t *policy_v1beta1_pod_security_policy_local_var = NULL;

    // policy_v1beta1_pod_security_policy->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_pod_security_policyJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // policy_v1beta1_pod_security_policy->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_pod_security_policyJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // policy_v1beta1_pod_security_policy->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_pod_security_policyJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // policy_v1beta1_pod_security_policy->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_pod_security_policyJSON, "spec");
    policy_v1beta1_pod_security_policy_spec_t *spec_local_nonprim = NULL;
    if (spec) { 
    spec_local_nonprim = policy_v1beta1_pod_security_policy_spec_parseFromJSON(spec); //nonprimitive
    }


    policy_v1beta1_pod_security_policy_local_var = policy_v1beta1_pod_security_policy_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL
        );

    return policy_v1beta1_pod_security_policy_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        policy_v1beta1_pod_security_policy_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    return NULL;

}
