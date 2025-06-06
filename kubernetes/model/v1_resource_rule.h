/*
 * v1_resource_rule.h
 *
 * ResourceRule is the list of actions the subject is allowed to perform on resources. The list ordering isn&#39;t significant, may contain duplicates, and possibly be incomplete.
 */

#ifndef _v1_resource_rule_H_
#define _v1_resource_rule_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_resource_rule_t v1_resource_rule_t;




typedef struct v1_resource_rule_t {
    list_t *api_groups; //primitive container
    list_t *resource_names; //primitive container
    list_t *resources; //primitive container
    list_t *verbs; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1_resource_rule_t;

__attribute__((deprecated)) v1_resource_rule_t *v1_resource_rule_create(
    list_t *api_groups,
    list_t *resource_names,
    list_t *resources,
    list_t *verbs
);

void v1_resource_rule_free(v1_resource_rule_t *v1_resource_rule);

v1_resource_rule_t *v1_resource_rule_parseFromJSON(cJSON *v1_resource_ruleJSON);

cJSON *v1_resource_rule_convertToJSON(v1_resource_rule_t *v1_resource_rule);

#endif /* _v1_resource_rule_H_ */

