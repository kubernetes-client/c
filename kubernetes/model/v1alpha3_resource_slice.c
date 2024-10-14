#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_resource_slice.h"



v1alpha3_resource_slice_t *v1alpha3_resource_slice_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha3_resource_slice_spec_t *spec
    ) {
    v1alpha3_resource_slice_t *v1alpha3_resource_slice_local_var = malloc(sizeof(v1alpha3_resource_slice_t));
    if (!v1alpha3_resource_slice_local_var) {
        return NULL;
    }
    v1alpha3_resource_slice_local_var->api_version = api_version;
    v1alpha3_resource_slice_local_var->kind = kind;
    v1alpha3_resource_slice_local_var->metadata = metadata;
    v1alpha3_resource_slice_local_var->spec = spec;

    return v1alpha3_resource_slice_local_var;
}


void v1alpha3_resource_slice_free(v1alpha3_resource_slice_t *v1alpha3_resource_slice) {
    if(NULL == v1alpha3_resource_slice){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_resource_slice->api_version) {
        free(v1alpha3_resource_slice->api_version);
        v1alpha3_resource_slice->api_version = NULL;
    }
    if (v1alpha3_resource_slice->kind) {
        free(v1alpha3_resource_slice->kind);
        v1alpha3_resource_slice->kind = NULL;
    }
    if (v1alpha3_resource_slice->metadata) {
        v1_object_meta_free(v1alpha3_resource_slice->metadata);
        v1alpha3_resource_slice->metadata = NULL;
    }
    if (v1alpha3_resource_slice->spec) {
        v1alpha3_resource_slice_spec_free(v1alpha3_resource_slice->spec);
        v1alpha3_resource_slice->spec = NULL;
    }
    free(v1alpha3_resource_slice);
}

cJSON *v1alpha3_resource_slice_convertToJSON(v1alpha3_resource_slice_t *v1alpha3_resource_slice) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_resource_slice->api_version
    if(v1alpha3_resource_slice->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1alpha3_resource_slice->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha3_resource_slice->kind
    if(v1alpha3_resource_slice->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1alpha3_resource_slice->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha3_resource_slice->metadata
    if(v1alpha3_resource_slice->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1alpha3_resource_slice->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha3_resource_slice->spec
    if (!v1alpha3_resource_slice->spec) {
        goto fail;
    }
    cJSON *spec_local_JSON = v1alpha3_resource_slice_spec_convertToJSON(v1alpha3_resource_slice->spec);
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

v1alpha3_resource_slice_t *v1alpha3_resource_slice_parseFromJSON(cJSON *v1alpha3_resource_sliceJSON){

    v1alpha3_resource_slice_t *v1alpha3_resource_slice_local_var = NULL;

    // define the local variable for v1alpha3_resource_slice->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1alpha3_resource_slice->spec
    v1alpha3_resource_slice_spec_t *spec_local_nonprim = NULL;

    // v1alpha3_resource_slice->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_sliceJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1alpha3_resource_slice->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_sliceJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1alpha3_resource_slice->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_sliceJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1alpha3_resource_slice->spec
    cJSON *spec = cJSON_GetObjectItemCaseSensitive(v1alpha3_resource_sliceJSON, "spec");
    if (!spec) {
        goto end;
    }

    
    spec_local_nonprim = v1alpha3_resource_slice_spec_parseFromJSON(spec); //nonprimitive


    v1alpha3_resource_slice_local_var = v1alpha3_resource_slice_create (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        spec_local_nonprim
        );

    return v1alpha3_resource_slice_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (spec_local_nonprim) {
        v1alpha3_resource_slice_spec_free(spec_local_nonprim);
        spec_local_nonprim = NULL;
    }
    return NULL;

}
