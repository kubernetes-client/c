# v1beta2_device_request_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**exactly** | [**v1beta2_exact_device_request_t**](v1beta2_exact_device_request.md) \* |  | [optional] 
**first_available** | [**list_t**](v1beta2_device_sub_request.md) \* | FirstAvailable contains subrequests, of which exactly one will be selected by the scheduler. It tries to satisfy them in the order in which they are listed here. So if there are two entries in the list, the scheduler will only check the second one if it determines that the first one can not be used.  DRA does not yet implement scoring, so the scheduler will select the first set of devices that satisfies all the requests in the claim. And if the requirements can be satisfied on more than one node, other scheduling features will determine which node is chosen. This means that the set of devices allocated to a claim might not be the optimal set available to the cluster. Scoring will be implemented later. | [optional] 
**name** | **char \*** | Name can be used to reference this request in a pod.spec.containers[].resources.claims entry and in a constraint of the claim.  References using the name in the DeviceRequest will uniquely identify a request when the Exactly field is set. When the FirstAvailable field is set, a reference to the name of the DeviceRequest will match whatever subrequest is chosen by the scheduler.  Must be a DNS label. | 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


