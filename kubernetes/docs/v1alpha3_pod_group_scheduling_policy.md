# v1alpha3_pod_group_scheduling_policy_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**basic** | [**object_t**](.md) \* | basic specifies that the pods in this group should be scheduled using standard Kubernetes scheduling behavior. Setting this field at group creation time opts this group to basic scheduling; this field cannot be changed afterward. | [optional] 
**gang** | [**v1alpha3_gang_scheduling_policy_t**](v1alpha3_gang_scheduling_policy.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


