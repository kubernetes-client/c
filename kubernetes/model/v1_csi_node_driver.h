/*
 * v1_csi_node_driver.h
 *
 * CSINodeDriver holds information about the specification of one CSI driver installed on a node
 */

#ifndef _v1_csi_node_driver_H_
#define _v1_csi_node_driver_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_csi_node_driver_t v1_csi_node_driver_t;

#include "v1_volume_node_resources.h"



typedef struct v1_csi_node_driver_t {
    struct v1_volume_node_resources_t *allocatable; //model
    char *name; // string
    char *node_id; // string
    list_t *topology_keys; //primitive container

} v1_csi_node_driver_t;

v1_csi_node_driver_t *v1_csi_node_driver_create(
    v1_volume_node_resources_t *allocatable,
    char *name,
    char *node_id,
    list_t *topology_keys
);

void v1_csi_node_driver_free(v1_csi_node_driver_t *v1_csi_node_driver);

v1_csi_node_driver_t *v1_csi_node_driver_parseFromJSON(cJSON *v1_csi_node_driverJSON);

cJSON *v1_csi_node_driver_convertToJSON(v1_csi_node_driver_t *v1_csi_node_driver);

#endif /* _v1_csi_node_driver_H_ */

