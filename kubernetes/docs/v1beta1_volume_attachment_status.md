# v1beta1_volume_attachment_status_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**attach_error** | [**v1beta1_volume_error_t**](v1beta1_volume_error.md) \* |  | [optional] 
**attached** | **int** | Indicates the volume is successfully attached. This field must only be set by the entity completing the attach operation, i.e. the external-attacher. | 
**attachment_metadata** | **list_t*** | Upon successful attach, this field is populated with any information returned by the attach operation that must be passed into subsequent WaitForAttach or Mount calls. This field must only be set by the entity completing the attach operation, i.e. the external-attacher. | [optional] 
**detach_error** | [**v1beta1_volume_error_t**](v1beta1_volume_error.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


