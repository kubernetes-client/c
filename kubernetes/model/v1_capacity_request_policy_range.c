#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_capacity_request_policy_range.h"



static v1_capacity_request_policy_range_t *v1_capacity_request_policy_range_create_internal(
    char *max,
    char *min,
    char *step
    ) {
    v1_capacity_request_policy_range_t *v1_capacity_request_policy_range_local_var = malloc(sizeof(v1_capacity_request_policy_range_t));
    if (!v1_capacity_request_policy_range_local_var) {
        return NULL;
    }
    v1_capacity_request_policy_range_local_var->max = max;
    v1_capacity_request_policy_range_local_var->min = min;
    v1_capacity_request_policy_range_local_var->step = step;

    v1_capacity_request_policy_range_local_var->_library_owned = 1;
    return v1_capacity_request_policy_range_local_var;
}

__attribute__((deprecated)) v1_capacity_request_policy_range_t *v1_capacity_request_policy_range_create(
    char *max,
    char *min,
    char *step
    ) {
    return v1_capacity_request_policy_range_create_internal (
        max,
        min,
        step
        );
}

void v1_capacity_request_policy_range_free(v1_capacity_request_policy_range_t *v1_capacity_request_policy_range) {
    if(NULL == v1_capacity_request_policy_range){
        return ;
    }
    if(v1_capacity_request_policy_range->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_capacity_request_policy_range_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_capacity_request_policy_range->max) {
        free(v1_capacity_request_policy_range->max);
        v1_capacity_request_policy_range->max = NULL;
    }
    if (v1_capacity_request_policy_range->min) {
        free(v1_capacity_request_policy_range->min);
        v1_capacity_request_policy_range->min = NULL;
    }
    if (v1_capacity_request_policy_range->step) {
        free(v1_capacity_request_policy_range->step);
        v1_capacity_request_policy_range->step = NULL;
    }
    free(v1_capacity_request_policy_range);
}

cJSON *v1_capacity_request_policy_range_convertToJSON(v1_capacity_request_policy_range_t *v1_capacity_request_policy_range) {
    cJSON *item = cJSON_CreateObject();

    // v1_capacity_request_policy_range->max
    if(v1_capacity_request_policy_range->max) {
    if(cJSON_AddStringToObject(item, "max", v1_capacity_request_policy_range->max) == NULL) {
    goto fail; //String
    }
    }


    // v1_capacity_request_policy_range->min
    if (!v1_capacity_request_policy_range->min) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "min", v1_capacity_request_policy_range->min) == NULL) {
    goto fail; //String
    }


    // v1_capacity_request_policy_range->step
    if(v1_capacity_request_policy_range->step) {
    if(cJSON_AddStringToObject(item, "step", v1_capacity_request_policy_range->step) == NULL) {
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

v1_capacity_request_policy_range_t *v1_capacity_request_policy_range_parseFromJSON(cJSON *v1_capacity_request_policy_rangeJSON){

    v1_capacity_request_policy_range_t *v1_capacity_request_policy_range_local_var = NULL;

    // v1_capacity_request_policy_range->max
    cJSON *max = cJSON_GetObjectItemCaseSensitive(v1_capacity_request_policy_rangeJSON, "max");
    if (cJSON_IsNull(max)) {
        max = NULL;
    }
    if (max) { 
    if(!cJSON_IsString(max) && !cJSON_IsNull(max))
    {
    goto end; //String
    }
    }

    // v1_capacity_request_policy_range->min
    cJSON *min = cJSON_GetObjectItemCaseSensitive(v1_capacity_request_policy_rangeJSON, "min");
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

    // v1_capacity_request_policy_range->step
    cJSON *step = cJSON_GetObjectItemCaseSensitive(v1_capacity_request_policy_rangeJSON, "step");
    if (cJSON_IsNull(step)) {
        step = NULL;
    }
    if (step) { 
    if(!cJSON_IsString(step) && !cJSON_IsNull(step))
    {
    goto end; //String
    }
    }


    v1_capacity_request_policy_range_local_var = v1_capacity_request_policy_range_create_internal (
        max && !cJSON_IsNull(max) ? strdup(max->valuestring) : NULL,
        strdup(min->valuestring),
        step && !cJSON_IsNull(step) ? strdup(step->valuestring) : NULL
        );

    return v1_capacity_request_policy_range_local_var;
end:
    return NULL;

}
