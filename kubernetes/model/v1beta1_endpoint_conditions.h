/*
 * v1beta1_endpoint_conditions.h
 *
 * EndpointConditions represents the current condition of an endpoint.
 */

#ifndef _v1beta1_endpoint_conditions_H_
#define _v1beta1_endpoint_conditions_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_endpoint_conditions_t v1beta1_endpoint_conditions_t;




typedef struct v1beta1_endpoint_conditions_t {
    int ready; //boolean

} v1beta1_endpoint_conditions_t;

v1beta1_endpoint_conditions_t *v1beta1_endpoint_conditions_create(
    int ready
);

void v1beta1_endpoint_conditions_free(v1beta1_endpoint_conditions_t *v1beta1_endpoint_conditions);

v1beta1_endpoint_conditions_t *v1beta1_endpoint_conditions_parseFromJSON(cJSON *v1beta1_endpoint_conditionsJSON);

cJSON *v1beta1_endpoint_conditions_convertToJSON(v1beta1_endpoint_conditions_t *v1beta1_endpoint_conditions);

#endif /* _v1beta1_endpoint_conditions_H_ */

