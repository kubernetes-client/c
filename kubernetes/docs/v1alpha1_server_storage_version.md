# v1alpha1_server_storage_version_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**api_server_id** | **char \*** | apiServerID is the ID of the reporting API server. | 
**decodable_versions** | **list_t \*** | decodableVersions are the encoding versions the API server can handle to decode. The API server can decode objects encoded in these versions. The encodingVersion must be included in the decodableVersions. | 
**encoding_version** | **char \*** | encodingVersion the API server encodes the object to when persisting it in the backend (e.g., etcd). | 
**served_versions** | **list_t \*** | servedVersions lists all versions the API server can serve. DecodableVersions must include all ServedVersions. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


