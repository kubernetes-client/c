/*
 * v1_node_allocatable_mapped_resources.h
 *
 * NodeAllocatableMappedResources describes mapped node allocatable resource allocations.
 */

#ifndef _v1_node_allocatable_mapped_resources_H_
#define _v1_node_allocatable_mapped_resources_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_node_allocatable_mapped_resources_t v1_node_allocatable_mapped_resources_t;




typedef struct v1_node_allocatable_mapped_resources_t {
    char *name; // string
    char *quantity; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_node_allocatable_mapped_resources_t;

__attribute__((deprecated)) v1_node_allocatable_mapped_resources_t *v1_node_allocatable_mapped_resources_create(
    char *name,
    char *quantity
);

void v1_node_allocatable_mapped_resources_free(v1_node_allocatable_mapped_resources_t *v1_node_allocatable_mapped_resources);

v1_node_allocatable_mapped_resources_t *v1_node_allocatable_mapped_resources_parseFromJSON(cJSON *v1_node_allocatable_mapped_resourcesJSON);

cJSON *v1_node_allocatable_mapped_resources_convertToJSON(v1_node_allocatable_mapped_resources_t *v1_node_allocatable_mapped_resources);

#endif /* _v1_node_allocatable_mapped_resources_H_ */

