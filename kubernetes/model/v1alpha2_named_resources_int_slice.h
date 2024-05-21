/*
 * v1alpha2_named_resources_int_slice.h
 *
 * NamedResourcesIntSlice contains a slice of 64-bit integers.
 */

#ifndef _v1alpha2_named_resources_int_slice_H_
#define _v1alpha2_named_resources_int_slice_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha2_named_resources_int_slice_t v1alpha2_named_resources_int_slice_t;




typedef struct v1alpha2_named_resources_int_slice_t {
    list_t *ints; //primitive container

} v1alpha2_named_resources_int_slice_t;

v1alpha2_named_resources_int_slice_t *v1alpha2_named_resources_int_slice_create(
    list_t *ints
);

void v1alpha2_named_resources_int_slice_free(v1alpha2_named_resources_int_slice_t *v1alpha2_named_resources_int_slice);

v1alpha2_named_resources_int_slice_t *v1alpha2_named_resources_int_slice_parseFromJSON(cJSON *v1alpha2_named_resources_int_sliceJSON);

cJSON *v1alpha2_named_resources_int_slice_convertToJSON(v1alpha2_named_resources_int_slice_t *v1alpha2_named_resources_int_slice);

#endif /* _v1alpha2_named_resources_int_slice_H_ */

