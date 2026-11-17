# v1_volume_health_status_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**health_conditions** | [**list_t**](v1_volume_health_condition.md) \* | conditions is the set of adverse conditions reported by the CSI controller plugin. An empty list means no adverse condition. At most 16 conditions may be reported. | [optional] 
**last_transition_time** | **char \*** | lastTransitionTime is when the current set of conditions first appeared. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


