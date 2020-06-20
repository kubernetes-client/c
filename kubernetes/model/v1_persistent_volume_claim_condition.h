/*
 * v1_persistent_volume_claim_condition.h
 *
 * PersistentVolumeClaimCondition contails details about state of pvc
 */

#ifndef _v1_persistent_volume_claim_condition_H_
#define _v1_persistent_volume_claim_condition_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_persistent_volume_claim_condition_t v1_persistent_volume_claim_condition_t;




typedef struct v1_persistent_volume_claim_condition_t {
    char *last_probe_time; //date time
    char *last_transition_time; //date time
    char *message; // string
    char *reason; // string
    char *status; // string
    char *type; // string

} v1_persistent_volume_claim_condition_t;

v1_persistent_volume_claim_condition_t *v1_persistent_volume_claim_condition_create(
    char *last_probe_time,
    char *last_transition_time,
    char *message,
    char *reason,
    char *status,
    char *type
);

void v1_persistent_volume_claim_condition_free(v1_persistent_volume_claim_condition_t *v1_persistent_volume_claim_condition);

v1_persistent_volume_claim_condition_t *v1_persistent_volume_claim_condition_parseFromJSON(cJSON *v1_persistent_volume_claim_conditionJSON);

cJSON *v1_persistent_volume_claim_condition_convertToJSON(v1_persistent_volume_claim_condition_t *v1_persistent_volume_claim_condition);

#endif /* _v1_persistent_volume_claim_condition_H_ */

