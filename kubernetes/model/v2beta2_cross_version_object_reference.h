/*
 * v2beta2_cross_version_object_reference.h
 *
 * CrossVersionObjectReference contains enough information to let you identify the referred resource.
 */

#ifndef _v2beta2_cross_version_object_reference_H_
#define _v2beta2_cross_version_object_reference_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v2beta2_cross_version_object_reference_t v2beta2_cross_version_object_reference_t;




typedef struct v2beta2_cross_version_object_reference_t {
    char *api_version; // string
    char *kind; // string
    char *name; // string

} v2beta2_cross_version_object_reference_t;

v2beta2_cross_version_object_reference_t *v2beta2_cross_version_object_reference_create(
    char *api_version,
    char *kind,
    char *name
);

void v2beta2_cross_version_object_reference_free(v2beta2_cross_version_object_reference_t *v2beta2_cross_version_object_reference);

v2beta2_cross_version_object_reference_t *v2beta2_cross_version_object_reference_parseFromJSON(cJSON *v2beta2_cross_version_object_referenceJSON);

cJSON *v2beta2_cross_version_object_reference_convertToJSON(v2beta2_cross_version_object_reference_t *v2beta2_cross_version_object_reference);

#endif /* _v2beta2_cross_version_object_reference_H_ */

