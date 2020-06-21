/*
 * v1_persistent_volume_claim_status.h
 *
 * PersistentVolumeClaimStatus is the current status of a persistent volume claim.
 */

#ifndef _v1_persistent_volume_claim_status_H_
#define _v1_persistent_volume_claim_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_persistent_volume_claim_status_t v1_persistent_volume_claim_status_t;

#include "v1_persistent_volume_claim_condition.h"



typedef struct v1_persistent_volume_claim_status_t {
    list_t *access_modes; //primitive container
    list_t* capacity; //map
    list_t *conditions; //nonprimitive container
    char *phase; // string

} v1_persistent_volume_claim_status_t;

v1_persistent_volume_claim_status_t *v1_persistent_volume_claim_status_create(
    list_t *access_modes,
    list_t* capacity,
    list_t *conditions,
    char *phase
);

void v1_persistent_volume_claim_status_free(v1_persistent_volume_claim_status_t *v1_persistent_volume_claim_status);

v1_persistent_volume_claim_status_t *v1_persistent_volume_claim_status_parseFromJSON(cJSON *v1_persistent_volume_claim_statusJSON);

cJSON *v1_persistent_volume_claim_status_convertToJSON(v1_persistent_volume_claim_status_t *v1_persistent_volume_claim_status);

#endif /* _v1_persistent_volume_claim_status_H_ */

