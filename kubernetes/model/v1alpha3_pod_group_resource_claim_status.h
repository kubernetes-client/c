/*
 * v1alpha3_pod_group_resource_claim_status.h
 *
 * PodGroupResourceClaimStatus is stored in the PodGroupStatus for each PodGroupResourceClaim which references a ResourceClaimTemplate. It stores the generated name for the corresponding ResourceClaim.
 */

#ifndef _v1alpha3_pod_group_resource_claim_status_H_
#define _v1alpha3_pod_group_resource_claim_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_pod_group_resource_claim_status_t v1alpha3_pod_group_resource_claim_status_t;




typedef struct v1alpha3_pod_group_resource_claim_status_t {
    char *name; // string
    char *resource_claim_name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha3_pod_group_resource_claim_status_t;

__attribute__((deprecated)) v1alpha3_pod_group_resource_claim_status_t *v1alpha3_pod_group_resource_claim_status_create(
    char *name,
    char *resource_claim_name
);

void v1alpha3_pod_group_resource_claim_status_free(v1alpha3_pod_group_resource_claim_status_t *v1alpha3_pod_group_resource_claim_status);

v1alpha3_pod_group_resource_claim_status_t *v1alpha3_pod_group_resource_claim_status_parseFromJSON(cJSON *v1alpha3_pod_group_resource_claim_statusJSON);

cJSON *v1alpha3_pod_group_resource_claim_status_convertToJSON(v1alpha3_pod_group_resource_claim_status_t *v1alpha3_pod_group_resource_claim_status);

#endif /* _v1alpha3_pod_group_resource_claim_status_H_ */

