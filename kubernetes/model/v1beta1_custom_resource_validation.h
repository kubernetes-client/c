/*
 * v1beta1_custom_resource_validation.h
 *
 * CustomResourceValidation is a list of validation methods for CustomResources.
 */

#ifndef _v1beta1_custom_resource_validation_H_
#define _v1beta1_custom_resource_validation_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_custom_resource_validation_t v1beta1_custom_resource_validation_t;

#include "v1beta1_json_schema_props.h"



typedef struct v1beta1_custom_resource_validation_t {
    struct v1beta1_json_schema_props_t *open_apiv3_schema; //model

} v1beta1_custom_resource_validation_t;

v1beta1_custom_resource_validation_t *v1beta1_custom_resource_validation_create(
    v1beta1_json_schema_props_t *open_apiv3_schema
);

void v1beta1_custom_resource_validation_free(v1beta1_custom_resource_validation_t *v1beta1_custom_resource_validation);

v1beta1_custom_resource_validation_t *v1beta1_custom_resource_validation_parseFromJSON(cJSON *v1beta1_custom_resource_validationJSON);

cJSON *v1beta1_custom_resource_validation_convertToJSON(v1beta1_custom_resource_validation_t *v1beta1_custom_resource_validation);

#endif /* _v1beta1_custom_resource_validation_H_ */

