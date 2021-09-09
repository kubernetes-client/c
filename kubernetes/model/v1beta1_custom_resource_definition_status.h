/*
 * v1beta1_custom_resource_definition_status.h
 *
 * CustomResourceDefinitionStatus indicates the state of the CustomResourceDefinition
 */

#ifndef _v1beta1_custom_resource_definition_status_H_
#define _v1beta1_custom_resource_definition_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_custom_resource_definition_status_t v1beta1_custom_resource_definition_status_t;

#include "v1beta1_custom_resource_definition_condition.h"
#include "v1beta1_custom_resource_definition_names.h"



typedef struct v1beta1_custom_resource_definition_status_t {
    struct v1beta1_custom_resource_definition_names_t *accepted_names; //model
    list_t *conditions; //nonprimitive container
    list_t *stored_versions; //primitive container

} v1beta1_custom_resource_definition_status_t;

v1beta1_custom_resource_definition_status_t *v1beta1_custom_resource_definition_status_create(
    v1beta1_custom_resource_definition_names_t *accepted_names,
    list_t *conditions,
    list_t *stored_versions
);

void v1beta1_custom_resource_definition_status_free(v1beta1_custom_resource_definition_status_t *v1beta1_custom_resource_definition_status);

v1beta1_custom_resource_definition_status_t *v1beta1_custom_resource_definition_status_parseFromJSON(cJSON *v1beta1_custom_resource_definition_statusJSON);

cJSON *v1beta1_custom_resource_definition_status_convertToJSON(v1beta1_custom_resource_definition_status_t *v1beta1_custom_resource_definition_status);

#endif /* _v1beta1_custom_resource_definition_status_H_ */

