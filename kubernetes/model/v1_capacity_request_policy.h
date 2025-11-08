/*
 * v1_capacity_request_policy.h
 *
 * CapacityRequestPolicy defines how requests consume device capacity.  Must not set more than one ValidRequestValues.
 */

#ifndef _v1_capacity_request_policy_H_
#define _v1_capacity_request_policy_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_capacity_request_policy_t v1_capacity_request_policy_t;

#include "v1_capacity_request_policy_range.h"



typedef struct v1_capacity_request_policy_t {
    char *_default; // string
    struct v1_capacity_request_policy_range_t *valid_range; //model
    list_t *valid_values; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1_capacity_request_policy_t;

__attribute__((deprecated)) v1_capacity_request_policy_t *v1_capacity_request_policy_create(
    char *_default,
    v1_capacity_request_policy_range_t *valid_range,
    list_t *valid_values
);

void v1_capacity_request_policy_free(v1_capacity_request_policy_t *v1_capacity_request_policy);

v1_capacity_request_policy_t *v1_capacity_request_policy_parseFromJSON(cJSON *v1_capacity_request_policyJSON);

cJSON *v1_capacity_request_policy_convertToJSON(v1_capacity_request_policy_t *v1_capacity_request_policy);

#endif /* _v1_capacity_request_policy_H_ */

