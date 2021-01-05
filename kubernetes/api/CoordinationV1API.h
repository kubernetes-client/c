#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_lease.h"
#include "../model/v1_lease_list.h"
#include "../model/v1_status.h"


// create a Lease
//
v1_lease_t*
CoordinationV1API_createNamespacedLease(apiClient_t *apiClient, char * _namespace , v1_lease_t * body , char * pretty , char * dryRun , char * fieldManager );


// delete collection of Lease
//
v1_status_t*
CoordinationV1API_deleteCollectionNamespacedLease(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete a Lease
//
v1_status_t*
CoordinationV1API_deleteNamespacedLease(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// get available resources
//
v1_api_resource_list_t*
CoordinationV1API_getAPIResources(apiClient_t *apiClient);


// list or watch objects of kind Lease
//
v1_lease_list_t*
CoordinationV1API_listLeaseForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind Lease
//
v1_lease_list_t*
CoordinationV1API_listNamespacedLease(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// partially update the specified Lease
//
v1_lease_t*
CoordinationV1API_patchNamespacedLease(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// read the specified Lease
//
v1_lease_t*
CoordinationV1API_readNamespacedLease(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , int exact , int _export );


// replace the specified Lease
//
v1_lease_t*
CoordinationV1API_replaceNamespacedLease(apiClient_t *apiClient, char * name , char * _namespace , v1_lease_t * body , char * pretty , char * dryRun , char * fieldManager );


