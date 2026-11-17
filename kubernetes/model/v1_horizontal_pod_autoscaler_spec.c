#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_horizontal_pod_autoscaler_spec.h"



static v1_horizontal_pod_autoscaler_spec_t *v1_horizontal_pod_autoscaler_spec_create_internal(
    int *max_replicas,
    int *min_replicas,
    v1_cross_version_object_reference_t *scale_target_ref,
    int *target_cpu_utilization_percentage
    ) {
    v1_horizontal_pod_autoscaler_spec_t *v1_horizontal_pod_autoscaler_spec_local_var = malloc(sizeof(v1_horizontal_pod_autoscaler_spec_t));
    if (!v1_horizontal_pod_autoscaler_spec_local_var) {
        return NULL;
    }
    memset(v1_horizontal_pod_autoscaler_spec_local_var, 0, sizeof(v1_horizontal_pod_autoscaler_spec_t));
    v1_horizontal_pod_autoscaler_spec_local_var->_library_owned = 1;
    v1_horizontal_pod_autoscaler_spec_local_var->max_replicas = max_replicas;
    v1_horizontal_pod_autoscaler_spec_local_var->min_replicas = min_replicas;
    v1_horizontal_pod_autoscaler_spec_local_var->scale_target_ref = scale_target_ref;
    v1_horizontal_pod_autoscaler_spec_local_var->target_cpu_utilization_percentage = target_cpu_utilization_percentage;
    return v1_horizontal_pod_autoscaler_spec_local_var;
}

__attribute__((deprecated)) v1_horizontal_pod_autoscaler_spec_t *v1_horizontal_pod_autoscaler_spec_create(
    int *max_replicas,
    int *min_replicas,
    v1_cross_version_object_reference_t *scale_target_ref,
    int *target_cpu_utilization_percentage
    ) {
    int *max_replicas_copy = NULL;
    if (max_replicas) {
        max_replicas_copy = malloc(sizeof(int));
        if (max_replicas_copy) *max_replicas_copy = *max_replicas;
    }
    int *min_replicas_copy = NULL;
    if (min_replicas) {
        min_replicas_copy = malloc(sizeof(int));
        if (min_replicas_copy) *min_replicas_copy = *min_replicas;
    }
    int *target_cpu_utilization_percentage_copy = NULL;
    if (target_cpu_utilization_percentage) {
        target_cpu_utilization_percentage_copy = malloc(sizeof(int));
        if (target_cpu_utilization_percentage_copy) *target_cpu_utilization_percentage_copy = *target_cpu_utilization_percentage;
    }
    v1_horizontal_pod_autoscaler_spec_t *result = v1_horizontal_pod_autoscaler_spec_create_internal (
        max_replicas_copy,
        min_replicas_copy,
        scale_target_ref,
        target_cpu_utilization_percentage_copy
        );
    if (!result) {
        free(max_replicas_copy);
        free(min_replicas_copy);
        free(target_cpu_utilization_percentage_copy);
    }
    return result;
}

void v1_horizontal_pod_autoscaler_spec_free(v1_horizontal_pod_autoscaler_spec_t *v1_horizontal_pod_autoscaler_spec) {
    if(NULL == v1_horizontal_pod_autoscaler_spec){
        return ;
    }
    if(v1_horizontal_pod_autoscaler_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_horizontal_pod_autoscaler_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_horizontal_pod_autoscaler_spec->max_replicas) {
        free(v1_horizontal_pod_autoscaler_spec->max_replicas);
        v1_horizontal_pod_autoscaler_spec->max_replicas = NULL;
    }
    if (v1_horizontal_pod_autoscaler_spec->min_replicas) {
        free(v1_horizontal_pod_autoscaler_spec->min_replicas);
        v1_horizontal_pod_autoscaler_spec->min_replicas = NULL;
    }
    if (v1_horizontal_pod_autoscaler_spec->scale_target_ref) {
        v1_cross_version_object_reference_free(v1_horizontal_pod_autoscaler_spec->scale_target_ref);
        v1_horizontal_pod_autoscaler_spec->scale_target_ref = NULL;
    }
    if (v1_horizontal_pod_autoscaler_spec->target_cpu_utilization_percentage) {
        free(v1_horizontal_pod_autoscaler_spec->target_cpu_utilization_percentage);
        v1_horizontal_pod_autoscaler_spec->target_cpu_utilization_percentage = NULL;
    }
    free(v1_horizontal_pod_autoscaler_spec);
}

