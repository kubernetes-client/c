# v2beta1_metric_status_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**container_resource** | [**v2beta1_container_resource_metric_status_t**](v2beta1_container_resource_metric_status.md) \* |  | [optional] 
**external** | [**v2beta1_external_metric_status_t**](v2beta1_external_metric_status.md) \* |  | [optional] 
**object** | [**v2beta1_object_metric_status_t**](v2beta1_object_metric_status.md) \* |  | [optional] 
**pods** | [**v2beta1_pods_metric_status_t**](v2beta1_pods_metric_status.md) \* |  | [optional] 
**resource** | [**v2beta1_resource_metric_status_t**](v2beta1_resource_metric_status.md) \* |  | [optional] 
**type** | **char \*** | type is the type of metric source.  It will be one of \&quot;ContainerResource\&quot;, \&quot;External\&quot;, \&quot;Object\&quot;, \&quot;Pods\&quot; or \&quot;Resource\&quot;, each corresponds to a matching field in the object. Note: \&quot;ContainerResource\&quot; type is available on when the feature-gate HPAContainerMetrics is enabled | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


