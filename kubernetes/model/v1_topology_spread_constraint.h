/*
 * v1_topology_spread_constraint.h
 *
 * TopologySpreadConstraint specifies how to spread matching pods among the given topology.
 */

#ifndef _v1_topology_spread_constraint_H_
#define _v1_topology_spread_constraint_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_topology_spread_constraint_t v1_topology_spread_constraint_t;

#include "v1_label_selector.h"



typedef struct v1_topology_spread_constraint_t {
    struct v1_label_selector_t *label_selector; //model
    int max_skew; //numeric
    char *topology_key; // string
    char *when_unsatisfiable; // string

} v1_topology_spread_constraint_t;

v1_topology_spread_constraint_t *v1_topology_spread_constraint_create(
    v1_label_selector_t *label_selector,
    int max_skew,
    char *topology_key,
    char *when_unsatisfiable
);

void v1_topology_spread_constraint_free(v1_topology_spread_constraint_t *v1_topology_spread_constraint);

v1_topology_spread_constraint_t *v1_topology_spread_constraint_parseFromJSON(cJSON *v1_topology_spread_constraintJSON);

cJSON *v1_topology_spread_constraint_convertToJSON(v1_topology_spread_constraint_t *v1_topology_spread_constraint);

#endif /* _v1_topology_spread_constraint_H_ */

