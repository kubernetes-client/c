/*
 * v1alpha3_device_taint_rule_spec.h
 *
 * DeviceTaintRuleSpec specifies the selector and one taint.
 */

#ifndef _v1alpha3_device_taint_rule_spec_H_
#define _v1alpha3_device_taint_rule_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_device_taint_rule_spec_t v1alpha3_device_taint_rule_spec_t;

#include "v1alpha3_device_taint.h"
#include "v1alpha3_device_taint_selector.h"



typedef struct v1alpha3_device_taint_rule_spec_t {
    struct v1alpha3_device_taint_selector_t *device_selector; //model
    struct v1alpha3_device_taint_t *taint; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha3_device_taint_rule_spec_t;

__attribute__((deprecated)) v1alpha3_device_taint_rule_spec_t *v1alpha3_device_taint_rule_spec_create(
    v1alpha3_device_taint_selector_t *device_selector,
    v1alpha3_device_taint_t *taint
);

void v1alpha3_device_taint_rule_spec_free(v1alpha3_device_taint_rule_spec_t *v1alpha3_device_taint_rule_spec);

v1alpha3_device_taint_rule_spec_t *v1alpha3_device_taint_rule_spec_parseFromJSON(cJSON *v1alpha3_device_taint_rule_specJSON);

cJSON *v1alpha3_device_taint_rule_spec_convertToJSON(v1alpha3_device_taint_rule_spec_t *v1alpha3_device_taint_rule_spec);

#endif /* _v1alpha3_device_taint_rule_spec_H_ */

