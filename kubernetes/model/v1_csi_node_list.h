/*
 * v1_csi_node_list.h
 *
 * CSINodeList is a collection of CSINode objects.
 */

#ifndef _v1_csi_node_list_H_
#define _v1_csi_node_list_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_csi_node_list_t v1_csi_node_list_t;

#include "v1_csi_node.h"
#include "v1_list_meta.h"



typedef struct v1_csi_node_list_t {
    char *api_version; // string
    list_t *items; //nonprimitive container
    char *kind; // string
    struct v1_list_meta_t *metadata; //model

} v1_csi_node_list_t;

v1_csi_node_list_t *v1_csi_node_list_create(
    char *api_version,
    list_t *items,
    char *kind,
    v1_list_meta_t *metadata
);

void v1_csi_node_list_free(v1_csi_node_list_t *v1_csi_node_list);

v1_csi_node_list_t *v1_csi_node_list_parseFromJSON(cJSON *v1_csi_node_listJSON);

cJSON *v1_csi_node_list_convertToJSON(v1_csi_node_list_t *v1_csi_node_list);

#endif /* _v1_csi_node_list_H_ */

