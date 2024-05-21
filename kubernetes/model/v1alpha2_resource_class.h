/*
 * v1alpha2_resource_class.h
 *
 * ResourceClass is used by administrators to influence how resources are allocated.  This is an alpha type and requires enabling the DynamicResourceAllocation feature gate.
 */

#ifndef _v1alpha2_resource_class_H_
#define _v1alpha2_resource_class_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha2_resource_class_t v1alpha2_resource_class_t;

#include "v1_node_selector.h"
#include "v1_object_meta.h"
#include "v1alpha2_resource_class_parameters_reference.h"



typedef struct v1alpha2_resource_class_t {
    char *api_version; // string
    char *driver_name; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1alpha2_resource_class_parameters_reference_t *parameters_ref; //model
    int structured_parameters; //boolean
    struct v1_node_selector_t *suitable_nodes; //model

} v1alpha2_resource_class_t;

v1alpha2_resource_class_t *v1alpha2_resource_class_create(
    char *api_version,
    char *driver_name,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha2_resource_class_parameters_reference_t *parameters_ref,
    int structured_parameters,
    v1_node_selector_t *suitable_nodes
);

void v1alpha2_resource_class_free(v1alpha2_resource_class_t *v1alpha2_resource_class);

v1alpha2_resource_class_t *v1alpha2_resource_class_parseFromJSON(cJSON *v1alpha2_resource_classJSON);

cJSON *v1alpha2_resource_class_convertToJSON(v1alpha2_resource_class_t *v1alpha2_resource_class);

#endif /* _v1alpha2_resource_class_H_ */

