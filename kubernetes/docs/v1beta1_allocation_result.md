# v1beta1_allocation_result_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**allocation_timestamp** | **char \*** | AllocationTimestamp stores the time when the resources were allocated. This field is not guaranteed to be set, in which case that time is unknown.  This is an alpha field and requires enabling the DRADeviceBindingConditions and DRAResourceClaimDeviceStatus feature gate. | [optional] 
**devices** | [**v1beta1_device_allocation_result_t**](v1beta1_device_allocation_result.md) \* |  | [optional] 
**node_selector** | [**v1_node_selector_t**](v1_node_selector.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


