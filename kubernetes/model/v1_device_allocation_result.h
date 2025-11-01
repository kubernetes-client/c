/*
 * v1_device_allocation_result.h
 *
 * DeviceAllocationResult is the result of allocating devices.
 */

#ifndef _v1_device_allocation_result_H_
#define _v1_device_allocation_result_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_device_allocation_result_t v1_device_allocation_result_t;

#include "v1_device_allocation_configuration.h"
#include "v1_device_request_allocation_result.h"



typedef struct v1_device_allocation_result_t {
    list_t *config; //nonprimitive container
    list_t *results; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1_device_allocation_result_t;

__attribute__((deprecated)) v1_device_allocation_result_t *v1_device_allocation_result_create(
    list_t *config,
    list_t *results
);

void v1_device_allocation_result_free(v1_device_allocation_result_t *v1_device_allocation_result);

v1_device_allocation_result_t *v1_device_allocation_result_parseFromJSON(cJSON *v1_device_allocation_resultJSON);

cJSON *v1_device_allocation_result_convertToJSON(v1_device_allocation_result_t *v1_device_allocation_result);

#endif /* _v1_device_allocation_result_H_ */

