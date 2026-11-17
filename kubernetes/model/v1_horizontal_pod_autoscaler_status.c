#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_horizontal_pod_autoscaler_status.h"



static v1_horizontal_pod_autoscaler_status_t *v1_horizontal_pod_autoscaler_status_create_internal(
    int *current_cpu_utilization_percentage,
    int *current_replicas,
    int *desired_replicas,
    char *last_scale_time,
    long *observed_generation
    ) {
    v1_horizontal_pod_autoscaler_status_t *v1_horizontal_pod_autoscaler_status_local_var = malloc(sizeof(v1_horizontal_pod_autoscaler_status_t));
    if (!v1_horizontal_pod_autoscaler_status_local_var) {
        return NULL;
    }
    memset(v1_horizontal_pod_autoscaler_status_local_var, 0, sizeof(v1_horizontal_pod_autoscaler_status_t));
    v1_horizontal_pod_autoscaler_status_local_var->_library_owned = 1;
    v1_horizontal_pod_autoscaler_status_local_var->current_cpu_utilization_percentage = current_cpu_utilization_percentage;
    v1_horizontal_pod_autoscaler_status_local_var->current_replicas = current_replicas;
    v1_horizontal_pod_autoscaler_status_local_var->desired_replicas = desired_replicas;
    v1_horizontal_pod_autoscaler_status_local_var->last_scale_time = last_scale_time;
    v1_horizontal_pod_autoscaler_status_local_var->observed_generation = observed_generation;
    return v1_horizontal_pod_autoscaler_status_local_var;
}

__attribute__((deprecated)) v1_horizontal_pod_autoscaler_status_t *v1_horizontal_pod_autoscaler_status_create(
    int *current_cpu_utilization_percentage,
    int *current_replicas,
    int *desired_replicas,
    char *last_scale_time,
    long *observed_generation
    ) {
    int *current_cpu_utilization_percentage_copy = NULL;
    if (current_cpu_utilization_percentage) {
        current_cpu_utilization_percentage_copy = malloc(sizeof(int));
        if (current_cpu_utilization_percentage_copy) *current_cpu_utilization_percentage_copy = *current_cpu_utilization_percentage;
    }
    int *current_replicas_copy = NULL;
    if (current_replicas) {
        current_replicas_copy = malloc(sizeof(int));
        if (current_replicas_copy) *current_replicas_copy = *current_replicas;
    }
    int *desired_replicas_copy = NULL;
    if (desired_replicas) {
        desired_replicas_copy = malloc(sizeof(int));
        if (desired_replicas_copy) *desired_replicas_copy = *desired_replicas;
    }
    long *observed_generation_copy = NULL;
    if (observed_generation) {
        observed_generation_copy = malloc(sizeof(long));
        if (observed_generation_copy) *observed_generation_copy = *observed_generation;
    }
    v1_horizontal_pod_autoscaler_status_t *result = v1_horizontal_pod_autoscaler_status_create_internal (
        current_cpu_utilization_percentage_copy,
        current_replicas_copy,
        desired_replicas_copy,
        last_scale_time,
        observed_generation_copy
        );
    if (!result) {
        free(current_cpu_utilization_percentage_copy);
        free(current_replicas_copy);
        free(desired_replicas_copy);
        free(observed_generation_copy);
    }
    return result;
}

