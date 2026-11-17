# v1_node_allocatable_resource_claim_status_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**containers** | **list_t \*** | Containers lists the names of all containers in this pod that reference the claim. | [optional] 
**mapping** | [**list_t**](v1_node_allocatable_mapped_resources.md) \* | Mapping contains allocations through devices mapped in the device spec&#39;s &#x60;nodeAllocatableResources[...].mapping&#x60; field. This is used by kubelet for pod level and container-level cgroup enforcement. | [optional] 
**overhead** | [**list_t**](v1_node_allocatable_overhead_resources.md) \* | Overhead contains allocations through devices mapped in the device spec&#39;s &#x60;nodeAllocatableResources[...].overhead&#x60; field. This is used by kubelet for pod level and container-level cgroup enforcement. | [optional] 
**resource_claim_name** | **char \*** | ResourceClaimName is the resource claim referenced by the pod that resulted in this node allocatable resource allocation. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


