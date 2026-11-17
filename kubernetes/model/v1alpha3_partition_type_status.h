/*
 * v1alpha3_partition_type_status.h
 *
 * PartitionTypeStatus reports allocatability for a single partition type, identified by the value of a grouping attribute.
 */

#ifndef _v1alpha3_partition_type_status_H_
#define _v1alpha3_partition_type_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_partition_type_status_t v1alpha3_partition_type_status_t;




typedef struct v1alpha3_partition_type_status_t {
    int *allocatable; //numeric
    char *attribute; // string
    int *total; //numeric
    char *type; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha3_partition_type_status_t;

__attribute__((deprecated)) v1alpha3_partition_type_status_t *v1alpha3_partition_type_status_create(
    int *allocatable,
    char *attribute,
    int *total,
    char *type
);

void v1alpha3_partition_type_status_free(v1alpha3_partition_type_status_t *v1alpha3_partition_type_status);

v1alpha3_partition_type_status_t *v1alpha3_partition_type_status_parseFromJSON(cJSON *v1alpha3_partition_type_statusJSON);

cJSON *v1alpha3_partition_type_status_convertToJSON(v1alpha3_partition_type_status_t *v1alpha3_partition_type_status);

#endif /* _v1alpha3_partition_type_status_H_ */

