/*
 * v1_pod_resource_claim_status.h
 *
 * PodResourceClaimStatus is stored in the PodStatus for each PodResourceClaim which references a ResourceClaimTemplate. It stores the generated name for the corresponding ResourceClaim.
 */

#ifndef _v1_pod_resource_claim_status_H_
#define _v1_pod_resource_claim_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_pod_resource_claim_status_t v1_pod_resource_claim_status_t;




typedef struct v1_pod_resource_claim_status_t {
    char *name; // string
    char *resource_claim_name; // string

} v1_pod_resource_claim_status_t;

v1_pod_resource_claim_status_t *v1_pod_resource_claim_status_create(
    char *name,
    char *resource_claim_name
);

void v1_pod_resource_claim_status_free(v1_pod_resource_claim_status_t *v1_pod_resource_claim_status);

v1_pod_resource_claim_status_t *v1_pod_resource_claim_status_parseFromJSON(cJSON *v1_pod_resource_claim_statusJSON);

cJSON *v1_pod_resource_claim_status_convertToJSON(v1_pod_resource_claim_status_t *v1_pod_resource_claim_status);

#endif /* _v1_pod_resource_claim_status_H_ */

