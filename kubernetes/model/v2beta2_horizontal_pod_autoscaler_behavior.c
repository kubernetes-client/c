#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2beta2_horizontal_pod_autoscaler_behavior.h"



v2beta2_horizontal_pod_autoscaler_behavior_t *v2beta2_horizontal_pod_autoscaler_behavior_create(
    v2beta2_hpa_scaling_rules_t *scale_down,
    v2beta2_hpa_scaling_rules_t *scale_up
    ) {
    v2beta2_horizontal_pod_autoscaler_behavior_t *v2beta2_horizontal_pod_autoscaler_behavior_local_var = malloc(sizeof(v2beta2_horizontal_pod_autoscaler_behavior_t));
    if (!v2beta2_horizontal_pod_autoscaler_behavior_local_var) {
        return NULL;
    }
    v2beta2_horizontal_pod_autoscaler_behavior_local_var->scale_down = scale_down;
    v2beta2_horizontal_pod_autoscaler_behavior_local_var->scale_up = scale_up;

    return v2beta2_horizontal_pod_autoscaler_behavior_local_var;
}


void v2beta2_horizontal_pod_autoscaler_behavior_free(v2beta2_horizontal_pod_autoscaler_behavior_t *v2beta2_horizontal_pod_autoscaler_behavior) {
    if(NULL == v2beta2_horizontal_pod_autoscaler_behavior){
        return ;
    }
    listEntry_t *listEntry;
    if (v2beta2_horizontal_pod_autoscaler_behavior->scale_down) {
        v2beta2_hpa_scaling_rules_free(v2beta2_horizontal_pod_autoscaler_behavior->scale_down);
        v2beta2_horizontal_pod_autoscaler_behavior->scale_down = NULL;
    }
    if (v2beta2_horizontal_pod_autoscaler_behavior->scale_up) {
        v2beta2_hpa_scaling_rules_free(v2beta2_horizontal_pod_autoscaler_behavior->scale_up);
        v2beta2_horizontal_pod_autoscaler_behavior->scale_up = NULL;
    }
    free(v2beta2_horizontal_pod_autoscaler_behavior);
}

cJSON *v2beta2_horizontal_pod_autoscaler_behavior_convertToJSON(v2beta2_horizontal_pod_autoscaler_behavior_t *v2beta2_horizontal_pod_autoscaler_behavior) {
    cJSON *item = cJSON_CreateObject();

    // v2beta2_horizontal_pod_autoscaler_behavior->scale_down
    if(v2beta2_horizontal_pod_autoscaler_behavior->scale_down) { 
    cJSON *scale_down_local_JSON = v2beta2_hpa_scaling_rules_convertToJSON(v2beta2_horizontal_pod_autoscaler_behavior->scale_down);
    if(scale_down_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "scaleDown", scale_down_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v2beta2_horizontal_pod_autoscaler_behavior->scale_up
    if(v2beta2_horizontal_pod_autoscaler_behavior->scale_up) { 
    cJSON *scale_up_local_JSON = v2beta2_hpa_scaling_rules_convertToJSON(v2beta2_horizontal_pod_autoscaler_behavior->scale_up);
    if(scale_up_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "scaleUp", scale_up_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v2beta2_horizontal_pod_autoscaler_behavior_t *v2beta2_horizontal_pod_autoscaler_behavior_parseFromJSON(cJSON *v2beta2_horizontal_pod_autoscaler_behaviorJSON){

    v2beta2_horizontal_pod_autoscaler_behavior_t *v2beta2_horizontal_pod_autoscaler_behavior_local_var = NULL;

    // v2beta2_horizontal_pod_autoscaler_behavior->scale_down
    cJSON *scale_down = cJSON_GetObjectItemCaseSensitive(v2beta2_horizontal_pod_autoscaler_behaviorJSON, "scaleDown");
    v2beta2_hpa_scaling_rules_t *scale_down_local_nonprim = NULL;
    if (scale_down) { 
    scale_down_local_nonprim = v2beta2_hpa_scaling_rules_parseFromJSON(scale_down); //nonprimitive
    }

    // v2beta2_horizontal_pod_autoscaler_behavior->scale_up
    cJSON *scale_up = cJSON_GetObjectItemCaseSensitive(v2beta2_horizontal_pod_autoscaler_behaviorJSON, "scaleUp");
    v2beta2_hpa_scaling_rules_t *scale_up_local_nonprim = NULL;
    if (scale_up) { 
    scale_up_local_nonprim = v2beta2_hpa_scaling_rules_parseFromJSON(scale_up); //nonprimitive
    }


    v2beta2_horizontal_pod_autoscaler_behavior_local_var = v2beta2_horizontal_pod_autoscaler_behavior_create (
        scale_down ? scale_down_local_nonprim : NULL,
        scale_up ? scale_up_local_nonprim : NULL
        );

    return v2beta2_horizontal_pod_autoscaler_behavior_local_var;
end:
    if (scale_down_local_nonprim) {
        v2beta2_hpa_scaling_rules_free(scale_down_local_nonprim);
        scale_down_local_nonprim = NULL;
    }
    if (scale_up_local_nonprim) {
        v2beta2_hpa_scaling_rules_free(scale_up_local_nonprim);
        scale_up_local_nonprim = NULL;
    }
    return NULL;

}
