#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_composite_gang_scheduling_policy.h"



static v1beta1_composite_gang_scheduling_policy_t *v1beta1_composite_gang_scheduling_policy_create_internal(
    int *min_group_count
    ) {
    v1beta1_composite_gang_scheduling_policy_t *v1beta1_composite_gang_scheduling_policy_local_var = malloc(sizeof(v1beta1_composite_gang_scheduling_policy_t));
    if (!v1beta1_composite_gang_scheduling_policy_local_var) {
        return NULL;
    }
    memset(v1beta1_composite_gang_scheduling_policy_local_var, 0, sizeof(v1beta1_composite_gang_scheduling_policy_t));
    v1beta1_composite_gang_scheduling_policy_local_var->_library_owned = 1;
    v1beta1_composite_gang_scheduling_policy_local_var->min_group_count = min_group_count;
    return v1beta1_composite_gang_scheduling_policy_local_var;
}

__attribute__((deprecated)) v1beta1_composite_gang_scheduling_policy_t *v1beta1_composite_gang_scheduling_policy_create(
    int *min_group_count
    ) {
    int *min_group_count_copy = NULL;
    if (min_group_count) {
        min_group_count_copy = malloc(sizeof(int));
        if (min_group_count_copy) *min_group_count_copy = *min_group_count;
    }
    v1beta1_composite_gang_scheduling_policy_t *result = v1beta1_composite_gang_scheduling_policy_create_internal (
        min_group_count_copy
        );
    if (!result) {
        free(min_group_count_copy);
    }
    return result;
}

void v1beta1_composite_gang_scheduling_policy_free(v1beta1_composite_gang_scheduling_policy_t *v1beta1_composite_gang_scheduling_policy) {
    if(NULL == v1beta1_composite_gang_scheduling_policy){
        return ;
    }
    if(v1beta1_composite_gang_scheduling_policy->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta1_composite_gang_scheduling_policy_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_composite_gang_scheduling_policy->min_group_count) {
        free(v1beta1_composite_gang_scheduling_policy->min_group_count);
        v1beta1_composite_gang_scheduling_policy->min_group_count = NULL;
    }
    free(v1beta1_composite_gang_scheduling_policy);
}

cJSON *v1beta1_composite_gang_scheduling_policy_convertToJSON(v1beta1_composite_gang_scheduling_policy_t *v1beta1_composite_gang_scheduling_policy) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_composite_gang_scheduling_policy->min_group_count
    if (!v1beta1_composite_gang_scheduling_policy->min_group_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "minGroupCount", *v1beta1_composite_gang_scheduling_policy->min_group_count) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta1_composite_gang_scheduling_policy_t *v1beta1_composite_gang_scheduling_policy_parseFromJSON(cJSON *v1beta1_composite_gang_scheduling_policyJSON){

    v1beta1_composite_gang_scheduling_policy_t *v1beta1_composite_gang_scheduling_policy_local_var = NULL;

    // define the local variable for v1beta1_composite_gang_scheduling_policy->min_group_count
    int *min_group_count_local_var = NULL;

    // v1beta1_composite_gang_scheduling_policy->min_group_count
    cJSON *min_group_count = cJSON_GetObjectItemCaseSensitive(v1beta1_composite_gang_scheduling_policyJSON, "minGroupCount");
    if (cJSON_IsNull(min_group_count)) {
        min_group_count = NULL;
    }
    if (!min_group_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(min_group_count))
    {
    goto end; //Numeric
    }
    min_group_count_local_var = malloc(sizeof(int));
    if(!min_group_count_local_var)
    {
        goto end;
    }
    *min_group_count_local_var = min_group_count->valuedouble;



    v1beta1_composite_gang_scheduling_policy_local_var = v1beta1_composite_gang_scheduling_policy_create_internal (
        min_group_count_local_var
        );

    if (!v1beta1_composite_gang_scheduling_policy_local_var) {
        goto end;
    }

    return v1beta1_composite_gang_scheduling_policy_local_var;
end:
    if (min_group_count_local_var) {
        free(min_group_count_local_var);
        min_group_count_local_var = NULL;
    }
    return NULL;

}
