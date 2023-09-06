# v1alpha1_server_storage_version_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**api_server_id** | **char \*** | The ID of the reporting API server. | [optional] 
**decodable_versions** | **list_t \*** | The API server can decode objects encoded in these versions. The encodingVersion must be included in the decodableVersions. | [optional] 
**encoding_version** | **char \*** | The API server encodes the object to this version when persisting it in the backend (e.g., etcd). | [optional] 
**served_versions** | **list_t \*** | The API server can serve these versions. DecodableVersions must include all ServedVersions. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


