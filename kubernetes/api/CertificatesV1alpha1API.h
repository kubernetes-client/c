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
#include "../model/v1alpha1_cluster_trust_bundle.h"
#include "../model/v1alpha1_cluster_trust_bundle_list.h"


// create a ClusterTrustBundle
//
v1alpha1_cluster_trust_bundle_t*
CertificatesV1alpha1API_createClusterTrustBundle(apiClient_t *apiClient, v1alpha1_cluster_trust_bundle_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// delete a ClusterTrustBundle
//
v1_status_t*
CertificatesV1alpha1API_deleteClusterTrustBundle(apiClient_t *apiClient, char *name, char *pretty, char *dryRun, int *gracePeriodSeconds, int *orphanDependents, char *propagationPolicy, v1_delete_options_t *body);


// delete collection of ClusterTrustBundle
//
v1_status_t*
CertificatesV1alpha1API_deleteCollectionClusterTrustBundle(apiClient_t *apiClient, char *pretty, char *_continue, char *dryRun, char *fieldSelector, int *gracePeriodSeconds, char *labelSelector, int *limit, int *orphanDependents, char *propagationPolicy, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, v1_delete_options_t *body);


// get available resources
//
v1_api_resource_list_t*
CertificatesV1alpha1API_getAPIResources_14(apiClient_t *apiClient);


// list or watch objects of kind ClusterTrustBundle
//
v1alpha1_cluster_trust_bundle_list_t*
CertificatesV1alpha1API_listClusterTrustBundle(apiClient_t *apiClient, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// partially update the specified ClusterTrustBundle
//
v1alpha1_cluster_trust_bundle_t*
CertificatesV1alpha1API_patchClusterTrustBundle(apiClient_t *apiClient, char *name, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// read the specified ClusterTrustBundle
//
v1alpha1_cluster_trust_bundle_t*
CertificatesV1alpha1API_readClusterTrustBundle(apiClient_t *apiClient, char *name, char *pretty);


// replace the specified ClusterTrustBundle
//
v1alpha1_cluster_trust_bundle_t*
CertificatesV1alpha1API_replaceClusterTrustBundle(apiClient_t *apiClient, char *name, v1alpha1_cluster_trust_bundle_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


