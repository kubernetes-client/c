/*
 * v2_cross_version_object_reference.h
 *
 * CrossVersionObjectReference contains enough information to let you identify the referred resource.
 */

#ifndef _v2_cross_version_object_reference_H_
#define _v2_cross_version_object_reference_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v2_cross_version_object_reference_t v2_cross_version_object_reference_t;




typedef struct v2_cross_version_object_reference_t {
    char *api_version; // string
    char *kind; // string
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v2_cross_version_object_reference_t;

__attribute__((deprecated)) v2_cross_version_object_reference_t *v2_cross_version_object_reference_create(
    char *api_version,
    char *kind,
    char *name
);

void v2_cross_version_object_reference_free(v2_cross_version_object_reference_t *v2_cross_version_object_reference);

v2_cross_version_object_reference_t *v2_cross_version_object_reference_parseFromJSON(cJSON *v2_cross_version_object_referenceJSON);

cJSON *v2_cross_version_object_reference_convertToJSON(v2_cross_version_object_reference_t *v2_cross_version_object_reference);

#endif /* _v2_cross_version_object_reference_H_ */

