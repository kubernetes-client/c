/*
 * v1_priority_level_configuration_condition.h
 *
 * PriorityLevelConfigurationCondition defines the condition of priority level.
 */

#ifndef _v1_priority_level_configuration_condition_H_
#define _v1_priority_level_configuration_condition_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_priority_level_configuration_condition_t v1_priority_level_configuration_condition_t;




typedef struct v1_priority_level_configuration_condition_t {
    char *last_transition_time; //date time
    char *message; // string
    char *reason; // string
    char *status; // string
    char *type; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_priority_level_configuration_condition_t;

__attribute__((deprecated)) v1_priority_level_configuration_condition_t *v1_priority_level_configuration_condition_create(
    char *last_transition_time,
    char *message,
    char *reason,
    char *status,
    char *type
);

void v1_priority_level_configuration_condition_free(v1_priority_level_configuration_condition_t *v1_priority_level_configuration_condition);

v1_priority_level_configuration_condition_t *v1_priority_level_configuration_condition_parseFromJSON(cJSON *v1_priority_level_configuration_conditionJSON);

cJSON *v1_priority_level_configuration_condition_convertToJSON(v1_priority_level_configuration_condition_t *v1_priority_level_configuration_condition);

#endif /* _v1_priority_level_configuration_condition_H_ */

