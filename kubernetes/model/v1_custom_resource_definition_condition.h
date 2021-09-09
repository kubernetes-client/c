/*
 * v1_custom_resource_definition_condition.h
 *
 * CustomResourceDefinitionCondition contains details for the current condition of this pod.
 */

#ifndef _v1_custom_resource_definition_condition_H_
#define _v1_custom_resource_definition_condition_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_custom_resource_definition_condition_t v1_custom_resource_definition_condition_t;




typedef struct v1_custom_resource_definition_condition_t {
    char *last_transition_time; //date time
    char *message; // string
    char *reason; // string
    char *status; // string
    char *type; // string

} v1_custom_resource_definition_condition_t;

v1_custom_resource_definition_condition_t *v1_custom_resource_definition_condition_create(
    char *last_transition_time,
    char *message,
    char *reason,
    char *status,
    char *type
);

void v1_custom_resource_definition_condition_free(v1_custom_resource_definition_condition_t *v1_custom_resource_definition_condition);

v1_custom_resource_definition_condition_t *v1_custom_resource_definition_condition_parseFromJSON(cJSON *v1_custom_resource_definition_conditionJSON);

cJSON *v1_custom_resource_definition_condition_convertToJSON(v1_custom_resource_definition_condition_t *v1_custom_resource_definition_condition);

#endif /* _v1_custom_resource_definition_condition_H_ */

