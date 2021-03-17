# v2beta2_metric_target_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**average_utilization** | **int** | averageUtilization is the target value of the average of the resource metric across all relevant pods, represented as a percentage of the requested value of the resource for the pods. Currently only valid for Resource metric source type | [optional] 
**average_value** | **char \*** | averageValue is the target value of the average of the metric across all relevant pods (as a quantity) | [optional] 
**type** | **char \*** | type represents whether the metric type is Utilization, Value, or AverageValue | 
**value** | **char \*** | value is the target value of the metric (as a quantity). | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


