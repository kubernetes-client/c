/*
 * v1alpha3_resource_pool.h
 *
 * ResourcePool describes the pool that ResourceSlices belong to.
 */

#ifndef _v1alpha3_resource_pool_H_
#define _v1alpha3_resource_pool_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_resource_pool_t v1alpha3_resource_pool_t;




typedef struct v1alpha3_resource_pool_t {
    long generation; //numeric
    char *name; // string
    long resource_slice_count; //numeric

} v1alpha3_resource_pool_t;

v1alpha3_resource_pool_t *v1alpha3_resource_pool_create(
    long generation,
    char *name,
    long resource_slice_count
);

void v1alpha3_resource_pool_free(v1alpha3_resource_pool_t *v1alpha3_resource_pool);

v1alpha3_resource_pool_t *v1alpha3_resource_pool_parseFromJSON(cJSON *v1alpha3_resource_poolJSON);

cJSON *v1alpha3_resource_pool_convertToJSON(v1alpha3_resource_pool_t *v1alpha3_resource_pool);

#endif /* _v1alpha3_resource_pool_H_ */

