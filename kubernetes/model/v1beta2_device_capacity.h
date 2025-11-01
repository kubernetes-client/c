/*
 * v1beta2_device_capacity.h
 *
 * DeviceCapacity describes a quantity associated with a device.
 */

#ifndef _v1beta2_device_capacity_H_
#define _v1beta2_device_capacity_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta2_device_capacity_t v1beta2_device_capacity_t;

#include "v1beta2_capacity_request_policy.h"



typedef struct v1beta2_device_capacity_t {
    struct v1beta2_capacity_request_policy_t *request_policy; //model
    char *value; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta2_device_capacity_t;

__attribute__((deprecated)) v1beta2_device_capacity_t *v1beta2_device_capacity_create(
    v1beta2_capacity_request_policy_t *request_policy,
    char *value
);

void v1beta2_device_capacity_free(v1beta2_device_capacity_t *v1beta2_device_capacity);

v1beta2_device_capacity_t *v1beta2_device_capacity_parseFromJSON(cJSON *v1beta2_device_capacityJSON);

cJSON *v1beta2_device_capacity_convertToJSON(v1beta2_device_capacity_t *v1beta2_device_capacity);

#endif /* _v1beta2_device_capacity_H_ */

