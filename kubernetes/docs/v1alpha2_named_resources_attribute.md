# v1alpha2_named_resources_attribute_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**_bool** | **int** | BoolValue is a true/false value. | [optional] 
**_int** | **long** | IntValue is a 64-bit integer. | [optional] 
**int_slice** | [**v1alpha2_named_resources_int_slice_t**](v1alpha2_named_resources_int_slice.md) \* |  | [optional] 
**name** | **char \*** | Name is unique identifier among all resource instances managed by the driver on the node. It must be a DNS subdomain. | 
**quantity** | **char \*** | QuantityValue is a quantity. | [optional] 
**string** | **char \*** | StringValue is a string. | [optional] 
**string_slice** | [**v1alpha2_named_resources_string_slice_t**](v1alpha2_named_resources_string_slice.md) \* |  | [optional] 
**version** | **char \*** | VersionValue is a semantic version according to semver.org spec 2.0.0. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


