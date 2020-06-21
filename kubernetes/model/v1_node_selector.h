/*
 * v1_node_selector.h
 *
 * A node selector represents the union of the results of one or more label queries over a set of nodes; that is, it represents the OR of the selectors represented by the node selector terms.
 */

#ifndef _v1_node_selector_H_
#define _v1_node_selector_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_node_selector_t v1_node_selector_t;

#include "v1_node_selector_term.h"



typedef struct v1_node_selector_t {
    list_t *node_selector_terms; //nonprimitive container

} v1_node_selector_t;

v1_node_selector_t *v1_node_selector_create(
    list_t *node_selector_terms
);

void v1_node_selector_free(v1_node_selector_t *v1_node_selector);

v1_node_selector_t *v1_node_selector_parseFromJSON(cJSON *v1_node_selectorJSON);

cJSON *v1_node_selector_convertToJSON(v1_node_selector_t *v1_node_selector);

#endif /* _v1_node_selector_H_ */

