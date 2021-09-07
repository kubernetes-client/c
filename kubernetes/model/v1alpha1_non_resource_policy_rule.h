/*
 * v1alpha1_non_resource_policy_rule.h
 *
 * NonResourcePolicyRule is a predicate that matches non-resource requests according to their verb and the target non-resource URL. A NonResourcePolicyRule matches a request if and only if both (a) at least one member of verbs matches the request and (b) at least one member of nonResourceURLs matches the request.
 */

#ifndef _v1alpha1_non_resource_policy_rule_H_
#define _v1alpha1_non_resource_policy_rule_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_non_resource_policy_rule_t v1alpha1_non_resource_policy_rule_t;




typedef struct v1alpha1_non_resource_policy_rule_t {
    list_t *non_resource_urls; //primitive container
    list_t *verbs; //primitive container

} v1alpha1_non_resource_policy_rule_t;

v1alpha1_non_resource_policy_rule_t *v1alpha1_non_resource_policy_rule_create(
    list_t *non_resource_urls,
    list_t *verbs
);

void v1alpha1_non_resource_policy_rule_free(v1alpha1_non_resource_policy_rule_t *v1alpha1_non_resource_policy_rule);

v1alpha1_non_resource_policy_rule_t *v1alpha1_non_resource_policy_rule_parseFromJSON(cJSON *v1alpha1_non_resource_policy_ruleJSON);

cJSON *v1alpha1_non_resource_policy_rule_convertToJSON(v1alpha1_non_resource_policy_rule_t *v1alpha1_non_resource_policy_rule);

#endif /* _v1alpha1_non_resource_policy_rule_H_ */

