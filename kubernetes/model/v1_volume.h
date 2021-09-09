/*
 * v1_volume.h
 *
 * Volume represents a named volume in a pod that may be accessed by any container in the pod.
 */

#ifndef _v1_volume_H_
#define _v1_volume_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct v1_volume_t v1_volume_t;

#include "v1_aws_elastic_block_store_volume_source.h"
#include "v1_azure_disk_volume_source.h"
#include "v1_azure_file_volume_source.h"
#include "v1_ceph_fs_volume_source.h"
#include "v1_cinder_volume_source.h"
#include "v1_config_map_volume_source.h"
#include "v1_csi_volume_source.h"
#include "v1_downward_api_volume_source.h"
#include "v1_empty_dir_volume_source.h"
#include "v1_fc_volume_source.h"
#include "v1_flex_volume_source.h"
#include "v1_flocker_volume_source.h"
#include "v1_gce_persistent_disk_volume_source.h"
#include "v1_git_repo_volume_source.h"
#include "v1_glusterfs_volume_source.h"
#include "v1_host_path_volume_source.h"
#include "v1_iscsi_volume_source.h"
#include "v1_nfs_volume_source.h"
#include "v1_persistent_volume_claim_volume_source.h"
#include "v1_photon_persistent_disk_volume_source.h"
#include "v1_portworx_volume_source.h"
#include "v1_projected_volume_source.h"
#include "v1_quobyte_volume_source.h"
#include "v1_rbd_volume_source.h"
#include "v1_scale_io_volume_source.h"
#include "v1_secret_volume_source.h"
#include "v1_storage_os_volume_source.h"
#include "v1_vsphere_virtual_disk_volume_source.h"



typedef struct v1_volume_t {
    struct v1_aws_elastic_block_store_volume_source_t *aws_elastic_block_store; //model
    struct v1_azure_disk_volume_source_t *azure_disk; //model
    struct v1_azure_file_volume_source_t *azure_file; //model
    struct v1_ceph_fs_volume_source_t *cephfs; //model
    struct v1_cinder_volume_source_t *cinder; //model
    struct v1_config_map_volume_source_t *config_map; //model
    struct v1_csi_volume_source_t *csi; //model
    struct v1_downward_api_volume_source_t *downward_api; //model
    struct v1_empty_dir_volume_source_t *empty_dir; //model
    struct v1_fc_volume_source_t *fc; //model
    struct v1_flex_volume_source_t *flex_volume; //model
    struct v1_flocker_volume_source_t *flocker; //model
    struct v1_gce_persistent_disk_volume_source_t *gce_persistent_disk; //model
    struct v1_git_repo_volume_source_t *git_repo; //model
    struct v1_glusterfs_volume_source_t *glusterfs; //model
    struct v1_host_path_volume_source_t *host_path; //model
    struct v1_iscsi_volume_source_t *iscsi; //model
    char *name; // string
    struct v1_nfs_volume_source_t *nfs; //model
    struct v1_persistent_volume_claim_volume_source_t *persistent_volume_claim; //model
    struct v1_photon_persistent_disk_volume_source_t *photon_persistent_disk; //model
    struct v1_portworx_volume_source_t *portworx_volume; //model
    struct v1_projected_volume_source_t *projected; //model
    struct v1_quobyte_volume_source_t *quobyte; //model
    struct v1_rbd_volume_source_t *rbd; //model
    struct v1_scale_io_volume_source_t *scale_io; //model
    struct v1_secret_volume_source_t *secret; //model
    struct v1_storage_os_volume_source_t *storageos; //model
    struct v1_vsphere_virtual_disk_volume_source_t *vsphere_volume; //model

} v1_volume_t;

v1_volume_t *v1_volume_create(
    v1_aws_elastic_block_store_volume_source_t *aws_elastic_block_store,
    v1_azure_disk_volume_source_t *azure_disk,
    v1_azure_file_volume_source_t *azure_file,
    v1_ceph_fs_volume_source_t *cephfs,
    v1_cinder_volume_source_t *cinder,
    v1_config_map_volume_source_t *config_map,
    v1_csi_volume_source_t *csi,
    v1_downward_api_volume_source_t *downward_api,
    v1_empty_dir_volume_source_t *empty_dir,
    v1_fc_volume_source_t *fc,
    v1_flex_volume_source_t *flex_volume,
    v1_flocker_volume_source_t *flocker,
    v1_gce_persistent_disk_volume_source_t *gce_persistent_disk,
    v1_git_repo_volume_source_t *git_repo,
    v1_glusterfs_volume_source_t *glusterfs,
    v1_host_path_volume_source_t *host_path,
    v1_iscsi_volume_source_t *iscsi,
    char *name,
    v1_nfs_volume_source_t *nfs,
    v1_persistent_volume_claim_volume_source_t *persistent_volume_claim,
    v1_photon_persistent_disk_volume_source_t *photon_persistent_disk,
    v1_portworx_volume_source_t *portworx_volume,
    v1_projected_volume_source_t *projected,
    v1_quobyte_volume_source_t *quobyte,
    v1_rbd_volume_source_t *rbd,
    v1_scale_io_volume_source_t *scale_io,
    v1_secret_volume_source_t *secret,
    v1_storage_os_volume_source_t *storageos,
    v1_vsphere_virtual_disk_volume_source_t *vsphere_volume
);

void v1_volume_free(v1_volume_t *v1_volume);

v1_volume_t *v1_volume_parseFromJSON(cJSON *v1_volumeJSON);

cJSON *v1_volume_convertToJSON(v1_volume_t *v1_volume);

#endif /* _v1_volume_H_ */

