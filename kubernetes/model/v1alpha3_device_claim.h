/*
 * v1alpha3_device_claim.h
 *
 * DeviceClaim defines how to request devices with a ResourceClaim.
 */

#ifndef _v1alpha3_device_claim_H_
#define _v1alpha3_device_claim_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_device_claim_t v1alpha3_device_claim_t;

#include "v1alpha3_device_claim_configuration.h"
#include "v1alpha3_device_constraint.h"
#include "v1alpha3_device_request.h"



typedef struct v1alpha3_device_claim_t {
    list_t *config; //nonprimitive container
    list_t *constraints; //nonprimitive container
    list_t *requests; //nonprimitive container

} v1alpha3_device_claim_t;

v1alpha3_device_claim_t *v1alpha3_device_claim_create(
    list_t *config,
    list_t *constraints,
    list_t *requests
);

void v1alpha3_device_claim_free(v1alpha3_device_claim_t *v1alpha3_device_claim);

v1alpha3_device_claim_t *v1alpha3_device_claim_parseFromJSON(cJSON *v1alpha3_device_claimJSON);

cJSON *v1alpha3_device_claim_convertToJSON(v1alpha3_device_claim_t *v1alpha3_device_claim);

#endif /* _v1alpha3_device_claim_H_ */

