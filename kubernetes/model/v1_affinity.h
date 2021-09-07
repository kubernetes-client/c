/*
 * v1_affinity.h
 *
 * Affinity is a group of affinity scheduling rules.
 */

#ifndef _v1_affinity_H_
#define _v1_affinity_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_affinity_t v1_affinity_t;

#include "v1_node_affinity.h"
#include "v1_pod_affinity.h"
#include "v1_pod_anti_affinity.h"



typedef struct v1_affinity_t {
    struct v1_node_affinity_t *node_affinity; //model
    struct v1_pod_affinity_t *pod_affinity; //model
    struct v1_pod_anti_affinity_t *pod_anti_affinity; //model

} v1_affinity_t;

v1_affinity_t *v1_affinity_create(
    v1_node_affinity_t *node_affinity,
    v1_pod_affinity_t *pod_affinity,
    v1_pod_anti_affinity_t *pod_anti_affinity
);

void v1_affinity_free(v1_affinity_t *v1_affinity);

v1_affinity_t *v1_affinity_parseFromJSON(cJSON *v1_affinityJSON);

cJSON *v1_affinity_convertToJSON(v1_affinity_t *v1_affinity);

#endif /* _v1_affinity_H_ */

