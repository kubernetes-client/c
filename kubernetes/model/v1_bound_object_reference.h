/*
 * v1_bound_object_reference.h
 *
 * BoundObjectReference is a reference to an object that a token is bound to.
 */

#ifndef _v1_bound_object_reference_H_
#define _v1_bound_object_reference_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_bound_object_reference_t v1_bound_object_reference_t;




typedef struct v1_bound_object_reference_t {
    char *api_version; // string
    char *kind; // string
    char *name; // string
    char *uid; // string

} v1_bound_object_reference_t;

v1_bound_object_reference_t *v1_bound_object_reference_create(
    char *api_version,
    char *kind,
    char *name,
    char *uid
);

void v1_bound_object_reference_free(v1_bound_object_reference_t *v1_bound_object_reference);

v1_bound_object_reference_t *v1_bound_object_reference_parseFromJSON(cJSON *v1_bound_object_referenceJSON);

cJSON *v1_bound_object_reference_convertToJSON(v1_bound_object_reference_t *v1_bound_object_reference);

#endif /* _v1_bound_object_reference_H_ */

