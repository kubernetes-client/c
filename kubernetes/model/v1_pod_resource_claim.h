/*
 * v1_pod_resource_claim.h
 *
 * PodResourceClaim references exactly one ResourceClaim, either directly or by naming a ResourceClaimTemplate which is then turned into a ResourceClaim for the pod.  It adds a name to it that uniquely identifies the ResourceClaim inside the Pod. Containers that need access to the ResourceClaim reference it with this name.
 */

#ifndef _v1_pod_resource_claim_H_
#define _v1_pod_resource_claim_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_pod_resource_claim_t v1_pod_resource_claim_t;




typedef struct v1_pod_resource_claim_t {
    char *name; // string
    char *resource_claim_name; // string
    char *resource_claim_template_name; // string

} v1_pod_resource_claim_t;

v1_pod_resource_claim_t *v1_pod_resource_claim_create(
    char *name,
    char *resource_claim_name,
    char *resource_claim_template_name
);

void v1_pod_resource_claim_free(v1_pod_resource_claim_t *v1_pod_resource_claim);

v1_pod_resource_claim_t *v1_pod_resource_claim_parseFromJSON(cJSON *v1_pod_resource_claimJSON);

cJSON *v1_pod_resource_claim_convertToJSON(v1_pod_resource_claim_t *v1_pod_resource_claim);

#endif /* _v1_pod_resource_claim_H_ */

