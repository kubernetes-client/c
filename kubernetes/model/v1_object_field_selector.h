/*
 * v1_object_field_selector.h
 *
 * ObjectFieldSelector selects an APIVersioned field of an object.
 */

#ifndef _v1_object_field_selector_H_
#define _v1_object_field_selector_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_object_field_selector_t v1_object_field_selector_t;




typedef struct v1_object_field_selector_t {
    char *api_version; // string
    char *field_path; // string

} v1_object_field_selector_t;

v1_object_field_selector_t *v1_object_field_selector_create(
    char *api_version,
    char *field_path
);

void v1_object_field_selector_free(v1_object_field_selector_t *v1_object_field_selector);

v1_object_field_selector_t *v1_object_field_selector_parseFromJSON(cJSON *v1_object_field_selectorJSON);

cJSON *v1_object_field_selector_convertToJSON(v1_object_field_selector_t *v1_object_field_selector);

#endif /* _v1_object_field_selector_H_ */

