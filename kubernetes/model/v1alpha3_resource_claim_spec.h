/*
 * v1alpha3_resource_claim_spec.h
 *
 * ResourceClaimSpec defines what is being requested in a ResourceClaim and how to configure it.
 */

#ifndef _v1alpha3_resource_claim_spec_H_
#define _v1alpha3_resource_claim_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1alpha3_resource_claim_spec_t v1alpha3_resource_claim_spec_t;

#include "v1alpha3_device_claim.h"



typedef struct v1alpha3_resource_claim_spec_t {
    char *controller; // string
    struct v1alpha3_device_claim_t *devices; //model

} v1alpha3_resource_claim_spec_t;

v1alpha3_resource_claim_spec_t *v1alpha3_resource_claim_spec_create(
    char *controller,
    v1alpha3_device_claim_t *devices
);

void v1alpha3_resource_claim_spec_free(v1alpha3_resource_claim_spec_t *v1alpha3_resource_claim_spec);

v1alpha3_resource_claim_spec_t *v1alpha3_resource_claim_spec_parseFromJSON(cJSON *v1alpha3_resource_claim_specJSON);

cJSON *v1alpha3_resource_claim_spec_convertToJSON(v1alpha3_resource_claim_spec_t *v1alpha3_resource_claim_spec);

#endif /* _v1alpha3_resource_claim_spec_H_ */

