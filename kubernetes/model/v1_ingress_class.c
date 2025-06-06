#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_ingress_class.h"



static v1_ingress_class_t *v1_ingress_class_create_internal(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_ingress_class_spec_t *spec
    ) {
    v1_ingress_class_t *v1_ingress_class_local_var = malloc(sizeof(v1_ingress_class_t));
    if (!v1_ingress_class_local_var) {
        return NULL;
    }
    v1_ingress_class_local_var->api_version = api_version;
    v1_ingress_class_local_var->kind = kind;
    v1_ingress_class_local_var->metadata = metadata;
    v1_ingress_class_local_var->spec = spec;

    v1_ingress_class_local_var->_library_owned = 1;
    return v1_ingress_class_local_var;
}

__attribute__((deprecated)) v1_ingress_class_t *v1_ingress_class_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_ingress_class_spec_t *spec
    ) {
    return v1_ingress_class_create_internal (
        api_version,
        kind,
        metadata,
        spec
        );
}

void v1_ingress_class_free(v1_ingress_class_t *v1_ingress_class) {
    if(NULL == v1_ingress_class){
        return ;
    }
    if(v1_ingress_class->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_ingress_class_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_ingress_class->api_version) {
        free(v1_ingress_class->api_version);
        v1_ingress_class->api_version = NULL;
    }
    if (v1_ingress_class->kind) {
        free(v1_ingress_class->kind);
        v1_ingress_class->kind = NULL;
    }
    if (v1_ingress_class->metadata) {
        v1_object_meta_free(v1_ingress_class->metadata);
        v1_ingress_class->metadata = NULL;
    }
    if (v1_ingress_class->spec) {
        v1_ingress_class_spec_free(v1_ingress_class->spec);
        v1_ingress_class->spec = NULL;
    }
    free(v1_ingress_class);
}

cJSON *v1_ingress_class_convertToJSON(v1_ingress_class_t *v1_ingress_class) {
    cJSON *item = cJSON_CreateObject();

    // v1_ingress_class->api_version
    if(v1_ingress_class->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1_ingress_class->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_ingress_class->kind
    if(v1_ingress_class->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1_ingress_class->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_ingress_class->metadata
    if(v1_ingress_class->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_ingress_class->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_ingress_class->spec
    if(v1_ingress_class->spec) {
    cJSON *spec_local_JSON = v1_ingress_class_spec_convertToJSON(v1_ingress_class->spec);
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

v1_ingress_class_t *v1_ingress_class_parseFromJSON(cJSON *v1_ingress_classJSON){

    v1_ingress_class_t *v1_ingress_class_local_var = NULL;

    // define the local variable for v1_ingress_class->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1_ingress_class->spec
    v1_ingress_class_spec_t *spec_local_nonprim = NULL;

    // v1_ingress_class->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_ingress_classJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_ingress_class->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_ingress_classJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_ingress_class->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_ingress_classJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_ingress_class->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1_ingress_classJSON, "spec");
    if (cJSON_IsNull(spec)) {
        spec = NULL;
    }
    if (spec) { 
    spec_local_nonprim = v1_ingress_class_spec_parseFromJSON(spec); //nonprimitive
    }


    v1_ingress_class_local_var = v1_ingress_class_create_internal (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec ? spec_local_nonprim : NULL
        );

    return v1_ingress_class_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1_ingress_class_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    return NULL;

}
