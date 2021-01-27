#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod.h"



v1_pod_t *v1_pod_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_pod_spec_t *spec,
    v1_pod_status_t *status
    ) {
    v1_pod_t *v1_pod_local_var = malloc(sizeof(v1_pod_t));
    if (!v1_pod_local_var) {
        return NULL;
    }
    v1_pod_local_var->api_version = api_version;
    v1_pod_local_var->kind = kind;
    v1_pod_local_var->metadata = metadata;
    v1_pod_local_var->spec = spec;
    v1_pod_local_var->status = status;

    return v1_pod_local_var;
}


void v1_pod_free(v1_pod_t *v1_pod) {
    if(NULL == v1_pod){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_pod->api_version) {
        free(v1_pod->api_version);
        v1_pod->api_version = NULL;
    }
    if (v1_pod->kind) {
        free(v1_pod->kind);
        v1_pod->kind = NULL;
    }
    if (v1_pod->metadata) {
        v1_object_meta_free(v1_pod->metadata);
        v1_pod->metadata = NULL;
    }
    if (v1_pod->spec) {
        v1_pod_spec_free(v1_pod->spec);
        v1_pod->spec = NULL;
    }
    if (v1_pod->status) {
        v1_pod_status_free(v1_pod->status);
        v1_pod->status = NULL;
    }
    free(v1_pod);
}

cJSON *v1_pod_convertToJSON(v1_pod_t *v1_pod) {
    cJSON *item = cJSON_CreateObject();

    // v1_pod->api_version
    if(v1_pod->api_version) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_pod->api_version) == NULL) {
    goto fail; //String
    }
     } 


    // v1_pod->kind
    if(v1_pod->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_pod->kind) == NULL) {
    goto fail; //String
    }
     } 


    // v1_pod->metadata
    if(v1_pod->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_pod->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_pod->spec
    if(v1_pod->spec) { 
    cJSON *spec_local_JSON = v1_pod_spec_convertToJSON(v1_pod->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_pod->status
    if(v1_pod->status) { 
    cJSON *status_local_JSON = v1_pod_status_convertToJSON(v1_pod->status);
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

v1_pod_t *v1_pod_parseFromJSON(cJSON *v1_podJSON){

    v1_pod_t *v1_pod_local_var = NULL;

    // v1_pod->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_podJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // v1_pod->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_podJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_pod->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_podJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_pod->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1_podJSON, "spec");
    v1_pod_spec_t *spec_local_nonprim = NULL;
    if (spec) { 
    spec_local_nonprim = v1_pod_spec_parseFromJSON(spec); //nonprimitive
    }

    // v1_pod->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1_podJSON, "status");
    v1_pod_status_t *status_local_nonprim = NULL;
    if (status) { 
    status_local_nonprim = v1_pod_status_parseFromJSON(status); //nonprimitive
    }


    v1_pod_local_var = v1_pod_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL,
        status ? status_local_nonprim : NULL
        );

    return v1_pod_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1_pod_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    if (status_local_nonprim) {
        v1_pod_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
