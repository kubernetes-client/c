#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_status.h"
#include "../model/v1beta2_controller_revision.h"
#include "../model/v1beta2_controller_revision_list.h"
#include "../model/v1beta2_daemon_set.h"
#include "../model/v1beta2_daemon_set_list.h"
#include "../model/v1beta2_deployment.h"
#include "../model/v1beta2_deployment_list.h"
#include "../model/v1beta2_replica_set.h"
#include "../model/v1beta2_replica_set_list.h"
#include "../model/v1beta2_scale.h"
#include "../model/v1beta2_stateful_set.h"
#include "../model/v1beta2_stateful_set_list.h"


// create a ControllerRevision
//
v1beta2_controller_revision_t*
AppsV1beta2API_createNamespacedControllerRevision(apiClient_t *apiClient, char * _namespace , v1beta2_controller_revision_t * body , char * pretty , char * dryRun , char * fieldManager );


// create a DaemonSet
//
v1beta2_daemon_set_t*
AppsV1beta2API_createNamespacedDaemonSet(apiClient_t *apiClient, char * _namespace , v1beta2_daemon_set_t * body , char * pretty , char * dryRun , char * fieldManager );


// create a Deployment
//
v1beta2_deployment_t*
AppsV1beta2API_createNamespacedDeployment(apiClient_t *apiClient, char * _namespace , v1beta2_deployment_t * body , char * pretty , char * dryRun , char * fieldManager );


// create a ReplicaSet
//
v1beta2_replica_set_t*
AppsV1beta2API_createNamespacedReplicaSet(apiClient_t *apiClient, char * _namespace , v1beta2_replica_set_t * body , char * pretty , char * dryRun , char * fieldManager );


// create a StatefulSet
//
v1beta2_stateful_set_t*
AppsV1beta2API_createNamespacedStatefulSet(apiClient_t *apiClient, char * _namespace , v1beta2_stateful_set_t * body , char * pretty , char * dryRun , char * fieldManager );


