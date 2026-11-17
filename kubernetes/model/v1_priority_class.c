#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_priority_class.h"



static v1_priority_class_t *v1_priority_class_create_internal(
    char *api_version,
    char *description,
    int *global_default,
    char *kind,
    v1_object_meta_t *metadata,
    char *preemption_policy,
    int *value
    ) {
    v1_priority_class_t *v1_priority_class_local_var = malloc(sizeof(v1_priority_class_t));
    if (!v1_priority_class_local_var) {
        return NULL;
    }
    memset(v1_priority_class_local_var, 0, sizeof(v1_priority_class_t));
    v1_priority_class_local_var->_library_owned = 1;
    v1_priority_class_local_var->api_version = api_version;
    v1_priority_class_local_var->description = description;
    v1_priority_class_local_var->global_default = global_default;
    v1_priority_class_local_var->kind = kind;
    v1_priority_class_local_var->metadata = metadata;
    v1_priority_class_local_var->preemption_policy = preemption_policy;
    v1_priority_class_local_var->value = value;
    return v1_priority_class_local_var;
}

__attribute__((deprecated)) v1_priority_class_t *v1_priority_class_create(
    char *api_version,
    char *description,
    int *global_default,
    char *kind,
    v1_object_meta_t *metadata,
    char *preemption_policy,
    int *value
    ) {
    int *global_default_copy = NULL;
    if (global_default) {
        global_default_copy = malloc(sizeof(int));
        if (global_default_copy) *global_default_copy = *global_default;
    }
    int *value_copy = NULL;
    if (value) {
        value_copy = malloc(sizeof(int));
        if (value_copy) *value_copy = *value;
    }
    v1_priority_class_t *result = v1_priority_class_create_internal (
        api_version,
        description,
        global_default_copy,
        kind,
        metadata,
        preemption_policy,
        value_copy
        );
    if (!result) {
        free(global_default_copy);
        free(value_copy);
    }
    return result;
}

void v1_priority_class_free(v1_priority_class_t *v1_priority_class) {
    if(NULL == v1_priority_class){
        return ;
    }
    if(v1_priority_class->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_priority_class_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_priority_class->api_version) {
        free(v1_priority_class->api_version);
        v1_priority_class->api_version = NULL;
    }
    if (v1_priority_class->description) {
        free(v1_priority_class->description);
        v1_priority_class->description = NULL;
    }
    if (v1_priority_class->global_default) {
        free(v1_priority_class->global_default);
        v1_priority_class->global_default = NULL;
    }
    if (v1_priority_class->kind) {
        free(v1_priority_class->kind);
        v1_priority_class->kind = NULL;
    }
    if (v1_priority_class->metadata) {
        v1_object_meta_free(v1_priority_class->metadata);
        v1_priority_class->metadata = NULL;
    }
    if (v1_priority_class->preemption_policy) {
        free(v1_priority_class->preemption_policy);
        v1_priority_class->preemption_policy = NULL;
    }
    if (v1_priority_class->value) {
        free(v1_priority_class->value);
        v1_priority_class->value = NULL;
    }
    free(v1_priority_class);
}

