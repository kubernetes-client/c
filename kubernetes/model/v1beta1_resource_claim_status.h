/*
 * v1beta1_resource_claim_status.h
 *
 * ResourceClaimStatus tracks whether the resource has been allocated and what the result of that was.
 */

#ifndef _v1beta1_resource_claim_status_H_
#define _v1beta1_resource_claim_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_resource_claim_status_t v1beta1_resource_claim_status_t;

#include "v1beta1_allocated_device_status.h"
#include "v1beta1_allocation_result.h"
#include "v1beta1_resource_claim_consumer_reference.h"



typedef struct v1beta1_resource_claim_status_t {
    struct v1beta1_allocation_result_t *allocation; //model
    list_t *devices; //nonprimitive container
    list_t *reserved_for; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta1_resource_claim_status_t;

__attribute__((deprecated)) v1beta1_resource_claim_status_t *v1beta1_resource_claim_status_create(
    v1beta1_allocation_result_t *allocation,
    list_t *devices,
    list_t *reserved_for
);

void v1beta1_resource_claim_status_free(v1beta1_resource_claim_status_t *v1beta1_resource_claim_status);

v1beta1_resource_claim_status_t *v1beta1_resource_claim_status_parseFromJSON(cJSON *v1beta1_resource_claim_statusJSON);

cJSON *v1beta1_resource_claim_status_convertToJSON(v1beta1_resource_claim_status_t *v1beta1_resource_claim_status);

#endif /* _v1beta1_resource_claim_status_H_ */

