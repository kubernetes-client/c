/*
 * v1beta1_custom_resource_column_definition.h
 *
 * CustomResourceColumnDefinition specifies a column for server side printing.
 */

#ifndef _v1beta1_custom_resource_column_definition_H_
#define _v1beta1_custom_resource_column_definition_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_custom_resource_column_definition_t v1beta1_custom_resource_column_definition_t;




typedef struct v1beta1_custom_resource_column_definition_t {
    char *json_path; // string
    char *description; // string
    char *format; // string
    char *name; // string
    int priority; //numeric
    char *type; // string

} v1beta1_custom_resource_column_definition_t;

v1beta1_custom_resource_column_definition_t *v1beta1_custom_resource_column_definition_create(
    char *json_path,
    char *description,
    char *format,
    char *name,
    int priority,
    char *type
);

void v1beta1_custom_resource_column_definition_free(v1beta1_custom_resource_column_definition_t *v1beta1_custom_resource_column_definition);

v1beta1_custom_resource_column_definition_t *v1beta1_custom_resource_column_definition_parseFromJSON(cJSON *v1beta1_custom_resource_column_definitionJSON);

cJSON *v1beta1_custom_resource_column_definition_convertToJSON(v1beta1_custom_resource_column_definition_t *v1beta1_custom_resource_column_definition);

#endif /* _v1beta1_custom_resource_column_definition_H_ */

