/*
 * v1_ephemeral_volume_source.h
 *
 * Represents an ephemeral volume that is handled by a normal storage driver.
 */

#ifndef _v1_ephemeral_volume_source_H_
#define _v1_ephemeral_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_ephemeral_volume_source_t v1_ephemeral_volume_source_t;

#include "v1_persistent_volume_claim_template.h"



typedef struct v1_ephemeral_volume_source_t {
    struct v1_persistent_volume_claim_template_t *volume_claim_template; //model

} v1_ephemeral_volume_source_t;

v1_ephemeral_volume_source_t *v1_ephemeral_volume_source_create(
    v1_persistent_volume_claim_template_t *volume_claim_template
);

void v1_ephemeral_volume_source_free(v1_ephemeral_volume_source_t *v1_ephemeral_volume_source);

v1_ephemeral_volume_source_t *v1_ephemeral_volume_source_parseFromJSON(cJSON *v1_ephemeral_volume_sourceJSON);

cJSON *v1_ephemeral_volume_source_convertToJSON(v1_ephemeral_volume_source_t *v1_ephemeral_volume_source);

#endif /* _v1_ephemeral_volume_source_H_ */

