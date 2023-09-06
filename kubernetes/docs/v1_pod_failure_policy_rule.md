# v1_pod_failure_policy_rule_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**action** | **char \*** | Specifies the action taken on a pod failure when the requirements are satisfied. Possible values are:  - FailJob: indicates that the pod&#39;s job is marked as Failed and all   running pods are terminated. - FailIndex: indicates that the pod&#39;s index is marked as Failed and will   not be restarted.   This value is alpha-level. It can be used when the   &#x60;JobBackoffLimitPerIndex&#x60; feature gate is enabled (disabled by default). - Ignore: indicates that the counter towards the .backoffLimit is not   incremented and a replacement pod is created. - Count: indicates that the pod is handled in the default way - the   counter towards the .backoffLimit is incremented. Additional values are considered to be added in the future. Clients should react to an unknown action by skipping the rule. | 
**on_exit_codes** | [**v1_pod_failure_policy_on_exit_codes_requirement_t**](v1_pod_failure_policy_on_exit_codes_requirement.md) \* |  | [optional] 
**on_pod_conditions** | [**list_t**](v1_pod_failure_policy_on_pod_conditions_pattern.md) \* | Represents the requirement on the pod conditions. The requirement is represented as a list of pod condition patterns. The requirement is satisfied if at least one pattern matches an actual pod condition. At most 20 elements are allowed. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


