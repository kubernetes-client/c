# OpenidAPI

All URIs are relative to *http://localhost*

Method | HTTP request | Description
------------- | ------------- | -------------
[**OpenidAPI_getServiceAccountIssuerOpenIDKeyset**](OpenidAPI.md#OpenidAPI_getServiceAccountIssuerOpenIDKeyset) | **GET** /openid/v1/jwks | 


# **OpenidAPI_getServiceAccountIssuerOpenIDKeyset**
```c
// get service account issuer OpenID JSON Web Key Set (contains public token verification keys)
//
char* OpenidAPI_getServiceAccountIssuerOpenIDKeyset(apiClient_t *apiClient);
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
 - **Accept**: application/jwk-set+json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

