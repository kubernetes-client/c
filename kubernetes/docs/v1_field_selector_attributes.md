# v1_field_selector_attributes_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**raw_selector** | **char \*** | rawSelector is the serialization of a field selector that would be included in a query parameter. Webhook implementations are encouraged to ignore rawSelector. The kube-apiserver&#39;s *SubjectAccessReview will parse the rawSelector as long as the requirements are not present. | [optional] 
**requirements** | [**list_t**](v1_field_selector_requirement.md) \* | requirements is the parsed interpretation of a field selector. All requirements must be met for a resource instance to match the selector. Webhook implementations should handle requirements, but how to handle them is up to the webhook. Since requirements can only limit the request, it is safe to authorize as unlimited request if the requirements are not understood. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


