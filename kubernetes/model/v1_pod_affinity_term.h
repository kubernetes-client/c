/*
 * v1_pod_affinity_term.h
 *
 * Defines a set of pods (namely those matching the labelSelector relative to the given namespace(s)) that this pod should be co-located (affinity) or not co-located (anti-affinity) with, where co-located is defined as running on a node whose value of the label with key &lt;topologyKey&gt; matches that of any node on which a pod of the set of pods is running
 */

#ifndef _v1_pod_affinity_term_H_
#define _v1_pod_affinity_term_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_pod_affinity_term_t v1_pod_affinity_term_t;

#include "v1_label_selector.h"



typedef struct v1_pod_affinity_term_t {
    struct v1_label_selector_t *label_selector; //model
    list_t *namespaces; //primitive container
    char *topology_key; // string

} v1_pod_affinity_term_t;

v1_pod_affinity_term_t *v1_pod_affinity_term_create(
    v1_label_selector_t *label_selector,
    list_t *namespaces,
    char *topology_key
);

void v1_pod_affinity_term_free(v1_pod_affinity_term_t *v1_pod_affinity_term);

v1_pod_affinity_term_t *v1_pod_affinity_term_parseFromJSON(cJSON *v1_pod_affinity_termJSON);

cJSON *v1_pod_affinity_term_convertToJSON(v1_pod_affinity_term_t *v1_pod_affinity_term);

#endif /* _v1_pod_affinity_term_H_ */

