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
#include "v1_container_user.h"
#include "v1_resource_requirements.h"
#include "v1_resource_status.h"
#include "v1_volume_mount_status.h"



typedef struct v1_container_status_t {
    list_t* allocated_resources; //map
    list_t *allocated_resources_status; //nonprimitive container
    char *container_id; // string
    char *image; // string
    char *image_id; // string
    struct v1_container_state_t *last_state; //model
    char *name; // string
    int ready; //boolean
    struct v1_resource_requirements_t *resources; //model
    int restart_count; //numeric
    int started; //boolean
    struct v1_container_state_t *state; //model
    struct v1_container_user_t *user; //model
    list_t *volume_mounts; //nonprimitive container

} v1_container_status_t;

v1_container_status_t *v1_container_status_create(
    list_t* allocated_resources,
    list_t *allocated_resources_status,
    char *container_id,
    char *image,
    char *image_id,
    v1_container_state_t *last_state,
    char *name,
    int ready,
    v1_resource_requirements_t *resources,
    int restart_count,
    int started,
    v1_container_state_t *state,
    v1_container_user_t *user,
    list_t *volume_mounts
);

void v1_container_status_free(v1_container_status_t *v1_container_status);

v1_container_status_t *v1_container_status_parseFromJSON(cJSON *v1_container_statusJSON);

cJSON *v1_container_status_convertToJSON(v1_container_status_t *v1_container_status);

#endif /* _v1_container_status_H_ */

