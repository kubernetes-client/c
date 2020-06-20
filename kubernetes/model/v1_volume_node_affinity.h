/*
 * v1_volume_node_affinity.h
 *
 * VolumeNodeAffinity defines constraints that limit what nodes this volume can be accessed from.
 */

#ifndef _v1_volume_node_affinity_H_
#define _v1_volume_node_affinity_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_volume_node_affinity_t v1_volume_node_affinity_t;

#include "v1_node_selector.h"



typedef struct v1_volume_node_affinity_t {
    struct v1_node_selector_t *required; //model

} v1_volume_node_affinity_t;

v1_volume_node_affinity_t *v1_volume_node_affinity_create(
    v1_node_selector_t *required
);

void v1_volume_node_affinity_free(v1_volume_node_affinity_t *v1_volume_node_affinity);

v1_volume_node_affinity_t *v1_volume_node_affinity_parseFromJSON(cJSON *v1_volume_node_affinityJSON);

cJSON *v1_volume_node_affinity_convertToJSON(v1_volume_node_affinity_t *v1_volume_node_affinity);

#endif /* _v1_volume_node_affinity_H_ */

