#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v2_horizontal_pod_autoscaler_behavior.h"



static v2_horizontal_pod_autoscaler_behavior_t *v2_horizontal_pod_autoscaler_behavior_create_internal(
    v2_hpa_scaling_rules_t *scale_down,
    v2_hpa_scaling_rules_t *scale_up
    ) {
    v2_horizontal_pod_autoscaler_behavior_t *v2_horizontal_pod_autoscaler_behavior_local_var = malloc(sizeof(v2_horizontal_pod_autoscaler_behavior_t));
    if (!v2_horizontal_pod_autoscaler_behavior_local_var) {
        return NULL;
    }
    v2_horizontal_pod_autoscaler_behavior_local_var->scale_down = scale_down;
    v2_horizontal_pod_autoscaler_behavior_local_var->scale_up = scale_up;

    v2_horizontal_pod_autoscaler_behavior_local_var->_library_owned = 1;
    return v2_horizontal_pod_autoscaler_behavior_local_var;
}

__attribute__((deprecated)) v2_horizontal_pod_autoscaler_behavior_t *v2_horizontal_pod_autoscaler_behavior_create(
    v2_hpa_scaling_rules_t *scale_down,
    v2_hpa_scaling_rules_t *scale_up
    ) {
    return v2_horizontal_pod_autoscaler_behavior_create_internal (
        scale_down,
        scale_up
        );
}

void v2_horizontal_pod_autoscaler_behavior_free(v2_horizontal_pod_autoscaler_behavior_t *v2_horizontal_pod_autoscaler_behavior) {
    if(NULL == v2_horizontal_pod_autoscaler_behavior){
        return ;
    }
    if(v2_horizontal_pod_autoscaler_behavior->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v2_horizontal_pod_autoscaler_behavior_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v2_horizontal_pod_autoscaler_behavior->scale_down) {
        v2_hpa_scaling_rules_free(v2_horizontal_pod_autoscaler_behavior->scale_down);
        v2_horizontal_pod_autoscaler_behavior->scale_down = NULL;
    }
    if (v2_horizontal_pod_autoscaler_behavior->scale_up) {
        v2_hpa_scaling_rules_free(v2_horizontal_pod_autoscaler_behavior->scale_up);
        v2_horizontal_pod_autoscaler_behavior->scale_up = NULL;
    }
    free(v2_horizontal_pod_autoscaler_behavior);
}

cJSON *v2_horizontal_pod_autoscaler_behavior_convertToJSON(v2_horizontal_pod_autoscaler_behavior_t *v2_horizontal_pod_autoscaler_behavior) {
    cJSON *item = cJSON_CreateObject();

    // v2_horizontal_pod_autoscaler_behavior->scale_down
    if(v2_horizontal_pod_autoscaler_behavior->scale_down) {
    cJSON *scale_down_local_JSON = v2_hpa_scaling_rules_convertToJSON(v2_horizontal_pod_autoscaler_behavior->scale_down);
    if(scale_down_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "scaleDown", scale_down_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v2_horizontal_pod_autoscaler_behavior->scale_up
    if(v2_horizontal_pod_autoscaler_behavior->scale_up) {
    cJSON *scale_up_local_JSON = v2_hpa_scaling_rules_convertToJSON(v2_horizontal_pod_autoscaler_behavior->scale_up);
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

v2_horizontal_pod_autoscaler_behavior_t *v2_horizontal_pod_autoscaler_behavior_parseFromJSON(cJSON *v2_horizontal_pod_autoscaler_behaviorJSON){

    v2_horizontal_pod_autoscaler_behavior_t *v2_horizontal_pod_autoscaler_behavior_local_var = NULL;

    // define the local variable for v2_horizontal_pod_autoscaler_behavior->scale_down
    v2_hpa_scaling_rules_t *scale_down_local_nonprim = NULL;

    // define the local variable for v2_horizontal_pod_autoscaler_behavior->scale_up
    v2_hpa_scaling_rules_t *scale_up_local_nonprim = NULL;

    // v2_horizontal_pod_autoscaler_behavior->scale_down
    cJSON *scale_down = cJSON_GetObjectItemCaseSensitive(v2_horizontal_pod_autoscaler_behaviorJSON, "scaleDown");
    if (cJSON_IsNull(scale_down)) {
        scale_down = NULL;
    }
    if (scale_down) { 
    scale_down_local_nonprim = v2_hpa_scaling_rules_parseFromJSON(scale_down); //nonprimitive
    }

    // v2_horizontal_pod_autoscaler_behavior->scale_up
    cJSON *scale_up = cJSON_GetObjectItemCaseSensitive(v2_horizontal_pod_autoscaler_behaviorJSON, "scaleUp");
    if (cJSON_IsNull(scale_up)) {
        scale_up = NULL;
    }
    if (scale_up) { 
    scale_up_local_nonprim = v2_hpa_scaling_rules_parseFromJSON(scale_up); //nonprimitive
    }


    v2_horizontal_pod_autoscaler_behavior_local_var = v2_horizontal_pod_autoscaler_behavior_create_internal (
        scale_down ? scale_down_local_nonprim : NULL,
        scale_up ? scale_up_local_nonprim : NULL
        );

    return v2_horizontal_pod_autoscaler_behavior_local_var;
end:
    if (scale_down_local_nonprim) {
        v2_hpa_scaling_rules_free(scale_down_local_nonprim);
        scale_down_local_nonprim = NULL;
    }
    if (scale_up_local_nonprim) {
        v2_hpa_scaling_rules_free(scale_up_local_nonprim);
        scale_up_local_nonprim = NULL;
    }
    return NULL;

}
