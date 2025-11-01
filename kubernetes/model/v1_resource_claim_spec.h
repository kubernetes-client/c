/*
 * v1_resource_claim_spec.h
 *
 * ResourceClaimSpec defines what is being requested in a ResourceClaim and how to configure it.
 */

#ifndef _v1_resource_claim_spec_H_
#define _v1_resource_claim_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_resource_claim_spec_t v1_resource_claim_spec_t;

#include "v1_device_claim.h"



typedef struct v1_resource_claim_spec_t {
    struct v1_device_claim_t *devices; //model

    int _library_owned; // Is the library responsible for freeing this object?
} v1_resource_claim_spec_t;

__attribute__((deprecated)) v1_resource_claim_spec_t *v1_resource_claim_spec_create(
    v1_device_claim_t *devices
);

void v1_resource_claim_spec_free(v1_resource_claim_spec_t *v1_resource_claim_spec);

v1_resource_claim_spec_t *v1_resource_claim_spec_parseFromJSON(cJSON *v1_resource_claim_specJSON);

cJSON *v1_resource_claim_spec_convertToJSON(v1_resource_claim_spec_t *v1_resource_claim_spec);

#endif /* _v1_resource_claim_spec_H_ */

