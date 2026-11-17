/*
 * v1beta1_composite_pod_group_template.h
 *
 * CompositePodGroupTemplate represents a template for a CompositePodGroup with a scheduling policy.
 */

#ifndef _v1beta1_composite_pod_group_template_H_
#define _v1beta1_composite_pod_group_template_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_composite_pod_group_template_t v1beta1_composite_pod_group_template_t;

#include "v1beta1_composite_disruption_mode.h"
#include "v1beta1_composite_pod_group_scheduling_constraints.h"
#include "v1beta1_composite_pod_group_scheduling_policy.h"
#include "v1beta1_pod_group_template.h"



typedef struct v1beta1_composite_pod_group_template_t {
    list_t *composite_pod_group_templates; //nonprimitive container
    struct v1beta1_composite_disruption_mode_t *disruption_mode; //model
    char *name; // string
    list_t *pod_group_templates; //nonprimitive container
    char *preemption_policy; // string
    int *priority; //numeric
    char *priority_class_name; // string
    struct v1beta1_composite_pod_group_scheduling_constraints_t *scheduling_constraints; //model
    struct v1beta1_composite_pod_group_scheduling_policy_t *scheduling_policy; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta1_composite_pod_group_template_t;

__attribute__((deprecated)) v1beta1_composite_pod_group_template_t *v1beta1_composite_pod_group_template_create(
    list_t *composite_pod_group_templates,
    v1beta1_composite_disruption_mode_t *disruption_mode,
    char *name,
    list_t *pod_group_templates,
    char *preemption_policy,
    int *priority,
    char *priority_class_name,
    v1beta1_composite_pod_group_scheduling_constraints_t *scheduling_constraints,
    v1beta1_composite_pod_group_scheduling_policy_t *scheduling_policy
);

void v1beta1_composite_pod_group_template_free(v1beta1_composite_pod_group_template_t *v1beta1_composite_pod_group_template);

v1beta1_composite_pod_group_template_t *v1beta1_composite_pod_group_template_parseFromJSON(cJSON *v1beta1_composite_pod_group_templateJSON);

cJSON *v1beta1_composite_pod_group_template_convertToJSON(v1beta1_composite_pod_group_template_t *v1beta1_composite_pod_group_template);

#endif /* _v1beta1_composite_pod_group_template_H_ */

