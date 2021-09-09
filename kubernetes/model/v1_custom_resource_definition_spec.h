/*
 * v1_custom_resource_definition_spec.h
 *
 * CustomResourceDefinitionSpec describes how a user wants their resource to appear
 */

#ifndef _v1_custom_resource_definition_spec_H_
#define _v1_custom_resource_definition_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_custom_resource_definition_spec_t v1_custom_resource_definition_spec_t;

#include "v1_custom_resource_conversion.h"
#include "v1_custom_resource_definition_names.h"
#include "v1_custom_resource_definition_version.h"



typedef struct v1_custom_resource_definition_spec_t {
    struct v1_custom_resource_conversion_t *conversion; //model
    char *group; // string
    struct v1_custom_resource_definition_names_t *names; //model
    int preserve_unknown_fields; //boolean
    char *scope; // string
    list_t *versions; //nonprimitive container

} v1_custom_resource_definition_spec_t;

v1_custom_resource_definition_spec_t *v1_custom_resource_definition_spec_create(
    v1_custom_resource_conversion_t *conversion,
    char *group,
    v1_custom_resource_definition_names_t *names,
    int preserve_unknown_fields,
    char *scope,
    list_t *versions
);

void v1_custom_resource_definition_spec_free(v1_custom_resource_definition_spec_t *v1_custom_resource_definition_spec);

v1_custom_resource_definition_spec_t *v1_custom_resource_definition_spec_parseFromJSON(cJSON *v1_custom_resource_definition_specJSON);

cJSON *v1_custom_resource_definition_spec_convertToJSON(v1_custom_resource_definition_spec_t *v1_custom_resource_definition_spec);

#endif /* _v1_custom_resource_definition_spec_H_ */

