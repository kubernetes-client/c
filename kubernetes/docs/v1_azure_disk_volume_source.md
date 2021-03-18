# v1_azure_disk_volume_source_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**caching_mode** | **char \*** | Host Caching mode: None, Read Only, Read Write. | [optional] 
**disk_name** | **char \*** | The Name of the data disk in the blob storage | 
**disk_uri** | **char \*** | The URI the data disk in the blob storage | 
**fs_type** | **char \*** | Filesystem type to mount. Must be a filesystem type supported by the host operating system. Ex. \&quot;ext4\&quot;, \&quot;xfs\&quot;, \&quot;ntfs\&quot;. Implicitly inferred to be \&quot;ext4\&quot; if unspecified. | [optional] 
**kind** | **char \*** | Expected values Shared: multiple blob disks per storage account  Dedicated: single blob disk per storage account  Managed: azure managed data disk (only in managed availability set). defaults to shared | [optional] 
**read_only** | **int** | Defaults to false (read/write). ReadOnly here will force the ReadOnly setting in VolumeMounts. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


