/*
 * v1_container_state.h
 *
 * ContainerState holds a possible state of container. Only one of its members may be specified. If none of them is specified, the default one is ContainerStateWaiting.
 */

#ifndef _v1_container_state_H_
#define _v1_container_state_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_container_state_t v1_container_state_t;

#include "v1_container_state_running.h"
#include "v1_container_state_terminated.h"
#include "v1_container_state_waiting.h"



typedef struct v1_container_state_t {
    struct v1_container_state_running_t *running; //model
    struct v1_container_state_terminated_t *terminated; //model
    struct v1_container_state_waiting_t *waiting; //model

} v1_container_state_t;

v1_container_state_t *v1_container_state_create(
    v1_container_state_running_t *running,
    v1_container_state_terminated_t *terminated,
    v1_container_state_waiting_t *waiting
);

void v1_container_state_free(v1_container_state_t *v1_container_state);

v1_container_state_t *v1_container_state_parseFromJSON(cJSON *v1_container_stateJSON);

cJSON *v1_container_state_convertToJSON(v1_container_state_t *v1_container_state);

#endif /* _v1_container_state_H_ */

