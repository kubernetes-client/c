/*
 * v1alpha3_resource_claim_status.h
 *
 * ResourceClaimStatus tracks whether the resource has been allocated and what the result of that was.
 */

#ifndef _v1alpha3_resource_claim_status_H_
#define _v1alpha3_resource_claim_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_resource_claim_status_t v1alpha3_resource_claim_status_t;

#include "v1alpha3_allocated_device_status.h"
#include "v1alpha3_allocation_result.h"
#include "v1alpha3_resource_claim_consumer_reference.h"



typedef struct v1alpha3_resource_claim_status_t {
    struct v1alpha3_allocation_result_t *allocation; //model
    list_t *devices; //nonprimitive container
    list_t *reserved_for; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1alpha3_resource_claim_status_t;

__attribute__((deprecated)) v1alpha3_resource_claim_status_t *v1alpha3_resource_claim_status_create(
    v1alpha3_allocation_result_t *allocation,
    list_t *devices,
    list_t *reserved_for
);

void v1alpha3_resource_claim_status_free(v1alpha3_resource_claim_status_t *v1alpha3_resource_claim_status);

v1alpha3_resource_claim_status_t *v1alpha3_resource_claim_status_parseFromJSON(cJSON *v1alpha3_resource_claim_statusJSON);

cJSON *v1alpha3_resource_claim_status_convertToJSON(v1alpha3_resource_claim_status_t *v1alpha3_resource_claim_status);

#endif /* _v1alpha3_resource_claim_status_H_ */

