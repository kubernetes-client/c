/*
 * v1_condition.h
 *
 * Condition contains details for one aspect of the current state of this API Resource.
 */

#ifndef _v1_condition_H_
#define _v1_condition_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_condition_t v1_condition_t;




typedef struct v1_condition_t {
    char *last_transition_time; //date time
    char *message; // string
    long observed_generation; //numeric
    char *reason; // string
    char *status; // string
    char *type; // string

} v1_condition_t;

v1_condition_t *v1_condition_create(
    char *last_transition_time,
    char *message,
    long observed_generation,
    char *reason,
    char *status,
    char *type
);

void v1_condition_free(v1_condition_t *v1_condition);

v1_condition_t *v1_condition_parseFromJSON(cJSON *v1_conditionJSON);

cJSON *v1_condition_convertToJSON(v1_condition_t *v1_condition);

#endif /* _v1_condition_H_ */

