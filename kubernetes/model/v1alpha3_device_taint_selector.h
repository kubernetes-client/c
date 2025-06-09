/*
 * v1alpha3_device_taint_selector.h
 *
 * DeviceTaintSelector defines which device(s) a DeviceTaintRule applies to. The empty selector matches all devices. Without a selector, no devices are matched.
 */

#ifndef _v1alpha3_device_taint_selector_H_
#define _v1alpha3_device_taint_selector_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_device_taint_selector_t v1alpha3_device_taint_selector_t;

#include "v1alpha3_device_selector.h"



typedef struct v1alpha3_device_taint_selector_t {
    char *device; // string
    char *device_class_name; // string
    char *driver; // string
    char *pool; // string
    list_t *selectors; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha3_device_taint_selector_t;

__attribute__((deprecated)) v1alpha3_device_taint_selector_t *v1alpha3_device_taint_selector_create(
    char *device,
    char *device_class_name,
    char *driver,
    char *pool,
    list_t *selectors
);

void v1alpha3_device_taint_selector_free(v1alpha3_device_taint_selector_t *v1alpha3_device_taint_selector);

v1alpha3_device_taint_selector_t *v1alpha3_device_taint_selector_parseFromJSON(cJSON *v1alpha3_device_taint_selectorJSON);

cJSON *v1alpha3_device_taint_selector_convertToJSON(v1alpha3_device_taint_selector_t *v1alpha3_device_taint_selector);

#endif /* _v1alpha3_device_taint_selector_H_ */

