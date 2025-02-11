/*
 * v1_stateful_set_persistent_volume_claim_retention_policy.h
 *
 * StatefulSetPersistentVolumeClaimRetentionPolicy describes the policy used for PVCs created from the StatefulSet VolumeClaimTemplates.
 */

#ifndef _v1_stateful_set_persistent_volume_claim_retention_policy_H_
#define _v1_stateful_set_persistent_volume_claim_retention_policy_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_stateful_set_persistent_volume_claim_retention_policy_t v1_stateful_set_persistent_volume_claim_retention_policy_t;




typedef struct v1_stateful_set_persistent_volume_claim_retention_policy_t {
    char *when_deleted; // string
    char *when_scaled; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_stateful_set_persistent_volume_claim_retention_policy_t;

__attribute__((deprecated)) v1_stateful_set_persistent_volume_claim_retention_policy_t *v1_stateful_set_persistent_volume_claim_retention_policy_create(
    char *when_deleted,
    char *when_scaled
);

void v1_stateful_set_persistent_volume_claim_retention_policy_free(v1_stateful_set_persistent_volume_claim_retention_policy_t *v1_stateful_set_persistent_volume_claim_retention_policy);

v1_stateful_set_persistent_volume_claim_retention_policy_t *v1_stateful_set_persistent_volume_claim_retention_policy_parseFromJSON(cJSON *v1_stateful_set_persistent_volume_claim_retention_policyJSON);

cJSON *v1_stateful_set_persistent_volume_claim_retention_policy_convertToJSON(v1_stateful_set_persistent_volume_claim_retention_policy_t *v1_stateful_set_persistent_volume_claim_retention_policy);

#endif /* _v1_stateful_set_persistent_volume_claim_retention_policy_H_ */

