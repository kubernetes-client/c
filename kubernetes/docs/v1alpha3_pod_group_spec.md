# v1alpha3_pod_group_spec_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**disruption_mode** | [**v1alpha3_disruption_mode_t**](v1alpha3_disruption_mode.md) \* |  | [optional] 
**parent_composite_pod_group_name** | **char \*** | parentCompositePodGroupName contains the name of the parent composite pod group within the same namespace as this pod group. If it&#39;s nil, then this pod group is a root of a workload&#39;s hierarchy. This field is used only when the CompositePodGroup feature gate is enabled. This field is immutable. | [optional] 
**preemption_policy** | **char \*** | preemptionPolicy is the Policy for preempting pods/podgroups with lower priority. One of Never, PreemptLowerPriority. Defaults to PreemptLowerPriority if unset. When Priority Admission Controller is enabled, it populates this field from PriorityClassName, and defaults to PreemptLowerPriority if value is unset in PriorityClass. This field is immutable. This field is available only when the PodGroupPreemptionPolicy feature gate is enabled. | [optional] 
**priority** | **int** | priority is the value of priority of this pod group. Various system components use this field to find the priority of the pod group. When Priority Admission Controller is enabled, it prevents users from setting this field. The admission controller populates this field from PriorityClassName. The higher the value, the higher the priority. This field is immutable. | [optional] 
**priority_class_name** | **char \*** | priorityClassName defines the priority that should be considered when scheduling this pod group. Controllers are expected to fill this field by copying it from a PodGroupTemplate. Otherwise, it is validated and resolved similarly to the PriorityClassName on PodGroupTemplate (i.e. if no priority class is specified, admission control can set this to the global default priority class if it exists. Otherwise, the pod group&#39;s priority will be zero). This field is immutable. | [optional] 
**resource_claims** | [**list_t**](v1alpha3_pod_group_resource_claim.md) \* | resourceClaims defines which ResourceClaims may be shared among Pods in the group. Pods consume the devices allocated to a PodGroup&#39;s claim by defining a claim in its own Spec.ResourceClaims that matches the PodGroup&#39;s claim exactly. The claim must have the same name and refer to the same ResourceClaim or ResourceClaimTemplate.  This is a beta-level field and requires that the DRAWorkloadResourceClaims feature gate is enabled.  This field is immutable. | [optional] 
**scheduling_constraints** | [**v1alpha3_pod_group_scheduling_constraints_t**](v1alpha3_pod_group_scheduling_constraints.md) \* |  | [optional] 
**scheduling_policy** | [**v1alpha3_pod_group_scheduling_policy_t**](v1alpha3_pod_group_scheduling_policy.md) \* |  | 
**workload_ref** | [**v1alpha3_workload_reference_t**](v1alpha3_workload_reference.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


