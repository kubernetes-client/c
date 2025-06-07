/*
 * v1beta1_device_request.h
 *
 * DeviceRequest is a request for devices required for a claim. This is typically a request for a single resource like a device, but can also ask for several identical devices.
 */

#ifndef _v1beta1_device_request_H_
#define _v1beta1_device_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_device_request_t v1beta1_device_request_t;

#include "v1beta1_device_selector.h"
#include "v1beta1_device_sub_request.h"
#include "v1beta1_device_toleration.h"



typedef struct v1beta1_device_request_t {
    int admin_access; //boolean
    char *allocation_mode; // string
    long count; //numeric
    char *device_class_name; // string
    list_t *first_available; //nonprimitive container
    char *name; // string
    list_t *selectors; //nonprimitive container
    list_t *tolerations; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta1_device_request_t;

__attribute__((deprecated)) v1beta1_device_request_t *v1beta1_device_request_create(
    int admin_access,
    char *allocation_mode,
    long count,
    char *device_class_name,
    list_t *first_available,
    char *name,
    list_t *selectors,
    list_t *tolerations
);

void v1beta1_device_request_free(v1beta1_device_request_t *v1beta1_device_request);

v1beta1_device_request_t *v1beta1_device_request_parseFromJSON(cJSON *v1beta1_device_requestJSON);

cJSON *v1beta1_device_request_convertToJSON(v1beta1_device_request_t *v1beta1_device_request);

#endif /* _v1beta1_device_request_H_ */

