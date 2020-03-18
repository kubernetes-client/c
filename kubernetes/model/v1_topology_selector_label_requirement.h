/*
 * v1_topology_selector_label_requirement.h
 *
 * A topology selector requirement is a selector that matches given label. This is an alpha feature and may change in the future.
 */

#ifndef _v1_topology_selector_label_requirement_H_
#define _v1_topology_selector_label_requirement_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_topology_selector_label_requirement_t {
    char *key; // string
    list_t *values; //primitive container

} v1_topology_selector_label_requirement_t;

v1_topology_selector_label_requirement_t *v1_topology_selector_label_requirement_create(
    char *key,
    list_t *values
);

void v1_topology_selector_label_requirement_free(v1_topology_selector_label_requirement_t *v1_topology_selector_label_requirement);

v1_topology_selector_label_requirement_t *v1_topology_selector_label_requirement_parseFromJSON(cJSON *v1_topology_selector_label_requirementJSON);

cJSON *v1_topology_selector_label_requirement_convertToJSON(v1_topology_selector_label_requirement_t *v1_topology_selector_label_requirement);

#endif /* _v1_topology_selector_label_requirement_H_ */

