#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_horizontal_pod_autoscaler.h"



static v1_horizontal_pod_autoscaler_t *v1_horizontal_pod_autoscaler_create_internal(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_horizontal_pod_autoscaler_spec_t *spec,
    v1_horizontal_pod_autoscaler_status_t *status
    ) {
    v1_horizontal_pod_autoscaler_t *v1_horizontal_pod_autoscaler_local_var = malloc(sizeof(v1_horizontal_pod_autoscaler_t));
    if (!v1_horizontal_pod_autoscaler_local_var) {
        return NULL;
    }
    memset(v1_horizontal_pod_autoscaler_local_var, 0, sizeof(v1_horizontal_pod_autoscaler_t));
    v1_horizontal_pod_autoscaler_local_var->_library_owned = 1;
    v1_horizontal_pod_autoscaler_local_var->api_version = api_version;
    v1_horizontal_pod_autoscaler_local_var->kind = kind;
    v1_horizontal_pod_autoscaler_local_var->metadata = metadata;
    v1_horizontal_pod_autoscaler_local_var->spec = spec;
    v1_horizontal_pod_autoscaler_local_var->status = status;
    return v1_horizontal_pod_autoscaler_local_var;
}

__attribute__((deprecated)) v1_horizontal_pod_autoscaler_t *v1_horizontal_pod_autoscaler_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_horizontal_pod_autoscaler_spec_t *spec,
    v1_horizontal_pod_autoscaler_status_t *status
    ) {
    v1_horizontal_pod_autoscaler_t *result = v1_horizontal_pod_autoscaler_create_internal (
        api_version,
        kind,
        metadata,
        spec,
        status
        );
    if (!result) {
    }
    return result;
}

void v1_horizontal_pod_autoscaler_free(v1_horizontal_pod_autoscaler_t *v1_horizontal_pod_autoscaler) {
    if(NULL == v1_horizontal_pod_autoscaler){
        return ;
    }
    if(v1_horizontal_pod_autoscaler->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_horizontal_pod_autoscaler_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_horizontal_pod_autoscaler->api_version) {
        free(v1_horizontal_pod_autoscaler->api_version);
        v1_horizontal_pod_autoscaler->api_version = NULL;
    }
    if (v1_horizontal_pod_autoscaler->kind) {
        free(v1_horizontal_pod_autoscaler->kind);
        v1_horizontal_pod_autoscaler->kind = NULL;
    }
    if (v1_horizontal_pod_autoscaler->metadata) {
        v1_object_meta_free(v1_horizontal_pod_autoscaler->metadata);
        v1_horizontal_pod_autoscaler->metadata = NULL;
    }
    if (v1_horizontal_pod_autoscaler->spec) {
        v1_horizontal_pod_autoscaler_spec_free(v1_horizontal_pod_autoscaler->spec);
        v1_horizontal_pod_autoscaler->spec = NULL;
    }
    if (v1_horizontal_pod_autoscaler->status) {
        v1_horizontal_pod_autoscaler_status_free(v1_horizontal_pod_autoscaler->status);
        v1_horizontal_pod_autoscaler->status = NULL;
    }
    free(v1_horizontal_pod_autoscaler);
}

cJSON *v1_horizontal_pod_autoscaler_convertToJSON(v1_horizontal_pod_autoscaler_t *v1_horizontal_pod_autoscaler) {
    cJSON *item = cJSON_CreateObject();

    // v1_horizontal_pod_autoscaler->api_version
    if(v1_horizontal_pod_autoscaler->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1_horizontal_pod_autoscaler->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_horizontal_pod_autoscaler->kind
    if(v1_horizontal_pod_autoscaler->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1_horizontal_pod_autoscaler->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_horizontal_pod_autoscaler->metadata
    if(v1_horizontal_pod_autoscaler->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_horizontal_pod_autoscaler->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_horizontal_pod_autoscaler->spec
    if (!v1_horizontal_pod_autoscaler->spec) {
        goto fail;
    }
    cJSON *spec_local_JSON = v1_horizontal_pod_autoscaler_spec_convertToJSON(v1_horizontal_pod_autoscaler->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1_horizontal_pod_autoscaler->status
    if(v1_horizontal_pod_autoscaler->status) {
    cJSON *status_local_JSON = v1_horizontal_pod_autoscaler_status_convertToJSON(v1_horizontal_pod_autoscaler->status);
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

v1_horizontal_pod_autoscaler_t *v1_horizontal_pod_autoscaler_parseFromJSON(cJSON *v1_horizontal_pod_autoscalerJSON){

    v1_horizontal_pod_autoscaler_t *v1_horizontal_pod_autoscaler_local_var = NULL;

    char *api_version_local_str = NULL;

    char *kind_local_str = NULL;

    // define the local variable for v1_horizontal_pod_autoscaler->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1_horizontal_pod_autoscaler->spec
    v1_horizontal_pod_autoscaler_spec_t *spec_local_nonprim = NULL;

    // define the local variable for v1_horizontal_pod_autoscaler->status
    v1_horizontal_pod_autoscaler_status_t *status_local_nonprim = NULL;

    // v1_horizontal_pod_autoscaler->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_horizontal_pod_autoscalerJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_horizontal_pod_autoscaler->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_horizontal_pod_autoscalerJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_horizontal_pod_autoscaler->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_horizontal_pod_autoscalerJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_horizontal_pod_autoscaler->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1_horizontal_pod_autoscalerJSON, "spec");
    if (cJSON_IsNull(spec)) {
        spec = NULL;
    }
    if (!spec) {
        goto end;
    }

    
    spec_local_nonprim = v1_horizontal_pod_autoscaler_spec_parseFromJSON(spec); //nonprimitive

    // v1_horizontal_pod_autoscaler->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1_horizontal_pod_autoscalerJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    status_local_nonprim = v1_horizontal_pod_autoscaler_status_parseFromJSON(status); //nonprimitive
    }


    if (api_version && !cJSON_IsNull(api_version)) api_version_local_str = strdup(api_version->valuestring);
    if (kind && !cJSON_IsNull(kind)) kind_local_str = strdup(kind->valuestring);

    v1_horizontal_pod_autoscaler_local_var = v1_horizontal_pod_autoscaler_create_internal (
        api_version_local_str,
        kind_local_str,
        metadata ? metadata_local_nonprim : NULL,
        spec_local_nonprim,
        status ? status_local_nonprim : NULL
        );

    if (!v1_horizontal_pod_autoscaler_local_var) {
        goto end;
    }

    return v1_horizontal_pod_autoscaler_local_var;
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
        v1_horizontal_pod_autoscaler_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    if (status_local_nonprim) {
        v1_horizontal_pod_autoscaler_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
