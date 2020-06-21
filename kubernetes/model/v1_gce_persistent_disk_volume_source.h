/*
 * v1_gce_persistent_disk_volume_source.h
 *
 * Represents a Persistent Disk resource in Google Compute Engine.  A GCE PD must exist before mounting to a container. The disk must also be in the same GCE project and zone as the kubelet. A GCE PD can only be mounted as read/write once or read-only many times. GCE PDs support ownership management and SELinux relabeling.
 */

#ifndef _v1_gce_persistent_disk_volume_source_H_
#define _v1_gce_persistent_disk_volume_source_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_gce_persistent_disk_volume_source_t v1_gce_persistent_disk_volume_source_t;




typedef struct v1_gce_persistent_disk_volume_source_t {
    char *fs_type; // string
    int partition; //numeric
    char *pd_name; // string
    int read_only; //boolean

} v1_gce_persistent_disk_volume_source_t;

v1_gce_persistent_disk_volume_source_t *v1_gce_persistent_disk_volume_source_create(
    char *fs_type,
    int partition,
    char *pd_name,
    int read_only
);

void v1_gce_persistent_disk_volume_source_free(v1_gce_persistent_disk_volume_source_t *v1_gce_persistent_disk_volume_source);

v1_gce_persistent_disk_volume_source_t *v1_gce_persistent_disk_volume_source_parseFromJSON(cJSON *v1_gce_persistent_disk_volume_sourceJSON);

cJSON *v1_gce_persistent_disk_volume_source_convertToJSON(v1_gce_persistent_disk_volume_source_t *v1_gce_persistent_disk_volume_source);

#endif /* _v1_gce_persistent_disk_volume_source_H_ */

