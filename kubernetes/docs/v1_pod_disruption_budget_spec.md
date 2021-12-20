# v1_pod_disruption_budget_spec_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**max_unavailable** | **int_or_string_t \*** | IntOrString is a type that can hold an int32 or a string.  When used in JSON or YAML marshalling and unmarshalling, it produces or consumes the inner type.  This allows you to have, for example, a JSON field that can accept a name or number. | [optional] 
**min_available** | **int_or_string_t \*** | IntOrString is a type that can hold an int32 or a string.  When used in JSON or YAML marshalling and unmarshalling, it produces or consumes the inner type.  This allows you to have, for example, a JSON field that can accept a name or number. | [optional] 
**selector** | [**v1_label_selector_t**](v1_label_selector.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


