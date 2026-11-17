#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_node_pod_preemption_policy.h"



static v1_node_pod_preemption_policy_t *v1_node_pod_preemption_policy_create_internal(
    list_t *disable_resize_preemption
    ) {
    v1_node_pod_preemption_policy_t *v1_node_pod_preemption_policy_local_var = malloc(sizeof(v1_node_pod_preemption_policy_t));
    if (!v1_node_pod_preemption_policy_local_var) {
        return NULL;
    }
    memset(v1_node_pod_preemption_policy_local_var, 0, sizeof(v1_node_pod_preemption_policy_t));
    v1_node_pod_preemption_policy_local_var->_library_owned = 1;
    v1_node_pod_preemption_policy_local_var->disable_resize_preemption = disable_resize_preemption;
    return v1_node_pod_preemption_policy_local_var;
}

__attribute__((deprecated)) v1_node_pod_preemption_policy_t *v1_node_pod_preemption_policy_create(
    list_t *disable_resize_preemption
    ) {
    v1_node_pod_preemption_policy_t *result = v1_node_pod_preemption_policy_create_internal (
        disable_resize_preemption
        );
    if (!result) {
    }
    return result;
}

void v1_node_pod_preemption_policy_free(v1_node_pod_preemption_policy_t *v1_node_pod_preemption_policy) {
    if(NULL == v1_node_pod_preemption_policy){
        return ;
    }
    if(v1_node_pod_preemption_policy->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_node_pod_preemption_policy_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_node_pod_preemption_policy->disable_resize_preemption) {
        list_ForEach(listEntry, v1_node_pod_preemption_policy->disable_resize_preemption) {
            free(listEntry->data);
        }
        list_freeList(v1_node_pod_preemption_policy->disable_resize_preemption);
        v1_node_pod_preemption_policy->disable_resize_preemption = NULL;
    }
    free(v1_node_pod_preemption_policy);
}

cJSON *v1_node_pod_preemption_policy_convertToJSON(v1_node_pod_preemption_policy_t *v1_node_pod_preemption_policy) {
    cJSON *item = cJSON_CreateObject();

    // v1_node_pod_preemption_policy->disable_resize_preemption
    if(v1_node_pod_preemption_policy->disable_resize_preemption) {
    cJSON *disable_resize_preemption = cJSON_AddArrayToObject(item, "disableResizePreemption");
    if(disable_resize_preemption == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *disable_resize_preemptionListEntry;
    list_ForEach(disable_resize_preemptionListEntry, v1_node_pod_preemption_policy->disable_resize_preemption) {
    if(cJSON_AddStringToObject(disable_resize_preemption, "", disable_resize_preemptionListEntry->data) == NULL)
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

v1_node_pod_preemption_policy_t *v1_node_pod_preemption_policy_parseFromJSON(cJSON *v1_node_pod_preemption_policyJSON){

    v1_node_pod_preemption_policy_t *v1_node_pod_preemption_policy_local_var = NULL;

    // define the local list for v1_node_pod_preemption_policy->disable_resize_preemption
    list_t *disable_resize_preemptionList = NULL;

    // v1_node_pod_preemption_policy->disable_resize_preemption
    cJSON *disable_resize_preemption = cJSON_GetObjectItemCaseSensitive(v1_node_pod_preemption_policyJSON, "disableResizePreemption");
    if (cJSON_IsNull(disable_resize_preemption)) {
        disable_resize_preemption = NULL;
    }
    if (disable_resize_preemption) { 
    cJSON *disable_resize_preemption_local = NULL;
    if(!cJSON_IsArray(disable_resize_preemption)) {
        goto end;//primitive container
    }
    disable_resize_preemptionList = list_createList();

    cJSON_ArrayForEach(disable_resize_preemption_local, disable_resize_preemption)
    {
        if(!cJSON_IsString(disable_resize_preemption_local))
        {
            goto end;
        }
        list_addElement(disable_resize_preemptionList , strdup(disable_resize_preemption_local->valuestring));
    }
    }



    v1_node_pod_preemption_policy_local_var = v1_node_pod_preemption_policy_create_internal (
        disable_resize_preemption ? disable_resize_preemptionList : NULL
        );

    if (!v1_node_pod_preemption_policy_local_var) {
        goto end;
    }

    return v1_node_pod_preemption_policy_local_var;
end:
    if (disable_resize_preemptionList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, disable_resize_preemptionList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(disable_resize_preemptionList);
        disable_resize_preemptionList = NULL;
    }
    return NULL;

}
