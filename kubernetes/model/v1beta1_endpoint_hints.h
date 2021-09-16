/*
 * v1beta1_endpoint_hints.h
 *
 * EndpointHints provides hints describing how an endpoint should be consumed.
 */

#ifndef _v1beta1_endpoint_hints_H_
#define _v1beta1_endpoint_hints_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_endpoint_hints_t v1beta1_endpoint_hints_t;

#include "v1beta1_for_zone.h"



typedef struct v1beta1_endpoint_hints_t {
    list_t *for_zones; //nonprimitive container

} v1beta1_endpoint_hints_t;

v1beta1_endpoint_hints_t *v1beta1_endpoint_hints_create(
    list_t *for_zones
);

void v1beta1_endpoint_hints_free(v1beta1_endpoint_hints_t *v1beta1_endpoint_hints);

v1beta1_endpoint_hints_t *v1beta1_endpoint_hints_parseFromJSON(cJSON *v1beta1_endpoint_hintsJSON);

cJSON *v1beta1_endpoint_hints_convertToJSON(v1beta1_endpoint_hints_t *v1beta1_endpoint_hints);

#endif /* _v1beta1_endpoint_hints_H_ */

