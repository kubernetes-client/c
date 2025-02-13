/*
 * v1_ingress_rule.h
 *
 * IngressRule represents the rules mapping the paths under a specified host to the related backend services. Incoming requests are first evaluated for a host match, then routed to the backend associated with the matching IngressRuleValue.
 */

#ifndef _v1_ingress_rule_H_
#define _v1_ingress_rule_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_ingress_rule_t v1_ingress_rule_t;

#include "v1_http_ingress_rule_value.h"



typedef struct v1_ingress_rule_t {
    char *host; // string
    struct v1_http_ingress_rule_value_t *http; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1_ingress_rule_t;

__attribute__((deprecated)) v1_ingress_rule_t *v1_ingress_rule_create(
    char *host,
    v1_http_ingress_rule_value_t *http
);

void v1_ingress_rule_free(v1_ingress_rule_t *v1_ingress_rule);

v1_ingress_rule_t *v1_ingress_rule_parseFromJSON(cJSON *v1_ingress_ruleJSON);

cJSON *v1_ingress_rule_convertToJSON(v1_ingress_rule_t *v1_ingress_rule);

#endif /* _v1_ingress_rule_H_ */

