/*
 * v1alpha1_policy.h
 *
 * Policy defines the configuration of how audit events are logged
 */

#ifndef _v1alpha1_policy_H_
#define _v1alpha1_policy_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1alpha1_policy_t {
    char *level; // string
    list_t *stages; //primitive container

} v1alpha1_policy_t;

v1alpha1_policy_t *v1alpha1_policy_create(
    char *level,
    list_t *stages
);

void v1alpha1_policy_free(v1alpha1_policy_t *v1alpha1_policy);

v1alpha1_policy_t *v1alpha1_policy_parseFromJSON(cJSON *v1alpha1_policyJSON);

cJSON *v1alpha1_policy_convertToJSON(v1alpha1_policy_t *v1alpha1_policy);

#endif /* _v1alpha1_policy_H_ */

