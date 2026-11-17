# v1alpha1_requester_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**intent** | **char \*** | intent specifies the action that should be taken for the specified target.  - Eviction means that the requester is interested in the eviction of the target. - Withdrawn means that the requester is no longer interested in the eviction of the target.   If all requesters&#39; intents are withdrawn, the eviction will be canceled.   Cancellation consequences:   - Inactive responders will never run.   - Active responders are expected to cancel the eviction.   - Completed or Interrupted responders should not take any action. | 
**name** | **char \*** | name allows you to identify the entity, that requested the eviction of the target.  It must be a valid domain-prefixed key (such as \&quot;acme.io/foo\&quot;). This field must be unique for each requester. This field is required. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


