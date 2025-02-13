/*
 * v1beta1_opaque_device_configuration.h
 *
 * OpaqueDeviceConfiguration contains configuration parameters for a driver in a format defined by the driver vendor.
 */

#ifndef _v1beta1_opaque_device_configuration_H_
#define _v1beta1_opaque_device_configuration_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_opaque_device_configuration_t v1beta1_opaque_device_configuration_t;

#include "object.h"



typedef struct v1beta1_opaque_device_configuration_t {
    char *driver; // string
    object_t *parameters; //object

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta1_opaque_device_configuration_t;

__attribute__((deprecated)) v1beta1_opaque_device_configuration_t *v1beta1_opaque_device_configuration_create(
    char *driver,
    object_t *parameters
);

void v1beta1_opaque_device_configuration_free(v1beta1_opaque_device_configuration_t *v1beta1_opaque_device_configuration);

v1beta1_opaque_device_configuration_t *v1beta1_opaque_device_configuration_parseFromJSON(cJSON *v1beta1_opaque_device_configurationJSON);

cJSON *v1beta1_opaque_device_configuration_convertToJSON(v1beta1_opaque_device_configuration_t *v1beta1_opaque_device_configuration);

#endif /* _v1beta1_opaque_device_configuration_H_ */

