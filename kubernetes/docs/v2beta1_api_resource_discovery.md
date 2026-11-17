# v2beta1_api_resource_discovery_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**resource** | **char \*** | resource is the plural name of the resource. | 
**response_kind** | [**v1_group_version_kind_t**](v1_group_version_kind.md) \* |  | [optional] 
**scope** | **char \*** | scope indicates the scope of a resource, either Cluster or Namespaced | 
**singular_resource** | **char \*** | singularResource is the singular name of the resource. | 
**verbs** | **list_t \*** | verbs is a list of supported API operation types | 
**short_names** | **list_t \*** | shortNames is a list of suggested short names of the resource. | [optional] 
**categories** | **list_t \*** | categories is a list of the grouped resources this resource belongs to. | [optional] 
**subresources** | [**list_t**](v2beta1_api_subresource_discovery.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


