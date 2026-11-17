#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_gang_scheduling_policy.h"



static v1beta1_gang_scheduling_policy_t *v1beta1_gang_scheduling_policy_create_internal(
    int *min_count
    ) {
    v1beta1_gang_scheduling_policy_t *v1beta1_gang_scheduling_policy_local_var = malloc(sizeof(v1beta1_gang_scheduling_policy_t));
    if (!v1beta1_gang_scheduling_policy_local_var) {
        return NULL;
    }
    memset(v1beta1_gang_scheduling_policy_local_var, 0, sizeof(v1beta1_gang_scheduling_policy_t));
    v1beta1_gang_scheduling_policy_local_var->_library_owned = 1;
    v1beta1_gang_scheduling_policy_local_var->min_count = min_count;
    return v1beta1_gang_scheduling_policy_local_var;
}

__attribute__((deprecated)) v1beta1_gang_scheduling_policy_t *v1beta1_gang_scheduling_policy_create(
    int *min_count
    ) {
    int *min_count_copy = NULL;
    if (min_count) {
        min_count_copy = malloc(sizeof(int));
        if (min_count_copy) *min_count_copy = *min_count;
    }
    v1beta1_gang_scheduling_policy_t *result = v1beta1_gang_scheduling_policy_create_internal (
        min_count_copy
        );
    if (!result) {
        free(min_count_copy);
    }
    return result;
}

void v1beta1_gang_scheduling_policy_free(v1beta1_gang_scheduling_policy_t *v1beta1_gang_scheduling_policy) {
    if(NULL == v1beta1_gang_scheduling_policy){
        return ;
    }
    if(v1beta1_gang_scheduling_policy->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta1_gang_scheduling_policy_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_gang_scheduling_policy->min_count) {
        free(v1beta1_gang_scheduling_policy->min_count);
        v1beta1_gang_scheduling_policy->min_count = NULL;
    }
    free(v1beta1_gang_scheduling_policy);
}

cJSON *v1beta1_gang_scheduling_policy_convertToJSON(v1beta1_gang_scheduling_policy_t *v1beta1_gang_scheduling_policy) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_gang_scheduling_policy->min_count
    if (!v1beta1_gang_scheduling_policy->min_count) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "minCount", *v1beta1_gang_scheduling_policy->min_count) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta1_gang_scheduling_policy_t *v1beta1_gang_scheduling_policy_parseFromJSON(cJSON *v1beta1_gang_scheduling_policyJSON){

    v1beta1_gang_scheduling_policy_t *v1beta1_gang_scheduling_policy_local_var = NULL;

    // define the local variable for v1beta1_gang_scheduling_policy->min_count
    int *min_count_local_var = NULL;

    // v1beta1_gang_scheduling_policy->min_count
    cJSON *min_count = cJSON_GetObjectItemCaseSensitive(v1beta1_gang_scheduling_policyJSON, "minCount");
    if (cJSON_IsNull(min_count)) {
        min_count = NULL;
    }
    if (!min_count) {
        goto end;
    }

    
    if(!cJSON_IsNumber(min_count))
    {
    goto end; //Numeric
    }
    min_count_local_var = malloc(sizeof(int));
    if(!min_count_local_var)
    {
        goto end;
    }
    *min_count_local_var = min_count->valuedouble;



    v1beta1_gang_scheduling_policy_local_var = v1beta1_gang_scheduling_policy_create_internal (
        min_count_local_var
        );

    if (!v1beta1_gang_scheduling_policy_local_var) {
        goto end;
    }

    return v1beta1_gang_scheduling_policy_local_var;
end:
    if (min_count_local_var) {
        free(min_count_local_var);
        min_count_local_var = NULL;
    }
    return NULL;

}
