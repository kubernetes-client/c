/*
 * v1_container_state_running.h
 *
 * ContainerStateRunning is a running state of a container.
 */

#ifndef _v1_container_state_running_H_
#define _v1_container_state_running_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_container_state_running_t v1_container_state_running_t;




typedef struct v1_container_state_running_t {
    char *started_at; //date time

} v1_container_state_running_t;

v1_container_state_running_t *v1_container_state_running_create(
    char *started_at
);

void v1_container_state_running_free(v1_container_state_running_t *v1_container_state_running);

v1_container_state_running_t *v1_container_state_running_parseFromJSON(cJSON *v1_container_state_runningJSON);

cJSON *v1_container_state_running_convertToJSON(v1_container_state_running_t *v1_container_state_running);

#endif /* _v1_container_state_running_H_ */

