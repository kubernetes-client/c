# v1beta1_endpoint_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**addresses** | **list_t \*** | addresses of this endpoint. The contents of this field are interpreted according to the corresponding EndpointSlice addressType field. Consumers must handle different types of addresses in the context of their own capabilities. This must contain at least one address but no more than 100. | 
**conditions** | [**v1beta1_endpoint_conditions_t**](v1beta1_endpoint_conditions.md) \* |  | [optional] 
**hostname** | **char \*** | hostname of this endpoint. This field may be used by consumers of endpoints to distinguish endpoints from each other (e.g. in DNS names). Multiple endpoints which use the same hostname should be considered fungible (e.g. multiple A values in DNS). Must pass DNS Label (RFC 1123) validation. | [optional] 
**target_ref** | [**v1_object_reference_t**](v1_object_reference.md) \* |  | [optional] 
**topology** | **list_t*** | topology contains arbitrary topology information associated with the endpoint. These key/value pairs must conform with the label format. https://kubernetes.io/docs/concepts/overview/working-with-objects/labels Topology may include a maximum of 16 key/value pairs. This includes, but is not limited to the following well known keys: * kubernetes.io/hostname: the value indicates the hostname of the node   where the endpoint is located. This should match the corresponding   node label. * topology.kubernetes.io/zone: the value indicates the zone where the   endpoint is located. This should match the corresponding node label. * topology.kubernetes.io/region: the value indicates the region where the   endpoint is located. This should match the corresponding node label. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


