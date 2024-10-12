#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_lease_candidate.h"



v1alpha1_lease_candidate_t *v1alpha1_lease_candidate_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha1_lease_candidate_spec_t *spec
    ) {
    v1alpha1_lease_candidate_t *v1alpha1_lease_candidate_local_var = malloc(sizeof(v1alpha1_lease_candidate_t));
    if (!v1alpha1_lease_candidate_local_var) {
        return NULL;
    }
    v1alpha1_lease_candidate_local_var->api_version = api_version;
    v1alpha1_lease_candidate_local_var->kind = kind;
    v1alpha1_lease_candidate_local_var->metadata = metadata;
    v1alpha1_lease_candidate_local_var->spec = spec;

    return v1alpha1_lease_candidate_local_var;
}


void v1alpha1_lease_candidate_free(v1alpha1_lease_candidate_t *v1alpha1_lease_candidate) {
    if(NULL == v1alpha1_lease_candidate){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_lease_candidate->api_version) {
        free(v1alpha1_lease_candidate->api_version);
        v1alpha1_lease_candidate->api_version = NULL;
    }
    if (v1alpha1_lease_candidate->kind) {
        free(v1alpha1_lease_candidate->kind);
        v1alpha1_lease_candidate->kind = NULL;
    }
    if (v1alpha1_lease_candidate->metadata) {
        v1_object_meta_free(v1alpha1_lease_candidate->metadata);
        v1alpha1_lease_candidate->metadata = NULL;
    }
    if (v1alpha1_lease_candidate->spec) {
        v1alpha1_lease_candidate_spec_free(v1alpha1_lease_candidate->spec);
        v1alpha1_lease_candidate->spec = NULL;
    }
    free(v1alpha1_lease_candidate);
}

cJSON *v1alpha1_lease_candidate_convertToJSON(v1alpha1_lease_candidate_t *v1alpha1_lease_candidate) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_lease_candidate->api_version
    if(v1alpha1_lease_candidate->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1alpha1_lease_candidate->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_lease_candidate->kind
    if(v1alpha1_lease_candidate->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1alpha1_lease_candidate->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_lease_candidate->metadata
    if(v1alpha1_lease_candidate->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1alpha1_lease_candidate->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha1_lease_candidate->spec
    if(v1alpha1_lease_candidate->spec) {
    cJSON *spec_local_JSON = v1alpha1_lease_candidate_spec_convertToJSON(v1alpha1_lease_candidate->spec);
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

v1alpha1_lease_candidate_t *v1alpha1_lease_candidate_parseFromJSON(cJSON *v1alpha1_lease_candidateJSON){

    v1alpha1_lease_candidate_t *v1alpha1_lease_candidate_local_var = NULL;

    // define the local variable for v1alpha1_lease_candidate->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1alpha1_lease_candidate->spec
    v1alpha1_lease_candidate_spec_t *spec_local_nonprim = NULL;

    // v1alpha1_lease_candidate->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1alpha1_lease_candidateJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1alpha1_lease_candidate->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1alpha1_lease_candidateJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1alpha1_lease_candidate->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1alpha1_lease_candidateJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1alpha1_lease_candidate->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1alpha1_lease_candidateJSON, "spec");
    if (spec) { 
    spec_local_nonprim = v1alpha1_lease_candidate_spec_parseFromJSON(spec); //nonprimitive
    }


    v1alpha1_lease_candidate_local_var = v1alpha1_lease_candidate_create (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL
        );

    return v1alpha1_lease_candidate_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1alpha1_lease_candidate_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    return NULL;

}
