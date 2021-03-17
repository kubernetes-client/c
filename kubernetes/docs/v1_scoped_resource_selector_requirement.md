# v1_scoped_resource_selector_requirement_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**_operator** | **char \*** | Represents a scope&#39;s relationship to a set of values. Valid operators are In, NotIn, Exists, DoesNotExist. | 
**scope_name** | **char \*** | The name of the scope that the selector applies to. | 
**values** | **list_t \*** | An array of string values. If the operator is In or NotIn, the values array must be non-empty. If the operator is Exists or DoesNotExist, the values array must be empty. This array is replaced during a strategic merge patch. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


