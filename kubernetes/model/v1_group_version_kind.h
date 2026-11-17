/*
 * v1_group_version_kind.h
 *
 * GroupVersionKind unambiguously identifies a kind.
 */

#ifndef _v1_group_version_kind_H_
#define _v1_group_version_kind_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_group_version_kind_t v1_group_version_kind_t;




typedef struct v1_group_version_kind_t {
    char *group; // string
    char *version; // string
    char *kind; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_group_version_kind_t;

__attribute__((deprecated)) v1_group_version_kind_t *v1_group_version_kind_create(
    char *group,
    char *version,
    char *kind
);

void v1_group_version_kind_free(v1_group_version_kind_t *v1_group_version_kind);

v1_group_version_kind_t *v1_group_version_kind_parseFromJSON(cJSON *v1_group_version_kindJSON);

cJSON *v1_group_version_kind_convertToJSON(v1_group_version_kind_t *v1_group_version_kind);

#endif /* _v1_group_version_kind_H_ */

