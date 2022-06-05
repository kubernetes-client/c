# v1_csi_persistent_volume_source_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**controller_expand_secret_ref** | [**v1_secret_reference_t**](v1_secret_reference.md) \* |  | [optional] 
**controller_publish_secret_ref** | [**v1_secret_reference_t**](v1_secret_reference.md) \* |  | [optional] 
**driver** | **char \*** | driver is the name of the driver to use for this volume. Required. | 
**fs_type** | **char \*** | fsType to mount. Must be a filesystem type supported by the host operating system. Ex. \&quot;ext4\&quot;, \&quot;xfs\&quot;, \&quot;ntfs\&quot;. | [optional] 
**node_publish_secret_ref** | [**v1_secret_reference_t**](v1_secret_reference.md) \* |  | [optional] 
**node_stage_secret_ref** | [**v1_secret_reference_t**](v1_secret_reference.md) \* |  | [optional] 
**read_only** | **int** | readOnly value to pass to ControllerPublishVolumeRequest. Defaults to false (read/write). | [optional] 
**volume_attributes** | **list_t*** | volumeAttributes of the volume to publish. | [optional] 
**volume_handle** | **char \*** | volumeHandle is the unique volume name returned by the CSI volume plugin’s CreateVolume to refer to the volume on all subsequent calls. Required. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


