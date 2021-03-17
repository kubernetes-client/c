# v1alpha1_pod_preset_spec_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**env** | [**list_t**](v1_env_var.md) \* | Env defines the collection of EnvVar to inject into containers. | [optional] 
**env_from** | [**list_t**](v1_env_from_source.md) \* | EnvFrom defines the collection of EnvFromSource to inject into containers. | [optional] 
**selector** | [**v1_label_selector_t**](v1_label_selector.md) \* |  | [optional] 
**volume_mounts** | [**list_t**](v1_volume_mount.md) \* | VolumeMounts defines the collection of VolumeMount to inject into containers. | [optional] 
**volumes** | [**list_t**](v1_volume.md) \* | Volumes defines the collection of Volume to inject into the pod. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


