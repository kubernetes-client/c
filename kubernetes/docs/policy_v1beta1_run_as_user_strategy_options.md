# policy_v1beta1_run_as_user_strategy_options_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**ranges** | [**list_t**](policy_v1beta1_id_range.md) \* | ranges are the allowed ranges of uids that may be used. If you would like to force a single uid then supply a single range with the same start and end. Required for MustRunAs. | [optional] 
**rule** | **char \*** | rule is the strategy that will dictate the allowable RunAsUser values that may be set. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


