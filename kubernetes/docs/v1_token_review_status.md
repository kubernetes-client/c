# v1_token_review_status_t

## Properties
Name | Type | Description | Notes
------------ | ------------- | ------------- | -------------
**audiences** | **list_t \*** | Audiences are audience identifiers chosen by the authenticator that are compatible with both the TokenReview and token. An identifier is any identifier in the intersection of the TokenReviewSpec audiences and the token&#39;s audiences. A client of the TokenReview API that sets the spec.audiences field should validate that a compatible audience identifier is returned in the status.audiences field to ensure that the TokenReview server is audience aware. If a TokenReview returns an empty status.audience field where status.authenticated is \&quot;true\&quot;, the token is valid against the audience of the Kubernetes API server. | [optional] 
**authenticated** | **int** | Authenticated indicates that the token was associated with a known user. | [optional] 
**error** | **char \*** | Error indicates that the token couldn&#39;t be checked | [optional] 
**user** | [**v1_user_info_t**](v1_user_info.md) \* |  | [optional] 

[[Back to Model list]](../README.md#documentation-for-models) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to README]](../README.md)


