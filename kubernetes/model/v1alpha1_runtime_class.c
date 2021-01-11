#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_runtime_class.h"



v1alpha1_runtime_class_t *v1alpha1_runtime_class_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha1_runtime_class_spec_t *spec
    ) {
    v1alpha1_runtime_class_t *v1alpha1_runtime_class_local_var = malloc(sizeof(v1alpha1_runtime_class_t));
    if (!v1alpha1_runtime_class_local_var) {
        return NULL;
    }
    v1alpha1_runtime_class_local_var->api_version = api_version;
    v1alpha1_runtime_class_local_var->kind = kind;
    v1alpha1_runtime_class_local_var->metadata = metadata;
    v1alpha1_runtime_class_local_var->spec = spec;

    return v1alpha1_runtime_class_local_var;
}


void v1alpha1_runtime_class_free(v1alpha1_runtime_class_t *v1alpha1_runtime_class) {
    if(NULL == v1alpha1_runtime_class){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_runtime_class->api_version) {
        free(v1alpha1_runtime_class->api_version);
        v1alpha1_runtime_class->api_version = NULL;
    }
    if (v1alpha1_runtime_class->kind) {
        free(v1alpha1_runtime_class->kind);
        v1alpha1_runtime_class->kind = NULL;
    }
    if (v1alpha1_runtime_class->metadata) {
        v1_object_meta_free(v1alpha1_runtime_class->metadata);
        v1alpha1_runtime_class->metadata = NULL;
    }
    if (v1alpha1_runtime_class->spec) {
        v1alpha1_runtime_class_spec_free(v1alpha1_runtime_class->spec);
        v1alpha1_runtime_class->spec = NULL;
    }
    free(v1alpha1_runtime_class);
}

cJSON *v1alpha1_runtime_class_convertToJSON(v1alpha1_runtime_class_t *v1alpha1_runtime_class) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_runtime_class->api_version
    if(v1alpha1_runtime_class->api_version) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1alpha1_runtime_class->api_version) == NULL) {
    goto fail; //String
    }
     } 


    // v1alpha1_runtime_class->kind
    if(v1alpha1_runtime_class->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1alpha1_runtime_class->kind) == NULL) {
    goto fail; //String
    }
     } 


    // v1alpha1_runtime_class->metadata
    if(v1alpha1_runtime_class->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1alpha1_runtime_class->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1alpha1_runtime_class->spec
    if (!v1alpha1_runtime_class->spec) {
        goto fail;
    }
    
    cJSON *spec_local_JSON = v1alpha1_runtime_class_spec_convertToJSON(v1alpha1_runtime_class->spec);
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

v1alpha1_runtime_class_t *v1alpha1_runtime_class_parseFromJSON(cJSON *v1alpha1_runtime_classJSON){

    v1alpha1_runtime_class_t *v1alpha1_runtime_class_local_var = NULL;

    // v1alpha1_runtime_class->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1alpha1_runtime_classJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // v1alpha1_runtime_class->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1alpha1_runtime_classJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1alpha1_runtime_class->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1alpha1_runtime_classJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1alpha1_runtime_class->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1alpha1_runtime_classJSON, "spec");
    if (!spec) {
        goto end;
    }

    v1alpha1_runtime_class_spec_t *spec_local_nonprim = NULL;
    
    spec_local_nonprim = v1alpha1_runtime_class_spec_parseFromJSON(spec); //nonprimitive


    v1alpha1_runtime_class_local_var = v1alpha1_runtime_class_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec_local_nonprim
        );

    return v1alpha1_runtime_class_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1alpha1_runtime_class_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    return NULL;

}
