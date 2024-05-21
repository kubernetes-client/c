# v1alpha1_storage_version_migration_status_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**conditions** | [**list_t**](v1alpha1_migration_condition.md) \* | The latest available observations of the migration&#39;s current state. | [optional] 
**resource_version** | **char \*** | ResourceVersion to compare with the GC cache for performing the migration. This is the current resource version of given group, version and resource when kube-controller-manager first observes this StorageVersionMigration resource. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


