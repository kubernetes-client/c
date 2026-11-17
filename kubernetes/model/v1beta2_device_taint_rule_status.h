/*
 * v1beta2_device_taint_rule_status.h
 *
 * DeviceTaintRuleStatus provides information about an on-going pod eviction.
 */

#ifndef _v1beta2_device_taint_rule_status_H_
#define _v1beta2_device_taint_rule_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta2_device_taint_rule_status_t v1beta2_device_taint_rule_status_t;

#include "v1_condition.h"



typedef struct v1beta2_device_taint_rule_status_t {
    list_t *conditions; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta2_device_taint_rule_status_t;

__attribute__((deprecated)) v1beta2_device_taint_rule_status_t *v1beta2_device_taint_rule_status_create(
    list_t *conditions
);

void v1beta2_device_taint_rule_status_free(v1beta2_device_taint_rule_status_t *v1beta2_device_taint_rule_status);

v1beta2_device_taint_rule_status_t *v1beta2_device_taint_rule_status_parseFromJSON(cJSON *v1beta2_device_taint_rule_statusJSON);

cJSON *v1beta2_device_taint_rule_status_convertToJSON(v1beta2_device_taint_rule_status_t *v1beta2_device_taint_rule_status);

#endif /* _v1beta2_device_taint_rule_status_H_ */

