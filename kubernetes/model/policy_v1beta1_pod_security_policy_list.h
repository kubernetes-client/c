/*
 * policy_v1beta1_pod_security_policy_list.h
 *
 * PodSecurityPolicyList is a list of PodSecurityPolicy objects.
 */

#ifndef _policy_v1beta1_pod_security_policy_list_H_
#define _policy_v1beta1_pod_security_policy_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct policy_v1beta1_pod_security_policy_list_t policy_v1beta1_pod_security_policy_list_t;

#include "policy_v1beta1_pod_security_policy.h"
#include "v1_list_meta.h"



typedef struct policy_v1beta1_pod_security_policy_list_t {
    char *api_version; // string
    list_t *items; //nonprimitive container
    char *kind; // string
    struct v1_list_meta_t *metadata; //model

} policy_v1beta1_pod_security_policy_list_t;

policy_v1beta1_pod_security_policy_list_t *policy_v1beta1_pod_security_policy_list_create(
    char *api_version,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
);

void policy_v1beta1_pod_security_policy_list_free(policy_v1beta1_pod_security_policy_list_t *policy_v1beta1_pod_security_policy_list);

policy_v1beta1_pod_security_policy_list_t *policy_v1beta1_pod_security_policy_list_parseFromJSON(cJSON *policy_v1beta1_pod_security_policy_listJSON);

cJSON *policy_v1beta1_pod_security_policy_list_convertToJSON(policy_v1beta1_pod_security_policy_list_t *policy_v1beta1_pod_security_policy_list);

#endif /* _policy_v1beta1_pod_security_policy_list_H_ */

