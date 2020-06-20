/*
 * v1_topology_selector_term.h
 *
 * A topology selector term represents the result of label queries. A null or empty topology selector term matches no objects. The requirements of them are ANDed. It provides a subset of functionality as NodeSelectorTerm. This is an alpha feature and may change in the future.
 */

#ifndef _v1_topology_selector_term_H_
#define _v1_topology_selector_term_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_topology_selector_term_t v1_topology_selector_term_t;

#include "v1_topology_selector_label_requirement.h"



typedef struct v1_topology_selector_term_t {
    list_t *match_label_expressions; //nonprimitive container

} v1_topology_selector_term_t;

v1_topology_selector_term_t *v1_topology_selector_term_create(
    list_t *match_label_expressions
);

void v1_topology_selector_term_free(v1_topology_selector_term_t *v1_topology_selector_term);

v1_topology_selector_term_t *v1_topology_selector_term_parseFromJSON(cJSON *v1_topology_selector_termJSON);

cJSON *v1_topology_selector_term_convertToJSON(v1_topology_selector_term_t *v1_topology_selector_term);

#endif /* _v1_topology_selector_term_H_ */

