# v1_api_resource_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**categories** | **list_t \*** | categories is a list of the grouped resources this resource belongs to (e.g. &#39;all&#39;) | [optional] 
**group** | **char \*** | group is the preferred group of the resource.  Empty implies the group of the containing resource list. For subresources, this may have a different value, for example: Scale\&quot;. | [optional] 
**kind** | **char \*** | kind is the kind for the resource (e.g. &#39;Foo&#39; is the kind for a resource &#39;foo&#39;) | 
**name** | **char \*** | name is the plural name of the resource. | 
**namespaced** | **int** | namespaced indicates if a resource is namespaced or not. | 
**short_names** | **list_t \*** | shortNames is a list of suggested short names of the resource. | [optional] 
**singular_name** | **char \*** | singularName is the singular name of the resource.  This allows clients to handle plural and singular opaquely. The singularName is more correct for reporting status on a single item and both singular and plural are allowed from the kubectl CLI interface. | 
**storage_version_hash** | **char \*** | The hash value of the storage version, the version this resource is converted to when written to the data store. Value must be treated as opaque by clients. Only equality comparison on the value is valid. This is an alpha feature and may change or be removed in the future. The field is populated by the apiserver only if the StorageVersionHash feature gate is enabled. This field will remain optional even if it graduates. | [optional] 
**verbs** | **list_t \*** | verbs is a list of supported kube verbs (this includes get, list, watch, create, update, patch, delete, deletecollection, and proxy) | 
**version** | **char \*** | version is the preferred version of the resource.  Empty implies the version of the containing resource list For subresources, this may have a different value, for example: v1 (while inside a v1beta1 version of the core resource&#39;s group)\&quot;. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


