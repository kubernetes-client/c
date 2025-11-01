#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_capacity_request_policy_range.h"



static v1beta2_capacity_request_policy_range_t *v1beta2_capacity_request_policy_range_create_internal(
    char *max,
    char *min,
    char *step
    ) {
    v1beta2_capacity_request_policy_range_t *v1beta2_capacity_request_policy_range_local_var = malloc(sizeof(v1beta2_capacity_request_policy_range_t));
    if (!v1beta2_capacity_request_policy_range_local_var) {
        return NULL;
    }
    v1beta2_capacity_request_policy_range_local_var->max = max;
    v1beta2_capacity_request_policy_range_local_var->min = min;
    v1beta2_capacity_request_policy_range_local_var->step = step;

    v1beta2_capacity_request_policy_range_local_var->_library_owned = 1;
    return v1beta2_capacity_request_policy_range_local_var;
}

__attribute__((deprecated)) v1beta2_capacity_request_policy_range_t *v1beta2_capacity_request_policy_range_create(
    char *max,
    char *min,
    char *step
    ) {
    return v1beta2_capacity_request_policy_range_create_internal (
        max,
        min,
        step
        );
}

void v1beta2_capacity_request_policy_range_free(v1beta2_capacity_request_policy_range_t *v1beta2_capacity_request_policy_range) {
    if(NULL == v1beta2_capacity_request_policy_range){
        return ;
    }
    if(v1beta2_capacity_request_policy_range->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta2_capacity_request_policy_range_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta2_capacity_request_policy_range->max) {
        free(v1beta2_capacity_request_policy_range->max);
        v1beta2_capacity_request_policy_range->max = NULL;
    }
    if (v1beta2_capacity_request_policy_range->min) {
        free(v1beta2_capacity_request_policy_range->min);
        v1beta2_capacity_request_policy_range->min = NULL;
    }
    if (v1beta2_capacity_request_policy_range->step) {
        free(v1beta2_capacity_request_policy_range->step);
        v1beta2_capacity_request_policy_range->step = NULL;
    }
    free(v1beta2_capacity_request_policy_range);
}

cJSON *v1beta2_capacity_request_policy_range_convertToJSON(v1beta2_capacity_request_policy_range_t *v1beta2_capacity_request_policy_range) {
    cJSON *item = cJSON_CreateObject();

    // v1beta2_capacity_request_policy_range->max
    if(v1beta2_capacity_request_policy_range->max) {
    if(cJSON_AddStringToObject(item, "max", v1beta2_capacity_request_policy_range->max) == NULL) {
    goto fail; //String
    }
    }


    // v1beta2_capacity_request_policy_range->min
    if (!v1beta2_capacity_request_policy_range->min) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "min", v1beta2_capacity_request_policy_range->min) == NULL) {
    goto fail; //String
    }


    // v1beta2_capacity_request_policy_range->step
    if(v1beta2_capacity_request_policy_range->step) {
    if(cJSON_AddStringToObject(item, "step", v1beta2_capacity_request_policy_range->step) == NULL) {
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

v1beta2_capacity_request_policy_range_t *v1beta2_capacity_request_policy_range_parseFromJSON(cJSON *v1beta2_capacity_request_policy_rangeJSON){

    v1beta2_capacity_request_policy_range_t *v1beta2_capacity_request_policy_range_local_var = NULL;

    // v1beta2_capacity_request_policy_range->max
    cJSON *max = cJSON_GetObjectItemCaseSensitive(v1beta2_capacity_request_policy_rangeJSON, "max");
    if (cJSON_IsNull(max)) {
        max = NULL;
    }
    if (max) { 
    if(!cJSON_IsString(max) && !cJSON_IsNull(max))
    {
    goto end; //String
    }
    }

    // v1beta2_capacity_request_policy_range->min
    cJSON *min = cJSON_GetObjectItemCaseSensitive(v1beta2_capacity_request_policy_rangeJSON, "min");
    if (cJSON_IsNull(min)) {
        min = NULL;
    }
    if (!min) {
        goto end;
    }

    
    if(!cJSON_IsString(min))
    {
    goto end; //String
    }

    // v1beta2_capacity_request_policy_range->step
    cJSON *step = cJSON_GetObjectItemCaseSensitive(v1beta2_capacity_request_policy_rangeJSON, "step");
    if (cJSON_IsNull(step)) {
        step = NULL;
    }
    if (step) { 
    if(!cJSON_IsString(step) && !cJSON_IsNull(step))
    {
    goto end; //String
    }
    }


    v1beta2_capacity_request_policy_range_local_var = v1beta2_capacity_request_policy_range_create_internal (
        max && !cJSON_IsNull(max) ? strdup(max->valuestring) : NULL,
        strdup(min->valuestring),
        step && !cJSON_IsNull(step) ? strdup(step->valuestring) : NULL
        );

    return v1beta2_capacity_request_policy_range_local_var;
end:
    return NULL;

}
