#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_pod_scheduling_context.h"



v1alpha3_pod_scheduling_context_t *v1alpha3_pod_scheduling_context_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha3_pod_scheduling_context_spec_t *spec,
    v1alpha3_pod_scheduling_context_status_t *status
    ) {
    v1alpha3_pod_scheduling_context_t *v1alpha3_pod_scheduling_context_local_var = malloc(sizeof(v1alpha3_pod_scheduling_context_t));
    if (!v1alpha3_pod_scheduling_context_local_var) {
        return NULL;
    }
    v1alpha3_pod_scheduling_context_local_var->api_version = api_version;
    v1alpha3_pod_scheduling_context_local_var->kind = kind;
    v1alpha3_pod_scheduling_context_local_var->metadata = metadata;
    v1alpha3_pod_scheduling_context_local_var->spec = spec;
    v1alpha3_pod_scheduling_context_local_var->status = status;

    return v1alpha3_pod_scheduling_context_local_var;
}


void v1alpha3_pod_scheduling_context_free(v1alpha3_pod_scheduling_context_t *v1alpha3_pod_scheduling_context) {
    if(NULL == v1alpha3_pod_scheduling_context){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_pod_scheduling_context->api_version) {
        free(v1alpha3_pod_scheduling_context->api_version);
        v1alpha3_pod_scheduling_context->api_version = NULL;
    }
    if (v1alpha3_pod_scheduling_context->kind) {
        free(v1alpha3_pod_scheduling_context->kind);
        v1alpha3_pod_scheduling_context->kind = NULL;
    }
    if (v1alpha3_pod_scheduling_context->metadata) {
        v1_object_meta_free(v1alpha3_pod_scheduling_context->metadata);
        v1alpha3_pod_scheduling_context->metadata = NULL;
    }
    if (v1alpha3_pod_scheduling_context->spec) {
        v1alpha3_pod_scheduling_context_spec_free(v1alpha3_pod_scheduling_context->spec);
        v1alpha3_pod_scheduling_context->spec = NULL;
    }
    if (v1alpha3_pod_scheduling_context->status) {
        v1alpha3_pod_scheduling_context_status_free(v1alpha3_pod_scheduling_context->status);
        v1alpha3_pod_scheduling_context->status = NULL;
    }
    free(v1alpha3_pod_scheduling_context);
}

cJSON *v1alpha3_pod_scheduling_context_convertToJSON(v1alpha3_pod_scheduling_context_t *v1alpha3_pod_scheduling_context) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_pod_scheduling_context->api_version
    if(v1alpha3_pod_scheduling_context->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1alpha3_pod_scheduling_context->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha3_pod_scheduling_context->kind
    if(v1alpha3_pod_scheduling_context->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1alpha3_pod_scheduling_context->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha3_pod_scheduling_context->metadata
    if(v1alpha3_pod_scheduling_context->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1alpha3_pod_scheduling_context->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha3_pod_scheduling_context->spec
    if (!v1alpha3_pod_scheduling_context->spec) {
        goto fail;
    }
    cJSON *spec_local_JSON = v1alpha3_pod_scheduling_context_spec_convertToJSON(v1alpha3_pod_scheduling_context->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1alpha3_pod_scheduling_context->status
    if(v1alpha3_pod_scheduling_context->status) {
    cJSON *status_local_JSON = v1alpha3_pod_scheduling_context_status_convertToJSON(v1alpha3_pod_scheduling_context->status);
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

v1alpha3_pod_scheduling_context_t *v1alpha3_pod_scheduling_context_parseFromJSON(cJSON *v1alpha3_pod_scheduling_contextJSON){

    v1alpha3_pod_scheduling_context_t *v1alpha3_pod_scheduling_context_local_var = NULL;

    // define the local variable for v1alpha3_pod_scheduling_context->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1alpha3_pod_scheduling_context->spec
    v1alpha3_pod_scheduling_context_spec_t *spec_local_nonprim = NULL;

    // define the local variable for v1alpha3_pod_scheduling_context->status
    v1alpha3_pod_scheduling_context_status_t *status_local_nonprim = NULL;

    // v1alpha3_pod_scheduling_context->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1alpha3_pod_scheduling_contextJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1alpha3_pod_scheduling_context->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1alpha3_pod_scheduling_contextJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1alpha3_pod_scheduling_context->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1alpha3_pod_scheduling_contextJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1alpha3_pod_scheduling_context->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1alpha3_pod_scheduling_contextJSON, "spec");
    if (!spec) {
        goto end;
    }

    
    spec_local_nonprim = v1alpha3_pod_scheduling_context_spec_parseFromJSON(spec); //nonprimitive

    // v1alpha3_pod_scheduling_context->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1alpha3_pod_scheduling_contextJSON, "status");
    if (status) { 
    status_local_nonprim = v1alpha3_pod_scheduling_context_status_parseFromJSON(status); //nonprimitive
    }


    v1alpha3_pod_scheduling_context_local_var = v1alpha3_pod_scheduling_context_create (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec_local_nonprim,
        status ? status_local_nonprim : NULL
        );

    return v1alpha3_pod_scheduling_context_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1alpha3_pod_scheduling_context_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    if (status_local_nonprim) {
        v1alpha3_pod_scheduling_context_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
