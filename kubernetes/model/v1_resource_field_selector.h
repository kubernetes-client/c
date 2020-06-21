/*
 * v1_resource_field_selector.h
 *
 * ResourceFieldSelector represents container resources (cpu, memory) and their output format
 */

#ifndef _v1_resource_field_selector_H_
#define _v1_resource_field_selector_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_resource_field_selector_t v1_resource_field_selector_t;




typedef struct v1_resource_field_selector_t {
    char *container_name; // string
    char *divisor; // string
    char *resource; // string

} v1_resource_field_selector_t;

v1_resource_field_selector_t *v1_resource_field_selector_create(
    char *container_name,
    char *divisor,
    char *resource
);

void v1_resource_field_selector_free(v1_resource_field_selector_t *v1_resource_field_selector);

v1_resource_field_selector_t *v1_resource_field_selector_parseFromJSON(cJSON *v1_resource_field_selectorJSON);

cJSON *v1_resource_field_selector_convertToJSON(v1_resource_field_selector_t *v1_resource_field_selector);

#endif /* _v1_resource_field_selector_H_ */

