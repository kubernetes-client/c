#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_binding.h"
#include "../model/v1_component_status.h"
#include "../model/v1_component_status_list.h"
#include "../model/v1_config_map.h"
#include "../model/v1_config_map_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_endpoints.h"
#include "../model/v1_endpoints_list.h"
#include "../model/v1_event.h"
#include "../model/v1_event_list.h"
#include "../model/v1_limit_range.h"
#include "../model/v1_limit_range_list.h"
#include "../model/v1_namespace.h"
#include "../model/v1_namespace_list.h"
#include "../model/v1_node.h"
#include "../model/v1_node_list.h"
#include "../model/v1_persistent_volume.h"
#include "../model/v1_persistent_volume_claim.h"
#include "../model/v1_persistent_volume_claim_list.h"
#include "../model/v1_persistent_volume_list.h"
#include "../model/v1_pod.h"
#include "../model/v1_pod_list.h"
#include "../model/v1_pod_template.h"
#include "../model/v1_pod_template_list.h"
#include "../model/v1_replication_controller.h"
#include "../model/v1_replication_controller_list.h"
#include "../model/v1_resource_quota.h"
#include "../model/v1_resource_quota_list.h"
#include "../model/v1_scale.h"
#include "../model/v1_secret.h"
#include "../model/v1_secret_list.h"
#include "../model/v1_service.h"
#include "../model/v1_service_account.h"
#include "../model/v1_service_account_list.h"
#include "../model/v1_service_list.h"
#include "../model/v1_status.h"
#include "../model/v1_token_request.h"
#include "../model/v1beta1_eviction.h"


// connect DELETE requests to proxy of Pod
//
char*
CoreV1API_connectDeleteNamespacedPodProxy(apiClient_t *apiClient, char * name , char * _namespace , char * path );


// connect DELETE requests to proxy of Pod
//
char*
CoreV1API_connectDeleteNamespacedPodProxyWithPath(apiClient_t *apiClient, char * name , char * _namespace , char * path , char * path2 );


// connect DELETE requests to proxy of Service
//
char*
CoreV1API_connectDeleteNamespacedServiceProxy(apiClient_t *apiClient, char * name , char * _namespace , char * path );


// connect DELETE requests to proxy of Service
//
char*
CoreV1API_connectDeleteNamespacedServiceProxyWithPath(apiClient_t *apiClient, char * name , char * _namespace , char * path , char * path2 );


// connect DELETE requests to proxy of Node
//
char*
CoreV1API_connectDeleteNodeProxy(apiClient_t *apiClient, char * name , char * path );


// connect DELETE requests to proxy of Node
//
char*
CoreV1API_connectDeleteNodeProxyWithPath(apiClient_t *apiClient, char * name , char * path , char * path2 );


// connect GET requests to attach of Pod
//
char*
CoreV1API_connectGetNamespacedPodAttach(apiClient_t *apiClient, char * name , char * _namespace , char * container , int _stderr , int _stdin , int _stdout , int tty );


// connect GET requests to exec of Pod
//
char*
CoreV1API_connectGetNamespacedPodExec(apiClient_t *apiClient, char * name , char * _namespace , char * command , char * container , int _stderr , int _stdin , int _stdout , int tty );


// connect GET requests to portforward of Pod
//
char*
CoreV1API_connectGetNamespacedPodPortforward(apiClient_t *apiClient, char * name , char * _namespace , int ports );


// connect GET requests to proxy of Pod
//
char*
CoreV1API_connectGetNamespacedPodProxy(apiClient_t *apiClient, char * name , char * _namespace , char * path );


// connect GET requests to proxy of Pod
//
char*
CoreV1API_connectGetNamespacedPodProxyWithPath(apiClient_t *apiClient, char * name , char * _namespace , char * path , char * path2 );


// connect GET requests to proxy of Service
//
char*
CoreV1API_connectGetNamespacedServiceProxy(apiClient_t *apiClient, char * name , char * _namespace , char * path );


// connect GET requests to proxy of Service
//
char*
CoreV1API_connectGetNamespacedServiceProxyWithPath(apiClient_t *apiClient, char * name , char * _namespace , char * path , char * path2 );


