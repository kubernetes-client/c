# v1beta1_workload_spec_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**composite_pod_group_templates** | [**list_t**](v1beta1_composite_pod_group_template.md) \* | compositePodGroupTemplates is the list of CompositePodGroup templates that make up the Workload. The maximum number of templates is 8. This field is immutable. Exactly one of CompositePodGroupTemplates and PodGroupTemplates must be set.  This field is used only when the CompositePodGroup feature gate is enabled. | [optional] 
**controller_ref** | [**v1beta1_typed_local_object_reference_t**](v1beta1_typed_local_object_reference.md) \* |  | [optional] 
**pod_group_templates** | [**list_t**](v1beta1_pod_group_template.md) \* | podGroupTemplates is the list of templates that make up the Workload. The maximum number of templates is 8. Templates cannot be added or removed after the workload is created. Existing templates may still be updated where their individual fields allow it. Exactly one of CompositePodGroupTemplates and PodGroupTemplates must be set. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


