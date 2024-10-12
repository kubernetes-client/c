/*
 * v1alpha3_resource_slice_spec.h
 *
 * ResourceSliceSpec contains the information published by the driver in one ResourceSlice.
 */

#ifndef _v1alpha3_resource_slice_spec_H_
#define _v1alpha3_resource_slice_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_resource_slice_spec_t v1alpha3_resource_slice_spec_t;

#include "v1_node_selector.h"
#include "v1alpha3_device.h"
#include "v1alpha3_resource_pool.h"



typedef struct v1alpha3_resource_slice_spec_t {
    int all_nodes; //boolean
    list_t *devices; //nonprimitive container
    char *driver; // string
    char *node_name; // string
    struct v1_node_selector_t *node_selector; //model
    struct v1alpha3_resource_pool_t *pool; //model

} v1alpha3_resource_slice_spec_t;

v1alpha3_resource_slice_spec_t *v1alpha3_resource_slice_spec_create(
    int all_nodes,
    list_t *devices,
    char *driver,
    char *node_name,
    v1_node_selector_t *node_selector,
    v1alpha3_resource_pool_t *pool
);

void v1alpha3_resource_slice_spec_free(v1alpha3_resource_slice_spec_t *v1alpha3_resource_slice_spec);

v1alpha3_resource_slice_spec_t *v1alpha3_resource_slice_spec_parseFromJSON(cJSON *v1alpha3_resource_slice_specJSON);

cJSON *v1alpha3_resource_slice_spec_convertToJSON(v1alpha3_resource_slice_spec_t *v1alpha3_resource_slice_spec);

#endif /* _v1alpha3_resource_slice_spec_H_ */

