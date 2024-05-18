# v1alpha2_structured_resource_handle_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**node_name** | **char \*** | NodeName is the name of the node providing the necessary resources if the resources are local to a node. | [optional] 
**results** | [**list_t**](v1alpha2_driver_allocation_result.md) \* | Results lists all allocated driver resources. | 
**vendor_claim_parameters** | [**object_t**](.md) \* | VendorClaimParameters are the per-claim configuration parameters from the resource claim parameters at the time that the claim was allocated. | [optional] 
**vendor_class_parameters** | [**object_t**](.md) \* | VendorClassParameters are the per-claim configuration parameters from the resource class at the time that the claim was allocated. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


