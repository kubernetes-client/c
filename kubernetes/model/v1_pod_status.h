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



typedef struct v1_pod_status_t {
    list_t *conditions; //nonprimitive container
    list_t *container_statuses; //nonprimitive container
    list_t *ephemeral_container_statuses; //nonprimitive container
    char *host_ip; // string
    list_t *init_container_statuses; //nonprimitive container
    char *message; // string
    char *nominated_node_name; // string
    char *phase; // string
    char *pod_ip; // string
    list_t *pod_ips; //nonprimitive container
    char *qos_class; // string
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
    char *phase,
    char *pod_ip,
    list_t *pod_ips,
    char *qos_class,
    char *reason,
    char *start_time
);

void v1_pod_status_free(v1_pod_status_t *v1_pod_status);

v1_pod_status_t *v1_pod_status_parseFromJSON(cJSON *v1_pod_statusJSON);

cJSON *v1_pod_status_convertToJSON(v1_pod_status_t *v1_pod_status);

#endif /* _v1_pod_status_H_ */

