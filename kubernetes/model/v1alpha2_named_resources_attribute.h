/*
 * v1alpha2_named_resources_attribute.h
 *
 * NamedResourcesAttribute is a combination of an attribute name and its value.
 */

#ifndef _v1alpha2_named_resources_attribute_H_
#define _v1alpha2_named_resources_attribute_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha2_named_resources_attribute_t v1alpha2_named_resources_attribute_t;

#include "v1alpha2_named_resources_int_slice.h"
#include "v1alpha2_named_resources_string_slice.h"



typedef struct v1alpha2_named_resources_attribute_t {
    int _bool; //boolean
    long _int; //numeric
    struct v1alpha2_named_resources_int_slice_t *int_slice; //model
    char *name; // string
    char *quantity; // string
    char *string; // string
    struct v1alpha2_named_resources_string_slice_t *string_slice; //model
    char *version; // string

} v1alpha2_named_resources_attribute_t;

v1alpha2_named_resources_attribute_t *v1alpha2_named_resources_attribute_create(
    int _bool,
    long _int,
    v1alpha2_named_resources_int_slice_t *int_slice,
    char *name,
    char *quantity,
    char *string,
    v1alpha2_named_resources_string_slice_t *string_slice,
    char *version
);

void v1alpha2_named_resources_attribute_free(v1alpha2_named_resources_attribute_t *v1alpha2_named_resources_attribute);

v1alpha2_named_resources_attribute_t *v1alpha2_named_resources_attribute_parseFromJSON(cJSON *v1alpha2_named_resources_attributeJSON);

cJSON *v1alpha2_named_resources_attribute_convertToJSON(v1alpha2_named_resources_attribute_t *v1alpha2_named_resources_attribute);

#endif /* _v1alpha2_named_resources_attribute_H_ */

