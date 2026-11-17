/*
 * v1beta1_pod_group_scheduling_constraints.h
 *
 * PodGroupSchedulingConstraints defines scheduling constraints (e.g. topology) for a PodGroup.
 */

#ifndef _v1beta1_pod_group_scheduling_constraints_H_
#define _v1beta1_pod_group_scheduling_constraints_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_pod_group_scheduling_constraints_t v1beta1_pod_group_scheduling_constraints_t;

#include "v1beta1_topology_constraint.h"



typedef struct v1beta1_pod_group_scheduling_constraints_t {
    list_t *topology; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta1_pod_group_scheduling_constraints_t;

__attribute__((deprecated)) v1beta1_pod_group_scheduling_constraints_t *v1beta1_pod_group_scheduling_constraints_create(
    list_t *topology
);

void v1beta1_pod_group_scheduling_constraints_free(v1beta1_pod_group_scheduling_constraints_t *v1beta1_pod_group_scheduling_constraints);

v1beta1_pod_group_scheduling_constraints_t *v1beta1_pod_group_scheduling_constraints_parseFromJSON(cJSON *v1beta1_pod_group_scheduling_constraintsJSON);

cJSON *v1beta1_pod_group_scheduling_constraints_convertToJSON(v1beta1_pod_group_scheduling_constraints_t *v1beta1_pod_group_scheduling_constraints);

#endif /* _v1beta1_pod_group_scheduling_constraints_H_ */

