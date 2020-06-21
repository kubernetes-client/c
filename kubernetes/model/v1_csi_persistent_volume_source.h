/*
 * v1_csi_persistent_volume_source.h
 *
 * Represents storage that is managed by an external CSI volume driver (Beta feature)
 */

#ifndef _v1_csi_persistent_volume_source_H_
#define _v1_csi_persistent_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_csi_persistent_volume_source_t v1_csi_persistent_volume_source_t;

#include "v1_secret_reference.h"



typedef struct v1_csi_persistent_volume_source_t {
    struct v1_secret_reference_t *controller_expand_secret_ref; //model
    struct v1_secret_reference_t *controller_publish_secret_ref; //model
    char *driver; // string
    char *fs_type; // string
    struct v1_secret_reference_t *node_publish_secret_ref; //model
    struct v1_secret_reference_t *node_stage_secret_ref; //model
    int read_only; //boolean
    list_t* volume_attributes; //map
    char *volume_handle; // string

} v1_csi_persistent_volume_source_t;

v1_csi_persistent_volume_source_t *v1_csi_persistent_volume_source_create(
    v1_secret_reference_t *controller_expand_secret_ref,
    v1_secret_reference_t *controller_publish_secret_ref,
    char *driver,
    char *fs_type,
    v1_secret_reference_t *node_publish_secret_ref,
    v1_secret_reference_t *node_stage_secret_ref,
    int read_only,
    list_t* volume_attributes,
    char *volume_handle
);

void v1_csi_persistent_volume_source_free(v1_csi_persistent_volume_source_t *v1_csi_persistent_volume_source);

v1_csi_persistent_volume_source_t *v1_csi_persistent_volume_source_parseFromJSON(cJSON *v1_csi_persistent_volume_sourceJSON);

cJSON *v1_csi_persistent_volume_source_convertToJSON(v1_csi_persistent_volume_source_t *v1_csi_persistent_volume_source);

#endif /* _v1_csi_persistent_volume_source_H_ */

