/*
 * v1_device_taint_rule_spec.h
 *
 * DeviceTaintRuleSpec specifies the selector and one taint.
 */

#ifndef _v1_device_taint_rule_spec_H_
#define _v1_device_taint_rule_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_device_taint_rule_spec_t v1_device_taint_rule_spec_t;

#include "v1_device_taint.h"
#include "v1_device_taint_selector.h"



typedef struct v1_device_taint_rule_spec_t {
    struct v1_device_taint_selector_t *device_selector; //model
    struct v1_device_taint_t *taint; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1_device_taint_rule_spec_t;

__attribute__((deprecated)) v1_device_taint_rule_spec_t *v1_device_taint_rule_spec_create(
    v1_device_taint_selector_t *device_selector,
    v1_device_taint_t *taint
);

void v1_device_taint_rule_spec_free(v1_device_taint_rule_spec_t *v1_device_taint_rule_spec);

v1_device_taint_rule_spec_t *v1_device_taint_rule_spec_parseFromJSON(cJSON *v1_device_taint_rule_specJSON);

cJSON *v1_device_taint_rule_spec_convertToJSON(v1_device_taint_rule_spec_t *v1_device_taint_rule_spec);

#endif /* _v1_device_taint_rule_spec_H_ */