// connect GET requests to proxy of Node
//
char*
CoreV1API_connectGetNodeProxy(apiClient_t *apiClient, char * name , char * path );


// connect GET requests to proxy of Node
//
char*
CoreV1API_connectGetNodeProxyWithPath(apiClient_t *apiClient, char * name , char * path , char * path2 );


// connect HEAD requests to proxy of Pod
//
char*
CoreV1API_connectHeadNamespacedPodProxy(apiClient_t *apiClient, char * name , char * _namespace , char * path );


// connect HEAD requests to proxy of Pod
//
char*
CoreV1API_connectHeadNamespacedPodProxyWithPath(apiClient_t *apiClient, char * name , char * _namespace , char * path , char * path2 );


// connect HEAD requests to proxy of Service
//
char*
CoreV1API_connectHeadNamespacedServiceProxy(apiClient_t *apiClient, char * name , char * _namespace , char * path );


// connect HEAD requests to proxy of Service
//
char*
CoreV1API_connectHeadNamespacedServiceProxyWithPath(apiClient_t *apiClient, char * name , char * _namespace , char * path , char * path2 );


// connect HEAD requests to proxy of Node
//
char*
CoreV1API_connectHeadNodeProxy(apiClient_t *apiClient, char * name , char * path );


// connect HEAD requests to proxy of Node
//
char*
CoreV1API_connectHeadNodeProxyWithPath(apiClient_t *apiClient, char * name , char * path , char * path2 );


// connect OPTIONS requests to proxy of Pod
//
char*
CoreV1API_connectOptionsNamespacedPodProxy(apiClient_t *apiClient, char * name , char * _namespace , char * path );


// connect OPTIONS requests to proxy of Pod
//
char*
CoreV1API_connectOptionsNamespacedPodProxyWithPath(apiClient_t *apiClient, char * name , char * _namespace , char * path , char * path2 );


// connect OPTIONS requests to proxy of Service
//
char*
CoreV1API_connectOptionsNamespacedServiceProxy(apiClient_t *apiClient, char * name , char * _namespace , char * path );


// connect OPTIONS requests to proxy of Service
//
char*
CoreV1API_connectOptionsNamespacedServiceProxyWithPath(apiClient_t *apiClient, char * name , char * _namespace , char * path , char * path2 );


// connect OPTIONS requests to proxy of Node
//
char*
CoreV1API_connectOptionsNodeProxy(apiClient_t *apiClient, char * name , char * path );


// connect OPTIONS requests to proxy of Node
//
char*
CoreV1API_connectOptionsNodeProxyWithPath(apiClient_t *apiClient, char * name , char * path , char * path2 );


// connect PATCH requests to proxy of Pod
//
char*
CoreV1API_connectPatchNamespacedPodProxy(apiClient_t *apiClient, char * name , char * _namespace , char * path );


// connect PATCH requests to proxy of Pod
//
char*
CoreV1API_connectPatchNamespacedPodProxyWithPath(apiClient_t *apiClient, char * name , char * _namespace , char * path , char * path2 );


// connect PATCH requests to proxy of Service
//
char*
CoreV1API_connectPatchNamespacedServiceProxy(apiClient_t *apiClient, char * name , char * _namespace , char * path );


// connect PATCH requests to proxy of Service
//
char*
CoreV1API_connectPatchNamespacedServiceProxyWithPath(apiClient_t *apiClient, char * name , char * _namespace , char * path , char * path2 );


// connect PATCH requests to proxy of Node
//
char*
CoreV1API_connectPatchNodeProxy(apiClient_t *apiClient, char * name , char * path );


// connect PATCH requests to proxy of Node
//
char*
CoreV1API_connectPatchNodeProxyWithPath(apiClient_t *apiClient, char * name , char * path , char * path2 );


// connect POST requests to attach of Pod
//
char*
CoreV1API_connectPostNamespacedPodAttach(apiClient_t *apiClient, char * name , char * _namespace , char * container , int _stderr , int _stdin , int _stdout , int tty );


