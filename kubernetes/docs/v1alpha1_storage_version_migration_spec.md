# v1alpha1_storage_version_migration_spec_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**continue_token** | **char \*** | The token used in the list options to get the next chunk of objects to migrate. When the .status.conditions indicates the migration is \&quot;Running\&quot;, users can use this token to check the progress of the migration. | [optional] 
**resource** | [**v1alpha1_group_version_resource_t**](v1alpha1_group_version_resource.md) \* |  | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


