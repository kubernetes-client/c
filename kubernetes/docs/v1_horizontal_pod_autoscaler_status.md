# v1_horizontal_pod_autoscaler_status_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**current_cpu_utilization_percentage** | **int** | currentCPUUtilizationPercentage is the current average CPU utilization over all pods, represented as a percentage of requested CPU, e.g. 70 means that an average pod is using now 70% of its requested CPU. | [optional] 
**current_replicas** | **int** | currentReplicas is the current number of replicas of pods managed by this autoscaler. | 
**desired_replicas** | **int** | desiredReplicas is the  desired number of replicas of pods managed by this autoscaler. | 
**last_scale_time** | **char \*** | lastScaleTime is the last time the HorizontalPodAutoscaler scaled the number of pods; used by the autoscaler to control how often the number of pods is changed. | [optional] 
**observed_generation** | **long** | observedGeneration is the most recent generation observed by this autoscaler. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


