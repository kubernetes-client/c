/*
 * v1_csi_volume_source.h
 *
 * Represents a source location of a volume to mount, managed by an external CSI driver
 */

#ifndef _v1_csi_volume_source_H_
#define _v1_csi_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_csi_volume_source_t v1_csi_volume_source_t;

#include "v1_local_object_reference.h"



typedef struct v1_csi_volume_source_t {
    char *driver; // string
    char *fs_type; // string
    struct v1_local_object_reference_t *node_publish_secret_ref; //model
    int read_only; //boolean
    list_t* volume_attributes; //map

} v1_csi_volume_source_t;

v1_csi_volume_source_t *v1_csi_volume_source_create(
    char *driver,
    char *fs_type,
    v1_local_object_reference_t *node_publish_secret_ref,
    int read_only,
    list_t* volume_attributes
);

void v1_csi_volume_source_free(v1_csi_volume_source_t *v1_csi_volume_source);

v1_csi_volume_source_t *v1_csi_volume_source_parseFromJSON(cJSON *v1_csi_volume_sourceJSON);

cJSON *v1_csi_volume_source_convertToJSON(v1_csi_volume_source_t *v1_csi_volume_source);

#endif /* _v1_csi_volume_source_H_ */

