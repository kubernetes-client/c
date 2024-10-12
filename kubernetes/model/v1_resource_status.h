/*
 * v1_resource_status.h
 *
 * 
 */

#ifndef _v1_resource_status_H_
#define _v1_resource_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_resource_status_t v1_resource_status_t;

#include "v1_resource_health.h"



typedef struct v1_resource_status_t {
    char *name; // string
    list_t *resources; //nonprimitive container

} v1_resource_status_t;

v1_resource_status_t *v1_resource_status_create(
    char *name,
    list_t *resources
);

void v1_resource_status_free(v1_resource_status_t *v1_resource_status);

v1_resource_status_t *v1_resource_status_parseFromJSON(cJSON *v1_resource_statusJSON);

cJSON *v1_resource_status_convertToJSON(v1_resource_status_t *v1_resource_status);

#endif /* _v1_resource_status_H_ */

