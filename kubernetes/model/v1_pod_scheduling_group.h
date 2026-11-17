/*
 * v1_pod_scheduling_group.h
 *
 * PodSchedulingGroup identifies the runtime scheduling group instance that a Pod belongs to. The scheduler uses this information to apply workload-aware scheduling semantics. Exactly one field must be specified.
 */

#ifndef _v1_pod_scheduling_group_H_
#define _v1_pod_scheduling_group_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_pod_scheduling_group_t v1_pod_scheduling_group_t;




typedef struct v1_pod_scheduling_group_t {
    char *pod_group_name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_pod_scheduling_group_t;

__attribute__((deprecated)) v1_pod_scheduling_group_t *v1_pod_scheduling_group_create(
    char *pod_group_name
);

void v1_pod_scheduling_group_free(v1_pod_scheduling_group_t *v1_pod_scheduling_group);

v1_pod_scheduling_group_t *v1_pod_scheduling_group_parseFromJSON(cJSON *v1_pod_scheduling_groupJSON);

cJSON *v1_pod_scheduling_group_convertToJSON(v1_pod_scheduling_group_t *v1_pod_scheduling_group);

#endif /* _v1_pod_scheduling_group_H_ */

