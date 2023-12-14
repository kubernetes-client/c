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
#include "../model/v2_horizontal_pod_autoscaler.h"
#include "../model/v2_horizontal_pod_autoscaler_list.h"


// create a HorizontalPodAutoscaler
//
v2_horizontal_pod_autoscaler_t*
AutoscalingV2API_createNamespacedHorizontalPodAutoscaler(apiClient_t *apiClient, char *_namespace, v2_horizontal_pod_autoscaler_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// delete collection of HorizontalPodAutoscaler
//
v1_status_t*
AutoscalingV2API_deleteCollectionNamespacedHorizontalPodAutoscaler(apiClient_t *apiClient, char *_namespace, char *pretty, char *_continue, char *dryRun, char *fieldSelector, int *gracePeriodSeconds, char *labelSelector, int *limit, int *orphanDependents, char *propagationPolicy, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, v1_delete_options_t *body);


// delete a HorizontalPodAutoscaler
//
v1_status_t*
AutoscalingV2API_deleteNamespacedHorizontalPodAutoscaler(apiClient_t *apiClient, char *name, char *_namespace, char *pretty, char *dryRun, int *gracePeriodSeconds, int *orphanDependents, char *propagationPolicy, v1_delete_options_t *body);


// get available resources
//
v1_api_resource_list_t*
AutoscalingV2API_getAPIResources(apiClient_t *apiClient);


// list or watch objects of kind HorizontalPodAutoscaler
//
v2_horizontal_pod_autoscaler_list_t*
AutoscalingV2API_listHorizontalPodAutoscalerForAllNamespaces(apiClient_t *apiClient, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *pretty, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// list or watch objects of kind HorizontalPodAutoscaler
//
v2_horizontal_pod_autoscaler_list_t*
AutoscalingV2API_listNamespacedHorizontalPodAutoscaler(apiClient_t *apiClient, char *_namespace, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// partially update the specified HorizontalPodAutoscaler
//
v2_horizontal_pod_autoscaler_t*
AutoscalingV2API_patchNamespacedHorizontalPodAutoscaler(apiClient_t *apiClient, char *name, char *_namespace, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// partially update status of the specified HorizontalPodAutoscaler
//
v2_horizontal_pod_autoscaler_t*
AutoscalingV2API_patchNamespacedHorizontalPodAutoscalerStatus(apiClient_t *apiClient, char *name, char *_namespace, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// read the specified HorizontalPodAutoscaler
//
v2_horizontal_pod_autoscaler_t*
AutoscalingV2API_readNamespacedHorizontalPodAutoscaler(apiClient_t *apiClient, char *name, char *_namespace, char *pretty);


// read status of the specified HorizontalPodAutoscaler
//
v2_horizontal_pod_autoscaler_t*
AutoscalingV2API_readNamespacedHorizontalPodAutoscalerStatus(apiClient_t *apiClient, char *name, char *_namespace, char *pretty);


// replace the specified HorizontalPodAutoscaler
//
v2_horizontal_pod_autoscaler_t*
AutoscalingV2API_replaceNamespacedHorizontalPodAutoscaler(apiClient_t *apiClient, char *name, char *_namespace, v2_horizontal_pod_autoscaler_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// replace status of the specified HorizontalPodAutoscaler
//
v2_horizontal_pod_autoscaler_t*
AutoscalingV2API_replaceNamespacedHorizontalPodAutoscalerStatus(apiClient_t *apiClient, char *name, char *_namespace, v2_horizontal_pod_autoscaler_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


