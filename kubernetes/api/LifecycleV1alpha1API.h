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
#include "../model/v1alpha1_eviction.h"
#include "../model/v1alpha1_eviction_list.h"
#include "../model/v1alpha1_eviction_request.h"
#include "../model/v1alpha1_eviction_request_list.h"


// create an Eviction
//
v1alpha1_eviction_t*
LifecycleV1alpha1API_createNamespacedEviction(apiClient_t *apiClient, char *_namespace, v1alpha1_eviction_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// create an EvictionRequest
//
v1alpha1_eviction_request_t*
LifecycleV1alpha1API_createNamespacedEvictionRequest(apiClient_t *apiClient, char *_namespace, v1alpha1_eviction_request_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// delete collection of Eviction
//
v1_status_t*
LifecycleV1alpha1API_deleteCollectionNamespacedEviction(apiClient_t *apiClient, char *_namespace, char *pretty, char *_continue, char *dryRun, char *fieldSelector, int *gracePeriodSeconds, int *ignoreStoreReadErrorWithClusterBreakingPotential, char *labelSelector, int *limit, int *orphanDependents, char *propagationPolicy, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, char *shardSelector, int *timeoutSeconds, v1_delete_options_t *body);


// delete collection of EvictionRequest
//
v1_status_t*
LifecycleV1alpha1API_deleteCollectionNamespacedEvictionRequest(apiClient_t *apiClient, char *_namespace, char *pretty, char *_continue, char *dryRun, char *fieldSelector, int *gracePeriodSeconds, int *ignoreStoreReadErrorWithClusterBreakingPotential, char *labelSelector, int *limit, int *orphanDependents, char *propagationPolicy, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, char *shardSelector, int *timeoutSeconds, v1_delete_options_t *body);


// delete an Eviction
//
v1_status_t*
LifecycleV1alpha1API_deleteNamespacedEviction(apiClient_t *apiClient, char *name, char *_namespace, char *pretty, char *dryRun, int *gracePeriodSeconds, int *ignoreStoreReadErrorWithClusterBreakingPotential, int *orphanDependents, char *propagationPolicy, v1_delete_options_t *body);


// delete an EvictionRequest
//
v1_status_t*
LifecycleV1alpha1API_deleteNamespacedEvictionRequest(apiClient_t *apiClient, char *name, char *_namespace, char *pretty, char *dryRun, int *gracePeriodSeconds, int *ignoreStoreReadErrorWithClusterBreakingPotential, int *orphanDependents, char *propagationPolicy, v1_delete_options_t *body);


// get available resources
//
v1_api_resource_list_t*
LifecycleV1alpha1API_getAPIResources(apiClient_t *apiClient);


// list or watch objects of kind Eviction
//
v1alpha1_eviction_list_t*
LifecycleV1alpha1API_listEvictionForAllNamespaces(apiClient_t *apiClient, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *pretty, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, char *shardSelector, int *timeoutSeconds, int *watch);


// list or watch objects of kind EvictionRequest
//
v1alpha1_eviction_request_list_t*
LifecycleV1alpha1API_listEvictionRequestForAllNamespaces(apiClient_t *apiClient, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *pretty, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, char *shardSelector, int *timeoutSeconds, int *watch);


// list or watch objects of kind Eviction
//
v1alpha1_eviction_list_t*
LifecycleV1alpha1API_listNamespacedEviction(apiClient_t *apiClient, char *_namespace, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, char *shardSelector, int *timeoutSeconds, int *watch);


// list or watch objects of kind EvictionRequest
//
v1alpha1_eviction_request_list_t*
LifecycleV1alpha1API_listNamespacedEvictionRequest(apiClient_t *apiClient, char *_namespace, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, char *shardSelector, int *timeoutSeconds, int *watch);


// partially update the specified Eviction
//
v1alpha1_eviction_t*
LifecycleV1alpha1API_patchNamespacedEviction(apiClient_t *apiClient, char *name, char *_namespace, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// partially update the specified EvictionRequest
//
v1alpha1_eviction_request_t*
LifecycleV1alpha1API_patchNamespacedEvictionRequest(apiClient_t *apiClient, char *name, char *_namespace, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// partially update status of the specified EvictionRequest
//
v1alpha1_eviction_request_t*
LifecycleV1alpha1API_patchNamespacedEvictionRequestStatus(apiClient_t *apiClient, char *name, char *_namespace, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// partially update status of the specified Eviction
//
v1alpha1_eviction_t*
LifecycleV1alpha1API_patchNamespacedEvictionStatus(apiClient_t *apiClient, char *name, char *_namespace, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// read the specified Eviction
//
v1alpha1_eviction_t*
LifecycleV1alpha1API_readNamespacedEviction(apiClient_t *apiClient, char *name, char *_namespace, char *pretty);


// read the specified EvictionRequest
//
v1alpha1_eviction_request_t*
LifecycleV1alpha1API_readNamespacedEvictionRequest(apiClient_t *apiClient, char *name, char *_namespace, char *pretty);


// read status of the specified EvictionRequest
//
v1alpha1_eviction_request_t*
LifecycleV1alpha1API_readNamespacedEvictionRequestStatus(apiClient_t *apiClient, char *name, char *_namespace, char *pretty);


// read status of the specified Eviction
//
v1alpha1_eviction_t*
LifecycleV1alpha1API_readNamespacedEvictionStatus(apiClient_t *apiClient, char *name, char *_namespace, char *pretty);


// replace the specified Eviction
//
v1alpha1_eviction_t*
LifecycleV1alpha1API_replaceNamespacedEviction(apiClient_t *apiClient, char *name, char *_namespace, v1alpha1_eviction_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// replace the specified EvictionRequest
//
v1alpha1_eviction_request_t*
LifecycleV1alpha1API_replaceNamespacedEvictionRequest(apiClient_t *apiClient, char *name, char *_namespace, v1alpha1_eviction_request_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// replace status of the specified EvictionRequest
//
v1alpha1_eviction_request_t*
LifecycleV1alpha1API_replaceNamespacedEvictionRequestStatus(apiClient_t *apiClient, char *name, char *_namespace, v1alpha1_eviction_request_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// replace status of the specified Eviction
//
v1alpha1_eviction_t*
LifecycleV1alpha1API_replaceNamespacedEvictionStatus(apiClient_t *apiClient, char *name, char *_namespace, v1alpha1_eviction_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


