# AuthorizationV1beta1API

All URIs are relative to *http://localhost*

Method | HTTP request | Description
------------- | ------------- | -------------
[**AuthorizationV1beta1API_createNamespacedLocalSubjectAccessReview**](AuthorizationV1beta1API.md#AuthorizationV1beta1API_createNamespacedLocalSubjectAccessReview) | **POST** /apis/authorization.k8s.io/v1beta1/namespaces/{namespace}/localsubjectaccessreviews | 
[**AuthorizationV1beta1API_createSelfSubjectAccessReview**](AuthorizationV1beta1API.md#AuthorizationV1beta1API_createSelfSubjectAccessReview) | **POST** /apis/authorization.k8s.io/v1beta1/selfsubjectaccessreviews | 
[**AuthorizationV1beta1API_createSelfSubjectRulesReview**](AuthorizationV1beta1API.md#AuthorizationV1beta1API_createSelfSubjectRulesReview) | **POST** /apis/authorization.k8s.io/v1beta1/selfsubjectrulesreviews | 
[**AuthorizationV1beta1API_createSubjectAccessReview**](AuthorizationV1beta1API.md#AuthorizationV1beta1API_createSubjectAccessReview) | **POST** /apis/authorization.k8s.io/v1beta1/subjectaccessreviews | 
[**AuthorizationV1beta1API_getAPIResources**](AuthorizationV1beta1API.md#AuthorizationV1beta1API_getAPIResources) | **GET** /apis/authorization.k8s.io/v1beta1/ | 


# **AuthorizationV1beta1API_createNamespacedLocalSubjectAccessReview**
```c
// create a LocalSubjectAccessReview
//
v1beta1_local_subject_access_review_t* AuthorizationV1beta1API_createNamespacedLocalSubjectAccessReview(apiClient_t *apiClient, char * _namespace, v1beta1_local_subject_access_review_t * body, char * dryRun, char * fieldManager, char * pretty);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**_namespace** | **char \*** | object name and auth scope, such as for teams and projects | 
**body** | **[v1beta1_local_subject_access_review_t](v1beta1_local_subject_access_review.md) \*** |  | 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. | [optional] 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 

### Return type

[v1beta1_local_subject_access_review_t](v1beta1_local_subject_access_review.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AuthorizationV1beta1API_createSelfSubjectAccessReview**
```c
// create a SelfSubjectAccessReview
//
v1beta1_self_subject_access_review_t* AuthorizationV1beta1API_createSelfSubjectAccessReview(apiClient_t *apiClient, v1beta1_self_subject_access_review_t * body, char * dryRun, char * fieldManager, char * pretty);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**body** | **[v1beta1_self_subject_access_review_t](v1beta1_self_subject_access_review.md) \*** |  | 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. | [optional] 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 

### Return type

[v1beta1_self_subject_access_review_t](v1beta1_self_subject_access_review.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AuthorizationV1beta1API_createSelfSubjectRulesReview**
```c
// create a SelfSubjectRulesReview
//
v1beta1_self_subject_rules_review_t* AuthorizationV1beta1API_createSelfSubjectRulesReview(apiClient_t *apiClient, v1beta1_self_subject_rules_review_t * body, char * dryRun, char * fieldManager, char * pretty);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**body** | **[v1beta1_self_subject_rules_review_t](v1beta1_self_subject_rules_review.md) \*** |  | 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. | [optional] 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 

### Return type

[v1beta1_self_subject_rules_review_t](v1beta1_self_subject_rules_review.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AuthorizationV1beta1API_createSubjectAccessReview**
```c
// create a SubjectAccessReview
//
v1beta1_subject_access_review_t* AuthorizationV1beta1API_createSubjectAccessReview(apiClient_t *apiClient, v1beta1_subject_access_review_t * body, char * dryRun, char * fieldManager, char * pretty);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**body** | **[v1beta1_subject_access_review_t](v1beta1_subject_access_review.md) \*** |  | 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. | [optional] 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 

### Return type

[v1beta1_subject_access_review_t](v1beta1_subject_access_review.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AuthorizationV1beta1API_getAPIResources**
```c
// get available resources
//
v1_api_resource_list_t* AuthorizationV1beta1API_getAPIResources(apiClient_t *apiClient);
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

