/*
 * v1beta1_resource_policy_rule.h
 *
 * ResourcePolicyRule is a predicate that matches some resource requests, testing the request&#39;s verb and the target resource. A ResourcePolicyRule matches a resource request if and only if: (a) at least one member of verbs matches the request, (b) at least one member of apiGroups matches the request, (c) at least one member of resources matches the request, and (d) either (d1) the request does not specify a namespace (i.e., &#x60;Namespace&#x3D;&#x3D;\&quot;\&quot;&#x60;) and clusterScope is true or (d2) the request specifies a namespace and least one member of namespaces matches the request&#39;s namespace.
 */

#ifndef _v1beta1_resource_policy_rule_H_
#define _v1beta1_resource_policy_rule_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_resource_policy_rule_t v1beta1_resource_policy_rule_t;




typedef struct v1beta1_resource_policy_rule_t {
    list_t *api_groups; //primitive container
    int cluster_scope; //boolean
    list_t *namespaces; //primitive container
    list_t *resources; //primitive container
    list_t *verbs; //primitive container

} v1beta1_resource_policy_rule_t;

v1beta1_resource_policy_rule_t *v1beta1_resource_policy_rule_create(
    list_t *api_groups,
    int cluster_scope,
    list_t *namespaces,
    list_t *resources,
    list_t *verbs
);

void v1beta1_resource_policy_rule_free(v1beta1_resource_policy_rule_t *v1beta1_resource_policy_rule);

v1beta1_resource_policy_rule_t *v1beta1_resource_policy_rule_parseFromJSON(cJSON *v1beta1_resource_policy_ruleJSON);

cJSON *v1beta1_resource_policy_rule_convertToJSON(v1beta1_resource_policy_rule_t *v1beta1_resource_policy_rule);

#endif /* _v1beta1_resource_policy_rule_H_ */

