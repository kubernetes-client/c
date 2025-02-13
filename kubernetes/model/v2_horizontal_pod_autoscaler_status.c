#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2_horizontal_pod_autoscaler_status.h"



static v2_horizontal_pod_autoscaler_status_t *v2_horizontal_pod_autoscaler_status_create_internal(
    list_t *conditions,
    list_t *current_metrics,
    int current_replicas,
    int desired_replicas,
    char *last_scale_time,
    long observed_generation
    ) {
    v2_horizontal_pod_autoscaler_status_t *v2_horizontal_pod_autoscaler_status_local_var = malloc(sizeof(v2_horizontal_pod_autoscaler_status_t));
    if (!v2_horizontal_pod_autoscaler_status_local_var) {
        return NULL;
    }
    v2_horizontal_pod_autoscaler_status_local_var->conditions = conditions;
    v2_horizontal_pod_autoscaler_status_local_var->current_metrics = current_metrics;
    v2_horizontal_pod_autoscaler_status_local_var->current_replicas = current_replicas;
    v2_horizontal_pod_autoscaler_status_local_var->desired_replicas = desired_replicas;
    v2_horizontal_pod_autoscaler_status_local_var->last_scale_time = last_scale_time;
    v2_horizontal_pod_autoscaler_status_local_var->observed_generation = observed_generation;

    v2_horizontal_pod_autoscaler_status_local_var->_library_owned = 1;
    return v2_horizontal_pod_autoscaler_status_local_var;
}

__attribute__((deprecated)) v2_horizontal_pod_autoscaler_status_t *v2_horizontal_pod_autoscaler_status_create(
    list_t *conditions,
    list_t *current_metrics,
    int current_replicas,
    int desired_replicas,
    char *last_scale_time,
    long observed_generation
    ) {
    return v2_horizontal_pod_autoscaler_status_create_internal (
        conditions,
        current_metrics,
        current_replicas,
        desired_replicas,
        last_scale_time,
        observed_generation
        );
}

void v2_horizontal_pod_autoscaler_status_free(v2_horizontal_pod_autoscaler_status_t *v2_horizontal_pod_autoscaler_status) {
    if(NULL == v2_horizontal_pod_autoscaler_status){
        return ;
    }
    if(v2_horizontal_pod_autoscaler_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v2_horizontal_pod_autoscaler_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v2_horizontal_pod_autoscaler_status->conditions) {
        list_ForEach(listEntry, v2_horizontal_pod_autoscaler_status->conditions) {
            v2_horizontal_pod_autoscaler_condition_free(listEntry->data);
        }
        list_freeList(v2_horizontal_pod_autoscaler_status->conditions);
        v2_horizontal_pod_autoscaler_status->conditions = NULL;
    }
    if (v2_horizontal_pod_autoscaler_status->current_metrics) {
        list_ForEach(listEntry, v2_horizontal_pod_autoscaler_status->current_metrics) {
            v2_metric_status_free(listEntry->data);
        }
        list_freeList(v2_horizontal_pod_autoscaler_status->current_metrics);
        v2_horizontal_pod_autoscaler_status->current_metrics = NULL;
    }
    if (v2_horizontal_pod_autoscaler_status->last_scale_time) {
        free(v2_horizontal_pod_autoscaler_status->last_scale_time);
        v2_horizontal_pod_autoscaler_status->last_scale_time = NULL;
    }
    free(v2_horizontal_pod_autoscaler_status);
}

