/*
 * v1beta1_csi_node.h
 *
 * DEPRECATED - This group version of CSINode is deprecated by storage/v1/CSINode. See the release notes for more information. CSINode holds information about all CSI drivers installed on a node. CSI drivers do not need to create the CSINode object directly. As long as they use the node-driver-registrar sidecar container, the kubelet will automatically populate the CSINode object for the CSI driver as part of kubelet plugin registration. CSINode has the same name as a node. If the object is missing, it means either there are no CSI Drivers available on the node, or the Kubelet version is low enough that it doesn&#39;t create this object. CSINode has an OwnerReference that points to the corresponding node object.
 */

#ifndef _v1beta1_csi_node_H_
#define _v1beta1_csi_node_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_csi_node_t v1beta1_csi_node_t;

#include "v1_object_meta.h"
#include "v1beta1_csi_node_spec.h"



typedef struct v1beta1_csi_node_t {
    char *api_version; // string
    char *kind; // string
    struct v1_object_meta_t *metadata; //model
    struct v1beta1_csi_node_spec_t *spec; //model

} v1beta1_csi_node_t;

v1beta1_csi_node_t *v1beta1_csi_node_create(
    char *api_version,
    char *kind,
    v1_object_meta_t *metadata,
    v1beta1_csi_node_spec_t *spec
);

void v1beta1_csi_node_free(v1beta1_csi_node_t *v1beta1_csi_node);

v1beta1_csi_node_t *v1beta1_csi_node_parseFromJSON(cJSON *v1beta1_csi_nodeJSON);

cJSON *v1beta1_csi_node_convertToJSON(v1beta1_csi_node_t *v1beta1_csi_node);

#endif /* _v1beta1_csi_node_H_ */

