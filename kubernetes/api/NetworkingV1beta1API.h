#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/networking_v1beta1_ingress.h"
#include "../model/networking_v1beta1_ingress_list.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_status.h"


// create an Ingress
//
networking_v1beta1_ingress_t*
NetworkingV1beta1API_createNamespacedIngress(apiClient_t *apiClient, char * _namespace , networking_v1beta1_ingress_t * body , char * pretty , char * dryRun , char * fieldManager );


// delete collection of Ingress
//
v1_status_t*
NetworkingV1beta1API_deleteCollectionNamespacedIngress(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete an Ingress
//
v1_status_t*
NetworkingV1beta1API_deleteNamespacedIngress(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// get available resources
//
v1_api_resource_list_t*
NetworkingV1beta1API_getAPIResources(apiClient_t *apiClient);


// list or watch objects of kind Ingress
//
networking_v1beta1_ingress_list_t*
NetworkingV1beta1API_listIngressForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind Ingress
//
networking_v1beta1_ingress_list_t*
NetworkingV1beta1API_listNamespacedIngress(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// partially update the specified Ingress
//
networking_v1beta1_ingress_t*
NetworkingV1beta1API_patchNamespacedIngress(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update status of the specified Ingress
//
networking_v1beta1_ingress_t*
NetworkingV1beta1API_patchNamespacedIngressStatus(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// read the specified Ingress
//
networking_v1beta1_ingress_t*
NetworkingV1beta1API_readNamespacedIngress(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , int exact , int _export );


// read status of the specified Ingress
//
networking_v1beta1_ingress_t*
NetworkingV1beta1API_readNamespacedIngressStatus(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// replace the specified Ingress
//
networking_v1beta1_ingress_t*
NetworkingV1beta1API_replaceNamespacedIngress(apiClient_t *apiClient, char * name , char * _namespace , networking_v1beta1_ingress_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace status of the specified Ingress
//
networking_v1beta1_ingress_t*
NetworkingV1beta1API_replaceNamespacedIngressStatus(apiClient_t *apiClient, char * name , char * _namespace , networking_v1beta1_ingress_t * body , char * pretty , char * dryRun , char * fieldManager );


