/*
 * v1_pod_volume_health.h
 *
 * PodVolumeHealth contains health information for a volume used by a pod, reported by the CSI node plugin via the kubelet.
 */

#ifndef _v1_pod_volume_health_H_
#define _v1_pod_volume_health_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_pod_volume_health_t v1_pod_volume_health_t;

#include "v1_volume_health_condition.h"



typedef struct v1_pod_volume_health_t {
    list_t *health_conditions; //nonprimitive container
    char *last_transition_time; //date time
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_pod_volume_health_t;

__attribute__((deprecated)) v1_pod_volume_health_t *v1_pod_volume_health_create(
    list_t *health_conditions,
    char *last_transition_time,
    char *name
);

void v1_pod_volume_health_free(v1_pod_volume_health_t *v1_pod_volume_health);

v1_pod_volume_health_t *v1_pod_volume_health_parseFromJSON(cJSON *v1_pod_volume_healthJSON);

cJSON *v1_pod_volume_health_convertToJSON(v1_pod_volume_health_t *v1_pod_volume_health);

#endif /* _v1_pod_volume_health_H_ */

