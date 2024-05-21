/*
 * v1alpha1_group_version_resource.h
 *
 * The names of the group, the version, and the resource.
 */

#ifndef _v1alpha1_group_version_resource_H_
#define _v1alpha1_group_version_resource_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_group_version_resource_t v1alpha1_group_version_resource_t;




typedef struct v1alpha1_group_version_resource_t {
    char *group; // string
    char *resource; // string
    char *version; // string

} v1alpha1_group_version_resource_t;

v1alpha1_group_version_resource_t *v1alpha1_group_version_resource_create(
    char *group,
    char *resource,
    char *version
);

void v1alpha1_group_version_resource_free(v1alpha1_group_version_resource_t *v1alpha1_group_version_resource);

v1alpha1_group_version_resource_t *v1alpha1_group_version_resource_parseFromJSON(cJSON *v1alpha1_group_version_resourceJSON);

cJSON *v1alpha1_group_version_resource_convertToJSON(v1alpha1_group_version_resource_t *v1alpha1_group_version_resource);

#endif /* _v1alpha1_group_version_resource_H_ */

