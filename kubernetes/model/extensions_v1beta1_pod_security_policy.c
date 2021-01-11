#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extensions_v1beta1_pod_security_policy.h"



extensions_v1beta1_pod_security_policy_t *extensions_v1beta1_pod_security_policy_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    extensions_v1beta1_pod_security_policy_spec_t *spec
    ) {
    extensions_v1beta1_pod_security_policy_t *extensions_v1beta1_pod_security_policy_local_var = malloc(sizeof(extensions_v1beta1_pod_security_policy_t));
    if (!extensions_v1beta1_pod_security_policy_local_var) {
        return NULL;
    }
    extensions_v1beta1_pod_security_policy_local_var->api_version = api_version;
    extensions_v1beta1_pod_security_policy_local_var->kind = kind;
    extensions_v1beta1_pod_security_policy_local_var->metadata = metadata;
    extensions_v1beta1_pod_security_policy_local_var->spec = spec;

    return extensions_v1beta1_pod_security_policy_local_var;
}


void extensions_v1beta1_pod_security_policy_free(extensions_v1beta1_pod_security_policy_t *extensions_v1beta1_pod_security_policy) {
    if(NULL == extensions_v1beta1_pod_security_policy){
        return ;
    }
    listEntry_t *listEntry;
    if (extensions_v1beta1_pod_security_policy->api_version) {
        free(extensions_v1beta1_pod_security_policy->api_version);
        extensions_v1beta1_pod_security_policy->api_version = NULL;
    }
    if (extensions_v1beta1_pod_security_policy->kind) {
        free(extensions_v1beta1_pod_security_policy->kind);
        extensions_v1beta1_pod_security_policy->kind = NULL;
    }
    if (extensions_v1beta1_pod_security_policy->metadata) {
        v1_object_meta_free(extensions_v1beta1_pod_security_policy->metadata);
        extensions_v1beta1_pod_security_policy->metadata = NULL;
    }
    if (extensions_v1beta1_pod_security_policy->spec) {
        extensions_v1beta1_pod_security_policy_spec_free(extensions_v1beta1_pod_security_policy->spec);
        extensions_v1beta1_pod_security_policy->spec = NULL;
    }
    free(extensions_v1beta1_pod_security_policy);
}

cJSON *extensions_v1beta1_pod_security_policy_convertToJSON(extensions_v1beta1_pod_security_policy_t *extensions_v1beta1_pod_security_policy) {
    cJSON *item = cJSON_CreateObject();

    // extensions_v1beta1_pod_security_policy->api_version
    if(extensions_v1beta1_pod_security_policy->api_version) { 
    if(cJSON_AddStringToObject(item, "apiVersion", extensions_v1beta1_pod_security_policy->api_version) == NULL) {
    goto fail; //String
    }
     } 


    // extensions_v1beta1_pod_security_policy->kind
    if(extensions_v1beta1_pod_security_policy->kind) { 
    if(cJSON_AddStringToObject(item, "kind", extensions_v1beta1_pod_security_policy->kind) == NULL) {
    goto fail; //String
    }
     } 


    // extensions_v1beta1_pod_security_policy->metadata
    if(extensions_v1beta1_pod_security_policy->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(extensions_v1beta1_pod_security_policy->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // extensions_v1beta1_pod_security_policy->spec
    if(extensions_v1beta1_pod_security_policy->spec) { 
    cJSON *spec_local_JSON = extensions_v1beta1_pod_security_policy_spec_convertToJSON(extensions_v1beta1_pod_security_policy->spec);
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

extensions_v1beta1_pod_security_policy_t *extensions_v1beta1_pod_security_policy_parseFromJSON(cJSON *extensions_v1beta1_pod_security_policyJSON){

    extensions_v1beta1_pod_security_policy_t *extensions_v1beta1_pod_security_policy_local_var = NULL;

    // extensions_v1beta1_pod_security_policy->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_pod_security_policyJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // extensions_v1beta1_pod_security_policy->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_pod_security_policyJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // extensions_v1beta1_pod_security_policy->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_pod_security_policyJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // extensions_v1beta1_pod_security_policy->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_pod_security_policyJSON, "spec");
    extensions_v1beta1_pod_security_policy_spec_t *spec_local_nonprim = NULL;
    if (spec) { 
    spec_local_nonprim = extensions_v1beta1_pod_security_policy_spec_parseFromJSON(spec); //nonprimitive
    }


    extensions_v1beta1_pod_security_policy_local_var = extensions_v1beta1_pod_security_policy_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL
        );

    return extensions_v1beta1_pod_security_policy_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        extensions_v1beta1_pod_security_policy_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    return NULL;

}
