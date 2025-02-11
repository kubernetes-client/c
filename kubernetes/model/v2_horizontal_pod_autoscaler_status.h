/*
 * v2_horizontal_pod_autoscaler_status.h
 *
 * HorizontalPodAutoscalerStatus describes the current status of a horizontal pod autoscaler.
 */

#ifndef _v2_horizontal_pod_autoscaler_status_H_
#define _v2_horizontal_pod_autoscaler_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v2_horizontal_pod_autoscaler_status_t v2_horizontal_pod_autoscaler_status_t;

#include "v2_horizontal_pod_autoscaler_condition.h"
#include "v2_metric_status.h"



typedef struct v2_horizontal_pod_autoscaler_status_t {
    list_t *conditions; //nonprimitive container
    list_t *current_metrics; //nonprimitive container
    int current_replicas; //numeric
    int desired_replicas; //numeric
    char *last_scale_time; //date time
    long observed_generation; //numeric

    int _library_owned; // Is the library responsible for freeing this object?
} v2_horizontal_pod_autoscaler_status_t;

__attribute__((deprecated)) v2_horizontal_pod_autoscaler_status_t *v2_horizontal_pod_autoscaler_status_create(
    list_t *conditions,
    list_t *current_metrics,
    int current_replicas,
    int desired_replicas,
    char *last_scale_time,
    long observed_generation
);

void v2_horizontal_pod_autoscaler_status_free(v2_horizontal_pod_autoscaler_status_t *v2_horizontal_pod_autoscaler_status);

v2_horizontal_pod_autoscaler_status_t *v2_horizontal_pod_autoscaler_status_parseFromJSON(cJSON *v2_horizontal_pod_autoscaler_statusJSON);

cJSON *v2_horizontal_pod_autoscaler_status_convertToJSON(v2_horizontal_pod_autoscaler_status_t *v2_horizontal_pod_autoscaler_status);

#endif /* _v2_horizontal_pod_autoscaler_status_H_ */

