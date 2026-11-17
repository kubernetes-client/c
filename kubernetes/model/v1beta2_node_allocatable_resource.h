/*
 * v1beta2_node_allocatable_resource.h
 *
 * NodeAllocatableResource defines the translation between the DRA device/capacity units requested to the corresponding quantity of the node allocatable resource. At least one of Mapping or Overhead must be specified. Not specifying either is an invalid configuration.
 */

#ifndef _v1beta2_node_allocatable_resource_H_
#define _v1beta2_node_allocatable_resource_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta2_node_allocatable_resource_t v1beta2_node_allocatable_resource_t;

#include "v1beta2_node_allocatable_mapping.h"
#include "v1beta2_node_allocatable_overhead.h"



typedef struct v1beta2_node_allocatable_resource_t {
    struct v1beta2_node_allocatable_mapping_t *mapping; //model
    struct v1beta2_node_allocatable_overhead_t *overhead; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta2_node_allocatable_resource_t;

__attribute__((deprecated)) v1beta2_node_allocatable_resource_t *v1beta2_node_allocatable_resource_create(
    v1beta2_node_allocatable_mapping_t *mapping,
    v1beta2_node_allocatable_overhead_t *overhead
);

void v1beta2_node_allocatable_resource_free(v1beta2_node_allocatable_resource_t *v1beta2_node_allocatable_resource);

v1beta2_node_allocatable_resource_t *v1beta2_node_allocatable_resource_parseFromJSON(cJSON *v1beta2_node_allocatable_resourceJSON);

cJSON *v1beta2_node_allocatable_resource_convertToJSON(v1beta2_node_allocatable_resource_t *v1beta2_node_allocatable_resource);

#endif /* _v1beta2_node_allocatable_resource_H_ */

