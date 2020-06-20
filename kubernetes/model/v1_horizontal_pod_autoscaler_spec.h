/*
 * v1_horizontal_pod_autoscaler_spec.h
 *
 * specification of a horizontal pod autoscaler.
 */

#ifndef _v1_horizontal_pod_autoscaler_spec_H_
#define _v1_horizontal_pod_autoscaler_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_horizontal_pod_autoscaler_spec_t v1_horizontal_pod_autoscaler_spec_t;

#include "v1_cross_version_object_reference.h"



typedef struct v1_horizontal_pod_autoscaler_spec_t {
    int max_replicas; //numeric
    int min_replicas; //numeric
    struct v1_cross_version_object_reference_t *scale_target_ref; //model
    int target_cpu_utilization_percentage; //numeric

} v1_horizontal_pod_autoscaler_spec_t;

v1_horizontal_pod_autoscaler_spec_t *v1_horizontal_pod_autoscaler_spec_create(
    int max_replicas,
    int min_replicas,
    v1_cross_version_object_reference_t *scale_target_ref,
    int target_cpu_utilization_percentage
);

void v1_horizontal_pod_autoscaler_spec_free(v1_horizontal_pod_autoscaler_spec_t *v1_horizontal_pod_autoscaler_spec);

v1_horizontal_pod_autoscaler_spec_t *v1_horizontal_pod_autoscaler_spec_parseFromJSON(cJSON *v1_horizontal_pod_autoscaler_specJSON);

cJSON *v1_horizontal_pod_autoscaler_spec_convertToJSON(v1_horizontal_pod_autoscaler_spec_t *v1_horizontal_pod_autoscaler_spec);

#endif /* _v1_horizontal_pod_autoscaler_spec_H_ */

