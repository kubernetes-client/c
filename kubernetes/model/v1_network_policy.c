#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_network_policy.h"



static v1_network_policy_t *v1_network_policy_create_internal(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_network_policy_spec_t *spec
    ) {
    v1_network_policy_t *v1_network_policy_local_var = malloc(sizeof(v1_network_policy_t));
    if (!v1_network_policy_local_var) {
        return NULL;
    }
    v1_network_policy_local_var->api_version = api_version;
    v1_network_policy_local_var->kind = kind;
    v1_network_policy_local_var->metadata = metadata;
    v1_network_policy_local_var->spec = spec;

    v1_network_policy_local_var->_library_owned = 1;
    return v1_network_policy_local_var;
}

__attribute__((deprecated)) v1_network_policy_t *v1_network_policy_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_network_policy_spec_t *spec
    ) {
    return v1_network_policy_create_internal (
        api_version,
        kind,
        metadata,
        spec
        );
}

void v1_network_policy_free(v1_network_policy_t *v1_network_policy) {
    if(NULL == v1_network_policy){
        return ;
    }
    if(v1_network_policy->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_network_policy_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_network_policy->api_version) {
        free(v1_network_policy->api_version);
        v1_network_policy->api_version = NULL;
    }
    if (v1_network_policy->kind) {
        free(v1_network_policy->kind);
        v1_network_policy->kind = NULL;
    }
    if (v1_network_policy->metadata) {
        v1_object_meta_free(v1_network_policy->metadata);
        v1_network_policy->metadata = NULL;
    }
    if (v1_network_policy->spec) {
        v1_network_policy_spec_free(v1_network_policy->spec);
        v1_network_policy->spec = NULL;
    }
    free(v1_network_policy);
}

cJSON *v1_network_policy_convertToJSON(v1_network_policy_t *v1_network_policy) {
    cJSON *item = cJSON_CreateObject();

    // v1_network_policy->api_version
    if(v1_network_policy->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1_network_policy->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_network_policy->kind
    if(v1_network_policy->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1_network_policy->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_network_policy->metadata
    if(v1_network_policy->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_network_policy->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_network_policy->spec
    if(v1_network_policy->spec) {
    cJSON *spec_local_JSON = v1_network_policy_spec_convertToJSON(v1_network_policy->spec);
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

v1_network_policy_t *v1_network_policy_parseFromJSON(cJSON *v1_network_policyJSON){

    v1_network_policy_t *v1_network_policy_local_var = NULL;

    // define the local variable for v1_network_policy->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1_network_policy->spec
    v1_network_policy_spec_t *spec_local_nonprim = NULL;

    // v1_network_policy->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_network_policyJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_network_policy->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_network_policyJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_network_policy->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_network_policyJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_network_policy->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1_network_policyJSON, "spec");
    if (cJSON_IsNull(spec)) {
        spec = NULL;
    }
    if (spec) { 
    spec_local_nonprim = v1_network_policy_spec_parseFromJSON(spec); //nonprimitive
    }


    v1_network_policy_local_var = v1_network_policy_create_internal (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL
        );

    return v1_network_policy_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1_network_policy_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    return NULL;

}
