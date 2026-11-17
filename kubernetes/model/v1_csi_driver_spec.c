#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_csi_driver_spec.h"



static v1_csi_driver_spec_t *v1_csi_driver_spec_create_internal(
    int *attach_required,
    char *fs_group_policy,
    long *node_allocatable_update_period_seconds,
    int *pod_info_on_mount,
    int *prevent_pod_scheduling_if_missing,
    int *requires_republish,
    int *se_linux_mount,
    int *service_account_token_in_secrets,
    int *storage_capacity,
    list_t *token_requests,
    list_t *volume_lifecycle_modes
    ) {
    v1_csi_driver_spec_t *v1_csi_driver_spec_local_var = malloc(sizeof(v1_csi_driver_spec_t));
    if (!v1_csi_driver_spec_local_var) {
        return NULL;
    }
    memset(v1_csi_driver_spec_local_var, 0, sizeof(v1_csi_driver_spec_t));
    v1_csi_driver_spec_local_var->_library_owned = 1;
    v1_csi_driver_spec_local_var->attach_required = attach_required;
    v1_csi_driver_spec_local_var->fs_group_policy = fs_group_policy;
    v1_csi_driver_spec_local_var->node_allocatable_update_period_seconds = node_allocatable_update_period_seconds;
    v1_csi_driver_spec_local_var->pod_info_on_mount = pod_info_on_mount;
    v1_csi_driver_spec_local_var->prevent_pod_scheduling_if_missing = prevent_pod_scheduling_if_missing;
    v1_csi_driver_spec_local_var->requires_republish = requires_republish;
    v1_csi_driver_spec_local_var->se_linux_mount = se_linux_mount;
    v1_csi_driver_spec_local_var->service_account_token_in_secrets = service_account_token_in_secrets;
    v1_csi_driver_spec_local_var->storage_capacity = storage_capacity;
    v1_csi_driver_spec_local_var->token_requests = token_requests;
    v1_csi_driver_spec_local_var->volume_lifecycle_modes = volume_lifecycle_modes;
    return v1_csi_driver_spec_local_var;
}

__attribute__((deprecated)) v1_csi_driver_spec_t *v1_csi_driver_spec_create(
    int *attach_required,
    char *fs_group_policy,
    long *node_allocatable_update_period_seconds,
    int *pod_info_on_mount,
    int *prevent_pod_scheduling_if_missing,
    int *requires_republish,
    int *se_linux_mount,
    int *service_account_token_in_secrets,
    int *storage_capacity,
    list_t *token_requests,
    list_t *volume_lifecycle_modes
    ) {
    int *attach_required_copy = NULL;
    if (attach_required) {
        attach_required_copy = malloc(sizeof(int));
        if (attach_required_copy) *attach_required_copy = *attach_required;
    }
    long *node_allocatable_update_period_seconds_copy = NULL;
    if (node_allocatable_update_period_seconds) {
        node_allocatable_update_period_seconds_copy = malloc(sizeof(long));
        if (node_allocatable_update_period_seconds_copy) *node_allocatable_update_period_seconds_copy = *node_allocatable_update_period_seconds;
    }
    int *pod_info_on_mount_copy = NULL;
    if (pod_info_on_mount) {
        pod_info_on_mount_copy = malloc(sizeof(int));
        if (pod_info_on_mount_copy) *pod_info_on_mount_copy = *pod_info_on_mount;
    }
    int *prevent_pod_scheduling_if_missing_copy = NULL;
    if (prevent_pod_scheduling_if_missing) {
        prevent_pod_scheduling_if_missing_copy = malloc(sizeof(int));
        if (prevent_pod_scheduling_if_missing_copy) *prevent_pod_scheduling_if_missing_copy = *prevent_pod_scheduling_if_missing;
    }
    int *requires_republish_copy = NULL;
    if (requires_republish) {
        requires_republish_copy = malloc(sizeof(int));
        if (requires_republish_copy) *requires_republish_copy = *requires_republish;
    }
    int *se_linux_mount_copy = NULL;
    if (se_linux_mount) {
        se_linux_mount_copy = malloc(sizeof(int));
        if (se_linux_mount_copy) *se_linux_mount_copy = *se_linux_mount;
    }
    int *service_account_token_in_secrets_copy = NULL;
    if (service_account_token_in_secrets) {
        service_account_token_in_secrets_copy = malloc(sizeof(int));
        if (service_account_token_in_secrets_copy) *service_account_token_in_secrets_copy = *service_account_token_in_secrets;
    }
    int *storage_capacity_copy = NULL;
    if (storage_capacity) {
        storage_capacity_copy = malloc(sizeof(int));
        if (storage_capacity_copy) *storage_capacity_copy = *storage_capacity;
    }
    v1_csi_driver_spec_t *result = v1_csi_driver_spec_create_internal (
        attach_required_copy,
        fs_group_policy,
        node_allocatable_update_period_seconds_copy,
        pod_info_on_mount_copy,
        prevent_pod_scheduling_if_missing_copy,
        requires_republish_copy,
        se_linux_mount_copy,
        service_account_token_in_secrets_copy,
        storage_capacity_copy,
        token_requests,
        volume_lifecycle_modes
        );
    if (!result) {
        free(attach_required_copy);
        free(node_allocatable_update_period_seconds_copy);
        free(pod_info_on_mount_copy);
        free(prevent_pod_scheduling_if_missing_copy);
        free(requires_republish_copy);
        free(se_linux_mount_copy);
        free(service_account_token_in_secrets_copy);
        free(storage_capacity_copy);
    }
    return result;
}

