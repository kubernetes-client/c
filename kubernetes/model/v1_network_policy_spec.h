/*
 * v1_network_policy_spec.h
 *
 * NetworkPolicySpec provides the specification of a NetworkPolicy
 */

#ifndef _v1_network_policy_spec_H_
#define _v1_network_policy_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_network_policy_spec_t v1_network_policy_spec_t;

#include "v1_label_selector.h"
#include "v1_network_policy_egress_rule.h"
#include "v1_network_policy_ingress_rule.h"



typedef struct v1_network_policy_spec_t {
    list_t *egress; //nonprimitive container
    list_t *ingress; //nonprimitive container
    struct v1_label_selector_t *pod_selector; //model
    list_t *policy_types; //primitive container

} v1_network_policy_spec_t;

v1_network_policy_spec_t *v1_network_policy_spec_create(
    list_t *egress,
    list_t *ingress,
    v1_label_selector_t *pod_selector,
    list_t *policy_types
);

void v1_network_policy_spec_free(v1_network_policy_spec_t *v1_network_policy_spec);

v1_network_policy_spec_t *v1_network_policy_spec_parseFromJSON(cJSON *v1_network_policy_specJSON);

cJSON *v1_network_policy_spec_convertToJSON(v1_network_policy_spec_t *v1_network_policy_spec);

#endif /* _v1_network_policy_spec_H_ */

