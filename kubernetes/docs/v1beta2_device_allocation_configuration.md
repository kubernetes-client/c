# v1beta2_device_allocation_configuration_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**opaque** | [**v1beta2_opaque_device_configuration_t**](v1beta2_opaque_device_configuration.md) \* |  | [optional] 
**requests** | **list_t \*** | Requests lists the names of requests where the configuration applies. If empty, its applies to all requests.  References to subrequests must include the name of the main request and may include the subrequest using the format &lt;main request&gt;[/&lt;subrequest&gt;]. If just the main request is given, the configuration applies to all subrequests. | [optional] 
**source** | **char \*** | Source records whether the configuration comes from a class and thus is not something that a normal user would have been able to set or from a claim. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


