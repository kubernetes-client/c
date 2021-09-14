# AppsV1beta1API

All URIs are relative to *http://localhost*

Method | HTTP request | Description
------------- | ------------- | -------------
[**AppsV1beta1API_createNamespacedControllerRevision**](AppsV1beta1API.md#AppsV1beta1API_createNamespacedControllerRevision) | **POST** /apis/apps/v1beta1/namespaces/{namespace}/controllerrevisions | 
[**AppsV1beta1API_createNamespacedDeployment**](AppsV1beta1API.md#AppsV1beta1API_createNamespacedDeployment) | **POST** /apis/apps/v1beta1/namespaces/{namespace}/deployments | 
[**AppsV1beta1API_createNamespacedDeploymentRollback**](AppsV1beta1API.md#AppsV1beta1API_createNamespacedDeploymentRollback) | **POST** /apis/apps/v1beta1/namespaces/{namespace}/deployments/{name}/rollback | 
[**AppsV1beta1API_createNamespacedStatefulSet**](AppsV1beta1API.md#AppsV1beta1API_createNamespacedStatefulSet) | **POST** /apis/apps/v1beta1/namespaces/{namespace}/statefulsets | 
[**AppsV1beta1API_deleteCollectionNamespacedControllerRevision**](AppsV1beta1API.md#AppsV1beta1API_deleteCollectionNamespacedControllerRevision) | **DELETE** /apis/apps/v1beta1/namespaces/{namespace}/controllerrevisions | 
[**AppsV1beta1API_deleteCollectionNamespacedDeployment**](AppsV1beta1API.md#AppsV1beta1API_deleteCollectionNamespacedDeployment) | **DELETE** /apis/apps/v1beta1/namespaces/{namespace}/deployments | 
[**AppsV1beta1API_deleteCollectionNamespacedStatefulSet**](AppsV1beta1API.md#AppsV1beta1API_deleteCollectionNamespacedStatefulSet) | **DELETE** /apis/apps/v1beta1/namespaces/{namespace}/statefulsets | 
[**AppsV1beta1API_deleteNamespacedControllerRevision**](AppsV1beta1API.md#AppsV1beta1API_deleteNamespacedControllerRevision) | **DELETE** /apis/apps/v1beta1/namespaces/{namespace}/controllerrevisions/{name} | 
[**AppsV1beta1API_deleteNamespacedDeployment**](AppsV1beta1API.md#AppsV1beta1API_deleteNamespacedDeployment) | **DELETE** /apis/apps/v1beta1/namespaces/{namespace}/deployments/{name} | 
[**AppsV1beta1API_deleteNamespacedStatefulSet**](AppsV1beta1API.md#AppsV1beta1API_deleteNamespacedStatefulSet) | **DELETE** /apis/apps/v1beta1/namespaces/{namespace}/statefulsets/{name} | 
[**AppsV1beta1API_getAPIResources**](AppsV1beta1API.md#AppsV1beta1API_getAPIResources) | **GET** /apis/apps/v1beta1/ | 
[**AppsV1beta1API_listControllerRevisionForAllNamespaces**](AppsV1beta1API.md#AppsV1beta1API_listControllerRevisionForAllNamespaces) | **GET** /apis/apps/v1beta1/controllerrevisions | 
[**AppsV1beta1API_listDeploymentForAllNamespaces**](AppsV1beta1API.md#AppsV1beta1API_listDeploymentForAllNamespaces) | **GET** /apis/apps/v1beta1/deployments | 
[**AppsV1beta1API_listNamespacedControllerRevision**](AppsV1beta1API.md#AppsV1beta1API_listNamespacedControllerRevision) | **GET** /apis/apps/v1beta1/namespaces/{namespace}/controllerrevisions | 
[**AppsV1beta1API_listNamespacedDeployment**](AppsV1beta1API.md#AppsV1beta1API_listNamespacedDeployment) | **GET** /apis/apps/v1beta1/namespaces/{namespace}/deployments | 
[**AppsV1beta1API_listNamespacedStatefulSet**](AppsV1beta1API.md#AppsV1beta1API_listNamespacedStatefulSet) | **GET** /apis/apps/v1beta1/namespaces/{namespace}/statefulsets | 
[**AppsV1beta1API_listStatefulSetForAllNamespaces**](AppsV1beta1API.md#AppsV1beta1API_listStatefulSetForAllNamespaces) | **GET** /apis/apps/v1beta1/statefulsets | 
[**AppsV1beta1API_patchNamespacedControllerRevision**](AppsV1beta1API.md#AppsV1beta1API_patchNamespacedControllerRevision) | **PATCH** /apis/apps/v1beta1/namespaces/{namespace}/controllerrevisions/{name} | 
[**AppsV1beta1API_patchNamespacedDeployment**](AppsV1beta1API.md#AppsV1beta1API_patchNamespacedDeployment) | **PATCH** /apis/apps/v1beta1/namespaces/{namespace}/deployments/{name} | 
[**AppsV1beta1API_patchNamespacedDeploymentScale**](AppsV1beta1API.md#AppsV1beta1API_patchNamespacedDeploymentScale) | **PATCH** /apis/apps/v1beta1/namespaces/{namespace}/deployments/{name}/scale | 
[**AppsV1beta1API_patchNamespacedDeploymentStatus**](AppsV1beta1API.md#AppsV1beta1API_patchNamespacedDeploymentStatus) | **PATCH** /apis/apps/v1beta1/namespaces/{namespace}/deployments/{name}/status | 
[**AppsV1beta1API_patchNamespacedStatefulSet**](AppsV1beta1API.md#AppsV1beta1API_patchNamespacedStatefulSet) | **PATCH** /apis/apps/v1beta1/namespaces/{namespace}/statefulsets/{name} | 
[**AppsV1beta1API_patchNamespacedStatefulSetScale**](AppsV1beta1API.md#AppsV1beta1API_patchNamespacedStatefulSetScale) | **PATCH** /apis/apps/v1beta1/namespaces/{namespace}/statefulsets/{name}/scale | 
[**AppsV1beta1API_patchNamespacedStatefulSetStatus**](AppsV1beta1API.md#AppsV1beta1API_patchNamespacedStatefulSetStatus) | **PATCH** /apis/apps/v1beta1/namespaces/{namespace}/statefulsets/{name}/status | 
[**AppsV1beta1API_readNamespacedControllerRevision**](AppsV1beta1API.md#AppsV1beta1API_readNamespacedControllerRevision) | **GET** /apis/apps/v1beta1/namespaces/{namespace}/controllerrevisions/{name} | 
[**AppsV1beta1API_readNamespacedDeployment**](AppsV1beta1API.md#AppsV1beta1API_readNamespacedDeployment) | **GET** /apis/apps/v1beta1/namespaces/{namespace}/deployments/{name} | 
[**AppsV1beta1API_readNamespacedDeploymentScale**](AppsV1beta1API.md#AppsV1beta1API_readNamespacedDeploymentScale) | **GET** /apis/apps/v1beta1/namespaces/{namespace}/deployments/{name}/scale | 
[**AppsV1beta1API_readNamespacedDeploymentStatus**](AppsV1beta1API.md#AppsV1beta1API_readNamespacedDeploymentStatus) | **GET** /apis/apps/v1beta1/namespaces/{namespace}/deployments/{name}/status | 
[**AppsV1beta1API_readNamespacedStatefulSet**](AppsV1beta1API.md#AppsV1beta1API_readNamespacedStatefulSet) | **GET** /apis/apps/v1beta1/namespaces/{namespace}/statefulsets/{name} | 
[**AppsV1beta1API_readNamespacedStatefulSetScale**](AppsV1beta1API.md#AppsV1beta1API_readNamespacedStatefulSetScale) | **GET** /apis/apps/v1beta1/namespaces/{namespace}/statefulsets/{name}/scale | 
[**AppsV1beta1API_readNamespacedStatefulSetStatus**](AppsV1beta1API.md#AppsV1beta1API_readNamespacedStatefulSetStatus) | **GET** /apis/apps/v1beta1/namespaces/{namespace}/statefulsets/{name}/status | 
[**AppsV1beta1API_replaceNamespacedControllerRevision**](AppsV1beta1API.md#AppsV1beta1API_replaceNamespacedControllerRevision) | **PUT** /apis/apps/v1beta1/namespaces/{namespace}/controllerrevisions/{name} | 
[**AppsV1beta1API_replaceNamespacedDeployment**](AppsV1beta1API.md#AppsV1beta1API_replaceNamespacedDeployment) | **PUT** /apis/apps/v1beta1/namespaces/{namespace}/deployments/{name} | 
[**AppsV1beta1API_replaceNamespacedDeploymentScale**](AppsV1beta1API.md#AppsV1beta1API_replaceNamespacedDeploymentScale) | **PUT** /apis/apps/v1beta1/namespaces/{namespace}/deployments/{name}/scale | 
[**AppsV1beta1API_replaceNamespacedDeploymentStatus**](AppsV1beta1API.md#AppsV1beta1API_replaceNamespacedDeploymentStatus) | **PUT** /apis/apps/v1beta1/namespaces/{namespace}/deployments/{name}/status | 
[**AppsV1beta1API_replaceNamespacedStatefulSet**](AppsV1beta1API.md#AppsV1beta1API_replaceNamespacedStatefulSet) | **PUT** /apis/apps/v1beta1/namespaces/{namespace}/statefulsets/{name} | 
[**AppsV1beta1API_replaceNamespacedStatefulSetScale**](AppsV1beta1API.md#AppsV1beta1API_replaceNamespacedStatefulSetScale) | **PUT** /apis/apps/v1beta1/namespaces/{namespace}/statefulsets/{name}/scale | 
[**AppsV1beta1API_replaceNamespacedStatefulSetStatus**](AppsV1beta1API.md#AppsV1beta1API_replaceNamespacedStatefulSetStatus) | **PUT** /apis/apps/v1beta1/namespaces/{namespace}/statefulsets/{name}/status | 


# **AppsV1beta1API_createNamespacedControllerRevision**
```c
// create a ControllerRevision
//
v1beta1_controller_revision_t* AppsV1beta1API_createNamespacedControllerRevision(apiClient_t *apiClient, char * _namespace, v1beta1_controller_revision_t * body, char * pretty, char * dryRun, char * fieldManager);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**_namespace** | **char \*** | object name and auth scope, such as for teams and projects | 
**body** | **[v1beta1_controller_revision_t](v1beta1_controller_revision.md) \*** |  | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. | [optional] 

### Return type

[v1beta1_controller_revision_t](v1beta1_controller_revision.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AppsV1beta1API_createNamespacedDeployment**
```c
// create a Deployment
//
apps_v1beta1_deployment_t* AppsV1beta1API_createNamespacedDeployment(apiClient_t *apiClient, char * _namespace, apps_v1beta1_deployment_t * body, char * pretty, char * dryRun, char * fieldManager);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**_namespace** | **char \*** | object name and auth scope, such as for teams and projects | 
**body** | **[apps_v1beta1_deployment_t](apps_v1beta1_deployment.md) \*** |  | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. | [optional] 

### Return type

[apps_v1beta1_deployment_t](apps_v1beta1_deployment.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AppsV1beta1API_createNamespacedDeploymentRollback**
```c
// create rollback of a Deployment
//
v1_status_t* AppsV1beta1API_createNamespacedDeploymentRollback(apiClient_t *apiClient, char * name, char * _namespace, apps_v1beta1_deployment_rollback_t * body, char * dryRun, char * fieldManager, char * pretty);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**name** | **char \*** | name of the DeploymentRollback | 
**_namespace** | **char \*** | object name and auth scope, such as for teams and projects | 
**body** | **[apps_v1beta1_deployment_rollback_t](apps_v1beta1_deployment_rollback.md) \*** |  | 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. | [optional] 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 

### Return type

[v1_status_t](v1_status.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AppsV1beta1API_createNamespacedStatefulSet**
```c
// create a StatefulSet
//
v1beta1_stateful_set_t* AppsV1beta1API_createNamespacedStatefulSet(apiClient_t *apiClient, char * _namespace, v1beta1_stateful_set_t * body, char * pretty, char * dryRun, char * fieldManager);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**_namespace** | **char \*** | object name and auth scope, such as for teams and projects | 
**body** | **[v1beta1_stateful_set_t](v1beta1_stateful_set.md) \*** |  | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. | [optional] 

### Return type

[v1beta1_stateful_set_t](v1beta1_stateful_set.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AppsV1beta1API_deleteCollectionNamespacedControllerRevision**
```c
// delete collection of ControllerRevision
//
v1_status_t* AppsV1beta1API_deleteCollectionNamespacedControllerRevision(apiClient_t *apiClient, char * _namespace, char * pretty, char * _continue, char * dryRun, char * fieldSelector, int gracePeriodSeconds, char * labelSelector, int limit, int orphanDependents, char * propagationPolicy, char * resourceVersion, int timeoutSeconds, v1_delete_options_t * body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**_namespace** | **char \*** | object name and auth scope, such as for teams and projects | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 
**_continue** | **char \*** | The continue option should be set when retrieving more results from the server. Since this value is server defined, clients may only use the continue value from a previous query result with identical query parameters (except for the value of continue) and the server may reject a continue value it does not recognize. If the specified continue value is no longer valid whether due to expiration (generally five to fifteen minutes) or a configuration change on the server, the server will respond with a 410 ResourceExpired error together with a continue token. If the client needs a consistent list, it must restart their list without the continue field. Otherwise, the client may send another list request with the token received with the 410 error, the server will respond with a list starting from the next key, but from the latest snapshot, which is inconsistent from the previous list results - objects that are created, modified, or deleted after the first list request will be included in the response, as long as their keys are after the \&quot;next key\&quot;.  This field is not supported when watch is true. Clients may start a watch from the last resourceVersion value returned by the server and not miss any modifications. | [optional] 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldSelector** | **char \*** | A selector to restrict the list of returned objects by their fields. Defaults to everything. | [optional] 
**gracePeriodSeconds** | **int** | The duration in seconds before the object should be deleted. Value must be non-negative integer. The value zero indicates delete immediately. If this value is nil, the default grace period for the specified type will be used. Defaults to a per object value if not specified. zero means delete immediately. | [optional] 
**labelSelector** | **char \*** | A selector to restrict the list of returned objects by their labels. Defaults to everything. | [optional] 
**limit** | **int** | limit is a maximum number of responses to return for a list call. If more items exist, the server will set the &#x60;continue&#x60; field on the list metadata to a value that can be used with the same initial query to retrieve the next set of results. Setting a limit may return fewer than the requested amount of items (up to zero items) in the event all requested objects are filtered out and clients should only use the presence of the continue field to determine whether more results are available. Servers may choose not to support the limit argument and will return all of the available results. If limit is specified and the continue field is empty, clients may assume that no more results are available. This field is not supported if watch is true.  The server guarantees that the objects returned when using continue will be identical to issuing a single list call without a limit - that is, no objects created, modified, or deleted after the first request is issued will be included in any subsequent continued requests. This is sometimes referred to as a consistent snapshot, and ensures that a client that is using limit to receive smaller chunks of a very large result can ensure they see all possible objects. If objects are updated during a chunked list the version of the object that was present at the time the first list result was calculated is returned. | [optional] 
**orphanDependents** | **int** | Deprecated: please use the PropagationPolicy, this field will be deprecated in 1.7. Should the dependent objects be orphaned. If true/false, the \&quot;orphan\&quot; finalizer will be added to/removed from the object&#39;s finalizers list. Either this field or PropagationPolicy may be set, but not both. | [optional] 
**propagationPolicy** | **char \*** | Whether and how garbage collection will be performed. Either this field or OrphanDependents may be set, but not both. The default policy is decided by the existing finalizer set in the metadata.finalizers and the resource-specific default policy. Acceptable values are: &#39;Orphan&#39; - orphan the dependents; &#39;Background&#39; - allow the garbage collector to delete the dependents in the background; &#39;Foreground&#39; - a cascading policy that deletes all dependents in the foreground. | [optional] 
**resourceVersion** | **char \*** | When specified with a watch call, shows changes that occur after that particular version of a resource. Defaults to changes from the beginning of history. When specified for list: - if unset, then the result is returned from remote storage based on quorum-read flag; - if it&#39;s 0, then we simply return what we currently have in cache, no guarantee; - if set to non zero, then the result is at least as fresh as given rv. | [optional] 
**timeoutSeconds** | **int** | Timeout for the list/watch call. This limits the duration of the call, regardless of any activity or inactivity. | [optional] 
**body** | **[v1_delete_options_t](v1_delete_options.md) \*** |  | [optional] 

### Return type

[v1_status_t](v1_status.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AppsV1beta1API_deleteCollectionNamespacedDeployment**
```c
// delete collection of Deployment
//
v1_status_t* AppsV1beta1API_deleteCollectionNamespacedDeployment(apiClient_t *apiClient, char * _namespace, char * pretty, char * _continue, char * dryRun, char * fieldSelector, int gracePeriodSeconds, char * labelSelector, int limit, int orphanDependents, char * propagationPolicy, char * resourceVersion, int timeoutSeconds, v1_delete_options_t * body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**_namespace** | **char \*** | object name and auth scope, such as for teams and projects | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 
**_continue** | **char \*** | The continue option should be set when retrieving more results from the server. Since this value is server defined, clients may only use the continue value from a previous query result with identical query parameters (except for the value of continue) and the server may reject a continue value it does not recognize. If the specified continue value is no longer valid whether due to expiration (generally five to fifteen minutes) or a configuration change on the server, the server will respond with a 410 ResourceExpired error together with a continue token. If the client needs a consistent list, it must restart their list without the continue field. Otherwise, the client may send another list request with the token received with the 410 error, the server will respond with a list starting from the next key, but from the latest snapshot, which is inconsistent from the previous list results - objects that are created, modified, or deleted after the first list request will be included in the response, as long as their keys are after the \&quot;next key\&quot;.  This field is not supported when watch is true. Clients may start a watch from the last resourceVersion value returned by the server and not miss any modifications. | [optional] 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldSelector** | **char \*** | A selector to restrict the list of returned objects by their fields. Defaults to everything. | [optional] 
**gracePeriodSeconds** | **int** | The duration in seconds before the object should be deleted. Value must be non-negative integer. The value zero indicates delete immediately. If this value is nil, the default grace period for the specified type will be used. Defaults to a per object value if not specified. zero means delete immediately. | [optional] 
**labelSelector** | **char \*** | A selector to restrict the list of returned objects by their labels. Defaults to everything. | [optional] 
**limit** | **int** | limit is a maximum number of responses to return for a list call. If more items exist, the server will set the &#x60;continue&#x60; field on the list metadata to a value that can be used with the same initial query to retrieve the next set of results. Setting a limit may return fewer than the requested amount of items (up to zero items) in the event all requested objects are filtered out and clients should only use the presence of the continue field to determine whether more results are available. Servers may choose not to support the limit argument and will return all of the available results. If limit is specified and the continue field is empty, clients may assume that no more results are available. This field is not supported if watch is true.  The server guarantees that the objects returned when using continue will be identical to issuing a single list call without a limit - that is, no objects created, modified, or deleted after the first request is issued will be included in any subsequent continued requests. This is sometimes referred to as a consistent snapshot, and ensures that a client that is using limit to receive smaller chunks of a very large result can ensure they see all possible objects. If objects are updated during a chunked list the version of the object that was present at the time the first list result was calculated is returned. | [optional] 
**orphanDependents** | **int** | Deprecated: please use the PropagationPolicy, this field will be deprecated in 1.7. Should the dependent objects be orphaned. If true/false, the \&quot;orphan\&quot; finalizer will be added to/removed from the object&#39;s finalizers list. Either this field or PropagationPolicy may be set, but not both. | [optional] 
**propagationPolicy** | **char \*** | Whether and how garbage collection will be performed. Either this field or OrphanDependents may be set, but not both. The default policy is decided by the existing finalizer set in the metadata.finalizers and the resource-specific default policy. Acceptable values are: &#39;Orphan&#39; - orphan the dependents; &#39;Background&#39; - allow the garbage collector to delete the dependents in the background; &#39;Foreground&#39; - a cascading policy that deletes all dependents in the foreground. | [optional] 
**resourceVersion** | **char \*** | When specified with a watch call, shows changes that occur after that particular version of a resource. Defaults to changes from the beginning of history. When specified for list: - if unset, then the result is returned from remote storage based on quorum-read flag; - if it&#39;s 0, then we simply return what we currently have in cache, no guarantee; - if set to non zero, then the result is at least as fresh as given rv. | [optional] 
**timeoutSeconds** | **int** | Timeout for the list/watch call. This limits the duration of the call, regardless of any activity or inactivity. | [optional] 
**body** | **[v1_delete_options_t](v1_delete_options.md) \*** |  | [optional] 

### Return type

[v1_status_t](v1_status.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AppsV1beta1API_deleteCollectionNamespacedStatefulSet**
```c
// delete collection of StatefulSet
//
v1_status_t* AppsV1beta1API_deleteCollectionNamespacedStatefulSet(apiClient_t *apiClient, char * _namespace, char * pretty, char * _continue, char * dryRun, char * fieldSelector, int gracePeriodSeconds, char * labelSelector, int limit, int orphanDependents, char * propagationPolicy, char * resourceVersion, int timeoutSeconds, v1_delete_options_t * body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**_namespace** | **char \*** | object name and auth scope, such as for teams and projects | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 
**_continue** | **char \*** | The continue option should be set when retrieving more results from the server. Since this value is server defined, clients may only use the continue value from a previous query result with identical query parameters (except for the value of continue) and the server may reject a continue value it does not recognize. If the specified continue value is no longer valid whether due to expiration (generally five to fifteen minutes) or a configuration change on the server, the server will respond with a 410 ResourceExpired error together with a continue token. If the client needs a consistent list, it must restart their list without the continue field. Otherwise, the client may send another list request with the token received with the 410 error, the server will respond with a list starting from the next key, but from the latest snapshot, which is inconsistent from the previous list results - objects that are created, modified, or deleted after the first list request will be included in the response, as long as their keys are after the \&quot;next key\&quot;.  This field is not supported when watch is true. Clients may start a watch from the last resourceVersion value returned by the server and not miss any modifications. | [optional] 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldSelector** | **char \*** | A selector to restrict the list of returned objects by their fields. Defaults to everything. | [optional] 
**gracePeriodSeconds** | **int** | The duration in seconds before the object should be deleted. Value must be non-negative integer. The value zero indicates delete immediately. If this value is nil, the default grace period for the specified type will be used. Defaults to a per object value if not specified. zero means delete immediately. | [optional] 
**labelSelector** | **char \*** | A selector to restrict the list of returned objects by their labels. Defaults to everything. | [optional] 
**limit** | **int** | limit is a maximum number of responses to return for a list call. If more items exist, the server will set the &#x60;continue&#x60; field on the list metadata to a value that can be used with the same initial query to retrieve the next set of results. Setting a limit may return fewer than the requested amount of items (up to zero items) in the event all requested objects are filtered out and clients should only use the presence of the continue field to determine whether more results are available. Servers may choose not to support the limit argument and will return all of the available results. If limit is specified and the continue field is empty, clients may assume that no more results are available. This field is not supported if watch is true.  The server guarantees that the objects returned when using continue will be identical to issuing a single list call without a limit - that is, no objects created, modified, or deleted after the first request is issued will be included in any subsequent continued requests. This is sometimes referred to as a consistent snapshot, and ensures that a client that is using limit to receive smaller chunks of a very large result can ensure they see all possible objects. If objects are updated during a chunked list the version of the object that was present at the time the first list result was calculated is returned. | [optional] 
**orphanDependents** | **int** | Deprecated: please use the PropagationPolicy, this field will be deprecated in 1.7. Should the dependent objects be orphaned. If true/false, the \&quot;orphan\&quot; finalizer will be added to/removed from the object&#39;s finalizers list. Either this field or PropagationPolicy may be set, but not both. | [optional] 
**propagationPolicy** | **char \*** | Whether and how garbage collection will be performed. Either this field or OrphanDependents may be set, but not both. The default policy is decided by the existing finalizer set in the metadata.finalizers and the resource-specific default policy. Acceptable values are: &#39;Orphan&#39; - orphan the dependents; &#39;Background&#39; - allow the garbage collector to delete the dependents in the background; &#39;Foreground&#39; - a cascading policy that deletes all dependents in the foreground. | [optional] 
**resourceVersion** | **char \*** | When specified with a watch call, shows changes that occur after that particular version of a resource. Defaults to changes from the beginning of history. When specified for list: - if unset, then the result is returned from remote storage based on quorum-read flag; - if it&#39;s 0, then we simply return what we currently have in cache, no guarantee; - if set to non zero, then the result is at least as fresh as given rv. | [optional] 
**timeoutSeconds** | **int** | Timeout for the list/watch call. This limits the duration of the call, regardless of any activity or inactivity. | [optional] 
**body** | **[v1_delete_options_t](v1_delete_options.md) \*** |  | [optional] 

### Return type

[v1_status_t](v1_status.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AppsV1beta1API_deleteNamespacedControllerRevision**
```c
// delete a ControllerRevision
//
v1_status_t* AppsV1beta1API_deleteNamespacedControllerRevision(apiClient_t *apiClient, char * name, char * _namespace, char * pretty, char * dryRun, int gracePeriodSeconds, int orphanDependents, char * propagationPolicy, v1_delete_options_t * body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**name** | **char \*** | name of the ControllerRevision | 
**_namespace** | **char \*** | object name and auth scope, such as for teams and projects | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**gracePeriodSeconds** | **int** | The duration in seconds before the object should be deleted. Value must be non-negative integer. The value zero indicates delete immediately. If this value is nil, the default grace period for the specified type will be used. Defaults to a per object value if not specified. zero means delete immediately. | [optional] 
**orphanDependents** | **int** | Deprecated: please use the PropagationPolicy, this field will be deprecated in 1.7. Should the dependent objects be orphaned. If true/false, the \&quot;orphan\&quot; finalizer will be added to/removed from the object&#39;s finalizers list. Either this field or PropagationPolicy may be set, but not both. | [optional] 
**propagationPolicy** | **char \*** | Whether and how garbage collection will be performed. Either this field or OrphanDependents may be set, but not both. The default policy is decided by the existing finalizer set in the metadata.finalizers and the resource-specific default policy. Acceptable values are: &#39;Orphan&#39; - orphan the dependents; &#39;Background&#39; - allow the garbage collector to delete the dependents in the background; &#39;Foreground&#39; - a cascading policy that deletes all dependents in the foreground. | [optional] 
**body** | **[v1_delete_options_t](v1_delete_options.md) \*** |  | [optional] 

### Return type

[v1_status_t](v1_status.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AppsV1beta1API_deleteNamespacedDeployment**
```c
// delete a Deployment
//
v1_status_t* AppsV1beta1API_deleteNamespacedDeployment(apiClient_t *apiClient, char * name, char * _namespace, char * pretty, char * dryRun, int gracePeriodSeconds, int orphanDependents, char * propagationPolicy, v1_delete_options_t * body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**name** | **char \*** | name of the Deployment | 
**_namespace** | **char \*** | object name and auth scope, such as for teams and projects | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**gracePeriodSeconds** | **int** | The duration in seconds before the object should be deleted. Value must be non-negative integer. The value zero indicates delete immediately. If this value is nil, the default grace period for the specified type will be used. Defaults to a per object value if not specified. zero means delete immediately. | [optional] 
**orphanDependents** | **int** | Deprecated: please use the PropagationPolicy, this field will be deprecated in 1.7. Should the dependent objects be orphaned. If true/false, the \&quot;orphan\&quot; finalizer will be added to/removed from the object&#39;s finalizers list. Either this field or PropagationPolicy may be set, but not both. | [optional] 
**propagationPolicy** | **char \*** | Whether and how garbage collection will be performed. Either this field or OrphanDependents may be set, but not both. The default policy is decided by the existing finalizer set in the metadata.finalizers and the resource-specific default policy. Acceptable values are: &#39;Orphan&#39; - orphan the dependents; &#39;Background&#39; - allow the garbage collector to delete the dependents in the background; &#39;Foreground&#39; - a cascading policy that deletes all dependents in the foreground. | [optional] 
**body** | **[v1_delete_options_t](v1_delete_options.md) \*** |  | [optional] 

### Return type

[v1_status_t](v1_status.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AppsV1beta1API_deleteNamespacedStatefulSet**
```c
// delete a StatefulSet
//
v1_status_t* AppsV1beta1API_deleteNamespacedStatefulSet(apiClient_t *apiClient, char * name, char * _namespace, char * pretty, char * dryRun, int gracePeriodSeconds, int orphanDependents, char * propagationPolicy, v1_delete_options_t * body);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**name** | **char \*** | name of the StatefulSet | 
**_namespace** | **char \*** | object name and auth scope, such as for teams and projects | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**gracePeriodSeconds** | **int** | The duration in seconds before the object should be deleted. Value must be non-negative integer. The value zero indicates delete immediately. If this value is nil, the default grace period for the specified type will be used. Defaults to a per object value if not specified. zero means delete immediately. | [optional] 
**orphanDependents** | **int** | Deprecated: please use the PropagationPolicy, this field will be deprecated in 1.7. Should the dependent objects be orphaned. If true/false, the \&quot;orphan\&quot; finalizer will be added to/removed from the object&#39;s finalizers list. Either this field or PropagationPolicy may be set, but not both. | [optional] 
**propagationPolicy** | **char \*** | Whether and how garbage collection will be performed. Either this field or OrphanDependents may be set, but not both. The default policy is decided by the existing finalizer set in the metadata.finalizers and the resource-specific default policy. Acceptable values are: &#39;Orphan&#39; - orphan the dependents; &#39;Background&#39; - allow the garbage collector to delete the dependents in the background; &#39;Foreground&#39; - a cascading policy that deletes all dependents in the foreground. | [optional] 
**body** | **[v1_delete_options_t](v1_delete_options.md) \*** |  | [optional] 

### Return type

[v1_status_t](v1_status.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AppsV1beta1API_getAPIResources**
```c
// get available resources
//
v1_api_resource_list_t* AppsV1beta1API_getAPIResources(apiClient_t *apiClient);
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

# **AppsV1beta1API_listControllerRevisionForAllNamespaces**
```c
// list or watch objects of kind ControllerRevision
//
v1beta1_controller_revision_list_t* AppsV1beta1API_listControllerRevisionForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks, char * _continue, char * fieldSelector, char * labelSelector, int limit, char * pretty, char * resourceVersion, int timeoutSeconds, int watch);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**allowWatchBookmarks** | **int** | allowWatchBookmarks requests watch events with type \&quot;BOOKMARK\&quot;. Servers that do not implement bookmarks may ignore this flag and bookmarks are sent at the server&#39;s discretion. Clients should not assume bookmarks are returned at any specific interval, nor may they assume the server will send any BOOKMARK event during a session. If this is not a watch, this field is ignored. If the feature gate WatchBookmarks is not enabled in apiserver, this field is ignored. | [optional] 
**_continue** | **char \*** | The continue option should be set when retrieving more results from the server. Since this value is server defined, clients may only use the continue value from a previous query result with identical query parameters (except for the value of continue) and the server may reject a continue value it does not recognize. If the specified continue value is no longer valid whether due to expiration (generally five to fifteen minutes) or a configuration change on the server, the server will respond with a 410 ResourceExpired error together with a continue token. If the client needs a consistent list, it must restart their list without the continue field. Otherwise, the client may send another list request with the token received with the 410 error, the server will respond with a list starting from the next key, but from the latest snapshot, which is inconsistent from the previous list results - objects that are created, modified, or deleted after the first list request will be included in the response, as long as their keys are after the \&quot;next key\&quot;.  This field is not supported when watch is true. Clients may start a watch from the last resourceVersion value returned by the server and not miss any modifications. | [optional] 
**fieldSelector** | **char \*** | A selector to restrict the list of returned objects by their fields. Defaults to everything. | [optional] 
**labelSelector** | **char \*** | A selector to restrict the list of returned objects by their labels. Defaults to everything. | [optional] 
**limit** | **int** | limit is a maximum number of responses to return for a list call. If more items exist, the server will set the &#x60;continue&#x60; field on the list metadata to a value that can be used with the same initial query to retrieve the next set of results. Setting a limit may return fewer than the requested amount of items (up to zero items) in the event all requested objects are filtered out and clients should only use the presence of the continue field to determine whether more results are available. Servers may choose not to support the limit argument and will return all of the available results. If limit is specified and the continue field is empty, clients may assume that no more results are available. This field is not supported if watch is true.  The server guarantees that the objects returned when using continue will be identical to issuing a single list call without a limit - that is, no objects created, modified, or deleted after the first request is issued will be included in any subsequent continued requests. This is sometimes referred to as a consistent snapshot, and ensures that a client that is using limit to receive smaller chunks of a very large result can ensure they see all possible objects. If objects are updated during a chunked list the version of the object that was present at the time the first list result was calculated is returned. | [optional] 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 
**resourceVersion** | **char \*** | When specified with a watch call, shows changes that occur after that particular version of a resource. Defaults to changes from the beginning of history. When specified for list: - if unset, then the result is returned from remote storage based on quorum-read flag; - if it&#39;s 0, then we simply return what we currently have in cache, no guarantee; - if set to non zero, then the result is at least as fresh as given rv. | [optional] 
**timeoutSeconds** | **int** | Timeout for the list/watch call. This limits the duration of the call, regardless of any activity or inactivity. | [optional] 
**watch** | **int** | Watch for changes to the described resources and return them as a stream of add, update, and remove notifications. Specify resourceVersion. | [optional] 

### Return type

[v1beta1_controller_revision_list_t](v1beta1_controller_revision_list.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf, application/json;stream=watch, application/vnd.kubernetes.protobuf;stream=watch

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AppsV1beta1API_listDeploymentForAllNamespaces**
```c
// list or watch objects of kind Deployment
//
apps_v1beta1_deployment_list_t* AppsV1beta1API_listDeploymentForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks, char * _continue, char * fieldSelector, char * labelSelector, int limit, char * pretty, char * resourceVersion, int timeoutSeconds, int watch);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**allowWatchBookmarks** | **int** | allowWatchBookmarks requests watch events with type \&quot;BOOKMARK\&quot;. Servers that do not implement bookmarks may ignore this flag and bookmarks are sent at the server&#39;s discretion. Clients should not assume bookmarks are returned at any specific interval, nor may they assume the server will send any BOOKMARK event during a session. If this is not a watch, this field is ignored. If the feature gate WatchBookmarks is not enabled in apiserver, this field is ignored. | [optional] 
**_continue** | **char \*** | The continue option should be set when retrieving more results from the server. Since this value is server defined, clients may only use the continue value from a previous query result with identical query parameters (except for the value of continue) and the server may reject a continue value it does not recognize. If the specified continue value is no longer valid whether due to expiration (generally five to fifteen minutes) or a configuration change on the server, the server will respond with a 410 ResourceExpired error together with a continue token. If the client needs a consistent list, it must restart their list without the continue field. Otherwise, the client may send another list request with the token received with the 410 error, the server will respond with a list starting from the next key, but from the latest snapshot, which is inconsistent from the previous list results - objects that are created, modified, or deleted after the first list request will be included in the response, as long as their keys are after the \&quot;next key\&quot;.  This field is not supported when watch is true. Clients may start a watch from the last resourceVersion value returned by the server and not miss any modifications. | [optional] 
**fieldSelector** | **char \*** | A selector to restrict the list of returned objects by their fields. Defaults to everything. | [optional] 
**labelSelector** | **char \*** | A selector to restrict the list of returned objects by their labels. Defaults to everything. | [optional] 
**limit** | **int** | limit is a maximum number of responses to return for a list call. If more items exist, the server will set the &#x60;continue&#x60; field on the list metadata to a value that can be used with the same initial query to retrieve the next set of results. Setting a limit may return fewer than the requested amount of items (up to zero items) in the event all requested objects are filtered out and clients should only use the presence of the continue field to determine whether more results are available. Servers may choose not to support the limit argument and will return all of the available results. If limit is specified and the continue field is empty, clients may assume that no more results are available. This field is not supported if watch is true.  The server guarantees that the objects returned when using continue will be identical to issuing a single list call without a limit - that is, no objects created, modified, or deleted after the first request is issued will be included in any subsequent continued requests. This is sometimes referred to as a consistent snapshot, and ensures that a client that is using limit to receive smaller chunks of a very large result can ensure they see all possible objects. If objects are updated during a chunked list the version of the object that was present at the time the first list result was calculated is returned. | [optional] 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 
**resourceVersion** | **char \*** | When specified with a watch call, shows changes that occur after that particular version of a resource. Defaults to changes from the beginning of history. When specified for list: - if unset, then the result is returned from remote storage based on quorum-read flag; - if it&#39;s 0, then we simply return what we currently have in cache, no guarantee; - if set to non zero, then the result is at least as fresh as given rv. | [optional] 
**timeoutSeconds** | **int** | Timeout for the list/watch call. This limits the duration of the call, regardless of any activity or inactivity. | [optional] 
**watch** | **int** | Watch for changes to the described resources and return them as a stream of add, update, and remove notifications. Specify resourceVersion. | [optional] 

### Return type

[apps_v1beta1_deployment_list_t](apps_v1beta1_deployment_list.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf, application/json;stream=watch, application/vnd.kubernetes.protobuf;stream=watch

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AppsV1beta1API_listNamespacedControllerRevision**
```c
// list or watch objects of kind ControllerRevision
//
v1beta1_controller_revision_list_t* AppsV1beta1API_listNamespacedControllerRevision(apiClient_t *apiClient, char * _namespace, char * pretty, int allowWatchBookmarks, char * _continue, char * fieldSelector, char * labelSelector, int limit, char * resourceVersion, int timeoutSeconds, int watch);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**_namespace** | **char \*** | object name and auth scope, such as for teams and projects | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 
**allowWatchBookmarks** | **int** | allowWatchBookmarks requests watch events with type \&quot;BOOKMARK\&quot;. Servers that do not implement bookmarks may ignore this flag and bookmarks are sent at the server&#39;s discretion. Clients should not assume bookmarks are returned at any specific interval, nor may they assume the server will send any BOOKMARK event during a session. If this is not a watch, this field is ignored. If the feature gate WatchBookmarks is not enabled in apiserver, this field is ignored. | [optional] 
**_continue** | **char \*** | The continue option should be set when retrieving more results from the server. Since this value is server defined, clients may only use the continue value from a previous query result with identical query parameters (except for the value of continue) and the server may reject a continue value it does not recognize. If the specified continue value is no longer valid whether due to expiration (generally five to fifteen minutes) or a configuration change on the server, the server will respond with a 410 ResourceExpired error together with a continue token. If the client needs a consistent list, it must restart their list without the continue field. Otherwise, the client may send another list request with the token received with the 410 error, the server will respond with a list starting from the next key, but from the latest snapshot, which is inconsistent from the previous list results - objects that are created, modified, or deleted after the first list request will be included in the response, as long as their keys are after the \&quot;next key\&quot;.  This field is not supported when watch is true. Clients may start a watch from the last resourceVersion value returned by the server and not miss any modifications. | [optional] 
**fieldSelector** | **char \*** | A selector to restrict the list of returned objects by their fields. Defaults to everything. | [optional] 
**labelSelector** | **char \*** | A selector to restrict the list of returned objects by their labels. Defaults to everything. | [optional] 
**limit** | **int** | limit is a maximum number of responses to return for a list call. If more items exist, the server will set the &#x60;continue&#x60; field on the list metadata to a value that can be used with the same initial query to retrieve the next set of results. Setting a limit may return fewer than the requested amount of items (up to zero items) in the event all requested objects are filtered out and clients should only use the presence of the continue field to determine whether more results are available. Servers may choose not to support the limit argument and will return all of the available results. If limit is specified and the continue field is empty, clients may assume that no more results are available. This field is not supported if watch is true.  The server guarantees that the objects returned when using continue will be identical to issuing a single list call without a limit - that is, no objects created, modified, or deleted after the first request is issued will be included in any subsequent continued requests. This is sometimes referred to as a consistent snapshot, and ensures that a client that is using limit to receive smaller chunks of a very large result can ensure they see all possible objects. If objects are updated during a chunked list the version of the object that was present at the time the first list result was calculated is returned. | [optional] 
**resourceVersion** | **char \*** | When specified with a watch call, shows changes that occur after that particular version of a resource. Defaults to changes from the beginning of history. When specified for list: - if unset, then the result is returned from remote storage based on quorum-read flag; - if it&#39;s 0, then we simply return what we currently have in cache, no guarantee; - if set to non zero, then the result is at least as fresh as given rv. | [optional] 
**timeoutSeconds** | **int** | Timeout for the list/watch call. This limits the duration of the call, regardless of any activity or inactivity. | [optional] 
**watch** | **int** | Watch for changes to the described resources and return them as a stream of add, update, and remove notifications. Specify resourceVersion. | [optional] 

### Return type

[v1beta1_controller_revision_list_t](v1beta1_controller_revision_list.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf, application/json;stream=watch, application/vnd.kubernetes.protobuf;stream=watch

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AppsV1beta1API_listNamespacedDeployment**
```c
// list or watch objects of kind Deployment
//
apps_v1beta1_deployment_list_t* AppsV1beta1API_listNamespacedDeployment(apiClient_t *apiClient, char * _namespace, char * pretty, int allowWatchBookmarks, char * _continue, char * fieldSelector, char * labelSelector, int limit, char * resourceVersion, int timeoutSeconds, int watch);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**_namespace** | **char \*** | object name and auth scope, such as for teams and projects | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 
**allowWatchBookmarks** | **int** | allowWatchBookmarks requests watch events with type \&quot;BOOKMARK\&quot;. Servers that do not implement bookmarks may ignore this flag and bookmarks are sent at the server&#39;s discretion. Clients should not assume bookmarks are returned at any specific interval, nor may they assume the server will send any BOOKMARK event during a session. If this is not a watch, this field is ignored. If the feature gate WatchBookmarks is not enabled in apiserver, this field is ignored. | [optional] 
**_continue** | **char \*** | The continue option should be set when retrieving more results from the server. Since this value is server defined, clients may only use the continue value from a previous query result with identical query parameters (except for the value of continue) and the server may reject a continue value it does not recognize. If the specified continue value is no longer valid whether due to expiration (generally five to fifteen minutes) or a configuration change on the server, the server will respond with a 410 ResourceExpired error together with a continue token. If the client needs a consistent list, it must restart their list without the continue field. Otherwise, the client may send another list request with the token received with the 410 error, the server will respond with a list starting from the next key, but from the latest snapshot, which is inconsistent from the previous list results - objects that are created, modified, or deleted after the first list request will be included in the response, as long as their keys are after the \&quot;next key\&quot;.  This field is not supported when watch is true. Clients may start a watch from the last resourceVersion value returned by the server and not miss any modifications. | [optional] 
**fieldSelector** | **char \*** | A selector to restrict the list of returned objects by their fields. Defaults to everything. | [optional] 
**labelSelector** | **char \*** | A selector to restrict the list of returned objects by their labels. Defaults to everything. | [optional] 
**limit** | **int** | limit is a maximum number of responses to return for a list call. If more items exist, the server will set the &#x60;continue&#x60; field on the list metadata to a value that can be used with the same initial query to retrieve the next set of results. Setting a limit may return fewer than the requested amount of items (up to zero items) in the event all requested objects are filtered out and clients should only use the presence of the continue field to determine whether more results are available. Servers may choose not to support the limit argument and will return all of the available results. If limit is specified and the continue field is empty, clients may assume that no more results are available. This field is not supported if watch is true.  The server guarantees that the objects returned when using continue will be identical to issuing a single list call without a limit - that is, no objects created, modified, or deleted after the first request is issued will be included in any subsequent continued requests. This is sometimes referred to as a consistent snapshot, and ensures that a client that is using limit to receive smaller chunks of a very large result can ensure they see all possible objects. If objects are updated during a chunked list the version of the object that was present at the time the first list result was calculated is returned. | [optional] 
**resourceVersion** | **char \*** | When specified with a watch call, shows changes that occur after that particular version of a resource. Defaults to changes from the beginning of history. When specified for list: - if unset, then the result is returned from remote storage based on quorum-read flag; - if it&#39;s 0, then we simply return what we currently have in cache, no guarantee; - if set to non zero, then the result is at least as fresh as given rv. | [optional] 
**timeoutSeconds** | **int** | Timeout for the list/watch call. This limits the duration of the call, regardless of any activity or inactivity. | [optional] 
**watch** | **int** | Watch for changes to the described resources and return them as a stream of add, update, and remove notifications. Specify resourceVersion. | [optional] 

### Return type

[apps_v1beta1_deployment_list_t](apps_v1beta1_deployment_list.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf, application/json;stream=watch, application/vnd.kubernetes.protobuf;stream=watch

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AppsV1beta1API_listNamespacedStatefulSet**
```c
// list or watch objects of kind StatefulSet
//
v1beta1_stateful_set_list_t* AppsV1beta1API_listNamespacedStatefulSet(apiClient_t *apiClient, char * _namespace, char * pretty, int allowWatchBookmarks, char * _continue, char * fieldSelector, char * labelSelector, int limit, char * resourceVersion, int timeoutSeconds, int watch);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**_namespace** | **char \*** | object name and auth scope, such as for teams and projects | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 
**allowWatchBookmarks** | **int** | allowWatchBookmarks requests watch events with type \&quot;BOOKMARK\&quot;. Servers that do not implement bookmarks may ignore this flag and bookmarks are sent at the server&#39;s discretion. Clients should not assume bookmarks are returned at any specific interval, nor may they assume the server will send any BOOKMARK event during a session. If this is not a watch, this field is ignored. If the feature gate WatchBookmarks is not enabled in apiserver, this field is ignored. | [optional] 
**_continue** | **char \*** | The continue option should be set when retrieving more results from the server. Since this value is server defined, clients may only use the continue value from a previous query result with identical query parameters (except for the value of continue) and the server may reject a continue value it does not recognize. If the specified continue value is no longer valid whether due to expiration (generally five to fifteen minutes) or a configuration change on the server, the server will respond with a 410 ResourceExpired error together with a continue token. If the client needs a consistent list, it must restart their list without the continue field. Otherwise, the client may send another list request with the token received with the 410 error, the server will respond with a list starting from the next key, but from the latest snapshot, which is inconsistent from the previous list results - objects that are created, modified, or deleted after the first list request will be included in the response, as long as their keys are after the \&quot;next key\&quot;.  This field is not supported when watch is true. Clients may start a watch from the last resourceVersion value returned by the server and not miss any modifications. | [optional] 
**fieldSelector** | **char \*** | A selector to restrict the list of returned objects by their fields. Defaults to everything. | [optional] 
**labelSelector** | **char \*** | A selector to restrict the list of returned objects by their labels. Defaults to everything. | [optional] 
**limit** | **int** | limit is a maximum number of responses to return for a list call. If more items exist, the server will set the &#x60;continue&#x60; field on the list metadata to a value that can be used with the same initial query to retrieve the next set of results. Setting a limit may return fewer than the requested amount of items (up to zero items) in the event all requested objects are filtered out and clients should only use the presence of the continue field to determine whether more results are available. Servers may choose not to support the limit argument and will return all of the available results. If limit is specified and the continue field is empty, clients may assume that no more results are available. This field is not supported if watch is true.  The server guarantees that the objects returned when using continue will be identical to issuing a single list call without a limit - that is, no objects created, modified, or deleted after the first request is issued will be included in any subsequent continued requests. This is sometimes referred to as a consistent snapshot, and ensures that a client that is using limit to receive smaller chunks of a very large result can ensure they see all possible objects. If objects are updated during a chunked list the version of the object that was present at the time the first list result was calculated is returned. | [optional] 
**resourceVersion** | **char \*** | When specified with a watch call, shows changes that occur after that particular version of a resource. Defaults to changes from the beginning of history. When specified for list: - if unset, then the result is returned from remote storage based on quorum-read flag; - if it&#39;s 0, then we simply return what we currently have in cache, no guarantee; - if set to non zero, then the result is at least as fresh as given rv. | [optional] 
**timeoutSeconds** | **int** | Timeout for the list/watch call. This limits the duration of the call, regardless of any activity or inactivity. | [optional] 
**watch** | **int** | Watch for changes to the described resources and return them as a stream of add, update, and remove notifications. Specify resourceVersion. | [optional] 

### Return type

[v1beta1_stateful_set_list_t](v1beta1_stateful_set_list.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf, application/json;stream=watch, application/vnd.kubernetes.protobuf;stream=watch

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AppsV1beta1API_listStatefulSetForAllNamespaces**
```c
// list or watch objects of kind StatefulSet
//
v1beta1_stateful_set_list_t* AppsV1beta1API_listStatefulSetForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks, char * _continue, char * fieldSelector, char * labelSelector, int limit, char * pretty, char * resourceVersion, int timeoutSeconds, int watch);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**allowWatchBookmarks** | **int** | allowWatchBookmarks requests watch events with type \&quot;BOOKMARK\&quot;. Servers that do not implement bookmarks may ignore this flag and bookmarks are sent at the server&#39;s discretion. Clients should not assume bookmarks are returned at any specific interval, nor may they assume the server will send any BOOKMARK event during a session. If this is not a watch, this field is ignored. If the feature gate WatchBookmarks is not enabled in apiserver, this field is ignored. | [optional] 
**_continue** | **char \*** | The continue option should be set when retrieving more results from the server. Since this value is server defined, clients may only use the continue value from a previous query result with identical query parameters (except for the value of continue) and the server may reject a continue value it does not recognize. If the specified continue value is no longer valid whether due to expiration (generally five to fifteen minutes) or a configuration change on the server, the server will respond with a 410 ResourceExpired error together with a continue token. If the client needs a consistent list, it must restart their list without the continue field. Otherwise, the client may send another list request with the token received with the 410 error, the server will respond with a list starting from the next key, but from the latest snapshot, which is inconsistent from the previous list results - objects that are created, modified, or deleted after the first list request will be included in the response, as long as their keys are after the \&quot;next key\&quot;.  This field is not supported when watch is true. Clients may start a watch from the last resourceVersion value returned by the server and not miss any modifications. | [optional] 
**fieldSelector** | **char \*** | A selector to restrict the list of returned objects by their fields. Defaults to everything. | [optional] 
**labelSelector** | **char \*** | A selector to restrict the list of returned objects by their labels. Defaults to everything. | [optional] 
**limit** | **int** | limit is a maximum number of responses to return for a list call. If more items exist, the server will set the &#x60;continue&#x60; field on the list metadata to a value that can be used with the same initial query to retrieve the next set of results. Setting a limit may return fewer than the requested amount of items (up to zero items) in the event all requested objects are filtered out and clients should only use the presence of the continue field to determine whether more results are available. Servers may choose not to support the limit argument and will return all of the available results. If limit is specified and the continue field is empty, clients may assume that no more results are available. This field is not supported if watch is true.  The server guarantees that the objects returned when using continue will be identical to issuing a single list call without a limit - that is, no objects created, modified, or deleted after the first request is issued will be included in any subsequent continued requests. This is sometimes referred to as a consistent snapshot, and ensures that a client that is using limit to receive smaller chunks of a very large result can ensure they see all possible objects. If objects are updated during a chunked list the version of the object that was present at the time the first list result was calculated is returned. | [optional] 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 
**resourceVersion** | **char \*** | When specified with a watch call, shows changes that occur after that particular version of a resource. Defaults to changes from the beginning of history. When specified for list: - if unset, then the result is returned from remote storage based on quorum-read flag; - if it&#39;s 0, then we simply return what we currently have in cache, no guarantee; - if set to non zero, then the result is at least as fresh as given rv. | [optional] 
**timeoutSeconds** | **int** | Timeout for the list/watch call. This limits the duration of the call, regardless of any activity or inactivity. | [optional] 
**watch** | **int** | Watch for changes to the described resources and return them as a stream of add, update, and remove notifications. Specify resourceVersion. | [optional] 

### Return type

[v1beta1_stateful_set_list_t](v1beta1_stateful_set_list.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf, application/json;stream=watch, application/vnd.kubernetes.protobuf;stream=watch

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AppsV1beta1API_patchNamespacedControllerRevision**
```c
// partially update the specified ControllerRevision
//
v1beta1_controller_revision_t* AppsV1beta1API_patchNamespacedControllerRevision(apiClient_t *apiClient, char * name, char * _namespace, object_t * body, char * pretty, char * dryRun, char * fieldManager, int force);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**name** | **char \*** | name of the ControllerRevision | 
**_namespace** | **char \*** | object name and auth scope, such as for teams and projects | 
**body** | **[object_t](object.md) \*** |  | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. This field is required for apply requests (application/apply-patch) but optional for non-apply patch types (JsonPatch, MergePatch, StrategicMergePatch). | [optional] 
**force** | **int** | Force is going to \&quot;force\&quot; Apply requests. It means user will re-acquire conflicting fields owned by other people. Force flag must be unset for non-apply patch requests. | [optional] 

### Return type

[v1beta1_controller_revision_t](v1beta1_controller_revision.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: application/json-patch+json, application/merge-patch+json, application/strategic-merge-patch+json, application/apply-patch+yaml
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AppsV1beta1API_patchNamespacedDeployment**
```c
// partially update the specified Deployment
//
apps_v1beta1_deployment_t* AppsV1beta1API_patchNamespacedDeployment(apiClient_t *apiClient, char * name, char * _namespace, object_t * body, char * pretty, char * dryRun, char * fieldManager, int force);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**name** | **char \*** | name of the Deployment | 
**_namespace** | **char \*** | object name and auth scope, such as for teams and projects | 
**body** | **[object_t](object.md) \*** |  | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. This field is required for apply requests (application/apply-patch) but optional for non-apply patch types (JsonPatch, MergePatch, StrategicMergePatch). | [optional] 
**force** | **int** | Force is going to \&quot;force\&quot; Apply requests. It means user will re-acquire conflicting fields owned by other people. Force flag must be unset for non-apply patch requests. | [optional] 

### Return type

[apps_v1beta1_deployment_t](apps_v1beta1_deployment.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: application/json-patch+json, application/merge-patch+json, application/strategic-merge-patch+json, application/apply-patch+yaml
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AppsV1beta1API_patchNamespacedDeploymentScale**
```c
// partially update scale of the specified Deployment
//
apps_v1beta1_scale_t* AppsV1beta1API_patchNamespacedDeploymentScale(apiClient_t *apiClient, char * name, char * _namespace, object_t * body, char * pretty, char * dryRun, char * fieldManager, int force);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**name** | **char \*** | name of the Scale | 
**_namespace** | **char \*** | object name and auth scope, such as for teams and projects | 
**body** | **[object_t](object.md) \*** |  | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. This field is required for apply requests (application/apply-patch) but optional for non-apply patch types (JsonPatch, MergePatch, StrategicMergePatch). | [optional] 
**force** | **int** | Force is going to \&quot;force\&quot; Apply requests. It means user will re-acquire conflicting fields owned by other people. Force flag must be unset for non-apply patch requests. | [optional] 

### Return type

[apps_v1beta1_scale_t](apps_v1beta1_scale.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: application/json-patch+json, application/merge-patch+json, application/strategic-merge-patch+json, application/apply-patch+yaml
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AppsV1beta1API_patchNamespacedDeploymentStatus**
```c
// partially update status of the specified Deployment
//
apps_v1beta1_deployment_t* AppsV1beta1API_patchNamespacedDeploymentStatus(apiClient_t *apiClient, char * name, char * _namespace, object_t * body, char * pretty, char * dryRun, char * fieldManager, int force);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**name** | **char \*** | name of the Deployment | 
**_namespace** | **char \*** | object name and auth scope, such as for teams and projects | 
**body** | **[object_t](object.md) \*** |  | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. This field is required for apply requests (application/apply-patch) but optional for non-apply patch types (JsonPatch, MergePatch, StrategicMergePatch). | [optional] 
**force** | **int** | Force is going to \&quot;force\&quot; Apply requests. It means user will re-acquire conflicting fields owned by other people. Force flag must be unset for non-apply patch requests. | [optional] 

### Return type

[apps_v1beta1_deployment_t](apps_v1beta1_deployment.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: application/json-patch+json, application/merge-patch+json, application/strategic-merge-patch+json, application/apply-patch+yaml
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AppsV1beta1API_patchNamespacedStatefulSet**
```c
// partially update the specified StatefulSet
//
v1beta1_stateful_set_t* AppsV1beta1API_patchNamespacedStatefulSet(apiClient_t *apiClient, char * name, char * _namespace, object_t * body, char * pretty, char * dryRun, char * fieldManager, int force);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**name** | **char \*** | name of the StatefulSet | 
**_namespace** | **char \*** | object name and auth scope, such as for teams and projects | 
**body** | **[object_t](object.md) \*** |  | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. This field is required for apply requests (application/apply-patch) but optional for non-apply patch types (JsonPatch, MergePatch, StrategicMergePatch). | [optional] 
**force** | **int** | Force is going to \&quot;force\&quot; Apply requests. It means user will re-acquire conflicting fields owned by other people. Force flag must be unset for non-apply patch requests. | [optional] 

### Return type

[v1beta1_stateful_set_t](v1beta1_stateful_set.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: application/json-patch+json, application/merge-patch+json, application/strategic-merge-patch+json, application/apply-patch+yaml
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AppsV1beta1API_patchNamespacedStatefulSetScale**
```c
// partially update scale of the specified StatefulSet
//
apps_v1beta1_scale_t* AppsV1beta1API_patchNamespacedStatefulSetScale(apiClient_t *apiClient, char * name, char * _namespace, object_t * body, char * pretty, char * dryRun, char * fieldManager, int force);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**name** | **char \*** | name of the Scale | 
**_namespace** | **char \*** | object name and auth scope, such as for teams and projects | 
**body** | **[object_t](object.md) \*** |  | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. This field is required for apply requests (application/apply-patch) but optional for non-apply patch types (JsonPatch, MergePatch, StrategicMergePatch). | [optional] 
**force** | **int** | Force is going to \&quot;force\&quot; Apply requests. It means user will re-acquire conflicting fields owned by other people. Force flag must be unset for non-apply patch requests. | [optional] 

### Return type

[apps_v1beta1_scale_t](apps_v1beta1_scale.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: application/json-patch+json, application/merge-patch+json, application/strategic-merge-patch+json, application/apply-patch+yaml
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AppsV1beta1API_patchNamespacedStatefulSetStatus**
```c
// partially update status of the specified StatefulSet
//
v1beta1_stateful_set_t* AppsV1beta1API_patchNamespacedStatefulSetStatus(apiClient_t *apiClient, char * name, char * _namespace, object_t * body, char * pretty, char * dryRun, char * fieldManager, int force);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**name** | **char \*** | name of the StatefulSet | 
**_namespace** | **char \*** | object name and auth scope, such as for teams and projects | 
**body** | **[object_t](object.md) \*** |  | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. This field is required for apply requests (application/apply-patch) but optional for non-apply patch types (JsonPatch, MergePatch, StrategicMergePatch). | [optional] 
**force** | **int** | Force is going to \&quot;force\&quot; Apply requests. It means user will re-acquire conflicting fields owned by other people. Force flag must be unset for non-apply patch requests. | [optional] 

### Return type

[v1beta1_stateful_set_t](v1beta1_stateful_set.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: application/json-patch+json, application/merge-patch+json, application/strategic-merge-patch+json, application/apply-patch+yaml
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AppsV1beta1API_readNamespacedControllerRevision**
```c
// read the specified ControllerRevision
//
v1beta1_controller_revision_t* AppsV1beta1API_readNamespacedControllerRevision(apiClient_t *apiClient, char * name, char * _namespace, char * pretty, int exact, int _export);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**name** | **char \*** | name of the ControllerRevision | 
**_namespace** | **char \*** | object name and auth scope, such as for teams and projects | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 
**exact** | **int** | Should the export be exact.  Exact export maintains cluster-specific fields like &#39;Namespace&#39;. Deprecated. Planned for removal in 1.18. | [optional] 
**_export** | **int** | Should this value be exported.  Export strips fields that a user can not specify. Deprecated. Planned for removal in 1.18. | [optional] 

### Return type

[v1beta1_controller_revision_t](v1beta1_controller_revision.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AppsV1beta1API_readNamespacedDeployment**
```c
// read the specified Deployment
//
apps_v1beta1_deployment_t* AppsV1beta1API_readNamespacedDeployment(apiClient_t *apiClient, char * name, char * _namespace, char * pretty, int exact, int _export);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**name** | **char \*** | name of the Deployment | 
**_namespace** | **char \*** | object name and auth scope, such as for teams and projects | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 
**exact** | **int** | Should the export be exact.  Exact export maintains cluster-specific fields like &#39;Namespace&#39;. Deprecated. Planned for removal in 1.18. | [optional] 
**_export** | **int** | Should this value be exported.  Export strips fields that a user can not specify. Deprecated. Planned for removal in 1.18. | [optional] 

### Return type

[apps_v1beta1_deployment_t](apps_v1beta1_deployment.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AppsV1beta1API_readNamespacedDeploymentScale**
```c
// read scale of the specified Deployment
//
apps_v1beta1_scale_t* AppsV1beta1API_readNamespacedDeploymentScale(apiClient_t *apiClient, char * name, char * _namespace, char * pretty);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**name** | **char \*** | name of the Scale | 
**_namespace** | **char \*** | object name and auth scope, such as for teams and projects | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 

### Return type

[apps_v1beta1_scale_t](apps_v1beta1_scale.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AppsV1beta1API_readNamespacedDeploymentStatus**
```c
// read status of the specified Deployment
//
apps_v1beta1_deployment_t* AppsV1beta1API_readNamespacedDeploymentStatus(apiClient_t *apiClient, char * name, char * _namespace, char * pretty);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**name** | **char \*** | name of the Deployment | 
**_namespace** | **char \*** | object name and auth scope, such as for teams and projects | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 

### Return type

[apps_v1beta1_deployment_t](apps_v1beta1_deployment.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AppsV1beta1API_readNamespacedStatefulSet**
```c
// read the specified StatefulSet
//
v1beta1_stateful_set_t* AppsV1beta1API_readNamespacedStatefulSet(apiClient_t *apiClient, char * name, char * _namespace, char * pretty, int exact, int _export);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**name** | **char \*** | name of the StatefulSet | 
**_namespace** | **char \*** | object name and auth scope, such as for teams and projects | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 
**exact** | **int** | Should the export be exact.  Exact export maintains cluster-specific fields like &#39;Namespace&#39;. Deprecated. Planned for removal in 1.18. | [optional] 
**_export** | **int** | Should this value be exported.  Export strips fields that a user can not specify. Deprecated. Planned for removal in 1.18. | [optional] 

### Return type

[v1beta1_stateful_set_t](v1beta1_stateful_set.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AppsV1beta1API_readNamespacedStatefulSetScale**
```c
// read scale of the specified StatefulSet
//
apps_v1beta1_scale_t* AppsV1beta1API_readNamespacedStatefulSetScale(apiClient_t *apiClient, char * name, char * _namespace, char * pretty);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**name** | **char \*** | name of the Scale | 
**_namespace** | **char \*** | object name and auth scope, such as for teams and projects | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 

### Return type

[apps_v1beta1_scale_t](apps_v1beta1_scale.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AppsV1beta1API_readNamespacedStatefulSetStatus**
```c
// read status of the specified StatefulSet
//
v1beta1_stateful_set_t* AppsV1beta1API_readNamespacedStatefulSetStatus(apiClient_t *apiClient, char * name, char * _namespace, char * pretty);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**name** | **char \*** | name of the StatefulSet | 
**_namespace** | **char \*** | object name and auth scope, such as for teams and projects | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 

### Return type

[v1beta1_stateful_set_t](v1beta1_stateful_set.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AppsV1beta1API_replaceNamespacedControllerRevision**
```c
// replace the specified ControllerRevision
//
v1beta1_controller_revision_t* AppsV1beta1API_replaceNamespacedControllerRevision(apiClient_t *apiClient, char * name, char * _namespace, v1beta1_controller_revision_t * body, char * pretty, char * dryRun, char * fieldManager);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**name** | **char \*** | name of the ControllerRevision | 
**_namespace** | **char \*** | object name and auth scope, such as for teams and projects | 
**body** | **[v1beta1_controller_revision_t](v1beta1_controller_revision.md) \*** |  | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. | [optional] 

### Return type

[v1beta1_controller_revision_t](v1beta1_controller_revision.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AppsV1beta1API_replaceNamespacedDeployment**
```c
// replace the specified Deployment
//
apps_v1beta1_deployment_t* AppsV1beta1API_replaceNamespacedDeployment(apiClient_t *apiClient, char * name, char * _namespace, apps_v1beta1_deployment_t * body, char * pretty, char * dryRun, char * fieldManager);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**name** | **char \*** | name of the Deployment | 
**_namespace** | **char \*** | object name and auth scope, such as for teams and projects | 
**body** | **[apps_v1beta1_deployment_t](apps_v1beta1_deployment.md) \*** |  | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. | [optional] 

### Return type

[apps_v1beta1_deployment_t](apps_v1beta1_deployment.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AppsV1beta1API_replaceNamespacedDeploymentScale**
```c
// replace scale of the specified Deployment
//
apps_v1beta1_scale_t* AppsV1beta1API_replaceNamespacedDeploymentScale(apiClient_t *apiClient, char * name, char * _namespace, apps_v1beta1_scale_t * body, char * pretty, char * dryRun, char * fieldManager);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**name** | **char \*** | name of the Scale | 
**_namespace** | **char \*** | object name and auth scope, such as for teams and projects | 
**body** | **[apps_v1beta1_scale_t](apps_v1beta1_scale.md) \*** |  | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. | [optional] 

### Return type

[apps_v1beta1_scale_t](apps_v1beta1_scale.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AppsV1beta1API_replaceNamespacedDeploymentStatus**
```c
// replace status of the specified Deployment
//
apps_v1beta1_deployment_t* AppsV1beta1API_replaceNamespacedDeploymentStatus(apiClient_t *apiClient, char * name, char * _namespace, apps_v1beta1_deployment_t * body, char * pretty, char * dryRun, char * fieldManager);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**name** | **char \*** | name of the Deployment | 
**_namespace** | **char \*** | object name and auth scope, such as for teams and projects | 
**body** | **[apps_v1beta1_deployment_t](apps_v1beta1_deployment.md) \*** |  | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. | [optional] 

### Return type

[apps_v1beta1_deployment_t](apps_v1beta1_deployment.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AppsV1beta1API_replaceNamespacedStatefulSet**
```c
// replace the specified StatefulSet
//
v1beta1_stateful_set_t* AppsV1beta1API_replaceNamespacedStatefulSet(apiClient_t *apiClient, char * name, char * _namespace, v1beta1_stateful_set_t * body, char * pretty, char * dryRun, char * fieldManager);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**name** | **char \*** | name of the StatefulSet | 
**_namespace** | **char \*** | object name and auth scope, such as for teams and projects | 
**body** | **[v1beta1_stateful_set_t](v1beta1_stateful_set.md) \*** |  | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. | [optional] 

### Return type

[v1beta1_stateful_set_t](v1beta1_stateful_set.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AppsV1beta1API_replaceNamespacedStatefulSetScale**
```c
// replace scale of the specified StatefulSet
//
apps_v1beta1_scale_t* AppsV1beta1API_replaceNamespacedStatefulSetScale(apiClient_t *apiClient, char * name, char * _namespace, apps_v1beta1_scale_t * body, char * pretty, char * dryRun, char * fieldManager);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**name** | **char \*** | name of the Scale | 
**_namespace** | **char \*** | object name and auth scope, such as for teams and projects | 
**body** | **[apps_v1beta1_scale_t](apps_v1beta1_scale.md) \*** |  | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. | [optional] 

### Return type

[apps_v1beta1_scale_t](apps_v1beta1_scale.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

# **AppsV1beta1API_replaceNamespacedStatefulSetStatus**
```c
// replace status of the specified StatefulSet
//
v1beta1_stateful_set_t* AppsV1beta1API_replaceNamespacedStatefulSetStatus(apiClient_t *apiClient, char * name, char * _namespace, v1beta1_stateful_set_t * body, char * pretty, char * dryRun, char * fieldManager);
```

### Parameters
Name | Type | Description  | Notes
------------- | ------------- | ------------- | -------------
**apiClient** | **apiClient_t \*** | context containing the client configuration |
**name** | **char \*** | name of the StatefulSet | 
**_namespace** | **char \*** | object name and auth scope, such as for teams and projects | 
**body** | **[v1beta1_stateful_set_t](v1beta1_stateful_set.md) \*** |  | 
**pretty** | **char \*** | If &#39;true&#39;, then the output is pretty printed. | [optional] 
**dryRun** | **char \*** | When present, indicates that modifications should not be persisted. An invalid or unrecognized dryRun directive will result in an error response and no further processing of the request. Valid values are: - All: all dry run stages will be processed | [optional] 
**fieldManager** | **char \*** | fieldManager is a name associated with the actor or entity that is making these changes. The value must be less than or 128 characters long, and only contain printable characters, as defined by https://golang.org/pkg/unicode/#IsPrint. | [optional] 

### Return type

[v1beta1_stateful_set_t](v1beta1_stateful_set.md) *


### Authorization

[BearerToken](../README.md#BearerToken)

### HTTP request headers

 - **Content-Type**: Not defined
 - **Accept**: application/json, application/yaml, application/vnd.kubernetes.protobuf

[[Back to top]](#) [[Back to API list]](../README.md#documentation-for-api-endpoints) [[Back to Model list]](../README.md#documentation-for-models) [[Back to README]](../README.md)