void v1_csi_driver_spec_free(v1_csi_driver_spec_t *v1_csi_driver_spec) {
    if(NULL == v1_csi_driver_spec){
        return ;
    }
    if(v1_csi_driver_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_csi_driver_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_csi_driver_spec->attach_required) {
        free(v1_csi_driver_spec->attach_required);
        v1_csi_driver_spec->attach_required = NULL;
    }
    if (v1_csi_driver_spec->fs_group_policy) {
        free(v1_csi_driver_spec->fs_group_policy);
        v1_csi_driver_spec->fs_group_policy = NULL;
    }
    if (v1_csi_driver_spec->node_allocatable_update_period_seconds) {
        free(v1_csi_driver_spec->node_allocatable_update_period_seconds);
        v1_csi_driver_spec->node_allocatable_update_period_seconds = NULL;
    }
    if (v1_csi_driver_spec->pod_info_on_mount) {
        free(v1_csi_driver_spec->pod_info_on_mount);
        v1_csi_driver_spec->pod_info_on_mount = NULL;
    }
    if (v1_csi_driver_spec->prevent_pod_scheduling_if_missing) {
        free(v1_csi_driver_spec->prevent_pod_scheduling_if_missing);
        v1_csi_driver_spec->prevent_pod_scheduling_if_missing = NULL;
    }
    if (v1_csi_driver_spec->requires_republish) {
        free(v1_csi_driver_spec->requires_republish);
        v1_csi_driver_spec->requires_republish = NULL;
    }
    if (v1_csi_driver_spec->se_linux_mount) {
        free(v1_csi_driver_spec->se_linux_mount);
        v1_csi_driver_spec->se_linux_mount = NULL;
    }
    if (v1_csi_driver_spec->service_account_token_in_secrets) {
        free(v1_csi_driver_spec->service_account_token_in_secrets);
        v1_csi_driver_spec->service_account_token_in_secrets = NULL;
    }
    if (v1_csi_driver_spec->storage_capacity) {
        free(v1_csi_driver_spec->storage_capacity);
        v1_csi_driver_spec->storage_capacity = NULL;
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
    if(cJSON_AddBoolToObject(item, "attachRequired", *v1_csi_driver_spec->attach_required) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_csi_driver_spec->fs_group_policy
    if(v1_csi_driver_spec->fs_group_policy) {
    if(cJSON_AddStringToObject(item, "fsGroupPolicy", v1_csi_driver_spec->fs_group_policy) == NULL) {
    goto fail; //String
    }
    }


    // v1_csi_driver_spec->node_allocatable_update_period_seconds
    if(v1_csi_driver_spec->node_allocatable_update_period_seconds) {
    if(cJSON_AddNumberToObject(item, "nodeAllocatableUpdatePeriodSeconds", *v1_csi_driver_spec->node_allocatable_update_period_seconds) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_csi_driver_spec->pod_info_on_mount
    if(v1_csi_driver_spec->pod_info_on_mount) {
    if(cJSON_AddBoolToObject(item, "podInfoOnMount", *v1_csi_driver_spec->pod_info_on_mount) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_csi_driver_spec->prevent_pod_scheduling_if_missing
    if(v1_csi_driver_spec->prevent_pod_scheduling_if_missing) {
    if(cJSON_AddBoolToObject(item, "preventPodSchedulingIfMissing", *v1_csi_driver_spec->prevent_pod_scheduling_if_missing) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_csi_driver_spec->requires_republish
    if(v1_csi_driver_spec->requires_republish) {
    if(cJSON_AddBoolToObject(item, "requiresRepublish", *v1_csi_driver_spec->requires_republish) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_csi_driver_spec->se_linux_mount
    if(v1_csi_driver_spec->se_linux_mount) {
    if(cJSON_AddBoolToObject(item, "seLinuxMount", *v1_csi_driver_spec->se_linux_mount) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_csi_driver_spec->service_account_token_in_secrets
    if(v1_csi_driver_spec->service_account_token_in_secrets) {
    if(cJSON_AddBoolToObject(item, "serviceAccountTokenInSecrets", *v1_csi_driver_spec->service_account_token_in_secrets) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_csi_driver_spec->storage_capacity
    if(v1_csi_driver_spec->storage_capacity) {
    if(cJSON_AddBoolToObject(item, "storageCapacity", *v1_csi_driver_spec->storage_capacity) == NULL) {
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
    if(cJSON_AddStringToObject(volume_lifecycle_modes, "", volume_lifecycle_modesListEntry->data) == NULL)
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

    // define the local variable for v1_csi_driver_spec->attach_required
    int *attach_required_local_var = NULL;

    char *fs_group_policy_local_str = NULL;

    // define the local variable for v1_csi_driver_spec->node_allocatable_update_period_seconds
    long *node_allocatable_update_period_seconds_local_var = NULL;

    // define the local variable for v1_csi_driver_spec->pod_info_on_mount
    int *pod_info_on_mount_local_var = NULL;

    // define the local variable for v1_csi_driver_spec->prevent_pod_scheduling_if_missing
    int *prevent_pod_scheduling_if_missing_local_var = NULL;

    // define the local variable for v1_csi_driver_spec->requires_republish
    int *requires_republish_local_var = NULL;

    // define the local variable for v1_csi_driver_spec->se_linux_mount
    int *se_linux_mount_local_var = NULL;

    // define the local variable for v1_csi_driver_spec->service_account_token_in_secrets
    int *service_account_token_in_secrets_local_var = NULL;

    // define the local variable for v1_csi_driver_spec->storage_capacity
    int *storage_capacity_local_var = NULL;

    // define the local list for v1_csi_driver_spec->token_requests
    list_t *token_requestsList = NULL;

    // define the local list for v1_csi_driver_spec->volume_lifecycle_modes
    list_t *volume_lifecycle_modesList = NULL;

    // v1_csi_driver_spec->attach_required
    cJSON *attach_required = cJSON_GetObjectItemCaseSensitive(v1_csi_driver_specJSON, "attachRequired");
    if (cJSON_IsNull(attach_required)) {
        attach_required = NULL;
    }
    if (attach_required) { 
    if(!cJSON_IsBool(attach_required))
    {
    goto end; //Bool
    }
    attach_required_local_var = malloc(sizeof(int));
    if(!attach_required_local_var)
    {
        goto end;
    }
    *attach_required_local_var = attach_required->valueint;
    }

    // v1_csi_driver_spec->fs_group_policy
    cJSON *fs_group_policy = cJSON_GetObjectItemCaseSensitive(v1_csi_driver_specJSON, "fsGroupPolicy");
    if (cJSON_IsNull(fs_group_policy)) {
        fs_group_policy = NULL;
    }
    if (fs_group_policy) { 
    if(!cJSON_IsString(fs_group_policy) && !cJSON_IsNull(fs_group_policy))
    {
    goto end; //String
    }
    }

    // v1_csi_driver_spec->node_allocatable_update_period_seconds
    cJSON *node_allocatable_update_period_seconds = cJSON_GetObjectItemCaseSensitive(v1_csi_driver_specJSON, "nodeAllocatableUpdatePeriodSeconds");
    if (cJSON_IsNull(node_allocatable_update_period_seconds)) {
        node_allocatable_update_period_seconds = NULL;
    }
    if (node_allocatable_update_period_seconds) { 
    if(!cJSON_IsNumber(node_allocatable_update_period_seconds))
    {
    goto end; //Numeric
    }
    node_allocatable_update_period_seconds_local_var = malloc(sizeof(long));
    if(!node_allocatable_update_period_seconds_local_var)
    {
        goto end;
    }
    *node_allocatable_update_period_seconds_local_var = node_allocatable_update_period_seconds->valuedouble;
    }

    // v1_csi_driver_spec->pod_info_on_mount
    cJSON *pod_info_on_mount = cJSON_GetObjectItemCaseSensitive(v1_csi_driver_specJSON, "podInfoOnMount");
    if (cJSON_IsNull(pod_info_on_mount)) {
        pod_info_on_mount = NULL;
    }
    if (pod_info_on_mount) { 
    if(!cJSON_IsBool(pod_info_on_mount))
    {
    goto end; //Bool
    }
    pod_info_on_mount_local_var = malloc(sizeof(int));
    if(!pod_info_on_mount_local_var)
    {
        goto end;
    }
    *pod_info_on_mount_local_var = pod_info_on_mount->valueint;
    }

    // v1_csi_driver_spec->prevent_pod_scheduling_if_missing
    cJSON *prevent_pod_scheduling_if_missing = cJSON_GetObjectItemCaseSensitive(v1_csi_driver_specJSON, "preventPodSchedulingIfMissing");
    if (cJSON_IsNull(prevent_pod_scheduling_if_missing)) {
        prevent_pod_scheduling_if_missing = NULL;
    }
    if (prevent_pod_scheduling_if_missing) { 
    if(!cJSON_IsBool(prevent_pod_scheduling_if_missing))
    {
    goto end; //Bool
    }
    prevent_pod_scheduling_if_missing_local_var = malloc(sizeof(int));
    if(!prevent_pod_scheduling_if_missing_local_var)
    {
        goto end;
    }
    *prevent_pod_scheduling_if_missing_local_var = prevent_pod_scheduling_if_missing->valueint;
    }

    // v1_csi_driver_spec->requires_republish
    cJSON *requires_republish = cJSON_GetObjectItemCaseSensitive(v1_csi_driver_specJSON, "requiresRepublish");
    if (cJSON_IsNull(requires_republish)) {
        requires_republish = NULL;
    }
    if (requires_republish) { 
    if(!cJSON_IsBool(requires_republish))
    {
    goto end; //Bool
    }
    requires_republish_local_var = malloc(sizeof(int));
    if(!requires_republish_local_var)
    {
        goto end;
    }
    *requires_republish_local_var = requires_republish->valueint;
    }

    // v1_csi_driver_spec->se_linux_mount
    cJSON *se_linux_mount = cJSON_GetObjectItemCaseSensitive(v1_csi_driver_specJSON, "seLinuxMount");
    if (cJSON_IsNull(se_linux_mount)) {
        se_linux_mount = NULL;
    }
    if (se_linux_mount) { 
    if(!cJSON_IsBool(se_linux_mount))
    {
    goto end; //Bool
    }
    se_linux_mount_local_var = malloc(sizeof(int));
    if(!se_linux_mount_local_var)
    {
        goto end;
    }
    *se_linux_mount_local_var = se_linux_mount->valueint;
    }

    // v1_csi_driver_spec->service_account_token_in_secrets
    cJSON *service_account_token_in_secrets = cJSON_GetObjectItemCaseSensitive(v1_csi_driver_specJSON, "serviceAccountTokenInSecrets");
    if (cJSON_IsNull(service_account_token_in_secrets)) {
        service_account_token_in_secrets = NULL;
    }
    if (service_account_token_in_secrets) { 
    if(!cJSON_IsBool(service_account_token_in_secrets))
    {
    goto end; //Bool
    }
    service_account_token_in_secrets_local_var = malloc(sizeof(int));
    if(!service_account_token_in_secrets_local_var)
    {
        goto end;
    }
    *service_account_token_in_secrets_local_var = service_account_token_in_secrets->valueint;
    }

    // v1_csi_driver_spec->storage_capacity
    cJSON *storage_capacity = cJSON_GetObjectItemCaseSensitive(v1_csi_driver_specJSON, "storageCapacity");
    if (cJSON_IsNull(storage_capacity)) {
        storage_capacity = NULL;
    }
    if (storage_capacity) { 
    if(!cJSON_IsBool(storage_capacity))
    {
    goto end; //Bool
    }
    storage_capacity_local_var = malloc(sizeof(int));
    if(!storage_capacity_local_var)
    {
        goto end;
    }
    *storage_capacity_local_var = storage_capacity->valueint;
    }

    // v1_csi_driver_spec->token_requests
    cJSON *token_requests = cJSON_GetObjectItemCaseSensitive(v1_csi_driver_specJSON, "tokenRequests");
    if (cJSON_IsNull(token_requests)) {
        token_requests = NULL;
    }
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
    if (cJSON_IsNull(volume_lifecycle_modes)) {
        volume_lifecycle_modes = NULL;
    }
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


    if (fs_group_policy && !cJSON_IsNull(fs_group_policy)) fs_group_policy_local_str = strdup(fs_group_policy->valuestring);

    v1_csi_driver_spec_local_var = v1_csi_driver_spec_create_internal (
        attach_required_local_var,
        fs_group_policy_local_str,
        node_allocatable_update_period_seconds_local_var,
        pod_info_on_mount_local_var,
        prevent_pod_scheduling_if_missing_local_var,
        requires_republish_local_var,
        se_linux_mount_local_var,
        service_account_token_in_secrets_local_var,
        storage_capacity_local_var,
        token_requests ? token_requestsList : NULL,
        volume_lifecycle_modes ? volume_lifecycle_modesList : NULL
        );

    if (!v1_csi_driver_spec_local_var) {
        goto end;
    }

    return v1_csi_driver_spec_local_var;
end:
    if (attach_required_local_var) {
        free(attach_required_local_var);
        attach_required_local_var = NULL;
    }
    if (fs_group_policy_local_str) {
        free(fs_group_policy_local_str);
        fs_group_policy_local_str = NULL;
    }
    if (node_allocatable_update_period_seconds_local_var) {
        free(node_allocatable_update_period_seconds_local_var);
        node_allocatable_update_period_seconds_local_var = NULL;
    }
    if (pod_info_on_mount_local_var) {
        free(pod_info_on_mount_local_var);
        pod_info_on_mount_local_var = NULL;
    }
    if (prevent_pod_scheduling_if_missing_local_var) {
        free(prevent_pod_scheduling_if_missing_local_var);
        prevent_pod_scheduling_if_missing_local_var = NULL;
    }
    if (requires_republish_local_var) {
        free(requires_republish_local_var);
        requires_republish_local_var = NULL;
    }
    if (se_linux_mount_local_var) {
        free(se_linux_mount_local_var);
        se_linux_mount_local_var = NULL;
    }
    if (service_account_token_in_secrets_local_var) {
        free(service_account_token_in_secrets_local_var);
        service_account_token_in_secrets_local_var = NULL;
    }
    if (storage_capacity_local_var) {
        free(storage_capacity_local_var);
        storage_capacity_local_var = NULL;
    }
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
