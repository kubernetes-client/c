#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_node_allocatable_mapping.h"



static v1_node_allocatable_mapping_t *v1_node_allocatable_mapping_create_internal(
    char *capacity_key,
    char *capacity_multiplier,
    char *device_multiplier
    ) {
    v1_node_allocatable_mapping_t *v1_node_allocatable_mapping_local_var = malloc(sizeof(v1_node_allocatable_mapping_t));
    if (!v1_node_allocatable_mapping_local_var) {
        return NULL;
    }
    memset(v1_node_allocatable_mapping_local_var, 0, sizeof(v1_node_allocatable_mapping_t));
    v1_node_allocatable_mapping_local_var->_library_owned = 1;
    v1_node_allocatable_mapping_local_var->capacity_key = capacity_key;
    v1_node_allocatable_mapping_local_var->capacity_multiplier = capacity_multiplier;
    v1_node_allocatable_mapping_local_var->device_multiplier = device_multiplier;
    return v1_node_allocatable_mapping_local_var;
}

__attribute__((deprecated)) v1_node_allocatable_mapping_t *v1_node_allocatable_mapping_create(
    char *capacity_key,
    char *capacity_multiplier,
    char *device_multiplier
    ) {
    v1_node_allocatable_mapping_t *result = v1_node_allocatable_mapping_create_internal (
        capacity_key,
        capacity_multiplier,
        device_multiplier
        );
    if (!result) {
    }
    return result;
}

void v1_node_allocatable_mapping_free(v1_node_allocatable_mapping_t *v1_node_allocatable_mapping) {
    if(NULL == v1_node_allocatable_mapping){
        return ;
    }
    if(v1_node_allocatable_mapping->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_node_allocatable_mapping_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_node_allocatable_mapping->capacity_key) {
        free(v1_node_allocatable_mapping->capacity_key);
        v1_node_allocatable_mapping->capacity_key = NULL;
    }
    if (v1_node_allocatable_mapping->capacity_multiplier) {
        free(v1_node_allocatable_mapping->capacity_multiplier);
        v1_node_allocatable_mapping->capacity_multiplier = NULL;
    }
    if (v1_node_allocatable_mapping->device_multiplier) {
        free(v1_node_allocatable_mapping->device_multiplier);
        v1_node_allocatable_mapping->device_multiplier = NULL;
    }
    free(v1_node_allocatable_mapping);
}

cJSON *v1_node_allocatable_mapping_convertToJSON(v1_node_allocatable_mapping_t *v1_node_allocatable_mapping) {
    cJSON *item = cJSON_CreateObject();

    // v1_node_allocatable_mapping->capacity_key
    if(v1_node_allocatable_mapping->capacity_key) {
    if(cJSON_AddStringToObject(item, "capacityKey", v1_node_allocatable_mapping->capacity_key) == NULL) {
    goto fail; //String
    }
    }


    // v1_node_allocatable_mapping->capacity_multiplier
    if(v1_node_allocatable_mapping->capacity_multiplier) {
    if(cJSON_AddStringToObject(item, "capacityMultiplier", v1_node_allocatable_mapping->capacity_multiplier) == NULL) {
    goto fail; //String
    }
    }


    // v1_node_allocatable_mapping->device_multiplier
    if(v1_node_allocatable_mapping->device_multiplier) {
    if(cJSON_AddStringToObject(item, "deviceMultiplier", v1_node_allocatable_mapping->device_multiplier) == NULL) {
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

v1_node_allocatable_mapping_t *v1_node_allocatable_mapping_parseFromJSON(cJSON *v1_node_allocatable_mappingJSON){

    v1_node_allocatable_mapping_t *v1_node_allocatable_mapping_local_var = NULL;

    char *capacity_key_local_str = NULL;

    char *capacity_multiplier_local_str = NULL;

    char *device_multiplier_local_str = NULL;

    // v1_node_allocatable_mapping->capacity_key
    cJSON *capacity_key = cJSON_GetObjectItemCaseSensitive(v1_node_allocatable_mappingJSON, "capacityKey");
    if (cJSON_IsNull(capacity_key)) {
        capacity_key = NULL;
    }
    if (capacity_key) { 
    if(!cJSON_IsString(capacity_key) && !cJSON_IsNull(capacity_key))
    {
    goto end; //String
    }
    }

    // v1_node_allocatable_mapping->capacity_multiplier
    cJSON *capacity_multiplier = cJSON_GetObjectItemCaseSensitive(v1_node_allocatable_mappingJSON, "capacityMultiplier");
    if (cJSON_IsNull(capacity_multiplier)) {
        capacity_multiplier = NULL;
    }
    if (capacity_multiplier) { 
    if(!cJSON_IsString(capacity_multiplier) && !cJSON_IsNull(capacity_multiplier))
    {
    goto end; //String
    }
    }

    // v1_node_allocatable_mapping->device_multiplier
    cJSON *device_multiplier = cJSON_GetObjectItemCaseSensitive(v1_node_allocatable_mappingJSON, "deviceMultiplier");
    if (cJSON_IsNull(device_multiplier)) {
        device_multiplier = NULL;
    }
    if (device_multiplier) { 
    if(!cJSON_IsString(device_multiplier) && !cJSON_IsNull(device_multiplier))
    {
    goto end; //String
    }
    }


    if (capacity_key && !cJSON_IsNull(capacity_key)) capacity_key_local_str = strdup(capacity_key->valuestring);
    if (capacity_multiplier && !cJSON_IsNull(capacity_multiplier)) capacity_multiplier_local_str = strdup(capacity_multiplier->valuestring);
    if (device_multiplier && !cJSON_IsNull(device_multiplier)) device_multiplier_local_str = strdup(device_multiplier->valuestring);

    v1_node_allocatable_mapping_local_var = v1_node_allocatable_mapping_create_internal (
        capacity_key_local_str,
        capacity_multiplier_local_str,
        device_multiplier_local_str
        );

    if (!v1_node_allocatable_mapping_local_var) {
        goto end;
    }

    return v1_node_allocatable_mapping_local_var;
end:
    if (capacity_key_local_str) {
        free(capacity_key_local_str);
        capacity_key_local_str = NULL;
    }
    if (capacity_multiplier_local_str) {
        free(capacity_multiplier_local_str);
        capacity_multiplier_local_str = NULL;
    }
    if (device_multiplier_local_str) {
        free(device_multiplier_local_str);
        device_multiplier_local_str = NULL;
    }
    return NULL;

}
