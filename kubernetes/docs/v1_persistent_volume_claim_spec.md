# v1_persistent_volume_claim_spec_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**access_modes** | **list_t \*** | AccessModes contains the desired access modes the volume should have. More info: https://kubernetes.io/docs/concepts/storage/persistent-volumes#access-modes-1 | [optional] 
**data_source** | [**v1_typed_local_object_reference_t**](v1_typed_local_object_reference.md) \* |  | [optional] 
**resources** | [**v1_resource_requirements_t**](v1_resource_requirements.md) \* |  | [optional] 
**selector** | [**v1_label_selector_t**](v1_label_selector.md) \* |  | [optional] 
**storage_class_name** | **char \*** | Name of the StorageClass required by the claim. More info: https://kubernetes.io/docs/concepts/storage/persistent-volumes#class-1 | [optional] 
**volume_mode** | **char \*** | volumeMode defines what type of volume is required by the claim. Value of Filesystem is implied when not included in claim spec. This is a beta feature. | [optional] 
**volume_name** | **char \*** | VolumeName is the binding reference to the PersistentVolume backing this claim. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