// connect POST requests to exec of Pod
//
char*
CoreV1API_connectPostNamespacedPodExec(apiClient_t *apiClient, char * name , char * _namespace , char * command , char * container , int _stderr , int _stdin , int _stdout , int tty );


// connect POST requests to portforward of Pod
//
char*
CoreV1API_connectPostNamespacedPodPortforward(apiClient_t *apiClient, char * name , char * _namespace , int ports );


// connect POST requests to proxy of Pod
//
char*
CoreV1API_connectPostNamespacedPodProxy(apiClient_t *apiClient, char * name , char * _namespace , char * path );


// connect POST requests to proxy of Pod
//
char*
CoreV1API_connectPostNamespacedPodProxyWithPath(apiClient_t *apiClient, char * name , char * _namespace , char * path , char * path2 );


// connect POST requests to proxy of Service
//
char*
CoreV1API_connectPostNamespacedServiceProxy(apiClient_t *apiClient, char * name , char * _namespace , char * path );


// connect POST requests to proxy of Service
//
char*
CoreV1API_connectPostNamespacedServiceProxyWithPath(apiClient_t *apiClient, char * name , char * _namespace , char * path , char * path2 );


// connect POST requests to proxy of Node
//
char*
CoreV1API_connectPostNodeProxy(apiClient_t *apiClient, char * name , char * path );


// connect POST requests to proxy of Node
//
char*
CoreV1API_connectPostNodeProxyWithPath(apiClient_t *apiClient, char * name , char * path , char * path2 );


// connect PUT requests to proxy of Pod
//
char*
CoreV1API_connectPutNamespacedPodProxy(apiClient_t *apiClient, char * name , char * _namespace , char * path );


// connect PUT requests to proxy of Pod
//
char*
CoreV1API_connectPutNamespacedPodProxyWithPath(apiClient_t *apiClient, char * name , char * _namespace , char * path , char * path2 );


// connect PUT requests to proxy of Service
//
char*
CoreV1API_connectPutNamespacedServiceProxy(apiClient_t *apiClient, char * name , char * _namespace , char * path );


// connect PUT requests to proxy of Service
//
char*
CoreV1API_connectPutNamespacedServiceProxyWithPath(apiClient_t *apiClient, char * name , char * _namespace , char * path , char * path2 );


// connect PUT requests to proxy of Node
//
char*
CoreV1API_connectPutNodeProxy(apiClient_t *apiClient, char * name , char * path );


// connect PUT requests to proxy of Node
//
char*
CoreV1API_connectPutNodeProxyWithPath(apiClient_t *apiClient, char * name , char * path , char * path2 );


// create a Namespace
//
v1_namespace_t*
CoreV1API_createNamespace(apiClient_t *apiClient, v1_namespace_t * body , char * pretty , char * dryRun , char * fieldManager );


// create a Binding
//
v1_binding_t*
CoreV1API_createNamespacedBinding(apiClient_t *apiClient, char * _namespace , v1_binding_t * body , char * dryRun , char * fieldManager , char * pretty );


// create a ConfigMap
//
v1_config_map_t*
CoreV1API_createNamespacedConfigMap(apiClient_t *apiClient, char * _namespace , v1_config_map_t * body , char * pretty , char * dryRun , char * fieldManager );


// create Endpoints
//
v1_endpoints_t*
CoreV1API_createNamespacedEndpoints(apiClient_t *apiClient, char * _namespace , v1_endpoints_t * body , char * pretty , char * dryRun , char * fieldManager );


// create an Event
//
v1_event_t*
CoreV1API_createNamespacedEvent(apiClient_t *apiClient, char * _namespace , v1_event_t * body , char * pretty , char * dryRun , char * fieldManager );


// create a LimitRange
//
v1_limit_range_t*
CoreV1API_createNamespacedLimitRange(apiClient_t *apiClient, char * _namespace , v1_limit_range_t * body , char * pretty , char * dryRun , char * fieldManager );


// create a PersistentVolumeClaim
//
v1_persistent_volume_claim_t*
CoreV1API_createNamespacedPersistentVolumeClaim(apiClient_t *apiClient, char * _namespace , v1_persistent_volume_claim_t * body , char * pretty , char * dryRun , char * fieldManager );


