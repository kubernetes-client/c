# v1beta1_capacity_request_policy_range_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**max** | **char \*** | Max defines the upper limit for capacity that can be requested.  Max must be less than or equal to the capacity value. Min and requestPolicy.default must be less than or equal to the maximum. | [optional] 
**min** | **char \*** | Min specifies the minimum capacity allowed for a consumption request.  Min must be greater than or equal to zero, and less than or equal to the capacity value. requestPolicy.default must be more than or equal to the minimum. | 
**step** | **char \*** | Step defines the step size between valid capacity amounts within the range.  Max (if set) and requestPolicy.default must be a multiple of Step. Min + Step must be less than or equal to the capacity value. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


