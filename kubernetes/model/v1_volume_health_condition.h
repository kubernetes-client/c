/*
 * v1_volume_health_condition.h
 *
 * VolumeHealthCondition represents an adverse health condition reported for a volume.
 */

#ifndef _v1_volume_health_condition_H_
#define _v1_volume_health_condition_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_volume_health_condition_t v1_volume_health_condition_t;




typedef struct v1_volume_health_condition_t {
    char *message; // string
    char *reason; // string
    char *status; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_volume_health_condition_t;

__attribute__((deprecated)) v1_volume_health_condition_t *v1_volume_health_condition_create(
    char *message,
    char *reason,
    char *status
);

void v1_volume_health_condition_free(v1_volume_health_condition_t *v1_volume_health_condition);

v1_volume_health_condition_t *v1_volume_health_condition_parseFromJSON(cJSON *v1_volume_health_conditionJSON);

cJSON *v1_volume_health_condition_convertToJSON(v1_volume_health_condition_t *v1_volume_health_condition);

#endif /* _v1_volume_health_condition_H_ */

