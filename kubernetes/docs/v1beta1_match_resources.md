# v1beta1_match_resources_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**exclude_resource_rules** | [**list_t**](v1beta1_named_rule_with_operations.md) \* | ExcludeResourceRules describes what operations on what resources/subresources the ValidatingAdmissionPolicy should not care about. The exclude rules take precedence over include rules (if a resource matches both, it is excluded) | [optional] 
**match_policy** | **char \*** | matchPolicy defines how the \&quot;MatchResources\&quot; list is used to match incoming requests. Allowed values are \&quot;Exact\&quot; or \&quot;Equivalent\&quot;.  - Exact: match a request only if it exactly matches a specified rule. For example, if deployments can be modified via apps/v1, apps/v1beta1, and extensions/v1beta1, but \&quot;rules\&quot; only included &#x60;apiGroups:[\&quot;apps\&quot;], apiVersions:[\&quot;v1\&quot;], resources: [\&quot;deployments\&quot;]&#x60;, a request to apps/v1beta1 or extensions/v1beta1 would not be sent to the ValidatingAdmissionPolicy.  - Equivalent: match a request if modifies a resource listed in rules, even via another API group or version. For example, if deployments can be modified via apps/v1, apps/v1beta1, and extensions/v1beta1, and \&quot;rules\&quot; only included &#x60;apiGroups:[\&quot;apps\&quot;], apiVersions:[\&quot;v1\&quot;], resources: [\&quot;deployments\&quot;]&#x60;, a request to apps/v1beta1 or extensions/v1beta1 would be converted to apps/v1 and sent to the ValidatingAdmissionPolicy.  Defaults to \&quot;Equivalent\&quot; | [optional] 
**namespace_selector** | [**v1_label_selector_t**](v1_label_selector.md) \* |  | [optional] 
**object_selector** | [**v1_label_selector_t**](v1_label_selector.md) \* |  | [optional] 
**resource_rules** | [**list_t**](v1beta1_named_rule_with_operations.md) \* | ResourceRules describes what operations on what resources/subresources the ValidatingAdmissionPolicy matches. The policy cares about an operation if it matches _any_ Rule. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


