/*
 * v1beta1_pod_group_resource_claim.h
 *
 * PodGroupResourceClaim references exactly one ResourceClaim, either directly or by naming a ResourceClaimTemplate which is then turned into a ResourceClaim for the PodGroup.  It adds a name to it that uniquely identifies the ResourceClaim inside the PodGroup. Pods that need access to the ResourceClaim define a matching reference in its own Spec.ResourceClaims. The Pod&#39;s claim must match all fields of the PodGroup&#39;s claim exactly.
 */

#ifndef _v1beta1_pod_group_resource_claim_H_
#define _v1beta1_pod_group_resource_claim_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_pod_group_resource_claim_t v1beta1_pod_group_resource_claim_t;




typedef struct v1beta1_pod_group_resource_claim_t {
    char *name; // string
    char *resource_claim_name; // string
    char *resource_claim_template_name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta1_pod_group_resource_claim_t;

__attribute__((deprecated)) v1beta1_pod_group_resource_claim_t *v1beta1_pod_group_resource_claim_create(
    char *name,
    char *resource_claim_name,
    char *resource_claim_template_name
);

void v1beta1_pod_group_resource_claim_free(v1beta1_pod_group_resource_claim_t *v1beta1_pod_group_resource_claim);

v1beta1_pod_group_resource_claim_t *v1beta1_pod_group_resource_claim_parseFromJSON(cJSON *v1beta1_pod_group_resource_claimJSON);

cJSON *v1beta1_pod_group_resource_claim_convertToJSON(v1beta1_pod_group_resource_claim_t *v1beta1_pod_group_resource_claim);

#endif /* _v1beta1_pod_group_resource_claim_H_ */

