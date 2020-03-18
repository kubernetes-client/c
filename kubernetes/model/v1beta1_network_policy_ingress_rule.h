/*
 * v1beta1_network_policy_ingress_rule.h
 *
 * DEPRECATED 1.9 - This group version of NetworkPolicyIngressRule is deprecated by networking/v1/NetworkPolicyIngressRule. This NetworkPolicyIngressRule matches traffic if and only if the traffic matches both ports AND from.
 */

#ifndef _v1beta1_network_policy_ingress_rule_H_
#define _v1beta1_network_policy_ingress_rule_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1beta1_network_policy_peer.h"
#include "v1beta1_network_policy_port.h"



typedef struct v1beta1_network_policy_ingress_rule_t {
    list_t *from; //nonprimitive container
    list_t *ports; //nonprimitive container

} v1beta1_network_policy_ingress_rule_t;

v1beta1_network_policy_ingress_rule_t *v1beta1_network_policy_ingress_rule_create(
    list_t *from,
    list_t *ports
);

void v1beta1_network_policy_ingress_rule_free(v1beta1_network_policy_ingress_rule_t *v1beta1_network_policy_ingress_rule);

v1beta1_network_policy_ingress_rule_t *v1beta1_network_policy_ingress_rule_parseFromJSON(cJSON *v1beta1_network_policy_ingress_ruleJSON);

cJSON *v1beta1_network_policy_ingress_rule_convertToJSON(v1beta1_network_policy_ingress_rule_t *v1beta1_network_policy_ingress_rule);

#endif /* _v1beta1_network_policy_ingress_rule_H_ */

