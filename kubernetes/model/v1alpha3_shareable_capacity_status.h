/*
 * v1alpha3_shareable_capacity_status.h
 *
 * ShareableCapacityStatus reports aggregate amounts for a single shareable capacity key.
 */

#ifndef _v1alpha3_shareable_capacity_status_H_
#define _v1alpha3_shareable_capacity_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_shareable_capacity_status_t v1alpha3_shareable_capacity_status_t;




typedef struct v1alpha3_shareable_capacity_status_t {
    char *available; // string
    char *consumed; // string
    char *name; // string
    char *total; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha3_shareable_capacity_status_t;

__attribute__((deprecated)) v1alpha3_shareable_capacity_status_t *v1alpha3_shareable_capacity_status_create(
    char *available,
    char *consumed,
    char *name,
    char *total
);

void v1alpha3_shareable_capacity_status_free(v1alpha3_shareable_capacity_status_t *v1alpha3_shareable_capacity_status);

v1alpha3_shareable_capacity_status_t *v1alpha3_shareable_capacity_status_parseFromJSON(cJSON *v1alpha3_shareable_capacity_statusJSON);

cJSON *v1alpha3_shareable_capacity_status_convertToJSON(v1alpha3_shareable_capacity_status_t *v1alpha3_shareable_capacity_status);

#endif /* _v1alpha3_shareable_capacity_status_H_ */

