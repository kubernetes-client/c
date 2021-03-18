# v1_resource_quota_spec_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**hard** | **list_t*** | hard is the set of desired hard limits for each named resource. More info: https://kubernetes.io/docs/concepts/policy/resource-quotas/ | [optional] 
**scope_selector** | [**v1_scope_selector_t**](v1_scope_selector.md) \* |  | [optional] 
**scopes** | **list_t \*** | A collection of filters that must match each object tracked by a quota. If not specified, the quota matches all objects. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


