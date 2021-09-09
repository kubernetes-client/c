/*
 * v1_probe.h
 *
 * Probe describes a health check to be performed against a container to determine whether it is alive or ready to receive traffic.
 */

#ifndef _v1_probe_H_
#define _v1_probe_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_probe_t v1_probe_t;

#include "v1_exec_action.h"
#include "v1_http_get_action.h"
#include "v1_tcp_socket_action.h"



typedef struct v1_probe_t {
    struct v1_exec_action_t *exec; //model
    int failure_threshold; //numeric
    struct v1_http_get_action_t *http_get; //model
    int initial_delay_seconds; //numeric
    int period_seconds; //numeric
    int success_threshold; //numeric
    struct v1_tcp_socket_action_t *tcp_socket; //model
    int timeout_seconds; //numeric

} v1_probe_t;

v1_probe_t *v1_probe_create(
    v1_exec_action_t *exec,
    int failure_threshold,
    v1_http_get_action_t *http_get,
    int initial_delay_seconds,
    int period_seconds,
    int success_threshold,
    v1_tcp_socket_action_t *tcp_socket,
    int timeout_seconds
);

void v1_probe_free(v1_probe_t *v1_probe);

v1_probe_t *v1_probe_parseFromJSON(cJSON *v1_probeJSON);

cJSON *v1_probe_convertToJSON(v1_probe_t *v1_probe);

#endif /* _v1_probe_H_ */

