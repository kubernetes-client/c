/*
 * v1beta1_device_claim.h
 *
 * DeviceClaim defines how to request devices with a ResourceClaim.
 */

#ifndef _v1beta1_device_claim_H_
#define _v1beta1_device_claim_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_device_claim_t v1beta1_device_claim_t;

#include "v1beta1_device_claim_configuration.h"
#include "v1beta1_device_constraint.h"
#include "v1beta1_device_request.h"



typedef struct v1beta1_device_claim_t {
    list_t *config; //nonprimitive container
    list_t *constraints; //nonprimitive container
    list_t *requests; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1beta1_device_claim_t;

__attribute__((deprecated)) v1beta1_device_claim_t *v1beta1_device_claim_create(
    list_t *config,
    list_t *constraints,
    list_t *requests
);

void v1beta1_device_claim_free(v1beta1_device_claim_t *v1beta1_device_claim);

v1beta1_device_claim_t *v1beta1_device_claim_parseFromJSON(cJSON *v1beta1_device_claimJSON);

cJSON *v1beta1_device_claim_convertToJSON(v1beta1_device_claim_t *v1beta1_device_claim);

#endif /* _v1beta1_device_claim_H_ */

