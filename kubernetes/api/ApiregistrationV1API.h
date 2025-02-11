#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/object.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_api_service.h"
#include "../model/v1_api_service_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_status.h"


// create an APIService
//
v1_api_service_t*
ApiregistrationV1API_createAPIService(apiClient_t *apiClient, v1_api_service_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// delete an APIService
//
v1_status_t*
ApiregistrationV1API_deleteAPIService(apiClient_t *apiClient, char *name, char *pretty, char *dryRun, int *gracePeriodSeconds, int *ignoreStoreReadErrorWithClusterBreakingPotential, int *orphanDependents, char *propagationPolicy, v1_delete_options_t *body);


// delete collection of APIService
//
v1_status_t*
ApiregistrationV1API_deleteCollectionAPIService(apiClient_t *apiClient, char *pretty, char *_continue, char *dryRun, char *fieldSelector, int *gracePeriodSeconds, int *ignoreStoreReadErrorWithClusterBreakingPotential, char *labelSelector, int *limit, int *orphanDependents, char *propagationPolicy, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, v1_delete_options_t *body);


// get available resources
//
v1_api_resource_list_t*
ApiregistrationV1API_getAPIResources(apiClient_t *apiClient);


// list or watch objects of kind APIService
//
v1_api_service_list_t*
ApiregistrationV1API_listAPIService(apiClient_t *apiClient, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// partially update the specified APIService
//
v1_api_service_t*
ApiregistrationV1API_patchAPIService(apiClient_t *apiClient, char *name, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// partially update status of the specified APIService
//
v1_api_service_t*
ApiregistrationV1API_patchAPIServiceStatus(apiClient_t *apiClient, char *name, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// read the specified APIService
//
v1_api_service_t*
ApiregistrationV1API_readAPIService(apiClient_t *apiClient, char *name, char *pretty);


// read status of the specified APIService
//
v1_api_service_t*
ApiregistrationV1API_readAPIServiceStatus(apiClient_t *apiClient, char *name, char *pretty);


// replace the specified APIService
//
v1_api_service_t*
ApiregistrationV1API_replaceAPIService(apiClient_t *apiClient, char *name, v1_api_service_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// replace status of the specified APIService
//
v1_api_service_t*
ApiregistrationV1API_replaceAPIServiceStatus(apiClient_t *apiClient, char *name, v1_api_service_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


