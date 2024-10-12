#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_resource_claim.h"



v1alpha3_resource_claim_t *v1alpha3_resource_claim_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha3_resource_claim_spec_t *spec,
    v1alpha3_resource_claim_status_t *status
    ) {
    v1alpha3_resource_claim_t *v1alpha3_resource_claim_local_var = malloc(sizeof(v1alpha3_resource_claim_t));
    if (!v1alpha3_resource_claim_local_var) {
        return NULL;
    }
    v1alpha3_resource_claim_local_var->api_version = api_version;
    v1alpha3_resource_claim_local_var->kind = kind;
    v1alpha3_resource_claim_local_var->metadata = metadata;
    v1alpha3_resource_claim_local_var->spec = spec;
    v1alpha3_resource_claim_local_var->status = status;

    return v1alpha3_resource_claim_local_var;
}


void v1alpha3_resource_claim_free(v1alpha3_resource_claim_t *v1alpha3_resource_claim) {
    if(NULL == v1alpha3_resource_claim){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_resource_claim->api_version) {
        free(v1alpha3_resource_claim->api_version);
        v1alpha3_resource_claim->api_version = NULL;
    }
    if (v1alpha3_resource_claim->kind) {
        free(v1alpha3_resource_claim->kind);
        v1alpha3_resource_claim->kind = NULL;
    }
    if (v1alpha3_resource_claim->metadata) {
        v1_object_meta_free(v1alpha3_resource_claim->metadata);
        v1alpha3_resource_claim->metadata = NULL;
    }
    if (v1alpha3_resource_claim->spec) {
        v1alpha3_resource_claim_spec_free(v1alpha3_resource_claim->spec);
        v1alpha3_resource_claim->spec = NULL;
    }
    if (v1alpha3_resource_claim->status) {
        v1alpha3_resource_claim_status_free(v1alpha3_resource_claim->status);
        v1alpha3_resource_claim->status = NULL;
    }
    free(v1alpha3_resource_claim);
}

cJSON *v1alpha3_resource_claim_convertToJSON(v1alpha3_resource_claim_t *v1alpha3_resource_claim) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_resource_claim->api_version
    if(v1alpha3_resource_claim->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1alpha3_resource_claim->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha3_resource_claim->kind
    if(v1alpha3_resource_claim->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1alpha3_resource_claim->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha3_resource_claim->metadata
    if(v1alpha3_resource_claim->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1alpha3_resource_claim->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha3_resource_claim->spec
    if (!v1alpha3_resource_claim->spec) {
        goto fail;
    }
    cJSON *spec_local_JSON = v1alpha3_resource_claim_spec_convertToJSON(v1alpha3_resource_claim->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1alpha3_resource_claim->status
    if(v1alpha3_resource_claim->status) {
    cJSON *status_local_JSON = v1alpha3_resource_claim_status_convertToJSON(v1alpha3_resource_claim->status);
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

v1alpha3_resource_claim_t *v1alpha3_resource_claim_parseFromJSON(cJSON *v1alpha3_resource_claimJSON){

    v1alpha3_resource_claim_t *v1alpha3_resource_claim_local_var = NULL;

    // define the local variable for v1alpha3_resource_claim->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1alpha3_resource_claim->spec
    v1alpha3_resource_claim_spec_t *spec_local_nonprim = NULL;

    // define the local variable for v1alpha3_resource_claim->status
    v1alpha3_resource_claim_status_t *status_local_nonprim = NULL;

    // v1alpha3_resource_claim->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_claimJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1alpha3_resource_claim->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_claimJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1alpha3_resource_claim->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_claimJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1alpha3_resource_claim->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_claimJSON, "spec");
    if (!spec) {
        goto end;
    }

    
    spec_local_nonprim = v1alpha3_resource_claim_spec_parseFromJSON(spec); //nonprimitive

    // v1alpha3_resource_claim->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_claimJSON, "status");
    if (status) { 
    status_local_nonprim = v1alpha3_resource_claim_status_parseFromJSON(status); //nonprimitive
    }


    v1alpha3_resource_claim_local_var = v1alpha3_resource_claim_create (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec_local_nonprim,
        status ? status_local_nonprim : NULL
        );

    return v1alpha3_resource_claim_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1alpha3_resource_claim_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    if (status_local_nonprim) {
        v1alpha3_resource_claim_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
