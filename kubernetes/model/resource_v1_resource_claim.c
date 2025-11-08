#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "resource_v1_resource_claim.h"



static resource_v1_resource_claim_t *resource_v1_resource_claim_create_internal(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_resource_claim_spec_t *spec,
    v1_resource_claim_status_t *status
    ) {
    resource_v1_resource_claim_t *resource_v1_resource_claim_local_var = malloc(sizeof(resource_v1_resource_claim_t));
    if (!resource_v1_resource_claim_local_var) {
        return NULL;
    }
    resource_v1_resource_claim_local_var->api_version = api_version;
    resource_v1_resource_claim_local_var->kind = kind;
    resource_v1_resource_claim_local_var->metadata = metadata;
    resource_v1_resource_claim_local_var->spec = spec;
    resource_v1_resource_claim_local_var->status = status;

    resource_v1_resource_claim_local_var->_library_owned = 1;
    return resource_v1_resource_claim_local_var;
}

__attribute__((deprecated)) resource_v1_resource_claim_t *resource_v1_resource_claim_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_resource_claim_spec_t *spec,
    v1_resource_claim_status_t *status
    ) {
    return resource_v1_resource_claim_create_internal (
        api_version,
        kind,
        metadata,
        spec,
        status
        );
}

void resource_v1_resource_claim_free(resource_v1_resource_claim_t *resource_v1_resource_claim) {
    if(NULL == resource_v1_resource_claim){
        return ;
    }
    if(resource_v1_resource_claim->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "resource_v1_resource_claim_free");
        return ;
    }
    listEntry_t *listEntry;
    if (resource_v1_resource_claim->api_version) {
        free(resource_v1_resource_claim->api_version);
        resource_v1_resource_claim->api_version = NULL;
    }
    if (resource_v1_resource_claim->kind) {
        free(resource_v1_resource_claim->kind);
        resource_v1_resource_claim->kind = NULL;
    }
    if (resource_v1_resource_claim->metadata) {
        v1_object_meta_free(resource_v1_resource_claim->metadata);
        resource_v1_resource_claim->metadata = NULL;
    }
    if (resource_v1_resource_claim->spec) {
        v1_resource_claim_spec_free(resource_v1_resource_claim->spec);
        resource_v1_resource_claim->spec = NULL;
    }
    if (resource_v1_resource_claim->status) {
        v1_resource_claim_status_free(resource_v1_resource_claim->status);
        resource_v1_resource_claim->status = NULL;
    }
    free(resource_v1_resource_claim);
}

cJSON *resource_v1_resource_claim_convertToJSON(resource_v1_resource_claim_t *resource_v1_resource_claim) {
    cJSON *item = cJSON_CreateObject();

    // resource_v1_resource_claim->api_version
    if(resource_v1_resource_claim->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", resource_v1_resource_claim->api_version) == NULL) {
    goto fail; //String
    }
    }


    // resource_v1_resource_claim->kind
    if(resource_v1_resource_claim->kind) {
    if(cJSON_AddStringToObject(item, "kind", resource_v1_resource_claim->kind) == NULL) {
    goto fail; //String
    }
    }


    // resource_v1_resource_claim->metadata
    if(resource_v1_resource_claim->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(resource_v1_resource_claim->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // resource_v1_resource_claim->spec
    if (!resource_v1_resource_claim->spec) {
        goto fail;
    }
    cJSON *spec_local_JSON = v1_resource_claim_spec_convertToJSON(resource_v1_resource_claim->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // resource_v1_resource_claim->status
    if(resource_v1_resource_claim->status) {
    cJSON *status_local_JSON = v1_resource_claim_status_convertToJSON(resource_v1_resource_claim->status);
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

resource_v1_resource_claim_t *resource_v1_resource_claim_parseFromJSON(cJSON *resource_v1_resource_claimJSON){

    resource_v1_resource_claim_t *resource_v1_resource_claim_local_var = NULL;

    // define the local variable for resource_v1_resource_claim->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for resource_v1_resource_claim->spec
    v1_resource_claim_spec_t *spec_local_nonprim = NULL;

    // define the local variable for resource_v1_resource_claim->status
    v1_resource_claim_status_t *status_local_nonprim = NULL;

    // resource_v1_resource_claim->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(resource_v1_resource_claimJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // resource_v1_resource_claim->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(resource_v1_resource_claimJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // resource_v1_resource_claim->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(resource_v1_resource_claimJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // resource_v1_resource_claim->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(resource_v1_resource_claimJSON, "spec");
    if (cJSON_IsNull(spec)) {
        spec = NULL;
    }
    if (!spec) {
        goto end;
    }

    
    spec_local_nonprim = v1_resource_claim_spec_parseFromJSON(spec); //nonprimitive

    // resource_v1_resource_claim->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(resource_v1_resource_claimJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    status_local_nonprim = v1_resource_claim_status_parseFromJSON(status); //nonprimitive
    }


    resource_v1_resource_claim_local_var = resource_v1_resource_claim_create_internal (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec_local_nonprim,
        status ? status_local_nonprim : NULL
        );

    return resource_v1_resource_claim_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1_resource_claim_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    if (status_local_nonprim) {
        v1_resource_claim_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
