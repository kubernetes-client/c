/*
 * v1_cluster_role.h
 *
 * ClusterRole is a cluster level, logical grouping of PolicyRules that can be referenced as a unit by a RoleBinding or ClusterRoleBinding.
 */

#ifndef _v1_cluster_role_H_
#define _v1_cluster_role_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_cluster_role_t v1_cluster_role_t;

#include "v1_aggregation_rule.h"
#include "v1_object_meta.h"
#include "v1_policy_rule.h"



typedef struct v1_cluster_role_t {
    struct v1_aggregation_rule_t *aggregation_rule; //model
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    list_t *rules; //nonprimitive container

} v1_cluster_role_t;

v1_cluster_role_t *v1_cluster_role_create(
    v1_aggregation_rule_t *aggregation_rule,
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    list_t *rules
);

void v1_cluster_role_free(v1_cluster_role_t *v1_cluster_role);

v1_cluster_role_t *v1_cluster_role_parseFromJSON(cJSON *v1_cluster_roleJSON);

cJSON *v1_cluster_role_convertToJSON(v1_cluster_role_t *v1_cluster_role);

#endif /* _v1_cluster_role_H_ */

