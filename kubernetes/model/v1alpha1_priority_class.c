#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_priority_class.h"



v1alpha1_priority_class_t *v1alpha1_priority_class_create(
    char *api_version,
    char *description,
    int global_default,
    char *kind,
    v1_object_meta_t *metadata,
    char *preemption_policy,
    int value
    ) {
    v1alpha1_priority_class_t *v1alpha1_priority_class_local_var = malloc(sizeof(v1alpha1_priority_class_t));
    if (!v1alpha1_priority_class_local_var) {
        return NULL;
    }
    v1alpha1_priority_class_local_var->api_version = api_version;
    v1alpha1_priority_class_local_var->description = description;
    v1alpha1_priority_class_local_var->global_default = global_default;
    v1alpha1_priority_class_local_var->kind = kind;
    v1alpha1_priority_class_local_var->metadata = metadata;
    v1alpha1_priority_class_local_var->preemption_policy = preemption_policy;
    v1alpha1_priority_class_local_var->value = value;

    return v1alpha1_priority_class_local_var;
}


void v1alpha1_priority_class_free(v1alpha1_priority_class_t *v1alpha1_priority_class) {
    if(NULL == v1alpha1_priority_class){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_priority_class->api_version) {
        free(v1alpha1_priority_class->api_version);
        v1alpha1_priority_class->api_version = NULL;
    }
    if (v1alpha1_priority_class->description) {
        free(v1alpha1_priority_class->description);
        v1alpha1_priority_class->description = NULL;
    }
    if (v1alpha1_priority_class->kind) {
        free(v1alpha1_priority_class->kind);
        v1alpha1_priority_class->kind = NULL;
    }
    if (v1alpha1_priority_class->metadata) {
        v1_object_meta_free(v1alpha1_priority_class->metadata);
        v1alpha1_priority_class->metadata = NULL;
    }
    if (v1alpha1_priority_class->preemption_policy) {
        free(v1alpha1_priority_class->preemption_policy);
        v1alpha1_priority_class->preemption_policy = NULL;
    }
    free(v1alpha1_priority_class);
}

cJSON *v1alpha1_priority_class_convertToJSON(v1alpha1_priority_class_t *v1alpha1_priority_class) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_priority_class->api_version
    if(v1alpha1_priority_class->api_version) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1alpha1_priority_class->api_version) == NULL) {
    goto fail; //String
    }
     } 


    // v1alpha1_priority_class->description
    if(v1alpha1_priority_class->description) { 
    if(cJSON_AddStringToObject(item, "description", v1alpha1_priority_class->description) == NULL) {
    goto fail; //String
    }
     } 


    // v1alpha1_priority_class->global_default
    if(v1alpha1_priority_class->global_default) { 
    if(cJSON_AddBoolToObject(item, "globalDefault", v1alpha1_priority_class->global_default) == NULL) {
    goto fail; //Bool
    }
     } 


    // v1alpha1_priority_class->kind
    if(v1alpha1_priority_class->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1alpha1_priority_class->kind) == NULL) {
    goto fail; //String
    }
     } 


    // v1alpha1_priority_class->metadata
    if(v1alpha1_priority_class->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1alpha1_priority_class->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1alpha1_priority_class->preemption_policy
    if(v1alpha1_priority_class->preemption_policy) { 
    if(cJSON_AddStringToObject(item, "preemptionPolicy", v1alpha1_priority_class->preemption_policy) == NULL) {
    goto fail; //String
    }
     } 


    // v1alpha1_priority_class->value
    if (!v1alpha1_priority_class->value) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "value", v1alpha1_priority_class->value) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha1_priority_class_t *v1alpha1_priority_class_parseFromJSON(cJSON *v1alpha1_priority_classJSON){

    v1alpha1_priority_class_t *v1alpha1_priority_class_local_var = NULL;

    // v1alpha1_priority_class->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1alpha1_priority_classJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // v1alpha1_priority_class->description
    cJSON *description = cJSON_GetObjectItemCaseSensitive(v1alpha1_priority_classJSON, "description");
    if (description) { 
    if(!cJSON_IsString(description))
    {
    goto end; //String
    }
    }

    // v1alpha1_priority_class->global_default
    cJSON *global_default = cJSON_GetObjectItemCaseSensitive(v1alpha1_priority_classJSON, "globalDefault");
    if (global_default) { 
    if(!cJSON_IsBool(global_default))
    {
    goto end; //Bool
    }
    }

    // v1alpha1_priority_class->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1alpha1_priority_classJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1alpha1_priority_class->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1alpha1_priority_classJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1alpha1_priority_class->preemption_policy
    cJSON *preemption_policy = cJSON_GetObjectItemCaseSensitive(v1alpha1_priority_classJSON, "preemptionPolicy");
    if (preemption_policy) { 
    if(!cJSON_IsString(preemption_policy))
    {
    goto end; //String
    }
    }

    // v1alpha1_priority_class->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(v1alpha1_priority_classJSON, "value");
    if (!value) {
        goto end;
    }

    
    if(!cJSON_IsNumber(value))
    {
    goto end; //Numeric
    }


    v1alpha1_priority_class_local_var = v1alpha1_priority_class_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        description ? strdup(description->valuestring) : NULL,
        global_default ? global_default->valueint : 0,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        preemption_policy ? strdup(preemption_policy->valuestring) : NULL,
        value->valuedouble
        );

    return v1alpha1_priority_class_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    return NULL;

}
