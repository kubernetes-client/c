/*
 * extensions_v1beta1_pod_security_policy_list.h
 *
 * PodSecurityPolicyList is a list of PodSecurityPolicy objects. Deprecated: use PodSecurityPolicyList from policy API Group instead.
 */

#ifndef _extensions_v1beta1_pod_security_policy_list_H_
#define _extensions_v1beta1_pod_security_policy_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct extensions_v1beta1_pod_security_policy_list_t extensions_v1beta1_pod_security_policy_list_t;

#include "extensions_v1beta1_pod_security_policy.h"
#include "v1_list_meta.h"



typedef struct extensions_v1beta1_pod_security_policy_list_t {
    char *api_version; // string
    list_t *items; //nonprimitive container
    char *kind; // string
    struct v1_list_meta_t *metadata; //model

} extensions_v1beta1_pod_security_policy_list_t;

extensions_v1beta1_pod_security_policy_list_t *extensions_v1beta1_pod_security_policy_list_create(
    char *api_version,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
);

void extensions_v1beta1_pod_security_policy_list_free(extensions_v1beta1_pod_security_policy_list_t *extensions_v1beta1_pod_security_policy_list);

extensions_v1beta1_pod_security_policy_list_t *extensions_v1beta1_pod_security_policy_list_parseFromJSON(cJSON *extensions_v1beta1_pod_security_policy_listJSON);

cJSON *extensions_v1beta1_pod_security_policy_list_convertToJSON(extensions_v1beta1_pod_security_policy_list_t *extensions_v1beta1_pod_security_policy_list);

#endif /* _extensions_v1beta1_pod_security_policy_list_H_ */

