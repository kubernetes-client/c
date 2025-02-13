/*
 * v1beta1_allocated_device_status.h
 *
 * AllocatedDeviceStatus contains the status of an allocated device, if the driver chooses to report it. This may include driver-specific information.
 */

#ifndef _v1beta1_allocated_device_status_H_
#define _v1beta1_allocated_device_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_allocated_device_status_t v1beta1_allocated_device_status_t;

#include "object.h"
#include "v1_condition.h"
#include "v1beta1_network_device_data.h"



typedef struct v1beta1_allocated_device_status_t {
    list_t *conditions; //nonprimitive container
    object_t *data; //object
    char *device; // string
    char *driver; // string
    struct v1beta1_network_device_data_t *network_data; //model
    char *pool; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta1_allocated_device_status_t;

__attribute__((deprecated)) v1beta1_allocated_device_status_t *v1beta1_allocated_device_status_create(
    list_t *conditions,
    object_t *data,
    char *device,
    char *driver,
    v1beta1_network_device_data_t *network_data,
    char *pool
);

void v1beta1_allocated_device_status_free(v1beta1_allocated_device_status_t *v1beta1_allocated_device_status);

v1beta1_allocated_device_status_t *v1beta1_allocated_device_status_parseFromJSON(cJSON *v1beta1_allocated_device_statusJSON);

cJSON *v1beta1_allocated_device_status_convertToJSON(v1beta1_allocated_device_status_t *v1beta1_allocated_device_status);

#endif /* _v1beta1_allocated_device_status_H_ */

