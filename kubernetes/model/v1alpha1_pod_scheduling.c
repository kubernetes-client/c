#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_pod_scheduling.h"



v1alpha1_pod_scheduling_t *v1alpha1_pod_scheduling_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha1_pod_scheduling_spec_t *spec,
    v1alpha1_pod_scheduling_status_t *status
    ) {
    v1alpha1_pod_scheduling_t *v1alpha1_pod_scheduling_local_var = malloc(sizeof(v1alpha1_pod_scheduling_t));
    if (!v1alpha1_pod_scheduling_local_var) {
        return NULL;
    }
    v1alpha1_pod_scheduling_local_var->api_version = api_version;
    v1alpha1_pod_scheduling_local_var->kind = kind;
    v1alpha1_pod_scheduling_local_var->metadata = metadata;
    v1alpha1_pod_scheduling_local_var->spec = spec;
    v1alpha1_pod_scheduling_local_var->status = status;

    return v1alpha1_pod_scheduling_local_var;
}


void v1alpha1_pod_scheduling_free(v1alpha1_pod_scheduling_t *v1alpha1_pod_scheduling) {
    if(NULL == v1alpha1_pod_scheduling){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_pod_scheduling->api_version) {
        free(v1alpha1_pod_scheduling->api_version);
        v1alpha1_pod_scheduling->api_version = NULL;
    }
    if (v1alpha1_pod_scheduling->kind) {
        free(v1alpha1_pod_scheduling->kind);
        v1alpha1_pod_scheduling->kind = NULL;
    }
    if (v1alpha1_pod_scheduling->metadata) {
        v1_object_meta_free(v1alpha1_pod_scheduling->metadata);
        v1alpha1_pod_scheduling->metadata = NULL;
    }
    if (v1alpha1_pod_scheduling->spec) {
        v1alpha1_pod_scheduling_spec_free(v1alpha1_pod_scheduling->spec);
        v1alpha1_pod_scheduling->spec = NULL;
    }
    if (v1alpha1_pod_scheduling->status) {
        v1alpha1_pod_scheduling_status_free(v1alpha1_pod_scheduling->status);
        v1alpha1_pod_scheduling->status = NULL;
    }
    free(v1alpha1_pod_scheduling);
}

cJSON *v1alpha1_pod_scheduling_convertToJSON(v1alpha1_pod_scheduling_t *v1alpha1_pod_scheduling) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_pod_scheduling->api_version
    if(v1alpha1_pod_scheduling->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1alpha1_pod_scheduling->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_pod_scheduling->kind
    if(v1alpha1_pod_scheduling->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1alpha1_pod_scheduling->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha1_pod_scheduling->metadata
    if(v1alpha1_pod_scheduling->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1alpha1_pod_scheduling->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha1_pod_scheduling->spec
    if (!v1alpha1_pod_scheduling->spec) {
        goto fail;
    }
    cJSON *spec_local_JSON = v1alpha1_pod_scheduling_spec_convertToJSON(v1alpha1_pod_scheduling->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1alpha1_pod_scheduling->status
    if(v1alpha1_pod_scheduling->status) {
    cJSON *status_local_JSON = v1alpha1_pod_scheduling_status_convertToJSON(v1alpha1_pod_scheduling->status);
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

v1alpha1_pod_scheduling_t *v1alpha1_pod_scheduling_parseFromJSON(cJSON *v1alpha1_pod_schedulingJSON){

    v1alpha1_pod_scheduling_t *v1alpha1_pod_scheduling_local_var = NULL;

    // define the local variable for v1alpha1_pod_scheduling->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1alpha1_pod_scheduling->spec
    v1alpha1_pod_scheduling_spec_t *spec_local_nonprim = NULL;

    // define the local variable for v1alpha1_pod_scheduling->status
    v1alpha1_pod_scheduling_status_t *status_local_nonprim = NULL;

    // v1alpha1_pod_scheduling->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1alpha1_pod_schedulingJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1alpha1_pod_scheduling->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1alpha1_pod_schedulingJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1alpha1_pod_scheduling->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1alpha1_pod_schedulingJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1alpha1_pod_scheduling->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1alpha1_pod_schedulingJSON, "spec");
    if (!spec) {
        goto end;
    }

    
    spec_local_nonprim = v1alpha1_pod_scheduling_spec_parseFromJSON(spec); //nonprimitive

    // v1alpha1_pod_scheduling->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1alpha1_pod_schedulingJSON, "status");
    if (status) { 
    status_local_nonprim = v1alpha1_pod_scheduling_status_parseFromJSON(status); //nonprimitive
    }


    v1alpha1_pod_scheduling_local_var = v1alpha1_pod_scheduling_create (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec_local_nonprim,
        status ? status_local_nonprim : NULL
        );

    return v1alpha1_pod_scheduling_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1alpha1_pod_scheduling_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    if (status_local_nonprim) {
        v1alpha1_pod_scheduling_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
