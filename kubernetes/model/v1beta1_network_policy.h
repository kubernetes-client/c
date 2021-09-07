/*
 * v1beta1_network_policy.h
 *
 * DEPRECATED 1.9 - This group version of NetworkPolicy is deprecated by networking/v1/NetworkPolicy. NetworkPolicy describes what network traffic is allowed for a set of Pods
 */

#ifndef _v1beta1_network_policy_H_
#define _v1beta1_network_policy_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_network_policy_t v1beta1_network_policy_t;

#include "v1_object_meta.h"
#include "v1beta1_network_policy_spec.h"



typedef struct v1beta1_network_policy_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1beta1_network_policy_spec_t *spec; //model

} v1beta1_network_policy_t;

v1beta1_network_policy_t *v1beta1_network_policy_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta1_network_policy_spec_t *spec
);

void v1beta1_network_policy_free(v1beta1_network_policy_t *v1beta1_network_policy);

v1beta1_network_policy_t *v1beta1_network_policy_parseFromJSON(cJSON *v1beta1_network_policyJSON);

cJSON *v1beta1_network_policy_convertToJSON(v1beta1_network_policy_t *v1beta1_network_policy);

#endif /* _v1beta1_network_policy_H_ */

