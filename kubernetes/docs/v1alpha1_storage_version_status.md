# v1alpha1_storage_version_status_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**common_encoding_version** | **char \*** | If all API server instances agree on the same encoding storage version, then this field is set to that version. Otherwise this field is left empty. API servers should finish updating its storageVersionStatus entry before serving write operations, so that this field will be in sync with the reality. | [optional] 
**conditions** | [**list_t**](v1alpha1_storage_version_condition.md) \* | The latest available observations of the storageVersion&#39;s state. | [optional] 
**storage_versions** | [**list_t**](v1alpha1_server_storage_version.md) \* | The reported versions per API server instance. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


