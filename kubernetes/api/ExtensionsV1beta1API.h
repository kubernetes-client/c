#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/extensions_v1beta1_deployment.h"
#include "../model/extensions_v1beta1_deployment_list.h"
#include "../model/extensions_v1beta1_deployment_rollback.h"
#include "../model/extensions_v1beta1_ingress.h"
#include "../model/extensions_v1beta1_ingress_list.h"
#include "../model/extensions_v1beta1_pod_security_policy.h"
#include "../model/extensions_v1beta1_pod_security_policy_list.h"
#include "../model/extensions_v1beta1_scale.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_status.h"
#include "../model/v1beta1_daemon_set.h"
#include "../model/v1beta1_daemon_set_list.h"
#include "../model/v1beta1_network_policy.h"
#include "../model/v1beta1_network_policy_list.h"
#include "../model/v1beta1_replica_set.h"
#include "../model/v1beta1_replica_set_list.h"


// create a DaemonSet
//
v1beta1_daemon_set_t*
ExtensionsV1beta1API_createNamespacedDaemonSet(apiClient_t *apiClient, char * _namespace , v1beta1_daemon_set_t * body , char * pretty , char * dryRun , char * fieldManager );


// create a Deployment
//
extensions_v1beta1_deployment_t*
ExtensionsV1beta1API_createNamespacedDeployment(apiClient_t *apiClient, char * _namespace , extensions_v1beta1_deployment_t * body , char * pretty , char * dryRun , char * fieldManager );


// create rollback of a Deployment
//
v1_status_t*
ExtensionsV1beta1API_createNamespacedDeploymentRollback(apiClient_t *apiClient, char * name , char * _namespace , extensions_v1beta1_deployment_rollback_t * body , char * dryRun , char * fieldManager , char * pretty );


// create an Ingress
//
extensions_v1beta1_ingress_t*
ExtensionsV1beta1API_createNamespacedIngress(apiClient_t *apiClient, char * _namespace , extensions_v1beta1_ingress_t * body , char * pretty , char * dryRun , char * fieldManager );


// create a NetworkPolicy
//
v1beta1_network_policy_t*
ExtensionsV1beta1API_createNamespacedNetworkPolicy(apiClient_t *apiClient, char * _namespace , v1beta1_network_policy_t * body , char * pretty , char * dryRun , char * fieldManager );


// create a ReplicaSet
//
v1beta1_replica_set_t*
ExtensionsV1beta1API_createNamespacedReplicaSet(apiClient_t *apiClient, char * _namespace , v1beta1_replica_set_t * body , char * pretty , char * dryRun , char * fieldManager );


// create a PodSecurityPolicy
//
extensions_v1beta1_pod_security_policy_t*
ExtensionsV1beta1API_createPodSecurityPolicy(apiClient_t *apiClient, extensions_v1beta1_pod_security_policy_t * body , char * pretty , char * dryRun , char * fieldManager );


