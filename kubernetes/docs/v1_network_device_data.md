# v1_network_device_data_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**hardware_address** | **char \*** | HardwareAddress represents the hardware address (e.g. MAC Address) of the device&#39;s network interface.  Must not be longer than 128 characters. | [optional] 
**interface_name** | **char \*** | InterfaceName specifies the name of the network interface associated with the allocated device. This might be the name of a physical or virtual network interface being configured in the pod.  Must not be longer than 256 characters. | [optional] 
**ips** | **list_t \*** | IPs lists the network addresses assigned to the device&#39;s network interface. This can include both IPv4 and IPv6 addresses. The IPs are in the CIDR notation, which includes both the address and the associated subnet mask. e.g.: \&quot;192.0.2.5/24\&quot; for IPv4 and \&quot;2001:db8::5/64\&quot; for IPv6. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


