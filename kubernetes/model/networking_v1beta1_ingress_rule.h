/*
 * networking_v1beta1_ingress_rule.h
 *
 * IngressRule represents the rules mapping the paths under a specified host to the related backend services. Incoming requests are first evaluated for a host match, then routed to the backend associated with the matching IngressRuleValue.
 */

#ifndef _networking_v1beta1_ingress_rule_H_
#define _networking_v1beta1_ingress_rule_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct networking_v1beta1_ingress_rule_t networking_v1beta1_ingress_rule_t;

#include "networking_v1beta1_http_ingress_rule_value.h"



typedef struct networking_v1beta1_ingress_rule_t {
    char *host; // string
    struct networking_v1beta1_http_ingress_rule_value_t *http; //model

} networking_v1beta1_ingress_rule_t;

networking_v1beta1_ingress_rule_t *networking_v1beta1_ingress_rule_create(
    char *host,
    networking_v1beta1_http_ingress_rule_value_t *http
);

void networking_v1beta1_ingress_rule_free(networking_v1beta1_ingress_rule_t *networking_v1beta1_ingress_rule);

networking_v1beta1_ingress_rule_t *networking_v1beta1_ingress_rule_parseFromJSON(cJSON *networking_v1beta1_ingress_ruleJSON);

cJSON *networking_v1beta1_ingress_rule_convertToJSON(networking_v1beta1_ingress_rule_t *networking_v1beta1_ingress_rule);

#endif /* _networking_v1beta1_ingress_rule_H_ */

