/*
 * v1alpha2_resource_slice.h
 *
 * ResourceSlice provides information about available resources on individual nodes.
 */

#ifndef _v1alpha2_resource_slice_H_
#define _v1alpha2_resource_slice_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha2_resource_slice_t v1alpha2_resource_slice_t;

#include "v1_object_meta.h"
#include "v1alpha2_named_resources_resources.h"



typedef struct v1alpha2_resource_slice_t {
    char *api_version; // string
    char *driver_name; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1alpha2_named_resources_resources_t *named_resources; //model
    char *node_name; // string

} v1alpha2_resource_slice_t;

v1alpha2_resource_slice_t *v1alpha2_resource_slice_create(
    char *api_version,
    char *driver_name,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha2_named_resources_resources_t *named_resources,
    char *node_name
);

void v1alpha2_resource_slice_free(v1alpha2_resource_slice_t *v1alpha2_resource_slice);

v1alpha2_resource_slice_t *v1alpha2_resource_slice_parseFromJSON(cJSON *v1alpha2_resource_sliceJSON);

cJSON *v1alpha2_resource_slice_convertToJSON(v1alpha2_resource_slice_t *v1alpha2_resource_slice);

#endif /* _v1alpha2_resource_slice_H_ */