cJSON *v1_horizontal_pod_autoscaler_spec_convertToJSON(v1_horizontal_pod_autoscaler_spec_t *v1_horizontal_pod_autoscaler_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_horizontal_pod_autoscaler_spec->max_replicas
    if (!v1_horizontal_pod_autoscaler_spec->max_replicas) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "maxReplicas", *v1_horizontal_pod_autoscaler_spec->max_replicas) == NULL) {
    goto fail; //Numeric
    }


    // v1_horizontal_pod_autoscaler_spec->min_replicas
    if(v1_horizontal_pod_autoscaler_spec->min_replicas) {
    if(cJSON_AddNumberToObject(item, "minReplicas", *v1_horizontal_pod_autoscaler_spec->min_replicas) == NULL) {
    goto fail; //Numeric
    }
    }


    // v1_horizontal_pod_autoscaler_spec->scale_target_ref
    if (!v1_horizontal_pod_autoscaler_spec->scale_target_ref) {
        goto fail;
    }
    cJSON *scale_target_ref_local_JSON = v1_cross_version_object_reference_convertToJSON(v1_horizontal_pod_autoscaler_spec->scale_target_ref);
    if(scale_target_ref_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "scaleTargetRef", scale_target_ref_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // v1_horizontal_pod_autoscaler_spec->target_cpu_utilization_percentage
    if(v1_horizontal_pod_autoscaler_spec->target_cpu_utilization_percentage) {
    if(cJSON_AddNumberToObject(item, "targetCPUUtilizationPercentage", *v1_horizontal_pod_autoscaler_spec->target_cpu_utilization_percentage) == NULL) {
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

v1_horizontal_pod_autoscaler_spec_t *v1_horizontal_pod_autoscaler_spec_parseFromJSON(cJSON *v1_horizontal_pod_autoscaler_specJSON){

    v1_horizontal_pod_autoscaler_spec_t *v1_horizontal_pod_autoscaler_spec_local_var = NULL;

    // define the local variable for v1_horizontal_pod_autoscaler_spec->max_replicas
    int *max_replicas_local_var = NULL;

    // define the local variable for v1_horizontal_pod_autoscaler_spec->min_replicas
    int *min_replicas_local_var = NULL;

    // define the local variable for v1_horizontal_pod_autoscaler_spec->scale_target_ref
    v1_cross_version_object_reference_t *scale_target_ref_local_nonprim = NULL;

    // define the local variable for v1_horizontal_pod_autoscaler_spec->target_cpu_utilization_percentage
    int *target_cpu_utilization_percentage_local_var = NULL;

    // v1_horizontal_pod_autoscaler_spec->max_replicas
    cJSON *max_replicas = cJSON_GetObjectItemCaseSensitive(v1_horizontal_pod_autoscaler_specJSON, "maxReplicas");
    if (cJSON_IsNull(max_replicas)) {
        max_replicas = NULL;
    }
    if (!max_replicas) {
        goto end;
    }

    
    if(!cJSON_IsNumber(max_replicas))
    {
    goto end; //Numeric
    }
    max_replicas_local_var = malloc(sizeof(int));
    if(!max_replicas_local_var)
    {
        goto end;
    }
    *max_replicas_local_var = max_replicas->valuedouble;

    // v1_horizontal_pod_autoscaler_spec->min_replicas
    cJSON *min_replicas = cJSON_GetObjectItemCaseSensitive(v1_horizontal_pod_autoscaler_specJSON, "minReplicas");
    if (cJSON_IsNull(min_replicas)) {
        min_replicas = NULL;
    }
    if (min_replicas) { 
    if(!cJSON_IsNumber(min_replicas))
    {
    goto end; //Numeric
    }
    min_replicas_local_var = malloc(sizeof(int));
    if(!min_replicas_local_var)
    {
        goto end;
    }
    *min_replicas_local_var = min_replicas->valuedouble;
    }

    // v1_horizontal_pod_autoscaler_spec->scale_target_ref
    cJSON *scale_target_ref = cJSON_GetObjectItemCaseSensitive(v1_horizontal_pod_autoscaler_specJSON, "scaleTargetRef");
    if (cJSON_IsNull(scale_target_ref)) {
        scale_target_ref = NULL;
    }
    if (!scale_target_ref) {
        goto end;
    }

    
    scale_target_ref_local_nonprim = v1_cross_version_object_reference_parseFromJSON(scale_target_ref); //nonprimitive

    // v1_horizontal_pod_autoscaler_spec->target_cpu_utilization_percentage
    cJSON *target_cpu_utilization_percentage = cJSON_GetObjectItemCaseSensitive(v1_horizontal_pod_autoscaler_specJSON, "targetCPUUtilizationPercentage");
    if (cJSON_IsNull(target_cpu_utilization_percentage)) {
        target_cpu_utilization_percentage = NULL;
    }
    if (target_cpu_utilization_percentage) { 
    if(!cJSON_IsNumber(target_cpu_utilization_percentage))
    {
    goto end; //Numeric
    }
    target_cpu_utilization_percentage_local_var = malloc(sizeof(int));
    if(!target_cpu_utilization_percentage_local_var)
    {
        goto end;
    }
    *target_cpu_utilization_percentage_local_var = target_cpu_utilization_percentage->valuedouble;
    }



    v1_horizontal_pod_autoscaler_spec_local_var = v1_horizontal_pod_autoscaler_spec_create_internal (
        max_replicas_local_var,
        min_replicas_local_var,
        scale_target_ref_local_nonprim,
        target_cpu_utilization_percentage_local_var
        );

    if (!v1_horizontal_pod_autoscaler_spec_local_var) {
        goto end;
    }

    return v1_horizontal_pod_autoscaler_spec_local_var;
end:
    if (max_replicas_local_var) {
        free(max_replicas_local_var);
        max_replicas_local_var = NULL;
    }
    if (min_replicas_local_var) {
        free(min_replicas_local_var);
        min_replicas_local_var = NULL;
    }
    if (scale_target_ref_local_nonprim) {
        v1_cross_version_object_reference_free(scale_target_ref_local_nonprim);
        scale_target_ref_local_nonprim = NULL;
    }
    if (target_cpu_utilization_percentage_local_var) {
        free(target_cpu_utilization_percentage_local_var);
        target_cpu_utilization_percentage_local_var = NULL;
    }
    return NULL;

}
