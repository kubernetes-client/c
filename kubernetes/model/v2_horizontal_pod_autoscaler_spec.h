/*
 * v2_horizontal_pod_autoscaler_spec.h
 *
 * HorizontalPodAutoscalerSpec describes the desired functionality of the HorizontalPodAutoscaler.
 */

#ifndef _v2_horizontal_pod_autoscaler_spec_H_
#define _v2_horizontal_pod_autoscaler_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v2_horizontal_pod_autoscaler_spec_t v2_horizontal_pod_autoscaler_spec_t;

#include "v2_cross_version_object_reference.h"
#include "v2_horizontal_pod_autoscaler_behavior.h"
#include "v2_metric_spec.h"



typedef struct v2_horizontal_pod_autoscaler_spec_t {
    struct v2_horizontal_pod_autoscaler_behavior_t *behavior; //model
    int max_replicas; //numeric
    list_t *metrics; //nonprimitive container
    int min_replicas; //numeric
    struct v2_cross_version_object_reference_t *scale_target_ref; //model

} v2_horizontal_pod_autoscaler_spec_t;

v2_horizontal_pod_autoscaler_spec_t *v2_horizontal_pod_autoscaler_spec_create(
    v2_horizontal_pod_autoscaler_behavior_t *behavior,
    int max_replicas,
    list_t *metrics,
    int min_replicas,
    v2_cross_version_object_reference_t *scale_target_ref
);

void v2_horizontal_pod_autoscaler_spec_free(v2_horizontal_pod_autoscaler_spec_t *v2_horizontal_pod_autoscaler_spec);

v2_horizontal_pod_autoscaler_spec_t *v2_horizontal_pod_autoscaler_spec_parseFromJSON(cJSON *v2_horizontal_pod_autoscaler_specJSON);

cJSON *v2_horizontal_pod_autoscaler_spec_convertToJSON(v2_horizontal_pod_autoscaler_spec_t *v2_horizontal_pod_autoscaler_spec);

#endif /* _v2_horizontal_pod_autoscaler_spec_H_ */

