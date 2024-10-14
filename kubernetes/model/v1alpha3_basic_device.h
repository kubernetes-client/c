/*
 * v1alpha3_basic_device.h
 *
 * BasicDevice defines one device instance.
 */

#ifndef _v1alpha3_basic_device_H_
#define _v1alpha3_basic_device_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_basic_device_t v1alpha3_basic_device_t;

#include "v1alpha3_device_attribute.h"



typedef struct v1alpha3_basic_device_t {
    list_t* attributes; //map
    list_t* capacity; //map

} v1alpha3_basic_device_t;

v1alpha3_basic_device_t *v1alpha3_basic_device_create(
    list_t* attributes,
    list_t* capacity
);

void v1alpha3_basic_device_free(v1alpha3_basic_device_t *v1alpha3_basic_device);

v1alpha3_basic_device_t *v1alpha3_basic_device_parseFromJSON(cJSON *v1alpha3_basic_deviceJSON);

cJSON *v1alpha3_basic_device_convertToJSON(v1alpha3_basic_device_t *v1alpha3_basic_device);

#endif /* _v1alpha3_basic_device_H_ */

