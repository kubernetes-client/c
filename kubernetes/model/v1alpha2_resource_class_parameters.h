/*
 * v1alpha2_resource_class_parameters.h
 *
 * ResourceClassParameters defines resource requests for a ResourceClass in an in-tree format understood by Kubernetes.
 */

#ifndef _v1alpha2_resource_class_parameters_H_
#define _v1alpha2_resource_class_parameters_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha2_resource_class_parameters_t v1alpha2_resource_class_parameters_t;

#include "v1_object_meta.h"
#include "v1alpha2_resource_class_parameters_reference.h"
#include "v1alpha2_resource_filter.h"
#include "v1alpha2_vendor_parameters.h"



typedef struct v1alpha2_resource_class_parameters_t {
    char *api_version; // string
    list_t *filters; //nonprimitive container
    struct v1alpha2_resource_class_parameters_reference_t *generated_from; //model
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    list_t *vendor_parameters; //nonprimitive container

} v1alpha2_resource_class_parameters_t;

v1alpha2_resource_class_parameters_t *v1alpha2_resource_class_parameters_create(
    char *api_version,
    list_t *filters,
    v1alpha2_resource_class_parameters_reference_t *generated_from,
    char *kind,
    v1_object_meta_t *metadata,
    list_t *vendor_parameters
);

void v1alpha2_resource_class_parameters_free(v1alpha2_resource_class_parameters_t *v1alpha2_resource_class_parameters);

v1alpha2_resource_class_parameters_t *v1alpha2_resource_class_parameters_parseFromJSON(cJSON *v1alpha2_resource_class_parametersJSON);

cJSON *v1alpha2_resource_class_parameters_convertToJSON(v1alpha2_resource_class_parameters_t *v1alpha2_resource_class_parameters);

#endif /* _v1alpha2_resource_class_parameters_H_ */

