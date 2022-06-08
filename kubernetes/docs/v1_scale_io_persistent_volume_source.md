# v1_scale_io_persistent_volume_source_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**fs_type** | **char \*** | fsType is the filesystem type to mount. Must be a filesystem type supported by the host operating system. Ex. \&quot;ext4\&quot;, \&quot;xfs\&quot;, \&quot;ntfs\&quot;. Default is \&quot;xfs\&quot; | [optional] 
**gateway** | **char \*** | gateway is the host address of the ScaleIO API Gateway. | 
**protection_domain** | **char \*** | protectionDomain is the name of the ScaleIO Protection Domain for the configured storage. | [optional] 
**read_only** | **int** | readOnly defaults to false (read/write). ReadOnly here will force the ReadOnly setting in VolumeMounts. | [optional] 
**secret_ref** | [**v1_secret_reference_t**](v1_secret_reference.md) \* |  | 
**ssl_enabled** | **int** | sslEnabled is the flag to enable/disable SSL communication with Gateway, default false | [optional] 
**storage_mode** | **char \*** | storageMode indicates whether the storage for a volume should be ThickProvisioned or ThinProvisioned. Default is ThinProvisioned. | [optional] 
**storage_pool** | **char \*** | storagePool is the ScaleIO Storage Pool associated with the protection domain. | [optional] 
**system** | **char \*** | system is the name of the storage system as configured in ScaleIO. | 
**volume_name** | **char \*** | volumeName is the name of a volume already created in the ScaleIO system that is associated with this volume source. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


