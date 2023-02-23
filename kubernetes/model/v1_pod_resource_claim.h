/*
 * v1_pod_resource_claim.h
 *
 * PodResourceClaim references exactly one ResourceClaim through a ClaimSource. It adds a name to it that uniquely identifies the ResourceClaim inside the Pod. Containers that need access to the ResourceClaim reference it with this name.
 */

#ifndef _v1_pod_resource_claim_H_
#define _v1_pod_resource_claim_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_pod_resource_claim_t v1_pod_resource_claim_t;

#include "v1_claim_source.h"



typedef struct v1_pod_resource_claim_t {
    char *name; // string
    struct v1_claim_source_t *source; //model

} v1_pod_resource_claim_t;

v1_pod_resource_claim_t *v1_pod_resource_claim_create(
    char *name,
    v1_claim_source_t *source
);

void v1_pod_resource_claim_free(v1_pod_resource_claim_t *v1_pod_resource_claim);

v1_pod_resource_claim_t *v1_pod_resource_claim_parseFromJSON(cJSON *v1_pod_resource_claimJSON);

cJSON *v1_pod_resource_claim_convertToJSON(v1_pod_resource_claim_t *v1_pod_resource_claim);

#endif /* _v1_pod_resource_claim_H_ */

