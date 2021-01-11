#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_token_request.h"



v1_token_request_t *v1_token_request_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_token_request_spec_t *spec,
    v1_token_request_status_t *status
    ) {
    v1_token_request_t *v1_token_request_local_var = malloc(sizeof(v1_token_request_t));
    if (!v1_token_request_local_var) {
        return NULL;
    }
    v1_token_request_local_var->api_version = api_version;
    v1_token_request_local_var->kind = kind;
    v1_token_request_local_var->metadata = metadata;
    v1_token_request_local_var->spec = spec;
    v1_token_request_local_var->status = status;

    return v1_token_request_local_var;
}


void v1_token_request_free(v1_token_request_t *v1_token_request) {
    if(NULL == v1_token_request){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_token_request->api_version) {
        free(v1_token_request->api_version);
        v1_token_request->api_version = NULL;
    }
    if (v1_token_request->kind) {
        free(v1_token_request->kind);
        v1_token_request->kind = NULL;
    }
    if (v1_token_request->metadata) {
        v1_object_meta_free(v1_token_request->metadata);
        v1_token_request->metadata = NULL;
    }
    if (v1_token_request->spec) {
        v1_token_request_spec_free(v1_token_request->spec);
        v1_token_request->spec = NULL;
    }
    if (v1_token_request->status) {
        v1_token_request_status_free(v1_token_request->status);
        v1_token_request->status = NULL;
    }
    free(v1_token_request);
}

cJSON *v1_token_request_convertToJSON(v1_token_request_t *v1_token_request) {
    cJSON *item = cJSON_CreateObject();

    // v1_token_request->api_version
    if(v1_token_request->api_version) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_token_request->api_version) == NULL) {
    goto fail; //String
    }
     } 


    // v1_token_request->kind
    if(v1_token_request->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_token_request->kind) == NULL) {
    goto fail; //String
    }
     } 


    // v1_token_request->metadata
    if(v1_token_request->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_token_request->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_token_request->spec
    if (!v1_token_request->spec) {
        goto fail;
    }
    
    cJSON *spec_local_JSON = v1_token_request_spec_convertToJSON(v1_token_request->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1_token_request->status
    if(v1_token_request->status) { 
    cJSON *status_local_JSON = v1_token_request_status_convertToJSON(v1_token_request->status);
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

v1_token_request_t *v1_token_request_parseFromJSON(cJSON *v1_token_requestJSON){

    v1_token_request_t *v1_token_request_local_var = NULL;

    // v1_token_request->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_token_requestJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // v1_token_request->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_token_requestJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_token_request->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_token_requestJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_token_request->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1_token_requestJSON, "spec");
    if (!spec) {
        goto end;
    }

    v1_token_request_spec_t *spec_local_nonprim = NULL;
    
    spec_local_nonprim = v1_token_request_spec_parseFromJSON(spec); //nonprimitive

    // v1_token_request->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1_token_requestJSON, "status");
    v1_token_request_status_t *status_local_nonprim = NULL;
    if (status) { 
    status_local_nonprim = v1_token_request_status_parseFromJSON(status); //nonprimitive
    }


    v1_token_request_local_var = v1_token_request_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec_local_nonprim,
        status ? status_local_nonprim : NULL
        );

    return v1_token_request_local_var;
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
