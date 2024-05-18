/*
 * v1alpha2_resource_request.h
 *
 * ResourceRequest is a request for resources from one particular driver.
 */

#ifndef _v1alpha2_resource_request_H_
#define _v1alpha2_resource_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha2_resource_request_t v1alpha2_resource_request_t;

#include "object.h"
#include "v1alpha2_named_resources_request.h"



typedef struct v1alpha2_resource_request_t {
    struct v1alpha2_named_resources_request_t *named_resources; //model
    object_t *vendor_parameters; //object

} v1alpha2_resource_request_t;

v1alpha2_resource_request_t *v1alpha2_resource_request_create(
    v1alpha2_named_resources_request_t *named_resources,
    object_t *vendor_parameters
);

void v1alpha2_resource_request_free(v1alpha2_resource_request_t *v1alpha2_resource_request);

v1alpha2_resource_request_t *v1alpha2_resource_request_parseFromJSON(cJSON *v1alpha2_resource_requestJSON);

cJSON *v1alpha2_resource_request_convertToJSON(v1alpha2_resource_request_t *v1alpha2_resource_request);

#endif /* _v1alpha2_resource_request_H_ */

