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
#include "../model/v1alpha1_storage_version_migration.h"
#include "../model/v1alpha1_storage_version_migration_list.h"


// create a StorageVersionMigration
//
v1alpha1_storage_version_migration_t*
StoragemigrationV1alpha1API_createStorageVersionMigration(apiClient_t *apiClient, v1alpha1_storage_version_migration_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// delete collection of StorageVersionMigration
//
v1_status_t*
StoragemigrationV1alpha1API_deleteCollectionStorageVersionMigration(apiClient_t *apiClient, char *pretty, char *_continue, char *dryRun, char *fieldSelector, int *gracePeriodSeconds, int *ignoreStoreReadErrorWithClusterBreakingPotential, char *labelSelector, int *limit, int *orphanDependents, char *propagationPolicy, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, v1_delete_options_t *body);


// delete a StorageVersionMigration
//
v1_status_t*
StoragemigrationV1alpha1API_deleteStorageVersionMigration(apiClient_t *apiClient, char *name, char *pretty, char *dryRun, int *gracePeriodSeconds, int *ignoreStoreReadErrorWithClusterBreakingPotential, int *orphanDependents, char *propagationPolicy, v1_delete_options_t *body);


// get available resources
//
v1_api_resource_list_t*
StoragemigrationV1alpha1API_getAPIResources(apiClient_t *apiClient);


// list or watch objects of kind StorageVersionMigration
//
v1alpha1_storage_version_migration_list_t*
StoragemigrationV1alpha1API_listStorageVersionMigration(apiClient_t *apiClient, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// partially update the specified StorageVersionMigration
//
v1alpha1_storage_version_migration_t*
StoragemigrationV1alpha1API_patchStorageVersionMigration(apiClient_t *apiClient, char *name, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// partially update status of the specified StorageVersionMigration
//
v1alpha1_storage_version_migration_t*
StoragemigrationV1alpha1API_patchStorageVersionMigrationStatus(apiClient_t *apiClient, char *name, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// read the specified StorageVersionMigration
//
v1alpha1_storage_version_migration_t*
StoragemigrationV1alpha1API_readStorageVersionMigration(apiClient_t *apiClient, char *name, char *pretty);


// read status of the specified StorageVersionMigration
//
v1alpha1_storage_version_migration_t*
StoragemigrationV1alpha1API_readStorageVersionMigrationStatus(apiClient_t *apiClient, char *name, char *pretty);


// replace the specified StorageVersionMigration
//
v1alpha1_storage_version_migration_t*
StoragemigrationV1alpha1API_replaceStorageVersionMigration(apiClient_t *apiClient, char *name, v1alpha1_storage_version_migration_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// replace status of the specified StorageVersionMigration
//
v1alpha1_storage_version_migration_t*
StoragemigrationV1alpha1API_replaceStorageVersionMigrationStatus(apiClient_t *apiClient, char *name, v1alpha1_storage_version_migration_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


