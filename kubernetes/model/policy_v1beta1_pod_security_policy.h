/*
 * policy_v1beta1_pod_security_policy.h
 *
 * PodSecurityPolicy governs the ability to make requests that affect the Security Context that will be applied to a pod and container.
 */

#ifndef _policy_v1beta1_pod_security_policy_H_
#define _policy_v1beta1_pod_security_policy_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct policy_v1beta1_pod_security_policy_t policy_v1beta1_pod_security_policy_t;

#include "policy_v1beta1_pod_security_policy_spec.h"
#include "v1_object_meta.h"



typedef struct policy_v1beta1_pod_security_policy_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct policy_v1beta1_pod_security_policy_spec_t *spec; //model

} policy_v1beta1_pod_security_policy_t;

policy_v1beta1_pod_security_policy_t *policy_v1beta1_pod_security_policy_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    policy_v1beta1_pod_security_policy_spec_t *spec
);

void policy_v1beta1_pod_security_policy_free(policy_v1beta1_pod_security_policy_t *policy_v1beta1_pod_security_policy);

policy_v1beta1_pod_security_policy_t *policy_v1beta1_pod_security_policy_parseFromJSON(cJSON *policy_v1beta1_pod_security_policyJSON);

cJSON *policy_v1beta1_pod_security_policy_convertToJSON(policy_v1beta1_pod_security_policy_t *policy_v1beta1_pod_security_policy);

#endif /* _policy_v1beta1_pod_security_policy_H_ */

