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


// Enum CONDITIONTYPE for v1_pod_readiness_gate

typedef enum  { kubernetes_v1_pod_readiness_gate_CONDITIONTYPE_NULL = 0, kubernetes_v1_pod_readiness_gate_CONDITIONTYPE_ContainersReady, kubernetes_v1_pod_readiness_gate_CONDITIONTYPE_Initialized, kubernetes_v1_pod_readiness_gate_CONDITIONTYPE_PodScheduled, kubernetes_v1_pod_readiness_gate_CONDITIONTYPE_Ready } kubernetes_v1_pod_readiness_gate_CONDITIONTYPE_e;

char* v1_pod_readiness_gate_condition_type_ToString(kubernetes_v1_pod_readiness_gate_CONDITIONTYPE_e condition_type);

kubernetes_v1_pod_readiness_gate_CONDITIONTYPE_e v1_pod_readiness_gate_condition_type_FromString(char* condition_type);



typedef struct v1_pod_readiness_gate_t {
    kubernetes_v1_pod_readiness_gate_CONDITIONTYPE_e condition_type; //enum

} v1_pod_readiness_gate_t;

v1_pod_readiness_gate_t *v1_pod_readiness_gate_create(
    kubernetes_v1_pod_readiness_gate_CONDITIONTYPE_e condition_type
);

void v1_pod_readiness_gate_free(v1_pod_readiness_gate_t *v1_pod_readiness_gate);

v1_pod_readiness_gate_t *v1_pod_readiness_gate_parseFromJSON(cJSON *v1_pod_readiness_gateJSON);

cJSON *v1_pod_readiness_gate_convertToJSON(v1_pod_readiness_gate_t *v1_pod_readiness_gate);

#endif /* _v1_pod_readiness_gate_H_ */

