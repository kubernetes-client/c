# v1alpha1_resource_class_parameters_reference_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**api_group** | **char \*** | APIGroup is the group for the resource being referenced. It is empty for the core API. This matches the group in the APIVersion that is used when creating the resources. | [optional] 
**kind** | **char \*** | Kind is the type of resource being referenced. This is the same value as in the parameter object&#39;s metadata. | 
**name** | **char \*** | Name is the name of resource being referenced. | 
**_namespace** | **char \*** | Namespace that contains the referenced resource. Must be empty for cluster-scoped resources and non-empty for namespaced resources. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


