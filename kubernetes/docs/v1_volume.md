# v1_volume_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**aws_elastic_block_store** | [**v1_aws_elastic_block_store_volume_source_t**](v1_aws_elastic_block_store_volume_source.md) \* |  | [optional] 
**azure_disk** | [**v1_azure_disk_volume_source_t**](v1_azure_disk_volume_source.md) \* |  | [optional] 
**azure_file** | [**v1_azure_file_volume_source_t**](v1_azure_file_volume_source.md) \* |  | [optional] 
**cephfs** | [**v1_ceph_fs_volume_source_t**](v1_ceph_fs_volume_source.md) \* |  | [optional] 
**cinder** | [**v1_cinder_volume_source_t**](v1_cinder_volume_source.md) \* |  | [optional] 
**config_map** | [**v1_config_map_volume_source_t**](v1_config_map_volume_source.md) \* |  | [optional] 
**csi** | [**v1_csi_volume_source_t**](v1_csi_volume_source.md) \* |  | [optional] 
**downward_api** | [**v1_downward_api_volume_source_t**](v1_downward_api_volume_source.md) \* |  | [optional] 
**empty_dir** | [**v1_empty_dir_volume_source_t**](v1_empty_dir_volume_source.md) \* |  | [optional] 
**fc** | [**v1_fc_volume_source_t**](v1_fc_volume_source.md) \* |  | [optional] 
**flex_volume** | [**v1_flex_volume_source_t**](v1_flex_volume_source.md) \* |  | [optional] 
**flocker** | [**v1_flocker_volume_source_t**](v1_flocker_volume_source.md) \* |  | [optional] 
**gce_persistent_disk** | [**v1_gce_persistent_disk_volume_source_t**](v1_gce_persistent_disk_volume_source.md) \* |  | [optional] 
**git_repo** | [**v1_git_repo_volume_source_t**](v1_git_repo_volume_source.md) \* |  | [optional] 
**glusterfs** | [**v1_glusterfs_volume_source_t**](v1_glusterfs_volume_source.md) \* |  | [optional] 
**host_path** | [**v1_host_path_volume_source_t**](v1_host_path_volume_source.md) \* |  | [optional] 
**iscsi** | [**v1_iscsi_volume_source_t**](v1_iscsi_volume_source.md) \* |  | [optional] 
**name** | **char \*** | Volume&#39;s name. Must be a DNS_LABEL and unique within the pod. More info: https://kubernetes.io/docs/concepts/overview/working-with-objects/names/#names | 
**nfs** | [**v1_nfs_volume_source_t**](v1_nfs_volume_source.md) \* |  | [optional] 
**persistent_volume_claim** | [**v1_persistent_volume_claim_volume_source_t**](v1_persistent_volume_claim_volume_source.md) \* |  | [optional] 
**photon_persistent_disk** | [**v1_photon_persistent_disk_volume_source_t**](v1_photon_persistent_disk_volume_source.md) \* |  | [optional] 
**portworx_volume** | [**v1_portworx_volume_source_t**](v1_portworx_volume_source.md) \* |  | [optional] 
**projected** | [**v1_projected_volume_source_t**](v1_projected_volume_source.md) \* |  | [optional] 
**quobyte** | [**v1_quobyte_volume_source_t**](v1_quobyte_volume_source.md) \* |  | [optional] 
**rbd** | [**v1_rbd_volume_source_t**](v1_rbd_volume_source.md) \* |  | [optional] 
**scale_io** | [**v1_scale_io_volume_source_t**](v1_scale_io_volume_source.md) \* |  | [optional] 
**secret** | [**v1_secret_volume_source_t**](v1_secret_volume_source.md) \* |  | [optional] 
**storageos** | [**v1_storage_os_volume_source_t**](v1_storage_os_volume_source.md) \* |  | [optional] 
**vsphere_volume** | [**v1_vsphere_virtual_disk_volume_source_t**](v1_vsphere_virtual_disk_volume_source.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


