/*
 * v1alpha2_driver_allocation_result.h
 *
 * DriverAllocationResult contains vendor parameters and the allocation result for one request.
 */

#ifndef _v1alpha2_driver_allocation_result_H_
#define _v1alpha2_driver_allocation_result_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha2_driver_allocation_result_t v1alpha2_driver_allocation_result_t;

#include "object.h"
#include "v1alpha2_named_resources_allocation_result.h"



typedef struct v1alpha2_driver_allocation_result_t {
    struct v1alpha2_named_resources_allocation_result_t *named_resources; //model
    object_t *vendor_request_parameters; //object

} v1alpha2_driver_allocation_result_t;

v1alpha2_driver_allocation_result_t *v1alpha2_driver_allocation_result_create(
    v1alpha2_named_resources_allocation_result_t *named_resources,
    object_t *vendor_request_parameters
);

void v1alpha2_driver_allocation_result_free(v1alpha2_driver_allocation_result_t *v1alpha2_driver_allocation_result);

v1alpha2_driver_allocation_result_t *v1alpha2_driver_allocation_result_parseFromJSON(cJSON *v1alpha2_driver_allocation_resultJSON);

cJSON *v1alpha2_driver_allocation_result_convertToJSON(v1alpha2_driver_allocation_result_t *v1alpha2_driver_allocation_result);

#endif /* _v1alpha2_driver_allocation_result_H_ */

