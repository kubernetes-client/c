# v1alpha3_workload_pod_group_gang_scheduling_policy_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**min_count** | **int** | minCount is the minimum number of pods that must be scheduled at the same time for the scheduler to admit the entire group. This field is optional. If it is not specified, the controller should inject a context-specific sane default (e.g., parallelism for a Job). If set, it must be a positive integer. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


