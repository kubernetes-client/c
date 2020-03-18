/*
 * v1_component_condition.h
 *
 * Information about the condition of a component.
 */

#ifndef _v1_component_condition_H_
#define _v1_component_condition_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_component_condition_t {
    char *error; // string
    char *message; // string
    char *status; // string
    char *type; // string

} v1_component_condition_t;

v1_component_condition_t *v1_component_condition_create(
    char *error,
    char *message,
    char *status,
    char *type
);

void v1_component_condition_free(v1_component_condition_t *v1_component_condition);

v1_component_condition_t *v1_component_condition_parseFromJSON(cJSON *v1_component_conditionJSON);

cJSON *v1_component_condition_convertToJSON(v1_component_condition_t *v1_component_condition);

#endif /* _v1_component_condition_H_ */

