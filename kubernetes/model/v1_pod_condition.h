/*
 * v1_pod_condition.h
 *
 * PodCondition contains details for the current condition of this pod.
 */

#ifndef _v1_pod_condition_H_
#define _v1_pod_condition_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_pod_condition_t v1_pod_condition_t;




typedef struct v1_pod_condition_t {
    char *last_probe_time; //date time
    char *last_transition_time; //date time
    char *message; // string
    long observed_generation; //numeric
    char *reason; // string
    char *status; // string
    char *type; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_pod_condition_t;

__attribute__((deprecated)) v1_pod_condition_t *v1_pod_condition_create(
    char *last_probe_time,
    char *last_transition_time,
    char *message,
    long observed_generation,
    char *reason,
    char *status,
    char *type
);

void v1_pod_condition_free(v1_pod_condition_t *v1_pod_condition);

v1_pod_condition_t *v1_pod_condition_parseFromJSON(cJSON *v1_pod_conditionJSON);

cJSON *v1_pod_condition_convertToJSON(v1_pod_condition_t *v1_pod_condition);

#endif /* _v1_pod_condition_H_ */

