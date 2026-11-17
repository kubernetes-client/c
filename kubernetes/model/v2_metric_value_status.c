#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2_metric_value_status.h"



static v2_metric_value_status_t *v2_metric_value_status_create_internal(
    int *average_utilization,
    char *average_value,
    char *value
    ) {
    v2_metric_value_status_t *v2_metric_value_status_local_var = malloc(sizeof(v2_metric_value_status_t));
    if (!v2_metric_value_status_local_var) {
        return NULL;
    }
    memset(v2_metric_value_status_local_var, 0, sizeof(v2_metric_value_status_t));
    v2_metric_value_status_local_var->_library_owned = 1;
    v2_metric_value_status_local_var->average_utilization = average_utilization;
    v2_metric_value_status_local_var->average_value = average_value;
    v2_metric_value_status_local_var->value = value;
    return v2_metric_value_status_local_var;
}

__attribute__((deprecated)) v2_metric_value_status_t *v2_metric_value_status_create(
    int *average_utilization,
    char *average_value,
    char *value
    ) {
    int *average_utilization_copy = NULL;
    if (average_utilization) {
        average_utilization_copy = malloc(sizeof(int));
        if (average_utilization_copy) *average_utilization_copy = *average_utilization;
    }
    v2_metric_value_status_t *result = v2_metric_value_status_create_internal (
        average_utilization_copy,
        average_value,
        value
        );
    if (!result) {
        free(average_utilization_copy);
    }
    return result;
}

void v2_metric_value_status_free(v2_metric_value_status_t *v2_metric_value_status) {
    if(NULL == v2_metric_value_status){
        return ;
    }
    if(v2_metric_value_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v2_metric_value_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v2_metric_value_status->average_utilization) {
        free(v2_metric_value_status->average_utilization);
        v2_metric_value_status->average_utilization = NULL;
    }
    if (v2_metric_value_status->average_value) {
        free(v2_metric_value_status->average_value);
        v2_metric_value_status->average_value = NULL;
    }
    if (v2_metric_value_status->value) {
        free(v2_metric_value_status->value);
        v2_metric_value_status->value = NULL;
    }
    free(v2_metric_value_status);
}

cJSON *v2_metric_value_status_convertToJSON(v2_metric_value_status_t *v2_metric_value_status) {
    cJSON *item = cJSON_CreateObject();

    // v2_metric_value_status->average_utilization
    if(v2_metric_value_status->average_utilization) {
    if(cJSON_AddNumberToObject(item, "averageUtilization", *v2_metric_value_status->average_utilization) == NULL) {
    goto fail; //Numeric
    }
    }


    // v2_metric_value_status->average_value
    if(v2_metric_value_status->average_value) {
    if(cJSON_AddStringToObject(item, "averageValue", v2_metric_value_status->average_value) == NULL) {
    goto fail; //String
    }
    }


    // v2_metric_value_status->value
    if(v2_metric_value_status->value) {
    if(cJSON_AddStringToObject(item, "value", v2_metric_value_status->value) == NULL) {
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

v2_metric_value_status_t *v2_metric_value_status_parseFromJSON(cJSON *v2_metric_value_statusJSON){

    v2_metric_value_status_t *v2_metric_value_status_local_var = NULL;

    // define the local variable for v2_metric_value_status->average_utilization
    int *average_utilization_local_var = NULL;

    char *average_value_local_str = NULL;

    char *value_local_str = NULL;

    // v2_metric_value_status->average_utilization
    cJSON *average_utilization = cJSON_GetObjectItemCaseSensitive(v2_metric_value_statusJSON, "averageUtilization");
    if (cJSON_IsNull(average_utilization)) {
        average_utilization = NULL;
    }
    if (average_utilization) { 
    if(!cJSON_IsNumber(average_utilization))
    {
    goto end; //Numeric
    }
    average_utilization_local_var = malloc(sizeof(int));
    if(!average_utilization_local_var)
    {
        goto end;
    }
    *average_utilization_local_var = average_utilization->valuedouble;
    }

    // v2_metric_value_status->average_value
    cJSON *average_value = cJSON_GetObjectItemCaseSensitive(v2_metric_value_statusJSON, "averageValue");
    if (cJSON_IsNull(average_value)) {
        average_value = NULL;
    }
    if (average_value) { 
    if(!cJSON_IsString(average_value) && !cJSON_IsNull(average_value))
    {
    goto end; //String
    }
    }

    // v2_metric_value_status->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(v2_metric_value_statusJSON, "value");
    if (cJSON_IsNull(value)) {
        value = NULL;
    }
    if (value) { 
    if(!cJSON_IsString(value) && !cJSON_IsNull(value))
    {
    goto end; //String
    }
    }


    if (average_value && !cJSON_IsNull(average_value)) average_value_local_str = strdup(average_value->valuestring);
    if (value && !cJSON_IsNull(value)) value_local_str = strdup(value->valuestring);

    v2_metric_value_status_local_var = v2_metric_value_status_create_internal (
        average_utilization_local_var,
        average_value_local_str,
        value_local_str
        );

    if (!v2_metric_value_status_local_var) {
        goto end;
    }

    return v2_metric_value_status_local_var;
end:
    if (average_utilization_local_var) {
        free(average_utilization_local_var);
        average_utilization_local_var = NULL;
    }
    if (average_value_local_str) {
        free(average_value_local_str);
        average_value_local_str = NULL;
    }
    if (value_local_str) {
        free(value_local_str);
        value_local_str = NULL;
    }
    return NULL;

}
