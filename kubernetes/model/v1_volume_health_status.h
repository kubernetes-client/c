/*
 * v1_volume_health_status.h
 *
 * VolumeHealthStatus contains health information for a volume reported by the CSI controller plugin.
 */

#ifndef _v1_volume_health_status_H_
#define _v1_volume_health_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_volume_health_status_t v1_volume_health_status_t;

#include "v1_volume_health_condition.h"



typedef struct v1_volume_health_status_t {
    list_t *health_conditions; //nonprimitive container
    char *last_transition_time; //date time

    int _library_owned; // Is the library responsible for freeing this object?
} v1_volume_health_status_t;

__attribute__((deprecated)) v1_volume_health_status_t *v1_volume_health_status_create(
    list_t *health_conditions,
    char *last_transition_time
);

void v1_volume_health_status_free(v1_volume_health_status_t *v1_volume_health_status);

v1_volume_health_status_t *v1_volume_health_status_parseFromJSON(cJSON *v1_volume_health_statusJSON);

cJSON *v1_volume_health_status_convertToJSON(v1_volume_health_status_t *v1_volume_health_status);

#endif /* _v1_volume_health_status_H_ */

