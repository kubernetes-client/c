#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_priority_level_configuration.h"



v1alpha1_priority_level_configuration_t *v1alpha1_priority_level_configuration_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha1_priority_level_configuration_spec_t *spec,
    v1alpha1_priority_level_configuration_status_t *status
    ) {
    v1alpha1_priority_level_configuration_t *v1alpha1_priority_level_configuration_local_var = malloc(sizeof(v1alpha1_priority_level_configuration_t));
    if (!v1alpha1_priority_level_configuration_local_var) {
        return NULL;
    }
    v1alpha1_priority_level_configuration_local_var->api_version = api_version;
    v1alpha1_priority_level_configuration_local_var->kind = kind;
    v1alpha1_priority_level_configuration_local_var->metadata = metadata;
    v1alpha1_priority_level_configuration_local_var->spec = spec;
    v1alpha1_priority_level_configuration_local_var->status = status;

    return v1alpha1_priority_level_configuration_local_var;
}


void v1alpha1_priority_level_configuration_free(v1alpha1_priority_level_configuration_t *v1alpha1_priority_level_configuration) {
    if(NULL == v1alpha1_priority_level_configuration){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_priority_level_configuration->api_version) {
        free(v1alpha1_priority_level_configuration->api_version);
        v1alpha1_priority_level_configuration->api_version = NULL;
    }
    if (v1alpha1_priority_level_configuration->kind) {
        free(v1alpha1_priority_level_configuration->kind);
        v1alpha1_priority_level_configuration->kind = NULL;
    }
    if (v1alpha1_priority_level_configuration->metadata) {
        v1_object_meta_free(v1alpha1_priority_level_configuration->metadata);
        v1alpha1_priority_level_configuration->metadata = NULL;
    }
    if (v1alpha1_priority_level_configuration->spec) {
        v1alpha1_priority_level_configuration_spec_free(v1alpha1_priority_level_configuration->spec);
        v1alpha1_priority_level_configuration->spec = NULL;
    }
    if (v1alpha1_priority_level_configuration->status) {
        v1alpha1_priority_level_configuration_status_free(v1alpha1_priority_level_configuration->status);
        v1alpha1_priority_level_configuration->status = NULL;
    }
    free(v1alpha1_priority_level_configuration);
}

cJSON *v1alpha1_priority_level_configuration_convertToJSON(v1alpha1_priority_level_configuration_t *v1alpha1_priority_level_configuration) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_priority_level_configuration->api_version
    if(v1alpha1_priority_level_configuration->api_version) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1alpha1_priority_level_configuration->api_version) == NULL) {
    goto fail; //String
    }
     } 


    // v1alpha1_priority_level_configuration->kind
    if(v1alpha1_priority_level_configuration->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1alpha1_priority_level_configuration->kind) == NULL) {
    goto fail; //String
    }
     } 


    // v1alpha1_priority_level_configuration->metadata
    if(v1alpha1_priority_level_configuration->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1alpha1_priority_level_configuration->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1alpha1_priority_level_configuration->spec
    if(v1alpha1_priority_level_configuration->spec) { 
    cJSON *spec_local_JSON = v1alpha1_priority_level_configuration_spec_convertToJSON(v1alpha1_priority_level_configuration->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1alpha1_priority_level_configuration->status
    if(v1alpha1_priority_level_configuration->status) { 
    cJSON *status_local_JSON = v1alpha1_priority_level_configuration_status_convertToJSON(v1alpha1_priority_level_configuration->status);
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

v1alpha1_priority_level_configuration_t *v1alpha1_priority_level_configuration_parseFromJSON(cJSON *v1alpha1_priority_level_configurationJSON){

    v1alpha1_priority_level_configuration_t *v1alpha1_priority_level_configuration_local_var = NULL;

    // v1alpha1_priority_level_configuration->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1alpha1_priority_level_configurationJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // v1alpha1_priority_level_configuration->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1alpha1_priority_level_configurationJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1alpha1_priority_level_configuration->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1alpha1_priority_level_configurationJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1alpha1_priority_level_configuration->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1alpha1_priority_level_configurationJSON, "spec");
    v1alpha1_priority_level_configuration_spec_t *spec_local_nonprim = NULL;
    if (spec) { 
    spec_local_nonprim = v1alpha1_priority_level_configuration_spec_parseFromJSON(spec); //nonprimitive
    }

    // v1alpha1_priority_level_configuration->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1alpha1_priority_level_configurationJSON, "status");
    v1alpha1_priority_level_configuration_status_t *status_local_nonprim = NULL;
    if (status) { 
    status_local_nonprim = v1alpha1_priority_level_configuration_status_parseFromJSON(status); //nonprimitive
    }


    v1alpha1_priority_level_configuration_local_var = v1alpha1_priority_level_configuration_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL,
        status ? status_local_nonprim : NULL
        );

    return v1alpha1_priority_level_configuration_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1alpha1_priority_level_configuration_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    if (status_local_nonprim) {
        v1alpha1_priority_level_configuration_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
