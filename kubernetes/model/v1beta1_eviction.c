#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_eviction.h"



v1beta1_eviction_t *v1beta1_eviction_create(
    char *api_version,
    v1_delete_options_t *delete_options,
    char *kind,
    v1_object_meta_t *metadata
    ) {
    v1beta1_eviction_t *v1beta1_eviction_local_var = malloc(sizeof(v1beta1_eviction_t));
    if (!v1beta1_eviction_local_var) {
        return NULL;
    }
    v1beta1_eviction_local_var->api_version = api_version;
    v1beta1_eviction_local_var->delete_options = delete_options;
    v1beta1_eviction_local_var->kind = kind;
    v1beta1_eviction_local_var->metadata = metadata;

    return v1beta1_eviction_local_var;
}


void v1beta1_eviction_free(v1beta1_eviction_t *v1beta1_eviction) {
    if(NULL == v1beta1_eviction){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_eviction->api_version) {
        free(v1beta1_eviction->api_version);
        v1beta1_eviction->api_version = NULL;
    }
    if (v1beta1_eviction->delete_options) {
        v1_delete_options_free(v1beta1_eviction->delete_options);
        v1beta1_eviction->delete_options = NULL;
    }
    if (v1beta1_eviction->kind) {
        free(v1beta1_eviction->kind);
        v1beta1_eviction->kind = NULL;
    }
    if (v1beta1_eviction->metadata) {
        v1_object_meta_free(v1beta1_eviction->metadata);
        v1beta1_eviction->metadata = NULL;
    }
    free(v1beta1_eviction);
}

cJSON *v1beta1_eviction_convertToJSON(v1beta1_eviction_t *v1beta1_eviction) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_eviction->api_version
    if(v1beta1_eviction->api_version) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1beta1_eviction->api_version) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_eviction->delete_options
    if(v1beta1_eviction->delete_options) { 
    cJSON *delete_options_local_JSON = v1_delete_options_convertToJSON(v1beta1_eviction->delete_options);
    if(delete_options_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "deleteOptions", delete_options_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1beta1_eviction->kind
    if(v1beta1_eviction->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1beta1_eviction->kind) == NULL) {
    goto fail; //String
    }
     } 


    // v1beta1_eviction->metadata
    if(v1beta1_eviction->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1beta1_eviction->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
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

v1beta1_eviction_t *v1beta1_eviction_parseFromJSON(cJSON *v1beta1_evictionJSON){

    v1beta1_eviction_t *v1beta1_eviction_local_var = NULL;

    // v1beta1_eviction->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1beta1_evictionJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // v1beta1_eviction->delete_options
    cJSON *delete_options = cJSON_GetObjectItemCaseSensitive(v1beta1_evictionJSON, "deleteOptions");
    v1_delete_options_t *delete_options_local_nonprim = NULL;
    if (delete_options) { 
    delete_options_local_nonprim = v1_delete_options_parseFromJSON(delete_options); //nonprimitive
    }

    // v1beta1_eviction->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1beta1_evictionJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1beta1_eviction->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1beta1_evictionJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }


    v1beta1_eviction_local_var = v1beta1_eviction_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        delete_options ? delete_options_local_nonprim : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL
        );

    return v1beta1_eviction_local_var;
end:
    if (delete_options_local_nonprim) {
        v1_delete_options_free(delete_options_local_nonprim);
        delete_options_local_nonprim = NULL;
    }
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    return NULL;

}
