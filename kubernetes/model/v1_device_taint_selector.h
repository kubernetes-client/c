/*
 * v1_device_taint_selector.h
 *
 * DeviceTaintSelector defines which device(s) a DeviceTaintRule applies to. The empty selector matches all devices. Without a selector, no devices are matched.
 */

#ifndef _v1_device_taint_selector_H_
#define _v1_device_taint_selector_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_device_taint_selector_t v1_device_taint_selector_t;




typedef struct v1_device_taint_selector_t {
    char *device; // string
    char *driver; // string
    char *pool; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_device_taint_selector_t;

__attribute__((deprecated)) v1_device_taint_selector_t *v1_device_taint_selector_create(
    char *device,
    char *driver,
    char *pool
);

void v1_device_taint_selector_free(v1_device_taint_selector_t *v1_device_taint_selector);

v1_device_taint_selector_t *v1_device_taint_selector_parseFromJSON(cJSON *v1_device_taint_selectorJSON);

cJSON *v1_device_taint_selector_convertToJSON(v1_device_taint_selector_t *v1_device_taint_selector);

#endif /* _v1_device_taint_selector_H_ */

