#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_mutating_admission_policy_binding.h"



static v1_mutating_admission_policy_binding_t *v1_mutating_admission_policy_binding_create_internal(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_mutating_admission_policy_binding_spec_t *spec
    ) {
    v1_mutating_admission_policy_binding_t *v1_mutating_admission_policy_binding_local_var = malloc(sizeof(v1_mutating_admission_policy_binding_t));
    if (!v1_mutating_admission_policy_binding_local_var) {
        return NULL;
    }
    memset(v1_mutating_admission_policy_binding_local_var, 0, sizeof(v1_mutating_admission_policy_binding_t));
    v1_mutating_admission_policy_binding_local_var->_library_owned = 1;
    v1_mutating_admission_policy_binding_local_var->api_version = api_version;
    v1_mutating_admission_policy_binding_local_var->kind = kind;
    v1_mutating_admission_policy_binding_local_var->metadata = metadata;
    v1_mutating_admission_policy_binding_local_var->spec = spec;
    return v1_mutating_admission_policy_binding_local_var;
}

__attribute__((deprecated)) v1_mutating_admission_policy_binding_t *v1_mutating_admission_policy_binding_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_mutating_admission_policy_binding_spec_t *spec
    ) {
    v1_mutating_admission_policy_binding_t *result = v1_mutating_admission_policy_binding_create_internal (
        api_version,
        kind,
        metadata,
        spec
        );
    if (!result) {
    }
    return result;
}

void v1_mutating_admission_policy_binding_free(v1_mutating_admission_policy_binding_t *v1_mutating_admission_policy_binding) {
    if(NULL == v1_mutating_admission_policy_binding){
        return ;
    }
    if(v1_mutating_admission_policy_binding->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_mutating_admission_policy_binding_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_mutating_admission_policy_binding->api_version) {
        free(v1_mutating_admission_policy_binding->api_version);
        v1_mutating_admission_policy_binding->api_version = NULL;
    }
    if (v1_mutating_admission_policy_binding->kind) {
        free(v1_mutating_admission_policy_binding->kind);
        v1_mutating_admission_policy_binding->kind = NULL;
    }
    if (v1_mutating_admission_policy_binding->metadata) {
        v1_object_meta_free(v1_mutating_admission_policy_binding->metadata);
        v1_mutating_admission_policy_binding->metadata = NULL;
    }
    if (v1_mutating_admission_policy_binding->spec) {
        v1_mutating_admission_policy_binding_spec_free(v1_mutating_admission_policy_binding->spec);
        v1_mutating_admission_policy_binding->spec = NULL;
    }
    free(v1_mutating_admission_policy_binding);
}

cJSON *v1_mutating_admission_policy_binding_convertToJSON(v1_mutating_admission_policy_binding_t *v1_mutating_admission_policy_binding) {
    cJSON *item = cJSON_CreateObject();

    // v1_mutating_admission_policy_binding->api_version
    if(v1_mutating_admission_policy_binding->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1_mutating_admission_policy_binding->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_mutating_admission_policy_binding->kind
    if(v1_mutating_admission_policy_binding->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1_mutating_admission_policy_binding->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_mutating_admission_policy_binding->metadata
    if(v1_mutating_admission_policy_binding->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_mutating_admission_policy_binding->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_mutating_admission_policy_binding->spec
    if(v1_mutating_admission_policy_binding->spec) {
    cJSON *spec_local_JSON = v1_mutating_admission_policy_binding_spec_convertToJSON(v1_mutating_admission_policy_binding->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
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

v1_mutating_admission_policy_binding_t *v1_mutating_admission_policy_binding_parseFromJSON(cJSON *v1_mutating_admission_policy_bindingJSON){

    v1_mutating_admission_policy_binding_t *v1_mutating_admission_policy_binding_local_var = NULL;

    char *api_version_local_str = NULL;

    char *kind_local_str = NULL;

    // define the local variable for v1_mutating_admission_policy_binding->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1_mutating_admission_policy_binding->spec
    v1_mutating_admission_policy_binding_spec_t *spec_local_nonprim = NULL;

    // v1_mutating_admission_policy_binding->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_mutating_admission_policy_bindingJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_mutating_admission_policy_binding->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_mutating_admission_policy_bindingJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_mutating_admission_policy_binding->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_mutating_admission_policy_bindingJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_mutating_admission_policy_binding->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1_mutating_admission_policy_bindingJSON, "spec");
    if (cJSON_IsNull(spec)) {
        spec = NULL;
    }
    if (spec) { 
    spec_local_nonprim = v1_mutating_admission_policy_binding_spec_parseFromJSON(spec); //nonprimitive
    }


    if (api_version && !cJSON_IsNull(api_version)) api_version_local_str = strdup(api_version->valuestring);
    if (kind && !cJSON_IsNull(kind)) kind_local_str = strdup(kind->valuestring);

    v1_mutating_admission_policy_binding_local_var = v1_mutating_admission_policy_binding_create_internal (
        api_version_local_str,
        kind_local_str,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL
        );

    if (!v1_mutating_admission_policy_binding_local_var) {
        goto end;
    }

    return v1_mutating_admission_policy_binding_local_var;
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
        v1_mutating_admission_policy_binding_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    return NULL;

}
