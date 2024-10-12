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
    char *device; // string
    char *driver; // string
    char *pool; // string
    char *request; // string

} v1alpha3_device_request_allocation_result_t;

v1alpha3_device_request_allocation_result_t *v1alpha3_device_request_allocation_result_create(
    char *device,
    char *driver,
    char *pool,
    char *request
);

void v1alpha3_device_request_allocation_result_free(v1alpha3_device_request_allocation_result_t *v1alpha3_device_request_allocation_result);

v1alpha3_device_request_allocation_result_t *v1alpha3_device_request_allocation_result_parseFromJSON(cJSON *v1alpha3_device_request_allocation_resultJSON);

cJSON *v1alpha3_device_request_allocation_result_convertToJSON(v1alpha3_device_request_allocation_result_t *v1alpha3_device_request_allocation_result);

#endif /* _v1alpha3_device_request_allocation_result_H_ */

