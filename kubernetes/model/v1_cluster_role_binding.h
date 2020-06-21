/*
 * v1_cluster_role_binding.h
 *
 * ClusterRoleBinding references a ClusterRole, but not contain it.  It can reference a ClusterRole in the global namespace, and adds who information via Subject.
 */

#ifndef _v1_cluster_role_binding_H_
#define _v1_cluster_role_binding_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_cluster_role_binding_t v1_cluster_role_binding_t;

#include "v1_object_meta.h"
#include "v1_role_ref.h"
#include "v1_subject.h"



typedef struct v1_cluster_role_binding_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1_role_ref_t *role_ref; //model
    list_t *subjects; //nonprimitive container

} v1_cluster_role_binding_t;

v1_cluster_role_binding_t *v1_cluster_role_binding_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_role_ref_t *role_ref,
    list_t *subjects
);

void v1_cluster_role_binding_free(v1_cluster_role_binding_t *v1_cluster_role_binding);

v1_cluster_role_binding_t *v1_cluster_role_binding_parseFromJSON(cJSON *v1_cluster_role_bindingJSON);

cJSON *v1_cluster_role_binding_convertToJSON(v1_cluster_role_binding_t *v1_cluster_role_binding);

#endif /* _v1_cluster_role_binding_H_ */

