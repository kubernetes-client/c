/*
 * v1_node_affinity.h
 *
 * Node affinity is a group of node affinity scheduling rules.
 */

#ifndef _v1_node_affinity_H_
#define _v1_node_affinity_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_node_affinity_t v1_node_affinity_t;

#include "v1_node_selector.h"
#include "v1_preferred_scheduling_term.h"



typedef struct v1_node_affinity_t {
    list_t *preferred_during_scheduling_ignored_during_execution; //nonprimitive container
    struct v1_node_selector_t *required_during_scheduling_ignored_during_execution; //model

} v1_node_affinity_t;

v1_node_affinity_t *v1_node_affinity_create(
    list_t *preferred_during_scheduling_ignored_during_execution,
    v1_node_selector_t *required_during_scheduling_ignored_during_execution
);

void v1_node_affinity_free(v1_node_affinity_t *v1_node_affinity);

v1_node_affinity_t *v1_node_affinity_parseFromJSON(cJSON *v1_node_affinityJSON);

cJSON *v1_node_affinity_convertToJSON(v1_node_affinity_t *v1_node_affinity);

#endif /* _v1_node_affinity_H_ */

