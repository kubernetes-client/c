# v1alpha1_policy_rules_with_subjects_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**non_resource_rules** | [**list_t**](v1alpha1_non_resource_policy_rule.md) \* | &#x60;nonResourceRules&#x60; is a list of NonResourcePolicyRules that identify matching requests according to their verb and the target non-resource URL. | [optional] 
**resource_rules** | [**list_t**](v1alpha1_resource_policy_rule.md) \* | &#x60;resourceRules&#x60; is a slice of ResourcePolicyRules that identify matching requests according to their verb and the target resource. At least one of &#x60;resourceRules&#x60; and &#x60;nonResourceRules&#x60; has to be non-empty. | [optional] 
**subjects** | [**list_t**](flowcontrol_v1alpha1_subject.md) \* | subjects is the list of normal user, serviceaccount, or group that this rule cares about. There must be at least one member in this slice. A slice that includes both the system:authenticated and system:unauthenticated user groups matches every request. Required. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


