# FlowcontrolApiserverAPI

All URIs are relative to *http://localhost*

Method | HTTP request | Description
------------- | ------------- | -------------
[**FlowcontrolApiserverAPI_getAPIGroup_11**](FlowcontrolApiserverAPI.md#FlowcontrolApiserverAPI_getAPIGroup_11) | **GET** /apis/flowcontrol.apiserver.k8s.io/ | 


# **FlowcontrolApiserverAPI_getAPIGroup_11**
```c
// get information of a group
//
v1_api_group_t* FlowcontrolApiserverAPI_getAPIGroup_11(apiClient_t *apiClient);
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

