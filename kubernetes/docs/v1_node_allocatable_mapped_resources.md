# v1_node_allocatable_mapped_resources_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**name** | **char \*** | Name is the name of the resource (e.g., cpu, memory). | 
**quantity** | **char \*** | Quantity is the total node allocatable resource capacity allocated for the claim. This claim&#39;s allocated devices is shared by all the containers referencing the claim. Kubelet adds this value to both requests and limits at the pod-level cgroup, and to limits at the container-level cgroup for each container referencing the claim. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


