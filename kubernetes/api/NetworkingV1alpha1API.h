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
#include "../model/v1alpha1_cluster_cidr.h"
#include "../model/v1alpha1_cluster_cidr_list.h"


// create a ClusterCIDR
//
v1alpha1_cluster_cidr_t*
NetworkingV1alpha1API_createClusterCIDR(apiClient_t *apiClient, v1alpha1_cluster_cidr_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation );


// delete a ClusterCIDR
//
v1_status_t*
NetworkingV1alpha1API_deleteClusterCIDR(apiClient_t *apiClient, char * name , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete collection of ClusterCIDR
//
v1_status_t*
NetworkingV1alpha1API_deleteCollectionClusterCIDR(apiClient_t *apiClient, char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , v1_delete_options_t * body );


// get available resources
//
v1_api_resource_list_t*
NetworkingV1alpha1API_getAPIResources(apiClient_t *apiClient);


// list or watch objects of kind ClusterCIDR
//
v1alpha1_cluster_cidr_list_t*
NetworkingV1alpha1API_listClusterCIDR(apiClient_t *apiClient, char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , int watch );


// partially update the specified ClusterCIDR
//
v1alpha1_cluster_cidr_t*
NetworkingV1alpha1API_patchClusterCIDR(apiClient_t *apiClient, char * name , object_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation , int force );


// read the specified ClusterCIDR
//
v1alpha1_cluster_cidr_t*
NetworkingV1alpha1API_readClusterCIDR(apiClient_t *apiClient, char * name , char * pretty );


// replace the specified ClusterCIDR
//
v1alpha1_cluster_cidr_t*
NetworkingV1alpha1API_replaceClusterCIDR(apiClient_t *apiClient, char * name , v1alpha1_cluster_cidr_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation );


