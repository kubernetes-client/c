/*
 * v1_node_pod_preemption_policy.h
 *
 * NodePodPreemptionPolicy defines the node-level policies governing preemption for pods on this node.
 */

#ifndef _v1_node_pod_preemption_policy_H_
#define _v1_node_pod_preemption_policy_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_node_pod_preemption_policy_t v1_node_pod_preemption_policy_t;




typedef struct v1_node_pod_preemption_policy_t {
    list_t *disable_resize_preemption; //primitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1_node_pod_preemption_policy_t;

__attribute__((deprecated)) v1_node_pod_preemption_policy_t *v1_node_pod_preemption_policy_create(
    list_t *disable_resize_preemption
);

void v1_node_pod_preemption_policy_free(v1_node_pod_preemption_policy_t *v1_node_pod_preemption_policy);

v1_node_pod_preemption_policy_t *v1_node_pod_preemption_policy_parseFromJSON(cJSON *v1_node_pod_preemption_policyJSON);

cJSON *v1_node_pod_preemption_policy_convertToJSON(v1_node_pod_preemption_policy_t *v1_node_pod_preemption_policy);

#endif /* _v1_node_pod_preemption_policy_H_ */

