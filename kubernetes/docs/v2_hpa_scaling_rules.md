# v2_hpa_scaling_rules_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**policies** | [**list_t**](v2_hpa_scaling_policy.md) \* | policies is a list of potential scaling polices which can be used during scaling. If not set, use the default values: - For scale up: allow doubling the number of pods, or an absolute change of 4 pods in a 15s window. - For scale down: allow all pods to be removed in a 15s window. | [optional] 
**select_policy** | **char \*** | selectPolicy is used to specify which policy should be used. If not set, the default value Max is used. | [optional] 
**stabilization_window_seconds** | **int** | stabilizationWindowSeconds is the number of seconds for which past recommendations should be considered while scaling up or scaling down. StabilizationWindowSeconds must be greater than or equal to zero and less than or equal to 3600 (one hour). If not set, use the default values: - For scale up: 0 (i.e. no stabilization is done). - For scale down: 300 (i.e. the stabilization window is 300 seconds long). | [optional] 
**tolerance** | **char \*** | tolerance is the tolerance on the ratio between the current and desired metric value under which no updates are made to the desired number of replicas (e.g. 0.01 for 1%). Must be greater than or equal to zero. If not set, the default cluster-wide tolerance is applied (by default 10%).  For example, if autoscaling is configured with a memory consumption target of 100Mi, and scale-down and scale-up tolerances of 5% and 1% respectively, scaling will be triggered when the actual consumption falls below 95Mi or exceeds 101Mi.  This is an alpha field and requires enabling the HPAConfigurableTolerance feature gate. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


