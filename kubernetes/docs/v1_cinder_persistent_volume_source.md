# v1_cinder_persistent_volume_source_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**fs_type** | **char \*** | Filesystem type to mount. Must be a filesystem type supported by the host operating system. Examples: \&quot;ext4\&quot;, \&quot;xfs\&quot;, \&quot;ntfs\&quot;. Implicitly inferred to be \&quot;ext4\&quot; if unspecified. More info: https://examples.k8s.io/mysql-cinder-pd/README.md | [optional] 
**read_only** | **int** | Optional: Defaults to false (read/write). ReadOnly here will force the ReadOnly setting in VolumeMounts. More info: https://examples.k8s.io/mysql-cinder-pd/README.md | [optional] 
**secret_ref** | [**v1_secret_reference_t**](v1_secret_reference.md) \* |  | [optional] 
**volume_id** | **char \*** | volume id used to identify the volume in cinder. More info: https://examples.k8s.io/mysql-cinder-pd/README.md | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


