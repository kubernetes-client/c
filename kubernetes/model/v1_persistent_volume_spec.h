/*
 * v1_persistent_volume_spec.h
 *
 * PersistentVolumeSpec is the specification of a persistent volume.
 */

#ifndef _v1_persistent_volume_spec_H_
#define _v1_persistent_volume_spec_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_persistent_volume_spec_t v1_persistent_volume_spec_t;

#include "v1_aws_elastic_block_store_volume_source.h"
#include "v1_azure_disk_volume_source.h"
#include "v1_azure_file_persistent_volume_source.h"
#include "v1_ceph_fs_persistent_volume_source.h"
#include "v1_cinder_persistent_volume_source.h"
#include "v1_csi_persistent_volume_source.h"
#include "v1_fc_volume_source.h"
#include "v1_flex_persistent_volume_source.h"
#include "v1_flocker_volume_source.h"
#include "v1_gce_persistent_disk_volume_source.h"
#include "v1_glusterfs_persistent_volume_source.h"
#include "v1_host_path_volume_source.h"
#include "v1_iscsi_persistent_volume_source.h"
#include "v1_local_volume_source.h"
#include "v1_nfs_volume_source.h"
#include "v1_object_reference.h"
#include "v1_photon_persistent_disk_volume_source.h"
#include "v1_portworx_volume_source.h"
#include "v1_quobyte_volume_source.h"
#include "v1_rbd_persistent_volume_source.h"
#include "v1_scale_io_persistent_volume_source.h"
#include "v1_storage_os_persistent_volume_source.h"
#include "v1_volume_node_affinity.h"
#include "v1_vsphere_virtual_disk_volume_source.h"



typedef struct v1_persistent_volume_spec_t {
    list_t *access_modes; //primitive container
    struct v1_aws_elastic_block_store_volume_source_t *aws_elastic_block_store; //model
    struct v1_azure_disk_volume_source_t *azure_disk; //model
    struct v1_azure_file_persistent_volume_source_t *azure_file; //model
    list_t* capacity; //map
    struct v1_ceph_fs_persistent_volume_source_t *cephfs; //model
    struct v1_cinder_persistent_volume_source_t *cinder; //model
    struct v1_object_reference_t *claim_ref; //model
    struct v1_csi_persistent_volume_source_t *csi; //model
    struct v1_fc_volume_source_t *fc; //model
    struct v1_flex_persistent_volume_source_t *flex_volume; //model
    struct v1_flocker_volume_source_t *flocker; //model
    struct v1_gce_persistent_disk_volume_source_t *gce_persistent_disk; //model
    struct v1_glusterfs_persistent_volume_source_t *glusterfs; //model
    struct v1_host_path_volume_source_t *host_path; //model
    struct v1_iscsi_persistent_volume_source_t *iscsi; //model
    struct v1_local_volume_source_t *local; //model
    list_t *mount_options; //primitive container
    struct v1_nfs_volume_source_t *nfs; //model
    struct v1_volume_node_affinity_t *node_affinity; //model
    char *persistent_volume_reclaim_policy; // string
    struct v1_photon_persistent_disk_volume_source_t *photon_persistent_disk; //model
    struct v1_portworx_volume_source_t *portworx_volume; //model
    struct v1_quobyte_volume_source_t *quobyte; //model
    struct v1_rbd_persistent_volume_source_t *rbd; //model
    struct v1_scale_io_persistent_volume_source_t *scale_io; //model
    char *storage_class_name; // string
    struct v1_storage_os_persistent_volume_source_t *storageos; //model
    char *volume_mode; // string
    struct v1_vsphere_virtual_disk_volume_source_t *vsphere_volume; //model

} v1_persistent_volume_spec_t;

v1_persistent_volume_spec_t *v1_persistent_volume_spec_create(
    list_t *access_modes,
    v1_aws_elastic_block_store_volume_source_t *aws_elastic_block_store,
    v1_azure_disk_volume_source_t *azure_disk,
    v1_azure_file_persistent_volume_source_t *azure_file,
    list_t* capacity,
    v1_ceph_fs_persistent_volume_source_t *cephfs,
    v1_cinder_persistent_volume_source_t *cinder,
    v1_object_reference_t *claim_ref,
    v1_csi_persistent_volume_source_t *csi,
    v1_fc_volume_source_t *fc,
    v1_flex_persistent_volume_source_t *flex_volume,
    v1_flocker_volume_source_t *flocker,
    v1_gce_persistent_disk_volume_source_t *gce_persistent_disk,
    v1_glusterfs_persistent_volume_source_t *glusterfs,
    v1_host_path_volume_source_t *host_path,
    v1_iscsi_persistent_volume_source_t *iscsi,
    v1_local_volume_source_t *local,
    list_t *mount_options,
    v1_nfs_volume_source_t *nfs,
    v1_volume_node_affinity_t *node_affinity,
    char *persistent_volume_reclaim_policy,
    v1_photon_persistent_disk_volume_source_t *photon_persistent_disk,
    v1_portworx_volume_source_t *portworx_volume,
    v1_quobyte_volume_source_t *quobyte,
    v1_rbd_persistent_volume_source_t *rbd,
    v1_scale_io_persistent_volume_source_t *scale_io,
    char *storage_class_name,
    v1_storage_os_persistent_volume_source_t *storageos,
    char *volume_mode,
    v1_vsphere_virtual_disk_volume_source_t *vsphere_volume
);

void v1_persistent_volume_spec_free(v1_persistent_volume_spec_t *v1_persistent_volume_spec);

v1_persistent_volume_spec_t *v1_persistent_volume_spec_parseFromJSON(cJSON *v1_persistent_volume_specJSON);

cJSON *v1_persistent_volume_spec_convertToJSON(v1_persistent_volume_spec_t *v1_persistent_volume_spec);

#endif /* _v1_persistent_volume_spec_H_ */

