/*
 * v1_endpoint.h
 *
 * Endpoint represents a single logical \&quot;backend\&quot; implementing a service.
 */

#ifndef _v1_endpoint_H_
#define _v1_endpoint_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_endpoint_t v1_endpoint_t;

#include "v1_endpoint_conditions.h"
#include "v1_endpoint_hints.h"
#include "v1_object_reference.h"



typedef struct v1_endpoint_t {
    list_t *addresses; //primitive container
    struct v1_endpoint_conditions_t *conditions; //model
    list_t* deprecated_topology; //map
    struct v1_endpoint_hints_t *hints; //model
    char *hostname; // string
    char *node_name; // string
    struct v1_object_reference_t *target_ref; //model
    char *zone; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_endpoint_t;

__attribute__((deprecated)) v1_endpoint_t *v1_endpoint_create(
    list_t *addresses,
    v1_endpoint_conditions_t *conditions,
    list_t* deprecated_topology,
    v1_endpoint_hints_t *hints,
    char *hostname,
    char *node_name,
    v1_object_reference_t *target_ref,
    char *zone
);

void v1_endpoint_free(v1_endpoint_t *v1_endpoint);

v1_endpoint_t *v1_endpoint_parseFromJSON(cJSON *v1_endpointJSON);

cJSON *v1_endpoint_convertToJSON(v1_endpoint_t *v1_endpoint);

#endif /* _v1_endpoint_H_ */

