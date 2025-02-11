/*
 * v1_pod_failure_policy_on_exit_codes_requirement.h
 *
 * PodFailurePolicyOnExitCodesRequirement describes the requirement for handling a failed pod based on its container exit codes. In particular, it lookups the .state.terminated.exitCode for each app container and init container status, represented by the .status.containerStatuses and .status.initContainerStatuses fields in the Pod status, respectively. Containers completed with success (exit code 0) are excluded from the requirement check.
 */

#ifndef _v1_pod_failure_policy_on_exit_codes_requirement_H_
#define _v1_pod_failure_policy_on_exit_codes_requirement_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_pod_failure_policy_on_exit_codes_requirement_t v1_pod_failure_policy_on_exit_codes_requirement_t;




typedef struct v1_pod_failure_policy_on_exit_codes_requirement_t {
    char *container_name; // string
    char *_operator; // string
    list_t *values; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1_pod_failure_policy_on_exit_codes_requirement_t;

__attribute__((deprecated)) v1_pod_failure_policy_on_exit_codes_requirement_t *v1_pod_failure_policy_on_exit_codes_requirement_create(
    char *container_name,
    char *_operator,
    list_t *values
);

void v1_pod_failure_policy_on_exit_codes_requirement_free(v1_pod_failure_policy_on_exit_codes_requirement_t *v1_pod_failure_policy_on_exit_codes_requirement);

v1_pod_failure_policy_on_exit_codes_requirement_t *v1_pod_failure_policy_on_exit_codes_requirement_parseFromJSON(cJSON *v1_pod_failure_policy_on_exit_codes_requirementJSON);

cJSON *v1_pod_failure_policy_on_exit_codes_requirement_convertToJSON(v1_pod_failure_policy_on_exit_codes_requirement_t *v1_pod_failure_policy_on_exit_codes_requirement);

#endif /* _v1_pod_failure_policy_on_exit_codes_requirement_H_ */

