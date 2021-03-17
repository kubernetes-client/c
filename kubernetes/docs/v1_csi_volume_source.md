# v1_csi_volume_source_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**driver** | **char \*** | Driver is the name of the CSI driver that handles this volume. Consult with your admin for the correct name as registered in the cluster. | 
**fs_type** | **char \*** | Filesystem type to mount. Ex. \&quot;ext4\&quot;, \&quot;xfs\&quot;, \&quot;ntfs\&quot;. If not provided, the empty value is passed to the associated CSI driver which will determine the default filesystem to apply. | [optional] 
**node_publish_secret_ref** | [**v1_local_object_reference_t**](v1_local_object_reference.md) \* |  | [optional] 
**read_only** | **int** | Specifies a read-only configuration for the volume. Defaults to false (read/write). | [optional] 
**volume_attributes** | **list_t*** | VolumeAttributes stores driver-specific properties that are passed to the CSI driver. Consult your driver&#39;s documentation for supported values. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


