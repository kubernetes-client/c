# AuthenticationV1API

All URIs are relative to *http://localhost*

Method | HTTP request | Description
------------- | ------------- | -------------
[**AuthenticationV1API_createTokenReview**](AuthenticationV1API.md#AuthenticationV1API_createTokenReview) | **POST** /apis/authentication.k8s.io/v1/tokenreviews | 
[**AuthenticationV1API_getAPIResources**](AuthenticationV1API.md#AuthenticationV1API_getAPIResources) | **GET** /apis/authentication.k8s.io/v1/ | 


# **AuthenticationV1API_createTokenReview**
```c
// create a TokenReview
//
v1_token_review_t* AuthenticationV1API_createTokenReview(apiClient_t *apiClient, v1_token_review_t * body, char * dryRun, char * fieldManager, char * pretty);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**body** | **[v1_token_review_t](v1_token_review.md) \*** |  | 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. | [optional] 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 

### Return type

[v1_token_review_t](v1_token_review.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AuthenticationV1API_getAPIResources**
```c
// get available resources
//
v1_api_resource_list_t* AuthenticationV1API_getAPIResources(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[v1_api_resource_list_t](v1_api_resource_list.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

