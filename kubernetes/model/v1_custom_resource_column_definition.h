/*
 * v1_custom_resource_column_definition.h
 *
 * CustomResourceColumnDefinition specifies a column for server side printing.
 */

#ifndef _v1_custom_resource_column_definition_H_
#define _v1_custom_resource_column_definition_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_custom_resource_column_definition_t v1_custom_resource_column_definition_t;




typedef struct v1_custom_resource_column_definition_t {
    char *description; // string
    char *format; // string
    char *json_path; // string
    char *name; // string
    int priority; //numeric
    char *type; // string

} v1_custom_resource_column_definition_t;

v1_custom_resource_column_definition_t *v1_custom_resource_column_definition_create(
    char *description,
    char *format,
    char *json_path,
    char *name,
    int priority,
    char *type
);

void v1_custom_resource_column_definition_free(v1_custom_resource_column_definition_t *v1_custom_resource_column_definition);

v1_custom_resource_column_definition_t *v1_custom_resource_column_definition_parseFromJSON(cJSON *v1_custom_resource_column_definitionJSON);

cJSON *v1_custom_resource_column_definition_convertToJSON(v1_custom_resource_column_definition_t *v1_custom_resource_column_definition);

#endif /* _v1_custom_resource_column_definition_H_ */

