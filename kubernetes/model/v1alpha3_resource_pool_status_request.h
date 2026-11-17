/*
 * v1alpha3_resource_pool_status_request.h
 *
 * ResourcePoolStatusRequest triggers a one-time calculation of resource pool status based on the provided filters. Once status is set, the request is considered complete and will not be reprocessed. Users should delete and recreate requests to get updated information.
 */

#ifndef _v1alpha3_resource_pool_status_request_H_
#define _v1alpha3_resource_pool_status_request_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_resource_pool_status_request_t v1alpha3_resource_pool_status_request_t;

#include "v1_object_meta.h"
#include "v1alpha3_resource_pool_status_request_spec.h"
#include "v1alpha3_resource_pool_status_request_status.h"



typedef struct v1alpha3_resource_pool_status_request_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1alpha3_resource_pool_status_request_spec_t *spec; //model
    struct v1alpha3_resource_pool_status_request_status_t *status; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha3_resource_pool_status_request_t;

__attribute__((deprecated)) v1alpha3_resource_pool_status_request_t *v1alpha3_resource_pool_status_request_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha3_resource_pool_status_request_spec_t *spec,
    v1alpha3_resource_pool_status_request_status_t *status
);

void v1alpha3_resource_pool_status_request_free(v1alpha3_resource_pool_status_request_t *v1alpha3_resource_pool_status_request);

v1alpha3_resource_pool_status_request_t *v1alpha3_resource_pool_status_request_parseFromJSON(cJSON *v1alpha3_resource_pool_status_requestJSON);

cJSON *v1alpha3_resource_pool_status_request_convertToJSON(v1alpha3_resource_pool_status_request_t *v1alpha3_resource_pool_status_request);

#endif /* _v1alpha3_resource_pool_status_request_H_ */

