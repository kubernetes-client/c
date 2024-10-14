# v1_resource_health_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**health** | **char \*** | Health of the resource. can be one of:  - Healthy: operates as normal  - Unhealthy: reported unhealthy. We consider this a temporary health issue               since we do not have a mechanism today to distinguish               temporary and permanent issues.  - Unknown: The status cannot be determined.             For example, Device Plugin got unregistered and hasn&#39;t been re-registered since.  In future we may want to introduce the PermanentlyUnhealthy Status. | [optional] 
**resource_id** | **char \*** | ResourceID is the unique identifier of the resource. See the ResourceID type for more information. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