// delete collection of ControllerRevision
//
v1_status_t*
AppsV1beta2API_deleteCollectionNamespacedControllerRevision(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of DaemonSet
//
v1_status_t*
AppsV1beta2API_deleteCollectionNamespacedDaemonSet(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of Deployment
//
v1_status_t*
AppsV1beta2API_deleteCollectionNamespacedDeployment(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of ReplicaSet
//
v1_status_t*
AppsV1beta2API_deleteCollectionNamespacedReplicaSet(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of StatefulSet
//
v1_status_t*
AppsV1beta2API_deleteCollectionNamespacedStatefulSet(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete a ControllerRevision
//
v1_status_t*
AppsV1beta2API_deleteNamespacedControllerRevision(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete a DaemonSet
//
v1_status_t*
AppsV1beta2API_deleteNamespacedDaemonSet(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete a Deployment
//
v1_status_t*
AppsV1beta2API_deleteNamespacedDeployment(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete a ReplicaSet
//
v1_status_t*
AppsV1beta2API_deleteNamespacedReplicaSet(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete a StatefulSet
//
v1_status_t*
AppsV1beta2API_deleteNamespacedStatefulSet(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// get available resources
//
v1_api_resource_list_t*
AppsV1beta2API_getAPIResources(apiClient_t *apiClient);


// list or watch objects of kind ControllerRevision
//
v1beta2_controller_revision_list_t*
AppsV1beta2API_listControllerRevisionForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind DaemonSet
//
v1beta2_daemon_set_list_t*
AppsV1beta2API_listDaemonSetForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind Deployment
//
v1beta2_deployment_list_t*
AppsV1beta2API_listDeploymentForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind ControllerRevision
//
v1beta2_controller_revision_list_t*
AppsV1beta2API_listNamespacedControllerRevision(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind DaemonSet
//
v1beta2_daemon_set_list_t*
AppsV1beta2API_listNamespacedDaemonSet(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind Deployment
//
v1beta2_deployment_list_t*
AppsV1beta2API_listNamespacedDeployment(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind ReplicaSet
//
v1beta2_replica_set_list_t*
AppsV1beta2API_listNamespacedReplicaSet(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind StatefulSet
//
v1beta2_stateful_set_list_t*
AppsV1beta2API_listNamespacedStatefulSet(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind ReplicaSet
//
v1beta2_replica_set_list_t*
AppsV1beta2API_listReplicaSetForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind StatefulSet
//
v1beta2_stateful_set_list_t*
AppsV1beta2API_listStatefulSetForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch );


// partially update the specified ControllerRevision
//
v1beta2_controller_revision_t*
AppsV1beta2API_patchNamespacedControllerRevision(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update the specified DaemonSet
//
v1beta2_daemon_set_t*
AppsV1beta2API_patchNamespacedDaemonSet(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update status of the specified DaemonSet
//
v1beta2_daemon_set_t*
AppsV1beta2API_patchNamespacedDaemonSetStatus(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update the specified Deployment
//
v1beta2_deployment_t*
AppsV1beta2API_patchNamespacedDeployment(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update scale of the specified Deployment
//
v1beta2_scale_t*
AppsV1beta2API_patchNamespacedDeploymentScale(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update status of the specified Deployment
//
v1beta2_deployment_t*
AppsV1beta2API_patchNamespacedDeploymentStatus(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update the specified ReplicaSet
//
v1beta2_replica_set_t*
AppsV1beta2API_patchNamespacedReplicaSet(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update scale of the specified ReplicaSet
//
v1beta2_scale_t*
AppsV1beta2API_patchNamespacedReplicaSetScale(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update status of the specified ReplicaSet
//
v1beta2_replica_set_t*
AppsV1beta2API_patchNamespacedReplicaSetStatus(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update the specified StatefulSet
//
v1beta2_stateful_set_t*
AppsV1beta2API_patchNamespacedStatefulSet(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update scale of the specified StatefulSet
//
v1beta2_scale_t*
AppsV1beta2API_patchNamespacedStatefulSetScale(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update status of the specified StatefulSet
//
v1beta2_stateful_set_t*
AppsV1beta2API_patchNamespacedStatefulSetStatus(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// read the specified ControllerRevision
//
v1beta2_controller_revision_t*
AppsV1beta2API_readNamespacedControllerRevision(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , int exact , int _export );


// read the specified DaemonSet
//
v1beta2_daemon_set_t*
AppsV1beta2API_readNamespacedDaemonSet(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , int exact , int _export );


// read status of the specified DaemonSet
//
v1beta2_daemon_set_t*
AppsV1beta2API_readNamespacedDaemonSetStatus(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// read the specified Deployment
//
v1beta2_deployment_t*
AppsV1beta2API_readNamespacedDeployment(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , int exact , int _export );


// read scale of the specified Deployment
//
v1beta2_scale_t*
AppsV1beta2API_readNamespacedDeploymentScale(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// read status of the specified Deployment
//
v1beta2_deployment_t*
AppsV1beta2API_readNamespacedDeploymentStatus(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// read the specified ReplicaSet
//
v1beta2_replica_set_t*
AppsV1beta2API_readNamespacedReplicaSet(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , int exact , int _export );


// read scale of the specified ReplicaSet
//
v1beta2_scale_t*
AppsV1beta2API_readNamespacedReplicaSetScale(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// read status of the specified ReplicaSet
//
v1beta2_replica_set_t*
AppsV1beta2API_readNamespacedReplicaSetStatus(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// read the specified StatefulSet
//
v1beta2_stateful_set_t*
AppsV1beta2API_readNamespacedStatefulSet(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , int exact , int _export );


// read scale of the specified StatefulSet
//
v1beta2_scale_t*
AppsV1beta2API_readNamespacedStatefulSetScale(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// read status of the specified StatefulSet
//
v1beta2_stateful_set_t*
AppsV1beta2API_readNamespacedStatefulSetStatus(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// replace the specified ControllerRevision
//
v1beta2_controller_revision_t*
AppsV1beta2API_replaceNamespacedControllerRevision(apiClient_t *apiClient, char * name , char * _namespace , v1beta2_controller_revision_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace the specified DaemonSet
//
v1beta2_daemon_set_t*
AppsV1beta2API_replaceNamespacedDaemonSet(apiClient_t *apiClient, char * name , char * _namespace , v1beta2_daemon_set_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace status of the specified DaemonSet
//
v1beta2_daemon_set_t*
AppsV1beta2API_replaceNamespacedDaemonSetStatus(apiClient_t *apiClient, char * name , char * _namespace , v1beta2_daemon_set_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace the specified Deployment
//
v1beta2_deployment_t*
AppsV1beta2API_replaceNamespacedDeployment(apiClient_t *apiClient, char * name , char * _namespace , v1beta2_deployment_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace scale of the specified Deployment
//
v1beta2_scale_t*
AppsV1beta2API_replaceNamespacedDeploymentScale(apiClient_t *apiClient, char * name , char * _namespace , v1beta2_scale_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace status of the specified Deployment
//
v1beta2_deployment_t*
AppsV1beta2API_replaceNamespacedDeploymentStatus(apiClient_t *apiClient, char * name , char * _namespace , v1beta2_deployment_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace the specified ReplicaSet
//
v1beta2_replica_set_t*
AppsV1beta2API_replaceNamespacedReplicaSet(apiClient_t *apiClient, char * name , char * _namespace , v1beta2_replica_set_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace scale of the specified ReplicaSet
//
v1beta2_scale_t*
AppsV1beta2API_replaceNamespacedReplicaSetScale(apiClient_t *apiClient, char * name , char * _namespace , v1beta2_scale_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace status of the specified ReplicaSet
//
v1beta2_replica_set_t*
AppsV1beta2API_replaceNamespacedReplicaSetStatus(apiClient_t *apiClient, char * name , char * _namespace , v1beta2_replica_set_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace the specified StatefulSet
//
v1beta2_stateful_set_t*
AppsV1beta2API_replaceNamespacedStatefulSet(apiClient_t *apiClient, char * name , char * _namespace , v1beta2_stateful_set_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace scale of the specified StatefulSet
//
v1beta2_scale_t*
AppsV1beta2API_replaceNamespacedStatefulSetScale(apiClient_t *apiClient, char * name , char * _namespace , v1beta2_scale_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace status of the specified StatefulSet
//
v1beta2_stateful_set_t*
AppsV1beta2API_replaceNamespacedStatefulSetStatus(apiClient_t *apiClient, char * name , char * _namespace , v1beta2_stateful_set_t * body , char * pretty , char * dryRun , char * fieldManager );


