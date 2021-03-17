# v1alpha1_flow_schema_spec_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**distinguisher_method** | [**v1alpha1_flow_distinguisher_method_t**](v1alpha1_flow_distinguisher_method.md) \* |  | [optional] 
**matching_precedence** | **int** | &#x60;matchingPrecedence&#x60; is used to choose among the FlowSchemas that match a given request. The chosen FlowSchema is among those with the numerically lowest (which we take to be logically highest) MatchingPrecedence.  Each MatchingPrecedence value must be non-negative. Note that if the precedence is not specified or zero, it will be set to 1000 as default. | [optional] 
**priority_level_configuration** | [**v1alpha1_priority_level_configuration_reference_t**](v1alpha1_priority_level_configuration_reference.md) \* |  | 
**rules** | [**list_t**](v1alpha1_policy_rules_with_subjects.md) \* | &#x60;rules&#x60; describes which requests will match this flow schema. This FlowSchema matches a request if and only if at least one member of rules matches the request. if it is an empty slice, there will be no requests matching the FlowSchema. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


