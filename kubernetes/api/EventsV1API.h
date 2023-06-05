#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/events_v1_event.h"
#include "../model/events_v1_event_list.h"
#include "../model/object.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_status.h"


// create an Event
//
events_v1_event_t*
EventsV1API_createNamespacedEvent(apiClient_t *apiClient, char * _namespace , events_v1_event_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation );


// delete collection of Event
//
v1_status_t*
EventsV1API_deleteCollectionNamespacedEvent(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , char * resourceVersionMatch , int sendInitialEvents , int timeoutSeconds , v1_delete_options_t * body );


// delete an Event
//
v1_status_t*
EventsV1API_deleteNamespacedEvent(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// get available resources
//
v1_api_resource_list_t*
EventsV1API_getAPIResources(apiClient_t *apiClient);


// list or watch objects of kind Event
//
events_v1_event_list_t*
EventsV1API_listEventForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , char * resourceVersionMatch , int sendInitialEvents , int timeoutSeconds , int watch );


// list or watch objects of kind Event
//
events_v1_event_list_t*
EventsV1API_listNamespacedEvent(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , char * resourceVersionMatch , int sendInitialEvents , int timeoutSeconds , int watch );


// partially update the specified Event
//
events_v1_event_t*
EventsV1API_patchNamespacedEvent(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation , int force );


// read the specified Event
//
events_v1_event_t*
EventsV1API_readNamespacedEvent(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// replace the specified Event
//
events_v1_event_t*
EventsV1API_replaceNamespacedEvent(apiClient_t *apiClient, char * name , char * _namespace , events_v1_event_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation );


