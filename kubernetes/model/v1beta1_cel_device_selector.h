/*
 * v1beta1_cel_device_selector.h
 *
 * CELDeviceSelector contains a CEL expression for selecting a device.
 */

#ifndef _v1beta1_cel_device_selector_H_
#define _v1beta1_cel_device_selector_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_cel_device_selector_t v1beta1_cel_device_selector_t;




typedef struct v1beta1_cel_device_selector_t {
    char *expression; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta1_cel_device_selector_t;

__attribute__((deprecated)) v1beta1_cel_device_selector_t *v1beta1_cel_device_selector_create(
    char *expression
);

void v1beta1_cel_device_selector_free(v1beta1_cel_device_selector_t *v1beta1_cel_device_selector);

v1beta1_cel_device_selector_t *v1beta1_cel_device_selector_parseFromJSON(cJSON *v1beta1_cel_device_selectorJSON);

cJSON *v1beta1_cel_device_selector_convertToJSON(v1beta1_cel_device_selector_t *v1beta1_cel_device_selector);

#endif /* _v1beta1_cel_device_selector_H_ */

