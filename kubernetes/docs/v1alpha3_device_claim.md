# v1alpha3_device_claim_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**config** | [**list_t**](v1alpha3_device_claim_configuration.md) \* | This field holds configuration for multiple potential drivers which could satisfy requests in this claim. It is ignored while allocating the claim. | [optional] 
**constraints** | [**list_t**](v1alpha3_device_constraint.md) \* | These constraints must be satisfied by the set of devices that get allocated for the claim. | [optional] 
**requests** | [**list_t**](v1alpha3_device_request.md) \* | Requests represent individual requests for distinct devices which must all be satisfied. If empty, nothing needs to be allocated. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


