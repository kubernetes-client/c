/*
 * v1_persistent_volume_claim.h
 *
 * PersistentVolumeClaim is a user&#39;s request for and claim to a persistent volume
 */

#ifndef _v1_persistent_volume_claim_H_
#define _v1_persistent_volume_claim_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_persistent_volume_claim_t v1_persistent_volume_claim_t;

#include "v1_object_meta.h"
#include "v1_persistent_volume_claim_spec.h"
#include "v1_persistent_volume_claim_status.h"



typedef struct v1_persistent_volume_claim_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1_persistent_volume_claim_spec_t *spec; //model
    struct v1_persistent_volume_claim_status_t *status; //model

} v1_persistent_volume_claim_t;

v1_persistent_volume_claim_t *v1_persistent_volume_claim_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_persistent_volume_claim_spec_t *spec,
    v1_persistent_volume_claim_status_t *status
);

void v1_persistent_volume_claim_free(v1_persistent_volume_claim_t *v1_persistent_volume_claim);

v1_persistent_volume_claim_t *v1_persistent_volume_claim_parseFromJSON(cJSON *v1_persistent_volume_claimJSON);

cJSON *v1_persistent_volume_claim_convertToJSON(v1_persistent_volume_claim_t *v1_persistent_volume_claim);

#endif /* _v1_persistent_volume_claim_H_ */

