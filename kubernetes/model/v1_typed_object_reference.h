/*
 * v1_typed_object_reference.h
 *
 * 
 */

#ifndef _v1_typed_object_reference_H_
#define _v1_typed_object_reference_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_typed_object_reference_t v1_typed_object_reference_t;




typedef struct v1_typed_object_reference_t {
    char *api_group; // string
    char *kind; // string
    char *name; // string
    char *_namespace; // string

} v1_typed_object_reference_t;

v1_typed_object_reference_t *v1_typed_object_reference_create(
    char *api_group,
    char *kind,
    char *name,
    char *_namespace
);

void v1_typed_object_reference_free(v1_typed_object_reference_t *v1_typed_object_reference);

v1_typed_object_reference_t *v1_typed_object_reference_parseFromJSON(cJSON *v1_typed_object_referenceJSON);

cJSON *v1_typed_object_reference_convertToJSON(v1_typed_object_reference_t *v1_typed_object_reference);

#endif /* _v1_typed_object_reference_H_ */

