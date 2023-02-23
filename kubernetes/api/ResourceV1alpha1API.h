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
#include "../model/v1_status.h"
#include "../model/v1alpha1_pod_scheduling.h"
#include "../model/v1alpha1_pod_scheduling_list.h"
#include "../model/v1alpha1_resource_claim.h"
#include "../model/v1alpha1_resource_claim_list.h"
#include "../model/v1alpha1_resource_claim_template.h"
#include "../model/v1alpha1_resource_claim_template_list.h"
#include "../model/v1alpha1_resource_class.h"
#include "../model/v1alpha1_resource_class_list.h"


// create a PodScheduling
//
v1alpha1_pod_scheduling_t*
ResourceV1alpha1API_createNamespacedPodScheduling(apiClient_t *apiClient, char * _namespace , v1alpha1_pod_scheduling_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation );


// create a ResourceClaim
//
v1alpha1_resource_claim_t*
ResourceV1alpha1API_createNamespacedResourceClaim(apiClient_t *apiClient, char * _namespace , v1alpha1_resource_claim_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation );


// create a ResourceClaimTemplate
//
v1alpha1_resource_claim_template_t*
ResourceV1alpha1API_createNamespacedResourceClaimTemplate(apiClient_t *apiClient, char * _namespace , v1alpha1_resource_claim_template_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation );


// create a ResourceClass
//
v1alpha1_resource_class_t*
ResourceV1alpha1API_createResourceClass(apiClient_t *apiClient, v1alpha1_resource_class_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation );


// delete collection of PodScheduling
//
v1_status_t*
ResourceV1alpha1API_deleteCollectionNamespacedPodScheduling(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of ResourceClaim
//
v1_status_t*
ResourceV1alpha1API_deleteCollectionNamespacedResourceClaim(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of ResourceClaimTemplate
//
v1_status_t*
ResourceV1alpha1API_deleteCollectionNamespacedResourceClaimTemplate(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of ResourceClass
//
v1_status_t*
ResourceV1alpha1API_deleteCollectionResourceClass(apiClient_t *apiClient, char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , v1_delete_options_t * body );


// delete a PodScheduling
//
v1alpha1_pod_scheduling_t*
ResourceV1alpha1API_deleteNamespacedPodScheduling(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete a ResourceClaim
//
v1alpha1_resource_claim_t*
ResourceV1alpha1API_deleteNamespacedResourceClaim(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete a ResourceClaimTemplate
//
v1alpha1_resource_claim_template_t*
ResourceV1alpha1API_deleteNamespacedResourceClaimTemplate(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete a ResourceClass
//
v1alpha1_resource_class_t*
ResourceV1alpha1API_deleteResourceClass(apiClient_t *apiClient, char * name , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// get available resources
//
v1_api_resource_list_t*
ResourceV1alpha1API_getAPIResources(apiClient_t *apiClient);


// list or watch objects of kind PodScheduling
//
v1alpha1_pod_scheduling_list_t*
ResourceV1alpha1API_listNamespacedPodScheduling(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , int watch );


// list or watch objects of kind ResourceClaim
//
v1alpha1_resource_claim_list_t*
ResourceV1alpha1API_listNamespacedResourceClaim(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , int watch );


// list or watch objects of kind ResourceClaimTemplate
//
v1alpha1_resource_claim_template_list_t*
ResourceV1alpha1API_listNamespacedResourceClaimTemplate(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , int watch );


// list or watch objects of kind PodScheduling
//
v1alpha1_pod_scheduling_list_t*
ResourceV1alpha1API_listPodSchedulingForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , int watch );


// list or watch objects of kind ResourceClaim
//
v1alpha1_resource_claim_list_t*
ResourceV1alpha1API_listResourceClaimForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , int watch );


// list or watch objects of kind ResourceClaimTemplate
//
v1alpha1_resource_claim_template_list_t*
ResourceV1alpha1API_listResourceClaimTemplateForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , int watch );


// list or watch objects of kind ResourceClass
//
v1alpha1_resource_class_list_t*
ResourceV1alpha1API_listResourceClass(apiClient_t *apiClient, char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , int watch );


// partially update the specified PodScheduling
//
v1alpha1_pod_scheduling_t*
ResourceV1alpha1API_patchNamespacedPodScheduling(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation , int force );


// partially update status of the specified PodScheduling
//
v1alpha1_pod_scheduling_t*
ResourceV1alpha1API_patchNamespacedPodSchedulingStatus(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation , int force );


// partially update the specified ResourceClaim
//
v1alpha1_resource_claim_t*
ResourceV1alpha1API_patchNamespacedResourceClaim(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation , int force );


// partially update status of the specified ResourceClaim
//
v1alpha1_resource_claim_t*
ResourceV1alpha1API_patchNamespacedResourceClaimStatus(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation , int force );


// partially update the specified ResourceClaimTemplate
//
v1alpha1_resource_claim_template_t*
ResourceV1alpha1API_patchNamespacedResourceClaimTemplate(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation , int force );


// partially update the specified ResourceClass
//
v1alpha1_resource_class_t*
ResourceV1alpha1API_patchResourceClass(apiClient_t *apiClient, char * name , object_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation , int force );


// read the specified PodScheduling
//
v1alpha1_pod_scheduling_t*
ResourceV1alpha1API_readNamespacedPodScheduling(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// read status of the specified PodScheduling
//
v1alpha1_pod_scheduling_t*
ResourceV1alpha1API_readNamespacedPodSchedulingStatus(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// read the specified ResourceClaim
//
v1alpha1_resource_claim_t*
ResourceV1alpha1API_readNamespacedResourceClaim(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// read status of the specified ResourceClaim
//
v1alpha1_resource_claim_t*
ResourceV1alpha1API_readNamespacedResourceClaimStatus(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// read the specified ResourceClaimTemplate
//
v1alpha1_resource_claim_template_t*
ResourceV1alpha1API_readNamespacedResourceClaimTemplate(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// read the specified ResourceClass
//
v1alpha1_resource_class_t*
ResourceV1alpha1API_readResourceClass(apiClient_t *apiClient, char * name , char * pretty );


// replace the specified PodScheduling
//
v1alpha1_pod_scheduling_t*
ResourceV1alpha1API_replaceNamespacedPodScheduling(apiClient_t *apiClient, char * name , char * _namespace , v1alpha1_pod_scheduling_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation );


// replace status of the specified PodScheduling
//
v1alpha1_pod_scheduling_t*
ResourceV1alpha1API_replaceNamespacedPodSchedulingStatus(apiClient_t *apiClient, char * name , char * _namespace , v1alpha1_pod_scheduling_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation );


// replace the specified ResourceClaim
//
v1alpha1_resource_claim_t*
ResourceV1alpha1API_replaceNamespacedResourceClaim(apiClient_t *apiClient, char * name , char * _namespace , v1alpha1_resource_claim_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation );


// replace status of the specified ResourceClaim
//
v1alpha1_resource_claim_t*
ResourceV1alpha1API_replaceNamespacedResourceClaimStatus(apiClient_t *apiClient, char * name , char * _namespace , v1alpha1_resource_claim_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation );


// replace the specified ResourceClaimTemplate
//
v1alpha1_resource_claim_template_t*
ResourceV1alpha1API_replaceNamespacedResourceClaimTemplate(apiClient_t *apiClient, char * name , char * _namespace , v1alpha1_resource_claim_template_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation );


// replace the specified ResourceClass
//
v1alpha1_resource_class_t*
ResourceV1alpha1API_replaceResourceClass(apiClient_t *apiClient, char * name , v1alpha1_resource_class_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation );


