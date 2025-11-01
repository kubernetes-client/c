/*
 * v1_container_restart_rule_on_exit_codes.h
 *
 * ContainerRestartRuleOnExitCodes describes the condition for handling an exited container based on its exit codes.
 */

#ifndef _v1_container_restart_rule_on_exit_codes_H_
#define _v1_container_restart_rule_on_exit_codes_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_container_restart_rule_on_exit_codes_t v1_container_restart_rule_on_exit_codes_t;




typedef struct v1_container_restart_rule_on_exit_codes_t {
    char *_operator; // string
    list_t *values; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1_container_restart_rule_on_exit_codes_t;

__attribute__((deprecated)) v1_container_restart_rule_on_exit_codes_t *v1_container_restart_rule_on_exit_codes_create(
    char *_operator,
    list_t *values
);

void v1_container_restart_rule_on_exit_codes_free(v1_container_restart_rule_on_exit_codes_t *v1_container_restart_rule_on_exit_codes);

v1_container_restart_rule_on_exit_codes_t *v1_container_restart_rule_on_exit_codes_parseFromJSON(cJSON *v1_container_restart_rule_on_exit_codesJSON);

cJSON *v1_container_restart_rule_on_exit_codes_convertToJSON(v1_container_restart_rule_on_exit_codes_t *v1_container_restart_rule_on_exit_codes);

#endif /* _v1_container_restart_rule_on_exit_codes_H_ */

