/*
 * v1beta1_topology_constraint.h
 *
 * TopologyConstraint defines a topology constraint for a PodGroup.
 */

#ifndef _v1beta1_topology_constraint_H_
#define _v1beta1_topology_constraint_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_topology_constraint_t v1beta1_topology_constraint_t;




typedef struct v1beta1_topology_constraint_t {
    char *key; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta1_topology_constraint_t;

__attribute__((deprecated)) v1beta1_topology_constraint_t *v1beta1_topology_constraint_create(
    char *key
);

void v1beta1_topology_constraint_free(v1beta1_topology_constraint_t *v1beta1_topology_constraint);

v1beta1_topology_constraint_t *v1beta1_topology_constraint_parseFromJSON(cJSON *v1beta1_topology_constraintJSON);

cJSON *v1beta1_topology_constraint_convertToJSON(v1beta1_topology_constraint_t *v1beta1_topology_constraint);

#endif /* _v1beta1_topology_constraint_H_ */

