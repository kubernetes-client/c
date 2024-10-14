# v1alpha3_device_class_spec_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**config** | [**list_t**](v1alpha3_device_class_configuration.md) \* | Config defines configuration parameters that apply to each device that is claimed via this class. Some classses may potentially be satisfied by multiple drivers, so each instance of a vendor configuration applies to exactly one driver.  They are passed to the driver, but are not considered while allocating the claim. | [optional] 
**selectors** | [**list_t**](v1alpha3_device_selector.md) \* | Each selector must be satisfied by a device which is claimed via this class. | [optional] 
**suitable_nodes** | [**v1_node_selector_t**](v1_node_selector.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


