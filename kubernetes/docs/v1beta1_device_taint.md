# v1beta1_device_taint_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**effect** | **char \*** | The effect of the taint on claims that do not tolerate the taint and through such claims on the pods using them. Valid effects are NoSchedule and NoExecute. PreferNoSchedule as used for nodes is not valid here. | 
**key** | **char \*** | The taint key to be applied to a device. Must be a label name. | 
**time_added** | **char \*** | TimeAdded represents the time at which the taint was added. Added automatically during create or update if not set. | [optional] 
**value** | **char \*** | The taint value corresponding to the taint key. Must be a label value. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


