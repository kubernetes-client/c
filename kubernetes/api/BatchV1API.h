#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_job.h"
#include "../model/v1_job_list.h"
#include "../model/v1_status.h"


// create a Job
//
v1_job_t*
BatchV1API_createNamespacedJob(apiClient_t *apiClient, char * _namespace , v1_job_t * body , char * pretty , char * dryRun , char * fieldManager );


// delete collection of Job
//
v1_status_t*
BatchV1API_deleteCollectionNamespacedJob(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete a Job
//
v1_status_t*
BatchV1API_deleteNamespacedJob(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// get available resources
//
v1_api_resource_list_t*
BatchV1API_getAPIResources(apiClient_t *apiClient);


// list or watch objects of kind Job
//
v1_job_list_t*
BatchV1API_listJobForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind Job
//
v1_job_list_t*
BatchV1API_listNamespacedJob(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// partially update the specified Job
//
v1_job_t*
BatchV1API_patchNamespacedJob(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update status of the specified Job
//
v1_job_t*
BatchV1API_patchNamespacedJobStatus(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// read the specified Job
//
v1_job_t*
BatchV1API_readNamespacedJob(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , int exact , int _export );


// read status of the specified Job
//
v1_job_t*
BatchV1API_readNamespacedJobStatus(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// replace the specified Job
//
v1_job_t*
BatchV1API_replaceNamespacedJob(apiClient_t *apiClient, char * name , char * _namespace , v1_job_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace status of the specified Job
//
v1_job_t*
BatchV1API_replaceNamespacedJobStatus(apiClient_t *apiClient, char * name , char * _namespace , v1_job_t * body , char * pretty , char * dryRun , char * fieldManager );


