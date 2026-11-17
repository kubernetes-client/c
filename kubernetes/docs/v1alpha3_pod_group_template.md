# v1alpha3_pod_group_template_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**disruption_mode** | [**v1alpha3_disruption_mode_t**](v1alpha3_disruption_mode.md) \* |  | [optional] 
**name** | **char \*** | name is a unique identifier for the PodGroupTemplate within the Workload. It must be a DNS label. This field is immutable. | 
**preemption_policy** | **char \*** | preemptionPolicy is the Policy for preempting pods/podgroups with lower priority. One of Never, PreemptLowerPriority. This field is immutable. This field is available only when the PodGroupPreemptionPolicy feature gate is enabled. | [optional] 
**priority** | **int** | priority is the value of priority of pod groups created from this template. Various system components use this field to find the priority of the pod group. The higher the value, the higher the priority. This field is immutable. | [optional] 
**priority_class_name** | **char \*** | priorityClassName indicates the priority that should be considered when scheduling a pod group created from this template. This field is immutable. | [optional] 
**resource_claims** | [**list_t**](v1alpha3_pod_group_resource_claim.md) \* | resourceClaims defines which ResourceClaims may be shared among Pods in the group. Pods consume the devices allocated to a PodGroup&#39;s claim by defining a claim in its own Spec.ResourceClaims that matches the PodGroup&#39;s claim exactly. The claim must have the same name and refer to the same ResourceClaim or ResourceClaimTemplate.  This is a beta-level field and requires that the DRAWorkloadResourceClaims feature gate is enabled.  This field is immutable. | [optional] 
**scheduling_constraints** | [**v1alpha3_pod_group_scheduling_constraints_t**](v1alpha3_pod_group_scheduling_constraints.md) \* |  | [optional] 
**scheduling_policy** | [**v1alpha3_pod_group_scheduling_policy_t**](v1alpha3_pod_group_scheduling_policy.md) \* |  | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


