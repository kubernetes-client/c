/*
 * v1beta1_role_list.h
 *
 * RoleList is a collection of Roles Deprecated in v1.17 in favor of rbac.authorization.k8s.io/v1 RoleList, and will no longer be served in v1.20.
 */

#ifndef _v1beta1_role_list_H_
#define _v1beta1_role_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_role_list_t v1beta1_role_list_t;

#include "v1_list_meta.h"
#include "v1beta1_role.h"



typedef struct v1beta1_role_list_t {
    char *api_version; // string
    list_t *items; //nonprimitive container
    char *kind; // string
    struct v1_list_meta_t *metadata; //model

} v1beta1_role_list_t;

v1beta1_role_list_t *v1beta1_role_list_create(
    char *api_version,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
);

void v1beta1_role_list_free(v1beta1_role_list_t *v1beta1_role_list);

v1beta1_role_list_t *v1beta1_role_list_parseFromJSON(cJSON *v1beta1_role_listJSON);

cJSON *v1beta1_role_list_convertToJSON(v1beta1_role_list_t *v1beta1_role_list);

#endif /* _v1beta1_role_list_H_ */

