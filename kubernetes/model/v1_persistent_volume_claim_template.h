/*
 * v1_persistent_volume_claim_template.h
 *
 * PersistentVolumeClaimTemplate is used to produce PersistentVolumeClaim objects as part of an EphemeralVolumeSource.
 */

#ifndef _v1_persistent_volume_claim_template_H_
#define _v1_persistent_volume_claim_template_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_persistent_volume_claim_template_t v1_persistent_volume_claim_template_t;

#include "v1_object_meta.h"
#include "v1_persistent_volume_claim_spec.h"



typedef struct v1_persistent_volume_claim_template_t {
    struct v1_object_meta_t *metadata; //model
    struct v1_persistent_volume_claim_spec_t *spec; //model

} v1_persistent_volume_claim_template_t;

v1_persistent_volume_claim_template_t *v1_persistent_volume_claim_template_create(
    v1_object_meta_t *metadata,
    v1_persistent_volume_claim_spec_t *spec
);

void v1_persistent_volume_claim_template_free(v1_persistent_volume_claim_template_t *v1_persistent_volume_claim_template);

v1_persistent_volume_claim_template_t *v1_persistent_volume_claim_template_parseFromJSON(cJSON *v1_persistent_volume_claim_templateJSON);

cJSON *v1_persistent_volume_claim_template_convertToJSON(v1_persistent_volume_claim_template_t *v1_persistent_volume_claim_template);

#endif /* _v1_persistent_volume_claim_template_H_ */

