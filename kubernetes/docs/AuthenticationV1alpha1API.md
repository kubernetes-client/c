# AuthenticationV1alpha1API

All URIs are relative to *http://localhost*

Method | HTTP request | Description
------------- | ------------- | -------------
[**AuthenticationV1alpha1API_createSelfSubjectReview_0**](AuthenticationV1alpha1API.md#AuthenticationV1alpha1API_createSelfSubjectReview_0) | **POST** /apis/authentication.k8s.io/v1alpha1/selfsubjectreviews | 
[**AuthenticationV1alpha1API_getAPIResources_7**](AuthenticationV1alpha1API.md#AuthenticationV1alpha1API_getAPIResources_7) | **GET** /apis/authentication.k8s.io/v1alpha1/ | 


# **AuthenticationV1alpha1API_createSelfSubjectReview_0**
```c
// create a SelfSubjectReview
//
v1alpha1_self_subject_review_t* AuthenticationV1alpha1API_createSelfSubjectReview_0(apiClient_t *apiClient, v1alpha1_self_subject_review_t *body, char *dryRun, char *fieldManager, char *fieldValidation, char *pretty);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**body** | **[v1alpha1_self_subject_review_t](v1alpha1_self_subject_review.md) \*** |  | 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. | [optional] 
**fieldValidation** | **char \*** | fieldValidation instructs the server on how to handle objects in the request (POST/PUT/PATCH) containing unknown or duplicate fields. Valid values are: - Ignore: This will ignore any unknown fields that are silently dropped from the object, and will ignore all but the last duplicate field that the decoder encounters. This is the default behavior prior to v1.23. - Warn: This will send a warning via the standard warning response header for each unknown field that is dropped from the object, and for each duplicate field that is encountered. The request will still succeed if there are no other errors, and will only persist the last of any duplicate fields. This is the default in v1.23+ - Strict: This will fail the request with a BadRequest error if any unknown fields would be dropped from the object, or if any duplicate fields are present. The error returned from the server will contain all unknown and duplicate fields encountered. | [optional] 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. Defaults to &#39;false&#39; unless the user-agent indicates a browser or command-line HTTP tool (curl and wget). | [optional] 

### Return type

[v1alpha1_self_subject_review_t](v1alpha1_self_subject_review.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AuthenticationV1alpha1API_getAPIResources_7**
```c
// get available resources
//
v1_api_resource_list_t* AuthenticationV1alpha1API_getAPIResources_7(apiClient_t *apiClient);
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

