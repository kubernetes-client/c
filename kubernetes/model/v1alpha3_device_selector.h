/*
 * v1alpha3_device_selector.h
 *
 * DeviceSelector must have exactly one field set.
 */

#ifndef _v1alpha3_device_selector_H_
#define _v1alpha3_device_selector_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_device_selector_t v1alpha3_device_selector_t;

#include "v1alpha3_cel_device_selector.h"



typedef struct v1alpha3_device_selector_t {
    struct v1alpha3_cel_device_selector_t *cel; //model

} v1alpha3_device_selector_t;

v1alpha3_device_selector_t *v1alpha3_device_selector_create(
    v1alpha3_cel_device_selector_t *cel
);

void v1alpha3_device_selector_free(v1alpha3_device_selector_t *v1alpha3_device_selector);

v1alpha3_device_selector_t *v1alpha3_device_selector_parseFromJSON(cJSON *v1alpha3_device_selectorJSON);

cJSON *v1alpha3_device_selector_convertToJSON(v1alpha3_device_selector_t *v1alpha3_device_selector);

#endif /* _v1alpha3_device_selector_H_ */

