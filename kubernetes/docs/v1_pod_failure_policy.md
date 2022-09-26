# v1_pod_failure_policy_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**rules** | [**list_t**](v1_pod_failure_policy_rule.md) \* | A list of pod failure policy rules. The rules are evaluated in order. Once a rule matches a Pod failure, the remaining of the rules are ignored. When no rule matches the Pod failure, the default handling applies - the counter of pod failures is incremented and it is checked against the backoffLimit. At most 20 elements are allowed. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


