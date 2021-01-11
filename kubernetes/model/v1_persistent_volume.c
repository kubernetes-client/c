#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_persistent_volume.h"



v1_persistent_volume_t *v1_persistent_volume_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_persistent_volume_spec_t *spec,
    v1_persistent_volume_status_t *status
    ) {
    v1_persistent_volume_t *v1_persistent_volume_local_var = malloc(sizeof(v1_persistent_volume_t));
    if (!v1_persistent_volume_local_var) {
        return NULL;
    }
    v1_persistent_volume_local_var->api_version = api_version;
    v1_persistent_volume_local_var->kind = kind;
    v1_persistent_volume_local_var->metadata = metadata;
    v1_persistent_volume_local_var->spec = spec;
    v1_persistent_volume_local_var->status = status;

    return v1_persistent_volume_local_var;
}


void v1_persistent_volume_free(v1_persistent_volume_t *v1_persistent_volume) {
    if(NULL == v1_persistent_volume){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_persistent_volume->api_version) {
        free(v1_persistent_volume->api_version);
        v1_persistent_volume->api_version = NULL;
    }
    if (v1_persistent_volume->kind) {
        free(v1_persistent_volume->kind);
        v1_persistent_volume->kind = NULL;
    }
    if (v1_persistent_volume->metadata) {
        v1_object_meta_free(v1_persistent_volume->metadata);
        v1_persistent_volume->metadata = NULL;
    }
    if (v1_persistent_volume->spec) {
        v1_persistent_volume_spec_free(v1_persistent_volume->spec);
        v1_persistent_volume->spec = NULL;
    }
    if (v1_persistent_volume->status) {
        v1_persistent_volume_status_free(v1_persistent_volume->status);
        v1_persistent_volume->status = NULL;
    }
    free(v1_persistent_volume);
}

cJSON *v1_persistent_volume_convertToJSON(v1_persistent_volume_t *v1_persistent_volume) {
    cJSON *item = cJSON_CreateObject();

    // v1_persistent_volume->api_version
    if(v1_persistent_volume->api_version) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_persistent_volume->api_version) == NULL) {
    goto fail; //String
    }
     } 


    // v1_persistent_volume->kind
    if(v1_persistent_volume->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_persistent_volume->kind) == NULL) {
    goto fail; //String
    }
     } 


    // v1_persistent_volume->metadata
    if(v1_persistent_volume->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_persistent_volume->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_persistent_volume->spec
    if(v1_persistent_volume->spec) { 
    cJSON *spec_local_JSON = v1_persistent_volume_spec_convertToJSON(v1_persistent_volume->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_persistent_volume->status
    if(v1_persistent_volume->status) { 
    cJSON *status_local_JSON = v1_persistent_volume_status_convertToJSON(v1_persistent_volume->status);
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

v1_persistent_volume_t *v1_persistent_volume_parseFromJSON(cJSON *v1_persistent_volumeJSON){

    v1_persistent_volume_t *v1_persistent_volume_local_var = NULL;

    // v1_persistent_volume->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_persistent_volumeJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // v1_persistent_volume->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_persistent_volumeJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_persistent_volume->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_persistent_volumeJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_persistent_volume->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1_persistent_volumeJSON, "spec");
    v1_persistent_volume_spec_t *spec_local_nonprim = NULL;
    if (spec) { 
    spec_local_nonprim = v1_persistent_volume_spec_parseFromJSON(spec); //nonprimitive
    }

    // v1_persistent_volume->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1_persistent_volumeJSON, "status");
    v1_persistent_volume_status_t *status_local_nonprim = NULL;
    if (status) { 
    status_local_nonprim = v1_persistent_volume_status_parseFromJSON(status); //nonprimitive
    }


    v1_persistent_volume_local_var = v1_persistent_volume_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL,
        status ? status_local_nonprim : NULL
        );

    return v1_persistent_volume_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1_persistent_volume_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    if (status_local_nonprim) {
        v1_persistent_volume_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
