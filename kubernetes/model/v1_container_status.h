/*
 * v1_container_status.h
 *
 * ContainerStatus contains details for the current status of this container.
 */

#ifndef _v1_container_status_H_
#define _v1_container_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_container_status_t v1_container_status_t;

#include "v1_container_state.h"



typedef struct v1_container_status_t {
    char *container_id; // string
    char *image; // string
    char *image_id; // string
    struct v1_container_state_t *last_state; //model
    char *name; // string
    int ready; //boolean
    int restart_count; //numeric
    int started; //boolean
    struct v1_container_state_t *state; //model

} v1_container_status_t;

v1_container_status_t *v1_container_status_create(
    char *container_id,
    char *image,
    char *image_id,
    v1_container_state_t *last_state,
    char *name,
    int ready,
    int restart_count,
    int started,
    v1_container_state_t *state
);

void v1_container_status_free(v1_container_status_t *v1_container_status);

v1_container_status_t *v1_container_status_parseFromJSON(cJSON *v1_container_statusJSON);

cJSON *v1_container_status_convertToJSON(v1_container_status_t *v1_container_status);

#endif /* _v1_container_status_H_ */

