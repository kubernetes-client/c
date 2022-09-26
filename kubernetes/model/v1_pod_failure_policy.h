/*
 * v1_pod_failure_policy.h
 *
 * PodFailurePolicy describes how failed pods influence the backoffLimit.
 */

#ifndef _v1_pod_failure_policy_H_
#define _v1_pod_failure_policy_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_pod_failure_policy_t v1_pod_failure_policy_t;

#include "v1_pod_failure_policy_rule.h"



typedef struct v1_pod_failure_policy_t {
    list_t *rules; //nonprimitive container

} v1_pod_failure_policy_t;

v1_pod_failure_policy_t *v1_pod_failure_policy_create(
    list_t *rules
);

void v1_pod_failure_policy_free(v1_pod_failure_policy_t *v1_pod_failure_policy);

v1_pod_failure_policy_t *v1_pod_failure_policy_parseFromJSON(cJSON *v1_pod_failure_policyJSON);

cJSON *v1_pod_failure_policy_convertToJSON(v1_pod_failure_policy_t *v1_pod_failure_policy);

#endif /* _v1_pod_failure_policy_H_ */

