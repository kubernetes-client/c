/*
 * v1alpha2_named_resources_string_slice.h
 *
 * NamedResourcesStringSlice contains a slice of strings.
 */

#ifndef _v1alpha2_named_resources_string_slice_H_
#define _v1alpha2_named_resources_string_slice_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha2_named_resources_string_slice_t v1alpha2_named_resources_string_slice_t;




typedef struct v1alpha2_named_resources_string_slice_t {
    list_t *strings; //primitive container

} v1alpha2_named_resources_string_slice_t;

v1alpha2_named_resources_string_slice_t *v1alpha2_named_resources_string_slice_create(
    list_t *strings
);

void v1alpha2_named_resources_string_slice_free(v1alpha2_named_resources_string_slice_t *v1alpha2_named_resources_string_slice);

v1alpha2_named_resources_string_slice_t *v1alpha2_named_resources_string_slice_parseFromJSON(cJSON *v1alpha2_named_resources_string_sliceJSON);

cJSON *v1alpha2_named_resources_string_slice_convertToJSON(v1alpha2_named_resources_string_slice_t *v1alpha2_named_resources_string_slice);

#endif /* _v1alpha2_named_resources_string_slice_H_ */

