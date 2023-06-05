#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/object.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_pod_disruption_budget.h"
#include "../model/v1_pod_disruption_budget_list.h"
#include "../model/v1_status.h"


// create a PodDisruptionBudget
//
v1_pod_disruption_budget_t*
PolicyV1API_createNamespacedPodDisruptionBudget(apiClient_t *apiClient, char * _namespace , v1_pod_disruption_budget_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation );


// delete collection of PodDisruptionBudget
//
v1_status_t*
PolicyV1API_deleteCollectionNamespacedPodDisruptionBudget(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , char * resourceVersionMatch , int sendInitialEvents , int timeoutSeconds , v1_delete_options_t * body );


// delete a PodDisruptionBudget
//
v1_status_t*
PolicyV1API_deleteNamespacedPodDisruptionBudget(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// get available resources
//
v1_api_resource_list_t*
PolicyV1API_getAPIResources(apiClient_t *apiClient);


// list or watch objects of kind PodDisruptionBudget
//
v1_pod_disruption_budget_list_t*
PolicyV1API_listNamespacedPodDisruptionBudget(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , char * resourceVersionMatch , int sendInitialEvents , int timeoutSeconds , int watch );


// list or watch objects of kind PodDisruptionBudget
//
v1_pod_disruption_budget_list_t*
PolicyV1API_listPodDisruptionBudgetForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , char * resourceVersionMatch , int sendInitialEvents , int timeoutSeconds , int watch );


// partially update the specified PodDisruptionBudget
//
v1_pod_disruption_budget_t*
PolicyV1API_patchNamespacedPodDisruptionBudget(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation , int force );


// partially update status of the specified PodDisruptionBudget
//
v1_pod_disruption_budget_t*
PolicyV1API_patchNamespacedPodDisruptionBudgetStatus(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation , int force );


// read the specified PodDisruptionBudget
//
v1_pod_disruption_budget_t*
PolicyV1API_readNamespacedPodDisruptionBudget(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// read status of the specified PodDisruptionBudget
//
v1_pod_disruption_budget_t*
PolicyV1API_readNamespacedPodDisruptionBudgetStatus(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// replace the specified PodDisruptionBudget
//
v1_pod_disruption_budget_t*
PolicyV1API_replaceNamespacedPodDisruptionBudget(apiClient_t *apiClient, char * name , char * _namespace , v1_pod_disruption_budget_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation );


// replace status of the specified PodDisruptionBudget
//
v1_pod_disruption_budget_t*
PolicyV1API_replaceNamespacedPodDisruptionBudgetStatus(apiClient_t *apiClient, char * name , char * _namespace , v1_pod_disruption_budget_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation );


