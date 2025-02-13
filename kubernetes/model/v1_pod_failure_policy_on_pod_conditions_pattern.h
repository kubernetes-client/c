/*
 * v1_pod_failure_policy_on_pod_conditions_pattern.h
 *
 * PodFailurePolicyOnPodConditionsPattern describes a pattern for matching an actual pod condition type.
 */

#ifndef _v1_pod_failure_policy_on_pod_conditions_pattern_H_
#define _v1_pod_failure_policy_on_pod_conditions_pattern_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_pod_failure_policy_on_pod_conditions_pattern_t v1_pod_failure_policy_on_pod_conditions_pattern_t;




typedef struct v1_pod_failure_policy_on_pod_conditions_pattern_t {
    char *status; // string
    char *type; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_pod_failure_policy_on_pod_conditions_pattern_t;

__attribute__((deprecated)) v1_pod_failure_policy_on_pod_conditions_pattern_t *v1_pod_failure_policy_on_pod_conditions_pattern_create(
    char *status,
    char *type
);

void v1_pod_failure_policy_on_pod_conditions_pattern_free(v1_pod_failure_policy_on_pod_conditions_pattern_t *v1_pod_failure_policy_on_pod_conditions_pattern);

v1_pod_failure_policy_on_pod_conditions_pattern_t *v1_pod_failure_policy_on_pod_conditions_pattern_parseFromJSON(cJSON *v1_pod_failure_policy_on_pod_conditions_patternJSON);

cJSON *v1_pod_failure_policy_on_pod_conditions_pattern_convertToJSON(v1_pod_failure_policy_on_pod_conditions_pattern_t *v1_pod_failure_policy_on_pod_conditions_pattern);

#endif /* _v1_pod_failure_policy_on_pod_conditions_pattern_H_ */

