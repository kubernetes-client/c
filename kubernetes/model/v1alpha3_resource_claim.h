/*
 * v1alpha3_resource_claim.h
 *
 * ResourceClaim describes a request for access to resources in the cluster, for use by workloads. For example, if a workload needs an accelerator device with specific properties, this is how that request is expressed. The status stanza tracks whether this claim has been satisfied and what specific resources have been allocated.  This is an alpha type and requires enabling the DynamicResourceAllocation feature gate.
 */

#ifndef _v1alpha3_resource_claim_H_
#define _v1alpha3_resource_claim_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_resource_claim_t v1alpha3_resource_claim_t;

#include "v1_object_meta.h"
#include "v1alpha3_resource_claim_spec.h"
#include "v1alpha3_resource_claim_status.h"



typedef struct v1alpha3_resource_claim_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1alpha3_resource_claim_spec_t *spec; //model
    struct v1alpha3_resource_claim_status_t *status; //model

} v1alpha3_resource_claim_t;

v1alpha3_resource_claim_t *v1alpha3_resource_claim_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1alpha3_resource_claim_spec_t *spec,
    v1alpha3_resource_claim_status_t *status
);

void v1alpha3_resource_claim_free(v1alpha3_resource_claim_t *v1alpha3_resource_claim);

v1alpha3_resource_claim_t *v1alpha3_resource_claim_parseFromJSON(cJSON *v1alpha3_resource_claimJSON);

cJSON *v1alpha3_resource_claim_convertToJSON(v1alpha3_resource_claim_t *v1alpha3_resource_claim);

#endif /* _v1alpha3_resource_claim_H_ */

