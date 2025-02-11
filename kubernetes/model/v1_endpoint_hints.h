/*
 * v1_endpoint_hints.h
 *
 * EndpointHints provides hints describing how an endpoint should be consumed.
 */

#ifndef _v1_endpoint_hints_H_
#define _v1_endpoint_hints_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_endpoint_hints_t v1_endpoint_hints_t;

#include "v1_for_zone.h"



typedef struct v1_endpoint_hints_t {
    list_t *for_zones; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1_endpoint_hints_t;

__attribute__((deprecated)) v1_endpoint_hints_t *v1_endpoint_hints_create(
    list_t *for_zones
);

void v1_endpoint_hints_free(v1_endpoint_hints_t *v1_endpoint_hints);

v1_endpoint_hints_t *v1_endpoint_hints_parseFromJSON(cJSON *v1_endpoint_hintsJSON);

cJSON *v1_endpoint_hints_convertToJSON(v1_endpoint_hints_t *v1_endpoint_hints);

#endif /* _v1_endpoint_hints_H_ */

