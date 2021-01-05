#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_custom_resource_definition.h"
#include "../model/v1_custom_resource_definition_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_status.h"


// create a CustomResourceDefinition
//
v1_custom_resource_definition_t*
ApiextensionsV1API_createCustomResourceDefinition(apiClient_t *apiClient, v1_custom_resource_definition_t * body , char * pretty , char * dryRun , char * fieldManager );


// delete collection of CustomResourceDefinition
//
v1_status_t*
ApiextensionsV1API_deleteCollectionCustomResourceDefinition(apiClient_t *apiClient, char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete a CustomResourceDefinition
//
v1_status_t*
ApiextensionsV1API_deleteCustomResourceDefinition(apiClient_t *apiClient, char * name , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// get available resources
//
v1_api_resource_list_t*
ApiextensionsV1API_getAPIResources(apiClient_t *apiClient);


// list or watch objects of kind CustomResourceDefinition
//
v1_custom_resource_definition_list_t*
ApiextensionsV1API_listCustomResourceDefinition(apiClient_t *apiClient, char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// partially update the specified CustomResourceDefinition
//
v1_custom_resource_definition_t*
ApiextensionsV1API_patchCustomResourceDefinition(apiClient_t *apiClient, char * name , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update status of the specified CustomResourceDefinition
//
v1_custom_resource_definition_t*
ApiextensionsV1API_patchCustomResourceDefinitionStatus(apiClient_t *apiClient, char * name , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// read the specified CustomResourceDefinition
//
v1_custom_resource_definition_t*
ApiextensionsV1API_readCustomResourceDefinition(apiClient_t *apiClient, char * name , char * pretty , int exact , int _export );


// read status of the specified CustomResourceDefinition
//
v1_custom_resource_definition_t*
ApiextensionsV1API_readCustomResourceDefinitionStatus(apiClient_t *apiClient, char * name , char * pretty );


// replace the specified CustomResourceDefinition
//
v1_custom_resource_definition_t*
ApiextensionsV1API_replaceCustomResourceDefinition(apiClient_t *apiClient, char * name , v1_custom_resource_definition_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace status of the specified CustomResourceDefinition
//
v1_custom_resource_definition_t*
ApiextensionsV1API_replaceCustomResourceDefinitionStatus(apiClient_t *apiClient, char * name , v1_custom_resource_definition_t * body , char * pretty , char * dryRun , char * fieldManager );


