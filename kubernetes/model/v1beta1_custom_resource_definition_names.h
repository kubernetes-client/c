/*
 * v1beta1_custom_resource_definition_names.h
 *
 * CustomResourceDefinitionNames indicates the names to serve this CustomResourceDefinition
 */

#ifndef _v1beta1_custom_resource_definition_names_H_
#define _v1beta1_custom_resource_definition_names_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_custom_resource_definition_names_t v1beta1_custom_resource_definition_names_t;




typedef struct v1beta1_custom_resource_definition_names_t {
    list_t *categories; //primitive container
    char *kind; // string
    char *list_kind; // string
    char *plural; // string
    list_t *short_names; //primitive container
    char *singular; // string

} v1beta1_custom_resource_definition_names_t;

v1beta1_custom_resource_definition_names_t *v1beta1_custom_resource_definition_names_create(
    list_t *categories,
    char *kind,
    char *list_kind,
    char *plural,
    list_t *short_names,
    char *singular
);

void v1beta1_custom_resource_definition_names_free(v1beta1_custom_resource_definition_names_t *v1beta1_custom_resource_definition_names);

v1beta1_custom_resource_definition_names_t *v1beta1_custom_resource_definition_names_parseFromJSON(cJSON *v1beta1_custom_resource_definition_namesJSON);

cJSON *v1beta1_custom_resource_definition_names_convertToJSON(v1beta1_custom_resource_definition_names_t *v1beta1_custom_resource_definition_names);

#endif /* _v1beta1_custom_resource_definition_names_H_ */

