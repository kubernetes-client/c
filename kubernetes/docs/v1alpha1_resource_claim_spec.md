# v1alpha1_resource_claim_spec_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**allocation_mode** | **char \*** | Allocation can start immediately or when a Pod wants to use the resource. \&quot;WaitForFirstConsumer\&quot; is the default. | [optional] 
**parameters_ref** | [**v1alpha1_resource_claim_parameters_reference_t**](v1alpha1_resource_claim_parameters_reference.md) \* |  | [optional] 
**resource_class_name** | **char \*** | ResourceClassName references the driver and additional parameters via the name of a ResourceClass that was created as part of the driver deployment. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


