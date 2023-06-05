# v1_endpoint_address_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**hostname** | **char \*** | The Hostname of this endpoint | [optional] 
**ip** | **char \*** | The IP of this endpoint. May not be loopback (127.0.0.0/8 or ::1), link-local (169.254.0.0/16 or fe80::/10), or link-local multicast (224.0.0.0/24 or ff02::/16). | 
**node_name** | **char \*** | Optional: Node hosting this endpoint. This can be used to determine endpoints local to a node. | [optional] 
**target_ref** | [**v1_object_reference_t**](v1_object_reference.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


