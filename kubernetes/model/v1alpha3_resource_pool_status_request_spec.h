/*
 * v1alpha3_resource_pool_status_request_spec.h
 *
 * ResourcePoolStatusRequestSpec defines the filters for the pool status request.
 */

#ifndef _v1alpha3_resource_pool_status_request_spec_H_
#define _v1alpha3_resource_pool_status_request_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_resource_pool_status_request_spec_t v1alpha3_resource_pool_status_request_spec_t;




typedef struct v1alpha3_resource_pool_status_request_spec_t {
    char *default_partition_type_attribute; // string
    char *driver; // string
    int *limit; //numeric
    char *pool_name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha3_resource_pool_status_request_spec_t;

__attribute__((deprecated)) v1alpha3_resource_pool_status_request_spec_t *v1alpha3_resource_pool_status_request_spec_create(
    char *default_partition_type_attribute,
    char *driver,
    int *limit,
    char *pool_name
);

void v1alpha3_resource_pool_status_request_spec_free(v1alpha3_resource_pool_status_request_spec_t *v1alpha3_resource_pool_status_request_spec);

v1alpha3_resource_pool_status_request_spec_t *v1alpha3_resource_pool_status_request_spec_parseFromJSON(cJSON *v1alpha3_resource_pool_status_request_specJSON);

cJSON *v1alpha3_resource_pool_status_request_spec_convertToJSON(v1alpha3_resource_pool_status_request_spec_t *v1alpha3_resource_pool_status_request_spec);

#endif /* _v1alpha3_resource_pool_status_request_spec_H_ */

