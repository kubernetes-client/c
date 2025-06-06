/*
 * v1beta2_device_request.h
 *
 * DeviceRequest is a request for devices required for a claim. This is typically a request for a single resource like a device, but can also ask for several identical devices. With FirstAvailable it is also possible to provide a prioritized list of requests.
 */

#ifndef _v1beta2_device_request_H_
#define _v1beta2_device_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta2_device_request_t v1beta2_device_request_t;

#include "v1beta2_device_sub_request.h"
#include "v1beta2_exact_device_request.h"



typedef struct v1beta2_device_request_t {
    struct v1beta2_exact_device_request_t *exactly; //model
    list_t *first_available; //nonprimitive container
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta2_device_request_t;

__attribute__((deprecated)) v1beta2_device_request_t *v1beta2_device_request_create(
    v1beta2_exact_device_request_t *exactly,
    list_t *first_available,
    char *name
);

void v1beta2_device_request_free(v1beta2_device_request_t *v1beta2_device_request);

v1beta2_device_request_t *v1beta2_device_request_parseFromJSON(cJSON *v1beta2_device_requestJSON);

cJSON *v1beta2_device_request_convertToJSON(v1beta2_device_request_t *v1beta2_device_request);

#endif /* _v1beta2_device_request_H_ */

