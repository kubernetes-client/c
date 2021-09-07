#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/apps_v1beta1_deployment.h"
#include "../model/apps_v1beta1_deployment_list.h"
#include "../model/apps_v1beta1_deployment_rollback.h"
#include "../model/apps_v1beta1_scale.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_status.h"
#include "../model/v1beta1_controller_revision.h"
#include "../model/v1beta1_controller_revision_list.h"
#include "../model/v1beta1_stateful_set.h"
#include "../model/v1beta1_stateful_set_list.h"


// create a ControllerRevision
//
v1beta1_controller_revision_t*
AppsV1beta1API_createNamespacedControllerRevision(apiClient_t *apiClient, char * _namespace , v1beta1_controller_revision_t * body , char * pretty , char * dryRun , char * fieldManager );


// create a Deployment
//
apps_v1beta1_deployment_t*
AppsV1beta1API_createNamespacedDeployment(apiClient_t *apiClient, char * _namespace , apps_v1beta1_deployment_t * body , char * pretty , char * dryRun , char * fieldManager );


// create rollback of a Deployment
//
v1_status_t*
AppsV1beta1API_createNamespacedDeploymentRollback(apiClient_t *apiClient, char * name , char * _namespace , apps_v1beta1_deployment_rollback_t * body , char * dryRun , char * fieldManager , char * pretty );


// create a StatefulSet
//
v1beta1_stateful_set_t*
AppsV1beta1API_createNamespacedStatefulSet(apiClient_t *apiClient, char * _namespace , v1beta1_stateful_set_t * body , char * pretty , char * dryRun , char * fieldManager );


// delete collection of ControllerRevision
//
v1_status_t*
AppsV1beta1API_deleteCollectionNamespacedControllerRevision(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of Deployment
//
v1_status_t*
AppsV1beta1API_deleteCollectionNamespacedDeployment(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of StatefulSet
//
v1_status_t*
AppsV1beta1API_deleteCollectionNamespacedStatefulSet(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete a ControllerRevision
//
v1_status_t*
AppsV1beta1API_deleteNamespacedControllerRevision(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete a Deployment
//
v1_status_t*
AppsV1beta1API_deleteNamespacedDeployment(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete a StatefulSet
//
v1_status_t*
AppsV1beta1API_deleteNamespacedStatefulSet(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// get available resources
//
v1_api_resource_list_t*
AppsV1beta1API_getAPIResources(apiClient_t *apiClient);


// list or watch objects of kind ControllerRevision
//
v1beta1_controller_revision_list_t*
AppsV1beta1API_listControllerRevisionForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind Deployment
//
apps_v1beta1_deployment_list_t*
AppsV1beta1API_listDeploymentForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind ControllerRevision
//
v1beta1_controller_revision_list_t*
AppsV1beta1API_listNamespacedControllerRevision(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind Deployment
//
apps_v1beta1_deployment_list_t*
AppsV1beta1API_listNamespacedDeployment(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind StatefulSet
//
v1beta1_stateful_set_list_t*
AppsV1beta1API_listNamespacedStatefulSet(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind StatefulSet
//
v1beta1_stateful_set_list_t*
AppsV1beta1API_listStatefulSetForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch );


// partially update the specified ControllerRevision
//
v1beta1_controller_revision_t*
AppsV1beta1API_patchNamespacedControllerRevision(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update the specified Deployment
//
apps_v1beta1_deployment_t*
AppsV1beta1API_patchNamespacedDeployment(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update scale of the specified Deployment
//
apps_v1beta1_scale_t*
AppsV1beta1API_patchNamespacedDeploymentScale(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update status of the specified Deployment
//
apps_v1beta1_deployment_t*
AppsV1beta1API_patchNamespacedDeploymentStatus(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update the specified StatefulSet
//
v1beta1_stateful_set_t*
AppsV1beta1API_patchNamespacedStatefulSet(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update scale of the specified StatefulSet
//
apps_v1beta1_scale_t*
AppsV1beta1API_patchNamespacedStatefulSetScale(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update status of the specified StatefulSet
//
v1beta1_stateful_set_t*
AppsV1beta1API_patchNamespacedStatefulSetStatus(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// read the specified ControllerRevision
//
v1beta1_controller_revision_t*
AppsV1beta1API_readNamespacedControllerRevision(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , int exact , int _export );


// read the specified Deployment
//
apps_v1beta1_deployment_t*
AppsV1beta1API_readNamespacedDeployment(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , int exact , int _export );


// read scale of the specified Deployment
//
apps_v1beta1_scale_t*
AppsV1beta1API_readNamespacedDeploymentScale(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// read status of the specified Deployment
//
apps_v1beta1_deployment_t*
AppsV1beta1API_readNamespacedDeploymentStatus(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// read the specified StatefulSet
//
v1beta1_stateful_set_t*
AppsV1beta1API_readNamespacedStatefulSet(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , int exact , int _export );


// read scale of the specified StatefulSet
//
apps_v1beta1_scale_t*
AppsV1beta1API_readNamespacedStatefulSetScale(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// read status of the specified StatefulSet
//
v1beta1_stateful_set_t*
AppsV1beta1API_readNamespacedStatefulSetStatus(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// replace the specified ControllerRevision
//
v1beta1_controller_revision_t*
AppsV1beta1API_replaceNamespacedControllerRevision(apiClient_t *apiClient, char * name , char * _namespace , v1beta1_controller_revision_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace the specified Deployment
//
apps_v1beta1_deployment_t*
AppsV1beta1API_replaceNamespacedDeployment(apiClient_t *apiClient, char * name , char * _namespace , apps_v1beta1_deployment_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace scale of the specified Deployment
//
apps_v1beta1_scale_t*
AppsV1beta1API_replaceNamespacedDeploymentScale(apiClient_t *apiClient, char * name , char * _namespace , apps_v1beta1_scale_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace status of the specified Deployment
//
apps_v1beta1_deployment_t*
AppsV1beta1API_replaceNamespacedDeploymentStatus(apiClient_t *apiClient, char * name , char * _namespace , apps_v1beta1_deployment_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace the specified StatefulSet
//
v1beta1_stateful_set_t*
AppsV1beta1API_replaceNamespacedStatefulSet(apiClient_t *apiClient, char * name , char * _namespace , v1beta1_stateful_set_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace scale of the specified StatefulSet
//
apps_v1beta1_scale_t*
AppsV1beta1API_replaceNamespacedStatefulSetScale(apiClient_t *apiClient, char * name , char * _namespace , apps_v1beta1_scale_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace status of the specified StatefulSet
//
v1beta1_stateful_set_t*
AppsV1beta1API_replaceNamespacedStatefulSetStatus(apiClient_t *apiClient, char * name , char * _namespace , v1beta1_stateful_set_t * body , char * pretty , char * dryRun , char * fieldManager );


