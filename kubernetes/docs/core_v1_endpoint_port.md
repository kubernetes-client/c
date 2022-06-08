# core_v1_endpoint_port_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**app_protocol** | **char \*** | The application protocol for this port. This field follows standard Kubernetes label syntax. Un-prefixed names are reserved for IANA standard service names (as per RFC-6335 and https://www.iana.org/assignments/service-names). Non-standard protocols should use prefixed names such as mycompany.com/my-custom-protocol. | [optional] 
**name** | **char \*** | The name of this port.  This must match the &#39;name&#39; field in the corresponding ServicePort. Must be a DNS_LABEL. Optional only if one port is defined. | [optional] 
**port** | **int** | The port number of the endpoint. | 
**protocol** | **char \*** | The IP protocol for this port. Must be UDP, TCP, or SCTP. Default is TCP.   | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


