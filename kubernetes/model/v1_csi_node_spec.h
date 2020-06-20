/*
 * v1_csi_node_spec.h
 *
 * CSINodeSpec holds information about the specification of all CSI drivers installed on a node
 */

#ifndef _v1_csi_node_spec_H_
#define _v1_csi_node_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_csi_node_spec_t v1_csi_node_spec_t;

#include "v1_csi_node_driver.h"



typedef struct v1_csi_node_spec_t {
    list_t *drivers; //nonprimitive container

} v1_csi_node_spec_t;

v1_csi_node_spec_t *v1_csi_node_spec_create(
    list_t *drivers
);

void v1_csi_node_spec_free(v1_csi_node_spec_t *v1_csi_node_spec);

v1_csi_node_spec_t *v1_csi_node_spec_parseFromJSON(cJSON *v1_csi_node_specJSON);

cJSON *v1_csi_node_spec_convertToJSON(v1_csi_node_spec_t *v1_csi_node_spec);

#endif /* _v1_csi_node_spec_H_ */