cJSON *v1_priority_class_convertToJSON(v1_priority_class_t *v1_priority_class) {
    cJSON *item = cJSON_CreateObject();

    // v1_priority_class->api_version
    if(v1_priority_class->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1_priority_class->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_priority_class->description
    if(v1_priority_class->description) {
    if(cJSON_AddStringToObject(item, "description", v1_priority_class->description) == NULL) {
    goto fail; //String
    }
    }


    // v1_priority_class->global_default
    if(v1_priority_class->global_default) {
    if(cJSON_AddBoolToObject(item, "globalDefault", *v1_priority_class->global_default) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_priority_class->kind
    if(v1_priority_class->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1_priority_class->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_priority_class->metadata
    if(v1_priority_class->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_priority_class->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_priority_class->preemption_policy
    if(v1_priority_class->preemption_policy) {
    if(cJSON_AddStringToObject(item, "preemptionPolicy", v1_priority_class->preemption_policy) == NULL) {
    goto fail; //String
    }
    }


    // v1_priority_class->value
    if(v1_priority_class->value) {
    if(cJSON_AddNumberToObject(item, "value", *v1_priority_class->value) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_priority_class_t *v1_priority_class_parseFromJSON(cJSON *v1_priority_classJSON){

    v1_priority_class_t *v1_priority_class_local_var = NULL;

    char *api_version_local_str = NULL;

    char *description_local_str = NULL;

    // define the local variable for v1_priority_class->global_default
    int *global_default_local_var = NULL;

    char *kind_local_str = NULL;

    // define the local variable for v1_priority_class->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    char *preemption_policy_local_str = NULL;

    // define the local variable for v1_priority_class->value
    int *value_local_var = NULL;

    // v1_priority_class->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_priority_classJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_priority_class->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(v1_priority_classJSON, "description");
    if (cJSON_IsNull(description)) {
        description = NULL;
    }
    if (description) { 
    if(!cJSON_IsString(description) && !cJSON_IsNull(description))
    {
    goto end; //String
    }
    }

    // v1_priority_class->global_default
    cJSON *global_default = cJSON_GetObjectItemCaseSensitive(v1_priority_classJSON, "globalDefault");
    if (cJSON_IsNull(global_default)) {
        global_default = NULL;
    }
    if (global_default) { 
    if(!cJSON_IsBool(global_default))
    {
    goto end; //Bool
    }
    global_default_local_var = malloc(sizeof(int));
    if(!global_default_local_var)
    {
        goto end;
    }
    *global_default_local_var = global_default->valueint;
    }

    // v1_priority_class->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_priority_classJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_priority_class->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_priority_classJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_priority_class->preemption_policy
    cJSON *preemption_policy = cJSON_GetObjectItemCaseSensitive(v1_priority_classJSON, "preemptionPolicy");
    if (cJSON_IsNull(preemption_policy)) {
        preemption_policy = NULL;
    }
    if (preemption_policy) { 
    if(!cJSON_IsString(preemption_policy) && !cJSON_IsNull(preemption_policy))
    {
    goto end; //String
    }
    }

    // v1_priority_class->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(v1_priority_classJSON, "value");
    if (cJSON_IsNull(value)) {
        value = NULL;
    }
    if (value) { 
    if(!cJSON_IsNumber(value))
    {
    goto end; //Numeric
    }
    value_local_var = malloc(sizeof(int));
    if(!value_local_var)
    {
        goto end;
    }
    *value_local_var = value->valuedouble;
    }


    if (api_version && !cJSON_IsNull(api_version)) api_version_local_str = strdup(api_version->valuestring);
    if (description && !cJSON_IsNull(description)) description_local_str = strdup(description->valuestring);
    if (kind && !cJSON_IsNull(kind)) kind_local_str = strdup(kind->valuestring);
    if (preemption_policy && !cJSON_IsNull(preemption_policy)) preemption_policy_local_str = strdup(preemption_policy->valuestring);

    v1_priority_class_local_var = v1_priority_class_create_internal (
        api_version_local_str,
        description_local_str,
        global_default_local_var,
        kind_local_str,
        metadata ? metadata_local_nonprim : NULL,
        preemption_policy_local_str,
        value_local_var
        );

    if (!v1_priority_class_local_var) {
        goto end;
    }

    return v1_priority_class_local_var;
end:
    if (api_version_local_str) {
        free(api_version_local_str);
        api_version_local_str = NULL;
    }
    if (description_local_str) {
        free(description_local_str);
        description_local_str = NULL;
    }
    if (global_default_local_var) {
        free(global_default_local_var);
        global_default_local_var = NULL;
    }
    if (kind_local_str) {
        free(kind_local_str);
        kind_local_str = NULL;
    }
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (preemption_policy_local_str) {
        free(preemption_policy_local_str);
        preemption_policy_local_str = NULL;
    }
    if (value_local_var) {
        free(value_local_var);
        value_local_var = NULL;
    }
    return NULL;

}
