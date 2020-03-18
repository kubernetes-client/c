/*
 * v1beta1_csi_node_spec.h
 *
 * CSINodeSpec holds information about the specification of all CSI drivers installed on a node
 */

#ifndef _v1beta1_csi_node_spec_H_
#define _v1beta1_csi_node_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "v1beta1_csi_node_driver.h"



typedef struct v1beta1_csi_node_spec_t {
    list_t *drivers; //nonprimitive container

} v1beta1_csi_node_spec_t;

v1beta1_csi_node_spec_t *v1beta1_csi_node_spec_create(
    list_t *drivers
);

void v1beta1_csi_node_spec_free(v1beta1_csi_node_spec_t *v1beta1_csi_node_spec);

v1beta1_csi_node_spec_t *v1beta1_csi_node_spec_parseFromJSON(cJSON *v1beta1_csi_node_specJSON);

cJSON *v1beta1_csi_node_spec_convertToJSON(v1beta1_csi_node_spec_t *v1beta1_csi_node_spec);

#endif /* _v1beta1_csi_node_spec_H_ */

