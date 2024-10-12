/*
 * v1_resource_claim.h
 *
 * ResourceClaim references one entry in PodSpec.ResourceClaims.
 */

#ifndef _v1_resource_claim_H_
#define _v1_resource_claim_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_resource_claim_t v1_resource_claim_t;




typedef struct v1_resource_claim_t {
    char *name; // string
    char *request; // string

} v1_resource_claim_t;

v1_resource_claim_t *v1_resource_claim_create(
    char *name,
    char *request
);

void v1_resource_claim_free(v1_resource_claim_t *v1_resource_claim);

v1_resource_claim_t *v1_resource_claim_parseFromJSON(cJSON *v1_resource_claimJSON);

cJSON *v1_resource_claim_convertToJSON(v1_resource_claim_t *v1_resource_claim);

#endif /* _v1_resource_claim_H_ */

