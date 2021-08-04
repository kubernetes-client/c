# v1beta1_certificate_signing_request_spec_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**extra** | **list_t*** | Extra information about the requesting user. See user.Info interface for details. | [optional] 
**groups** | **list_t \*** | Group information about the requesting user. See user.Info interface for details. | [optional] 
**request** | **char \*** | Base64-encoded PKCS#10 CSR data | 
**uid** | **char \*** | UID information about the requesting user. See user.Info interface for details. | [optional] 
**usages** | **list_t \*** | allowedUsages specifies a set of usage contexts the key will be valid for. See: https://tools.ietf.org/html/rfc5280#section-4.2.1.3      https://tools.ietf.org/html/rfc5280#section-4.2.1.12 | [optional] 
**username** | **char \*** | Information about the requesting user. See user.Info interface for details. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


