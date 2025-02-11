/*
 * v1_endpoint_conditions.h
 *
 * EndpointConditions represents the current condition of an endpoint.
 */

#ifndef _v1_endpoint_conditions_H_
#define _v1_endpoint_conditions_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_endpoint_conditions_t v1_endpoint_conditions_t;




typedef struct v1_endpoint_conditions_t {
    int ready; //boolean
    int serving; //boolean
    int terminating; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} v1_endpoint_conditions_t;

__attribute__((deprecated)) v1_endpoint_conditions_t *v1_endpoint_conditions_create(
    int ready,
    int serving,
    int terminating
);

void v1_endpoint_conditions_free(v1_endpoint_conditions_t *v1_endpoint_conditions);

v1_endpoint_conditions_t *v1_endpoint_conditions_parseFromJSON(cJSON *v1_endpoint_conditionsJSON);

cJSON *v1_endpoint_conditions_convertToJSON(v1_endpoint_conditions_t *v1_endpoint_conditions);

#endif /* _v1_endpoint_conditions_H_ */

