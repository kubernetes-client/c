#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_horizontal_pod_autoscaler_spec.h"



v1_horizontal_pod_autoscaler_spec_t *v1_horizontal_pod_autoscaler_spec_create(
    int max_replicas,
    int min_replicas,
    v1_cross_version_object_reference_t *scale_target_ref,
    int target_cpu_utilization_percentage
    ) {
    v1_horizontal_pod_autoscaler_spec_t *v1_horizontal_pod_autoscaler_spec_local_var = malloc(sizeof(v1_horizontal_pod_autoscaler_spec_t));
    if (!v1_horizontal_pod_autoscaler_spec_local_var) {
        return NULL;
    }
    v1_horizontal_pod_autoscaler_spec_local_var->max_replicas = max_replicas;
    v1_horizontal_pod_autoscaler_spec_local_var->min_replicas = min_replicas;
    v1_horizontal_pod_autoscaler_spec_local_var->scale_target_ref = scale_target_ref;
    v1_horizontal_pod_autoscaler_spec_local_var->target_cpu_utilization_percentage = target_cpu_utilization_percentage;

    return v1_horizontal_pod_autoscaler_spec_local_var;
}


void v1_horizontal_pod_autoscaler_spec_free(v1_horizontal_pod_autoscaler_spec_t *v1_horizontal_pod_autoscaler_spec) {
    if(NULL == v1_horizontal_pod_autoscaler_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_horizontal_pod_autoscaler_spec->scale_target_ref) {
        v1_cross_version_object_reference_free(v1_horizontal_pod_autoscaler_spec->scale_target_ref);
        v1_horizontal_pod_autoscaler_spec->scale_target_ref = NULL;
    }
    free(v1_horizontal_pod_autoscaler_spec);
}

cJSON *v1_horizontal_pod_autoscaler_spec_convertToJSON(v1_horizontal_pod_autoscaler_spec_t *v1_horizontal_pod_autoscaler_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_horizontal_pod_autoscaler_spec->max_replicas
    if (!v1_horizontal_pod_autoscaler_spec->max_replicas) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "maxReplicas", v1_horizontal_pod_autoscaler_spec->max_replicas) == NULL) {
    goto fail; //Numeric
    }


    // v1_horizontal_pod_autoscaler_spec->min_replicas
    if(v1_horizontal_pod_autoscaler_spec->min_replicas) { 
    if(cJSON_AddNumberToObject(item, "minReplicas", v1_horizontal_pod_autoscaler_spec->min_replicas) == NULL) {
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
    if(cJSON_AddNumberToObject(item, "targetCPUUtilizationPercentage", v1_horizontal_pod_autoscaler_spec->target_cpu_utilization_percentage) == NULL) {
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

    // v1_horizontal_pod_autoscaler_spec->max_replicas
    cJSON *max_replicas = cJSON_GetObjectItemCaseSensitive(v1_horizontal_pod_autoscaler_specJSON, "maxReplicas");
    if (!max_replicas) {
        goto end;
    }

    
    if(!cJSON_IsNumber(max_replicas))
    {
    goto end; //Numeric
    }

    // v1_horizontal_pod_autoscaler_spec->min_replicas
    cJSON *min_replicas = cJSON_GetObjectItemCaseSensitive(v1_horizontal_pod_autoscaler_specJSON, "minReplicas");
    if (min_replicas) { 
    if(!cJSON_IsNumber(min_replicas))
    {
    goto end; //Numeric
    }
    }

    // v1_horizontal_pod_autoscaler_spec->scale_target_ref
    cJSON *scale_target_ref = cJSON_GetObjectItemCaseSensitive(v1_horizontal_pod_autoscaler_specJSON, "scaleTargetRef");
    if (!scale_target_ref) {
        goto end;
    }

    v1_cross_version_object_reference_t *scale_target_ref_local_nonprim = NULL;
    
    scale_target_ref_local_nonprim = v1_cross_version_object_reference_parseFromJSON(scale_target_ref); //nonprimitive

    // v1_horizontal_pod_autoscaler_spec->target_cpu_utilization_percentage
    cJSON *target_cpu_utilization_percentage = cJSON_GetObjectItemCaseSensitive(v1_horizontal_pod_autoscaler_specJSON, "targetCPUUtilizationPercentage");
    if (target_cpu_utilization_percentage) { 
    if(!cJSON_IsNumber(target_cpu_utilization_percentage))
    {
    goto end; //Numeric
    }
    }


    v1_horizontal_pod_autoscaler_spec_local_var = v1_horizontal_pod_autoscaler_spec_create (
        max_replicas->valuedouble,
        min_replicas ? min_replicas->valuedouble : 0,
        scale_target_ref_local_nonprim,
        target_cpu_utilization_percentage ? target_cpu_utilization_percentage->valuedouble : 0
        );

    return v1_horizontal_pod_autoscaler_spec_local_var;
end:
    if (scale_target_ref_local_nonprim) {
        v1_cross_version_object_reference_free(scale_target_ref_local_nonprim);
        scale_target_ref_local_nonprim = NULL;
    }
    return NULL;

}
