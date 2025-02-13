#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_binding.h"



static v1_binding_t *v1_binding_create_internal(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_object_reference_t *target
    ) {
    v1_binding_t *v1_binding_local_var = malloc(sizeof(v1_binding_t));
    if (!v1_binding_local_var) {
        return NULL;
    }
    v1_binding_local_var->api_version = api_version;
    v1_binding_local_var->kind = kind;
    v1_binding_local_var->metadata = metadata;
    v1_binding_local_var->target = target;

    v1_binding_local_var->_library_owned = 1;
    return v1_binding_local_var;
}

__attribute__((deprecated)) v1_binding_t *v1_binding_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_object_reference_t *target
    ) {
    return v1_binding_create_internal (
        api_version,
        kind,
        metadata,
        target
        );
}

void v1_binding_free(v1_binding_t *v1_binding) {
    if(NULL == v1_binding){
        return ;
    }
    if(v1_binding->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_binding_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_binding->api_version) {
        free(v1_binding->api_version);
        v1_binding->api_version = NULL;
    }
    if (v1_binding->kind) {
        free(v1_binding->kind);
        v1_binding->kind = NULL;
    }
    if (v1_binding->metadata) {
        v1_object_meta_free(v1_binding->metadata);
        v1_binding->metadata = NULL;
    }
    if (v1_binding->target) {
        v1_object_reference_free(v1_binding->target);
        v1_binding->target = NULL;
    }
    free(v1_binding);
}

cJSON *v1_binding_convertToJSON(v1_binding_t *v1_binding) {
    cJSON *item = cJSON_CreateObject();

    // v1_binding->api_version
    if(v1_binding->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1_binding->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_binding->kind
    if(v1_binding->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1_binding->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_binding->metadata
    if(v1_binding->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_binding->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_binding->target
    if (!v1_binding->target) {
        goto fail;
    }
    cJSON *target_local_JSON = v1_object_reference_convertToJSON(v1_binding->target);
    if(target_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "target", target_local_JSON);
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

v1_binding_t *v1_binding_parseFromJSON(cJSON *v1_bindingJSON){

    v1_binding_t *v1_binding_local_var = NULL;

    // define the local variable for v1_binding->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1_binding->target
    v1_object_reference_t *target_local_nonprim = NULL;

    // v1_binding->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_bindingJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_binding->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_bindingJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_binding->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_bindingJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_binding->target
    cJSON *target = cJSON_GetObjectItemCaseSensitive(v1_bindingJSON, "target");
    if (cJSON_IsNull(target)) {
        target = NULL;
    }
    if (!target) {
        goto end;
    }

    
    target_local_nonprim = v1_object_reference_parseFromJSON(target); //nonprimitive


    v1_binding_local_var = v1_binding_create_internal (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        target_local_nonprim
        );

    return v1_binding_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (target_local_nonprim) {
        v1_object_reference_free(target_local_nonprim);
        target_local_nonprim = NULL;
    }
    return NULL;

}
