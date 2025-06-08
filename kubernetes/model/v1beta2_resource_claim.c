#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_resource_claim.h"



static v1beta2_resource_claim_t *v1beta2_resource_claim_create_internal(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta2_resource_claim_spec_t *spec,
    v1beta2_resource_claim_status_t *status
    ) {
    v1beta2_resource_claim_t *v1beta2_resource_claim_local_var = malloc(sizeof(v1beta2_resource_claim_t));
    if (!v1beta2_resource_claim_local_var) {
        return NULL;
    }
    v1beta2_resource_claim_local_var->api_version = api_version;
    v1beta2_resource_claim_local_var->kind = kind;
    v1beta2_resource_claim_local_var->metadata = metadata;
    v1beta2_resource_claim_local_var->spec = spec;
    v1beta2_resource_claim_local_var->status = status;

    v1beta2_resource_claim_local_var->_library_owned = 1;
    return v1beta2_resource_claim_local_var;
}

__attribute__((deprecated)) v1beta2_resource_claim_t *v1beta2_resource_claim_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta2_resource_claim_spec_t *spec,
    v1beta2_resource_claim_status_t *status
    ) {
    return v1beta2_resource_claim_create_internal (
        api_version,
        kind,
        metadata,
        spec,
        status
        );
}

void v1beta2_resource_claim_free(v1beta2_resource_claim_t *v1beta2_resource_claim) {
    if(NULL == v1beta2_resource_claim){
        return ;
    }
    if(v1beta2_resource_claim->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta2_resource_claim_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta2_resource_claim->api_version) {
        free(v1beta2_resource_claim->api_version);
        v1beta2_resource_claim->api_version = NULL;
    }
    if (v1beta2_resource_claim->kind) {
        free(v1beta2_resource_claim->kind);
        v1beta2_resource_claim->kind = NULL;
    }
    if (v1beta2_resource_claim->metadata) {
        v1_object_meta_free(v1beta2_resource_claim->metadata);
        v1beta2_resource_claim->metadata = NULL;
    }
    if (v1beta2_resource_claim->spec) {
        v1beta2_resource_claim_spec_free(v1beta2_resource_claim->spec);
        v1beta2_resource_claim->spec = NULL;
    }
    if (v1beta2_resource_claim->status) {
        v1beta2_resource_claim_status_free(v1beta2_resource_claim->status);
        v1beta2_resource_claim->status = NULL;
    }
    free(v1beta2_resource_claim);
}

cJSON *v1beta2_resource_claim_convertToJSON(v1beta2_resource_claim_t *v1beta2_resource_claim) {
    cJSON *item = cJSON_CreateObject();

    // v1beta2_resource_claim->api_version
    if(v1beta2_resource_claim->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1beta2_resource_claim->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1beta2_resource_claim->kind
    if(v1beta2_resource_claim->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1beta2_resource_claim->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1beta2_resource_claim->metadata
    if(v1beta2_resource_claim->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1beta2_resource_claim->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1beta2_resource_claim->spec
    if (!v1beta2_resource_claim->spec) {
        goto fail;
    }
    cJSON *spec_local_JSON = v1beta2_resource_claim_spec_convertToJSON(v1beta2_resource_claim->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1beta2_resource_claim->status
    if(v1beta2_resource_claim->status) {
    cJSON *status_local_JSON = v1beta2_resource_claim_status_convertToJSON(v1beta2_resource_claim->status);
    if(status_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
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

v1beta2_resource_claim_t *v1beta2_resource_claim_parseFromJSON(cJSON *v1beta2_resource_claimJSON){

    v1beta2_resource_claim_t *v1beta2_resource_claim_local_var = NULL;

    // define the local variable for v1beta2_resource_claim->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1beta2_resource_claim->spec
    v1beta2_resource_claim_spec_t *spec_local_nonprim = NULL;

    // define the local variable for v1beta2_resource_claim->status
    v1beta2_resource_claim_status_t *status_local_nonprim = NULL;

    // v1beta2_resource_claim->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1beta2_resource_claimJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1beta2_resource_claim->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1beta2_resource_claimJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1beta2_resource_claim->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1beta2_resource_claimJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1beta2_resource_claim->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1beta2_resource_claimJSON, "spec");
    if (cJSON_IsNull(spec)) {
        spec = NULL;
    }
    if (!spec) {
        goto end;
    }

    
    spec_local_nonprim = v1beta2_resource_claim_spec_parseFromJSON(spec); //nonprimitive

    // v1beta2_resource_claim->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1beta2_resource_claimJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    status_local_nonprim = v1beta2_resource_claim_status_parseFromJSON(status); //nonprimitive
    }


    v1beta2_resource_claim_local_var = v1beta2_resource_claim_create_internal (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec_local_nonprim,
        status ? status_local_nonprim : NULL
        );

    return v1beta2_resource_claim_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1beta2_resource_claim_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    if (status_local_nonprim) {
        v1beta2_resource_claim_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
