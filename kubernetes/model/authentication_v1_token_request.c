#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "authentication_v1_token_request.h"



static authentication_v1_token_request_t *authentication_v1_token_request_create_internal(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_token_request_spec_t *spec,
    v1_token_request_status_t *status
    ) {
    authentication_v1_token_request_t *authentication_v1_token_request_local_var = malloc(sizeof(authentication_v1_token_request_t));
    if (!authentication_v1_token_request_local_var) {
        return NULL;
    }
    authentication_v1_token_request_local_var->api_version = api_version;
    authentication_v1_token_request_local_var->kind = kind;
    authentication_v1_token_request_local_var->metadata = metadata;
    authentication_v1_token_request_local_var->spec = spec;
    authentication_v1_token_request_local_var->status = status;

    authentication_v1_token_request_local_var->_library_owned = 1;
    return authentication_v1_token_request_local_var;
}

__attribute__((deprecated)) authentication_v1_token_request_t *authentication_v1_token_request_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_token_request_spec_t *spec,
    v1_token_request_status_t *status
    ) {
    return authentication_v1_token_request_create_internal (
        api_version,
        kind,
        metadata,
        spec,
        status
        );
}

void authentication_v1_token_request_free(authentication_v1_token_request_t *authentication_v1_token_request) {
    if(NULL == authentication_v1_token_request){
        return ;
    }
    if(authentication_v1_token_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "authentication_v1_token_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (authentication_v1_token_request->api_version) {
        free(authentication_v1_token_request->api_version);
        authentication_v1_token_request->api_version = NULL;
    }
    if (authentication_v1_token_request->kind) {
        free(authentication_v1_token_request->kind);
        authentication_v1_token_request->kind = NULL;
    }
    if (authentication_v1_token_request->metadata) {
        v1_object_meta_free(authentication_v1_token_request->metadata);
        authentication_v1_token_request->metadata = NULL;
    }
    if (authentication_v1_token_request->spec) {
        v1_token_request_spec_free(authentication_v1_token_request->spec);
        authentication_v1_token_request->spec = NULL;
    }
    if (authentication_v1_token_request->status) {
        v1_token_request_status_free(authentication_v1_token_request->status);
        authentication_v1_token_request->status = NULL;
    }
    free(authentication_v1_token_request);
}

cJSON *authentication_v1_token_request_convertToJSON(authentication_v1_token_request_t *authentication_v1_token_request) {
    cJSON *item = cJSON_CreateObject();

    // authentication_v1_token_request->api_version
    if(authentication_v1_token_request->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", authentication_v1_token_request->api_version) == NULL) {
    goto fail; //String
    }
    }


    // authentication_v1_token_request->kind
    if(authentication_v1_token_request->kind) {
    if(cJSON_AddStringToObject(item, "kind", authentication_v1_token_request->kind) == NULL) {
    goto fail; //String
    }
    }


    // authentication_v1_token_request->metadata
    if(authentication_v1_token_request->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(authentication_v1_token_request->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // authentication_v1_token_request->spec
    if (!authentication_v1_token_request->spec) {
        goto fail;
    }
    cJSON *spec_local_JSON = v1_token_request_spec_convertToJSON(authentication_v1_token_request->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // authentication_v1_token_request->status
    if(authentication_v1_token_request->status) {
    cJSON *status_local_JSON = v1_token_request_status_convertToJSON(authentication_v1_token_request->status);
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

authentication_v1_token_request_t *authentication_v1_token_request_parseFromJSON(cJSON *authentication_v1_token_requestJSON){

    authentication_v1_token_request_t *authentication_v1_token_request_local_var = NULL;

    // define the local variable for authentication_v1_token_request->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for authentication_v1_token_request->spec
    v1_token_request_spec_t *spec_local_nonprim = NULL;

    // define the local variable for authentication_v1_token_request->status
    v1_token_request_status_t *status_local_nonprim = NULL;

    // authentication_v1_token_request->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(authentication_v1_token_requestJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // authentication_v1_token_request->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(authentication_v1_token_requestJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // authentication_v1_token_request->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(authentication_v1_token_requestJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // authentication_v1_token_request->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(authentication_v1_token_requestJSON, "spec");
    if (cJSON_IsNull(spec)) {
        spec = NULL;
    }
    if (!spec) {
        goto end;
    }

    
    spec_local_nonprim = v1_token_request_spec_parseFromJSON(spec); //nonprimitive

    // authentication_v1_token_request->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(authentication_v1_token_requestJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    status_local_nonprim = v1_token_request_status_parseFromJSON(status); //nonprimitive
    }


    authentication_v1_token_request_local_var = authentication_v1_token_request_create_internal (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec_local_nonprim,
        status ? status_local_nonprim : NULL
        );

    return authentication_v1_token_request_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1_token_request_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    if (status_local_nonprim) {
        v1_token_request_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
