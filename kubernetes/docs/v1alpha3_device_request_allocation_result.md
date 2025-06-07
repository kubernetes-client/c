# v1alpha3_device_request_allocation_result_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**admin_access** | **int** | AdminAccess indicates that this device was allocated for administrative access. See the corresponding request field for a definition of mode.  This is an alpha field and requires enabling the DRAAdminAccess feature gate. Admin access is disabled if this field is unset or set to false, otherwise it is enabled. | [optional] 
**device** | **char \*** | Device references one device instance via its name in the driver&#39;s resource pool. It must be a DNS label. | 
**driver** | **char \*** | Driver specifies the name of the DRA driver whose kubelet plugin should be invoked to process the allocation once the claim is needed on a node.  Must be a DNS subdomain and should end with a DNS domain owned by the vendor of the driver. | 
**pool** | **char \*** | This name together with the driver name and the device name field identify which device was allocated (&#x60;&lt;driver name&gt;/&lt;pool name&gt;/&lt;device name&gt;&#x60;).  Must not be longer than 253 characters and may contain one or more DNS sub-domains separated by slashes. | 
**request** | **char \*** | Request is the name of the request in the claim which caused this device to be allocated. If it references a subrequest in the firstAvailable list on a DeviceRequest, this field must include both the name of the main request and the subrequest using the format &lt;main request&gt;/&lt;subrequest&gt;.  Multiple devices may have been allocated per request. | 
**tolerations** | [**list_t**](v1alpha3_device_toleration.md) \* | A copy of all tolerations specified in the request at the time when the device got allocated.  The maximum number of tolerations is 16.  This is an alpha field and requires enabling the DRADeviceTaints feature gate. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


