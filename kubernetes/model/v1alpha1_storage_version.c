#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_storage_version.h"



v1alpha1_storage_version_t *v1alpha1_storage_version_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    object_t *spec,
    v1alpha1_storage_version_status_t *status
    ) {
    v1alpha1_storage_version_t *v1alpha1_storage_version_local_var = malloc(sizeof(v1alpha1_storage_version_t));
    if (!v1alpha1_storage_version_local_var) {
        return NULL;
    }
    v1alpha1_storage_version_local_var->api_version = api_version;
    v1alpha1_storage_version_local_var->kind = kind;
    v1alpha1_storage_version_local_var->metadata = metadata;
    v1alpha1_storage_version_local_var->spec = spec;
    v1alpha1_storage_version_local_var->status = status;

    return v1alpha1_storage_version_local_var;
}


void v1alpha1_storage_version_free(v1alpha1_storage_version_t *v1alpha1_storage_version) {
    if(NULL == v1alpha1_storage_version){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_storage_version->api_version) {
        free(v1alpha1_storage_version->api_version);
        v1alpha1_storage_version->api_version = NULL;
    }
    if (v1alpha1_storage_version->kind) {
        free(v1alpha1_storage_version->kind);
        v1alpha1_storage_version->kind = NULL;
    }
    if (v1alpha1_storage_version->metadata) {
        v1_object_meta_free(v1alpha1_storage_version->metadata);
        v1alpha1_storage_version->metadata = NULL;
    }
    if (v1alpha1_storage_version->spec) {
        object_free(v1alpha1_storage_version->spec);
        v1alpha1_storage_version->spec = NULL;
    }
    if (v1alpha1_storage_version->status) {
        v1alpha1_storage_version_status_free(v1alpha1_storage_version->status);
        v1alpha1_storage_version->status = NULL;
    }
    free(v1alpha1_storage_version);
}

cJSON *v1alpha1_storage_version_convertToJSON(v1alpha1_storage_version_t *v1alpha1_storage_version) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_storage_version->api_version
    if(v1alpha1_storage_version->api_version) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1alpha1_storage_version->api_version) == NULL) {
    goto fail; //String
    }
     } 


    // v1alpha1_storage_version->kind
    if(v1alpha1_storage_version->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1alpha1_storage_version->kind) == NULL) {
    goto fail; //String
    }
     } 


    // v1alpha1_storage_version->metadata
    if(v1alpha1_storage_version->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1alpha1_storage_version->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1alpha1_storage_version->spec
    if (!v1alpha1_storage_version->spec) {
        goto fail;
    }
    
    cJSON *spec_object = object_convertToJSON(v1alpha1_storage_version->spec);
    if(spec_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_object);
    if(item->child == NULL) {
    goto fail;
    }


    // v1alpha1_storage_version->status
    if (!v1alpha1_storage_version->status) {
        goto fail;
    }
    
    cJSON *status_local_JSON = v1alpha1_storage_version_status_convertToJSON(v1alpha1_storage_version->status);
    if(status_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "status", status_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha1_storage_version_t *v1alpha1_storage_version_parseFromJSON(cJSON *v1alpha1_storage_versionJSON){

    v1alpha1_storage_version_t *v1alpha1_storage_version_local_var = NULL;

    // v1alpha1_storage_version->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1alpha1_storage_versionJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // v1alpha1_storage_version->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1alpha1_storage_versionJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1alpha1_storage_version->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1alpha1_storage_versionJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1alpha1_storage_version->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1alpha1_storage_versionJSON, "spec");
    if (!spec) {
        goto end;
    }

    object_t *spec_local_object = NULL;
    
    spec_local_object = object_parseFromJSON(spec); //object

    // v1alpha1_storage_version->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1alpha1_storage_versionJSON, "status");
    if (!status) {
        goto end;
    }

    v1alpha1_storage_version_status_t *status_local_nonprim = NULL;
    
    status_local_nonprim = v1alpha1_storage_version_status_parseFromJSON(status); //nonprimitive


    v1alpha1_storage_version_local_var = v1alpha1_storage_version_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec_local_object,
        status_local_nonprim
        );

    return v1alpha1_storage_version_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (status_local_nonprim) {
        v1alpha1_storage_version_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
