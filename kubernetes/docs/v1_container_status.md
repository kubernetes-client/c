# v1_container_status_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**container_id** | **char \*** | Container&#39;s ID in the format &#39;docker://&lt;container_id&gt;&#39;. | [optional] 
**image** | **char \*** | The image the container is running. More info: https://kubernetes.io/docs/concepts/containers/images | 
**image_id** | **char \*** | ImageID of the container&#39;s image. | 
**last_state** | [**v1_container_state_t**](v1_container_state.md) \* |  | [optional] 
**name** | **char \*** | This must be a DNS_LABEL. Each container in a pod must have a unique name. Cannot be updated. | 
**ready** | **int** | Specifies whether the container has passed its readiness probe. | 
**restart_count** | **int** | The number of times the container has been restarted, currently based on the number of dead containers that have not yet been removed. Note that this is calculated from dead containers. But those containers are subject to garbage collection. This value will get capped at 5 by GC. | 
**started** | **int** | Specifies whether the container has passed its startup probe. Initialized as false, becomes true after startupProbe is considered successful. Resets to false when the container is restarted, or if kubelet loses state temporarily. Is always true when no startupProbe is defined. | [optional] 
**state** | [**v1_container_state_t**](v1_container_state.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


