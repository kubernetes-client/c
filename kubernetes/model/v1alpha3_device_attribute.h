/*
 * v1alpha3_device_attribute.h
 *
 * DeviceAttribute must have exactly one field set.
 */

#ifndef _v1alpha3_device_attribute_H_
#define _v1alpha3_device_attribute_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_device_attribute_t v1alpha3_device_attribute_t;




typedef struct v1alpha3_device_attribute_t {
    int _bool; //boolean
    long _int; //numeric
    char *string; // string
    char *version; // string

} v1alpha3_device_attribute_t;

v1alpha3_device_attribute_t *v1alpha3_device_attribute_create(
    int _bool,
    long _int,
    char *string,
    char *version
);

void v1alpha3_device_attribute_free(v1alpha3_device_attribute_t *v1alpha3_device_attribute);

v1alpha3_device_attribute_t *v1alpha3_device_attribute_parseFromJSON(cJSON *v1alpha3_device_attributeJSON);

cJSON *v1alpha3_device_attribute_convertToJSON(v1alpha3_device_attribute_t *v1alpha3_device_attribute);

#endif /* _v1alpha3_device_attribute_H_ */

