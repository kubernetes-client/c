/*
 * v1beta1_custom_resource_definition_spec.h
 *
 * CustomResourceDefinitionSpec describes how a user wants their resource to appear
 */

#ifndef _v1beta1_custom_resource_definition_spec_H_
#define _v1beta1_custom_resource_definition_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_custom_resource_definition_spec_t v1beta1_custom_resource_definition_spec_t;

#include "v1beta1_custom_resource_column_definition.h"
#include "v1beta1_custom_resource_conversion.h"
#include "v1beta1_custom_resource_definition_names.h"
#include "v1beta1_custom_resource_definition_version.h"
#include "v1beta1_custom_resource_subresources.h"
#include "v1beta1_custom_resource_validation.h"



typedef struct v1beta1_custom_resource_definition_spec_t {
    list_t *additional_printer_columns; //nonprimitive container
    struct v1beta1_custom_resource_conversion_t *conversion; //model
    char *group; // string
    struct v1beta1_custom_resource_definition_names_t *names; //model
    int preserve_unknown_fields; //boolean
    char *scope; // string
    struct v1beta1_custom_resource_subresources_t *subresources; //model
    struct v1beta1_custom_resource_validation_t *validation; //model
    char *version; // string
    list_t *versions; //nonprimitive container

} v1beta1_custom_resource_definition_spec_t;

v1beta1_custom_resource_definition_spec_t *v1beta1_custom_resource_definition_spec_create(
    list_t *additional_printer_columns,
    v1beta1_custom_resource_conversion_t *conversion,
    char *group,
    v1beta1_custom_resource_definition_names_t *names,
    int preserve_unknown_fields,
    char *scope,
    v1beta1_custom_resource_subresources_t *subresources,
    v1beta1_custom_resource_validation_t *validation,
    char *version,
    list_t *versions
);

void v1beta1_custom_resource_definition_spec_free(v1beta1_custom_resource_definition_spec_t *v1beta1_custom_resource_definition_spec);

v1beta1_custom_resource_definition_spec_t *v1beta1_custom_resource_definition_spec_parseFromJSON(cJSON *v1beta1_custom_resource_definition_specJSON);

cJSON *v1beta1_custom_resource_definition_spec_convertToJSON(v1beta1_custom_resource_definition_spec_t *v1beta1_custom_resource_definition_spec);

#endif /* _v1beta1_custom_resource_definition_spec_H_ */

