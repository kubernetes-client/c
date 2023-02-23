# v1alpha1_validating_admission_policy_spec_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**failure_policy** | **char \*** | FailurePolicy defines how to handle failures for the admission policy. Failures can occur from invalid or mis-configured policy definitions or bindings. A policy is invalid if spec.paramKind refers to a non-existent Kind. A binding is invalid if spec.paramRef.name refers to a non-existent resource. Allowed values are Ignore or Fail. Defaults to Fail. | [optional] 
**match_constraints** | [**v1alpha1_match_resources_t**](v1alpha1_match_resources.md) \* |  | [optional] 
**param_kind** | [**v1alpha1_param_kind_t**](v1alpha1_param_kind.md) \* |  | [optional] 
**validations** | [**list_t**](v1alpha1_validation.md) \* | Validations contain CEL expressions which is used to apply the validation. A minimum of one validation is required for a policy definition. Required. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


