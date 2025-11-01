/*
 * resource_v1_resource_claim.h
 *
 * ResourceClaim describes a request for access to resources in the cluster, for use by workloads. For example, if a workload needs an accelerator device with specific properties, this is how that request is expressed. The status stanza tracks whether this claim has been satisfied and what specific resources have been allocated.  This is an alpha type and requires enabling the DynamicResourceAllocation feature gate.
 */

#ifndef _resource_v1_resource_claim_H_
#define _resource_v1_resource_claim_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct resource_v1_resource_claim_t resource_v1_resource_claim_t;

#include "v1_object_meta.h"
#include "v1_resource_claim_spec.h"
#include "v1_resource_claim_status.h"



typedef struct resource_v1_resource_claim_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1_resource_claim_spec_t *spec; //model
    struct v1_resource_claim_status_t *status; //model

    int _library_owned; // Is the library responsible for freeing this object?
} resource_v1_resource_claim_t;

__attribute__((deprecated)) resource_v1_resource_claim_t *resource_v1_resource_claim_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_resource_claim_spec_t *spec,
    v1_resource_claim_status_t *status
);

void resource_v1_resource_claim_free(resource_v1_resource_claim_t *resource_v1_resource_claim);

resource_v1_resource_claim_t *resource_v1_resource_claim_parseFromJSON(cJSON *resource_v1_resource_claimJSON);

cJSON *resource_v1_resource_claim_convertToJSON(resource_v1_resource_claim_t *resource_v1_resource_claim);

#endif /* _resource_v1_resource_claim_H_ */

