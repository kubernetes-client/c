/*
 * v1_success_policy_rule.h
 *
 * SuccessPolicyRule describes rule for declaring a Job as succeeded. Each rule must have at least one of the \&quot;succeededIndexes\&quot; or \&quot;succeededCount\&quot; specified.
 */

#ifndef _v1_success_policy_rule_H_
#define _v1_success_policy_rule_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_success_policy_rule_t v1_success_policy_rule_t;




typedef struct v1_success_policy_rule_t {
    int succeeded_count; //numeric
    char *succeeded_indexes; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_success_policy_rule_t;

__attribute__((deprecated)) v1_success_policy_rule_t *v1_success_policy_rule_create(
    int succeeded_count,
    char *succeeded_indexes
);

void v1_success_policy_rule_free(v1_success_policy_rule_t *v1_success_policy_rule);

v1_success_policy_rule_t *v1_success_policy_rule_parseFromJSON(cJSON *v1_success_policy_ruleJSON);

cJSON *v1_success_policy_rule_convertToJSON(v1_success_policy_rule_t *v1_success_policy_rule);

#endif /* _v1_success_policy_rule_H_ */