cJSON *v2_horizontal_pod_autoscaler_status_convertToJSON(v2_horizontal_pod_autoscaler_status_t *v2_horizontal_pod_autoscaler_status) {
    cJSON *item = cJSON_CreateObject();

    // v2_horizontal_pod_autoscaler_status->conditions
    if(v2_horizontal_pod_autoscaler_status->conditions) {
    cJSON *conditions = cJSON_AddArrayToObject(item, "conditions");
    if(conditions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *conditionsListEntry;
    if (v2_horizontal_pod_autoscaler_status->conditions) {
    list_ForEach(conditionsListEntry, v2_horizontal_pod_autoscaler_status->conditions) {
    cJSON *itemLocal = v2_horizontal_pod_autoscaler_condition_convertToJSON(conditionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(conditions, itemLocal);
    }
    }
    }


    // v2_horizontal_pod_autoscaler_status->current_metrics
    if(v2_horizontal_pod_autoscaler_status->current_metrics) {
    cJSON *current_metrics = cJSON_AddArrayToObject(item, "currentMetrics");
    if(current_metrics == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *current_metricsListEntry;
    if (v2_horizontal_pod_autoscaler_status->current_metrics) {
    list_ForEach(current_metricsListEntry, v2_horizontal_pod_autoscaler_status->current_metrics) {
    cJSON *itemLocal = v2_metric_status_convertToJSON(current_metricsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(current_metrics, itemLocal);
    }
    }
    }


    // v2_horizontal_pod_autoscaler_status->current_replicas
    if(v2_horizontal_pod_autoscaler_status->current_replicas) {
    if(cJSON_AddNumberToObject(item, "currentReplicas", v2_horizontal_pod_autoscaler_status->current_replicas) == NULL) {
    goto fail; //Numeric
    }
    }


    // v2_horizontal_pod_autoscaler_status->desired_replicas
    if (!v2_horizontal_pod_autoscaler_status->desired_replicas) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "desiredReplicas", v2_horizontal_pod_autoscaler_status->desired_replicas) == NULL) {
    goto fail; //Numeric
    }


    // v2_horizontal_pod_autoscaler_status->last_scale_time
    if(v2_horizontal_pod_autoscaler_status->last_scale_time) {
    if(cJSON_AddStringToObject(item, "lastScaleTime", v2_horizontal_pod_autoscaler_status->last_scale_time) == NULL) {
    goto fail; //Date-Time
    }
    }


    // v2_horizontal_pod_autoscaler_status->observed_generation
    if(v2_horizontal_pod_autoscaler_status->observed_generation) {
    if(cJSON_AddNumberToObject(item, "observedGeneration", v2_horizontal_pod_autoscaler_status->observed_generation) == NULL) {
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

v2_horizontal_pod_autoscaler_status_t *v2_horizontal_pod_autoscaler_status_parseFromJSON(cJSON *v2_horizontal_pod_autoscaler_statusJSON){

    v2_horizontal_pod_autoscaler_status_t *v2_horizontal_pod_autoscaler_status_local_var = NULL;

    // define the local list for v2_horizontal_pod_autoscaler_status->conditions
    list_t *conditionsList = NULL;

    // define the local list for v2_horizontal_pod_autoscaler_status->current_metrics
    list_t *current_metricsList = NULL;

    // v2_horizontal_pod_autoscaler_status->conditions
    cJSON *conditions = cJSON_GetObjectItemCaseSensitive(v2_horizontal_pod_autoscaler_statusJSON, "conditions");
    if (cJSON_IsNull(conditions)) {
        conditions = NULL;
    }
    if (conditions) { 
    cJSON *conditions_local_nonprimitive = NULL;
    if(!cJSON_IsArray(conditions)){
        goto end; //nonprimitive container
    }

    conditionsList = list_createList();

    cJSON_ArrayForEach(conditions_local_nonprimitive,conditions )
    {
        if(!cJSON_IsObject(conditions_local_nonprimitive)){
            goto end;
        }
        v2_horizontal_pod_autoscaler_condition_t *conditionsItem = v2_horizontal_pod_autoscaler_condition_parseFromJSON(conditions_local_nonprimitive);

        list_addElement(conditionsList, conditionsItem);
    }
    }

    // v2_horizontal_pod_autoscaler_status->current_metrics
    cJSON *current_metrics = cJSON_GetObjectItemCaseSensitive(v2_horizontal_pod_autoscaler_statusJSON, "currentMetrics");
    if (cJSON_IsNull(current_metrics)) {
        current_metrics = NULL;
    }
    if (current_metrics) { 
    cJSON *current_metrics_local_nonprimitive = NULL;
    if(!cJSON_IsArray(current_metrics)){
        goto end; //nonprimitive container
    }

    current_metricsList = list_createList();

    cJSON_ArrayForEach(current_metrics_local_nonprimitive,current_metrics )
    {
        if(!cJSON_IsObject(current_metrics_local_nonprimitive)){
            goto end;
        }
        v2_metric_status_t *current_metricsItem = v2_metric_status_parseFromJSON(current_metrics_local_nonprimitive);

        list_addElement(current_metricsList, current_metricsItem);
    }
    }

    // v2_horizontal_pod_autoscaler_status->current_replicas
    cJSON *current_replicas = cJSON_GetObjectItemCaseSensitive(v2_horizontal_pod_autoscaler_statusJSON, "currentReplicas");
    if (cJSON_IsNull(current_replicas)) {
        current_replicas = NULL;
    }
    if (current_replicas) { 
    if(!cJSON_IsNumber(current_replicas))
    {
    goto end; //Numeric
    }
    }

    // v2_horizontal_pod_autoscaler_status->desired_replicas
    cJSON *desired_replicas = cJSON_GetObjectItemCaseSensitive(v2_horizontal_pod_autoscaler_statusJSON, "desiredReplicas");
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

    // v2_horizontal_pod_autoscaler_status->last_scale_time
    cJSON *last_scale_time = cJSON_GetObjectItemCaseSensitive(v2_horizontal_pod_autoscaler_statusJSON, "lastScaleTime");
    if (cJSON_IsNull(last_scale_time)) {
        last_scale_time = NULL;
    }
    if (last_scale_time) { 
    if(!cJSON_IsString(last_scale_time) && !cJSON_IsNull(last_scale_time))
    {
    goto end; //DateTime
    }
    }

    // v2_horizontal_pod_autoscaler_status->observed_generation
    cJSON *observed_generation = cJSON_GetObjectItemCaseSensitive(v2_horizontal_pod_autoscaler_statusJSON, "observedGeneration");
    if (cJSON_IsNull(observed_generation)) {
        observed_generation = NULL;
    }
    if (observed_generation) { 
    if(!cJSON_IsNumber(observed_generation))
    {
    goto end; //Numeric
    }
    }


    v2_horizontal_pod_autoscaler_status_local_var = v2_horizontal_pod_autoscaler_status_create_internal (
        conditions ? conditionsList : NULL,
        current_metrics ? current_metricsList : NULL,
        current_replicas ? current_replicas->valuedouble : 0,
        desired_replicas->valuedouble,
        last_scale_time && !cJSON_IsNull(last_scale_time) ? strdup(last_scale_time->valuestring) : NULL,
        observed_generation ? observed_generation->valuedouble : 0
        );

    return v2_horizontal_pod_autoscaler_status_local_var;
end:
    if (conditionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, conditionsList) {
            v2_horizontal_pod_autoscaler_condition_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(conditionsList);
        conditionsList = NULL;
    }
    if (current_metricsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, current_metricsList) {
            v2_metric_status_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(current_metricsList);
        current_metricsList = NULL;
    }
    return NULL;

}
