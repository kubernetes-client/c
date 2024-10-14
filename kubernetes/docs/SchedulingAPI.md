# SchedulingAPI

All URIs are relative to *http://localhost*

Method | HTTP request | Description
------------- | ------------- | -------------
[**SchedulingAPI_getAPIGroup_18**](SchedulingAPI.md#SchedulingAPI_getAPIGroup_18) | **GET** /apis/scheduling.k8s.io/ | 


# **SchedulingAPI_getAPIGroup_18**
```c
// get information of a group
//
v1_api_group_t* SchedulingAPI_getAPIGroup_18(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

[v1_api_group_t](v1_api_group.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

