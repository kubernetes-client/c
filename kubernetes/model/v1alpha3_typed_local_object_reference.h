/*
 * v1alpha3_typed_local_object_reference.h
 *
 * TypedLocalObjectReference allows to reference typed object inside the same namespace.
 */

#ifndef _v1alpha3_typed_local_object_reference_H_
#define _v1alpha3_typed_local_object_reference_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_typed_local_object_reference_t v1alpha3_typed_local_object_reference_t;




typedef struct v1alpha3_typed_local_object_reference_t {
    char *api_group; // string
    char *kind; // string
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha3_typed_local_object_reference_t;

__attribute__((deprecated)) v1alpha3_typed_local_object_reference_t *v1alpha3_typed_local_object_reference_create(
    char *api_group,
    char *kind,
    char *name
);

void v1alpha3_typed_local_object_reference_free(v1alpha3_typed_local_object_reference_t *v1alpha3_typed_local_object_reference);

v1alpha3_typed_local_object_reference_t *v1alpha3_typed_local_object_reference_parseFromJSON(cJSON *v1alpha3_typed_local_object_referenceJSON);

cJSON *v1alpha3_typed_local_object_reference_convertToJSON(v1alpha3_typed_local_object_reference_t *v1alpha3_typed_local_object_reference);

#endif /* _v1alpha3_typed_local_object_reference_H_ */

