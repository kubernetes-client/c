/*
 * v1alpha3_device_taint_rule.h
 *
 * DeviceTaintRule adds one taint to all devices which match the selector. This has the same effect as if the taint was specified directly in the ResourceSlice by the DRA driver.
 */

#ifndef _v1alpha3_device_taint_rule_H_
#define _v1alpha3_device_taint_rule_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_device_taint_rule_t v1alpha3_device_taint_rule_t;

#include "v1_object_meta.h"
#include "v1alpha3_device_taint_rule_spec.h"



typedef struct v1alpha3_device_taint_rule_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1alpha3_device_taint_rule_spec_t *spec; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha3_device_taint_rule_t;

__attribute__((deprecated)) v1alpha3_device_taint_rule_t *v1alpha3_device_taint_rule_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha3_device_taint_rule_spec_t *spec
);

void v1alpha3_device_taint_rule_free(v1alpha3_device_taint_rule_t *v1alpha3_device_taint_rule);

v1alpha3_device_taint_rule_t *v1alpha3_device_taint_rule_parseFromJSON(cJSON *v1alpha3_device_taint_ruleJSON);

cJSON *v1alpha3_device_taint_rule_convertToJSON(v1alpha3_device_taint_rule_t *v1alpha3_device_taint_rule);

#endif /* _v1alpha3_device_taint_rule_H_ */

