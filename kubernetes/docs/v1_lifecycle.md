# v1_lifecycle_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**post_start** | [**v1_lifecycle_handler_t**](v1_lifecycle_handler.md) \* |  | [optional] 
**pre_stop** | [**v1_lifecycle_handler_t**](v1_lifecycle_handler.md) \* |  | [optional] 
**stop_signal** | **char \*** | StopSignal defines which signal will be sent to a container when it is being stopped. If not specified, the default is defined by the container runtime in use. StopSignal can only be set for Pods with a non-empty .spec.os.name | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


