/*
 * v1_weighted_pod_affinity_term.h
 *
 * The weights of all of the matched WeightedPodAffinityTerm fields are added per-node to find the most preferred node(s)
 */

#ifndef _v1_weighted_pod_affinity_term_H_
#define _v1_weighted_pod_affinity_term_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_weighted_pod_affinity_term_t v1_weighted_pod_affinity_term_t;

#include "v1_pod_affinity_term.h"



typedef struct v1_weighted_pod_affinity_term_t {
    struct v1_pod_affinity_term_t *pod_affinity_term; //model
    int weight; //numeric

} v1_weighted_pod_affinity_term_t;

v1_weighted_pod_affinity_term_t *v1_weighted_pod_affinity_term_create(
    v1_pod_affinity_term_t *pod_affinity_term,
    int weight
);

void v1_weighted_pod_affinity_term_free(v1_weighted_pod_affinity_term_t *v1_weighted_pod_affinity_term);

v1_weighted_pod_affinity_term_t *v1_weighted_pod_affinity_term_parseFromJSON(cJSON *v1_weighted_pod_affinity_termJSON);

cJSON *v1_weighted_pod_affinity_term_convertToJSON(v1_weighted_pod_affinity_term_t *v1_weighted_pod_affinity_term);

#endif /* _v1_weighted_pod_affinity_term_H_ */

