/*
 * v1_network_policy_list.h
 *
 * NetworkPolicyList is a list of NetworkPolicy objects.
 */

#ifndef _v1_network_policy_list_H_
#define _v1_network_policy_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_network_policy_list_t v1_network_policy_list_t;

#include "v1_list_meta.h"
#include "v1_network_policy.h"



typedef struct v1_network_policy_list_t {
    char *api_version; // string
    list_t *items; //nonprimitive container
    char *kind; // string
    struct v1_list_meta_t *metadata; //model

} v1_network_policy_list_t;

v1_network_policy_list_t *v1_network_policy_list_create(
    char *api_version,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
);

void v1_network_policy_list_free(v1_network_policy_list_t *v1_network_policy_list);

v1_network_policy_list_t *v1_network_policy_list_parseFromJSON(cJSON *v1_network_policy_listJSON);

cJSON *v1_network_policy_list_convertToJSON(v1_network_policy_list_t *v1_network_policy_list);

#endif /* _v1_network_policy_list_H_ */

