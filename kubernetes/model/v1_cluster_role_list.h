/*
 * v1_cluster_role_list.h
 *
 * ClusterRoleList is a collection of ClusterRoles
 */

#ifndef _v1_cluster_role_list_H_
#define _v1_cluster_role_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_cluster_role_list_t v1_cluster_role_list_t;

#include "v1_cluster_role.h"
#include "v1_list_meta.h"



typedef struct v1_cluster_role_list_t {
    char *api_version; // string
    list_t *items; //nonprimitive container
    char *kind; // string
    struct v1_list_meta_t *metadata; //model

} v1_cluster_role_list_t;

v1_cluster_role_list_t *v1_cluster_role_list_create(
    char *api_version,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
);

void v1_cluster_role_list_free(v1_cluster_role_list_t *v1_cluster_role_list);

v1_cluster_role_list_t *v1_cluster_role_list_parseFromJSON(cJSON *v1_cluster_role_listJSON);

cJSON *v1_cluster_role_list_convertToJSON(v1_cluster_role_list_t *v1_cluster_role_list);

#endif /* _v1_cluster_role_list_H_ */

