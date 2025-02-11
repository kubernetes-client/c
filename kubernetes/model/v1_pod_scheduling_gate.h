/*
 * v1_pod_scheduling_gate.h
 *
 * PodSchedulingGate is associated to a Pod to guard its scheduling.
 */

#ifndef _v1_pod_scheduling_gate_H_
#define _v1_pod_scheduling_gate_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_pod_scheduling_gate_t v1_pod_scheduling_gate_t;




typedef struct v1_pod_scheduling_gate_t {
    char *name; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_pod_scheduling_gate_t;

__attribute__((deprecated)) v1_pod_scheduling_gate_t *v1_pod_scheduling_gate_create(
    char *name
);

void v1_pod_scheduling_gate_free(v1_pod_scheduling_gate_t *v1_pod_scheduling_gate);

v1_pod_scheduling_gate_t *v1_pod_scheduling_gate_parseFromJSON(cJSON *v1_pod_scheduling_gateJSON);

cJSON *v1_pod_scheduling_gate_convertToJSON(v1_pod_scheduling_gate_t *v1_pod_scheduling_gate);

#endif /* _v1_pod_scheduling_gate_H_ */

