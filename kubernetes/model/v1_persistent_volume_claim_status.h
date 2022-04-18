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

// Enum PHASE for v1_persistent_volume_claim_status

typedef enum  { kubernetes_v1_persistent_volume_claim_status_PHASE_NULL = 0, kubernetes_v1_persistent_volume_claim_status_PHASE_Bound, kubernetes_v1_persistent_volume_claim_status_PHASE_Lost, kubernetes_v1_persistent_volume_claim_status_PHASE_Pending } kubernetes_v1_persistent_volume_claim_status_PHASE_e;

char* v1_persistent_volume_claim_status_phase_ToString(kubernetes_v1_persistent_volume_claim_status_PHASE_e phase);

kubernetes_v1_persistent_volume_claim_status_PHASE_e v1_persistent_volume_claim_status_phase_FromString(char* phase);



typedef struct v1_persistent_volume_claim_status_t {
    list_t *access_modes; //primitive container
    list_t* allocated_resources; //map
    list_t* capacity; //map
    list_t *conditions; //nonprimitive container
    kubernetes_v1_persistent_volume_claim_status_PHASE_e phase; //enum
    char *resize_status; // string

} v1_persistent_volume_claim_status_t;

v1_persistent_volume_claim_status_t *v1_persistent_volume_claim_status_create(
    list_t *access_modes,
    list_t* allocated_resources,
    list_t* capacity,
    list_t *conditions,
    kubernetes_v1_persistent_volume_claim_status_PHASE_e phase,
    char *resize_status
);

void v1_persistent_volume_claim_status_free(v1_persistent_volume_claim_status_t *v1_persistent_volume_claim_status);

v1_persistent_volume_claim_status_t *v1_persistent_volume_claim_status_parseFromJSON(cJSON *v1_persistent_volume_claim_statusJSON);

cJSON *v1_persistent_volume_claim_status_convertToJSON(v1_persistent_volume_claim_status_t *v1_persistent_volume_claim_status);

#endif /* _v1_persistent_volume_claim_status_H_ */