// create a Pod
//
v1_pod_t*
CoreV1API_createNamespacedPod(apiClient_t *apiClient, char * _namespace , v1_pod_t * body , char * pretty , char * dryRun , char * fieldManager );


// create binding of a Pod
//
v1_binding_t*
CoreV1API_createNamespacedPodBinding(apiClient_t *apiClient, char * name , char * _namespace , v1_binding_t * body , char * dryRun , char * fieldManager , char * pretty );


// create eviction of a Pod
//
v1beta1_eviction_t*
CoreV1API_createNamespacedPodEviction(apiClient_t *apiClient, char * name , char * _namespace , v1beta1_eviction_t * body , char * dryRun , char * fieldManager , char * pretty );


// create a PodTemplate
//
v1_pod_template_t*
CoreV1API_createNamespacedPodTemplate(apiClient_t *apiClient, char * _namespace , v1_pod_template_t * body , char * pretty , char * dryRun , char * fieldManager );


// create a ReplicationController
//
v1_replication_controller_t*
CoreV1API_createNamespacedReplicationController(apiClient_t *apiClient, char * _namespace , v1_replication_controller_t * body , char * pretty , char * dryRun , char * fieldManager );


// create a ResourceQuota
//
v1_resource_quota_t*
CoreV1API_createNamespacedResourceQuota(apiClient_t *apiClient, char * _namespace , v1_resource_quota_t * body , char * pretty , char * dryRun , char * fieldManager );


// create a Secret
//
v1_secret_t*
CoreV1API_createNamespacedSecret(apiClient_t *apiClient, char * _namespace , v1_secret_t * body , char * pretty , char * dryRun , char * fieldManager );


// create a Service
//
v1_service_t*
CoreV1API_createNamespacedService(apiClient_t *apiClient, char * _namespace , v1_service_t * body , char * pretty , char * dryRun , char * fieldManager );


// create a ServiceAccount
//
v1_service_account_t*
CoreV1API_createNamespacedServiceAccount(apiClient_t *apiClient, char * _namespace , v1_service_account_t * body , char * pretty , char * dryRun , char * fieldManager );


// create token of a ServiceAccount
//
v1_token_request_t*
CoreV1API_createNamespacedServiceAccountToken(apiClient_t *apiClient, char * name , char * _namespace , v1_token_request_t * body , char * dryRun , char * fieldManager , char * pretty );


// create a Node
//
v1_node_t*
CoreV1API_createNode(apiClient_t *apiClient, v1_node_t * body , char * pretty , char * dryRun , char * fieldManager );


// create a PersistentVolume
//
v1_persistent_volume_t*
CoreV1API_createPersistentVolume(apiClient_t *apiClient, v1_persistent_volume_t * body , char * pretty , char * dryRun , char * fieldManager );


