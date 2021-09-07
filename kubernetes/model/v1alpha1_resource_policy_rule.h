/*
 * v1alpha1_resource_policy_rule.h
 *
 * ResourcePolicyRule is a predicate that matches some resource requests, testing the request&#39;s verb and the target resource. A ResourcePolicyRule matches a resource request if and only if: (a) at least one member of verbs matches the request, (b) at least one member of apiGroups matches the request, (c) at least one member of resources matches the request, and (d) least one member of namespaces matches the request.
 */

#ifndef _v1alpha1_resource_policy_rule_H_
#define _v1alpha1_resource_policy_rule_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_resource_policy_rule_t v1alpha1_resource_policy_rule_t;




typedef struct v1alpha1_resource_policy_rule_t {
    list_t *api_groups; //primitive container
    int cluster_scope; //boolean
    list_t *namespaces; //primitive container
    list_t *resources; //primitive container
    list_t *verbs; //primitive container

} v1alpha1_resource_policy_rule_t;

v1alpha1_resource_policy_rule_t *v1alpha1_resource_policy_rule_create(
    list_t *api_groups,
    int cluster_scope,
    list_t *namespaces,
    list_t *resources,
    list_t *verbs
);

void v1alpha1_resource_policy_rule_free(v1alpha1_resource_policy_rule_t *v1alpha1_resource_policy_rule);

v1alpha1_resource_policy_rule_t *v1alpha1_resource_policy_rule_parseFromJSON(cJSON *v1alpha1_resource_policy_ruleJSON);

cJSON *v1alpha1_resource_policy_rule_convertToJSON(v1alpha1_resource_policy_rule_t *v1alpha1_resource_policy_rule);

#endif /* _v1alpha1_resource_policy_rule_H_ */

