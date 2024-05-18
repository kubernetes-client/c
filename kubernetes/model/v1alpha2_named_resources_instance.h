/*
 * v1alpha2_named_resources_instance.h
 *
 * NamedResourcesInstance represents one individual hardware instance that can be selected based on its attributes.
 */

#ifndef _v1alpha2_named_resources_instance_H_
#define _v1alpha2_named_resources_instance_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha2_named_resources_instance_t v1alpha2_named_resources_instance_t;

#include "v1alpha2_named_resources_attribute.h"



typedef struct v1alpha2_named_resources_instance_t {
    list_t *attributes; //nonprimitive container
    char *name; // string

} v1alpha2_named_resources_instance_t;

v1alpha2_named_resources_instance_t *v1alpha2_named_resources_instance_create(
    list_t *attributes,
    char *name
);

void v1alpha2_named_resources_instance_free(v1alpha2_named_resources_instance_t *v1alpha2_named_resources_instance);

v1alpha2_named_resources_instance_t *v1alpha2_named_resources_instance_parseFromJSON(cJSON *v1alpha2_named_resources_instanceJSON);

cJSON *v1alpha2_named_resources_instance_convertToJSON(v1alpha2_named_resources_instance_t *v1alpha2_named_resources_instance);

#endif /* _v1alpha2_named_resources_instance_H_ */

