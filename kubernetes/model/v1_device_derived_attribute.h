/*
 * v1_device_derived_attribute.h
 *
 * DeviceDerivedAttribute defines a derived attribute computed via CEL.
 */

#ifndef _v1_device_derived_attribute_H_
#define _v1_device_derived_attribute_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_device_derived_attribute_t v1_device_derived_attribute_t;




typedef struct v1_device_derived_attribute_t {
    char *expression; // string
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_device_derived_attribute_t;

__attribute__((deprecated)) v1_device_derived_attribute_t *v1_device_derived_attribute_create(
    char *expression,
    char *name
);

void v1_device_derived_attribute_free(v1_device_derived_attribute_t *v1_device_derived_attribute);

v1_device_derived_attribute_t *v1_device_derived_attribute_parseFromJSON(cJSON *v1_device_derived_attributeJSON);

cJSON *v1_device_derived_attribute_convertToJSON(v1_device_derived_attribute_t *v1_device_derived_attribute);

#endif /* _v1_device_derived_attribute_H_ */

