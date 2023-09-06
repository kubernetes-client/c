# WellKnownAPI

All URIs are relative to *http://localhost*

Method | HTTP request | Description
------------- | ------------- | -------------
[**WellKnownAPI_getServiceAccountIssuerOpenIDConfiguration**](WellKnownAPI.md#WellKnownAPI_getServiceAccountIssuerOpenIDConfiguration) | **GET** /.well-known/openid-configuration | 


# **WellKnownAPI_getServiceAccountIssuerOpenIDConfiguration**
```c
// get service account issuer OpenID configuration, also known as the 'OIDC discovery doc'
//
char* WellKnownAPI_getServiceAccountIssuerOpenIDConfiguration(apiClient_t *apiClient);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |

### Return type

char*



### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

