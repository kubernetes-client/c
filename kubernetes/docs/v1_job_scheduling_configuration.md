# v1_job_scheduling_configuration_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**disruption_mode** | [**v1alpha3_workload_pod_group_disruption_mode_t**](v1alpha3_workload_pod_group_disruption_mode.md) \* |  | [optional] 
**resource_claims** | [**list_t**](v1alpha3_workload_pod_group_resource_claim.md) \* | ResourceClaims defines which ResourceClaims may be shared among Pods in the Job. Pods consume the devices allocated to a PodGroup&#39;s claim by defining a claim in its own Spec.ResourceClaims that matches the PodGroup&#39;s claim exactly. The claim must have the same name and refer to the same ResourceClaim or ResourceClaimTemplate. At most 4 claims may be set, matching the limit on the resulting PodGroup. This list is immutable after creation: entries may neither be added, removed, nor modified. | [optional] 
**scheduling_constraints** | [**v1alpha3_workload_pod_group_scheduling_constraints_t**](v1alpha3_workload_pod_group_scheduling_constraints.md) \* |  | [optional] 
**scheduling_policy** | [**v1alpha3_workload_pod_group_scheduling_policy_t**](v1alpha3_workload_pod_group_scheduling_policy.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


