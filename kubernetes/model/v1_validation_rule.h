/*
 * v1_validation_rule.h
 *
 * ValidationRule describes a validation rule written in the CEL expression language.
 */

#ifndef _v1_validation_rule_H_
#define _v1_validation_rule_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_validation_rule_t v1_validation_rule_t;




typedef struct v1_validation_rule_t {
    char *field_path; // string
    char *message; // string
    char *message_expression; // string
    char *reason; // string
    char *rule; // string

} v1_validation_rule_t;

v1_validation_rule_t *v1_validation_rule_create(
    char *field_path,
    char *message,
    char *message_expression,
    char *reason,
    char *rule
);

void v1_validation_rule_free(v1_validation_rule_t *v1_validation_rule);

v1_validation_rule_t *v1_validation_rule_parseFromJSON(cJSON *v1_validation_ruleJSON);

cJSON *v1_validation_rule_convertToJSON(v1_validation_rule_t *v1_validation_rule);

#endif /* _v1_validation_rule_H_ */