// delete collection of DaemonSet
//
v1_status_t*
ExtensionsV1beta1API_deleteCollectionNamespacedDaemonSet(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of Deployment
//
v1_status_t*
ExtensionsV1beta1API_deleteCollectionNamespacedDeployment(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of Ingress
//
v1_status_t*
ExtensionsV1beta1API_deleteCollectionNamespacedIngress(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of NetworkPolicy
//
v1_status_t*
ExtensionsV1beta1API_deleteCollectionNamespacedNetworkPolicy(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of ReplicaSet
//
v1_status_t*
ExtensionsV1beta1API_deleteCollectionNamespacedReplicaSet(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of PodSecurityPolicy
//
v1_status_t*
ExtensionsV1beta1API_deleteCollectionPodSecurityPolicy(apiClient_t *apiClient, char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete a DaemonSet
//
v1_status_t*
ExtensionsV1beta1API_deleteNamespacedDaemonSet(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete a Deployment
//
v1_status_t*
ExtensionsV1beta1API_deleteNamespacedDeployment(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete an Ingress
//
v1_status_t*
ExtensionsV1beta1API_deleteNamespacedIngress(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete a NetworkPolicy
//
v1_status_t*
ExtensionsV1beta1API_deleteNamespacedNetworkPolicy(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete a ReplicaSet
//
v1_status_t*
ExtensionsV1beta1API_deleteNamespacedReplicaSet(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete a PodSecurityPolicy
//
v1_status_t*
ExtensionsV1beta1API_deletePodSecurityPolicy(apiClient_t *apiClient, char * name , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// get available resources
//
v1_api_resource_list_t*
ExtensionsV1beta1API_getAPIResources(apiClient_t *apiClient);


// list or watch objects of kind DaemonSet
//
v1beta1_daemon_set_list_t*
ExtensionsV1beta1API_listDaemonSetForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind Deployment
//
extensions_v1beta1_deployment_list_t*
ExtensionsV1beta1API_listDeploymentForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind Ingress
//
extensions_v1beta1_ingress_list_t*
ExtensionsV1beta1API_listIngressForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind DaemonSet
//
v1beta1_daemon_set_list_t*
ExtensionsV1beta1API_listNamespacedDaemonSet(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind Deployment
//
extensions_v1beta1_deployment_list_t*
ExtensionsV1beta1API_listNamespacedDeployment(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind Ingress
//
extensions_v1beta1_ingress_list_t*
ExtensionsV1beta1API_listNamespacedIngress(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind NetworkPolicy
//
v1beta1_network_policy_list_t*
ExtensionsV1beta1API_listNamespacedNetworkPolicy(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind ReplicaSet
//
v1beta1_replica_set_list_t*
ExtensionsV1beta1API_listNamespacedReplicaSet(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind NetworkPolicy
//
v1beta1_network_policy_list_t*
ExtensionsV1beta1API_listNetworkPolicyForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind PodSecurityPolicy
//
extensions_v1beta1_pod_security_policy_list_t*
ExtensionsV1beta1API_listPodSecurityPolicy(apiClient_t *apiClient, char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind ReplicaSet
//
v1beta1_replica_set_list_t*
ExtensionsV1beta1API_listReplicaSetForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch );


// partially update the specified DaemonSet
//
v1beta1_daemon_set_t*
ExtensionsV1beta1API_patchNamespacedDaemonSet(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update status of the specified DaemonSet
//
v1beta1_daemon_set_t*
ExtensionsV1beta1API_patchNamespacedDaemonSetStatus(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update the specified Deployment
//
extensions_v1beta1_deployment_t*
ExtensionsV1beta1API_patchNamespacedDeployment(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update scale of the specified Deployment
//
extensions_v1beta1_scale_t*
ExtensionsV1beta1API_patchNamespacedDeploymentScale(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update status of the specified Deployment
//
extensions_v1beta1_deployment_t*
ExtensionsV1beta1API_patchNamespacedDeploymentStatus(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update the specified Ingress
//
extensions_v1beta1_ingress_t*
ExtensionsV1beta1API_patchNamespacedIngress(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update status of the specified Ingress
//
extensions_v1beta1_ingress_t*
ExtensionsV1beta1API_patchNamespacedIngressStatus(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update the specified NetworkPolicy
//
v1beta1_network_policy_t*
ExtensionsV1beta1API_patchNamespacedNetworkPolicy(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update the specified ReplicaSet
//
v1beta1_replica_set_t*
ExtensionsV1beta1API_patchNamespacedReplicaSet(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update scale of the specified ReplicaSet
//
extensions_v1beta1_scale_t*
ExtensionsV1beta1API_patchNamespacedReplicaSetScale(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update status of the specified ReplicaSet
//
v1beta1_replica_set_t*
ExtensionsV1beta1API_patchNamespacedReplicaSetStatus(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update scale of the specified ReplicationControllerDummy
//
extensions_v1beta1_scale_t*
ExtensionsV1beta1API_patchNamespacedReplicationControllerDummyScale(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update the specified PodSecurityPolicy
//
extensions_v1beta1_pod_security_policy_t*
ExtensionsV1beta1API_patchPodSecurityPolicy(apiClient_t *apiClient, char * name , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// read the specified DaemonSet
//
v1beta1_daemon_set_t*
ExtensionsV1beta1API_readNamespacedDaemonSet(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , int exact , int _export );


// read status of the specified DaemonSet
//
v1beta1_daemon_set_t*
ExtensionsV1beta1API_readNamespacedDaemonSetStatus(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// read the specified Deployment
//
extensions_v1beta1_deployment_t*
ExtensionsV1beta1API_readNamespacedDeployment(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , int exact , int _export );


// read scale of the specified Deployment
//
extensions_v1beta1_scale_t*
ExtensionsV1beta1API_readNamespacedDeploymentScale(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// read status of the specified Deployment
//
extensions_v1beta1_deployment_t*
ExtensionsV1beta1API_readNamespacedDeploymentStatus(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// read the specified Ingress
//
extensions_v1beta1_ingress_t*
ExtensionsV1beta1API_readNamespacedIngress(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , int exact , int _export );


// read status of the specified Ingress
//
extensions_v1beta1_ingress_t*
ExtensionsV1beta1API_readNamespacedIngressStatus(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// read the specified NetworkPolicy
//
v1beta1_network_policy_t*
ExtensionsV1beta1API_readNamespacedNetworkPolicy(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , int exact , int _export );


// read the specified ReplicaSet
//
v1beta1_replica_set_t*
ExtensionsV1beta1API_readNamespacedReplicaSet(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , int exact , int _export );


// read scale of the specified ReplicaSet
//
extensions_v1beta1_scale_t*
ExtensionsV1beta1API_readNamespacedReplicaSetScale(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// read status of the specified ReplicaSet
//
v1beta1_replica_set_t*
ExtensionsV1beta1API_readNamespacedReplicaSetStatus(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// read scale of the specified ReplicationControllerDummy
//
extensions_v1beta1_scale_t*
ExtensionsV1beta1API_readNamespacedReplicationControllerDummyScale(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// read the specified PodSecurityPolicy
//
extensions_v1beta1_pod_security_policy_t*
ExtensionsV1beta1API_readPodSecurityPolicy(apiClient_t *apiClient, char * name , char * pretty , int exact , int _export );


// replace the specified DaemonSet
//
v1beta1_daemon_set_t*
ExtensionsV1beta1API_replaceNamespacedDaemonSet(apiClient_t *apiClient, char * name , char * _namespace , v1beta1_daemon_set_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace status of the specified DaemonSet
//
v1beta1_daemon_set_t*
ExtensionsV1beta1API_replaceNamespacedDaemonSetStatus(apiClient_t *apiClient, char * name , char * _namespace , v1beta1_daemon_set_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace the specified Deployment
//
extensions_v1beta1_deployment_t*
ExtensionsV1beta1API_replaceNamespacedDeployment(apiClient_t *apiClient, char * name , char * _namespace , extensions_v1beta1_deployment_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace scale of the specified Deployment
//
extensions_v1beta1_scale_t*
ExtensionsV1beta1API_replaceNamespacedDeploymentScale(apiClient_t *apiClient, char * name , char * _namespace , extensions_v1beta1_scale_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace status of the specified Deployment
//
extensions_v1beta1_deployment_t*
ExtensionsV1beta1API_replaceNamespacedDeploymentStatus(apiClient_t *apiClient, char * name , char * _namespace , extensions_v1beta1_deployment_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace the specified Ingress
//
extensions_v1beta1_ingress_t*
ExtensionsV1beta1API_replaceNamespacedIngress(apiClient_t *apiClient, char * name , char * _namespace , extensions_v1beta1_ingress_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace status of the specified Ingress
//
extensions_v1beta1_ingress_t*
ExtensionsV1beta1API_replaceNamespacedIngressStatus(apiClient_t *apiClient, char * name , char * _namespace , extensions_v1beta1_ingress_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace the specified NetworkPolicy
//
v1beta1_network_policy_t*
ExtensionsV1beta1API_replaceNamespacedNetworkPolicy(apiClient_t *apiClient, char * name , char * _namespace , v1beta1_network_policy_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace the specified ReplicaSet
//
v1beta1_replica_set_t*
ExtensionsV1beta1API_replaceNamespacedReplicaSet(apiClient_t *apiClient, char * name , char * _namespace , v1beta1_replica_set_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace scale of the specified ReplicaSet
//
extensions_v1beta1_scale_t*
ExtensionsV1beta1API_replaceNamespacedReplicaSetScale(apiClient_t *apiClient, char * name , char * _namespace , extensions_v1beta1_scale_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace status of the specified ReplicaSet
//
v1beta1_replica_set_t*
ExtensionsV1beta1API_replaceNamespacedReplicaSetStatus(apiClient_t *apiClient, char * name , char * _namespace , v1beta1_replica_set_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace scale of the specified ReplicationControllerDummy
//
extensions_v1beta1_scale_t*
ExtensionsV1beta1API_replaceNamespacedReplicationControllerDummyScale(apiClient_t *apiClient, char * name , char * _namespace , extensions_v1beta1_scale_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace the specified PodSecurityPolicy
//
extensions_v1beta1_pod_security_policy_t*
ExtensionsV1beta1API_replacePodSecurityPolicy(apiClient_t *apiClient, char * name , extensions_v1beta1_pod_security_policy_t * body , char * pretty , char * dryRun , char * fieldManager );


