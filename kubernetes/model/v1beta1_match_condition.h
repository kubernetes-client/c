/*
 * v1beta1_match_condition.h
 *
 * MatchCondition represents a condition which must be fulfilled for a request to be sent to a webhook.
 */

#ifndef _v1beta1_match_condition_H_
#define _v1beta1_match_condition_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_match_condition_t v1beta1_match_condition_t;




typedef struct v1beta1_match_condition_t {
    char *expression; // string
    char *name; // string

} v1beta1_match_condition_t;

v1beta1_match_condition_t *v1beta1_match_condition_create(
    char *expression,
    char *name
);

void v1beta1_match_condition_free(v1beta1_match_condition_t *v1beta1_match_condition);

v1beta1_match_condition_t *v1beta1_match_condition_parseFromJSON(cJSON *v1beta1_match_conditionJSON);

cJSON *v1beta1_match_condition_convertToJSON(v1beta1_match_condition_t *v1beta1_match_condition);

#endif /* _v1beta1_match_condition_H_ */

