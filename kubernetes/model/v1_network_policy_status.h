/*
 * v1_network_policy_status.h
 *
 * NetworkPolicyStatus describe the current state of the NetworkPolicy.
 */

#ifndef _v1_network_policy_status_H_
#define _v1_network_policy_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_network_policy_status_t v1_network_policy_status_t;

#include "v1_condition.h"



typedef struct v1_network_policy_status_t {
    list_t *conditions; //nonprimitive container

} v1_network_policy_status_t;

v1_network_policy_status_t *v1_network_policy_status_create(
    list_t *conditions
);

void v1_network_policy_status_free(v1_network_policy_status_t *v1_network_policy_status);

v1_network_policy_status_t *v1_network_policy_status_parseFromJSON(cJSON *v1_network_policy_statusJSON);

cJSON *v1_network_policy_status_convertToJSON(v1_network_policy_status_t *v1_network_policy_status);

#endif /* _v1_network_policy_status_H_ */

