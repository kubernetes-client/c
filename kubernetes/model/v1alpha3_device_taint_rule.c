#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_device_taint_rule.h"



static v1alpha3_device_taint_rule_t *v1alpha3_device_taint_rule_create_internal(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha3_device_taint_rule_spec_t *spec
    ) {
    v1alpha3_device_taint_rule_t *v1alpha3_device_taint_rule_local_var = malloc(sizeof(v1alpha3_device_taint_rule_t));
    if (!v1alpha3_device_taint_rule_local_var) {
        return NULL;
    }
    v1alpha3_device_taint_rule_local_var->api_version = api_version;
    v1alpha3_device_taint_rule_local_var->kind = kind;
    v1alpha3_device_taint_rule_local_var->metadata = metadata;
    v1alpha3_device_taint_rule_local_var->spec = spec;

    v1alpha3_device_taint_rule_local_var->_library_owned = 1;
    return v1alpha3_device_taint_rule_local_var;
}

__attribute__((deprecated)) v1alpha3_device_taint_rule_t *v1alpha3_device_taint_rule_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha3_device_taint_rule_spec_t *spec
    ) {
    return v1alpha3_device_taint_rule_create_internal (
        api_version,
        kind,
        metadata,
        spec
        );
}

void v1alpha3_device_taint_rule_free(v1alpha3_device_taint_rule_t *v1alpha3_device_taint_rule) {
    if(NULL == v1alpha3_device_taint_rule){
        return ;
    }
    if(v1alpha3_device_taint_rule->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha3_device_taint_rule_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_device_taint_rule->api_version) {
        free(v1alpha3_device_taint_rule->api_version);
        v1alpha3_device_taint_rule->api_version = NULL;
    }
    if (v1alpha3_device_taint_rule->kind) {
        free(v1alpha3_device_taint_rule->kind);
        v1alpha3_device_taint_rule->kind = NULL;
    }
    if (v1alpha3_device_taint_rule->metadata) {
        v1_object_meta_free(v1alpha3_device_taint_rule->metadata);
        v1alpha3_device_taint_rule->metadata = NULL;
    }
    if (v1alpha3_device_taint_rule->spec) {
        v1alpha3_device_taint_rule_spec_free(v1alpha3_device_taint_rule->spec);
        v1alpha3_device_taint_rule->spec = NULL;
    }
    free(v1alpha3_device_taint_rule);
}

cJSON *v1alpha3_device_taint_rule_convertToJSON(v1alpha3_device_taint_rule_t *v1alpha3_device_taint_rule) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_device_taint_rule->api_version
    if(v1alpha3_device_taint_rule->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1alpha3_device_taint_rule->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha3_device_taint_rule->kind
    if(v1alpha3_device_taint_rule->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1alpha3_device_taint_rule->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha3_device_taint_rule->metadata
    if(v1alpha3_device_taint_rule->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1alpha3_device_taint_rule->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha3_device_taint_rule->spec
    if (!v1alpha3_device_taint_rule->spec) {
        goto fail;
    }
    cJSON *spec_local_JSON = v1alpha3_device_taint_rule_spec_convertToJSON(v1alpha3_device_taint_rule->spec);
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

v1alpha3_device_taint_rule_t *v1alpha3_device_taint_rule_parseFromJSON(cJSON *v1alpha3_device_taint_ruleJSON){

    v1alpha3_device_taint_rule_t *v1alpha3_device_taint_rule_local_var = NULL;

    // define the local variable for v1alpha3_device_taint_rule->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1alpha3_device_taint_rule->spec
    v1alpha3_device_taint_rule_spec_t *spec_local_nonprim = NULL;

    // v1alpha3_device_taint_rule->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_taint_ruleJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1alpha3_device_taint_rule->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_taint_ruleJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1alpha3_device_taint_rule->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_taint_ruleJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1alpha3_device_taint_rule->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1alpha3_device_taint_ruleJSON, "spec");
    if (cJSON_IsNull(spec)) {
        spec = NULL;
    }
    if (!spec) {
        goto end;
    }

    
    spec_local_nonprim = v1alpha3_device_taint_rule_spec_parseFromJSON(spec); //nonprimitive


    v1alpha3_device_taint_rule_local_var = v1alpha3_device_taint_rule_create_internal (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec_local_nonprim
        );

    return v1alpha3_device_taint_rule_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1alpha3_device_taint_rule_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    return NULL;

}
