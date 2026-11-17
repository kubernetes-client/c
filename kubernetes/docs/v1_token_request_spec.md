# v1_token_request_spec_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**attestations** | **list_t*** | attestations is a map of well-known keys to string-slice values. The values for each key have a specific semantic meaning, which is documented on the key definition. Requesters of tokens may ask the Kubernetes API Server to attest to certain claims. The API Server may perform authorization checks depending on the key of this map. | [optional] 
**audiences** | **list_t \*** | audiences are the intendend audiences of the token. A recipient of a token must identify themself with an identifier in the list of audiences of the token, and otherwise should reject the token. A token issued for multiple audiences may be used to authenticate against any of the audiences listed but implies a high degree of trust between the target audiences. | [optional] 
**bound_object_ref** | [**v1_bound_object_reference_t**](v1_bound_object_reference.md) \* |  | [optional] 
**expiration_seconds** | **long** | expirationSeconds is the requested duration of validity of the request. The token issuer may return a token with a different validity duration so a client needs to check the &#39;expiration&#39; field in a response. | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


