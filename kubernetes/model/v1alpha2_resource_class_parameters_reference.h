/*
 * v1alpha2_resource_class_parameters_reference.h
 *
 * ResourceClassParametersReference contains enough information to let you locate the parameters for a ResourceClass.
 */

#ifndef _v1alpha2_resource_class_parameters_reference_H_
#define _v1alpha2_resource_class_parameters_reference_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha2_resource_class_parameters_reference_t v1alpha2_resource_class_parameters_reference_t;




typedef struct v1alpha2_resource_class_parameters_reference_t {
    char *api_group; // string
    char *kind; // string
    char *name; // string
    char *_namespace; // string

} v1alpha2_resource_class_parameters_reference_t;

v1alpha2_resource_class_parameters_reference_t *v1alpha2_resource_class_parameters_reference_create(
    char *api_group,
    char *kind,
    char *name,
    char *_namespace
);

void v1alpha2_resource_class_parameters_reference_free(v1alpha2_resource_class_parameters_reference_t *v1alpha2_resource_class_parameters_reference);

v1alpha2_resource_class_parameters_reference_t *v1alpha2_resource_class_parameters_reference_parseFromJSON(cJSON *v1alpha2_resource_class_parameters_referenceJSON);

cJSON *v1alpha2_resource_class_parameters_reference_convertToJSON(v1alpha2_resource_class_parameters_reference_t *v1alpha2_resource_class_parameters_reference);

#endif /* _v1alpha2_resource_class_parameters_reference_H_ */

