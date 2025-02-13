/*
 * v1_custom_resource_definition_version.h
 *
 * CustomResourceDefinitionVersion describes a version for CRD.
 */

#ifndef _v1_custom_resource_definition_version_H_
#define _v1_custom_resource_definition_version_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_custom_resource_definition_version_t v1_custom_resource_definition_version_t;

#include "v1_custom_resource_column_definition.h"
#include "v1_custom_resource_subresources.h"
#include "v1_custom_resource_validation.h"
#include "v1_selectable_field.h"



typedef struct v1_custom_resource_definition_version_t {
    list_t *additional_printer_columns; //nonprimitive container
    int deprecated; //boolean
    char *deprecation_warning; // string
    char *name; // string
    struct v1_custom_resource_validation_t *schema; //model
    list_t *selectable_fields; //nonprimitive container
    int served; //boolean
    int storage; //boolean
    struct v1_custom_resource_subresources_t *subresources; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1_custom_resource_definition_version_t;

__attribute__((deprecated)) v1_custom_resource_definition_version_t *v1_custom_resource_definition_version_create(
    list_t *additional_printer_columns,
    int deprecated,
    char *deprecation_warning,
    char *name,
    v1_custom_resource_validation_t *schema,
    list_t *selectable_fields,
    int served,
    int storage,
    v1_custom_resource_subresources_t *subresources
);

void v1_custom_resource_definition_version_free(v1_custom_resource_definition_version_t *v1_custom_resource_definition_version);

v1_custom_resource_definition_version_t *v1_custom_resource_definition_version_parseFromJSON(cJSON *v1_custom_resource_definition_versionJSON);

cJSON *v1_custom_resource_definition_version_convertToJSON(v1_custom_resource_definition_version_t *v1_custom_resource_definition_version);

#endif /* _v1_custom_resource_definition_version_H_ */

