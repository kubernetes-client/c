/*
 * v1alpha1_resource_claim_status.h
 *
 * ResourceClaimStatus tracks whether the resource has been allocated and what the resulting attributes are.
 */

#ifndef _v1alpha1_resource_claim_status_H_
#define _v1alpha1_resource_claim_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha1_resource_claim_status_t v1alpha1_resource_claim_status_t;

#include "v1alpha1_allocation_result.h"
#include "v1alpha1_resource_claim_consumer_reference.h"



typedef struct v1alpha1_resource_claim_status_t {
    struct v1alpha1_allocation_result_t *allocation; //model
    int deallocation_requested; //boolean
    char *driver_name; // string
    list_t *reserved_for; //nonprimitive container

} v1alpha1_resource_claim_status_t;

v1alpha1_resource_claim_status_t *v1alpha1_resource_claim_status_create(
    v1alpha1_allocation_result_t *allocation,
    int deallocation_requested,
    char *driver_name,
    list_t *reserved_for
);

void v1alpha1_resource_claim_status_free(v1alpha1_resource_claim_status_t *v1alpha1_resource_claim_status);

v1alpha1_resource_claim_status_t *v1alpha1_resource_claim_status_parseFromJSON(cJSON *v1alpha1_resource_claim_statusJSON);

cJSON *v1alpha1_resource_claim_status_convertToJSON(v1alpha1_resource_claim_status_t *v1alpha1_resource_claim_status);

#endif /* _v1alpha1_resource_claim_status_H_ */

