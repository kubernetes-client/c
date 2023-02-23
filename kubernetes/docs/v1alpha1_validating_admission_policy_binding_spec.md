# v1alpha1_validating_admission_policy_binding_spec_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**match_resources** | [**v1alpha1_match_resources_t**](v1alpha1_match_resources.md) \* |  | [optional] 
**param_ref** | [**v1alpha1_param_ref_t**](v1alpha1_param_ref.md) \* |  | [optional] 
**policy_name** | **char \*** | PolicyName references a ValidatingAdmissionPolicy name which the ValidatingAdmissionPolicyBinding binds to. If the referenced resource does not exist, this binding is considered invalid and will be ignored Required. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


