/*
 * v1_typed_local_object_reference.h
 *
 * TypedLocalObjectReference contains enough information to let you locate the typed referenced object inside the same namespace.
 */

#ifndef _v1_typed_local_object_reference_H_
#define _v1_typed_local_object_reference_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_typed_local_object_reference_t v1_typed_local_object_reference_t;




typedef struct v1_typed_local_object_reference_t {
    char *api_group; // string
    char *kind; // string
    char *name; // string

} v1_typed_local_object_reference_t;

v1_typed_local_object_reference_t *v1_typed_local_object_reference_create(
    char *api_group,
    char *kind,
    char *name
);

void v1_typed_local_object_reference_free(v1_typed_local_object_reference_t *v1_typed_local_object_reference);

v1_typed_local_object_reference_t *v1_typed_local_object_reference_parseFromJSON(cJSON *v1_typed_local_object_referenceJSON);

cJSON *v1_typed_local_object_reference_convertToJSON(v1_typed_local_object_reference_t *v1_typed_local_object_reference);

#endif /* _v1_typed_local_object_reference_H_ */

