/*
 * v1_local_object_reference.h
 *
 * LocalObjectReference contains enough information to let you locate the referenced object inside the same namespace.
 */

#ifndef _v1_local_object_reference_H_
#define _v1_local_object_reference_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"



typedef struct v1_local_object_reference_t {
    char *name; // string

} v1_local_object_reference_t;

v1_local_object_reference_t *v1_local_object_reference_create(
    char *name
);

void v1_local_object_reference_free(v1_local_object_reference_t *v1_local_object_reference);

v1_local_object_reference_t *v1_local_object_reference_parseFromJSON(cJSON *v1_local_object_referenceJSON);

cJSON *v1_local_object_reference_convertToJSON(v1_local_object_reference_t *v1_local_object_reference);

#endif /* _v1_local_object_reference_H_ */

