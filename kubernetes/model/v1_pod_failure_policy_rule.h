/*
 * v1_pod_failure_policy_rule.h
 *
 * PodFailurePolicyRule describes how a pod failure is handled when the requirements are met. One of onExitCodes and onPodConditions, but not both, can be used in each rule.
 */

#ifndef _v1_pod_failure_policy_rule_H_
#define _v1_pod_failure_policy_rule_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_pod_failure_policy_rule_t v1_pod_failure_policy_rule_t;

#include "v1_pod_failure_policy_on_exit_codes_requirement.h"
#include "v1_pod_failure_policy_on_pod_conditions_pattern.h"



typedef struct v1_pod_failure_policy_rule_t {
    char *action; // string
    struct v1_pod_failure_policy_on_exit_codes_requirement_t *on_exit_codes; //model
    list_t *on_pod_conditions; //nonprimitive container

} v1_pod_failure_policy_rule_t;

v1_pod_failure_policy_rule_t *v1_pod_failure_policy_rule_create(
    char *action,
    v1_pod_failure_policy_on_exit_codes_requirement_t *on_exit_codes,
    list_t *on_pod_conditions
);

void v1_pod_failure_policy_rule_free(v1_pod_failure_policy_rule_t *v1_pod_failure_policy_rule);

v1_pod_failure_policy_rule_t *v1_pod_failure_policy_rule_parseFromJSON(cJSON *v1_pod_failure_policy_ruleJSON);

cJSON *v1_pod_failure_policy_rule_convertToJSON(v1_pod_failure_policy_rule_t *v1_pod_failure_policy_rule);

#endif /* _v1_pod_failure_policy_rule_H_ */

