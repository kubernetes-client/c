# v2beta1_container_resource_metric_source_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**container** | **char \*** | container is the name of the container in the pods of the scaling target | 
**name** | **char \*** | name is the name of the resource in question. | 
**target_average_utilization** | **int** | targetAverageUtilization is the target value of the average of the resource metric across all relevant pods, represented as a percentage of the requested value of the resource for the pods. | [optional] 
**target_average_value** | **char \*** | targetAverageValue is the target value of the average of the resource metric across all relevant pods, as a raw value (instead of as a percentage of the request), similar to the \&quot;pods\&quot; metric source type. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


