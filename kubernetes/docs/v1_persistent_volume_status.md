# v1_persistent_volume_status_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**last_phase_transition_time** | **char \*** | lastPhaseTransitionTime is the time the phase transitioned from one to another and automatically resets to current time everytime a volume phase transitions. | [optional] 
**message** | **char \*** | message is a human-readable message indicating details about why the volume is in this state. | [optional] 
**phase** | **char \*** | phase indicates if a volume is available, bound to a claim, or released by a claim. More info: https://kubernetes.io/docs/concepts/storage/persistent-volumes#phase | [optional] 
**reason** | **char \*** | reason is a brief CamelCase string that describes any failure and is meant for machine parsing and tidy display in the CLI. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


