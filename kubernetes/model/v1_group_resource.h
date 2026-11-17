/*
 * v1_group_resource.h
 *
 * GroupResource specifies a Group and a Resource, but does not force a version.  This is useful for identifying concepts during lookup stages without having partially valid types
 */

#ifndef _v1_group_resource_H_
#define _v1_group_resource_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_group_resource_t v1_group_resource_t;




typedef struct v1_group_resource_t {
    char *group; // string
    char *resource; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_group_resource_t;

__attribute__((deprecated)) v1_group_resource_t *v1_group_resource_create(
    char *group,
    char *resource
);

void v1_group_resource_free(v1_group_resource_t *v1_group_resource);

v1_group_resource_t *v1_group_resource_parseFromJSON(cJSON *v1_group_resourceJSON);

cJSON *v1_group_resource_convertToJSON(v1_group_resource_t *v1_group_resource);

#endif /* _v1_group_resource_H_ */

