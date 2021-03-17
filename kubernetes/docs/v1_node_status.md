# v1_node_status_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**addresses** | [**list_t**](v1_node_address.md) \* | List of addresses reachable to the node. Queried from cloud provider, if available. More info: https://kubernetes.io/docs/concepts/nodes/node/#addresses Note: This field is declared as mergeable, but the merge key is not sufficiently unique, which can cause data corruption when it is merged. Callers should instead use a full-replacement patch. See http://pr.k8s.io/79391 for an example. | [optional] 
**allocatable** | **list_t*** | Allocatable represents the resources of a node that are available for scheduling. Defaults to Capacity. | [optional] 
**capacity** | **list_t*** | Capacity represents the total resources of a node. More info: https://kubernetes.io/docs/concepts/storage/persistent-volumes#capacity | [optional] 
**conditions** | [**list_t**](v1_node_condition.md) \* | Conditions is an array of current observed node conditions. More info: https://kubernetes.io/docs/concepts/nodes/node/#condition | [optional] 
**config** | [**v1_node_config_status_t**](v1_node_config_status.md) \* |  | [optional] 
**daemon_endpoints** | [**v1_node_daemon_endpoints_t**](v1_node_daemon_endpoints.md) \* |  | [optional] 
**images** | [**list_t**](v1_container_image.md) \* | List of container images on this node | [optional] 
**node_info** | [**v1_node_system_info_t**](v1_node_system_info.md) \* |  | [optional] 
**phase** | **char \*** | NodePhase is the recently observed lifecycle phase of the node. More info: https://kubernetes.io/docs/concepts/nodes/node/#phase The field is never populated, and now is deprecated. | [optional] 
**volumes_attached** | [**list_t**](v1_attached_volume.md) \* | List of volumes that are attached to the node. | [optional] 
**volumes_in_use** | **list_t \*** | List of attachable volumes in use (mounted) by the node. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


