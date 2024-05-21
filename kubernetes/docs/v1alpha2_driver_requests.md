# v1alpha2_driver_requests_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**driver_name** | **char \*** | DriverName is the name used by the DRA driver kubelet plugin. | [optional] 
**requests** | [**list_t**](v1alpha2_resource_request.md) \* | Requests describes all resources that are needed from the driver. | [optional] 
**vendor_parameters** | [**object_t**](.md) \* | VendorParameters are arbitrary setup parameters for all requests of the claim. They are ignored while allocating the claim. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


