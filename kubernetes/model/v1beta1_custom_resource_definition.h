/*
 * v1beta1_custom_resource_definition.h
 *
 * CustomResourceDefinition represents a resource that should be exposed on the API server.  Its name MUST be in the format &lt;.spec.name&gt;.&lt;.spec.group&gt;. Deprecated in v1.16, planned for removal in v1.19. Use apiextensions.k8s.io/v1 CustomResourceDefinition instead.
 */

#ifndef _v1beta1_custom_resource_definition_H_
#define _v1beta1_custom_resource_definition_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_custom_resource_definition_t v1beta1_custom_resource_definition_t;

#include "v1_object_meta.h"
#include "v1beta1_custom_resource_definition_spec.h"
#include "v1beta1_custom_resource_definition_status.h"



typedef struct v1beta1_custom_resource_definition_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1beta1_custom_resource_definition_spec_t *spec; //model
    struct v1beta1_custom_resource_definition_status_t *status; //model

} v1beta1_custom_resource_definition_t;

v1beta1_custom_resource_definition_t *v1beta1_custom_resource_definition_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta1_custom_resource_definition_spec_t *spec,
    v1beta1_custom_resource_definition_status_t *status
);

void v1beta1_custom_resource_definition_free(v1beta1_custom_resource_definition_t *v1beta1_custom_resource_definition);

v1beta1_custom_resource_definition_t *v1beta1_custom_resource_definition_parseFromJSON(cJSON *v1beta1_custom_resource_definitionJSON);

cJSON *v1beta1_custom_resource_definition_convertToJSON(v1beta1_custom_resource_definition_t *v1beta1_custom_resource_definition);

#endif /* _v1beta1_custom_resource_definition_H_ */

