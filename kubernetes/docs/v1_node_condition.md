# v1_node_condition_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**last_heartbeat_time** | **char \*** | Last time we got an update on a given condition. | [optional] 
**last_transition_time** | **char \*** | Last time the condition transit from one status to another. | [optional] 
**message** | **char \*** | Human readable message indicating details about last transition. | [optional] 
**reason** | **char \*** | (brief) reason for the condition&#39;s last transition. | [optional] 
**status** | **char \*** | Status of the condition, one of True, False, Unknown. | 
**type** | **kubernetes_v1_node_condition_TYPE_e** | Type of node condition.  Possible enum values:  - &#x60;\&quot;DiskPressure\&quot;&#x60; means the kubelet is under pressure due to insufficient available disk.  - &#x60;\&quot;MemoryPressure\&quot;&#x60; means the kubelet is under pressure due to insufficient available memory.  - &#x60;\&quot;NetworkUnavailable\&quot;&#x60; means that network for the node is not correctly configured.  - &#x60;\&quot;PIDPressure\&quot;&#x60; means the kubelet is under pressure due to insufficient available PID.  - &#x60;\&quot;Ready\&quot;&#x60; means kubelet is healthy and ready to accept pods. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


