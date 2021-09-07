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
#include "../model/v1beta1_cron_job.h"
#include "../model/v1beta1_cron_job_list.h"


// create a CronJob
//
v1beta1_cron_job_t*
BatchV1beta1API_createNamespacedCronJob(apiClient_t *apiClient, char * _namespace , v1beta1_cron_job_t * body , char * pretty , char * dryRun , char * fieldManager );


// delete collection of CronJob
//
v1_status_t*
BatchV1beta1API_deleteCollectionNamespacedCronJob(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete a CronJob
//
v1_status_t*
BatchV1beta1API_deleteNamespacedCronJob(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// get available resources
//
v1_api_resource_list_t*
BatchV1beta1API_getAPIResources(apiClient_t *apiClient);


// list or watch objects of kind CronJob
//
v1beta1_cron_job_list_t*
BatchV1beta1API_listCronJobForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind CronJob
//
v1beta1_cron_job_list_t*
BatchV1beta1API_listNamespacedCronJob(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// partially update the specified CronJob
//
v1beta1_cron_job_t*
BatchV1beta1API_patchNamespacedCronJob(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update status of the specified CronJob
//
v1beta1_cron_job_t*
BatchV1beta1API_patchNamespacedCronJobStatus(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// read the specified CronJob
//
v1beta1_cron_job_t*
BatchV1beta1API_readNamespacedCronJob(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , int exact , int _export );


// read status of the specified CronJob
//
v1beta1_cron_job_t*
BatchV1beta1API_readNamespacedCronJobStatus(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// replace the specified CronJob
//
v1beta1_cron_job_t*
BatchV1beta1API_replaceNamespacedCronJob(apiClient_t *apiClient, char * name , char * _namespace , v1beta1_cron_job_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace status of the specified CronJob
//
v1beta1_cron_job_t*
BatchV1beta1API_replaceNamespacedCronJobStatus(apiClient_t *apiClient, char * name , char * _namespace , v1beta1_cron_job_t * body , char * pretty , char * dryRun , char * fieldManager );


