/*
 * v1_device_attribute.h
 *
 * DeviceAttribute must have exactly one field set.
 */

#ifndef _v1_device_attribute_H_
#define _v1_device_attribute_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_device_attribute_t v1_device_attribute_t;




typedef struct v1_device_attribute_t {
    int *_bool; //boolean
    list_t *bools; //primitive container
    long *_int; //numeric
    list_t *ints; //primitive container
    char *string; // string
    list_t *strings; //primitive container
    char *version; // string
    list_t *versions; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1_device_attribute_t;

__attribute__((deprecated)) v1_device_attribute_t *v1_device_attribute_create(
    int *_bool,
    list_t *bools,
    long *_int,
    list_t *ints,
    char *string,
    list_t *strings,
    char *version,
    list_t *versions
);

void v1_device_attribute_free(v1_device_attribute_t *v1_device_attribute);

v1_device_attribute_t *v1_device_attribute_parseFromJSON(cJSON *v1_device_attributeJSON);

cJSON *v1_device_attribute_convertToJSON(v1_device_attribute_t *v1_device_attribute);

#endif /* _v1_device_attribute_H_ */

