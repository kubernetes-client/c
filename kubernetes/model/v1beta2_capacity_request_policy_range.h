/*
 * v1beta2_capacity_request_policy_range.h
 *
 * CapacityRequestPolicyRange defines a valid range for consumable capacity values.    - If the requested amount is less than Min, it is rounded up to the Min value.   - If Step is set and the requested amount is between Min and Max but not aligned with Step,     it will be rounded up to the next value equal to Min + (n * Step).   - If Step is not set, the requested amount is used as-is if it falls within the range Min to Max (if set).   - If the requested or rounded amount exceeds Max (if set), the request does not satisfy the policy,     and the device cannot be allocated.
 */

#ifndef _v1beta2_capacity_request_policy_range_H_
#define _v1beta2_capacity_request_policy_range_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta2_capacity_request_policy_range_t v1beta2_capacity_request_policy_range_t;




typedef struct v1beta2_capacity_request_policy_range_t {
    char *max; // string
    char *min; // string
    char *step; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta2_capacity_request_policy_range_t;

__attribute__((deprecated)) v1beta2_capacity_request_policy_range_t *v1beta2_capacity_request_policy_range_create(
    char *max,
    char *min,
    char *step
);

void v1beta2_capacity_request_policy_range_free(v1beta2_capacity_request_policy_range_t *v1beta2_capacity_request_policy_range);

v1beta2_capacity_request_policy_range_t *v1beta2_capacity_request_policy_range_parseFromJSON(cJSON *v1beta2_capacity_request_policy_rangeJSON);

cJSON *v1beta2_capacity_request_policy_range_convertToJSON(v1beta2_capacity_request_policy_range_t *v1beta2_capacity_request_policy_range);

#endif /* _v1beta2_capacity_request_policy_range_H_ */

