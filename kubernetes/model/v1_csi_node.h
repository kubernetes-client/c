/*
 * v1_csi_node.h
 *
 * CSINode holds information about all CSI drivers installed on a node. CSI drivers do not need to create the CSINode object directly. As long as they use the node-driver-registrar sidecar container, the kubelet will automatically populate the CSINode object for the CSI driver as part of kubelet plugin registration. CSINode has the same name as a node. If the object is missing, it means either there are no CSI Drivers available on the node, or the Kubelet version is low enough that it doesn&#39;t create this object. CSINode has an OwnerReference that points to the corresponding node object.
 */

#ifndef _v1_csi_node_H_
#define _v1_csi_node_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_csi_node_t v1_csi_node_t;

#include "v1_csi_node_spec.h"
#include "v1_object_meta.h"



typedef struct v1_csi_node_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1_csi_node_spec_t *spec; //model

} v1_csi_node_t;

v1_csi_node_t *v1_csi_node_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1_csi_node_spec_t *spec
);

void v1_csi_node_free(v1_csi_node_t *v1_csi_node);

v1_csi_node_t *v1_csi_node_parseFromJSON(cJSON *v1_csi_nodeJSON);

cJSON *v1_csi_node_convertToJSON(v1_csi_node_t *v1_csi_node);

#endif /* _v1_csi_node_H_ */

