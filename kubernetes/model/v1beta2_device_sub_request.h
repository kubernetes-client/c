/*
 * v1beta2_device_sub_request.h
 *
 * DeviceSubRequest describes a request for device provided in the claim.spec.devices.requests[].firstAvailable array. Each is typically a request for a single resource like a device, but can also ask for several identical devices.  DeviceSubRequest is similar to ExactDeviceRequest, but doesn&#39;t expose the AdminAccess field as that one is only supported when requesting a specific device.
 */

#ifndef _v1beta2_device_sub_request_H_
#define _v1beta2_device_sub_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta2_device_sub_request_t v1beta2_device_sub_request_t;

#include "v1beta2_device_selector.h"
#include "v1beta2_device_toleration.h"



typedef struct v1beta2_device_sub_request_t {
    char *allocation_mode; // string
    long count; //numeric
    char *device_class_name; // string
    char *name; // string
    list_t *selectors; //nonprimitive container
    list_t *tolerations; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta2_device_sub_request_t;

__attribute__((deprecated)) v1beta2_device_sub_request_t *v1beta2_device_sub_request_create(
    char *allocation_mode,
    long count,
    char *device_class_name,
    char *name,
    list_t *selectors,
    list_t *tolerations
);

void v1beta2_device_sub_request_free(v1beta2_device_sub_request_t *v1beta2_device_sub_request);

v1beta2_device_sub_request_t *v1beta2_device_sub_request_parseFromJSON(cJSON *v1beta2_device_sub_requestJSON);

cJSON *v1beta2_device_sub_request_convertToJSON(v1beta2_device_sub_request_t *v1beta2_device_sub_request);

#endif /* _v1beta2_device_sub_request_H_ */