void v1_horizontal_pod_autoscaler_status_free(v1_horizontal_pod_autoscaler_status_t *v1_horizontal_pod_autoscaler_status) {
    if(NULL == v1_horizontal_pod_autoscaler_status){
        return ;
    }
    if(v1_horizontal_pod_autoscaler_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_horizontal_pod_autoscaler_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_horizontal_pod_autoscaler_status->current_cpu_utilization_percentage) {
        free(v1_horizontal_pod_autoscaler_status->current_cpu_utilization_percentage);
        v1_horizontal_pod_autoscaler_status->current_cpu_utilization_percentage = NULL;
    }
    if (v1_horizontal_pod_autoscaler_status->current_replicas) {
        free(v1_horizontal_pod_autoscaler_status->current_replicas);
        v1_horizontal_pod_autoscaler_status->current_replicas = NULL;
    }
    if (v1_horizontal_pod_autoscaler_status->desired_replicas) {
        free(v1_horizontal_pod_autoscaler_status->desired_replicas);
        v1_horizontal_pod_autoscaler_status->desired_replicas = NULL;
    }
    if (v1_horizontal_pod_autoscaler_status->last_scale_time) {
        free(v1_horizontal_pod_autoscaler_status->last_scale_time);
        v1_horizontal_pod_autoscaler_status->last_scale_time = NULL;
    }
    if (v1_horizontal_pod_autoscaler_status->observed_generation) {
        free(v1_horizontal_pod_autoscaler_status->observed_generation);
        v1_horizontal_pod_autoscaler_status->observed_generation = NULL;
    }
    free(v1_horizontal_pod_autoscaler_status);
}

