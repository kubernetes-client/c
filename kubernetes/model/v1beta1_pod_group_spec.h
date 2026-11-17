/*
 * v1beta1_pod_group_spec.h
 *
 * PodGroupSpec defines the desired state of a PodGroup.
 */

#ifndef _v1beta1_pod_group_spec_H_
#define _v1beta1_pod_group_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_pod_group_spec_t v1beta1_pod_group_spec_t;

#include "v1beta1_disruption_mode.h"
#include "v1beta1_pod_group_resource_claim.h"
#include "v1beta1_pod_group_scheduling_constraints.h"
#include "v1beta1_pod_group_scheduling_policy.h"
#include "v1beta1_workload_reference.h"



typedef struct v1beta1_pod_group_spec_t {
    struct v1beta1_disruption_mode_t *disruption_mode; //model
    char *parent_composite_pod_group_name; // string
    char *preemption_policy; // string
    int *priority; //numeric
    char *priority_class_name; // string
    list_t *resource_claims; //nonprimitive container
    struct v1beta1_pod_group_scheduling_constraints_t *scheduling_constraints; //model
    struct v1beta1_pod_group_scheduling_policy_t *scheduling_policy; //model
    struct v1beta1_workload_reference_t *workload_ref; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta1_pod_group_spec_t;

__attribute__((deprecated)) v1beta1_pod_group_spec_t *v1beta1_pod_group_spec_create(
    v1beta1_disruption_mode_t *disruption_mode,
    char *parent_composite_pod_group_name,
    char *preemption_policy,
    int *priority,
    char *priority_class_name,
    list_t *resource_claims,
    v1beta1_pod_group_scheduling_constraints_t *scheduling_constraints,
    v1beta1_pod_group_scheduling_policy_t *scheduling_policy,
    v1beta1_workload_reference_t *workload_ref
);

void v1beta1_pod_group_spec_free(v1beta1_pod_group_spec_t *v1beta1_pod_group_spec);

v1beta1_pod_group_spec_t *v1beta1_pod_group_spec_parseFromJSON(cJSON *v1beta1_pod_group_specJSON);

cJSON *v1beta1_pod_group_spec_convertToJSON(v1beta1_pod_group_spec_t *v1beta1_pod_group_spec);

#endif /* _v1beta1_pod_group_spec_H_ */

