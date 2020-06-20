/*
 * v1_preferred_scheduling_term.h
 *
 * An empty preferred scheduling term matches all objects with implicit weight 0 (i.e. it&#39;s a no-op). A null preferred scheduling term matches no objects (i.e. is also a no-op).
 */

#ifndef _v1_preferred_scheduling_term_H_
#define _v1_preferred_scheduling_term_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_preferred_scheduling_term_t v1_preferred_scheduling_term_t;

#include "v1_node_selector_term.h"



typedef struct v1_preferred_scheduling_term_t {
    struct v1_node_selector_term_t *preference; //model
    int weight; //numeric

} v1_preferred_scheduling_term_t;

v1_preferred_scheduling_term_t *v1_preferred_scheduling_term_create(
    v1_node_selector_term_t *preference,
    int weight
);

void v1_preferred_scheduling_term_free(v1_preferred_scheduling_term_t *v1_preferred_scheduling_term);

v1_preferred_scheduling_term_t *v1_preferred_scheduling_term_parseFromJSON(cJSON *v1_preferred_scheduling_termJSON);

cJSON *v1_preferred_scheduling_term_convertToJSON(v1_preferred_scheduling_term_t *v1_preferred_scheduling_term);

#endif /* _v1_preferred_scheduling_term_H_ */

