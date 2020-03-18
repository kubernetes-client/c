/*
 * v1_capabilities.h
 *
 * Adds and removes POSIX capabilities from running containers.
 */

#ifndef _v1_capabilities_H_
#define _v1_capabilities_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_capabilities_t {
    list_t *add; //primitive container
    list_t *drop; //primitive container

} v1_capabilities_t;

v1_capabilities_t *v1_capabilities_create(
    list_t *add,
    list_t *drop
);

void v1_capabilities_free(v1_capabilities_t *v1_capabilities);

v1_capabilities_t *v1_capabilities_parseFromJSON(cJSON *v1_capabilitiesJSON);

cJSON *v1_capabilities_convertToJSON(v1_capabilities_t *v1_capabilities);

#endif /* _v1_capabilities_H_ */

