/*
 * v1_storage_health.h
 *
 * StorageHealth contains storage backend health reported by a CSI driver on a node.
 */

#ifndef _v1_storage_health_H_
#define _v1_storage_health_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_storage_health_t v1_storage_health_t;

#include "v1_storage_health_condition.h"



typedef struct v1_storage_health_t {
    list_t *health_conditions; //nonprimitive container
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_storage_health_t;

__attribute__((deprecated)) v1_storage_health_t *v1_storage_health_create(
    list_t *health_conditions,
    char *name
);

void v1_storage_health_free(v1_storage_health_t *v1_storage_health);

v1_storage_health_t *v1_storage_health_parseFromJSON(cJSON *v1_storage_healthJSON);

cJSON *v1_storage_health_convertToJSON(v1_storage_health_t *v1_storage_health);

#endif /* _v1_storage_health_H_ */

