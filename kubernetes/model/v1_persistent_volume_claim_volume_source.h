/*
 * v1_persistent_volume_claim_volume_source.h
 *
 * PersistentVolumeClaimVolumeSource references the user&#39;s PVC in the same namespace. This volume finds the bound PV and mounts that volume for the pod. A PersistentVolumeClaimVolumeSource is, essentially, a wrapper around another type of volume that is owned by someone else (the system).
 */

#ifndef _v1_persistent_volume_claim_volume_source_H_
#define _v1_persistent_volume_claim_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_persistent_volume_claim_volume_source_t v1_persistent_volume_claim_volume_source_t;




typedef struct v1_persistent_volume_claim_volume_source_t {
    char *claim_name; // string
    int read_only; //boolean

} v1_persistent_volume_claim_volume_source_t;

v1_persistent_volume_claim_volume_source_t *v1_persistent_volume_claim_volume_source_create(
    char *claim_name,
    int read_only
);

void v1_persistent_volume_claim_volume_source_free(v1_persistent_volume_claim_volume_source_t *v1_persistent_volume_claim_volume_source);

v1_persistent_volume_claim_volume_source_t *v1_persistent_volume_claim_volume_source_parseFromJSON(cJSON *v1_persistent_volume_claim_volume_sourceJSON);

cJSON *v1_persistent_volume_claim_volume_source_convertToJSON(v1_persistent_volume_claim_volume_source_t *v1_persistent_volume_claim_volume_source);

#endif /* _v1_persistent_volume_claim_volume_source_H_ */

