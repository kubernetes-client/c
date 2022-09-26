#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_csi_driver_spec.h"



v1_csi_driver_spec_t *v1_csi_driver_spec_create(
    int attach_required,
    char *fs_group_policy,
    int pod_info_on_mount,
    int requires_republish,
    int se_linux_mount,
    int storage_capacity,
    list_t *token_requests,
    list_t *volume_lifecycle_modes
    ) {
    v1_csi_driver_spec_t *v1_csi_driver_spec_local_var = malloc(sizeof(v1_csi_driver_spec_t));
    if (!v1_csi_driver_spec_local_var) {
        return NULL;
    }
    v1_csi_driver_spec_local_var->attach_required = attach_required;
    v1_csi_driver_spec_local_var->fs_group_policy = fs_group_policy;
    v1_csi_driver_spec_local_var->pod_info_on_mount = pod_info_on_mount;
    v1_csi_driver_spec_local_var->requires_republish = requires_republish;
    v1_csi_driver_spec_local_var->se_linux_mount = se_linux_mount;
    v1_csi_driver_spec_local_var->storage_capacity = storage_capacity;
    v1_csi_driver_spec_local_var->token_requests = token_requests;
    v1_csi_driver_spec_local_var->volume_lifecycle_modes = volume_lifecycle_modes;

    return v1_csi_driver_spec_local_var;
}


void v1_csi_driver_spec_free(v1_csi_driver_spec_t *v1_csi_driver_spec) {
    if(NULL == v1_csi_driver_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_csi_driver_spec->fs_group_policy) {
        free(v1_csi_driver_spec->fs_group_policy);
        v1_csi_driver_spec->fs_group_policy = NULL;
    }
    if (v1_csi_driver_spec->token_requests) {
        list_ForEach(listEntry, v1_csi_driver_spec->token_requests) {
            storage_v1_token_request_free(listEntry->data);
        }
        list_freeList(v1_csi_driver_spec->token_requests);
        v1_csi_driver_spec->token_requests = NULL;
    }
    if (v1_csi_driver_spec->volume_lifecycle_modes) {
        list_ForEach(listEntry, v1_csi_driver_spec->volume_lifecycle_modes) {
            free(listEntry->data);
        }
        list_freeList(v1_csi_driver_spec->volume_lifecycle_modes);
        v1_csi_driver_spec->volume_lifecycle_modes = NULL;
    }
    free(v1_csi_driver_spec);
}

