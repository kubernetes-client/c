# v1beta1_custom_resource_definition_status_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**accepted_names** | [**v1beta1_custom_resource_definition_names_t**](v1beta1_custom_resource_definition_names.md) \* |  | 
**conditions** | [**list_t**](v1beta1_custom_resource_definition_condition.md) \* | conditions indicate state for particular aspects of a CustomResourceDefinition | [optional] 
**stored_versions** | **list_t \*** | storedVersions lists all versions of CustomResources that were ever persisted. Tracking these versions allows a migration path for stored versions in etcd. The field is mutable so a migration controller can finish a migration to another version (ensuring no old objects are left in storage), and then remove the rest of the versions from this list. Versions may not be removed from &#x60;spec.versions&#x60; while they exist in this list. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


