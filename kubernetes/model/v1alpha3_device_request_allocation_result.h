/*
 * v1alpha3_device_request_allocation_result.h
 *
 * DeviceRequestAllocationResult contains the allocation result for one request.
 */

#ifndef _v1alpha3_device_request_allocation_result_H_
#define _v1alpha3_device_request_allocation_result_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_device_request_allocation_result_t v1alpha3_device_request_allocation_result_t;




typedef struct v1alpha3_device_request_allocation_result_t {
    int admin_access; //boolean
    char *device; // string
    char *driver; // string
    char *pool; // string
    char *request; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha3_device_request_allocation_result_t;

__attribute__((deprecated)) v1alpha3_device_request_allocation_result_t *v1alpha3_device_request_allocation_result_create(
    int admin_access,
    char *device,
    char *driver,
    char *pool,
    char *request
);

void v1alpha3_device_request_allocation_result_free(v1alpha3_device_request_allocation_result_t *v1alpha3_device_request_allocation_result);

v1alpha3_device_request_allocation_result_t *v1alpha3_device_request_allocation_result_parseFromJSON(cJSON *v1alpha3_device_request_allocation_resultJSON);

cJSON *v1alpha3_device_request_allocation_result_convertToJSON(v1alpha3_device_request_allocation_result_t *v1alpha3_device_request_allocation_result);

#endif /* _v1alpha3_device_request_allocation_result_H_ */

