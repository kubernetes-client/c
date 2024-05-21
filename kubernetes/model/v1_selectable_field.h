/*
 * v1_selectable_field.h
 *
 * SelectableField specifies the JSON path of a field that may be used with field selectors.
 */

#ifndef _v1_selectable_field_H_
#define _v1_selectable_field_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_selectable_field_t v1_selectable_field_t;




typedef struct v1_selectable_field_t {
    char *json_path; // string

} v1_selectable_field_t;

v1_selectable_field_t *v1_selectable_field_create(
    char *json_path
);

void v1_selectable_field_free(v1_selectable_field_t *v1_selectable_field);

v1_selectable_field_t *v1_selectable_field_parseFromJSON(cJSON *v1_selectable_fieldJSON);

cJSON *v1_selectable_field_convertToJSON(v1_selectable_field_t *v1_selectable_field);

#endif /* _v1_selectable_field_H_ */

