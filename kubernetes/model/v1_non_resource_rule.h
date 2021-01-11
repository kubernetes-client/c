/*
 * v1_non_resource_rule.h
 *
 * NonResourceRule holds information that describes a rule for the non-resource
 */

#ifndef _v1_non_resource_rule_H_
#define _v1_non_resource_rule_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_non_resource_rule_t v1_non_resource_rule_t;




typedef struct v1_non_resource_rule_t {
    list_t *non_resource_urls; //primitive container
    list_t *verbs; //primitive container

} v1_non_resource_rule_t;

v1_non_resource_rule_t *v1_non_resource_rule_create(
    list_t *non_resource_urls,
    list_t *verbs
);

void v1_non_resource_rule_free(v1_non_resource_rule_t *v1_non_resource_rule);

v1_non_resource_rule_t *v1_non_resource_rule_parseFromJSON(cJSON *v1_non_resource_ruleJSON);

cJSON *v1_non_resource_rule_convertToJSON(v1_non_resource_rule_t *v1_non_resource_rule);

#endif /* _v1_non_resource_rule_H_ */

