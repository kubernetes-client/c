/*
 * v1_container_state_waiting.h
 *
 * ContainerStateWaiting is a waiting state of a container.
 */

#ifndef _v1_container_state_waiting_H_
#define _v1_container_state_waiting_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_container_state_waiting_t v1_container_state_waiting_t;




typedef struct v1_container_state_waiting_t {
    char *message; // string
    char *reason; // string

    int _library_owned; // Is the library responsible for freeing this object?
} v1_container_state_waiting_t;

__attribute__((deprecated)) v1_container_state_waiting_t *v1_container_state_waiting_create(
    char *message,
    char *reason
);

void v1_container_state_waiting_free(v1_container_state_waiting_t *v1_container_state_waiting);

v1_container_state_waiting_t *v1_container_state_waiting_parseFromJSON(cJSON *v1_container_state_waitingJSON);

cJSON *v1_container_state_waiting_convertToJSON(v1_container_state_waiting_t *v1_container_state_waiting);

#endif /* _v1_container_state_waiting_H_ */

