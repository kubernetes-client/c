/*
 * v1_horizontal_pod_autoscaler_status.h
 *
 * current status of a horizontal pod autoscaler
 */

#ifndef _v1_horizontal_pod_autoscaler_status_H_
#define _v1_horizontal_pod_autoscaler_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_horizontal_pod_autoscaler_status_t v1_horizontal_pod_autoscaler_status_t;




typedef struct v1_horizontal_pod_autoscaler_status_t {
    int current_cpu_utilization_percentage; //numeric
    int current_replicas; //numeric
    int desired_replicas; //numeric
    char *last_scale_time; //date time
    long observed_generation; //numeric

} v1_horizontal_pod_autoscaler_status_t;

v1_horizontal_pod_autoscaler_status_t *v1_horizontal_pod_autoscaler_status_create(
    int current_cpu_utilization_percentage,
    int current_replicas,
    int desired_replicas,
    char *last_scale_time,
    long observed_generation
);

void v1_horizontal_pod_autoscaler_status_free(v1_horizontal_pod_autoscaler_status_t *v1_horizontal_pod_autoscaler_status);

v1_horizontal_pod_autoscaler_status_t *v1_horizontal_pod_autoscaler_status_parseFromJSON(cJSON *v1_horizontal_pod_autoscaler_statusJSON);

cJSON *v1_horizontal_pod_autoscaler_status_convertToJSON(v1_horizontal_pod_autoscaler_status_t *v1_horizontal_pod_autoscaler_status);

#endif /* _v1_horizontal_pod_autoscaler_status_H_ */

