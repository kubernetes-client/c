# v1_scale_io_volume_source_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**fs_type** | **char \*** | Filesystem type to mount. Must be a filesystem type supported by the host operating system. Ex. \&quot;ext4\&quot;, \&quot;xfs\&quot;, \&quot;ntfs\&quot;. Default is \&quot;xfs\&quot;. | [optional] 
**gateway** | **char \*** | The host address of the ScaleIO API Gateway. | 
**protection_domain** | **char \*** | The name of the ScaleIO Protection Domain for the configured storage. | [optional] 
**read_only** | **int** | Defaults to false (read/write). ReadOnly here will force the ReadOnly setting in VolumeMounts. | [optional] 
**secret_ref** | [**v1_local_object_reference_t**](v1_local_object_reference.md) \* |  | 
**ssl_enabled** | **int** | Flag to enable/disable SSL communication with Gateway, default false | [optional] 
**storage_mode** | **char \*** | Indicates whether the storage for a volume should be ThickProvisioned or ThinProvisioned. Default is ThinProvisioned. | [optional] 
**storage_pool** | **char \*** | The ScaleIO Storage Pool associated with the protection domain. | [optional] 
**system** | **char \*** | The name of the storage system as configured in ScaleIO. | 
**volume_name** | **char \*** | The name of a volume already created in the ScaleIO system that is associated with this volume source. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


