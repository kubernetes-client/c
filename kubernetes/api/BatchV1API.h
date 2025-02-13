#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/object.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_cron_job.h"
#include "../model/v1_cron_job_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_job.h"
#include "../model/v1_job_list.h"
#include "../model/v1_status.h"


// create a CronJob
//
v1_cron_job_t*
BatchV1API_createNamespacedCronJob(apiClient_t *apiClient, char *_namespace, v1_cron_job_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// create a Job
//
v1_job_t*
BatchV1API_createNamespacedJob(apiClient_t *apiClient, char *_namespace, v1_job_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// delete collection of CronJob
//
v1_status_t*
BatchV1API_deleteCollectionNamespacedCronJob(apiClient_t *apiClient, char *_namespace, char *pretty, char *_continue, char *dryRun, char *fieldSelector, int *gracePeriodSeconds, int *ignoreStoreReadErrorWithClusterBreakingPotential, char *labelSelector, int *limit, int *orphanDependents, char *propagationPolicy, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, v1_delete_options_t *body);


// delete collection of Job
//
v1_status_t*
BatchV1API_deleteCollectionNamespacedJob(apiClient_t *apiClient, char *_namespace, char *pretty, char *_continue, char *dryRun, char *fieldSelector, int *gracePeriodSeconds, int *ignoreStoreReadErrorWithClusterBreakingPotential, char *labelSelector, int *limit, int *orphanDependents, char *propagationPolicy, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, v1_delete_options_t *body);


// delete a CronJob
//
v1_status_t*
BatchV1API_deleteNamespacedCronJob(apiClient_t *apiClient, char *name, char *_namespace, char *pretty, char *dryRun, int *gracePeriodSeconds, int *ignoreStoreReadErrorWithClusterBreakingPotential, int *orphanDependents, char *propagationPolicy, v1_delete_options_t *body);


// delete a Job
//
v1_status_t*
BatchV1API_deleteNamespacedJob(apiClient_t *apiClient, char *name, char *_namespace, char *pretty, char *dryRun, int *gracePeriodSeconds, int *ignoreStoreReadErrorWithClusterBreakingPotential, int *orphanDependents, char *propagationPolicy, v1_delete_options_t *body);


// get available resources
//
v1_api_resource_list_t*
BatchV1API_getAPIResources(apiClient_t *apiClient);


// list or watch objects of kind CronJob
//
v1_cron_job_list_t*
BatchV1API_listCronJobForAllNamespaces(apiClient_t *apiClient, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *pretty, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// list or watch objects of kind Job
//
v1_job_list_t*
BatchV1API_listJobForAllNamespaces(apiClient_t *apiClient, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *pretty, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// list or watch objects of kind CronJob
//
v1_cron_job_list_t*
BatchV1API_listNamespacedCronJob(apiClient_t *apiClient, char *_namespace, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// list or watch objects of kind Job
//
v1_job_list_t*
BatchV1API_listNamespacedJob(apiClient_t *apiClient, char *_namespace, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// partially update the specified CronJob
//
v1_cron_job_t*
BatchV1API_patchNamespacedCronJob(apiClient_t *apiClient, char *name, char *_namespace, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// partially update status of the specified CronJob
//
v1_cron_job_t*
BatchV1API_patchNamespacedCronJobStatus(apiClient_t *apiClient, char *name, char *_namespace, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// partially update the specified Job
//
v1_job_t*
BatchV1API_patchNamespacedJob(apiClient_t *apiClient, char *name, char *_namespace, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// partially update status of the specified Job
//
v1_job_t*
BatchV1API_patchNamespacedJobStatus(apiClient_t *apiClient, char *name, char *_namespace, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// read the specified CronJob
//
v1_cron_job_t*
BatchV1API_readNamespacedCronJob(apiClient_t *apiClient, char *name, char *_namespace, char *pretty);


// read status of the specified CronJob
//
v1_cron_job_t*
BatchV1API_readNamespacedCronJobStatus(apiClient_t *apiClient, char *name, char *_namespace, char *pretty);


// read the specified Job
//
v1_job_t*
BatchV1API_readNamespacedJob(apiClient_t *apiClient, char *name, char *_namespace, char *pretty);


// read status of the specified Job
//
v1_job_t*
BatchV1API_readNamespacedJobStatus(apiClient_t *apiClient, char *name, char *_namespace, char *pretty);


// replace the specified CronJob
//
v1_cron_job_t*
BatchV1API_replaceNamespacedCronJob(apiClient_t *apiClient, char *name, char *_namespace, v1_cron_job_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// replace status of the specified CronJob
//
v1_cron_job_t*
BatchV1API_replaceNamespacedCronJobStatus(apiClient_t *apiClient, char *name, char *_namespace, v1_cron_job_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// replace the specified Job
//
v1_job_t*
BatchV1API_replaceNamespacedJob(apiClient_t *apiClient, char *name, char *_namespace, v1_job_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// replace status of the specified Job
//
v1_job_t*
BatchV1API_replaceNamespacedJobStatus(apiClient_t *apiClient, char *name, char *_namespace, v1_job_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


