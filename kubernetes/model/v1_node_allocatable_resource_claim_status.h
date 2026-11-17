/*
 * v1_node_allocatable_resource_claim_status.h
 *
 * NodeAllocatableResourceClaimStatus describes the status of node allocatable resources allocated via DRA.
 */

#ifndef _v1_node_allocatable_resource_claim_status_H_
#define _v1_node_allocatable_resource_claim_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_node_allocatable_resource_claim_status_t v1_node_allocatable_resource_claim_status_t;

#include "v1_node_allocatable_mapped_resources.h"
#include "v1_node_allocatable_overhead_resources.h"



typedef struct v1_node_allocatable_resource_claim_status_t {
    list_t *containers; //primitive container
    list_t *mapping; //nonprimitive container
    list_t *overhead; //nonprimitive container
    char *resource_claim_name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_node_allocatable_resource_claim_status_t;

__attribute__((deprecated)) v1_node_allocatable_resource_claim_status_t *v1_node_allocatable_resource_claim_status_create(
    list_t *containers,
    list_t *mapping,
    list_t *overhead,
    char *resource_claim_name
);

void v1_node_allocatable_resource_claim_status_free(v1_node_allocatable_resource_claim_status_t *v1_node_allocatable_resource_claim_status);

v1_node_allocatable_resource_claim_status_t *v1_node_allocatable_resource_claim_status_parseFromJSON(cJSON *v1_node_allocatable_resource_claim_statusJSON);

cJSON *v1_node_allocatable_resource_claim_status_convertToJSON(v1_node_allocatable_resource_claim_status_t *v1_node_allocatable_resource_claim_status);

#endif /* _v1_node_allocatable_resource_claim_status_H_ */

