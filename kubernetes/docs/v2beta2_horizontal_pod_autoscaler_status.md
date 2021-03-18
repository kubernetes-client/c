# v2beta2_horizontal_pod_autoscaler_status_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**conditions** | [**list_t**](v2beta2_horizontal_pod_autoscaler_condition.md) \* | conditions is the set of conditions required for this autoscaler to scale its target, and indicates whether or not those conditions are met. | 
**current_metrics** | [**list_t**](v2beta2_metric_status.md) \* | currentMetrics is the last read state of the metrics used by this autoscaler. | [optional] 
**current_replicas** | **int** | currentReplicas is current number of replicas of pods managed by this autoscaler, as last seen by the autoscaler. | 
**desired_replicas** | **int** | desiredReplicas is the desired number of replicas of pods managed by this autoscaler, as last calculated by the autoscaler. | 
**last_scale_time** | **char \*** | lastScaleTime is the last time the HorizontalPodAutoscaler scaled the number of pods, used by the autoscaler to control how often the number of pods is changed. | [optional] 
**observed_generation** | **long** | observedGeneration is the most recent generation observed by this autoscaler. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


