/*
 * v1alpha3_pod_group_spec.h
 *
 * PodGroupSpec defines the desired state of a PodGroup.
 */

#ifndef _v1alpha3_pod_group_spec_H_
#define _v1alpha3_pod_group_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_pod_group_spec_t v1alpha3_pod_group_spec_t;

#include "v1alpha3_disruption_mode.h"
#include "v1alpha3_pod_group_resource_claim.h"
#include "v1alpha3_pod_group_scheduling_constraints.h"
#include "v1alpha3_pod_group_scheduling_policy.h"
#include "v1alpha3_workload_reference.h"



typedef struct v1alpha3_pod_group_spec_t {
    struct v1alpha3_disruption_mode_t *disruption_mode; //model
    char *parent_composite_pod_group_name; // string
    char *preemption_policy; // string
    int *priority; //numeric
    char *priority_class_name; // string
    list_t *resource_claims; //nonprimitive container
    struct v1alpha3_pod_group_scheduling_constraints_t *scheduling_constraints; //model
    struct v1alpha3_pod_group_scheduling_policy_t *scheduling_policy; //model
    struct v1alpha3_workload_reference_t *workload_ref; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha3_pod_group_spec_t;

__attribute__((deprecated)) v1alpha3_pod_group_spec_t *v1alpha3_pod_group_spec_create(
    v1alpha3_disruption_mode_t *disruption_mode,
    char *parent_composite_pod_group_name,
    char *preemption_policy,
    int *priority,
    char *priority_class_name,
    list_t *resource_claims,
    v1alpha3_pod_group_scheduling_constraints_t *scheduling_constraints,
    v1alpha3_pod_group_scheduling_policy_t *scheduling_policy,
    v1alpha3_workload_reference_t *workload_ref
);

void v1alpha3_pod_group_spec_free(v1alpha3_pod_group_spec_t *v1alpha3_pod_group_spec);

v1alpha3_pod_group_spec_t *v1alpha3_pod_group_spec_parseFromJSON(cJSON *v1alpha3_pod_group_specJSON);

cJSON *v1alpha3_pod_group_spec_convertToJSON(v1alpha3_pod_group_spec_t *v1alpha3_pod_group_spec);

#endif /* _v1alpha3_pod_group_spec_H_ */

