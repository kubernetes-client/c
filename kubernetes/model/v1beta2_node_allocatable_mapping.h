/*
 * v1beta2_node_allocatable_mapping.h
 *
 * NodeAllocatableMapping defines how a DRA allocation directly translates into a node allocatable resource quantity. The mapping can be derived from either the count of allocated devices (via deviceMultiplier) or the specific capacity consumed (via capacityKey and capacityMultiplier). These options are mutually exclusive. Kubelet adds this mapped resource quantity from claim to both requests and limits at the pod-level cgroup, and to limits at the container-level cgroup for each container referencing the claim.
 */

#ifndef _v1beta2_node_allocatable_mapping_H_
#define _v1beta2_node_allocatable_mapping_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta2_node_allocatable_mapping_t v1beta2_node_allocatable_mapping_t;




typedef struct v1beta2_node_allocatable_mapping_t {
    char *capacity_key; // string
    char *capacity_multiplier; // string
    char *device_multiplier; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta2_node_allocatable_mapping_t;

__attribute__((deprecated)) v1beta2_node_allocatable_mapping_t *v1beta2_node_allocatable_mapping_create(
    char *capacity_key,
    char *capacity_multiplier,
    char *device_multiplier
);

void v1beta2_node_allocatable_mapping_free(v1beta2_node_allocatable_mapping_t *v1beta2_node_allocatable_mapping);

v1beta2_node_allocatable_mapping_t *v1beta2_node_allocatable_mapping_parseFromJSON(cJSON *v1beta2_node_allocatable_mappingJSON);

cJSON *v1beta2_node_allocatable_mapping_convertToJSON(v1beta2_node_allocatable_mapping_t *v1beta2_node_allocatable_mapping);

#endif /* _v1beta2_node_allocatable_mapping_H_ */

