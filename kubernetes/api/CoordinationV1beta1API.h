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
#include "../model/v1beta1_lease_candidate.h"
#include "../model/v1beta1_lease_candidate_list.h"


// create a LeaseCandidate
//
v1beta1_lease_candidate_t*
CoordinationV1beta1API_createNamespacedLeaseCandidate(apiClient_t *apiClient, char *_namespace, v1beta1_lease_candidate_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// delete collection of LeaseCandidate
//
v1_status_t*
CoordinationV1beta1API_deleteCollectionNamespacedLeaseCandidate(apiClient_t *apiClient, char *_namespace, char *pretty, char *_continue, char *dryRun, char *fieldSelector, int *gracePeriodSeconds, int *ignoreStoreReadErrorWithClusterBreakingPotential, char *labelSelector, int *limit, int *orphanDependents, char *propagationPolicy, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, v1_delete_options_t *body);


// delete a LeaseCandidate
//
v1_status_t*
CoordinationV1beta1API_deleteNamespacedLeaseCandidate(apiClient_t *apiClient, char *name, char *_namespace, char *pretty, char *dryRun, int *gracePeriodSeconds, int *ignoreStoreReadErrorWithClusterBreakingPotential, int *orphanDependents, char *propagationPolicy, v1_delete_options_t *body);


// get available resources
//
v1_api_resource_list_t*
CoordinationV1beta1API_getAPIResources(apiClient_t *apiClient);


// list or watch objects of kind LeaseCandidate
//
v1beta1_lease_candidate_list_t*
CoordinationV1beta1API_listLeaseCandidateForAllNamespaces(apiClient_t *apiClient, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *pretty, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// list or watch objects of kind LeaseCandidate
//
v1beta1_lease_candidate_list_t*
CoordinationV1beta1API_listNamespacedLeaseCandidate(apiClient_t *apiClient, char *_namespace, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// partially update the specified LeaseCandidate
//
v1beta1_lease_candidate_t*
CoordinationV1beta1API_patchNamespacedLeaseCandidate(apiClient_t *apiClient, char *name, char *_namespace, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// read the specified LeaseCandidate
//
v1beta1_lease_candidate_t*
CoordinationV1beta1API_readNamespacedLeaseCandidate(apiClient_t *apiClient, char *name, char *_namespace, char *pretty);


// replace the specified LeaseCandidate
//
v1beta1_lease_candidate_t*
CoordinationV1beta1API_replaceNamespacedLeaseCandidate(apiClient_t *apiClient, char *name, char *_namespace, v1beta1_lease_candidate_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


