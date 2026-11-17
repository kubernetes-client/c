# v1_node_allocatable_overhead_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**per_container** | **char \*** | PerContainer is applied per container reference to the claim. This models overhead scaling linearly with the number of containers actively using the device. When both PerPod and PerContainer are specified, the total overhead allocated for each pod referencing the claim is computed as: Quantity &#x3D; PerPod + (PerContainer * NumReferences) Kubelet accounts for this overhead in cgroups: - Pod-level cgroup (requests and limits): Kubelet adds PerPod + (PerContainer * NumReferences). - Container-level cgroup (limits only): Kubelet adds PerPod + PerContainer for each referencing container. This allows any single container to access the pod-level overhead, while the parent cgroup caps the total usage to account for PerPod exactly once. | [optional] 
**per_pod** | **char \*** | PerPod is overhead applied once per pod referencing the claim on this node. This is a flat overhead incurred for every pod referencing the claim. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


