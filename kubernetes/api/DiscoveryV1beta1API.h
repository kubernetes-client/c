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
#include "../model/v1beta1_endpoint_slice.h"
#include "../model/v1beta1_endpoint_slice_list.h"


// create an EndpointSlice
//
v1beta1_endpoint_slice_t*
DiscoveryV1beta1API_createNamespacedEndpointSlice(apiClient_t *apiClient, char * _namespace , v1beta1_endpoint_slice_t * body , char * pretty , char * dryRun , char * fieldManager );


// delete collection of EndpointSlice
//
v1_status_t*
DiscoveryV1beta1API_deleteCollectionNamespacedEndpointSlice(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete an EndpointSlice
//
v1_status_t*
DiscoveryV1beta1API_deleteNamespacedEndpointSlice(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// get available resources
//
v1_api_resource_list_t*
DiscoveryV1beta1API_getAPIResources(apiClient_t *apiClient);


// list or watch objects of kind EndpointSlice
//
v1beta1_endpoint_slice_list_t*
DiscoveryV1beta1API_listEndpointSliceForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind EndpointSlice
//
v1beta1_endpoint_slice_list_t*
DiscoveryV1beta1API_listNamespacedEndpointSlice(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// partially update the specified EndpointSlice
//
v1beta1_endpoint_slice_t*
DiscoveryV1beta1API_patchNamespacedEndpointSlice(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// read the specified EndpointSlice
//
v1beta1_endpoint_slice_t*
DiscoveryV1beta1API_readNamespacedEndpointSlice(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , int exact , int _export );


// replace the specified EndpointSlice
//
v1beta1_endpoint_slice_t*
DiscoveryV1beta1API_replaceNamespacedEndpointSlice(apiClient_t *apiClient, char * name , char * _namespace , v1beta1_endpoint_slice_t * body , char * pretty , char * dryRun , char * fieldManager );


