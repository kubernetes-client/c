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
#include "../model/v1beta1_runtime_class.h"
#include "../model/v1beta1_runtime_class_list.h"


// create a RuntimeClass
//
v1beta1_runtime_class_t*
NodeV1beta1API_createRuntimeClass(apiClient_t *apiClient, v1beta1_runtime_class_t * body , char * pretty , char * dryRun , char * fieldManager );


// delete collection of RuntimeClass
//
v1_status_t*
NodeV1beta1API_deleteCollectionRuntimeClass(apiClient_t *apiClient, char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete a RuntimeClass
//
v1_status_t*
NodeV1beta1API_deleteRuntimeClass(apiClient_t *apiClient, char * name , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// get available resources
//
v1_api_resource_list_t*
NodeV1beta1API_getAPIResources(apiClient_t *apiClient);


// list or watch objects of kind RuntimeClass
//
v1beta1_runtime_class_list_t*
NodeV1beta1API_listRuntimeClass(apiClient_t *apiClient, char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// partially update the specified RuntimeClass
//
v1beta1_runtime_class_t*
NodeV1beta1API_patchRuntimeClass(apiClient_t *apiClient, char * name , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// read the specified RuntimeClass
//
v1beta1_runtime_class_t*
NodeV1beta1API_readRuntimeClass(apiClient_t *apiClient, char * name , char * pretty , int exact , int _export );


// replace the specified RuntimeClass
//
v1beta1_runtime_class_t*
NodeV1beta1API_replaceRuntimeClass(apiClient_t *apiClient, char * name , v1beta1_runtime_class_t * body , char * pretty , char * dryRun , char * fieldManager );


