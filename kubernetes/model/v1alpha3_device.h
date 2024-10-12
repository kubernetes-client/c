/*
 * v1alpha3_device.h
 *
 * Device represents one individual hardware instance that can be selected based on its attributes. Besides the name, exactly one field must be set.
 */

#ifndef _v1alpha3_device_H_
#define _v1alpha3_device_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_device_t v1alpha3_device_t;

#include "v1alpha3_basic_device.h"



typedef struct v1alpha3_device_t {
    struct v1alpha3_basic_device_t *basic; //model
    char *name; // string

} v1alpha3_device_t;

v1alpha3_device_t *v1alpha3_device_create(
    v1alpha3_basic_device_t *basic,
    char *name
);

void v1alpha3_device_free(v1alpha3_device_t *v1alpha3_device);

v1alpha3_device_t *v1alpha3_device_parseFromJSON(cJSON *v1alpha3_deviceJSON);

cJSON *v1alpha3_device_convertToJSON(v1alpha3_device_t *v1alpha3_device);

#endif /* _v1alpha3_device_H_ */

