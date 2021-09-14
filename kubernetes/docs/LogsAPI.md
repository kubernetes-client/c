# LogsAPI

All URIs are relative to *http://localhost*

Method | HTTP request | Description
------------- | ------------- | -------------
[**LogsAPI_logFileHandler**](LogsAPI.md#LogsAPI_logFileHandler) | **GET** /logs/{logpath} | 
[**LogsAPI_logFileListHandler**](LogsAPI.md#LogsAPI_logFileListHandler) | **GET** /logs/ | 


# **LogsAPI_logFileHandler**
```c
void LogsAPI_logFileHandler(apiClient_t *apiClient, char * logpath);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**logpath** | **char \*** | path to the log | 

### Return type

void

### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **LogsAPI_logFileListHandler**
```c
void LogsAPI_logFileListHandler(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

void

### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: Not defined

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

