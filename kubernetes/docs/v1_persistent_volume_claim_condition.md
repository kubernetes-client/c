# v1_persistent_volume_claim_condition_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**last_probe_time** | **char \*** | Last time we probed the condition. | [optional] 
**last_transition_time** | **char \*** | Last time the condition transitioned from one status to another. | [optional] 
**message** | **char \*** | Human-readable message indicating details about last transition. | [optional] 
**reason** | **char \*** | Unique, this should be a short, machine understandable string that gives the reason for condition&#39;s last transition. If it reports \&quot;ResizeStarted\&quot; that means the underlying persistent volume is being resized. | [optional] 
**status** | **char \*** |  | 
**type** | **char \*** |  | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


