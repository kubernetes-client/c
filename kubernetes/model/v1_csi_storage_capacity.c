#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_csi_storage_capacity.h"



v1_csi_storage_capacity_t *v1_csi_storage_capacity_create(
    char *api_version,
    char *capacity,
    char *kind,
    char *maximum_volume_size,
    v1_object_meta_t *metadata,
    v1_label_selector_t *node_topology,
    char *storage_class_name
    ) {
    v1_csi_storage_capacity_t *v1_csi_storage_capacity_local_var = malloc(sizeof(v1_csi_storage_capacity_t));
    if (!v1_csi_storage_capacity_local_var) {
        return NULL;
    }
    v1_csi_storage_capacity_local_var->api_version = api_version;
    v1_csi_storage_capacity_local_var->capacity = capacity;
    v1_csi_storage_capacity_local_var->kind = kind;
    v1_csi_storage_capacity_local_var->maximum_volume_size = maximum_volume_size;
    v1_csi_storage_capacity_local_var->metadata = metadata;
    v1_csi_storage_capacity_local_var->node_topology = node_topology;
    v1_csi_storage_capacity_local_var->storage_class_name = storage_class_name;

    return v1_csi_storage_capacity_local_var;
}


void v1_csi_storage_capacity_free(v1_csi_storage_capacity_t *v1_csi_storage_capacity) {
    if(NULL == v1_csi_storage_capacity){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_csi_storage_capacity->api_version) {
        free(v1_csi_storage_capacity->api_version);
        v1_csi_storage_capacity->api_version = NULL;
    }
    if (v1_csi_storage_capacity->capacity) {
        free(v1_csi_storage_capacity->capacity);
        v1_csi_storage_capacity->capacity = NULL;
    }
    if (v1_csi_storage_capacity->kind) {
        free(v1_csi_storage_capacity->kind);
        v1_csi_storage_capacity->kind = NULL;
    }
    if (v1_csi_storage_capacity->maximum_volume_size) {
        free(v1_csi_storage_capacity->maximum_volume_size);
        v1_csi_storage_capacity->maximum_volume_size = NULL;
    }
    if (v1_csi_storage_capacity->metadata) {
        v1_object_meta_free(v1_csi_storage_capacity->metadata);
        v1_csi_storage_capacity->metadata = NULL;
    }
    if (v1_csi_storage_capacity->node_topology) {
        v1_label_selector_free(v1_csi_storage_capacity->node_topology);
        v1_csi_storage_capacity->node_topology = NULL;
    }
    if (v1_csi_storage_capacity->storage_class_name) {
        free(v1_csi_storage_capacity->storage_class_name);
        v1_csi_storage_capacity->storage_class_name = NULL;
    }
    free(v1_csi_storage_capacity);
}

cJSON *v1_csi_storage_capacity_convertToJSON(v1_csi_storage_capacity_t *v1_csi_storage_capacity) {
    cJSON *item = cJSON_CreateObject();

    // v1_csi_storage_capacity->api_version
    if(v1_csi_storage_capacity->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1_csi_storage_capacity->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1_csi_storage_capacity->capacity
    if(v1_csi_storage_capacity->capacity) {
    if(cJSON_AddStringToObject(item, "capacity", v1_csi_storage_capacity->capacity) == NULL) {
    goto fail; //String
    }
    }


    // v1_csi_storage_capacity->kind
    if(v1_csi_storage_capacity->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1_csi_storage_capacity->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1_csi_storage_capacity->maximum_volume_size
    if(v1_csi_storage_capacity->maximum_volume_size) {
    if(cJSON_AddStringToObject(item, "maximumVolumeSize", v1_csi_storage_capacity->maximum_volume_size) == NULL) {
    goto fail; //String
    }
    }


    // v1_csi_storage_capacity->metadata
    if(v1_csi_storage_capacity->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_csi_storage_capacity->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_csi_storage_capacity->node_topology
    if(v1_csi_storage_capacity->node_topology) {
    cJSON *node_topology_local_JSON = v1_label_selector_convertToJSON(v1_csi_storage_capacity->node_topology);
    if(node_topology_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "nodeTopology", node_topology_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_csi_storage_capacity->storage_class_name
    if (!v1_csi_storage_capacity->storage_class_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "storageClassName", v1_csi_storage_capacity->storage_class_name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_csi_storage_capacity_t *v1_csi_storage_capacity_parseFromJSON(cJSON *v1_csi_storage_capacityJSON){

    v1_csi_storage_capacity_t *v1_csi_storage_capacity_local_var = NULL;

    // define the local variable for v1_csi_storage_capacity->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local variable for v1_csi_storage_capacity->node_topology
    v1_label_selector_t *node_topology_local_nonprim = NULL;

    // v1_csi_storage_capacity->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_csi_storage_capacityJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // v1_csi_storage_capacity->capacity
    cJSON *capacity = cJSON_GetObjectItemCaseSensitive(v1_csi_storage_capacityJSON, "capacity");
    if (capacity) { 
    if(!cJSON_IsString(capacity))
    {
    goto end; //String
    }
    }

    // v1_csi_storage_capacity->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_csi_storage_capacityJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_csi_storage_capacity->maximum_volume_size
    cJSON *maximum_volume_size = cJSON_GetObjectItemCaseSensitive(v1_csi_storage_capacityJSON, "maximumVolumeSize");
    if (maximum_volume_size) { 
    if(!cJSON_IsString(maximum_volume_size))
    {
    goto end; //String
    }
    }

    // v1_csi_storage_capacity->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_csi_storage_capacityJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_csi_storage_capacity->node_topology
    cJSON *node_topology = cJSON_GetObjectItemCaseSensitive(v1_csi_storage_capacityJSON, "nodeTopology");
    if (node_topology) { 
    node_topology_local_nonprim = v1_label_selector_parseFromJSON(node_topology); //nonprimitive
    }

    // v1_csi_storage_capacity->storage_class_name
    cJSON *storage_class_name = cJSON_GetObjectItemCaseSensitive(v1_csi_storage_capacityJSON, "storageClassName");
    if (!storage_class_name) {
        goto end;
    }

    
    if(!cJSON_IsString(storage_class_name))
    {
    goto end; //String
    }


    v1_csi_storage_capacity_local_var = v1_csi_storage_capacity_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        capacity ? strdup(capacity->valuestring) : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        maximum_volume_size ? strdup(maximum_volume_size->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        node_topology ? node_topology_local_nonprim : NULL,
        strdup(storage_class_name->valuestring)
        );

    return v1_csi_storage_capacity_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (node_topology_local_nonprim) {
        v1_label_selector_free(node_topology_local_nonprim);
        node_topology_local_nonprim = NULL;
    }
    return NULL;

}
