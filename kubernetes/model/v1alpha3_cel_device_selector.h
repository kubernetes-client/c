/*
 * v1alpha3_cel_device_selector.h
 *
 * CELDeviceSelector contains a CEL expression for selecting a device.
 */

#ifndef _v1alpha3_cel_device_selector_H_
#define _v1alpha3_cel_device_selector_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_cel_device_selector_t v1alpha3_cel_device_selector_t;




typedef struct v1alpha3_cel_device_selector_t {
    char *expression; // string

} v1alpha3_cel_device_selector_t;

v1alpha3_cel_device_selector_t *v1alpha3_cel_device_selector_create(
    char *expression
);

void v1alpha3_cel_device_selector_free(v1alpha3_cel_device_selector_t *v1alpha3_cel_device_selector);

v1alpha3_cel_device_selector_t *v1alpha3_cel_device_selector_parseFromJSON(cJSON *v1alpha3_cel_device_selectorJSON);

cJSON *v1alpha3_cel_device_selector_convertToJSON(v1alpha3_cel_device_selector_t *v1alpha3_cel_device_selector);

#endif /* _v1alpha3_cel_device_selector_H_ */

