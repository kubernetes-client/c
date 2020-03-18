/*
 * v1_network_policy_ingress_rule.h
 *
 * NetworkPolicyIngressRule describes a particular set of traffic that is allowed to the pods matched by a NetworkPolicySpec&#39;s podSelector. The traffic must match both ports and from.
 */

#ifndef _v1_network_policy_ingress_rule_H_
#define _v1_network_policy_ingress_rule_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_network_policy_peer.h"
#include "v1_network_policy_port.h"



typedef struct v1_network_policy_ingress_rule_t {
    list_t *from; //nonprimitive container
    list_t *ports; //nonprimitive container

} v1_network_policy_ingress_rule_t;

v1_network_policy_ingress_rule_t *v1_network_policy_ingress_rule_create(
    list_t *from,
    list_t *ports
);

void v1_network_policy_ingress_rule_free(v1_network_policy_ingress_rule_t *v1_network_policy_ingress_rule);

v1_network_policy_ingress_rule_t *v1_network_policy_ingress_rule_parseFromJSON(cJSON *v1_network_policy_ingress_ruleJSON);

cJSON *v1_network_policy_ingress_rule_convertToJSON(v1_network_policy_ingress_rule_t *v1_network_policy_ingress_rule);

#endif /* _v1_network_policy_ingress_rule_H_ */

