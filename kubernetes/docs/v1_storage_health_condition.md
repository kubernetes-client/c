# v1_storage_health_condition_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**access_mode** | **char \*** | accessMode is the access mode affected. Nil means all access modes are affected. | [optional] 
**last_transition_time** | **char \*** | lastTransitionTime is when this condition first appeared at its current state. | [optional] 
**message** | **char \*** | message is a human-readable description. Maximum permitted length of a message is 1024 characters. | [optional] 
**reason** | **char \*** | reason is a brief CamelCase machine-parseable reason. Maximum permitted length of a reason is 256 characters. | 
**status** | **char \*** | status is the health status category. One of \&quot;StorageUnreachable\&quot;, \&quot;StorageDegraded\&quot;. | 
**volume_mode** | **char \*** | volumeMode is the volume mode affected. Nil means both are affected. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


