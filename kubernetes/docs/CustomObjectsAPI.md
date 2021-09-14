# CustomObjectsAPI

All URIs are relative to *http://localhost*

Method | HTTP request | Description
------------- | ------------- | -------------
[**CustomObjectsAPI_createClusterCustomObject**](CustomObjectsAPI.md#CustomObjectsAPI_createClusterCustomObject) | **POST** /apis/{group}/{version}/{plural} | 
[**CustomObjectsAPI_createNamespacedCustomObject**](CustomObjectsAPI.md#CustomObjectsAPI_createNamespacedCustomObject) | **POST** /apis/{group}/{version}/namespaces/{namespace}/{plural} | 
[**CustomObjectsAPI_deleteClusterCustomObject**](CustomObjectsAPI.md#CustomObjectsAPI_deleteClusterCustomObject) | **DELETE** /apis/{group}/{version}/{plural}/{name} | 
[**CustomObjectsAPI_deleteCollectionClusterCustomObject**](CustomObjectsAPI.md#CustomObjectsAPI_deleteCollectionClusterCustomObject) | **DELETE** /apis/{group}/{version}/{plural} | 
[**CustomObjectsAPI_deleteCollectionNamespacedCustomObject**](CustomObjectsAPI.md#CustomObjectsAPI_deleteCollectionNamespacedCustomObject) | **DELETE** /apis/{group}/{version}/namespaces/{namespace}/{plural} | 
[**CustomObjectsAPI_deleteNamespacedCustomObject**](CustomObjectsAPI.md#CustomObjectsAPI_deleteNamespacedCustomObject) | **DELETE** /apis/{group}/{version}/namespaces/{namespace}/{plural}/{name} | 
[**CustomObjectsAPI_getClusterCustomObject**](CustomObjectsAPI.md#CustomObjectsAPI_getClusterCustomObject) | **GET** /apis/{group}/{version}/{plural}/{name} | 
[**CustomObjectsAPI_getClusterCustomObjectScale**](CustomObjectsAPI.md#CustomObjectsAPI_getClusterCustomObjectScale) | **GET** /apis/{group}/{version}/{plural}/{name}/scale | 
[**CustomObjectsAPI_getClusterCustomObjectStatus**](CustomObjectsAPI.md#CustomObjectsAPI_getClusterCustomObjectStatus) | **GET** /apis/{group}/{version}/{plural}/{name}/status | 
[**CustomObjectsAPI_getNamespacedCustomObject**](CustomObjectsAPI.md#CustomObjectsAPI_getNamespacedCustomObject) | **GET** /apis/{group}/{version}/namespaces/{namespace}/{plural}/{name} | 
[**CustomObjectsAPI_getNamespacedCustomObjectScale**](CustomObjectsAPI.md#CustomObjectsAPI_getNamespacedCustomObjectScale) | **GET** /apis/{group}/{version}/namespaces/{namespace}/{plural}/{name}/scale | 
[**CustomObjectsAPI_getNamespacedCustomObjectStatus**](CustomObjectsAPI.md#CustomObjectsAPI_getNamespacedCustomObjectStatus) | **GET** /apis/{group}/{version}/namespaces/{namespace}/{plural}/{name}/status | 
[**CustomObjectsAPI_listClusterCustomObject**](CustomObjectsAPI.md#CustomObjectsAPI_listClusterCustomObject) | **GET** /apis/{group}/{version}/{plural} | 
[**CustomObjectsAPI_listNamespacedCustomObject**](CustomObjectsAPI.md#CustomObjectsAPI_listNamespacedCustomObject) | **GET** /apis/{group}/{version}/namespaces/{namespace}/{plural} | 
[**CustomObjectsAPI_patchClusterCustomObject**](CustomObjectsAPI.md#CustomObjectsAPI_patchClusterCustomObject) | **PATCH** /apis/{group}/{version}/{plural}/{name} | 
[**CustomObjectsAPI_patchClusterCustomObjectScale**](CustomObjectsAPI.md#CustomObjectsAPI_patchClusterCustomObjectScale) | **PATCH** /apis/{group}/{version}/{plural}/{name}/scale | 
[**CustomObjectsAPI_patchClusterCustomObjectStatus**](CustomObjectsAPI.md#CustomObjectsAPI_patchClusterCustomObjectStatus) | **PATCH** /apis/{group}/{version}/{plural}/{name}/status | 
[**CustomObjectsAPI_patchNamespacedCustomObject**](CustomObjectsAPI.md#CustomObjectsAPI_patchNamespacedCustomObject) | **PATCH** /apis/{group}/{version}/namespaces/{namespace}/{plural}/{name} | 
[**CustomObjectsAPI_patchNamespacedCustomObjectScale**](CustomObjectsAPI.md#CustomObjectsAPI_patchNamespacedCustomObjectScale) | **PATCH** /apis/{group}/{version}/namespaces/{namespace}/{plural}/{name}/scale | 
[**CustomObjectsAPI_patchNamespacedCustomObjectStatus**](CustomObjectsAPI.md#CustomObjectsAPI_patchNamespacedCustomObjectStatus) | **PATCH** /apis/{group}/{version}/namespaces/{namespace}/{plural}/{name}/status | 
[**CustomObjectsAPI_replaceClusterCustomObject**](CustomObjectsAPI.md#CustomObjectsAPI_replaceClusterCustomObject) | **PUT** /apis/{group}/{version}/{plural}/{name} | 
[**CustomObjectsAPI_replaceClusterCustomObjectScale**](CustomObjectsAPI.md#CustomObjectsAPI_replaceClusterCustomObjectScale) | **PUT** /apis/{group}/{version}/{plural}/{name}/scale | 
[**CustomObjectsAPI_replaceClusterCustomObjectStatus**](CustomObjectsAPI.md#CustomObjectsAPI_replaceClusterCustomObjectStatus) | **PUT** /apis/{group}/{version}/{plural}/{name}/status | 
[**CustomObjectsAPI_replaceNamespacedCustomObject**](CustomObjectsAPI.md#CustomObjectsAPI_replaceNamespacedCustomObject) | **PUT** /apis/{group}/{version}/namespaces/{namespace}/{plural}/{name} | 
[**CustomObjectsAPI_replaceNamespacedCustomObjectScale**](CustomObjectsAPI.md#CustomObjectsAPI_replaceNamespacedCustomObjectScale) | **PUT** /apis/{group}/{version}/namespaces/{namespace}/{plural}/{name}/scale | 
[**CustomObjectsAPI_replaceNamespacedCustomObjectStatus**](CustomObjectsAPI.md#CustomObjectsAPI_replaceNamespacedCustomObjectStatus) | **PUT** /apis/{group}/{version}/namespaces/{namespace}/{plural}/{name}/status | 


# **CustomObjectsAPI_createClusterCustomObject**
```c
// Creates a cluster scoped Custom object
//
object_t* CustomObjectsAPI_createClusterCustomObject(apiClient_t *apiClient, char * group, char * version, char * plural, object_t * body, char * pretty, char * dryRun, char * fieldManager);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**group** | **char \*** | The custom resource&#39;s group name | 
**version** | **char \*** | The custom resource&#39;s version | 
**plural** | **char \*** | The custom resource&#39;s plural name. For TPRs this would be lowercase plural kind. | 
**body** | **[object_t](object.md) \*** | The JSON schema of the Resource to create. | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. This field is required for apply requests (application/apply-patch) but optional for non-apply patch types (JsonPatch, MergePatch, StrategicMergePatch). | [optional] 

### Return type

[object_t](object.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomObjectsAPI_createNamespacedCustomObject**
```c
// Creates a namespace scoped Custom object
//
object_t* CustomObjectsAPI_createNamespacedCustomObject(apiClient_t *apiClient, char * group, char * version, char * _namespace, char * plural, object_t * body, char * pretty, char * dryRun, char * fieldManager);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**group** | **char \*** | The custom resource&#39;s group name | 
**version** | **char \*** | The custom resource&#39;s version | 
**_namespace** | **char \*** | The custom resource&#39;s namespace | 
**plural** | **char \*** | The custom resource&#39;s plural name. For TPRs this would be lowercase plural kind. | 
**body** | **[object_t](object.md) \*** | The JSON schema of the Resource to create. | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. | [optional] 

### Return type

[object_t](object.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomObjectsAPI_deleteClusterCustomObject**
```c
// Deletes the specified cluster scoped custom object
//
object_t* CustomObjectsAPI_deleteClusterCustomObject(apiClient_t *apiClient, char * group, char * version, char * plural, char * name, int gracePeriodSeconds, int orphanDependents, char * propagationPolicy, char * dryRun, v1_delete_options_t * body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**group** | **char \*** | the custom resource&#39;s group | 
**version** | **char \*** | the custom resource&#39;s version | 
**plural** | **char \*** | the custom object&#39;s plural name. For TPRs this would be lowercase plural kind. | 
**name** | **char \*** | the custom object&#39;s name | 
**gracePeriodSeconds** | **int** | The duration in seconds before the object should be deleted. Value must be non-negative integer. The value zero indicates delete immediately. If this value is nil, the default grace period for the specified type will be used. Defaults to a per object value if not specified. zero means delete immediately. | [optional] 
**orphanDependents** | **int** | Deprecated: please use the PropagationPolicy, this field will be deprecated in 1.7. Should the dependent objects be orphaned. If true/false, the \&quot;orphan\&quot; finalizer will be added to/removed from the object&#39;s finalizers list. Either this field or PropagationPolicy may be set, but not both. | [optional] 
**propagationPolicy** | **char \*** | Whether and how garbage collection will be performed. Either this field or OrphanDependents may be set, but not both. The default policy is decided by the existing finalizer set in the metadata.finalizers and the resource-specific default policy. | [optional] 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**body** | **[v1_delete_options_t](v1_delete_options.md) \*** |  | [optional] 

### Return type

[object_t](object.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomObjectsAPI_deleteCollectionClusterCustomObject**
```c
// Delete collection of cluster scoped custom objects
//
object_t* CustomObjectsAPI_deleteCollectionClusterCustomObject(apiClient_t *apiClient, char * group, char * version, char * plural, char * pretty, int gracePeriodSeconds, int orphanDependents, char * propagationPolicy, char * dryRun, v1_delete_options_t * body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**group** | **char \*** | The custom resource&#39;s group name | 
**version** | **char \*** | The custom resource&#39;s version | 
**plural** | **char \*** | The custom resource&#39;s plural name. For TPRs this would be lowercase plural kind. | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 
**gracePeriodSeconds** | **int** | The duration in seconds before the object should be deleted. Value must be non-negative integer. The value zero indicates delete immediately. If this value is nil, the default grace period for the specified type will be used. Defaults to a per object value if not specified. zero means delete immediately. | [optional] 
**orphanDependents** | **int** | Deprecated: please use the PropagationPolicy, this field will be deprecated in 1.7. Should the dependent objects be orphaned. If true/false, the \&quot;orphan\&quot; finalizer will be added to/removed from the object&#39;s finalizers list. Either this field or PropagationPolicy may be set, but not both. | [optional] 
**propagationPolicy** | **char \*** | Whether and how garbage collection will be performed. Either this field or OrphanDependents may be set, but not both. The default policy is decided by the existing finalizer set in the metadata.finalizers and the resource-specific default policy. | [optional] 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**body** | **[v1_delete_options_t](v1_delete_options.md) \*** |  | [optional] 

### Return type

[object_t](object.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomObjectsAPI_deleteCollectionNamespacedCustomObject**
```c
// Delete collection of namespace scoped custom objects
//
object_t* CustomObjectsAPI_deleteCollectionNamespacedCustomObject(apiClient_t *apiClient, char * group, char * version, char * _namespace, char * plural, char * pretty, int gracePeriodSeconds, int orphanDependents, char * propagationPolicy, char * dryRun, v1_delete_options_t * body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**group** | **char \*** | The custom resource&#39;s group name | 
**version** | **char \*** | The custom resource&#39;s version | 
**_namespace** | **char \*** | The custom resource&#39;s namespace | 
**plural** | **char \*** | The custom resource&#39;s plural name. For TPRs this would be lowercase plural kind. | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 
**gracePeriodSeconds** | **int** | The duration in seconds before the object should be deleted. Value must be non-negative integer. The value zero indicates delete immediately. If this value is nil, the default grace period for the specified type will be used. Defaults to a per object value if not specified. zero means delete immediately. | [optional] 
**orphanDependents** | **int** | Deprecated: please use the PropagationPolicy, this field will be deprecated in 1.7. Should the dependent objects be orphaned. If true/false, the \&quot;orphan\&quot; finalizer will be added to/removed from the object&#39;s finalizers list. Either this field or PropagationPolicy may be set, but not both. | [optional] 
**propagationPolicy** | **char \*** | Whether and how garbage collection will be performed. Either this field or OrphanDependents may be set, but not both. The default policy is decided by the existing finalizer set in the metadata.finalizers and the resource-specific default policy. | [optional] 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**body** | **[v1_delete_options_t](v1_delete_options.md) \*** |  | [optional] 

### Return type

[object_t](object.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomObjectsAPI_deleteNamespacedCustomObject**
```c
// Deletes the specified namespace scoped custom object
//
object_t* CustomObjectsAPI_deleteNamespacedCustomObject(apiClient_t *apiClient, char * group, char * version, char * _namespace, char * plural, char * name, int gracePeriodSeconds, int orphanDependents, char * propagationPolicy, char * dryRun, v1_delete_options_t * body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**group** | **char \*** | the custom resource&#39;s group | 
**version** | **char \*** | the custom resource&#39;s version | 
**_namespace** | **char \*** | The custom resource&#39;s namespace | 
**plural** | **char \*** | the custom resource&#39;s plural name. For TPRs this would be lowercase plural kind. | 
**name** | **char \*** | the custom object&#39;s name | 
**gracePeriodSeconds** | **int** | The duration in seconds before the object should be deleted. Value must be non-negative integer. The value zero indicates delete immediately. If this value is nil, the default grace period for the specified type will be used. Defaults to a per object value if not specified. zero means delete immediately. | [optional] 
**orphanDependents** | **int** | Deprecated: please use the PropagationPolicy, this field will be deprecated in 1.7. Should the dependent objects be orphaned. If true/false, the \&quot;orphan\&quot; finalizer will be added to/removed from the object&#39;s finalizers list. Either this field or PropagationPolicy may be set, but not both. | [optional] 
**propagationPolicy** | **char \*** | Whether and how garbage collection will be performed. Either this field or OrphanDependents may be set, but not both. The default policy is decided by the existing finalizer set in the metadata.finalizers and the resource-specific default policy. | [optional] 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**body** | **[v1_delete_options_t](v1_delete_options.md) \*** |  | [optional] 

### Return type

[object_t](object.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomObjectsAPI_getClusterCustomObject**
```c
// Returns a cluster scoped custom object
//
object_t* CustomObjectsAPI_getClusterCustomObject(apiClient_t *apiClient, char * group, char * version, char * plural, char * name);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**group** | **char \*** | the custom resource&#39;s group | 
**version** | **char \*** | the custom resource&#39;s version | 
**plural** | **char \*** | the custom object&#39;s plural name. For TPRs this would be lowercase plural kind. | 
**name** | **char \*** | the custom object&#39;s name | 

### Return type

[object_t](object.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomObjectsAPI_getClusterCustomObjectScale**
```c
// read scale of the specified custom object
//
object_t* CustomObjectsAPI_getClusterCustomObjectScale(apiClient_t *apiClient, char * group, char * version, char * plural, char * name);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**group** | **char \*** | the custom resource&#39;s group | 
**version** | **char \*** | the custom resource&#39;s version | 
**plural** | **char \*** | the custom resource&#39;s plural name. For TPRs this would be lowercase plural kind. | 
**name** | **char \*** | the custom object&#39;s name | 

### Return type

[object_t](object.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomObjectsAPI_getClusterCustomObjectStatus**
```c
// read status of the specified cluster scoped custom object
//
object_t* CustomObjectsAPI_getClusterCustomObjectStatus(apiClient_t *apiClient, char * group, char * version, char * plural, char * name);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**group** | **char \*** | the custom resource&#39;s group | 
**version** | **char \*** | the custom resource&#39;s version | 
**plural** | **char \*** | the custom resource&#39;s plural name. For TPRs this would be lowercase plural kind. | 
**name** | **char \*** | the custom object&#39;s name | 

### Return type

[object_t](object.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomObjectsAPI_getNamespacedCustomObject**
```c
// Returns a namespace scoped custom object
//
object_t* CustomObjectsAPI_getNamespacedCustomObject(apiClient_t *apiClient, char * group, char * version, char * _namespace, char * plural, char * name);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**group** | **char \*** | the custom resource&#39;s group | 
**version** | **char \*** | the custom resource&#39;s version | 
**_namespace** | **char \*** | The custom resource&#39;s namespace | 
**plural** | **char \*** | the custom resource&#39;s plural name. For TPRs this would be lowercase plural kind. | 
**name** | **char \*** | the custom object&#39;s name | 

### Return type

[object_t](object.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomObjectsAPI_getNamespacedCustomObjectScale**
```c
// read scale of the specified namespace scoped custom object
//
object_t* CustomObjectsAPI_getNamespacedCustomObjectScale(apiClient_t *apiClient, char * group, char * version, char * _namespace, char * plural, char * name);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**group** | **char \*** | the custom resource&#39;s group | 
**version** | **char \*** | the custom resource&#39;s version | 
**_namespace** | **char \*** | The custom resource&#39;s namespace | 
**plural** | **char \*** | the custom resource&#39;s plural name. For TPRs this would be lowercase plural kind. | 
**name** | **char \*** | the custom object&#39;s name | 

### Return type

[object_t](object.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomObjectsAPI_getNamespacedCustomObjectStatus**
```c
// read status of the specified namespace scoped custom object
//
object_t* CustomObjectsAPI_getNamespacedCustomObjectStatus(apiClient_t *apiClient, char * group, char * version, char * _namespace, char * plural, char * name);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**group** | **char \*** | the custom resource&#39;s group | 
**version** | **char \*** | the custom resource&#39;s version | 
**_namespace** | **char \*** | The custom resource&#39;s namespace | 
**plural** | **char \*** | the custom resource&#39;s plural name. For TPRs this would be lowercase plural kind. | 
**name** | **char \*** | the custom object&#39;s name | 

### Return type

[object_t](object.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomObjectsAPI_listClusterCustomObject**
```c
// list or watch cluster scoped custom objects
//
object_t* CustomObjectsAPI_listClusterCustomObject(apiClient_t *apiClient, char * group, char * version, char * plural, char * pretty, int allowWatchBookmarks, char * _continue, char * fieldSelector, char * labelSelector, int limit, char * resourceVersion, char * resourceVersionMatch, int timeoutSeconds, int watch);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**group** | **char \*** | The custom resource&#39;s group name | 
**version** | **char \*** | The custom resource&#39;s version | 
**plural** | **char \*** | The custom resource&#39;s plural name. For TPRs this would be lowercase plural kind. | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 
**allowWatchBookmarks** | **int** | allowWatchBookmarks requests watch events with type \&quot;BOOKMARK\&quot;. Servers that do not implement bookmarks may ignore this flag and bookmarks are sent at the server&#39;s discretion. Clients should not assume bookmarks are returned at any specific interval, nor may they assume the server will send any BOOKMARK event during a session. If this is not a watch, this field is ignored. If the feature gate WatchBookmarks is not enabled in apiserver, this field is ignored. | [optional] 
**_continue** | **char \*** | The continue option should be set when retrieving more results from the server. Since this value is server defined, clients may only use the continue value from a previous query result with identical query parameters (except for the value of continue) and the server may reject a continue value it does not recognize. If the specified continue value is no longer valid whether due to expiration (generally five to fifteen minutes) or a configuration change on the server, the server will respond with a 410 ResourceExpired error together with a continue token. If the client needs a consistent list, it must restart their list without the continue field. Otherwise, the client may send another list request with the token received with the 410 error, the server will respond with a list starting from the next key, but from the latest snapshot, which is inconsistent from the previous list results - objects that are created, modified, or deleted after the first list request will be included in the response, as long as their keys are after the \&quot;next key\&quot;.  This field is not supported when watch is true. Clients may start a watch from the last resourceVersion value returned by the server and not miss any modifications. | [optional] 
**fieldSelector** | **char \*** | A selector to restrict the list of returned objects by their fields. Defaults to everything. | [optional] 
**labelSelector** | **char \*** | A selector to restrict the list of returned objects by their labels. Defaults to everything. | [optional] 
**limit** | **int** | limit is a maximum number of responses to return for a list call. If more items exist, the server will set the &#x60;continue&#x60; field on the list metadata to a value that can be used with the same initial query to retrieve the next set of results. Setting a limit may return fewer than the requested amount of items (up to zero items) in the event all requested objects are filtered out and clients should only use the presence of the continue field to determine whether more results are available. Servers may choose not to support the limit argument and will return all of the available results. If limit is specified and the continue field is empty, clients may assume that no more results are available. This field is not supported if watch is true.  The server guarantees that the objects returned when using continue will be identical to issuing a single list call without a limit - that is, no objects created, modified, or deleted after the first request is issued will be included in any subsequent continued requests. This is sometimes referred to as a consistent snapshot, and ensures that a client that is using limit to receive smaller chunks of a very large result can ensure they see all possible objects. If objects are updated during a chunked list the version of the object that was present at the time the first list result was calculated is returned. | [optional] 
**resourceVersion** | **char \*** | When specified with a watch call, shows changes that occur after that particular version of a resource. Defaults to changes from the beginning of history. When specified for list: - if unset, then the result is returned from remote storage based on quorum-read flag; - if it&#39;s 0, then we simply return what we currently have in cache, no guarantee; - if set to non zero, then the result is at least as fresh as given rv. | [optional] 
**resourceVersionMatch** | **char \*** | resourceVersionMatch determines how resourceVersion is applied to list calls. It is highly recommended that resourceVersionMatch be set for list calls where resourceVersion is set See https://kubernetes.io/docs/reference/using-api/api-concepts/#resource-versions for details.  Defaults to unset | [optional] 
**timeoutSeconds** | **int** | Timeout for the list/watch call. This limits the duration of the call, regardless of any activity or inactivity. | [optional] 
**watch** | **int** | Watch for changes to the described resources and return them as a stream of add, update, and remove notifications. | [optional] 

### Return type

[object_t](object.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/json;stream=watch

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomObjectsAPI_listNamespacedCustomObject**
```c
// list or watch namespace scoped custom objects
//
object_t* CustomObjectsAPI_listNamespacedCustomObject(apiClient_t *apiClient, char * group, char * version, char * _namespace, char * plural, char * pretty, int allowWatchBookmarks, char * _continue, char * fieldSelector, char * labelSelector, int limit, char * resourceVersion, char * resourceVersionMatch, int timeoutSeconds, int watch);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**group** | **char \*** | The custom resource&#39;s group name | 
**version** | **char \*** | The custom resource&#39;s version | 
**_namespace** | **char \*** | The custom resource&#39;s namespace | 
**plural** | **char \*** | The custom resource&#39;s plural name. For TPRs this would be lowercase plural kind. | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 
**allowWatchBookmarks** | **int** | allowWatchBookmarks requests watch events with type \&quot;BOOKMARK\&quot;. Servers that do not implement bookmarks may ignore this flag and bookmarks are sent at the server&#39;s discretion. Clients should not assume bookmarks are returned at any specific interval, nor may they assume the server will send any BOOKMARK event during a session. If this is not a watch, this field is ignored. If the feature gate WatchBookmarks is not enabled in apiserver, this field is ignored. | [optional] 
**_continue** | **char \*** | The continue option should be set when retrieving more results from the server. Since this value is server defined, clients may only use the continue value from a previous query result with identical query parameters (except for the value of continue) and the server may reject a continue value it does not recognize. If the specified continue value is no longer valid whether due to expiration (generally five to fifteen minutes) or a configuration change on the server, the server will respond with a 410 ResourceExpired error together with a continue token. If the client needs a consistent list, it must restart their list without the continue field. Otherwise, the client may send another list request with the token received with the 410 error, the server will respond with a list starting from the next key, but from the latest snapshot, which is inconsistent from the previous list results - objects that are created, modified, or deleted after the first list request will be included in the response, as long as their keys are after the \&quot;next key\&quot;.  This field is not supported when watch is true. Clients may start a watch from the last resourceVersion value returned by the server and not miss any modifications. | [optional] 
**fieldSelector** | **char \*** | A selector to restrict the list of returned objects by their fields. Defaults to everything. | [optional] 
**labelSelector** | **char \*** | A selector to restrict the list of returned objects by their labels. Defaults to everything. | [optional] 
**limit** | **int** | limit is a maximum number of responses to return for a list call. If more items exist, the server will set the &#x60;continue&#x60; field on the list metadata to a value that can be used with the same initial query to retrieve the next set of results. Setting a limit may return fewer than the requested amount of items (up to zero items) in the event all requested objects are filtered out and clients should only use the presence of the continue field to determine whether more results are available. Servers may choose not to support the limit argument and will return all of the available results. If limit is specified and the continue field is empty, clients may assume that no more results are available. This field is not supported if watch is true.  The server guarantees that the objects returned when using continue will be identical to issuing a single list call without a limit - that is, no objects created, modified, or deleted after the first request is issued will be included in any subsequent continued requests. This is sometimes referred to as a consistent snapshot, and ensures that a client that is using limit to receive smaller chunks of a very large result can ensure they see all possible objects. If objects are updated during a chunked list the version of the object that was present at the time the first list result was calculated is returned. | [optional] 
**resourceVersion** | **char \*** | When specified with a watch call, shows changes that occur after that particular version of a resource. Defaults to changes from the beginning of history. When specified for list: - if unset, then the result is returned from remote storage based on quorum-read flag; - if it&#39;s 0, then we simply return what we currently have in cache, no guarantee; - if set to non zero, then the result is at least as fresh as given rv. | [optional] 
**resourceVersionMatch** | **char \*** | resourceVersionMatch determines how resourceVersion is applied to list calls. It is highly recommended that resourceVersionMatch be set for list calls where resourceVersion is set See https://kubernetes.io/docs/reference/using-api/api-concepts/#resource-versions for details.  Defaults to unset | [optional] 
**timeoutSeconds** | **int** | Timeout for the list/watch call. This limits the duration of the call, regardless of any activity or inactivity. | [optional] 
**watch** | **int** | Watch for changes to the described resources and return them as a stream of add, update, and remove notifications. | [optional] 

### Return type

[object_t](object.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/json;stream=watch

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomObjectsAPI_patchClusterCustomObject**
```c
// patch the specified cluster scoped custom object
//
object_t* CustomObjectsAPI_patchClusterCustomObject(apiClient_t *apiClient, char * group, char * version, char * plural, char * name, object_t * body, char * dryRun, char * fieldManager, int force);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**group** | **char \*** | the custom resource&#39;s group | 
**version** | **char \*** | the custom resource&#39;s version | 
**plural** | **char \*** | the custom object&#39;s plural name. For TPRs this would be lowercase plural kind. | 
**name** | **char \*** | the custom object&#39;s name | 
**body** | **[object_t](object.md) \*** | The JSON schema of the Resource to patch. | 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. This field is required for apply requests (application/apply-patch) but optional for non-apply patch types (JsonPatch, MergePatch, StrategicMergePatch). | [optional] 
**force** | **int** | Force is going to \&quot;force\&quot; Apply requests. It means user will re-acquire conflicting fields owned by other people. Force flag must be unset for non-apply patch requests. | [optional] 

### Return type

[object_t](object.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: application/json-patch+json, application/merge-patch+json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomObjectsAPI_patchClusterCustomObjectScale**
```c
// partially update scale of the specified cluster scoped custom object
//
object_t* CustomObjectsAPI_patchClusterCustomObjectScale(apiClient_t *apiClient, char * group, char * version, char * plural, char * name, object_t * body, char * dryRun, char * fieldManager, int force);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**group** | **char \*** | the custom resource&#39;s group | 
**version** | **char \*** | the custom resource&#39;s version | 
**plural** | **char \*** | the custom resource&#39;s plural name. For TPRs this would be lowercase plural kind. | 
**name** | **char \*** | the custom object&#39;s name | 
**body** | **[object_t](object.md) \*** |  | 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. This field is required for apply requests (application/apply-patch) but optional for non-apply patch types (JsonPatch, MergePatch, StrategicMergePatch). | [optional] 
**force** | **int** | Force is going to \&quot;force\&quot; Apply requests. It means user will re-acquire conflicting fields owned by other people. Force flag must be unset for non-apply patch requests. | [optional] 

### Return type

[object_t](object.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: application/json-patch+json, application/merge-patch+json
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomObjectsAPI_patchClusterCustomObjectStatus**
```c
// partially update status of the specified cluster scoped custom object
//
object_t* CustomObjectsAPI_patchClusterCustomObjectStatus(apiClient_t *apiClient, char * group, char * version, char * plural, char * name, object_t * body, char * dryRun, char * fieldManager, int force);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**group** | **char \*** | the custom resource&#39;s group | 
**version** | **char \*** | the custom resource&#39;s version | 
**plural** | **char \*** | the custom resource&#39;s plural name. For TPRs this would be lowercase plural kind. | 
**name** | **char \*** | the custom object&#39;s name | 
**body** | **[object_t](object.md) \*** |  | 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. This field is required for apply requests (application/apply-patch) but optional for non-apply patch types (JsonPatch, MergePatch, StrategicMergePatch). | [optional] 
**force** | **int** | Force is going to \&quot;force\&quot; Apply requests. It means user will re-acquire conflicting fields owned by other people. Force flag must be unset for non-apply patch requests. | [optional] 

### Return type

[object_t](object.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: application/json-patch+json, application/merge-patch+json
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomObjectsAPI_patchNamespacedCustomObject**
```c
// patch the specified namespace scoped custom object
//
object_t* CustomObjectsAPI_patchNamespacedCustomObject(apiClient_t *apiClient, char * group, char * version, char * _namespace, char * plural, char * name, object_t * body, char * dryRun, char * fieldManager, int force);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**group** | **char \*** | the custom resource&#39;s group | 
**version** | **char \*** | the custom resource&#39;s version | 
**_namespace** | **char \*** | The custom resource&#39;s namespace | 
**plural** | **char \*** | the custom resource&#39;s plural name. For TPRs this would be lowercase plural kind. | 
**name** | **char \*** | the custom object&#39;s name | 
**body** | **[object_t](object.md) \*** | The JSON schema of the Resource to patch. | 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. This field is required for apply requests (application/apply-patch) but optional for non-apply patch types (JsonPatch, MergePatch, StrategicMergePatch). | [optional] 
**force** | **int** | Force is going to \&quot;force\&quot; Apply requests. It means user will re-acquire conflicting fields owned by other people. Force flag must be unset for non-apply patch requests. | [optional] 

### Return type

[object_t](object.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: application/json-patch+json, application/merge-patch+json
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomObjectsAPI_patchNamespacedCustomObjectScale**
```c
// partially update scale of the specified namespace scoped custom object
//
object_t* CustomObjectsAPI_patchNamespacedCustomObjectScale(apiClient_t *apiClient, char * group, char * version, char * _namespace, char * plural, char * name, object_t * body, char * dryRun, char * fieldManager, int force);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**group** | **char \*** | the custom resource&#39;s group | 
**version** | **char \*** | the custom resource&#39;s version | 
**_namespace** | **char \*** | The custom resource&#39;s namespace | 
**plural** | **char \*** | the custom resource&#39;s plural name. For TPRs this would be lowercase plural kind. | 
**name** | **char \*** | the custom object&#39;s name | 
**body** | **[object_t](object.md) \*** |  | 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. This field is required for apply requests (application/apply-patch) but optional for non-apply patch types (JsonPatch, MergePatch, StrategicMergePatch). | [optional] 
**force** | **int** | Force is going to \&quot;force\&quot; Apply requests. It means user will re-acquire conflicting fields owned by other people. Force flag must be unset for non-apply patch requests. | [optional] 

### Return type

[object_t](object.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: application/json-patch+json, application/merge-patch+json, application/apply-patch+yaml
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomObjectsAPI_patchNamespacedCustomObjectStatus**
```c
// partially update status of the specified namespace scoped custom object
//
object_t* CustomObjectsAPI_patchNamespacedCustomObjectStatus(apiClient_t *apiClient, char * group, char * version, char * _namespace, char * plural, char * name, object_t * body, char * dryRun, char * fieldManager, int force);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**group** | **char \*** | the custom resource&#39;s group | 
**version** | **char \*** | the custom resource&#39;s version | 
**_namespace** | **char \*** | The custom resource&#39;s namespace | 
**plural** | **char \*** | the custom resource&#39;s plural name. For TPRs this would be lowercase plural kind. | 
**name** | **char \*** | the custom object&#39;s name | 
**body** | **[object_t](object.md) \*** |  | 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. This field is required for apply requests (application/apply-patch) but optional for non-apply patch types (JsonPatch, MergePatch, StrategicMergePatch). | [optional] 
**force** | **int** | Force is going to \&quot;force\&quot; Apply requests. It means user will re-acquire conflicting fields owned by other people. Force flag must be unset for non-apply patch requests. | [optional] 

### Return type

[object_t](object.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: application/json-patch+json, application/merge-patch+json, application/apply-patch+yaml
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomObjectsAPI_replaceClusterCustomObject**
```c
// replace the specified cluster scoped custom object
//
object_t* CustomObjectsAPI_replaceClusterCustomObject(apiClient_t *apiClient, char * group, char * version, char * plural, char * name, object_t * body, char * dryRun, char * fieldManager);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**group** | **char \*** | the custom resource&#39;s group | 
**version** | **char \*** | the custom resource&#39;s version | 
**plural** | **char \*** | the custom object&#39;s plural name. For TPRs this would be lowercase plural kind. | 
**name** | **char \*** | the custom object&#39;s name | 
**body** | **[object_t](object.md) \*** | The JSON schema of the Resource to replace. | 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. | [optional] 

### Return type

[object_t](object.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomObjectsAPI_replaceClusterCustomObjectScale**
```c
// replace scale of the specified cluster scoped custom object
//
object_t* CustomObjectsAPI_replaceClusterCustomObjectScale(apiClient_t *apiClient, char * group, char * version, char * plural, char * name, object_t * body, char * dryRun, char * fieldManager);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**group** | **char \*** | the custom resource&#39;s group | 
**version** | **char \*** | the custom resource&#39;s version | 
**plural** | **char \*** | the custom resource&#39;s plural name. For TPRs this would be lowercase plural kind. | 
**name** | **char \*** | the custom object&#39;s name | 
**body** | **[object_t](object.md) \*** |  | 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. | [optional] 

### Return type

[object_t](object.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomObjectsAPI_replaceClusterCustomObjectStatus**
```c
// replace status of the cluster scoped specified custom object
//
object_t* CustomObjectsAPI_replaceClusterCustomObjectStatus(apiClient_t *apiClient, char * group, char * version, char * plural, char * name, object_t * body, char * dryRun, char * fieldManager);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**group** | **char \*** | the custom resource&#39;s group | 
**version** | **char \*** | the custom resource&#39;s version | 
**plural** | **char \*** | the custom resource&#39;s plural name. For TPRs this would be lowercase plural kind. | 
**name** | **char \*** | the custom object&#39;s name | 
**body** | **[object_t](object.md) \*** |  | 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. | [optional] 

### Return type

[object_t](object.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomObjectsAPI_replaceNamespacedCustomObject**
```c
// replace the specified namespace scoped custom object
//
object_t* CustomObjectsAPI_replaceNamespacedCustomObject(apiClient_t *apiClient, char * group, char * version, char * _namespace, char * plural, char * name, object_t * body, char * dryRun, char * fieldManager);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**group** | **char \*** | the custom resource&#39;s group | 
**version** | **char \*** | the custom resource&#39;s version | 
**_namespace** | **char \*** | The custom resource&#39;s namespace | 
**plural** | **char \*** | the custom resource&#39;s plural name. For TPRs this would be lowercase plural kind. | 
**name** | **char \*** | the custom object&#39;s name | 
**body** | **[object_t](object.md) \*** | The JSON schema of the Resource to replace. | 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. | [optional] 

### Return type

[object_t](object.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomObjectsAPI_replaceNamespacedCustomObjectScale**
```c
// replace scale of the specified namespace scoped custom object
//
object_t* CustomObjectsAPI_replaceNamespacedCustomObjectScale(apiClient_t *apiClient, char * group, char * version, char * _namespace, char * plural, char * name, object_t * body, char * dryRun, char * fieldManager);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**group** | **char \*** | the custom resource&#39;s group | 
**version** | **char \*** | the custom resource&#39;s version | 
**_namespace** | **char \*** | The custom resource&#39;s namespace | 
**plural** | **char \*** | the custom resource&#39;s plural name. For TPRs this would be lowercase plural kind. | 
**name** | **char \*** | the custom object&#39;s name | 
**body** | **[object_t](object.md) \*** |  | 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. | [optional] 

### Return type

[object_t](object.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **CustomObjectsAPI_replaceNamespacedCustomObjectStatus**
```c
// replace status of the specified namespace scoped custom object
//
object_t* CustomObjectsAPI_replaceNamespacedCustomObjectStatus(apiClient_t *apiClient, char * group, char * version, char * _namespace, char * plural, char * name, object_t * body, char * dryRun, char * fieldManager);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**group** | **char \*** | the custom resource&#39;s group | 
**version** | **char \*** | the custom resource&#39;s version | 
**_namespace** | **char \*** | The custom resource&#39;s namespace | 
**plural** | **char \*** | the custom resource&#39;s plural name. For TPRs this would be lowercase plural kind. | 
**name** | **char \*** | the custom object&#39;s name | 
**body** | **[object_t](object.md) \*** |  | 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. | [optional] 

### Return type

[object_t](object.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

