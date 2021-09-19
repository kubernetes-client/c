/*
 * v2beta2_horizontal_pod_autoscaler_behavior.h
 *
 * HorizontalPodAutoscalerBehavior configures the scaling behavior of the target in both Up and Down directions (scaleUp and scaleDown fields respectively).
 */

#ifndef _v2beta2_horizontal_pod_autoscaler_behavior_H_
#define _v2beta2_horizontal_pod_autoscaler_behavior_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v2beta2_horizontal_pod_autoscaler_behavior_t v2beta2_horizontal_pod_autoscaler_behavior_t;

#include "v2beta2_hpa_scaling_rules.h"



typedef struct v2beta2_horizontal_pod_autoscaler_behavior_t {
    struct v2beta2_hpa_scaling_rules_t *scale_down; //model
    struct v2beta2_hpa_scaling_rules_t *scale_up; //model

} v2beta2_horizontal_pod_autoscaler_behavior_t;

v2beta2_horizontal_pod_autoscaler_behavior_t *v2beta2_horizontal_pod_autoscaler_behavior_create(
    v2beta2_hpa_scaling_rules_t *scale_down,
    v2beta2_hpa_scaling_rules_t *scale_up
);

void v2beta2_horizontal_pod_autoscaler_behavior_free(v2beta2_horizontal_pod_autoscaler_behavior_t *v2beta2_horizontal_pod_autoscaler_behavior);

v2beta2_horizontal_pod_autoscaler_behavior_t *v2beta2_horizontal_pod_autoscaler_behavior_parseFromJSON(cJSON *v2beta2_horizontal_pod_autoscaler_behaviorJSON);

cJSON *v2beta2_horizontal_pod_autoscaler_behavior_convertToJSON(v2beta2_horizontal_pod_autoscaler_behavior_t *v2beta2_horizontal_pod_autoscaler_behavior);

#endif /* _v2beta2_horizontal_pod_autoscaler_behavior_H_ */

