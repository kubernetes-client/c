/*
 * v1_csi_node_status.h
 *
 * CSINodeStatus contains health and status information for storage on a node.
 */

#ifndef _v1_csi_node_status_H_
#define _v1_csi_node_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_csi_node_status_t v1_csi_node_status_t;

#include "v1_storage_health.h"



typedef struct v1_csi_node_status_t {
    list_t *storage_health; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} v1_csi_node_status_t;

__attribute__((deprecated)) v1_csi_node_status_t *v1_csi_node_status_create(
    list_t *storage_health
);

void v1_csi_node_status_free(v1_csi_node_status_t *v1_csi_node_status);

v1_csi_node_status_t *v1_csi_node_status_parseFromJSON(cJSON *v1_csi_node_statusJSON);

cJSON *v1_csi_node_status_convertToJSON(v1_csi_node_status_t *v1_csi_node_status);

#endif /* _v1_csi_node_status_H_ */

