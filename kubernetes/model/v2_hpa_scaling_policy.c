#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2_hpa_scaling_policy.h"



static v2_hpa_scaling_policy_t *v2_hpa_scaling_policy_create_internal(
    int *period_seconds,
    char *type,
    int *value
    ) {
    v2_hpa_scaling_policy_t *v2_hpa_scaling_policy_local_var = malloc(sizeof(v2_hpa_scaling_policy_t));
    if (!v2_hpa_scaling_policy_local_var) {
        return NULL;
    }
    memset(v2_hpa_scaling_policy_local_var, 0, sizeof(v2_hpa_scaling_policy_t));
    v2_hpa_scaling_policy_local_var->_library_owned = 1;
    v2_hpa_scaling_policy_local_var->period_seconds = period_seconds;
    v2_hpa_scaling_policy_local_var->type = type;
    v2_hpa_scaling_policy_local_var->value = value;
    return v2_hpa_scaling_policy_local_var;
}

__attribute__((deprecated)) v2_hpa_scaling_policy_t *v2_hpa_scaling_policy_create(
    int *period_seconds,
    char *type,
    int *value
    ) {
    int *period_seconds_copy = NULL;
    if (period_seconds) {
        period_seconds_copy = malloc(sizeof(int));
        if (period_seconds_copy) *period_seconds_copy = *period_seconds;
    }
    int *value_copy = NULL;
    if (value) {
        value_copy = malloc(sizeof(int));
        if (value_copy) *value_copy = *value;
    }
    v2_hpa_scaling_policy_t *result = v2_hpa_scaling_policy_create_internal (
        period_seconds_copy,
        type,
        value_copy
        );
    if (!result) {
        free(period_seconds_copy);
        free(value_copy);
    }
    return result;
}

void v2_hpa_scaling_policy_free(v2_hpa_scaling_policy_t *v2_hpa_scaling_policy) {
    if(NULL == v2_hpa_scaling_policy){
        return ;
    }
    if(v2_hpa_scaling_policy->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v2_hpa_scaling_policy_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v2_hpa_scaling_policy->period_seconds) {
        free(v2_hpa_scaling_policy->period_seconds);
        v2_hpa_scaling_policy->period_seconds = NULL;
    }
    if (v2_hpa_scaling_policy->type) {
        free(v2_hpa_scaling_policy->type);
        v2_hpa_scaling_policy->type = NULL;
    }
    if (v2_hpa_scaling_policy->value) {
        free(v2_hpa_scaling_policy->value);
        v2_hpa_scaling_policy->value = NULL;
    }
    free(v2_hpa_scaling_policy);
}

cJSON *v2_hpa_scaling_policy_convertToJSON(v2_hpa_scaling_policy_t *v2_hpa_scaling_policy) {
    cJSON *item = cJSON_CreateObject();

    // v2_hpa_scaling_policy->period_seconds
    if (!v2_hpa_scaling_policy->period_seconds) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "periodSeconds", *v2_hpa_scaling_policy->period_seconds) == NULL) {
    goto fail; //Numeric
    }


    // v2_hpa_scaling_policy->type
    if (!v2_hpa_scaling_policy->type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "type", v2_hpa_scaling_policy->type) == NULL) {
    goto fail; //String
    }


    // v2_hpa_scaling_policy->value
    if (!v2_hpa_scaling_policy->value) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "value", *v2_hpa_scaling_policy->value) == NULL) {
    goto fail; //Numeric
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v2_hpa_scaling_policy_t *v2_hpa_scaling_policy_parseFromJSON(cJSON *v2_hpa_scaling_policyJSON){

    v2_hpa_scaling_policy_t *v2_hpa_scaling_policy_local_var = NULL;

    // define the local variable for v2_hpa_scaling_policy->period_seconds
    int *period_seconds_local_var = NULL;

    char *type_local_str = NULL;

    // define the local variable for v2_hpa_scaling_policy->value
    int *value_local_var = NULL;

    // v2_hpa_scaling_policy->period_seconds
    cJSON *period_seconds = cJSON_GetObjectItemCaseSensitive(v2_hpa_scaling_policyJSON, "periodSeconds");
    if (cJSON_IsNull(period_seconds)) {
        period_seconds = NULL;
    }
    if (!period_seconds) {
        goto end;
    }

    
    if(!cJSON_IsNumber(period_seconds))
    {
    goto end; //Numeric
    }
    period_seconds_local_var = malloc(sizeof(int));
    if(!period_seconds_local_var)
    {
        goto end;
    }
    *period_seconds_local_var = period_seconds->valuedouble;

    // v2_hpa_scaling_policy->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v2_hpa_scaling_policyJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (!type) {
        goto end;
    }

    
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }

    // v2_hpa_scaling_policy->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(v2_hpa_scaling_policyJSON, "value");
    if (cJSON_IsNull(value)) {
        value = NULL;
    }
    if (!value) {
        goto end;
    }

    
    if(!cJSON_IsNumber(value))
    {
    goto end; //Numeric
    }
    value_local_var = malloc(sizeof(int));
    if(!value_local_var)
    {
        goto end;
    }
    *value_local_var = value->valuedouble;


    if (type && !cJSON_IsNull(type)) type_local_str = strdup(type->valuestring);

    v2_hpa_scaling_policy_local_var = v2_hpa_scaling_policy_create_internal (
        period_seconds_local_var,
        type_local_str,
        value_local_var
        );

    if (!v2_hpa_scaling_policy_local_var) {
        goto end;
    }

    return v2_hpa_scaling_policy_local_var;
end:
    if (period_seconds_local_var) {
        free(period_seconds_local_var);
        period_seconds_local_var = NULL;
    }
    if (type_local_str) {
        free(type_local_str);
        type_local_str = NULL;
    }
    if (value_local_var) {
        free(value_local_var);
        value_local_var = NULL;
    }
    return NULL;

}
