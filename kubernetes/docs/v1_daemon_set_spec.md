# v1_daemon_set_spec_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**min_ready_seconds** | **int** | The minimum number of seconds for which a newly created DaemonSet pod should be ready without any of its container crashing, for it to be considered available. Defaults to 0 (pod will be considered available as soon as it is ready). | [optional] 
**revision_history_limit** | **int** | The number of old history to retain to allow rollback. This is a pointer to distinguish between explicit zero and not specified. Defaults to 10. | [optional] 
**selector** | [**v1_label_selector_t**](v1_label_selector.md) \* |  | 
**_template** | [**v1_pod_template_spec_t**](v1_pod_template_spec.md) \* |  | 
**update_strategy** | [**v1_daemon_set_update_strategy_t**](v1_daemon_set_update_strategy.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


