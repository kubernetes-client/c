/*
 * v1alpha2_named_resources_resources.h
 *
 * NamedResourcesResources is used in ResourceModel.
 */

#ifndef _v1alpha2_named_resources_resources_H_
#define _v1alpha2_named_resources_resources_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha2_named_resources_resources_t v1alpha2_named_resources_resources_t;

#include "v1alpha2_named_resources_instance.h"



typedef struct v1alpha2_named_resources_resources_t {
    list_t *instances; //nonprimitive container

} v1alpha2_named_resources_resources_t;

v1alpha2_named_resources_resources_t *v1alpha2_named_resources_resources_create(
    list_t *instances
);

void v1alpha2_named_resources_resources_free(v1alpha2_named_resources_resources_t *v1alpha2_named_resources_resources);

v1alpha2_named_resources_resources_t *v1alpha2_named_resources_resources_parseFromJSON(cJSON *v1alpha2_named_resources_resourcesJSON);

cJSON *v1alpha2_named_resources_resources_convertToJSON(v1alpha2_named_resources_resources_t *v1alpha2_named_resources_resources);

#endif /* _v1alpha2_named_resources_resources_H_ */

