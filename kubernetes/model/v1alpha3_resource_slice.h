/*
 * v1alpha3_resource_slice.h
 *
 * ResourceSlice represents one or more resources in a pool of similar resources, managed by a common driver. A pool may span more than one ResourceSlice, and exactly how many ResourceSlices comprise a pool is determined by the driver.  At the moment, the only supported resources are devices with attributes and capacities. Each device in a given pool, regardless of how many ResourceSlices, must have a unique name. The ResourceSlice in which a device gets published may change over time. The unique identifier for a device is the tuple &lt;driver name&gt;, &lt;pool name&gt;, &lt;device name&gt;.  Whenever a driver needs to update a pool, it increments the pool.Spec.Pool.Generation number and updates all ResourceSlices with that new number and new resource definitions. A consumer must only use ResourceSlices with the highest generation number and ignore all others.  When allocating all resources in a pool matching certain criteria or when looking for the best solution among several different alternatives, a consumer should check the number of ResourceSlices in a pool (included in each ResourceSlice) to determine whether its view of a pool is complete and if not, should wait until the driver has completed updating the pool.  For resources that are not local to a node, the node name is not set. Instead, the driver may use a node selector to specify where the devices are available.  This is an alpha type and requires enabling the DynamicResourceAllocation feature gate.
 */

#ifndef _v1alpha3_resource_slice_H_
#define _v1alpha3_resource_slice_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_resource_slice_t v1alpha3_resource_slice_t;

#include "v1_object_meta.h"
#include "v1alpha3_resource_slice_spec.h"



typedef struct v1alpha3_resource_slice_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1alpha3_resource_slice_spec_t *spec; //model

} v1alpha3_resource_slice_t;

v1alpha3_resource_slice_t *v1alpha3_resource_slice_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha3_resource_slice_spec_t *spec
);

void v1alpha3_resource_slice_free(v1alpha3_resource_slice_t *v1alpha3_resource_slice);

v1alpha3_resource_slice_t *v1alpha3_resource_slice_parseFromJSON(cJSON *v1alpha3_resource_sliceJSON);

cJSON *v1alpha3_resource_slice_convertToJSON(v1alpha3_resource_slice_t *v1alpha3_resource_slice);

#endif /* _v1alpha3_resource_slice_H_ */

