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
#include "../model/v1beta1_pod_group.h"
#include "../model/v1beta1_pod_group_list.h"
#include "../model/v1beta1_workload.h"
#include "../model/v1beta1_workload_list.h"


// create a PodGroup
//
v1beta1_pod_group_t*
SchedulingV1beta1API_createNamespacedPodGroup(apiClient_t *apiClient, char *_namespace, v1beta1_pod_group_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// create a Workload
//
v1beta1_workload_t*
SchedulingV1beta1API_createNamespacedWorkload(apiClient_t *apiClient, char *_namespace, v1beta1_workload_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// delete collection of PodGroup
//
v1_status_t*
SchedulingV1beta1API_deleteCollectionNamespacedPodGroup(apiClient_t *apiClient, char *_namespace, char *pretty, char *_continue, char *dryRun, char *fieldSelector, int *gracePeriodSeconds, int *ignoreStoreReadErrorWithClusterBreakingPotential, char *labelSelector, int *limit, int *orphanDependents, char *propagationPolicy, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, char *shardSelector, int *timeoutSeconds, v1_delete_options_t *body);


// delete collection of Workload
//
v1_status_t*
SchedulingV1beta1API_deleteCollectionNamespacedWorkload(apiClient_t *apiClient, char *_namespace, char *pretty, char *_continue, char *dryRun, char *fieldSelector, int *gracePeriodSeconds, int *ignoreStoreReadErrorWithClusterBreakingPotential, char *labelSelector, int *limit, int *orphanDependents, char *propagationPolicy, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, char *shardSelector, int *timeoutSeconds, v1_delete_options_t *body);


// delete a PodGroup
//
v1_status_t*
SchedulingV1beta1API_deleteNamespacedPodGroup(apiClient_t *apiClient, char *name, char *_namespace, char *pretty, char *dryRun, int *gracePeriodSeconds, int *ignoreStoreReadErrorWithClusterBreakingPotential, int *orphanDependents, char *propagationPolicy, v1_delete_options_t *body);


// delete a Workload
//
v1_status_t*
SchedulingV1beta1API_deleteNamespacedWorkload(apiClient_t *apiClient, char *name, char *_namespace, char *pretty, char *dryRun, int *gracePeriodSeconds, int *ignoreStoreReadErrorWithClusterBreakingPotential, int *orphanDependents, char *propagationPolicy, v1_delete_options_t *body);


// get available resources
//
v1_api_resource_list_t*
SchedulingV1beta1API_getAPIResources(apiClient_t *apiClient);


// list or watch objects of kind PodGroup
//
v1beta1_pod_group_list_t*
SchedulingV1beta1API_listNamespacedPodGroup(apiClient_t *apiClient, char *_namespace, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, char *shardSelector, int *timeoutSeconds, int *watch);


// list or watch objects of kind Workload
//
v1beta1_workload_list_t*
SchedulingV1beta1API_listNamespacedWorkload(apiClient_t *apiClient, char *_namespace, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, char *shardSelector, int *timeoutSeconds, int *watch);


// list or watch objects of kind PodGroup
//
v1beta1_pod_group_list_t*
SchedulingV1beta1API_listPodGroupForAllNamespaces(apiClient_t *apiClient, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *pretty, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, char *shardSelector, int *timeoutSeconds, int *watch);


// list or watch objects of kind Workload
//
v1beta1_workload_list_t*
SchedulingV1beta1API_listWorkloadForAllNamespaces(apiClient_t *apiClient, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *pretty, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, char *shardSelector, int *timeoutSeconds, int *watch);


// partially update the specified PodGroup
//
v1beta1_pod_group_t*
SchedulingV1beta1API_patchNamespacedPodGroup(apiClient_t *apiClient, char *name, char *_namespace, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// partially update status of the specified PodGroup
//
v1beta1_pod_group_t*
SchedulingV1beta1API_patchNamespacedPodGroupStatus(apiClient_t *apiClient, char *name, char *_namespace, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// partially update the specified Workload
//
v1beta1_workload_t*
SchedulingV1beta1API_patchNamespacedWorkload(apiClient_t *apiClient, char *name, char *_namespace, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// read the specified PodGroup
//
v1beta1_pod_group_t*
SchedulingV1beta1API_readNamespacedPodGroup(apiClient_t *apiClient, char *name, char *_namespace, char *pretty);


// read status of the specified PodGroup
//
v1beta1_pod_group_t*
SchedulingV1beta1API_readNamespacedPodGroupStatus(apiClient_t *apiClient, char *name, char *_namespace, char *pretty);


// read the specified Workload
//
v1beta1_workload_t*
SchedulingV1beta1API_readNamespacedWorkload(apiClient_t *apiClient, char *name, char *_namespace, char *pretty);


// replace the specified PodGroup
//
v1beta1_pod_group_t*
SchedulingV1beta1API_replaceNamespacedPodGroup(apiClient_t *apiClient, char *name, char *_namespace, v1beta1_pod_group_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// replace status of the specified PodGroup
//
v1beta1_pod_group_t*
SchedulingV1beta1API_replaceNamespacedPodGroupStatus(apiClient_t *apiClient, char *name, char *_namespace, v1beta1_pod_group_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// replace the specified Workload
//
v1beta1_workload_t*
SchedulingV1beta1API_replaceNamespacedWorkload(apiClient_t *apiClient, char *name, char *_namespace, v1beta1_workload_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


