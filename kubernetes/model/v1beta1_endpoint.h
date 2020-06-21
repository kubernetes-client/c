/*
 * v1beta1_endpoint.h
 *
 * Endpoint represents a single logical \&quot;backend\&quot; implementing a service.
 */

#ifndef _v1beta1_endpoint_H_
#define _v1beta1_endpoint_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_endpoint_t v1beta1_endpoint_t;

#include "v1_object_reference.h"
#include "v1beta1_endpoint_conditions.h"



typedef struct v1beta1_endpoint_t {
    list_t *addresses; //primitive container
    struct v1beta1_endpoint_conditions_t *conditions; //model
    char *hostname; // string
    struct v1_object_reference_t *target_ref; //model
    list_t* topology; //map

} v1beta1_endpoint_t;

v1beta1_endpoint_t *v1beta1_endpoint_create(
    list_t *addresses,
    v1beta1_endpoint_conditions_t *conditions,
    char *hostname,
    v1_object_reference_t *target_ref,
    list_t* topology
);

void v1beta1_endpoint_free(v1beta1_endpoint_t *v1beta1_endpoint);

v1beta1_endpoint_t *v1beta1_endpoint_parseFromJSON(cJSON *v1beta1_endpointJSON);

cJSON *v1beta1_endpoint_convertToJSON(v1beta1_endpoint_t *v1beta1_endpoint);

#endif /* _v1beta1_endpoint_H_ */

