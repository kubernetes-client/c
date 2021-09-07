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
#include "../model/v1alpha1_flow_schema.h"
#include "../model/v1alpha1_flow_schema_list.h"
#include "../model/v1alpha1_priority_level_configuration.h"
#include "../model/v1alpha1_priority_level_configuration_list.h"


// create a FlowSchema
//
v1alpha1_flow_schema_t*
FlowcontrolApiserverV1alpha1API_createFlowSchema(apiClient_t *apiClient, v1alpha1_flow_schema_t * body , char * pretty , char * dryRun , char * fieldManager );


// create a PriorityLevelConfiguration
//
v1alpha1_priority_level_configuration_t*
FlowcontrolApiserverV1alpha1API_createPriorityLevelConfiguration(apiClient_t *apiClient, v1alpha1_priority_level_configuration_t * body , char * pretty , char * dryRun , char * fieldManager );


// delete collection of FlowSchema
//
v1_status_t*
FlowcontrolApiserverV1alpha1API_deleteCollectionFlowSchema(apiClient_t *apiClient, char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of PriorityLevelConfiguration
//
v1_status_t*
FlowcontrolApiserverV1alpha1API_deleteCollectionPriorityLevelConfiguration(apiClient_t *apiClient, char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete a FlowSchema
//
v1_status_t*
FlowcontrolApiserverV1alpha1API_deleteFlowSchema(apiClient_t *apiClient, char * name , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete a PriorityLevelConfiguration
//
v1_status_t*
FlowcontrolApiserverV1alpha1API_deletePriorityLevelConfiguration(apiClient_t *apiClient, char * name , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// get available resources
//
v1_api_resource_list_t*
FlowcontrolApiserverV1alpha1API_getAPIResources(apiClient_t *apiClient);


// list or watch objects of kind FlowSchema
//
v1alpha1_flow_schema_list_t*
FlowcontrolApiserverV1alpha1API_listFlowSchema(apiClient_t *apiClient, char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind PriorityLevelConfiguration
//
v1alpha1_priority_level_configuration_list_t*
FlowcontrolApiserverV1alpha1API_listPriorityLevelConfiguration(apiClient_t *apiClient, char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// partially update the specified FlowSchema
//
v1alpha1_flow_schema_t*
FlowcontrolApiserverV1alpha1API_patchFlowSchema(apiClient_t *apiClient, char * name , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update status of the specified FlowSchema
//
v1alpha1_flow_schema_t*
FlowcontrolApiserverV1alpha1API_patchFlowSchemaStatus(apiClient_t *apiClient, char * name , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update the specified PriorityLevelConfiguration
//
v1alpha1_priority_level_configuration_t*
FlowcontrolApiserverV1alpha1API_patchPriorityLevelConfiguration(apiClient_t *apiClient, char * name , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update status of the specified PriorityLevelConfiguration
//
v1alpha1_priority_level_configuration_t*
FlowcontrolApiserverV1alpha1API_patchPriorityLevelConfigurationStatus(apiClient_t *apiClient, char * name , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// read the specified FlowSchema
//
v1alpha1_flow_schema_t*
FlowcontrolApiserverV1alpha1API_readFlowSchema(apiClient_t *apiClient, char * name , char * pretty , int exact , int _export );


// read status of the specified FlowSchema
//
v1alpha1_flow_schema_t*
FlowcontrolApiserverV1alpha1API_readFlowSchemaStatus(apiClient_t *apiClient, char * name , char * pretty );


// read the specified PriorityLevelConfiguration
//
v1alpha1_priority_level_configuration_t*
FlowcontrolApiserverV1alpha1API_readPriorityLevelConfiguration(apiClient_t *apiClient, char * name , char * pretty , int exact , int _export );


// read status of the specified PriorityLevelConfiguration
//
v1alpha1_priority_level_configuration_t*
FlowcontrolApiserverV1alpha1API_readPriorityLevelConfigurationStatus(apiClient_t *apiClient, char * name , char * pretty );


// replace the specified FlowSchema
//
v1alpha1_flow_schema_t*
FlowcontrolApiserverV1alpha1API_replaceFlowSchema(apiClient_t *apiClient, char * name , v1alpha1_flow_schema_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace status of the specified FlowSchema
//
v1alpha1_flow_schema_t*
FlowcontrolApiserverV1alpha1API_replaceFlowSchemaStatus(apiClient_t *apiClient, char * name , v1alpha1_flow_schema_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace the specified PriorityLevelConfiguration
//
v1alpha1_priority_level_configuration_t*
FlowcontrolApiserverV1alpha1API_replacePriorityLevelConfiguration(apiClient_t *apiClient, char * name , v1alpha1_priority_level_configuration_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace status of the specified PriorityLevelConfiguration
//
v1alpha1_priority_level_configuration_t*
FlowcontrolApiserverV1alpha1API_replacePriorityLevelConfigurationStatus(apiClient_t *apiClient, char * name , v1alpha1_priority_level_configuration_t * body , char * pretty , char * dryRun , char * fieldManager );


