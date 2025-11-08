/*
 * v1_device_class_configuration.h
 *
 * DeviceClassConfiguration is used in DeviceClass.
 */

#ifndef _v1_device_class_configuration_H_
#define _v1_device_class_configuration_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_device_class_configuration_t v1_device_class_configuration_t;

#include "v1_opaque_device_configuration.h"



typedef struct v1_device_class_configuration_t {
    struct v1_opaque_device_configuration_t *opaque; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1_device_class_configuration_t;

__attribute__((deprecated)) v1_device_class_configuration_t *v1_device_class_configuration_create(
    v1_opaque_device_configuration_t *opaque
);

void v1_device_class_configuration_free(v1_device_class_configuration_t *v1_device_class_configuration);

v1_device_class_configuration_t *v1_device_class_configuration_parseFromJSON(cJSON *v1_device_class_configurationJSON);

cJSON *v1_device_class_configuration_convertToJSON(v1_device_class_configuration_t *v1_device_class_configuration);

#endif /* _v1_device_class_configuration_H_ */

