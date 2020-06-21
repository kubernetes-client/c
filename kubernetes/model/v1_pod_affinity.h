/*
 * v1_pod_affinity.h
 *
 * Pod affinity is a group of inter pod affinity scheduling rules.
 */

#ifndef _v1_pod_affinity_H_
#define _v1_pod_affinity_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_pod_affinity_t v1_pod_affinity_t;

#include "v1_pod_affinity_term.h"
#include "v1_weighted_pod_affinity_term.h"



typedef struct v1_pod_affinity_t {
    list_t *preferred_during_scheduling_ignored_during_execution; //nonprimitive container
    list_t *required_during_scheduling_ignored_during_execution; //nonprimitive container

} v1_pod_affinity_t;

v1_pod_affinity_t *v1_pod_affinity_create(
    list_t *preferred_during_scheduling_ignored_during_execution,
    list_t *required_during_scheduling_ignored_during_execution
);

void v1_pod_affinity_free(v1_pod_affinity_t *v1_pod_affinity);

v1_pod_affinity_t *v1_pod_affinity_parseFromJSON(cJSON *v1_pod_affinityJSON);

cJSON *v1_pod_affinity_convertToJSON(v1_pod_affinity_t *v1_pod_affinity);

#endif /* _v1_pod_affinity_H_ */

