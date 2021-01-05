#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_vsphere_virtual_disk_volume_source.h"



v1_vsphere_virtual_disk_volume_source_t *v1_vsphere_virtual_disk_volume_source_create(
    char *fs_type,
    char *storage_policy_id,
    char *storage_policy_name,
    char *volume_path
    ) {
    v1_vsphere_virtual_disk_volume_source_t *v1_vsphere_virtual_disk_volume_source_local_var = malloc(sizeof(v1_vsphere_virtual_disk_volume_source_t));
    if (!v1_vsphere_virtual_disk_volume_source_local_var) {
        return NULL;
    }
    v1_vsphere_virtual_disk_volume_source_local_var->fs_type = fs_type;
    v1_vsphere_virtual_disk_volume_source_local_var->storage_policy_id = storage_policy_id;
    v1_vsphere_virtual_disk_volume_source_local_var->storage_policy_name = storage_policy_name;
    v1_vsphere_virtual_disk_volume_source_local_var->volume_path = volume_path;

    return v1_vsphere_virtual_disk_volume_source_local_var;
}


void v1_vsphere_virtual_disk_volume_source_free(v1_vsphere_virtual_disk_volume_source_t *v1_vsphere_virtual_disk_volume_source) {
    if(NULL == v1_vsphere_virtual_disk_volume_source){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_vsphere_virtual_disk_volume_source->fs_type) {
        free(v1_vsphere_virtual_disk_volume_source->fs_type);
        v1_vsphere_virtual_disk_volume_source->fs_type = NULL;
    }
    if (v1_vsphere_virtual_disk_volume_source->storage_policy_id) {
        free(v1_vsphere_virtual_disk_volume_source->storage_policy_id);
        v1_vsphere_virtual_disk_volume_source->storage_policy_id = NULL;
    }
    if (v1_vsphere_virtual_disk_volume_source->storage_policy_name) {
        free(v1_vsphere_virtual_disk_volume_source->storage_policy_name);
        v1_vsphere_virtual_disk_volume_source->storage_policy_name = NULL;
    }
    if (v1_vsphere_virtual_disk_volume_source->volume_path) {
        free(v1_vsphere_virtual_disk_volume_source->volume_path);
        v1_vsphere_virtual_disk_volume_source->volume_path = NULL;
    }
    free(v1_vsphere_virtual_disk_volume_source);
}

cJSON *v1_vsphere_virtual_disk_volume_source_convertToJSON(v1_vsphere_virtual_disk_volume_source_t *v1_vsphere_virtual_disk_volume_source) {
    cJSON *item = cJSON_CreateObject();

    // v1_vsphere_virtual_disk_volume_source->fs_type
    if(v1_vsphere_virtual_disk_volume_source->fs_type) { 
    if(cJSON_AddStringToObject(item, "fsType", v1_vsphere_virtual_disk_volume_source->fs_type) == NULL) {
    goto fail; //String
    }
     } 


    // v1_vsphere_virtual_disk_volume_source->storage_policy_id
    if(v1_vsphere_virtual_disk_volume_source->storage_policy_id) { 
    if(cJSON_AddStringToObject(item, "storagePolicyID", v1_vsphere_virtual_disk_volume_source->storage_policy_id) == NULL) {
    goto fail; //String
    }
     } 


    // v1_vsphere_virtual_disk_volume_source->storage_policy_name
    if(v1_vsphere_virtual_disk_volume_source->storage_policy_name) { 
    if(cJSON_AddStringToObject(item, "storagePolicyName", v1_vsphere_virtual_disk_volume_source->storage_policy_name) == NULL) {
    goto fail; //String
    }
     } 


    // v1_vsphere_virtual_disk_volume_source->volume_path
    if (!v1_vsphere_virtual_disk_volume_source->volume_path) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "volumePath", v1_vsphere_virtual_disk_volume_source->volume_path) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_vsphere_virtual_disk_volume_source_t *v1_vsphere_virtual_disk_volume_source_parseFromJSON(cJSON *v1_vsphere_virtual_disk_volume_sourceJSON){

    v1_vsphere_virtual_disk_volume_source_t *v1_vsphere_virtual_disk_volume_source_local_var = NULL;

    // v1_vsphere_virtual_disk_volume_source->fs_type
    cJSON *fs_type = cJSON_GetObjectItemCaseSensitive(v1_vsphere_virtual_disk_volume_sourceJSON, "fsType");
    if (fs_type) { 
    if(!cJSON_IsString(fs_type))
    {
    goto end; //String
    }
    }

    // v1_vsphere_virtual_disk_volume_source->storage_policy_id
    cJSON *storage_policy_id = cJSON_GetObjectItemCaseSensitive(v1_vsphere_virtual_disk_volume_sourceJSON, "storagePolicyID");
    if (storage_policy_id) { 
    if(!cJSON_IsString(storage_policy_id))
    {
    goto end; //String
    }
    }

    // v1_vsphere_virtual_disk_volume_source->storage_policy_name
    cJSON *storage_policy_name = cJSON_GetObjectItemCaseSensitive(v1_vsphere_virtual_disk_volume_sourceJSON, "storagePolicyName");
    if (storage_policy_name) { 
    if(!cJSON_IsString(storage_policy_name))
    {
    goto end; //String
    }
    }

    // v1_vsphere_virtual_disk_volume_source->volume_path
    cJSON *volume_path = cJSON_GetObjectItemCaseSensitive(v1_vsphere_virtual_disk_volume_sourceJSON, "volumePath");
    if (!volume_path) {
        goto end;
    }

    
    if(!cJSON_IsString(volume_path))
    {
    goto end; //String
    }


    v1_vsphere_virtual_disk_volume_source_local_var = v1_vsphere_virtual_disk_volume_source_create (
        fs_type ? strdup(fs_type->valuestring) : NULL,
        storage_policy_id ? strdup(storage_policy_id->valuestring) : NULL,
        storage_policy_name ? strdup(storage_policy_name->valuestring) : NULL,
        strdup(volume_path->valuestring)
        );

    return v1_vsphere_virtual_disk_volume_source_local_var;
end:
    return NULL;

}
