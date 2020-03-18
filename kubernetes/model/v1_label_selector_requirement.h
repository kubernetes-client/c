/*
 * v1_label_selector_requirement.h
 *
 * A label selector requirement is a selector that contains values, a key, and an operator that relates the key and values.
 */

#ifndef _v1_label_selector_requirement_H_
#define _v1_label_selector_requirement_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_label_selector_requirement_t {
    char *key; // string
    char *operator; // string
    list_t *values; //primitive container

} v1_label_selector_requirement_t;

v1_label_selector_requirement_t *v1_label_selector_requirement_create(
    char *key,
    char *operator,
    list_t *values
);

void v1_label_selector_requirement_free(v1_label_selector_requirement_t *v1_label_selector_requirement);

v1_label_selector_requirement_t *v1_label_selector_requirement_parseFromJSON(cJSON *v1_label_selector_requirementJSON);

cJSON *v1_label_selector_requirement_convertToJSON(v1_label_selector_requirement_t *v1_label_selector_requirement);

#endif /* _v1_label_selector_requirement_H_ */

