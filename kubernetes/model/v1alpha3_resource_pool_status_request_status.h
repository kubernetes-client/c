/*
 * v1alpha3_resource_pool_status_request_status.h
 *
 * ResourcePoolStatusRequestStatus contains the calculated pool status information.
 */

#ifndef _v1alpha3_resource_pool_status_request_status_H_
#define _v1alpha3_resource_pool_status_request_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_resource_pool_status_request_status_t v1alpha3_resource_pool_status_request_status_t;

#include "v1_condition.h"
#include "v1alpha3_pool_status.h"



typedef struct v1alpha3_resource_pool_status_request_status_t {
    list_t *conditions; //nonprimitive container
    int *pool_count; //numeric
    list_t *pools; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha3_resource_pool_status_request_status_t;

__attribute__((deprecated)) v1alpha3_resource_pool_status_request_status_t *v1alpha3_resource_pool_status_request_status_create(
    list_t *conditions,
    int *pool_count,
    list_t *pools
);

void v1alpha3_resource_pool_status_request_status_free(v1alpha3_resource_pool_status_request_status_t *v1alpha3_resource_pool_status_request_status);

v1alpha3_resource_pool_status_request_status_t *v1alpha3_resource_pool_status_request_status_parseFromJSON(cJSON *v1alpha3_resource_pool_status_request_statusJSON);

cJSON *v1alpha3_resource_pool_status_request_status_convertToJSON(v1alpha3_resource_pool_status_request_status_t *v1alpha3_resource_pool_status_request_status);

#endif /* _v1alpha3_resource_pool_status_request_status_H_ */

