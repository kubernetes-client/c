# v1_subject_rules_review_status_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**evaluation_error** | **char \*** | EvaluationError can appear in combination with Rules. It indicates an error occurred during rule evaluation, such as an authorizer that doesn&#39;t support rule evaluation, and that ResourceRules and/or NonResourceRules may be incomplete. | [optional] 
**incomplete** | **int** | Incomplete is true when the rules returned by this call are incomplete. This is most commonly encountered when an authorizer, such as an external authorizer, doesn&#39;t support rules evaluation. | 
**non_resource_rules** | [**list_t**](v1_non_resource_rule.md) \* | NonResourceRules is the list of actions the subject is allowed to perform on non-resources. The list ordering isn&#39;t significant, may contain duplicates, and possibly be incomplete. | 
**resource_rules** | [**list_t**](v1_resource_rule.md) \* | ResourceRules is the list of actions the subject is allowed to perform on resources. The list ordering isn&#39;t significant, may contain duplicates, and possibly be incomplete. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


