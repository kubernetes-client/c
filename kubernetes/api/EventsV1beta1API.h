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
#include "../model/v1beta1_event.h"
#include "../model/v1beta1_event_list.h"


// create an Event
//
v1beta1_event_t*
EventsV1beta1API_createNamespacedEvent(apiClient_t *apiClient, char * _namespace , v1beta1_event_t * body , char * pretty , char * dryRun , char * fieldManager );


// delete collection of Event
//
v1_status_t*
EventsV1beta1API_deleteCollectionNamespacedEvent(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete an Event
//
v1_status_t*
EventsV1beta1API_deleteNamespacedEvent(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// get available resources
//
v1_api_resource_list_t*
EventsV1beta1API_getAPIResources(apiClient_t *apiClient);


// list or watch objects of kind Event
//
v1beta1_event_list_t*
EventsV1beta1API_listEventForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind Event
//
v1beta1_event_list_t*
EventsV1beta1API_listNamespacedEvent(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// partially update the specified Event
//
v1beta1_event_t*
EventsV1beta1API_patchNamespacedEvent(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// read the specified Event
//
v1beta1_event_t*
EventsV1beta1API_readNamespacedEvent(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , int exact , int _export );


// replace the specified Event
//
v1beta1_event_t*
EventsV1beta1API_replaceNamespacedEvent(apiClient_t *apiClient, char * name , char * _namespace , v1beta1_event_t * body , char * pretty , char * dryRun , char * fieldManager );


