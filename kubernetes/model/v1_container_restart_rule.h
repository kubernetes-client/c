/*
 * v1_container_restart_rule.h
 *
 * ContainerRestartRule describes how a container exit is handled.
 */

#ifndef _v1_container_restart_rule_H_
#define _v1_container_restart_rule_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_container_restart_rule_t v1_container_restart_rule_t;

#include "v1_container_restart_rule_on_exit_codes.h"



typedef struct v1_container_restart_rule_t {
    char *action; // string
    struct v1_container_restart_rule_on_exit_codes_t *exit_codes; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1_container_restart_rule_t;

__attribute__((deprecated)) v1_container_restart_rule_t *v1_container_restart_rule_create(
    char *action,
    v1_container_restart_rule_on_exit_codes_t *exit_codes
);

void v1_container_restart_rule_free(v1_container_restart_rule_t *v1_container_restart_rule);

v1_container_restart_rule_t *v1_container_restart_rule_parseFromJSON(cJSON *v1_container_restart_ruleJSON);

cJSON *v1_container_restart_rule_convertToJSON(v1_container_restart_rule_t *v1_container_restart_rule);

#endif /* _v1_container_restart_rule_H_ */

