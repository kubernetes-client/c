/*
 * v1_pod_status.h
 *
 * PodStatus represents information about the status of a pod. Status may trail the actual state of a system, especially if the node that hosts the pod cannot contact the control plane.
 */

#ifndef _v1_pod_status_H_
#define _v1_pod_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_pod_status_t v1_pod_status_t;

#include "v1_container_status.h"
#include "v1_pod_condition.h"
#include "v1_pod_ip.h"

// Enum PHASE for v1_pod_status

typedef enum  { kubernetes_v1_pod_status_PHASE_NULL = 0, kubernetes_v1_pod_status_PHASE_Failed, kubernetes_v1_pod_status_PHASE_Pending, kubernetes_v1_pod_status_PHASE_Running, kubernetes_v1_pod_status_PHASE_Succeeded, kubernetes_v1_pod_status_PHASE_Unknown } kubernetes_v1_pod_status_PHASE_e;

char* v1_pod_status_phase_ToString(kubernetes_v1_pod_status_PHASE_e phase);

kubernetes_v1_pod_status_PHASE_e v1_pod_status_phase_FromString(char* phase);

// Enum QOSCLASS for v1_pod_status

typedef enum  { kubernetes_v1_pod_status_QOSCLASS_NULL = 0, kubernetes_v1_pod_status_QOSCLASS_BestEffort, kubernetes_v1_pod_status_QOSCLASS_Burstable, kubernetes_v1_pod_status_QOSCLASS_Guaranteed } kubernetes_v1_pod_status_QOSCLASS_e;

char* v1_pod_status_qos_class_ToString(kubernetes_v1_pod_status_QOSCLASS_e qos_class);

kubernetes_v1_pod_status_QOSCLASS_e v1_pod_status_qos_class_FromString(char* qos_class);



typedef struct v1_pod_status_t {
    list_t *conditions; //nonprimitive container
    list_t *container_statuses; //nonprimitive container
    list_t *ephemeral_container_statuses; //nonprimitive container
    char *host_ip; // string
    list_t *init_container_statuses; //nonprimitive container
    char *message; // string
    char *nominated_node_name; // string
    kubernetes_v1_pod_status_PHASE_e phase; //enum
    char *pod_ip; // string
    list_t *pod_ips; //nonprimitive container
    kubernetes_v1_pod_status_QOSCLASS_e qos_class; //enum
    char *reason; // string
    char *start_time; //date time

} v1_pod_status_t;

v1_pod_status_t *v1_pod_status_create(
    list_t *conditions,
    list_t *container_statuses,
    list_t *ephemeral_container_statuses,
    char *host_ip,
    list_t *init_container_statuses,
    char *message,
    char *nominated_node_name,
    kubernetes_v1_pod_status_PHASE_e phase,
    char *pod_ip,
    list_t *pod_ips,
    kubernetes_v1_pod_status_QOSCLASS_e qos_class,
    char *reason,
    char *start_time
);

void v1_pod_status_free(v1_pod_status_t *v1_pod_status);

v1_pod_status_t *v1_pod_status_parseFromJSON(cJSON *v1_pod_statusJSON);

cJSON *v1_pod_status_convertToJSON(v1_pod_status_t *v1_pod_status);

#endif /* _v1_pod_status_H_ */

