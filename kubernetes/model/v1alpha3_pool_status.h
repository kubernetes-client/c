/*
 * v1alpha3_pool_status.h
 *
 * PoolStatus contains status information for a single resource pool.
 */

#ifndef _v1alpha3_pool_status_H_
#define _v1alpha3_pool_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_pool_status_t v1alpha3_pool_status_t;

#include "v1alpha3_partition_type_status.h"
#include "v1alpha3_shareable_summary_status.h"



typedef struct v1alpha3_pool_status_t {
    int *allocated_devices; //numeric
    int *available_devices; //numeric
    char *driver; // string
    long *generation; //numeric
    char *node_name; // string
    list_t *partition_summary; //nonprimitive container
    char *pool_name; // string
    int *resource_slice_count; //numeric
    struct v1alpha3_shareable_summary_status_t *shareable_summary; //model
    int *total_devices; //numeric
    int *unavailable_devices; //numeric
    char *validation_error; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha3_pool_status_t;

__attribute__((deprecated)) v1alpha3_pool_status_t *v1alpha3_pool_status_create(
    int *allocated_devices,
    int *available_devices,
    char *driver,
    long *generation,
    char *node_name,
    list_t *partition_summary,
    char *pool_name,
    int *resource_slice_count,
    v1alpha3_shareable_summary_status_t *shareable_summary,
    int *total_devices,
    int *unavailable_devices,
    char *validation_error
);

void v1alpha3_pool_status_free(v1alpha3_pool_status_t *v1alpha3_pool_status);

v1alpha3_pool_status_t *v1alpha3_pool_status_parseFromJSON(cJSON *v1alpha3_pool_statusJSON);

cJSON *v1alpha3_pool_status_convertToJSON(v1alpha3_pool_status_t *v1alpha3_pool_status);

#endif /* _v1alpha3_pool_status_H_ */

