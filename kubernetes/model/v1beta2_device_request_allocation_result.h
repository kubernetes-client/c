/*
 * v1beta2_device_request_allocation_result.h
 *
 * DeviceRequestAllocationResult contains the allocation result for one request.
 */

#ifndef _v1beta2_device_request_allocation_result_H_
#define _v1beta2_device_request_allocation_result_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta2_device_request_allocation_result_t v1beta2_device_request_allocation_result_t;

#include "v1beta2_device_toleration.h"



typedef struct v1beta2_device_request_allocation_result_t {
    int admin_access; //boolean
    char *device; // string
    char *driver; // string
    char *pool; // string
    char *request; // string
    list_t *tolerations; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta2_device_request_allocation_result_t;

__attribute__((deprecated)) v1beta2_device_request_allocation_result_t *v1beta2_device_request_allocation_result_create(
    int admin_access,
    char *device,
    char *driver,
    char *pool,
    char *request,
    list_t *tolerations
);

void v1beta2_device_request_allocation_result_free(v1beta2_device_request_allocation_result_t *v1beta2_device_request_allocation_result);

v1beta2_device_request_allocation_result_t *v1beta2_device_request_allocation_result_parseFromJSON(cJSON *v1beta2_device_request_allocation_resultJSON);

cJSON *v1beta2_device_request_allocation_result_convertToJSON(v1beta2_device_request_allocation_result_t *v1beta2_device_request_allocation_result);

#endif /* _v1beta2_device_request_allocation_result_H_ */

