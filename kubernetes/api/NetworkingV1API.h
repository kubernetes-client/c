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
#include "../model/v1_ingress.h"
#include "../model/v1_ingress_class.h"
#include "../model/v1_ingress_class_list.h"
#include "../model/v1_ingress_list.h"
#include "../model/v1_network_policy.h"
#include "../model/v1_network_policy_list.h"
#include "../model/v1_status.h"


// create an IngressClass
//
v1_ingress_class_t*
NetworkingV1API_createIngressClass(apiClient_t *apiClient, v1_ingress_class_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation );


// create an Ingress
//
v1_ingress_t*
NetworkingV1API_createNamespacedIngress(apiClient_t *apiClient, char * _namespace , v1_ingress_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation );


// create a NetworkPolicy
//
v1_network_policy_t*
NetworkingV1API_createNamespacedNetworkPolicy(apiClient_t *apiClient, char * _namespace , v1_network_policy_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation );


// delete collection of IngressClass
//
v1_status_t*
NetworkingV1API_deleteCollectionIngressClass(apiClient_t *apiClient, char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of Ingress
//
v1_status_t*
NetworkingV1API_deleteCollectionNamespacedIngress(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of NetworkPolicy
//
v1_status_t*
NetworkingV1API_deleteCollectionNamespacedNetworkPolicy(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , v1_delete_options_t * body );


// delete an IngressClass
//
v1_status_t*
NetworkingV1API_deleteIngressClass(apiClient_t *apiClient, char * name , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete an Ingress
//
v1_status_t*
NetworkingV1API_deleteNamespacedIngress(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete a NetworkPolicy
//
v1_status_t*
NetworkingV1API_deleteNamespacedNetworkPolicy(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// get available resources
//
v1_api_resource_list_t*
NetworkingV1API_getAPIResources(apiClient_t *apiClient);


// list or watch objects of kind IngressClass
//
v1_ingress_class_list_t*
NetworkingV1API_listIngressClass(apiClient_t *apiClient, char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , int watch );


// list or watch objects of kind Ingress
//
v1_ingress_list_t*
NetworkingV1API_listIngressForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , int watch );


// list or watch objects of kind Ingress
//
v1_ingress_list_t*
NetworkingV1API_listNamespacedIngress(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , int watch );


// list or watch objects of kind NetworkPolicy
//
v1_network_policy_list_t*
NetworkingV1API_listNamespacedNetworkPolicy(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , int watch );


// list or watch objects of kind NetworkPolicy
//
v1_network_policy_list_t*
NetworkingV1API_listNetworkPolicyForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , int watch );


// partially update the specified IngressClass
//
v1_ingress_class_t*
NetworkingV1API_patchIngressClass(apiClient_t *apiClient, char * name , object_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation , int force );


// partially update the specified Ingress
//
v1_ingress_t*
NetworkingV1API_patchNamespacedIngress(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation , int force );


// partially update status of the specified Ingress
//
v1_ingress_t*
NetworkingV1API_patchNamespacedIngressStatus(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation , int force );


// partially update the specified NetworkPolicy
//
v1_network_policy_t*
NetworkingV1API_patchNamespacedNetworkPolicy(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation , int force );


// partially update status of the specified NetworkPolicy
//
v1_network_policy_t*
NetworkingV1API_patchNamespacedNetworkPolicyStatus(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation , int force );


// read the specified IngressClass
//
v1_ingress_class_t*
NetworkingV1API_readIngressClass(apiClient_t *apiClient, char * name , char * pretty );


// read the specified Ingress
//
v1_ingress_t*
NetworkingV1API_readNamespacedIngress(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// read status of the specified Ingress
//
v1_ingress_t*
NetworkingV1API_readNamespacedIngressStatus(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// read the specified NetworkPolicy
//
v1_network_policy_t*
NetworkingV1API_readNamespacedNetworkPolicy(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// read status of the specified NetworkPolicy
//
v1_network_policy_t*
NetworkingV1API_readNamespacedNetworkPolicyStatus(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// replace the specified IngressClass
//
v1_ingress_class_t*
NetworkingV1API_replaceIngressClass(apiClient_t *apiClient, char * name , v1_ingress_class_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation );


// replace the specified Ingress
//
v1_ingress_t*
NetworkingV1API_replaceNamespacedIngress(apiClient_t *apiClient, char * name , char * _namespace , v1_ingress_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation );


// replace status of the specified Ingress
//
v1_ingress_t*
NetworkingV1API_replaceNamespacedIngressStatus(apiClient_t *apiClient, char * name , char * _namespace , v1_ingress_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation );


// replace the specified NetworkPolicy
//
v1_network_policy_t*
NetworkingV1API_replaceNamespacedNetworkPolicy(apiClient_t *apiClient, char * name , char * _namespace , v1_network_policy_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation );


// replace status of the specified NetworkPolicy
//
v1_network_policy_t*
NetworkingV1API_replaceNamespacedNetworkPolicyStatus(apiClient_t *apiClient, char * name , char * _namespace , v1_network_policy_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation );


