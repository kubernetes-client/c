/*
 * v1alpha2_driver_requests.h
 *
 * DriverRequests describes all resources that are needed from one particular driver.
 */

#ifndef _v1alpha2_driver_requests_H_
#define _v1alpha2_driver_requests_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha2_driver_requests_t v1alpha2_driver_requests_t;

#include "object.h"
#include "v1alpha2_resource_request.h"



typedef struct v1alpha2_driver_requests_t {
    char *driver_name; // string
    list_t *requests; //nonprimitive container
    object_t *vendor_parameters; //object

} v1alpha2_driver_requests_t;

v1alpha2_driver_requests_t *v1alpha2_driver_requests_create(
    char *driver_name,
    list_t *requests,
    object_t *vendor_parameters
);

void v1alpha2_driver_requests_free(v1alpha2_driver_requests_t *v1alpha2_driver_requests);

v1alpha2_driver_requests_t *v1alpha2_driver_requests_parseFromJSON(cJSON *v1alpha2_driver_requestsJSON);

cJSON *v1alpha2_driver_requests_convertToJSON(v1alpha2_driver_requests_t *v1alpha2_driver_requests);

#endif /* _v1alpha2_driver_requests_H_ */

