/*
 * v1_cross_version_object_reference.h
 *
 * CrossVersionObjectReference contains enough information to let you identify the referred resource.
 */

#ifndef _v1_cross_version_object_reference_H_
#define _v1_cross_version_object_reference_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_cross_version_object_reference_t v1_cross_version_object_reference_t;




typedef struct v1_cross_version_object_reference_t {
    char *api_version; // string
    char *kind; // string
    char *name; // string

} v1_cross_version_object_reference_t;

v1_cross_version_object_reference_t *v1_cross_version_object_reference_create(
    char *api_version,
    char *kind,
    char *name
);

void v1_cross_version_object_reference_free(v1_cross_version_object_reference_t *v1_cross_version_object_reference);

v1_cross_version_object_reference_t *v1_cross_version_object_reference_parseFromJSON(cJSON *v1_cross_version_object_referenceJSON);

cJSON *v1_cross_version_object_reference_convertToJSON(v1_cross_version_object_reference_t *v1_cross_version_object_reference);

#endif /* _v1_cross_version_object_reference_H_ */

