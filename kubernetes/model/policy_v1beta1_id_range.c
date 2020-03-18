#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "policy_v1beta1_id_range.h"



policy_v1beta1_id_range_t *policy_v1beta1_id_range_create(
    long max,
    long min
    ) {
    policy_v1beta1_id_range_t *policy_v1beta1_id_range_local_var = malloc(sizeof(policy_v1beta1_id_range_t));
    if (!policy_v1beta1_id_range_local_var) {
        return NULL;
    }
    policy_v1beta1_id_range_local_var->max = max;
    policy_v1beta1_id_range_local_var->min = min;

    return policy_v1beta1_id_range_local_var;
}


void policy_v1beta1_id_range_free(policy_v1beta1_id_range_t *policy_v1beta1_id_range) {
    if(NULL == policy_v1beta1_id_range){
        return ;
    }
    listEntry_t *listEntry;
    free(policy_v1beta1_id_range);
}

cJSON *policy_v1beta1_id_range_convertToJSON(policy_v1beta1_id_range_t *policy_v1beta1_id_range) {
    cJSON *item = cJSON_CreateObject();

    // policy_v1beta1_id_range->max
    if (!policy_v1beta1_id_range->max) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "max", policy_v1beta1_id_range->max) == NULL) {
    goto fail; //Numeric
    }


    // policy_v1beta1_id_range->min
    if (!policy_v1beta1_id_range->min) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "min", policy_v1beta1_id_range->min) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

policy_v1beta1_id_range_t *policy_v1beta1_id_range_parseFromJSON(cJSON *policy_v1beta1_id_rangeJSON){

    policy_v1beta1_id_range_t *policy_v1beta1_id_range_local_var = NULL;

    // policy_v1beta1_id_range->max
    cJSON *max = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_id_rangeJSON, "max");
    if (!max) {
        goto end;
    }

    
    if(!cJSON_IsNumber(max))
    {
    goto end; //Numeric
    }

    // policy_v1beta1_id_range->min
    cJSON *min = cJSON_GetObjectItemCaseSensitive(policy_v1beta1_id_rangeJSON, "min");
    if (!min) {
        goto end;
    }

    
    if(!cJSON_IsNumber(min))
    {
    goto end; //Numeric
    }


    policy_v1beta1_id_range_local_var = policy_v1beta1_id_range_create (
        max->valuedouble,
        min->valuedouble
        );

    return policy_v1beta1_id_range_local_var;
end:
    return NULL;

}
