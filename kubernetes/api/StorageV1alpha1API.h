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
#include "../model/v1alpha1_volume_attributes_class.h"
#include "../model/v1alpha1_volume_attributes_class_list.h"


// create a VolumeAttributesClass
//
v1alpha1_volume_attributes_class_t*
StorageV1alpha1API_createVolumeAttributesClass(apiClient_t *apiClient, v1alpha1_volume_attributes_class_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// delete collection of VolumeAttributesClass
//
v1_status_t*
StorageV1alpha1API_deleteCollectionVolumeAttributesClass(apiClient_t *apiClient, char *pretty, char *_continue, char *dryRun, char *fieldSelector, int *gracePeriodSeconds, int *ignoreStoreReadErrorWithClusterBreakingPotential, char *labelSelector, int *limit, int *orphanDependents, char *propagationPolicy, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, v1_delete_options_t *body);


// delete a VolumeAttributesClass
//
v1alpha1_volume_attributes_class_t*
StorageV1alpha1API_deleteVolumeAttributesClass(apiClient_t *apiClient, char *name, char *pretty, char *dryRun, int *gracePeriodSeconds, int *ignoreStoreReadErrorWithClusterBreakingPotential, int *orphanDependents, char *propagationPolicy, v1_delete_options_t *body);


// get available resources
//
v1_api_resource_list_t*
StorageV1alpha1API_getAPIResources(apiClient_t *apiClient);


// list or watch objects of kind VolumeAttributesClass
//
v1alpha1_volume_attributes_class_list_t*
StorageV1alpha1API_listVolumeAttributesClass(apiClient_t *apiClient, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// partially update the specified VolumeAttributesClass
//
v1alpha1_volume_attributes_class_t*
StorageV1alpha1API_patchVolumeAttributesClass(apiClient_t *apiClient, char *name, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// read the specified VolumeAttributesClass
//
v1alpha1_volume_attributes_class_t*
StorageV1alpha1API_readVolumeAttributesClass(apiClient_t *apiClient, char *name, char *pretty);


// replace the specified VolumeAttributesClass
//
v1alpha1_volume_attributes_class_t*
StorageV1alpha1API_replaceVolumeAttributesClass(apiClient_t *apiClient, char *name, v1alpha1_volume_attributes_class_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


