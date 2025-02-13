/*
 * v1beta1_device_attribute.h
 *
 * DeviceAttribute must have exactly one field set.
 */

#ifndef _v1beta1_device_attribute_H_
#define _v1beta1_device_attribute_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_device_attribute_t v1beta1_device_attribute_t;




typedef struct v1beta1_device_attribute_t {
    int _bool; //boolean
    long _int; //numeric
    char *string; // string
    char *version; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta1_device_attribute_t;

__attribute__((deprecated)) v1beta1_device_attribute_t *v1beta1_device_attribute_create(
    int _bool,
    long _int,
    char *string,
    char *version
);

void v1beta1_device_attribute_free(v1beta1_device_attribute_t *v1beta1_device_attribute);

v1beta1_device_attribute_t *v1beta1_device_attribute_parseFromJSON(cJSON *v1beta1_device_attributeJSON);

cJSON *v1beta1_device_attribute_convertToJSON(v1beta1_device_attribute_t *v1beta1_device_attribute);

#endif /* _v1beta1_device_attribute_H_ */

