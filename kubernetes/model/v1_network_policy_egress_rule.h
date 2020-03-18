/*
 * v1_network_policy_egress_rule.h
 *
 * NetworkPolicyEgressRule describes a particular set of traffic that is allowed out of pods matched by a NetworkPolicySpec&#39;s podSelector. The traffic must match both ports and to. This type is beta-level in 1.8
 */

#ifndef _v1_network_policy_egress_rule_H_
#define _v1_network_policy_egress_rule_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1_network_policy_peer.h"
#include "v1_network_policy_port.h"



typedef struct v1_network_policy_egress_rule_t {
    list_t *ports; //nonprimitive container
    list_t *to; //nonprimitive container

} v1_network_policy_egress_rule_t;

v1_network_policy_egress_rule_t *v1_network_policy_egress_rule_create(
    list_t *ports,
    list_t *to
);

void v1_network_policy_egress_rule_free(v1_network_policy_egress_rule_t *v1_network_policy_egress_rule);

v1_network_policy_egress_rule_t *v1_network_policy_egress_rule_parseFromJSON(cJSON *v1_network_policy_egress_ruleJSON);

cJSON *v1_network_policy_egress_rule_convertToJSON(v1_network_policy_egress_rule_t *v1_network_policy_egress_rule);

#endif /* _v1_network_policy_egress_rule_H_ */

