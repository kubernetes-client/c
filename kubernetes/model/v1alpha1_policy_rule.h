/*
 * v1alpha1_policy_rule.h
 *
 * PolicyRule holds information that describes a policy rule, but does not contain information about who the rule applies to or which namespace the rule applies to.
 */

#ifndef _v1alpha1_policy_rule_H_
#define _v1alpha1_policy_rule_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_policy_rule_t v1alpha1_policy_rule_t;




typedef struct v1alpha1_policy_rule_t {
    list_t *api_groups; //primitive container
    list_t *non_resource_urls; //primitive container
    list_t *resource_names; //primitive container
    list_t *resources; //primitive container
    list_t *verbs; //primitive container

} v1alpha1_policy_rule_t;

v1alpha1_policy_rule_t *v1alpha1_policy_rule_create(
    list_t *api_groups,
    list_t *non_resource_urls,
    list_t *resource_names,
    list_t *resources,
    list_t *verbs
);

void v1alpha1_policy_rule_free(v1alpha1_policy_rule_t *v1alpha1_policy_rule);

v1alpha1_policy_rule_t *v1alpha1_policy_rule_parseFromJSON(cJSON *v1alpha1_policy_ruleJSON);

cJSON *v1alpha1_policy_rule_convertToJSON(v1alpha1_policy_rule_t *v1alpha1_policy_rule);

#endif /* _v1alpha1_policy_rule_H_ */

