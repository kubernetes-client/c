/*
 * extensions_v1beta1_ingress_rule.h
 *
 * IngressRule represents the rules mapping the paths under a specified host to the related backend services. Incoming requests are first evaluated for a host match, then routed to the backend associated with the matching IngressRuleValue.
 */

#ifndef _extensions_v1beta1_ingress_rule_H_
#define _extensions_v1beta1_ingress_rule_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct extensions_v1beta1_ingress_rule_t extensions_v1beta1_ingress_rule_t;

#include "extensions_v1beta1_http_ingress_rule_value.h"



typedef struct extensions_v1beta1_ingress_rule_t {
    char *host; // string
    struct extensions_v1beta1_http_ingress_rule_value_t *http; //model

} extensions_v1beta1_ingress_rule_t;

extensions_v1beta1_ingress_rule_t *extensions_v1beta1_ingress_rule_create(
    char *host,
    extensions_v1beta1_http_ingress_rule_value_t *http
);

void extensions_v1beta1_ingress_rule_free(extensions_v1beta1_ingress_rule_t *extensions_v1beta1_ingress_rule);

extensions_v1beta1_ingress_rule_t *extensions_v1beta1_ingress_rule_parseFromJSON(cJSON *extensions_v1beta1_ingress_ruleJSON);

cJSON *extensions_v1beta1_ingress_rule_convertToJSON(extensions_v1beta1_ingress_rule_t *extensions_v1beta1_ingress_rule);

#endif /* _extensions_v1beta1_ingress_rule_H_ */

