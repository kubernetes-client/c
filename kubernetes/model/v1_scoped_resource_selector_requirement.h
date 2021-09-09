/*
 * v1_scoped_resource_selector_requirement.h
 *
 * A scoped-resource selector requirement is a selector that contains values, a scope name, and an operator that relates the scope name and values.
 */

#ifndef _v1_scoped_resource_selector_requirement_H_
#define _v1_scoped_resource_selector_requirement_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_scoped_resource_selector_requirement_t v1_scoped_resource_selector_requirement_t;




typedef struct v1_scoped_resource_selector_requirement_t {
    char *_operator; // string
    char *scope_name; // string
    list_t *values; //primitive container

} v1_scoped_resource_selector_requirement_t;

v1_scoped_resource_selector_requirement_t *v1_scoped_resource_selector_requirement_create(
    char *_operator,
    char *scope_name,
    list_t *values
);

void v1_scoped_resource_selector_requirement_free(v1_scoped_resource_selector_requirement_t *v1_scoped_resource_selector_requirement);

v1_scoped_resource_selector_requirement_t *v1_scoped_resource_selector_requirement_parseFromJSON(cJSON *v1_scoped_resource_selector_requirementJSON);

cJSON *v1_scoped_resource_selector_requirement_convertToJSON(v1_scoped_resource_selector_requirement_t *v1_scoped_resource_selector_requirement);

#endif /* _v1_scoped_resource_selector_requirement_H_ */

