/*
 * v1alpha3_pod_group_template.h
 *
 * PodGroupTemplate represents a template for a set of pods with a scheduling policy.
 */

#ifndef _v1alpha3_pod_group_template_H_
#define _v1alpha3_pod_group_template_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_pod_group_template_t v1alpha3_pod_group_template_t;

#include "v1alpha3_disruption_mode.h"
#include "v1alpha3_pod_group_resource_claim.h"
#include "v1alpha3_pod_group_scheduling_constraints.h"
#include "v1alpha3_pod_group_scheduling_policy.h"



typedef struct v1alpha3_pod_group_template_t {
    struct v1alpha3_disruption_mode_t *disruption_mode; //model
    char *name; // string
    char *preemption_policy; // string
    int *priority; //numeric
    char *priority_class_name; // string
    list_t *resource_claims; //nonprimitive container
    struct v1alpha3_pod_group_scheduling_constraints_t *scheduling_constraints; //model
    struct v1alpha3_pod_group_scheduling_policy_t *scheduling_policy; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha3_pod_group_template_t;

__attribute__((deprecated)) v1alpha3_pod_group_template_t *v1alpha3_pod_group_template_create(
    v1alpha3_disruption_mode_t *disruption_mode,
    char *name,
    char *preemption_policy,
    int *priority,
    char *priority_class_name,
    list_t *resource_claims,
    v1alpha3_pod_group_scheduling_constraints_t *scheduling_constraints,
    v1alpha3_pod_group_scheduling_policy_t *scheduling_policy
);

void v1alpha3_pod_group_template_free(v1alpha3_pod_group_template_t *v1alpha3_pod_group_template);

v1alpha3_pod_group_template_t *v1alpha3_pod_group_template_parseFromJSON(cJSON *v1alpha3_pod_group_templateJSON);

cJSON *v1alpha3_pod_group_template_convertToJSON(v1alpha3_pod_group_template_t *v1alpha3_pod_group_template);

#endif /* _v1alpha3_pod_group_template_H_ */

