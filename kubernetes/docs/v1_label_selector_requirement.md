# v1_label_selector_requirement_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**key** | **char \*** | key is the label key that the selector applies to. | 
**_operator** | **char \*** | operator represents a key&#39;s relationship to a set of values. Valid operators are In, NotIn, Exists and DoesNotExist. | 
**values** | **list_t \*** | values is an array of string values. If the operator is In or NotIn, the values array must be non-empty. If the operator is Exists or DoesNotExist, the values array must be empty. This array is replaced during a strategic merge patch. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


