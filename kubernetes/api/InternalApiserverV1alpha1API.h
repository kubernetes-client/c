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
#include "../model/v1_status.h"
#include "../model/v1alpha1_storage_version.h"
#include "../model/v1alpha1_storage_version_list.h"


// create a StorageVersion
//
v1alpha1_storage_version_t*
InternalApiserverV1alpha1API_createStorageVersion(apiClient_t *apiClient, v1alpha1_storage_version_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// delete collection of StorageVersion
//
v1_status_t*
InternalApiserverV1alpha1API_deleteCollectionStorageVersion(apiClient_t *apiClient, char *pretty, char *_continue, char *dryRun, char *fieldSelector, int *gracePeriodSeconds, char *labelSelector, int *limit, int *orphanDependents, char *propagationPolicy, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, v1_delete_options_t *body);


// delete a StorageVersion
//
v1_status_t*
InternalApiserverV1alpha1API_deleteStorageVersion(apiClient_t *apiClient, char *name, char *pretty, char *dryRun, int *gracePeriodSeconds, int *orphanDependents, char *propagationPolicy, v1_delete_options_t *body);


// get available resources
//
v1_api_resource_list_t*
InternalApiserverV1alpha1API_getAPIResources_21(apiClient_t *apiClient);


// list or watch objects of kind StorageVersion
//
v1alpha1_storage_version_list_t*
InternalApiserverV1alpha1API_listStorageVersion(apiClient_t *apiClient, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// partially update the specified StorageVersion
//
v1alpha1_storage_version_t*
InternalApiserverV1alpha1API_patchStorageVersion(apiClient_t *apiClient, char *name, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// partially update status of the specified StorageVersion
//
v1alpha1_storage_version_t*
InternalApiserverV1alpha1API_patchStorageVersionStatus(apiClient_t *apiClient, char *name, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// read the specified StorageVersion
//
v1alpha1_storage_version_t*
InternalApiserverV1alpha1API_readStorageVersion(apiClient_t *apiClient, char *name, char *pretty);


// read status of the specified StorageVersion
//
v1alpha1_storage_version_t*
InternalApiserverV1alpha1API_readStorageVersionStatus(apiClient_t *apiClient, char *name, char *pretty);


// replace the specified StorageVersion
//
v1alpha1_storage_version_t*
InternalApiserverV1alpha1API_replaceStorageVersion(apiClient_t *apiClient, char *name, v1alpha1_storage_version_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// replace status of the specified StorageVersion
//
v1alpha1_storage_version_t*
InternalApiserverV1alpha1API_replaceStorageVersionStatus(apiClient_t *apiClient, char *name, v1alpha1_storage_version_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


