/*
 * v1_match_condition.h
 *
 * MatchCondition represents a condition which must by fulfilled for a request to be sent to a webhook.
 */

#ifndef _v1_match_condition_H_
#define _v1_match_condition_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_match_condition_t v1_match_condition_t;




typedef struct v1_match_condition_t {
    char *expression; // string
    char *name; // string

} v1_match_condition_t;

v1_match_condition_t *v1_match_condition_create(
    char *expression,
    char *name
);

void v1_match_condition_free(v1_match_condition_t *v1_match_condition);

v1_match_condition_t *v1_match_condition_parseFromJSON(cJSON *v1_match_conditionJSON);

cJSON *v1_match_condition_convertToJSON(v1_match_condition_t *v1_match_condition);

#endif /* _v1_match_condition_H_ */