cJSON *v1_horizontal_pod_autoscaler_status_convertToJSON(v1_horizontal_pod_autoscaler_status_t *v1_horizontal_pod_autoscaler_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_horizontal_pod_autoscaler_status->current_cpu_utilization_percentage
    if(v1_horizontal_pod_autoscaler_status->current_cpu_utilization_percentage) {
    if(cJSON_AddNumberToObject(item, "currentCPUUtilizationPercentage", *v1_horizontal_pod_autoscaler_status->current_cpu_utilization_percentage) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_horizontal_pod_autoscaler_status->current_replicas
    if (!v1_horizontal_pod_autoscaler_status->current_replicas) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "currentReplicas", *v1_horizontal_pod_autoscaler_status->current_replicas) == NULL) {
    goto fail; //Numeric
    }


    // v1_horizontal_pod_autoscaler_status->desired_replicas
    if (!v1_horizontal_pod_autoscaler_status->desired_replicas) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "desiredReplicas", *v1_horizontal_pod_autoscaler_status->desired_replicas) == NULL) {
    goto fail; //Numeric
    }


    // v1_horizontal_pod_autoscaler_status->last_scale_time
    if(v1_horizontal_pod_autoscaler_status->last_scale_time) {
    if(cJSON_AddStringToObject(item, "lastScaleTime", v1_horizontal_pod_autoscaler_status->last_scale_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v1_horizontal_pod_autoscaler_status->observed_generation
    if(v1_horizontal_pod_autoscaler_status->observed_generation) {
    if(cJSON_AddNumberToObject(item, "observedGeneration", *v1_horizontal_pod_autoscaler_status->observed_generation) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_horizontal_pod_autoscaler_status_t *v1_horizontal_pod_autoscaler_status_parseFromJSON(cJSON *v1_horizontal_pod_autoscaler_statusJSON){

    v1_horizontal_pod_autoscaler_status_t *v1_horizontal_pod_autoscaler_status_local_var = NULL;

    // define the local variable for v1_horizontal_pod_autoscaler_status->current_cpu_utilization_percentage
    int *current_cpu_utilization_percentage_local_var = NULL;

    // define the local variable for v1_horizontal_pod_autoscaler_status->current_replicas
    int *current_replicas_local_var = NULL;

    // define the local variable for v1_horizontal_pod_autoscaler_status->desired_replicas
    int *desired_replicas_local_var = NULL;

    char *last_scale_time_local_str = NULL;

    // define the local variable for v1_horizontal_pod_autoscaler_status->observed_generation
    long *observed_generation_local_var = NULL;

    // v1_horizontal_pod_autoscaler_status->current_cpu_utilization_percentage
    cJSON *current_cpu_utilization_percentage = cJSON_GetObjectItemCaseSensitive(v1_horizontal_pod_autoscaler_statusJSON, "currentCPUUtilizationPercentage");
    if (cJSON_IsNull(current_cpu_utilization_percentage)) {
        current_cpu_utilization_percentage = NULL;
    }
    if (current_cpu_utilization_percentage) { 
    if(!cJSON_IsNumber(current_cpu_utilization_percentage))
    {
    goto end; //Numeric
    }
    current_cpu_utilization_percentage_local_var = malloc(sizeof(int));
    if(!current_cpu_utilization_percentage_local_var)
    {
        goto end;
    }
    *current_cpu_utilization_percentage_local_var = current_cpu_utilization_percentage->valuedouble;
    }

    // v1_horizontal_pod_autoscaler_status->current_replicas
    cJSON *current_replicas = cJSON_GetObjectItemCaseSensitive(v1_horizontal_pod_autoscaler_statusJSON, "currentReplicas");
    if (cJSON_IsNull(current_replicas)) {
        current_replicas = NULL;
    }
    if (!current_replicas) {
        goto end;
    }

    
    if(!cJSON_IsNumber(current_replicas))
    {
    goto end; //Numeric
    }
    current_replicas_local_var = malloc(sizeof(int));
    if(!current_replicas_local_var)
    {
        goto end;
    }
    *current_replicas_local_var = current_replicas->valuedouble;

    // v1_horizontal_pod_autoscaler_status->desired_replicas
    cJSON *desired_replicas = cJSON_GetObjectItemCaseSensitive(v1_horizontal_pod_autoscaler_statusJSON, "desiredReplicas");
    if (cJSON_IsNull(desired_replicas)) {
        desired_replicas = NULL;
    }
    if (!desired_replicas) {
        goto end;
    }

    
    if(!cJSON_IsNumber(desired_replicas))
    {
    goto end; //Numeric
    }
    desired_replicas_local_var = malloc(sizeof(int));
    if(!desired_replicas_local_var)
    {
        goto end;
    }
    *desired_replicas_local_var = desired_replicas->valuedouble;

    // v1_horizontal_pod_autoscaler_status->last_scale_time
    cJSON *last_scale_time = cJSON_GetObjectItemCaseSensitive(v1_horizontal_pod_autoscaler_statusJSON, "lastScaleTime");
    if (cJSON_IsNull(last_scale_time)) {
        last_scale_time = NULL;
    }
    if (last_scale_time) { 
    if(!cJSON_IsString(last_scale_time) && !cJSON_IsNull(last_scale_time))
    {
    goto end; //DateTime
    }
    }

    // v1_horizontal_pod_autoscaler_status->observed_generation
    cJSON *observed_generation = cJSON_GetObjectItemCaseSensitive(v1_horizontal_pod_autoscaler_statusJSON, "observedGeneration");
    if (cJSON_IsNull(observed_generation)) {
        observed_generation = NULL;
    }
    if (observed_generation) { 
    if(!cJSON_IsNumber(observed_generation))
    {
    goto end; //Numeric
    }
    observed_generation_local_var = malloc(sizeof(long));
    if(!observed_generation_local_var)
    {
        goto end;
    }
    *observed_generation_local_var = observed_generation->valuedouble;
    }


    if (last_scale_time && !cJSON_IsNull(last_scale_time)) last_scale_time_local_str = strdup(last_scale_time->valuestring);

    v1_horizontal_pod_autoscaler_status_local_var = v1_horizontal_pod_autoscaler_status_create_internal (
        current_cpu_utilization_percentage_local_var,
        current_replicas_local_var,
        desired_replicas_local_var,
        last_scale_time_local_str,
        observed_generation_local_var
        );

    if (!v1_horizontal_pod_autoscaler_status_local_var) {
        goto end;
    }

    return v1_horizontal_pod_autoscaler_status_local_var;
end:
    if (current_cpu_utilization_percentage_local_var) {
        free(current_cpu_utilization_percentage_local_var);
        current_cpu_utilization_percentage_local_var = NULL;
    }
    if (current_replicas_local_var) {
        free(current_replicas_local_var);
        current_replicas_local_var = NULL;
    }
    if (desired_replicas_local_var) {
        free(desired_replicas_local_var);
        desired_replicas_local_var = NULL;
    }
    if (last_scale_time_local_str) {
        free(last_scale_time_local_str);
        last_scale_time_local_str = NULL;
    }
    if (observed_generation_local_var) {
        free(observed_generation_local_var);
        observed_generation_local_var = NULL;
    }
    return NULL;

}
