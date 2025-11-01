/*
 * v1_pod_extended_resource_claim_status.h
 *
 * PodExtendedResourceClaimStatus is stored in the PodStatus for the extended resource requests backed by DRA. It stores the generated name for the corresponding special ResourceClaim created by the scheduler.
 */

#ifndef _v1_pod_extended_resource_claim_status_H_
#define _v1_pod_extended_resource_claim_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_pod_extended_resource_claim_status_t v1_pod_extended_resource_claim_status_t;

#include "v1_container_extended_resource_request.h"



typedef struct v1_pod_extended_resource_claim_status_t {
    list_t *request_mappings; //nonprimitive container
    char *resource_claim_name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_pod_extended_resource_claim_status_t;

__attribute__((deprecated)) v1_pod_extended_resource_claim_status_t *v1_pod_extended_resource_claim_status_create(
    list_t *request_mappings,
    char *resource_claim_name
);

void v1_pod_extended_resource_claim_status_free(v1_pod_extended_resource_claim_status_t *v1_pod_extended_resource_claim_status);

v1_pod_extended_resource_claim_status_t *v1_pod_extended_resource_claim_status_parseFromJSON(cJSON *v1_pod_extended_resource_claim_statusJSON);

cJSON *v1_pod_extended_resource_claim_status_convertToJSON(v1_pod_extended_resource_claim_status_t *v1_pod_extended_resource_claim_status);

#endif /* _v1_pod_extended_resource_claim_status_H_ */