cJSON *v1_csi_driver_spec_convertToJSON(v1_csi_driver_spec_t *v1_csi_driver_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_csi_driver_spec->attach_required
    if(v1_csi_driver_spec->attach_required) {
    if(cJSON_AddBoolToObject(item, "attachRequired", v1_csi_driver_spec->attach_required) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_csi_driver_spec->fs_group_policy
    if(v1_csi_driver_spec->fs_group_policy) {
    if(cJSON_AddStringToObject(item, "fsGroupPolicy", v1_csi_driver_spec->fs_group_policy) == NULL) {
    goto fail; //String
    }
    }


    // v1_csi_driver_spec->pod_info_on_mount
    if(v1_csi_driver_spec->pod_info_on_mount) {
    if(cJSON_AddBoolToObject(item, "podInfoOnMount", v1_csi_driver_spec->pod_info_on_mount) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_csi_driver_spec->requires_republish
    if(v1_csi_driver_spec->requires_republish) {
    if(cJSON_AddBoolToObject(item, "requiresRepublish", v1_csi_driver_spec->requires_republish) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_csi_driver_spec->se_linux_mount
    if(v1_csi_driver_spec->se_linux_mount) {
    if(cJSON_AddBoolToObject(item, "seLinuxMount", v1_csi_driver_spec->se_linux_mount) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_csi_driver_spec->storage_capacity
    if(v1_csi_driver_spec->storage_capacity) {
    if(cJSON_AddBoolToObject(item, "storageCapacity", v1_csi_driver_spec->storage_capacity) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_csi_driver_spec->token_requests
    if(v1_csi_driver_spec->token_requests) {
    cJSON *token_requests = cJSON_AddArrayToObject(item, "tokenRequests");
    if(token_requests == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *token_requestsListEntry;
    if (v1_csi_driver_spec->token_requests) {
    list_ForEach(token_requestsListEntry, v1_csi_driver_spec->token_requests) {
    cJSON *itemLocal = storage_v1_token_request_convertToJSON(token_requestsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(token_requests, itemLocal);
    }
    }
    }


    // v1_csi_driver_spec->volume_lifecycle_modes
    if(v1_csi_driver_spec->volume_lifecycle_modes) {
    cJSON *volume_lifecycle_modes = cJSON_AddArrayToObject(item, "volumeLifecycleModes");
    if(volume_lifecycle_modes == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *volume_lifecycle_modesListEntry;
    list_ForEach(volume_lifecycle_modesListEntry, v1_csi_driver_spec->volume_lifecycle_modes) {
    if(cJSON_AddStringToObject(volume_lifecycle_modes, "", (char*)volume_lifecycle_modesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_csi_driver_spec_t *v1_csi_driver_spec_parseFromJSON(cJSON *v1_csi_driver_specJSON){

    v1_csi_driver_spec_t *v1_csi_driver_spec_local_var = NULL;

    // define the local list for v1_csi_driver_spec->token_requests
    list_t *token_requestsList = NULL;

    // define the local list for v1_csi_driver_spec->volume_lifecycle_modes
    list_t *volume_lifecycle_modesList = NULL;

    // v1_csi_driver_spec->attach_required
    cJSON *attach_required = cJSON_GetObjectItemCaseSensitive(v1_csi_driver_specJSON, "attachRequired");
    if (attach_required) { 
    if(!cJSON_IsBool(attach_required))
    {
    goto end; //Bool
    }
    }

    // v1_csi_driver_spec->fs_group_policy
    cJSON *fs_group_policy = cJSON_GetObjectItemCaseSensitive(v1_csi_driver_specJSON, "fsGroupPolicy");
    if (fs_group_policy) { 
    if(!cJSON_IsString(fs_group_policy))
    {
    goto end; //String
    }
    }

    // v1_csi_driver_spec->pod_info_on_mount
    cJSON *pod_info_on_mount = cJSON_GetObjectItemCaseSensitive(v1_csi_driver_specJSON, "podInfoOnMount");
    if (pod_info_on_mount) { 
    if(!cJSON_IsBool(pod_info_on_mount))
    {
    goto end; //Bool
    }
    }

    // v1_csi_driver_spec->requires_republish
    cJSON *requires_republish = cJSON_GetObjectItemCaseSensitive(v1_csi_driver_specJSON, "requiresRepublish");
    if (requires_republish) { 
    if(!cJSON_IsBool(requires_republish))
    {
    goto end; //Bool
    }
    }

    // v1_csi_driver_spec->se_linux_mount
    cJSON *se_linux_mount = cJSON_GetObjectItemCaseSensitive(v1_csi_driver_specJSON, "seLinuxMount");
    if (se_linux_mount) { 
    if(!cJSON_IsBool(se_linux_mount))
    {
    goto end; //Bool
    }
    }

    // v1_csi_driver_spec->storage_capacity
    cJSON *storage_capacity = cJSON_GetObjectItemCaseSensitive(v1_csi_driver_specJSON, "storageCapacity");
    if (storage_capacity) { 
    if(!cJSON_IsBool(storage_capacity))
    {
    goto end; //Bool
    }
    }

    // v1_csi_driver_spec->token_requests
    cJSON *token_requests = cJSON_GetObjectItemCaseSensitive(v1_csi_driver_specJSON, "tokenRequests");
    if (token_requests) { 
    cJSON *token_requests_local_nonprimitive = NULL;
    if(!cJSON_IsArray(token_requests)){
        goto end; //nonprimitive container
    }

    token_requestsList = list_createList();

    cJSON_ArrayForEach(token_requests_local_nonprimitive,token_requests )
    {
        if(!cJSON_IsObject(token_requests_local_nonprimitive)){
            goto end;
        }
        storage_v1_token_request_t *token_requestsItem = storage_v1_token_request_parseFromJSON(token_requests_local_nonprimitive);

        list_addElement(token_requestsList, token_requestsItem);
    }
    }

    // v1_csi_driver_spec->volume_lifecycle_modes
    cJSON *volume_lifecycle_modes = cJSON_GetObjectItemCaseSensitive(v1_csi_driver_specJSON, "volumeLifecycleModes");
    if (volume_lifecycle_modes) { 
    cJSON *volume_lifecycle_modes_local = NULL;
    if(!cJSON_IsArray(volume_lifecycle_modes)) {
        goto end;//primitive container
    }
    volume_lifecycle_modesList = list_createList();

    cJSON_ArrayForEach(volume_lifecycle_modes_local, volume_lifecycle_modes)
    {
        if(!cJSON_IsString(volume_lifecycle_modes_local))
        {
            goto end;
        }
        list_addElement(volume_lifecycle_modesList , strdup(volume_lifecycle_modes_local->valuestring));
    }
    }


    v1_csi_driver_spec_local_var = v1_csi_driver_spec_create (
        attach_required ? attach_required->valueint : 0,
        fs_group_policy ? strdup(fs_group_policy->valuestring) : NULL,
        pod_info_on_mount ? pod_info_on_mount->valueint : 0,
        requires_republish ? requires_republish->valueint : 0,
        se_linux_mount ? se_linux_mount->valueint : 0,
        storage_capacity ? storage_capacity->valueint : 0,
        token_requests ? token_requestsList : NULL,
        volume_lifecycle_modes ? volume_lifecycle_modesList : NULL
        );

    return v1_csi_driver_spec_local_var;
end:
    if (token_requestsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, token_requestsList) {
            storage_v1_token_request_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(token_requestsList);
        token_requestsList = NULL;
    }
    if (volume_lifecycle_modesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, volume_lifecycle_modesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(volume_lifecycle_modesList);
        volume_lifecycle_modesList = NULL;
    }
    return NULL;

}
