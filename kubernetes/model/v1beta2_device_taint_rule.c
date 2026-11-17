#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_device_taint_rule.h"



static v1beta2_device_taint_rule_t *v1beta2_device_taint_rule_create_internal(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta2_device_taint_rule_spec_t *spec,
    v1beta2_device_taint_rule_status_t *status
    ) {
    v1beta2_device_taint_rule_t *v1beta2_device_taint_rule_local_var = malloc(sizeof(v1beta2_device_taint_rule_t));
    if (!v1beta2_device_taint_rule_local_var) {
        return NULL;
    }
    memset(v1beta2_device_taint_rule_local_var, 0, sizeof(v1beta2_device_taint_rule_t));
    v1beta2_device_taint_rule_local_var->_library_owned = 1;
    v1beta2_device_taint_rule_local_var->api_version = api_version;
    v1beta2_device_taint_rule_local_var->kind = kind;
    v1beta2_device_taint_rule_local_var->metadata = metadata;
    v1beta2_device_taint_rule_local_var->spec = spec;
    v1beta2_device_taint_rule_local_var->status = status;
    return v1beta2_device_taint_rule_local_var;
}

__attribute__((deprecated)) v1beta2_device_taint_rule_t *v1beta2_device_taint_rule_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta2_device_taint_rule_spec_t *spec,
    v1beta2_device_taint_rule_status_t *status
    ) {
    v1beta2_device_taint_rule_t *result = v1beta2_device_taint_rule_create_internal (
        api_version,
        kind,
        metadata,
        spec,
        status
        );
    if (!result) {
    }
    return result;
}

void v1beta2_device_taint_rule_free(v1beta2_device_taint_rule_t *v1beta2_device_taint_rule) {
    if(NULL == v1beta2_device_taint_rule){
        return ;
    }
    if(v1beta2_device_taint_rule->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta2_device_taint_rule_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta2_device_taint_rule->api_version) {
        free(v1beta2_device_taint_rule->api_version);
        v1beta2_device_taint_rule->api_version = NULL;
    }
    if (v1beta2_device_taint_rule->kind) {
        free(v1beta2_device_taint_rule->kind);
        v1beta2_device_taint_rule->kind = NULL;
    }
    if (v1beta2_device_taint_rule->metadata) {
        v1_object_meta_free(v1beta2_device_taint_rule->metadata);
        v1beta2_device_taint_rule->metadata = NULL;
    }
    if (v1beta2_device_taint_rule->spec) {
        v1beta2_device_taint_rule_spec_free(v1beta2_device_taint_rule->spec);
        v1beta2_device_taint_rule->spec = NULL;
    }
    if (v1beta2_device_taint_rule->status) {
        v1beta2_device_taint_rule_status_free(v1beta2_device_taint_rule->status);
        v1beta2_device_taint_rule->status = NULL;
    }
    free(v1beta2_device_taint_rule);
}

cJSON *v1beta2_device_taint_rule_convertToJSON(v1beta2_device_taint_rule_t *v1beta2_device_taint_rule) {
    cJSON *item = cJSON_CreateObject();

    // v1beta2_device_taint_rule->api_version
    if(v1beta2_device_taint_rule->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1beta2_device_taint_rule->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1beta2_device_taint_rule->kind
    if(v1beta2_device_taint_rule->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1beta2_device_taint_rule->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1beta2_device_taint_rule->metadata
    if(v1beta2_device_taint_rule->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1beta2_device_taint_rule->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1beta2_device_taint_rule->spec
    if (!v1beta2_device_taint_rule->spec) {
        goto fail;
    }
    cJSON *spec_local_JSON = v1beta2_device_taint_rule_spec_convertToJSON(v1beta2_device_taint_rule->spec);
    if(spec_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "spec", spec_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1beta2_device_taint_rule->status
    if(v1beta2_device_taint_rule->status) {
    cJSON *status_local_JSON = v1beta2_device_taint_rule_status_convertToJSON(v1beta2_device_taint_rule->status);
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

v1beta2_device_taint_rule_t *v1beta2_device_taint_rule_parseFromJSON(cJSON *v1beta2_device_taint_ruleJSON){

    v1beta2_device_taint_rule_t *v1beta2_device_taint_rule_local_var = NULL;

    char *api_version_local_str = NULL;

    char *kind_local_str = NULL;

    // define the local variable for v1beta2_device_taint_rule->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1beta2_device_taint_rule->spec
    v1beta2_device_taint_rule_spec_t *spec_local_nonprim = NULL;

    // define the local variable for v1beta2_device_taint_rule->status
    v1beta2_device_taint_rule_status_t *status_local_nonprim = NULL;

    // v1beta2_device_taint_rule->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1beta2_device_taint_ruleJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1beta2_device_taint_rule->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1beta2_device_taint_ruleJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1beta2_device_taint_rule->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1beta2_device_taint_ruleJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1beta2_device_taint_rule->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1beta2_device_taint_ruleJSON, "spec");
    if (cJSON_IsNull(spec)) {
        spec = NULL;
    }
    if (!spec) {
        goto end;
    }

    
    spec_local_nonprim = v1beta2_device_taint_rule_spec_parseFromJSON(spec); //nonprimitive

    // v1beta2_device_taint_rule->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1beta2_device_taint_ruleJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    status_local_nonprim = v1beta2_device_taint_rule_status_parseFromJSON(status); //nonprimitive
    }


    if (api_version && !cJSON_IsNull(api_version)) api_version_local_str = strdup(api_version->valuestring);
    if (kind && !cJSON_IsNull(kind)) kind_local_str = strdup(kind->valuestring);

    v1beta2_device_taint_rule_local_var = v1beta2_device_taint_rule_create_internal (
        api_version_local_str,
        kind_local_str,
        metadata ? metadata_local_nonprim : NULL,
        spec_local_nonprim,
        status ? status_local_nonprim : NULL
        );

    if (!v1beta2_device_taint_rule_local_var) {
        goto end;
    }

    return v1beta2_device_taint_rule_local_var;
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
        v1beta2_device_taint_rule_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    if (status_local_nonprim) {
        v1beta2_device_taint_rule_status_free(status_local_nonprim);
        status_local_nonprim = NULL;
    }
    return NULL;

}
