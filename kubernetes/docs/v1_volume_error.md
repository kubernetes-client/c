# v1_volume_error_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**error_code** | **int** | errorCode is a numeric gRPC code representing the error encountered during Attach or Detach operations.  This is an optional, alpha field that requires the MutableCSINodeAllocatableCount feature gate being enabled to be set. | [optional] 
**message** | **char \*** | message represents the error encountered during Attach or Detach operation. This string may be logged, so it should not contain sensitive information. | [optional] 
**time** | **char \*** | time represents the time the error was encountered. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


