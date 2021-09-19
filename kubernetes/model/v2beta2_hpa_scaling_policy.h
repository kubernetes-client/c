/*
 * v2beta2_hpa_scaling_policy.h
 *
 * HPAScalingPolicy is a single policy which must hold true for a specified past interval.
 */

#ifndef _v2beta2_hpa_scaling_policy_H_
#define _v2beta2_hpa_scaling_policy_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v2beta2_hpa_scaling_policy_t v2beta2_hpa_scaling_policy_t;




typedef struct v2beta2_hpa_scaling_policy_t {
    int period_seconds; //numeric
    char *type; // string
    int value; //numeric

} v2beta2_hpa_scaling_policy_t;

v2beta2_hpa_scaling_policy_t *v2beta2_hpa_scaling_policy_create(
    int period_seconds,
    char *type,
    int value
);

void v2beta2_hpa_scaling_policy_free(v2beta2_hpa_scaling_policy_t *v2beta2_hpa_scaling_policy);

v2beta2_hpa_scaling_policy_t *v2beta2_hpa_scaling_policy_parseFromJSON(cJSON *v2beta2_hpa_scaling_policyJSON);

cJSON *v2beta2_hpa_scaling_policy_convertToJSON(v2beta2_hpa_scaling_policy_t *v2beta2_hpa_scaling_policy);

#endif /* _v2beta2_hpa_scaling_policy_H_ */

