#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha2_resource_slice.h"



v1alpha2_resource_slice_t *v1alpha2_resource_slice_create(
    char *api_version,
    char *driver_name,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha2_named_resources_resources_t *named_resources,
    char *node_name
    ) {
    v1alpha2_resource_slice_t *v1alpha2_resource_slice_local_var = malloc(sizeof(v1alpha2_resource_slice_t));
    if (!v1alpha2_resource_slice_local_var) {
        return NULL;
    }
    v1alpha2_resource_slice_local_var->api_version = api_version;
    v1alpha2_resource_slice_local_var->driver_name = driver_name;
    v1alpha2_resource_slice_local_var->kind = kind;
    v1alpha2_resource_slice_local_var->metadata = metadata;
    v1alpha2_resource_slice_local_var->named_resources = named_resources;
    v1alpha2_resource_slice_local_var->node_name = node_name;

    return v1alpha2_resource_slice_local_var;
}


void v1alpha2_resource_slice_free(v1alpha2_resource_slice_t *v1alpha2_resource_slice) {
    if(NULL == v1alpha2_resource_slice){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha2_resource_slice->api_version) {
        free(v1alpha2_resource_slice->api_version);
        v1alpha2_resource_slice->api_version = NULL;
    }
    if (v1alpha2_resource_slice->driver_name) {
        free(v1alpha2_resource_slice->driver_name);
        v1alpha2_resource_slice->driver_name = NULL;
    }
    if (v1alpha2_resource_slice->kind) {
        free(v1alpha2_resource_slice->kind);
        v1alpha2_resource_slice->kind = NULL;
    }
    if (v1alpha2_resource_slice->metadata) {
        v1_object_meta_free(v1alpha2_resource_slice->metadata);
        v1alpha2_resource_slice->metadata = NULL;
    }
    if (v1alpha2_resource_slice->named_resources) {
        v1alpha2_named_resources_resources_free(v1alpha2_resource_slice->named_resources);
        v1alpha2_resource_slice->named_resources = NULL;
    }
    if (v1alpha2_resource_slice->node_name) {
        free(v1alpha2_resource_slice->node_name);
        v1alpha2_resource_slice->node_name = NULL;
    }
    free(v1alpha2_resource_slice);
}

cJSON *v1alpha2_resource_slice_convertToJSON(v1alpha2_resource_slice_t *v1alpha2_resource_slice) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha2_resource_slice->api_version
    if(v1alpha2_resource_slice->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1alpha2_resource_slice->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha2_resource_slice->driver_name
    if (!v1alpha2_resource_slice->driver_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "driverName", v1alpha2_resource_slice->driver_name) == NULL) {
    goto fail; //String
    }


    // v1alpha2_resource_slice->kind
    if(v1alpha2_resource_slice->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1alpha2_resource_slice->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1alpha2_resource_slice->metadata
    if(v1alpha2_resource_slice->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1alpha2_resource_slice->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha2_resource_slice->named_resources
    if(v1alpha2_resource_slice->named_resources) {
    cJSON *named_resources_local_JSON = v1alpha2_named_resources_resources_convertToJSON(v1alpha2_resource_slice->named_resources);
    if(named_resources_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "namedResources", named_resources_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha2_resource_slice->node_name
    if(v1alpha2_resource_slice->node_name) {
    if(cJSON_AddStringToObject(item, "nodeName", v1alpha2_resource_slice->node_name) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1alpha2_resource_slice_t *v1alpha2_resource_slice_parseFromJSON(cJSON *v1alpha2_resource_sliceJSON){

    v1alpha2_resource_slice_t *v1alpha2_resource_slice_local_var = NULL;

    // define the local variable for v1alpha2_resource_slice->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1alpha2_resource_slice->named_resources
    v1alpha2_named_resources_resources_t *named_resources_local_nonprim = NULL;

    // v1alpha2_resource_slice->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1alpha2_resource_sliceJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1alpha2_resource_slice->driver_name
    cJSON *driver_name = cJSON_GetObjectItemCaseSensitive(v1alpha2_resource_sliceJSON, "driverName");
    if (!driver_name) {
        goto end;
    }

    
    if(!cJSON_IsString(driver_name))
    {
    goto end; //String
    }

    // v1alpha2_resource_slice->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1alpha2_resource_sliceJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1alpha2_resource_slice->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1alpha2_resource_sliceJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1alpha2_resource_slice->named_resources
    cJSON *named_resources = cJSON_GetObjectItemCaseSensitive(v1alpha2_resource_sliceJSON, "namedResources");
    if (named_resources) { 
    named_resources_local_nonprim = v1alpha2_named_resources_resources_parseFromJSON(named_resources); //nonprimitive
    }

    // v1alpha2_resource_slice->node_name
    cJSON *node_name = cJSON_GetObjectItemCaseSensitive(v1alpha2_resource_sliceJSON, "nodeName");
    if (node_name) { 
    if(!cJSON_IsString(node_name) && !cJSON_IsNull(node_name))
    {
    goto end; //String
    }
    }


    v1alpha2_resource_slice_local_var = v1alpha2_resource_slice_create (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        strdup(driver_name->valuestring),
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        named_resources ? named_resources_local_nonprim : NULL,
        node_name && !cJSON_IsNull(node_name) ? strdup(node_name->valuestring) : NULL
        );

    return v1alpha2_resource_slice_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (named_resources_local_nonprim) {
        v1alpha2_named_resources_resources_free(named_resources_local_nonprim);
        named_resources_local_nonprim = NULL;
    }
    return NULL;

}
