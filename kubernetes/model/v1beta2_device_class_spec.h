/*
 * v1beta2_device_class_spec.h
 *
 * DeviceClassSpec is used in a [DeviceClass] to define what can be allocated and how to configure it.
 */

#ifndef _v1beta2_device_class_spec_H_
#define _v1beta2_device_class_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta2_device_class_spec_t v1beta2_device_class_spec_t;

#include "v1beta2_device_class_configuration.h"
#include "v1beta2_device_selector.h"



typedef struct v1beta2_device_class_spec_t {
    list_t *config; //nonprimitive container
    list_t *selectors; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta2_device_class_spec_t;

__attribute__((deprecated)) v1beta2_device_class_spec_t *v1beta2_device_class_spec_create(
    list_t *config,
    list_t *selectors
);

void v1beta2_device_class_spec_free(v1beta2_device_class_spec_t *v1beta2_device_class_spec);

v1beta2_device_class_spec_t *v1beta2_device_class_spec_parseFromJSON(cJSON *v1beta2_device_class_specJSON);

cJSON *v1beta2_device_class_spec_convertToJSON(v1beta2_device_class_spec_t *v1beta2_device_class_spec);

#endif /* _v1beta2_device_class_spec_H_ */

