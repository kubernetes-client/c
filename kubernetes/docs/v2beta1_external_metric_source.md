# v2beta1_external_metric_source_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**metric_name** | **char \*** | metricName is the name of the metric in question. | 
**metric_selector** | [**v1_label_selector_t**](v1_label_selector.md) \* |  | [optional] 
**target_average_value** | **char \*** | targetAverageValue is the target per-pod value of global metric (as a quantity). Mutually exclusive with TargetValue. | [optional] 
**target_value** | **char \*** | targetValue is the target value of the metric (as a quantity). Mutually exclusive with TargetAverageValue. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


