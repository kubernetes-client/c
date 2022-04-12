/*
 * v1_pod_condition.h
 *
 * PodCondition contains details for the current condition of this pod.
 */

#ifndef _v1_pod_condition_H_
#define _v1_pod_condition_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_pod_condition_t v1_pod_condition_t;


// Enum TYPE for v1_pod_condition

typedef enum  { kubernetes_v1_pod_condition_TYPE_NULL = 0, kubernetes_v1_pod_condition_TYPE_ContainersReady, kubernetes_v1_pod_condition_TYPE_Initialized, kubernetes_v1_pod_condition_TYPE_PodScheduled, kubernetes_v1_pod_condition_TYPE_Ready } kubernetes_v1_pod_condition_TYPE_e;

char* v1_pod_condition_type_ToString(kubernetes_v1_pod_condition_TYPE_e type);

kubernetes_v1_pod_condition_TYPE_e v1_pod_condition_type_FromString(char* type);



typedef struct v1_pod_condition_t {
    char *last_probe_time; //date time
    char *last_transition_time; //date time
    char *message; // string
    char *reason; // string
    char *status; // string
    kubernetes_v1_pod_condition_TYPE_e type; //enum

} v1_pod_condition_t;

v1_pod_condition_t *v1_pod_condition_create(
    char *last_probe_time,
    char *last_transition_time,
    char *message,
    char *reason,
    char *status,
    kubernetes_v1_pod_condition_TYPE_e type
);

void v1_pod_condition_free(v1_pod_condition_t *v1_pod_condition);

v1_pod_condition_t *v1_pod_condition_parseFromJSON(cJSON *v1_pod_conditionJSON);

cJSON *v1_pod_condition_convertToJSON(v1_pod_condition_t *v1_pod_condition);

#endif /* _v1_pod_condition_H_ */

