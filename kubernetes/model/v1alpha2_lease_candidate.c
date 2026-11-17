#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha2_lease_candidate.h"



static v1alpha2_lease_candidate_t *v1alpha2_lease_candidate_create_internal(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha2_lease_candidate_spec_t *spec
    ) {
    v1alpha2_lease_candidate_t *v1alpha2_lease_candidate_local_var = malloc(sizeof(v1alpha2_lease_candidate_t));
    if (!v1alpha2_lease_candidate_local_var) {
        return NULL;
    }
    memset(v1alpha2_lease_candidate_local_var, 0, sizeof(v1alpha2_lease_candidate_t));
    v1alpha2_lease_candidate_local_var->_library_owned = 1;
    v1alpha2_lease_candidate_local_var->api_version = api_version;
    v1alpha2_lease_candidate_local_var->kind = kind;
    v1alpha2_lease_candidate_local_var->metadata = metadata;
    v1alpha2_lease_candidate_local_var->spec = spec;
    return v1alpha2_lease_candidate_local_var;
}

__attribute__((deprecated)) v1alpha2_lease_candidate_t *v1alpha2_lease_candidate_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha2_lease_candidate_spec_t *spec
    ) {
    v1alpha2_lease_candidate_t *result = v1alpha2_lease_candidate_create_internal (
        api_version,
        kind,
        metadata,
        spec
        );
    if (!result) {
    }
    return result;
}

void v1alpha2_lease_candidate_free(v1alpha2_lease_candidate_t *v1alpha2_lease_candidate) {
    if(NULL == v1alpha2_lease_candidate){
        return ;
    }
    if(v1alpha2_lease_candidate->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha2_lease_candidate_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha2_lease_candidate->api_version) {
        free(v1alpha2_lease_candidate->api_version);
        v1alpha2_lease_candidate->api_version = NULL;
    }
    if (v1alpha2_lease_candidate->kind) {
        free(v1alpha2_lease_candidate->kind);
        v1alpha2_lease_candidate->kind = NULL;
    }
    if (v1alpha2_lease_candidate->metadata) {
        v1_object_meta_free(v1alpha2_lease_candidate->metadata);
        v1alpha2_lease_candidate->metadata = NULL;
    }
    if (v1alpha2_lease_candidate->spec) {
        v1alpha2_lease_candidate_spec_free(v1alpha2_lease_candidate->spec);
        v1alpha2_lease_candidate->spec = NULL;
    }
    free(v1alpha2_lease_candidate);
}

cJSON *v1alpha2_lease_candidate_convertToJSON(v1alpha2_lease_candidate_t *v1alpha2_lease_candidate) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha2_lease_candidate->api_version
    if(v1alpha2_lease_candidate->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1alpha2_lease_candidate->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha2_lease_candidate->kind
    if(v1alpha2_lease_candidate->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1alpha2_lease_candidate->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha2_lease_candidate->metadata
    if(v1alpha2_lease_candidate->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1alpha2_lease_candidate->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha2_lease_candidate->spec
    if (!v1alpha2_lease_candidate->spec) {
        goto fail;
    }
    cJSON *spec_local_JSON = v1alpha2_lease_candidate_spec_convertToJSON(v1alpha2_lease_candidate->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha2_lease_candidate_t *v1alpha2_lease_candidate_parseFromJSON(cJSON *v1alpha2_lease_candidateJSON){

    v1alpha2_lease_candidate_t *v1alpha2_lease_candidate_local_var = NULL;

    char *api_version_local_str = NULL;

    char *kind_local_str = NULL;

    // define the local variable for v1alpha2_lease_candidate->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1alpha2_lease_candidate->spec
    v1alpha2_lease_candidate_spec_t *spec_local_nonprim = NULL;

    // v1alpha2_lease_candidate->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1alpha2_lease_candidateJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1alpha2_lease_candidate->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1alpha2_lease_candidateJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1alpha2_lease_candidate->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1alpha2_lease_candidateJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1alpha2_lease_candidate->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1alpha2_lease_candidateJSON, "spec");
    if (cJSON_IsNull(spec)) {
        spec = NULL;
    }
    if (!spec) {
        goto end;
    }

    
    spec_local_nonprim = v1alpha2_lease_candidate_spec_parseFromJSON(spec); //nonprimitive


    if (api_version && !cJSON_IsNull(api_version)) api_version_local_str = strdup(api_version->valuestring);
    if (kind && !cJSON_IsNull(kind)) kind_local_str = strdup(kind->valuestring);

    v1alpha2_lease_candidate_local_var = v1alpha2_lease_candidate_create_internal (
        api_version_local_str,
        kind_local_str,
        metadata ? metadata_local_nonprim : NULL,
        spec_local_nonprim
        );

    if (!v1alpha2_lease_candidate_local_var) {
        goto end;
    }

    return v1alpha2_lease_candidate_local_var;
end:
    if (api_version_local_str) {
        free(api_version_local_str);
        api_version_local_str = NULL;
    }
    if (kind_local_str) {
        free(kind_local_str);
        kind_local_str = NULL;
    }
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1alpha2_lease_candidate_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    return NULL;

}
