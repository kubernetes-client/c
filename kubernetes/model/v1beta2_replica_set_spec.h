/*
 * v1beta2_replica_set_spec.h
 *
 * ReplicaSetSpec is the specification of a ReplicaSet.
 */

#ifndef _v1beta2_replica_set_spec_H_
#define _v1beta2_replica_set_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta2_replica_set_spec_t v1beta2_replica_set_spec_t;

#include "v1_label_selector.h"
#include "v1_pod_template_spec.h"



typedef struct v1beta2_replica_set_spec_t {
    int min_ready_seconds; //numeric
    int replicas; //numeric
    struct v1_label_selector_t *selector; //model
    struct v1_pod_template_spec_t *_template; //model

} v1beta2_replica_set_spec_t;

v1beta2_replica_set_spec_t *v1beta2_replica_set_spec_create(
    int min_ready_seconds,
    int replicas,
    v1_label_selector_t *selector,
    v1_pod_template_spec_t *_template
);

void v1beta2_replica_set_spec_free(v1beta2_replica_set_spec_t *v1beta2_replica_set_spec);

v1beta2_replica_set_spec_t *v1beta2_replica_set_spec_parseFromJSON(cJSON *v1beta2_replica_set_specJSON);

cJSON *v1beta2_replica_set_spec_convertToJSON(v1beta2_replica_set_spec_t *v1beta2_replica_set_spec);

#endif /* _v1beta2_replica_set_spec_H_ */

