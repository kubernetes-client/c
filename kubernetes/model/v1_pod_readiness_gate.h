/*
 * v1_pod_readiness_gate.h
 *
 * PodReadinessGate contains the reference to a pod condition
 */

#ifndef _v1_pod_readiness_gate_H_
#define _v1_pod_readiness_gate_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_pod_readiness_gate_t v1_pod_readiness_gate_t;




typedef struct v1_pod_readiness_gate_t {
    char *condition_type; // string

} v1_pod_readiness_gate_t;

v1_pod_readiness_gate_t *v1_pod_readiness_gate_create(
    char *condition_type
);

void v1_pod_readiness_gate_free(v1_pod_readiness_gate_t *v1_pod_readiness_gate);

v1_pod_readiness_gate_t *v1_pod_readiness_gate_parseFromJSON(cJSON *v1_pod_readiness_gateJSON);

cJSON *v1_pod_readiness_gate_convertToJSON(v1_pod_readiness_gate_t *v1_pod_readiness_gate);

#endif /* _v1_pod_readiness_gate_H_ */

