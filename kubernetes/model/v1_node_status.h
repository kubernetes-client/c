/*
 * v1_node_status.h
 *
 * NodeStatus is information about the current status of a node.
 */

#ifndef _v1_node_status_H_
#define _v1_node_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_node_status_t v1_node_status_t;

#include "v1_attached_volume.h"
#include "v1_container_image.h"
#include "v1_node_address.h"
#include "v1_node_condition.h"
#include "v1_node_config_status.h"
#include "v1_node_daemon_endpoints.h"
#include "v1_node_system_info.h"



typedef struct v1_node_status_t {
    list_t *addresses; //nonprimitive container
    list_t* allocatable; //map
    list_t* capacity; //map
    list_t *conditions; //nonprimitive container
    struct v1_node_config_status_t *config; //model
    struct v1_node_daemon_endpoints_t *daemon_endpoints; //model
    list_t *images; //nonprimitive container
    struct v1_node_system_info_t *node_info; //model
    char *phase; // string
    list_t *volumes_attached; //nonprimitive container
    list_t *volumes_in_use; //primitive container

} v1_node_status_t;

v1_node_status_t *v1_node_status_create(
    list_t *addresses,
    list_t* allocatable,
    list_t* capacity,
    list_t *conditions,
    v1_node_config_status_t *config,
    v1_node_daemon_endpoints_t *daemon_endpoints,
    list_t *images,
    v1_node_system_info_t *node_info,
    char *phase,
    list_t *volumes_attached,
    list_t *volumes_in_use
);

void v1_node_status_free(v1_node_status_t *v1_node_status);

v1_node_status_t *v1_node_status_parseFromJSON(cJSON *v1_node_statusJSON);

cJSON *v1_node_status_convertToJSON(v1_node_status_t *v1_node_status);

#endif /* _v1_node_status_H_ */

