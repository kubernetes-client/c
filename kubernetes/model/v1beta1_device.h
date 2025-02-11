/*
 * v1beta1_device.h
 *
 * Device represents one individual hardware instance that can be selected based on its attributes. Besides the name, exactly one field must be set.
 */

#ifndef _v1beta1_device_H_
#define _v1beta1_device_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_device_t v1beta1_device_t;

#include "v1beta1_basic_device.h"



typedef struct v1beta1_device_t {
    struct v1beta1_basic_device_t *basic; //model
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta1_device_t;

__attribute__((deprecated)) v1beta1_device_t *v1beta1_device_create(
    v1beta1_basic_device_t *basic,
    char *name
);

void v1beta1_device_free(v1beta1_device_t *v1beta1_device);

v1beta1_device_t *v1beta1_device_parseFromJSON(cJSON *v1beta1_deviceJSON);

cJSON *v1beta1_device_convertToJSON(v1beta1_device_t *v1beta1_device);

#endif /* _v1beta1_device_H_ */

