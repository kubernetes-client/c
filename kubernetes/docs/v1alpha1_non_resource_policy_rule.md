# v1alpha1_non_resource_policy_rule_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**non_resource_urls** | **list_t \*** | &#x60;nonResourceURLs&#x60; is a set of url prefixes that a user should have access to and may not be empty. For example:   - \&quot;/healthz\&quot; is legal   - \&quot;/hea*\&quot; is illegal   - \&quot;/hea\&quot; is legal but matches nothing   - \&quot;/hea/*\&quot; also matches nothing   - \&quot;/healthz/*\&quot; matches all per-component health checks. \&quot;*\&quot; matches all non-resource urls. if it is present, it must be the only entry. Required. | 
**verbs** | **list_t \*** | &#x60;verbs&#x60; is a list of matching verbs and may not be empty. \&quot;*\&quot; matches all verbs. If it is present, it must be the only entry. Required. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


