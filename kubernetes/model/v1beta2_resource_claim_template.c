#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_resource_claim_template.h"



static v1beta2_resource_claim_template_t *v1beta2_resource_claim_template_create_internal(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta2_resource_claim_template_spec_t *spec
    ) {
    v1beta2_resource_claim_template_t *v1beta2_resource_claim_template_local_var = malloc(sizeof(v1beta2_resource_claim_template_t));
    if (!v1beta2_resource_claim_template_local_var) {
        return NULL;
    }
    v1beta2_resource_claim_template_local_var->api_version = api_version;
    v1beta2_resource_claim_template_local_var->kind = kind;
    v1beta2_resource_claim_template_local_var->metadata = metadata;
    v1beta2_resource_claim_template_local_var->spec = spec;

    v1beta2_resource_claim_template_local_var->_library_owned = 1;
    return v1beta2_resource_claim_template_local_var;
}

__attribute__((deprecated)) v1beta2_resource_claim_template_t *v1beta2_resource_claim_template_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta2_resource_claim_template_spec_t *spec
    ) {
    return v1beta2_resource_claim_template_create_internal (
        api_version,
        kind,
        metadata,
        spec
        );
}

void v1beta2_resource_claim_template_free(v1beta2_resource_claim_template_t *v1beta2_resource_claim_template) {
    if(NULL == v1beta2_resource_claim_template){
        return ;
    }
    if(v1beta2_resource_claim_template->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta2_resource_claim_template_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta2_resource_claim_template->api_version) {
        free(v1beta2_resource_claim_template->api_version);
        v1beta2_resource_claim_template->api_version = NULL;
    }
    if (v1beta2_resource_claim_template->kind) {
        free(v1beta2_resource_claim_template->kind);
        v1beta2_resource_claim_template->kind = NULL;
    }
    if (v1beta2_resource_claim_template->metadata) {
        v1_object_meta_free(v1beta2_resource_claim_template->metadata);
        v1beta2_resource_claim_template->metadata = NULL;
    }
    if (v1beta2_resource_claim_template->spec) {
        v1beta2_resource_claim_template_spec_free(v1beta2_resource_claim_template->spec);
        v1beta2_resource_claim_template->spec = NULL;
    }
    free(v1beta2_resource_claim_template);
}

cJSON *v1beta2_resource_claim_template_convertToJSON(v1beta2_resource_claim_template_t *v1beta2_resource_claim_template) {
    cJSON *item = cJSON_CreateObject();

    // v1beta2_resource_claim_template->api_version
    if(v1beta2_resource_claim_template->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1beta2_resource_claim_template->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1beta2_resource_claim_template->kind
    if(v1beta2_resource_claim_template->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1beta2_resource_claim_template->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1beta2_resource_claim_template->metadata
    if(v1beta2_resource_claim_template->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1beta2_resource_claim_template->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1beta2_resource_claim_template->spec
    if (!v1beta2_resource_claim_template->spec) {
        goto fail;
    }
    cJSON *spec_local_JSON = v1beta2_resource_claim_template_spec_convertToJSON(v1beta2_resource_claim_template->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
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

v1beta2_resource_claim_template_t *v1beta2_resource_claim_template_parseFromJSON(cJSON *v1beta2_resource_claim_templateJSON){

    v1beta2_resource_claim_template_t *v1beta2_resource_claim_template_local_var = NULL;

    // define the local variable for v1beta2_resource_claim_template->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1beta2_resource_claim_template->spec
    v1beta2_resource_claim_template_spec_t *spec_local_nonprim = NULL;

    // v1beta2_resource_claim_template->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1beta2_resource_claim_templateJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1beta2_resource_claim_template->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1beta2_resource_claim_templateJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1beta2_resource_claim_template->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1beta2_resource_claim_templateJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1beta2_resource_claim_template->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1beta2_resource_claim_templateJSON, "spec");
    if (cJSON_IsNull(spec)) {
        spec = NULL;
    }
    if (!spec) {
        goto end;
    }

    
    spec_local_nonprim = v1beta2_resource_claim_template_spec_parseFromJSON(spec); //nonprimitive


    v1beta2_resource_claim_template_local_var = v1beta2_resource_claim_template_create_internal (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec_local_nonprim
        );

    return v1beta2_resource_claim_template_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1beta2_resource_claim_template_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    return NULL;

}
