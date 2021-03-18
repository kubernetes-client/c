# v1_persistent_volume_spec_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**access_modes** | **list_t \*** | AccessModes contains all ways the volume can be mounted. More info: https://kubernetes.io/docs/concepts/storage/persistent-volumes#access-modes | [optional] 
**aws_elastic_block_store** | [**v1_aws_elastic_block_store_volume_source_t**](v1_aws_elastic_block_store_volume_source.md) \* |  | [optional] 
**azure_disk** | [**v1_azure_disk_volume_source_t**](v1_azure_disk_volume_source.md) \* |  | [optional] 
**azure_file** | [**v1_azure_file_persistent_volume_source_t**](v1_azure_file_persistent_volume_source.md) \* |  | [optional] 
**capacity** | **list_t*** | A description of the persistent volume&#39;s resources and capacity. More info: https://kubernetes.io/docs/concepts/storage/persistent-volumes#capacity | [optional] 
**cephfs** | [**v1_ceph_fs_persistent_volume_source_t**](v1_ceph_fs_persistent_volume_source.md) \* |  | [optional] 
**cinder** | [**v1_cinder_persistent_volume_source_t**](v1_cinder_persistent_volume_source.md) \* |  | [optional] 
**claim_ref** | [**v1_object_reference_t**](v1_object_reference.md) \* |  | [optional] 
**csi** | [**v1_csi_persistent_volume_source_t**](v1_csi_persistent_volume_source.md) \* |  | [optional] 
**fc** | [**v1_fc_volume_source_t**](v1_fc_volume_source.md) \* |  | [optional] 
**flex_volume** | [**v1_flex_persistent_volume_source_t**](v1_flex_persistent_volume_source.md) \* |  | [optional] 
**flocker** | [**v1_flocker_volume_source_t**](v1_flocker_volume_source.md) \* |  | [optional] 
**gce_persistent_disk** | [**v1_gce_persistent_disk_volume_source_t**](v1_gce_persistent_disk_volume_source.md) \* |  | [optional] 
**glusterfs** | [**v1_glusterfs_persistent_volume_source_t**](v1_glusterfs_persistent_volume_source.md) \* |  | [optional] 
**host_path** | [**v1_host_path_volume_source_t**](v1_host_path_volume_source.md) \* |  | [optional] 
**iscsi** | [**v1_iscsi_persistent_volume_source_t**](v1_iscsi_persistent_volume_source.md) \* |  | [optional] 
**local** | [**v1_local_volume_source_t**](v1_local_volume_source.md) \* |  | [optional] 
**mount_options** | **list_t \*** | A list of mount options, e.g. [\&quot;ro\&quot;, \&quot;soft\&quot;]. Not validated - mount will simply fail if one is invalid. More info: https://kubernetes.io/docs/concepts/storage/persistent-volumes/#mount-options | [optional] 
**nfs** | [**v1_nfs_volume_source_t**](v1_nfs_volume_source.md) \* |  | [optional] 
**node_affinity** | [**v1_volume_node_affinity_t**](v1_volume_node_affinity.md) \* |  | [optional] 
**persistent_volume_reclaim_policy** | **char \*** | What happens to a persistent volume when released from its claim. Valid options are Retain (default for manually created PersistentVolumes), Delete (default for dynamically provisioned PersistentVolumes), and Recycle (deprecated). Recycle must be supported by the volume plugin underlying this PersistentVolume. More info: https://kubernetes.io/docs/concepts/storage/persistent-volumes#reclaiming | [optional] 
**photon_persistent_disk** | [**v1_photon_persistent_disk_volume_source_t**](v1_photon_persistent_disk_volume_source.md) \* |  | [optional] 
**portworx_volume** | [**v1_portworx_volume_source_t**](v1_portworx_volume_source.md) \* |  | [optional] 
**quobyte** | [**v1_quobyte_volume_source_t**](v1_quobyte_volume_source.md) \* |  | [optional] 
**rbd** | [**v1_rbd_persistent_volume_source_t**](v1_rbd_persistent_volume_source.md) \* |  | [optional] 
**scale_io** | [**v1_scale_io_persistent_volume_source_t**](v1_scale_io_persistent_volume_source.md) \* |  | [optional] 
**storage_class_name** | **char \*** | Name of StorageClass to which this persistent volume belongs. Empty value means that this volume does not belong to any StorageClass. | [optional] 
**storageos** | [**v1_storage_os_persistent_volume_source_t**](v1_storage_os_persistent_volume_source.md) \* |  | [optional] 
**volume_mode** | **char \*** | volumeMode defines if a volume is intended to be used with a formatted filesystem or to remain in raw block state. Value of Filesystem is implied when not included in spec. This is a beta feature. | [optional] 
**vsphere_volume** | [**v1_vsphere_virtual_disk_volume_source_t**](v1_vsphere_virtual_disk_volume_source.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


