/*
 * v1_node_allocatable_overhead_resources.h
 *
 * NodeAllocatableOverheadResources describes auxiliary overhead resource allocations.
 */

#ifndef _v1_node_allocatable_overhead_resources_H_
#define _v1_node_allocatable_overhead_resources_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_node_allocatable_overhead_resources_t v1_node_allocatable_overhead_resources_t;




typedef struct v1_node_allocatable_overhead_resources_t {
    char *name; // string
    char *per_container; // string
    char *per_pod; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_node_allocatable_overhead_resources_t;

__attribute__((deprecated)) v1_node_allocatable_overhead_resources_t *v1_node_allocatable_overhead_resources_create(
    char *name,
    char *per_container,
    char *per_pod
);

void v1_node_allocatable_overhead_resources_free(v1_node_allocatable_overhead_resources_t *v1_node_allocatable_overhead_resources);

v1_node_allocatable_overhead_resources_t *v1_node_allocatable_overhead_resources_parseFromJSON(cJSON *v1_node_allocatable_overhead_resourcesJSON);

cJSON *v1_node_allocatable_overhead_resources_convertToJSON(v1_node_allocatable_overhead_resources_t *v1_node_allocatable_overhead_resources);

#endif /* _v1_node_allocatable_overhead_resources_H_ */

