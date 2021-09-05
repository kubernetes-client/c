# AuthorizationV1API

All URIs are relative to *http://localhost*

Method | HTTP request | Description
------------- | ------------- | -------------
[**AuthorizationV1API_createNamespacedLocalSubjectAccessReview**](AuthorizationV1API.md#AuthorizationV1API_createNamespacedLocalSubjectAccessReview) | **POST** /apis/authorization.k8s.io/v1/namespaces/{namespace}/localsubjectaccessreviews | 
[**AuthorizationV1API_createSelfSubjectAccessReview**](AuthorizationV1API.md#AuthorizationV1API_createSelfSubjectAccessReview) | **POST** /apis/authorization.k8s.io/v1/selfsubjectaccessreviews | 
[**AuthorizationV1API_createSelfSubjectRulesReview**](AuthorizationV1API.md#AuthorizationV1API_createSelfSubjectRulesReview) | **POST** /apis/authorization.k8s.io/v1/selfsubjectrulesreviews | 
[**AuthorizationV1API_createSubjectAccessReview**](AuthorizationV1API.md#AuthorizationV1API_createSubjectAccessReview) | **POST** /apis/authorization.k8s.io/v1/subjectaccessreviews | 
[**AuthorizationV1API_getAPIResources**](AuthorizationV1API.md#AuthorizationV1API_getAPIResources) | **GET** /apis/authorization.k8s.io/v1/ | 


# **AuthorizationV1API_createNamespacedLocalSubjectAccessReview**
```c
// create a LocalSubjectAccessReview
//
v1_local_subject_access_review_t* AuthorizationV1API_createNamespacedLocalSubjectAccessReview(apiClient_t *apiClient, char * _namespace, v1_local_subject_access_review_t * body, char * dryRun, char * fieldManager, char * pretty);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**_namespace** | **char \*** | object name and auth scope, such as for teams and projects | 
**body** | **[v1_local_subject_access_review_t](v1_local_subject_access_review.md) \*** |  | 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. | [optional] 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 

### Return type

[v1_local_subject_access_review_t](v1_local_subject_access_review.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AuthorizationV1API_createSelfSubjectAccessReview**
```c
// create a SelfSubjectAccessReview
//
v1_self_subject_access_review_t* AuthorizationV1API_createSelfSubjectAccessReview(apiClient_t *apiClient, v1_self_subject_access_review_t * body, char * dryRun, char * fieldManager, char * pretty);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**body** | **[v1_self_subject_access_review_t](v1_self_subject_access_review.md) \*** |  | 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. | [optional] 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 

### Return type

[v1_self_subject_access_review_t](v1_self_subject_access_review.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AuthorizationV1API_createSelfSubjectRulesReview**
```c
// create a SelfSubjectRulesReview
//
v1_self_subject_rules_review_t* AuthorizationV1API_createSelfSubjectRulesReview(apiClient_t *apiClient, v1_self_subject_rules_review_t * body, char * dryRun, char * fieldManager, char * pretty);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**body** | **[v1_self_subject_rules_review_t](v1_self_subject_rules_review.md) \*** |  | 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. | [optional] 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 

### Return type

[v1_self_subject_rules_review_t](v1_self_subject_rules_review.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AuthorizationV1API_createSubjectAccessReview**
```c
// create a SubjectAccessReview
//
v1_subject_access_review_t* AuthorizationV1API_createSubjectAccessReview(apiClient_t *apiClient, v1_subject_access_review_t * body, char * dryRun, char * fieldManager, char * pretty);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**body** | **[v1_subject_access_review_t](v1_subject_access_review.md) \*** |  | 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. | [optional] 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 

### Return type

[v1_subject_access_review_t](v1_subject_access_review.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AuthorizationV1API_getAPIResources**
```c
// get available resources
//
v1_api_resource_list_t* AuthorizationV1API_getAPIResources(apiClient_t *apiClient);
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

