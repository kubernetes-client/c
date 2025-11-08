/*
 * core_v1_resource_claim.h
 *
 * ResourceClaim references one entry in PodSpec.ResourceClaims.
 */

#ifndef _core_v1_resource_claim_H_
#define _core_v1_resource_claim_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct core_v1_resource_claim_t core_v1_resource_claim_t;




typedef struct core_v1_resource_claim_t {
    char *name; // string
    char *request; // string

    int _library_owned; // Is the library responsible for freeing this object?
} core_v1_resource_claim_t;

__attribute__((deprecated)) core_v1_resource_claim_t *core_v1_resource_claim_create(
    char *name,
    char *request
);

void core_v1_resource_claim_free(core_v1_resource_claim_t *core_v1_resource_claim);

core_v1_resource_claim_t *core_v1_resource_claim_parseFromJSON(cJSON *core_v1_resource_claimJSON);

cJSON *core_v1_resource_claim_convertToJSON(core_v1_resource_claim_t *core_v1_resource_claim);

#endif /* _core_v1_resource_claim_H_ */

