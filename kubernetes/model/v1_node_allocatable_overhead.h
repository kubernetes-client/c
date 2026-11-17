/*
 * v1_node_allocatable_overhead.h
 *
 * NodeAllocatableOverhead defines auxiliary resource overheads incurred when allocating a device. Overheads can be specified as a fixed cost per pod referencing the claim, a variable cost per container reference, or both. Kubelet accounts for this overhead by adding it to both the pod-level and container-level cgroups of referencing containers.
 */

#ifndef _v1_node_allocatable_overhead_H_
#define _v1_node_allocatable_overhead_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_node_allocatable_overhead_t v1_node_allocatable_overhead_t;




typedef struct v1_node_allocatable_overhead_t {
    char *per_container; // string
    char *per_pod; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_node_allocatable_overhead_t;

__attribute__((deprecated)) v1_node_allocatable_overhead_t *v1_node_allocatable_overhead_create(
    char *per_container,
    char *per_pod
);

void v1_node_allocatable_overhead_free(v1_node_allocatable_overhead_t *v1_node_allocatable_overhead);

v1_node_allocatable_overhead_t *v1_node_allocatable_overhead_parseFromJSON(cJSON *v1_node_allocatable_overheadJSON);

cJSON *v1_node_allocatable_overhead_convertToJSON(v1_node_allocatable_overhead_t *v1_node_allocatable_overhead);

#endif /* _v1_node_allocatable_overhead_H_ */

