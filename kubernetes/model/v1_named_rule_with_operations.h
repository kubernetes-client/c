/*
 * v1_named_rule_with_operations.h
 *
 * NamedRuleWithOperations is a tuple of Operations and Resources with ResourceNames.
 */

#ifndef _v1_named_rule_with_operations_H_
#define _v1_named_rule_with_operations_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_named_rule_with_operations_t v1_named_rule_with_operations_t;




typedef struct v1_named_rule_with_operations_t {
    list_t *api_groups; //primitive container
    list_t *api_versions; //primitive container
    list_t *operations; //primitive container
    list_t *resource_names; //primitive container
    list_t *resources; //primitive container
    char *scope; // string

} v1_named_rule_with_operations_t;

v1_named_rule_with_operations_t *v1_named_rule_with_operations_create(
    list_t *api_groups,
    list_t *api_versions,
    list_t *operations,
    list_t *resource_names,
    list_t *resources,
    char *scope
);

void v1_named_rule_with_operations_free(v1_named_rule_with_operations_t *v1_named_rule_with_operations);

v1_named_rule_with_operations_t *v1_named_rule_with_operations_parseFromJSON(cJSON *v1_named_rule_with_operationsJSON);

cJSON *v1_named_rule_with_operations_convertToJSON(v1_named_rule_with_operations_t *v1_named_rule_with_operations);

#endif /* _v1_named_rule_with_operations_H_ */

