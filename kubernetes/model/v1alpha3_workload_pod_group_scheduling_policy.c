#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_workload_pod_group_scheduling_policy.h"



static v1alpha3_workload_pod_group_scheduling_policy_t *v1alpha3_workload_pod_group_scheduling_policy_create_internal(
    object_t *basic,
    v1alpha3_workload_pod_group_gang_scheduling_policy_t *gang
    ) {
    v1alpha3_workload_pod_group_scheduling_policy_t *v1alpha3_workload_pod_group_scheduling_policy_local_var = malloc(sizeof(v1alpha3_workload_pod_group_scheduling_policy_t));
    if (!v1alpha3_workload_pod_group_scheduling_policy_local_var) {
        return NULL;
    }
    memset(v1alpha3_workload_pod_group_scheduling_policy_local_var, 0, sizeof(v1alpha3_workload_pod_group_scheduling_policy_t));
    v1alpha3_workload_pod_group_scheduling_policy_local_var->_library_owned = 1;
    v1alpha3_workload_pod_group_scheduling_policy_local_var->basic = basic;
    v1alpha3_workload_pod_group_scheduling_policy_local_var->gang = gang;
    return v1alpha3_workload_pod_group_scheduling_policy_local_var;
}

__attribute__((deprecated)) v1alpha3_workload_pod_group_scheduling_policy_t *v1alpha3_workload_pod_group_scheduling_policy_create(
    object_t *basic,
    v1alpha3_workload_pod_group_gang_scheduling_policy_t *gang
    ) {
    v1alpha3_workload_pod_group_scheduling_policy_t *result = v1alpha3_workload_pod_group_scheduling_policy_create_internal (
        basic,
        gang
        );
    if (!result) {
    }
    return result;
}

void v1alpha3_workload_pod_group_scheduling_policy_free(v1alpha3_workload_pod_group_scheduling_policy_t *v1alpha3_workload_pod_group_scheduling_policy) {
    if(NULL == v1alpha3_workload_pod_group_scheduling_policy){
        return ;
    }
    if(v1alpha3_workload_pod_group_scheduling_policy->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha3_workload_pod_group_scheduling_policy_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_workload_pod_group_scheduling_policy->basic) {
        object_free(v1alpha3_workload_pod_group_scheduling_policy->basic);
        v1alpha3_workload_pod_group_scheduling_policy->basic = NULL;
    }
    if (v1alpha3_workload_pod_group_scheduling_policy->gang) {
        v1alpha3_workload_pod_group_gang_scheduling_policy_free(v1alpha3_workload_pod_group_scheduling_policy->gang);
        v1alpha3_workload_pod_group_scheduling_policy->gang = NULL;
    }
    free(v1alpha3_workload_pod_group_scheduling_policy);
}

cJSON *v1alpha3_workload_pod_group_scheduling_policy_convertToJSON(v1alpha3_workload_pod_group_scheduling_policy_t *v1alpha3_workload_pod_group_scheduling_policy) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_workload_pod_group_scheduling_policy->basic
    if(v1alpha3_workload_pod_group_scheduling_policy->basic) {
    cJSON *basic_object = object_convertToJSON(v1alpha3_workload_pod_group_scheduling_policy->basic);
    if(basic_object == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "basic", basic_object);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1alpha3_workload_pod_group_scheduling_policy->gang
    if(v1alpha3_workload_pod_group_scheduling_policy->gang) {
    cJSON *gang_local_JSON = v1alpha3_workload_pod_group_gang_scheduling_policy_convertToJSON(v1alpha3_workload_pod_group_scheduling_policy->gang);
    if(gang_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "gang", gang_local_JSON);
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

v1alpha3_workload_pod_group_scheduling_policy_t *v1alpha3_workload_pod_group_scheduling_policy_parseFromJSON(cJSON *v1alpha3_workload_pod_group_scheduling_policyJSON){

    v1alpha3_workload_pod_group_scheduling_policy_t *v1alpha3_workload_pod_group_scheduling_policy_local_var = NULL;

    // define the local variable for v1alpha3_workload_pod_group_scheduling_policy->gang
    v1alpha3_workload_pod_group_gang_scheduling_policy_t *gang_local_nonprim = NULL;

    // v1alpha3_workload_pod_group_scheduling_policy->basic
    cJSON *basic = cJSON_GetObjectItemCaseSensitive(v1alpha3_workload_pod_group_scheduling_policyJSON, "basic");
    if (cJSON_IsNull(basic)) {
        basic = NULL;
    }
    object_t *basic_local_object = NULL;
    if (basic) { 
    basic_local_object = object_parseFromJSON(basic); //object
    }

    // v1alpha3_workload_pod_group_scheduling_policy->gang
    cJSON *gang = cJSON_GetObjectItemCaseSensitive(v1alpha3_workload_pod_group_scheduling_policyJSON, "gang");
    if (cJSON_IsNull(gang)) {
        gang = NULL;
    }
    if (gang) { 
    gang_local_nonprim = v1alpha3_workload_pod_group_gang_scheduling_policy_parseFromJSON(gang); //nonprimitive
    }



    v1alpha3_workload_pod_group_scheduling_policy_local_var = v1alpha3_workload_pod_group_scheduling_policy_create_internal (
        basic ? basic_local_object : NULL,
        gang ? gang_local_nonprim : NULL
        );

    if (!v1alpha3_workload_pod_group_scheduling_policy_local_var) {
        goto end;
    }

    return v1alpha3_workload_pod_group_scheduling_policy_local_var;
end:
    if (gang_local_nonprim) {
        v1alpha3_workload_pod_group_gang_scheduling_policy_free(gang_local_nonprim);
        gang_local_nonprim = NULL;
    }
    return NULL;

}
