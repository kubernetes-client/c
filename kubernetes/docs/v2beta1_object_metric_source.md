# v2beta1_object_metric_source_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**average_value** | **char \*** | averageValue is the target value of the average of the metric across all relevant pods (as a quantity) | [optional] 
**metric_name** | **char \*** | metricName is the name of the metric in question. | 
**selector** | [**v1_label_selector_t**](v1_label_selector.md) \* |  | [optional] 
**target** | [**v2beta1_cross_version_object_reference_t**](v2beta1_cross_version_object_reference.md) \* |  | 
**target_value** | **char \*** | targetValue is the target value of the metric (as a quantity). | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


