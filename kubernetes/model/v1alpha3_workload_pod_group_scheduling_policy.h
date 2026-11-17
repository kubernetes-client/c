/*
 * v1alpha3_workload_pod_group_scheduling_policy.h
 *
 * WorkloadPodGroupSchedulingPolicy defines the scheduling policy for a group of pods managed by a workload controller. Exactly one policy must be set.
 */

#ifndef _v1alpha3_workload_pod_group_scheduling_policy_H_
#define _v1alpha3_workload_pod_group_scheduling_policy_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_workload_pod_group_scheduling_policy_t v1alpha3_workload_pod_group_scheduling_policy_t;

#include "object.h"
#include "v1alpha3_workload_pod_group_gang_scheduling_policy.h"



typedef struct v1alpha3_workload_pod_group_scheduling_policy_t {
    object_t *basic; //object
    struct v1alpha3_workload_pod_group_gang_scheduling_policy_t *gang; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha3_workload_pod_group_scheduling_policy_t;

__attribute__((deprecated)) v1alpha3_workload_pod_group_scheduling_policy_t *v1alpha3_workload_pod_group_scheduling_policy_create(
    object_t *basic,
    v1alpha3_workload_pod_group_gang_scheduling_policy_t *gang
);

void v1alpha3_workload_pod_group_scheduling_policy_free(v1alpha3_workload_pod_group_scheduling_policy_t *v1alpha3_workload_pod_group_scheduling_policy);

v1alpha3_workload_pod_group_scheduling_policy_t *v1alpha3_workload_pod_group_scheduling_policy_parseFromJSON(cJSON *v1alpha3_workload_pod_group_scheduling_policyJSON);

cJSON *v1alpha3_workload_pod_group_scheduling_policy_convertToJSON(v1alpha3_workload_pod_group_scheduling_policy_t *v1alpha3_workload_pod_group_scheduling_policy);

#endif /* _v1alpha3_workload_pod_group_scheduling_policy_H_ */

