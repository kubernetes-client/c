#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_daemon_set.h"



v1beta2_daemon_set_t *v1beta2_daemon_set_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta2_daemon_set_spec_t *spec,
    v1beta2_daemon_set_status_t *status
    ) {
    v1beta2_daemon_set_t *v1beta2_daemon_set_local_var = malloc(sizeof(v1beta2_daemon_set_t));
    if (!v1beta2_daemon_set_local_var) {
        return NULL;
    }
    v1beta2_daemon_set_local_var->api_version = api_version;
    v1beta2_daemon_set_local_var->kind = kind;
    v1beta2_daemon_set_local_var->metadata = metadata;
    v1beta2_daemon_set_local_var->spec = spec;
    v1beta2_daemon_set_local_var->status = status;

    return v1beta2_daemon_set_local_var;
}


void v1beta2_daemon_set_free(v1beta2_daemon_set_t *v1beta2_daemon_set) {
    if(NULL == v1beta2_daemon_set){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta2_daemon_set->api_version) {
        free(v1beta2_daemon_set->api_version);
        v1beta2_daemon_set->api_version = NULL;
    }
    if (v1beta2_daemon_set->kind) {
        free(v1beta2_daemon_set->kind);
        v1beta2_daemon_set->kind = NULL;
    }
    if (v1beta2_daemon_set->metadata) {
        v1_object_meta_free(v1beta2_daemon_set->metadata);
        v1beta2_daemon_set->metadata = NULL;
    }
    if (v1beta2_daemon_set->spec) {
        v1beta2_daemon_set_spec_free(v1beta2_daemon_set->spec);
        v1beta2_daemon_set->spec = NULL;
    }
    if (v1beta2_daemon_set->status) {
        v1beta2_daemon_set_status_free(v1beta2_daemon_set->status);
        v1beta2_daemon_set->status = NULL;
    }
    free(v1beta2_daemon_set);
}

cJSON *v1beta2_daemon_set_convertToJSON(v1beta2_daemon_set_t *v1beta2_daemon_set) {
    cJSON *item = cJSON_CreateObject();

    // v1beta2_daemon_set->api_version
    if(v1beta2_daemon_set->api_version) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1beta2_daemon_set->api_version) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta2_daemon_set->kind
    if(v1beta2_daemon_set->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1beta2_daemon_set->kind) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta2_daemon_set->metadata
    if(v1beta2_daemon_set->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1beta2_daemon_set->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1beta2_daemon_set->spec
    if(v1beta2_daemon_set->spec) { 
    cJSON *spec_local_JSON = v1beta2_daemon_set_spec_convertToJSON(v1beta2_daemon_set->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1beta2_daemon_set->status
    if(v1beta2_daemon_set->status) { 
    cJSON *status_local_JSON = v1beta2_daemon_set_status_convertToJSON(v1beta2_daemon_set->status);
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

v1beta2_daemon_set_t *v1beta2_daemon_set_parseFromJSON(cJSON *v1beta2_daemon_setJSON){

    v1beta2_daemon_set_t *v1beta2_daemon_set_local_var = NULL;

    // v1beta2_daemon_set->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1beta2_daemon_setJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // v1beta2_daemon_set->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1beta2_daemon_setJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1beta2_daemon_set->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1beta2_daemon_setJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1beta2_daemon_set->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1beta2_daemon_setJSON, "spec");
    v1beta2_daemon_set_spec_t *spec_local_nonprim = NULL;
    if (spec) { 
    spec_local_nonprim = v1beta2_daemon_set_spec_parseFromJSON(spec); //nonprimitive
    }

    // v1beta2_daemon_set->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1beta2_daemon_setJSON, "status");
    v1beta2_daemon_set_status_t *status_local_nonprim = NULL;
    if (status) { 
    status_local_nonprim = v1beta2_daemon_set_status_parseFromJSON(status); //nonprimitive
    }


    v1beta2_daemon_set_local_var = v1beta2_daemon_set_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL,
        status ? status_local_nonprim : NULL
        );

    return v1beta2_daemon_set_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1beta2_daemon_set_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    if (status_local_nonprim) {
        v1beta2_daemon_set_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
