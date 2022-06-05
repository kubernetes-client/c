/*
 * v1beta1_csi_storage_capacity.h
 *
 * CSIStorageCapacity stores the result of one CSI GetCapacity call. For a given StorageClass, this describes the available capacity in a particular topology segment.  This can be used when considering where to instantiate new PersistentVolumes.  For example this can express things like: - StorageClass \&quot;standard\&quot; has \&quot;1234 GiB\&quot; available in \&quot;topology.kubernetes.io/zone&#x3D;us-east1\&quot; - StorageClass \&quot;localssd\&quot; has \&quot;10 GiB\&quot; available in \&quot;kubernetes.io/hostname&#x3D;knode-abc123\&quot;  The following three cases all imply that no capacity is available for a certain combination: - no object exists with suitable topology and storage class name - such an object exists, but the capacity is unset - such an object exists, but the capacity is zero  The producer of these objects can decide which approach is more suitable.  They are consumed by the kube-scheduler when a CSI driver opts into capacity-aware scheduling with CSIDriverSpec.StorageCapacity. The scheduler compares the MaximumVolumeSize against the requested size of pending volumes to filter out unsuitable nodes. If MaximumVolumeSize is unset, it falls back to a comparison against the less precise Capacity. If that is also unset, the scheduler assumes that capacity is insufficient and tries some other node.
 */

#ifndef _v1beta1_csi_storage_capacity_H_
#define _v1beta1_csi_storage_capacity_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1beta1_csi_storage_capacity_t v1beta1_csi_storage_capacity_t;

#include "v1_label_selector.h"
#include "v1_object_meta.h"



typedef struct v1beta1_csi_storage_capacity_t {
    char *api_version; // string
    char *capacity; // string
    char *kind; // string
    char *maximum_volume_size; // string
    struct v1_object_meta_t *metadata; //model
    struct v1_label_selector_t *node_topology; //model
    char *storage_class_name; // string

} v1beta1_csi_storage_capacity_t;

v1beta1_csi_storage_capacity_t *v1beta1_csi_storage_capacity_create(
    char *api_version,
    char *capacity,
    char *kind,
    char *maximum_volume_size,
    v1_object_meta_t *metadata,
    v1_label_selector_t *node_topology,
    char *storage_class_name
);

void v1beta1_csi_storage_capacity_free(v1beta1_csi_storage_capacity_t *v1beta1_csi_storage_capacity);

v1beta1_csi_storage_capacity_t *v1beta1_csi_storage_capacity_parseFromJSON(cJSON *v1beta1_csi_storage_capacityJSON);

cJSON *v1beta1_csi_storage_capacity_convertToJSON(v1beta1_csi_storage_capacity_t *v1beta1_csi_storage_capacity);

#endif /* _v1beta1_csi_storage_capacity_H_ */

