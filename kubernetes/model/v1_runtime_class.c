#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_runtime_class.h"



static v1_runtime_class_t *v1_runtime_class_create_internal(
    char *api_version,
    char *handler,
    char *kind,
    v1_object_meta_t *metadata,
    v1_overhead_t *overhead,
    v1_scheduling_t *scheduling
    ) {
    v1_runtime_class_t *v1_runtime_class_local_var = malloc(sizeof(v1_runtime_class_t));
    if (!v1_runtime_class_local_var) {
        return NULL;
    }
    v1_runtime_class_local_var->api_version = api_version;
    v1_runtime_class_local_var->handler = handler;
    v1_runtime_class_local_var->kind = kind;
    v1_runtime_class_local_var->metadata = metadata;
    v1_runtime_class_local_var->overhead = overhead;
    v1_runtime_class_local_var->scheduling = scheduling;

    v1_runtime_class_local_var->_library_owned = 1;
    return v1_runtime_class_local_var;
}

__attribute__((deprecated)) v1_runtime_class_t *v1_runtime_class_create(
    char *api_version,
    char *handler,
    char *kind,
    v1_object_meta_t *metadata,
    v1_overhead_t *overhead,
    v1_scheduling_t *scheduling
    ) {
    return v1_runtime_class_create_internal (
        api_version,
        handler,
        kind,
        metadata,
        overhead,
        scheduling
        );
}

void v1_runtime_class_free(v1_runtime_class_t *v1_runtime_class) {
    if(NULL == v1_runtime_class){
        return ;
    }
    if(v1_runtime_class->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_runtime_class_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_runtime_class->api_version) {
        free(v1_runtime_class->api_version);
        v1_runtime_class->api_version = NULL;
    }
    if (v1_runtime_class->handler) {
        free(v1_runtime_class->handler);
        v1_runtime_class->handler = NULL;
    }
    if (v1_runtime_class->kind) {
        free(v1_runtime_class->kind);
        v1_runtime_class->kind = NULL;
    }
    if (v1_runtime_class->metadata) {
        v1_object_meta_free(v1_runtime_class->metadata);
        v1_runtime_class->metadata = NULL;
    }
    if (v1_runtime_class->overhead) {
        v1_overhead_free(v1_runtime_class->overhead);
        v1_runtime_class->overhead = NULL;
    }
    if (v1_runtime_class->scheduling) {
        v1_scheduling_free(v1_runtime_class->scheduling);
        v1_runtime_class->scheduling = NULL;
    }
    free(v1_runtime_class);
}

cJSON *v1_runtime_class_convertToJSON(v1_runtime_class_t *v1_runtime_class) {
    cJSON *item = cJSON_CreateObject();

    // v1_runtime_class->api_version
    if(v1_runtime_class->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1_runtime_class->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_runtime_class->handler
    if (!v1_runtime_class->handler) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "handler", v1_runtime_class->handler) == NULL) {
    goto fail; //String
    }


    // v1_runtime_class->kind
    if(v1_runtime_class->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1_runtime_class->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_runtime_class->metadata
    if(v1_runtime_class->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_runtime_class->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_runtime_class->overhead
    if(v1_runtime_class->overhead) {
    cJSON *overhead_local_JSON = v1_overhead_convertToJSON(v1_runtime_class->overhead);
    if(overhead_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "overhead", overhead_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_runtime_class->scheduling
    if(v1_runtime_class->scheduling) {
    cJSON *scheduling_local_JSON = v1_scheduling_convertToJSON(v1_runtime_class->scheduling);
    if(scheduling_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "scheduling", scheduling_local_JSON);
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

v1_runtime_class_t *v1_runtime_class_parseFromJSON(cJSON *v1_runtime_classJSON){

    v1_runtime_class_t *v1_runtime_class_local_var = NULL;

    // define the local variable for v1_runtime_class->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1_runtime_class->overhead
    v1_overhead_t *overhead_local_nonprim = NULL;

    // define the local variable for v1_runtime_class->scheduling
    v1_scheduling_t *scheduling_local_nonprim = NULL;

    // v1_runtime_class->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_runtime_classJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_runtime_class->handler
    cJSON *handler = cJSON_GetObjectItemCaseSensitive(v1_runtime_classJSON, "handler");
    if (cJSON_IsNull(handler)) {
        handler = NULL;
    }
    if (!handler) {
        goto end;
    }

    
    if(!cJSON_IsString(handler))
    {
    goto end; //String
    }

    // v1_runtime_class->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_runtime_classJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_runtime_class->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_runtime_classJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_runtime_class->overhead
    cJSON *overhead = cJSON_GetObjectItemCaseSensitive(v1_runtime_classJSON, "overhead");
    if (cJSON_IsNull(overhead)) {
        overhead = NULL;
    }
    if (overhead) { 
    overhead_local_nonprim = v1_overhead_parseFromJSON(overhead); //nonprimitive
    }

    // v1_runtime_class->scheduling
    cJSON *scheduling = cJSON_GetObjectItemCaseSensitive(v1_runtime_classJSON, "scheduling");
    if (cJSON_IsNull(scheduling)) {
        scheduling = NULL;
    }
    if (scheduling) { 
    scheduling_local_nonprim = v1_scheduling_parseFromJSON(scheduling); //nonprimitive
    }


    v1_runtime_class_local_var = v1_runtime_class_create_internal (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        strdup(handler->valuestring),
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        overhead ? overhead_local_nonprim : NULL,
        scheduling ? scheduling_local_nonprim : NULL
        );

    return v1_runtime_class_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (overhead_local_nonprim) {
        v1_overhead_free(overhead_local_nonprim);
        overhead_local_nonprim = NULL;
    }
    if (scheduling_local_nonprim) {
        v1_scheduling_free(scheduling_local_nonprim);
        scheduling_local_nonprim = NULL;
    }
    return NULL;

}
