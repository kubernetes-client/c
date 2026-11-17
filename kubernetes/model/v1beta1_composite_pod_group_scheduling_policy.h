/*
 * v1beta1_composite_pod_group_scheduling_policy.h
 *
 * CompositePodGroupSchedulingPolicy defines the scheduling configuration for a CompositePodGroup. Exactly one policy must be set.
 */

#ifndef _v1beta1_composite_pod_group_scheduling_policy_H_
#define _v1beta1_composite_pod_group_scheduling_policy_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_composite_pod_group_scheduling_policy_t v1beta1_composite_pod_group_scheduling_policy_t;

#include "object.h"
#include "v1beta1_composite_gang_scheduling_policy.h"



typedef struct v1beta1_composite_pod_group_scheduling_policy_t {
    object_t *basic; //object
    struct v1beta1_composite_gang_scheduling_policy_t *gang; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta1_composite_pod_group_scheduling_policy_t;

__attribute__((deprecated)) v1beta1_composite_pod_group_scheduling_policy_t *v1beta1_composite_pod_group_scheduling_policy_create(
    object_t *basic,
    v1beta1_composite_gang_scheduling_policy_t *gang
);

void v1beta1_composite_pod_group_scheduling_policy_free(v1beta1_composite_pod_group_scheduling_policy_t *v1beta1_composite_pod_group_scheduling_policy);

v1beta1_composite_pod_group_scheduling_policy_t *v1beta1_composite_pod_group_scheduling_policy_parseFromJSON(cJSON *v1beta1_composite_pod_group_scheduling_policyJSON);

cJSON *v1beta1_composite_pod_group_scheduling_policy_convertToJSON(v1beta1_composite_pod_group_scheduling_policy_t *v1beta1_composite_pod_group_scheduling_policy);

#endif /* _v1beta1_composite_pod_group_scheduling_policy_H_ */

