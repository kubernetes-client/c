# v1_ip_block_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**cidr** | **char \*** | CIDR is a string representing the IP Block Valid examples are \&quot;192.168.1.0/24\&quot; or \&quot;2001:db8::/64\&quot; | 
**except** | **list_t \*** | Except is a slice of CIDRs that should not be included within an IP Block Valid examples are \&quot;192.168.1.0/24\&quot; or \&quot;2001:db8::/64\&quot; Except values will be rejected if they are outside the CIDR range | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


