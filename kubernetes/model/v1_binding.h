/*
 * v1_binding.h
 *
 * Binding ties one object to another; for example, a pod is bound to a node by a scheduler. Deprecated in 1.7, please use the bindings subresource of pods instead.
 */

#ifndef _v1_binding_H_
#define _v1_binding_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_binding_t v1_binding_t;

#include "v1_object_meta.h"
#include "v1_object_reference.h"



typedef struct v1_binding_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1_object_reference_t *target; //model

} v1_binding_t;

v1_binding_t *v1_binding_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_object_reference_t *target
);

void v1_binding_free(v1_binding_t *v1_binding);

v1_binding_t *v1_binding_parseFromJSON(cJSON *v1_bindingJSON);

cJSON *v1_binding_convertToJSON(v1_binding_t *v1_binding);

#endif /* _v1_binding_H_ */

