/*
 * v1_node_selector_term.h
 *
 * A null or empty node selector term matches no objects. The requirements of them are ANDed. The TopologySelectorTerm type implements a subset of the NodeSelectorTerm.
 */

#ifndef _v1_node_selector_term_H_
#define _v1_node_selector_term_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_node_selector_term_t v1_node_selector_term_t;

#include "v1_node_selector_requirement.h"



typedef struct v1_node_selector_term_t {
    list_t *match_expressions; //nonprimitive container
    list_t *match_fields; //nonprimitive container

} v1_node_selector_term_t;

v1_node_selector_term_t *v1_node_selector_term_create(
    list_t *match_expressions,
    list_t *match_fields
);

void v1_node_selector_term_free(v1_node_selector_term_t *v1_node_selector_term);

v1_node_selector_term_t *v1_node_selector_term_parseFromJSON(cJSON *v1_node_selector_termJSON);

cJSON *v1_node_selector_term_convertToJSON(v1_node_selector_term_t *v1_node_selector_term);

#endif /* _v1_node_selector_term_H_ */