// delete collection of ConfigMap
//
v1_status_t*
CoreV1API_deleteCollectionNamespacedConfigMap(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of Endpoints
//
v1_status_t*
CoreV1API_deleteCollectionNamespacedEndpoints(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of Event
//
v1_status_t*
CoreV1API_deleteCollectionNamespacedEvent(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of LimitRange
//
v1_status_t*
CoreV1API_deleteCollectionNamespacedLimitRange(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of PersistentVolumeClaim
//
v1_status_t*
CoreV1API_deleteCollectionNamespacedPersistentVolumeClaim(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of Pod
//
v1_status_t*
CoreV1API_deleteCollectionNamespacedPod(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of PodTemplate
//
v1_status_t*
CoreV1API_deleteCollectionNamespacedPodTemplate(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of ReplicationController
//
v1_status_t*
CoreV1API_deleteCollectionNamespacedReplicationController(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of ResourceQuota
//
v1_status_t*
CoreV1API_deleteCollectionNamespacedResourceQuota(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of Secret
//
v1_status_t*
CoreV1API_deleteCollectionNamespacedSecret(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of ServiceAccount
//
v1_status_t*
CoreV1API_deleteCollectionNamespacedServiceAccount(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of Node
//
v1_status_t*
CoreV1API_deleteCollectionNode(apiClient_t *apiClient, char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of PersistentVolume
//
v1_status_t*
CoreV1API_deleteCollectionPersistentVolume(apiClient_t *apiClient, char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete a Namespace
//
v1_status_t*
CoreV1API_deleteNamespace(apiClient_t *apiClient, char * name , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete a ConfigMap
//
v1_status_t*
CoreV1API_deleteNamespacedConfigMap(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete Endpoints
//
v1_status_t*
CoreV1API_deleteNamespacedEndpoints(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete an Event
//
v1_status_t*
CoreV1API_deleteNamespacedEvent(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete a LimitRange
//
v1_status_t*
CoreV1API_deleteNamespacedLimitRange(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete a PersistentVolumeClaim
//
v1_status_t*
CoreV1API_deleteNamespacedPersistentVolumeClaim(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete a Pod
//
v1_status_t*
CoreV1API_deleteNamespacedPod(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete a PodTemplate
//
v1_status_t*
CoreV1API_deleteNamespacedPodTemplate(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete a ReplicationController
//
v1_status_t*
CoreV1API_deleteNamespacedReplicationController(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete a ResourceQuota
//
v1_status_t*
CoreV1API_deleteNamespacedResourceQuota(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete a Secret
//
v1_status_t*
CoreV1API_deleteNamespacedSecret(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete a Service
//
v1_status_t*
CoreV1API_deleteNamespacedService(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete a ServiceAccount
//
v1_status_t*
CoreV1API_deleteNamespacedServiceAccount(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete a Node
//
v1_status_t*
CoreV1API_deleteNode(apiClient_t *apiClient, char * name , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete a PersistentVolume
//
v1_status_t*
CoreV1API_deletePersistentVolume(apiClient_t *apiClient, char * name , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// get available resources
//
v1_api_resource_list_t*
CoreV1API_getAPIResources(apiClient_t *apiClient);


// list objects of kind ComponentStatus
//
v1_component_status_list_t*
CoreV1API_listComponentStatus(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind ConfigMap
//
v1_config_map_list_t*
CoreV1API_listConfigMapForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind Endpoints
//
v1_endpoints_list_t*
CoreV1API_listEndpointsForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind Event
//
v1_event_list_t*
CoreV1API_listEventForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind LimitRange
//
v1_limit_range_list_t*
CoreV1API_listLimitRangeForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind Namespace
//
v1_namespace_list_t*
CoreV1API_listNamespace(apiClient_t *apiClient, char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind ConfigMap
//
v1_config_map_list_t*
CoreV1API_listNamespacedConfigMap(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind Endpoints
//
v1_endpoints_list_t*
CoreV1API_listNamespacedEndpoints(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind Event
//
v1_event_list_t*
CoreV1API_listNamespacedEvent(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind LimitRange
//
v1_limit_range_list_t*
CoreV1API_listNamespacedLimitRange(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind PersistentVolumeClaim
//
v1_persistent_volume_claim_list_t*
CoreV1API_listNamespacedPersistentVolumeClaim(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind Pod
//
v1_pod_list_t*
CoreV1API_listNamespacedPod(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind PodTemplate
//
v1_pod_template_list_t*
CoreV1API_listNamespacedPodTemplate(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind ReplicationController
//
v1_replication_controller_list_t*
CoreV1API_listNamespacedReplicationController(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind ResourceQuota
//
v1_resource_quota_list_t*
CoreV1API_listNamespacedResourceQuota(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind Secret
//
v1_secret_list_t*
CoreV1API_listNamespacedSecret(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind Service
//
v1_service_list_t*
CoreV1API_listNamespacedService(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind ServiceAccount
//
v1_service_account_list_t*
CoreV1API_listNamespacedServiceAccount(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind Node
//
v1_node_list_t*
CoreV1API_listNode(apiClient_t *apiClient, char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind PersistentVolume
//
v1_persistent_volume_list_t*
CoreV1API_listPersistentVolume(apiClient_t *apiClient, char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind PersistentVolumeClaim
//
v1_persistent_volume_claim_list_t*
CoreV1API_listPersistentVolumeClaimForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind Pod
//
v1_pod_list_t*
CoreV1API_listPodForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind PodTemplate
//
v1_pod_template_list_t*
CoreV1API_listPodTemplateForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind ReplicationController
//
v1_replication_controller_list_t*
CoreV1API_listReplicationControllerForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind ResourceQuota
//
v1_resource_quota_list_t*
CoreV1API_listResourceQuotaForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind Secret
//
v1_secret_list_t*
CoreV1API_listSecretForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind ServiceAccount
//
v1_service_account_list_t*
CoreV1API_listServiceAccountForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind Service
//
v1_service_list_t*
CoreV1API_listServiceForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch );


// partially update the specified Namespace
//
v1_namespace_t*
CoreV1API_patchNamespace(apiClient_t *apiClient, char * name , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update status of the specified Namespace
//
v1_namespace_t*
CoreV1API_patchNamespaceStatus(apiClient_t *apiClient, char * name , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update the specified ConfigMap
//
v1_config_map_t*
CoreV1API_patchNamespacedConfigMap(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update the specified Endpoints
//
v1_endpoints_t*
CoreV1API_patchNamespacedEndpoints(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update the specified Event
//
v1_event_t*
CoreV1API_patchNamespacedEvent(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update the specified LimitRange
//
v1_limit_range_t*
CoreV1API_patchNamespacedLimitRange(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update the specified PersistentVolumeClaim
//
v1_persistent_volume_claim_t*
CoreV1API_patchNamespacedPersistentVolumeClaim(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update status of the specified PersistentVolumeClaim
//
v1_persistent_volume_claim_t*
CoreV1API_patchNamespacedPersistentVolumeClaimStatus(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update the specified Pod
//
v1_pod_t*
CoreV1API_patchNamespacedPod(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update status of the specified Pod
//
v1_pod_t*
CoreV1API_patchNamespacedPodStatus(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update the specified PodTemplate
//
v1_pod_template_t*
CoreV1API_patchNamespacedPodTemplate(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update the specified ReplicationController
//
v1_replication_controller_t*
CoreV1API_patchNamespacedReplicationController(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update scale of the specified ReplicationController
//
v1_scale_t*
CoreV1API_patchNamespacedReplicationControllerScale(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update status of the specified ReplicationController
//
v1_replication_controller_t*
CoreV1API_patchNamespacedReplicationControllerStatus(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update the specified ResourceQuota
//
v1_resource_quota_t*
CoreV1API_patchNamespacedResourceQuota(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update status of the specified ResourceQuota
//
v1_resource_quota_t*
CoreV1API_patchNamespacedResourceQuotaStatus(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update the specified Secret
//
v1_secret_t*
CoreV1API_patchNamespacedSecret(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update the specified Service
//
v1_service_t*
CoreV1API_patchNamespacedService(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update the specified ServiceAccount
//
v1_service_account_t*
CoreV1API_patchNamespacedServiceAccount(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update status of the specified Service
//
v1_service_t*
CoreV1API_patchNamespacedServiceStatus(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update the specified Node
//
v1_node_t*
CoreV1API_patchNode(apiClient_t *apiClient, char * name , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update status of the specified Node
//
v1_node_t*
CoreV1API_patchNodeStatus(apiClient_t *apiClient, char * name , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update the specified PersistentVolume
//
v1_persistent_volume_t*
CoreV1API_patchPersistentVolume(apiClient_t *apiClient, char * name , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update status of the specified PersistentVolume
//
v1_persistent_volume_t*
CoreV1API_patchPersistentVolumeStatus(apiClient_t *apiClient, char * name , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// read the specified ComponentStatus
//
v1_component_status_t*
CoreV1API_readComponentStatus(apiClient_t *apiClient, char * name , char * pretty );


// read the specified Namespace
//
v1_namespace_t*
CoreV1API_readNamespace(apiClient_t *apiClient, char * name , char * pretty , int exact , int _export );


// read status of the specified Namespace
//
v1_namespace_t*
CoreV1API_readNamespaceStatus(apiClient_t *apiClient, char * name , char * pretty );


// read the specified ConfigMap
//
v1_config_map_t*
CoreV1API_readNamespacedConfigMap(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , int exact , int _export );


// read the specified Endpoints
//
v1_endpoints_t*
CoreV1API_readNamespacedEndpoints(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , int exact , int _export );


// read the specified Event
//
v1_event_t*
CoreV1API_readNamespacedEvent(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , int exact , int _export );


// read the specified LimitRange
//
v1_limit_range_t*
CoreV1API_readNamespacedLimitRange(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , int exact , int _export );


// read the specified PersistentVolumeClaim
//
v1_persistent_volume_claim_t*
CoreV1API_readNamespacedPersistentVolumeClaim(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , int exact , int _export );


// read status of the specified PersistentVolumeClaim
//
v1_persistent_volume_claim_t*
CoreV1API_readNamespacedPersistentVolumeClaimStatus(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// read the specified Pod
//
v1_pod_t*
CoreV1API_readNamespacedPod(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , int exact , int _export );


// read log of the specified Pod
//
char*
CoreV1API_readNamespacedPodLog(apiClient_t *apiClient, char * name , char * _namespace , char * container , int follow , int insecureSkipTLSVerifyBackend , int limitBytes , char * pretty , int previous , int sinceSeconds , int tailLines , int timestamps );


// read status of the specified Pod
//
v1_pod_t*
CoreV1API_readNamespacedPodStatus(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// read the specified PodTemplate
//
v1_pod_template_t*
CoreV1API_readNamespacedPodTemplate(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , int exact , int _export );


// read the specified ReplicationController
//
v1_replication_controller_t*
CoreV1API_readNamespacedReplicationController(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , int exact , int _export );


// read scale of the specified ReplicationController
//
v1_scale_t*
CoreV1API_readNamespacedReplicationControllerScale(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// read status of the specified ReplicationController
//
v1_replication_controller_t*
CoreV1API_readNamespacedReplicationControllerStatus(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// read the specified ResourceQuota
//
v1_resource_quota_t*
CoreV1API_readNamespacedResourceQuota(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , int exact , int _export );


// read status of the specified ResourceQuota
//
v1_resource_quota_t*
CoreV1API_readNamespacedResourceQuotaStatus(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// read the specified Secret
//
v1_secret_t*
CoreV1API_readNamespacedSecret(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , int exact , int _export );


// read the specified Service
//
v1_service_t*
CoreV1API_readNamespacedService(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , int exact , int _export );


// read the specified ServiceAccount
//
v1_service_account_t*
CoreV1API_readNamespacedServiceAccount(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , int exact , int _export );


// read status of the specified Service
//
v1_service_t*
CoreV1API_readNamespacedServiceStatus(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// read the specified Node
//
v1_node_t*
CoreV1API_readNode(apiClient_t *apiClient, char * name , char * pretty , int exact , int _export );


// read status of the specified Node
//
v1_node_t*
CoreV1API_readNodeStatus(apiClient_t *apiClient, char * name , char * pretty );


// read the specified PersistentVolume
//
v1_persistent_volume_t*
CoreV1API_readPersistentVolume(apiClient_t *apiClient, char * name , char * pretty , int exact , int _export );


// read status of the specified PersistentVolume
//
v1_persistent_volume_t*
CoreV1API_readPersistentVolumeStatus(apiClient_t *apiClient, char * name , char * pretty );


// replace the specified Namespace
//
v1_namespace_t*
CoreV1API_replaceNamespace(apiClient_t *apiClient, char * name , v1_namespace_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace finalize of the specified Namespace
//
v1_namespace_t*
CoreV1API_replaceNamespaceFinalize(apiClient_t *apiClient, char * name , v1_namespace_t * body , char * dryRun , char * fieldManager , char * pretty );


// replace status of the specified Namespace
//
v1_namespace_t*
CoreV1API_replaceNamespaceStatus(apiClient_t *apiClient, char * name , v1_namespace_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace the specified ConfigMap
//
v1_config_map_t*
CoreV1API_replaceNamespacedConfigMap(apiClient_t *apiClient, char * name , char * _namespace , v1_config_map_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace the specified Endpoints
//
v1_endpoints_t*
CoreV1API_replaceNamespacedEndpoints(apiClient_t *apiClient, char * name , char * _namespace , v1_endpoints_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace the specified Event
//
v1_event_t*
CoreV1API_replaceNamespacedEvent(apiClient_t *apiClient, char * name , char * _namespace , v1_event_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace the specified LimitRange
//
v1_limit_range_t*
CoreV1API_replaceNamespacedLimitRange(apiClient_t *apiClient, char * name , char * _namespace , v1_limit_range_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace the specified PersistentVolumeClaim
//
v1_persistent_volume_claim_t*
CoreV1API_replaceNamespacedPersistentVolumeClaim(apiClient_t *apiClient, char * name , char * _namespace , v1_persistent_volume_claim_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace status of the specified PersistentVolumeClaim
//
v1_persistent_volume_claim_t*
CoreV1API_replaceNamespacedPersistentVolumeClaimStatus(apiClient_t *apiClient, char * name , char * _namespace , v1_persistent_volume_claim_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace the specified Pod
//
v1_pod_t*
CoreV1API_replaceNamespacedPod(apiClient_t *apiClient, char * name , char * _namespace , v1_pod_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace status of the specified Pod
//
v1_pod_t*
CoreV1API_replaceNamespacedPodStatus(apiClient_t *apiClient, char * name , char * _namespace , v1_pod_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace the specified PodTemplate
//
v1_pod_template_t*
CoreV1API_replaceNamespacedPodTemplate(apiClient_t *apiClient, char * name , char * _namespace , v1_pod_template_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace the specified ReplicationController
//
v1_replication_controller_t*
CoreV1API_replaceNamespacedReplicationController(apiClient_t *apiClient, char * name , char * _namespace , v1_replication_controller_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace scale of the specified ReplicationController
//
v1_scale_t*
CoreV1API_replaceNamespacedReplicationControllerScale(apiClient_t *apiClient, char * name , char * _namespace , v1_scale_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace status of the specified ReplicationController
//
v1_replication_controller_t*
CoreV1API_replaceNamespacedReplicationControllerStatus(apiClient_t *apiClient, char * name , char * _namespace , v1_replication_controller_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace the specified ResourceQuota
//
v1_resource_quota_t*
CoreV1API_replaceNamespacedResourceQuota(apiClient_t *apiClient, char * name , char * _namespace , v1_resource_quota_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace status of the specified ResourceQuota
//
v1_resource_quota_t*
CoreV1API_replaceNamespacedResourceQuotaStatus(apiClient_t *apiClient, char * name , char * _namespace , v1_resource_quota_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace the specified Secret
//
v1_secret_t*
CoreV1API_replaceNamespacedSecret(apiClient_t *apiClient, char * name , char * _namespace , v1_secret_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace the specified Service
//
v1_service_t*
CoreV1API_replaceNamespacedService(apiClient_t *apiClient, char * name , char * _namespace , v1_service_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace the specified ServiceAccount
//
v1_service_account_t*
CoreV1API_replaceNamespacedServiceAccount(apiClient_t *apiClient, char * name , char * _namespace , v1_service_account_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace status of the specified Service
//
v1_service_t*
CoreV1API_replaceNamespacedServiceStatus(apiClient_t *apiClient, char * name , char * _namespace , v1_service_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace the specified Node
//
v1_node_t*
CoreV1API_replaceNode(apiClient_t *apiClient, char * name , v1_node_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace status of the specified Node
//
v1_node_t*
CoreV1API_replaceNodeStatus(apiClient_t *apiClient, char * name , v1_node_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace the specified PersistentVolume
//
v1_persistent_volume_t*
CoreV1API_replacePersistentVolume(apiClient_t *apiClient, char * name , v1_persistent_volume_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace status of the specified PersistentVolume
//
v1_persistent_volume_t*
CoreV1API_replacePersistentVolumeStatus(apiClient_t *apiClient, char * name , v1_persistent_volume_t * body , char * pretty , char * dryRun , char * fieldManager );


