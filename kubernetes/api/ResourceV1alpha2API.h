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
#include "../model/v1alpha2_pod_scheduling_context.h"
#include "../model/v1alpha2_pod_scheduling_context_list.h"
#include "../model/v1alpha2_resource_claim.h"
#include "../model/v1alpha2_resource_claim_list.h"
#include "../model/v1alpha2_resource_claim_parameters.h"
#include "../model/v1alpha2_resource_claim_parameters_list.h"
#include "../model/v1alpha2_resource_claim_template.h"
#include "../model/v1alpha2_resource_claim_template_list.h"
#include "../model/v1alpha2_resource_class.h"
#include "../model/v1alpha2_resource_class_list.h"
#include "../model/v1alpha2_resource_class_parameters.h"
#include "../model/v1alpha2_resource_class_parameters_list.h"
#include "../model/v1alpha2_resource_slice.h"
#include "../model/v1alpha2_resource_slice_list.h"


// create a PodSchedulingContext
//
v1alpha2_pod_scheduling_context_t*
ResourceV1alpha2API_createNamespacedPodSchedulingContext(apiClient_t *apiClient, char *_namespace, v1alpha2_pod_scheduling_context_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// create a ResourceClaim
//
v1alpha2_resource_claim_t*
ResourceV1alpha2API_createNamespacedResourceClaim(apiClient_t *apiClient, char *_namespace, v1alpha2_resource_claim_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// create ResourceClaimParameters
//
v1alpha2_resource_claim_parameters_t*
ResourceV1alpha2API_createNamespacedResourceClaimParameters(apiClient_t *apiClient, char *_namespace, v1alpha2_resource_claim_parameters_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// create a ResourceClaimTemplate
//
v1alpha2_resource_claim_template_t*
ResourceV1alpha2API_createNamespacedResourceClaimTemplate(apiClient_t *apiClient, char *_namespace, v1alpha2_resource_claim_template_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// create ResourceClassParameters
//
v1alpha2_resource_class_parameters_t*
ResourceV1alpha2API_createNamespacedResourceClassParameters(apiClient_t *apiClient, char *_namespace, v1alpha2_resource_class_parameters_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// create a ResourceClass
//
v1alpha2_resource_class_t*
ResourceV1alpha2API_createResourceClass(apiClient_t *apiClient, v1alpha2_resource_class_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// create a ResourceSlice
//
v1alpha2_resource_slice_t*
ResourceV1alpha2API_createResourceSlice(apiClient_t *apiClient, v1alpha2_resource_slice_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// delete collection of PodSchedulingContext
//
v1_status_t*
ResourceV1alpha2API_deleteCollectionNamespacedPodSchedulingContext(apiClient_t *apiClient, char *_namespace, char *pretty, char *_continue, char *dryRun, char *fieldSelector, int *gracePeriodSeconds, char *labelSelector, int *limit, int *orphanDependents, char *propagationPolicy, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, v1_delete_options_t *body);


// delete collection of ResourceClaim
//
v1_status_t*
ResourceV1alpha2API_deleteCollectionNamespacedResourceClaim(apiClient_t *apiClient, char *_namespace, char *pretty, char *_continue, char *dryRun, char *fieldSelector, int *gracePeriodSeconds, char *labelSelector, int *limit, int *orphanDependents, char *propagationPolicy, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, v1_delete_options_t *body);


// delete collection of ResourceClaimParameters
//
v1_status_t*
ResourceV1alpha2API_deleteCollectionNamespacedResourceClaimParameters(apiClient_t *apiClient, char *_namespace, char *pretty, char *_continue, char *dryRun, char *fieldSelector, int *gracePeriodSeconds, char *labelSelector, int *limit, int *orphanDependents, char *propagationPolicy, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, v1_delete_options_t *body);


// delete collection of ResourceClaimTemplate
//
v1_status_t*
ResourceV1alpha2API_deleteCollectionNamespacedResourceClaimTemplate(apiClient_t *apiClient, char *_namespace, char *pretty, char *_continue, char *dryRun, char *fieldSelector, int *gracePeriodSeconds, char *labelSelector, int *limit, int *orphanDependents, char *propagationPolicy, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, v1_delete_options_t *body);


// delete collection of ResourceClassParameters
//
v1_status_t*
ResourceV1alpha2API_deleteCollectionNamespacedResourceClassParameters(apiClient_t *apiClient, char *_namespace, char *pretty, char *_continue, char *dryRun, char *fieldSelector, int *gracePeriodSeconds, char *labelSelector, int *limit, int *orphanDependents, char *propagationPolicy, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, v1_delete_options_t *body);


// delete collection of ResourceClass
//
v1_status_t*
ResourceV1alpha2API_deleteCollectionResourceClass(apiClient_t *apiClient, char *pretty, char *_continue, char *dryRun, char *fieldSelector, int *gracePeriodSeconds, char *labelSelector, int *limit, int *orphanDependents, char *propagationPolicy, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, v1_delete_options_t *body);


// delete collection of ResourceSlice
//
v1_status_t*
ResourceV1alpha2API_deleteCollectionResourceSlice(apiClient_t *apiClient, char *pretty, char *_continue, char *dryRun, char *fieldSelector, int *gracePeriodSeconds, char *labelSelector, int *limit, int *orphanDependents, char *propagationPolicy, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, v1_delete_options_t *body);


// delete a PodSchedulingContext
//
v1alpha2_pod_scheduling_context_t*
ResourceV1alpha2API_deleteNamespacedPodSchedulingContext(apiClient_t *apiClient, char *name, char *_namespace, char *pretty, char *dryRun, int *gracePeriodSeconds, int *orphanDependents, char *propagationPolicy, v1_delete_options_t *body);


// delete a ResourceClaim
//
v1alpha2_resource_claim_t*
ResourceV1alpha2API_deleteNamespacedResourceClaim(apiClient_t *apiClient, char *name, char *_namespace, char *pretty, char *dryRun, int *gracePeriodSeconds, int *orphanDependents, char *propagationPolicy, v1_delete_options_t *body);


// delete ResourceClaimParameters
//
v1alpha2_resource_claim_parameters_t*
ResourceV1alpha2API_deleteNamespacedResourceClaimParameters(apiClient_t *apiClient, char *name, char *_namespace, char *pretty, char *dryRun, int *gracePeriodSeconds, int *orphanDependents, char *propagationPolicy, v1_delete_options_t *body);


// delete a ResourceClaimTemplate
//
v1alpha2_resource_claim_template_t*
ResourceV1alpha2API_deleteNamespacedResourceClaimTemplate(apiClient_t *apiClient, char *name, char *_namespace, char *pretty, char *dryRun, int *gracePeriodSeconds, int *orphanDependents, char *propagationPolicy, v1_delete_options_t *body);


// delete ResourceClassParameters
//
v1alpha2_resource_class_parameters_t*
ResourceV1alpha2API_deleteNamespacedResourceClassParameters(apiClient_t *apiClient, char *name, char *_namespace, char *pretty, char *dryRun, int *gracePeriodSeconds, int *orphanDependents, char *propagationPolicy, v1_delete_options_t *body);


// delete a ResourceClass
//
v1alpha2_resource_class_t*
ResourceV1alpha2API_deleteResourceClass(apiClient_t *apiClient, char *name, char *pretty, char *dryRun, int *gracePeriodSeconds, int *orphanDependents, char *propagationPolicy, v1_delete_options_t *body);


// delete a ResourceSlice
//
v1alpha2_resource_slice_t*
ResourceV1alpha2API_deleteResourceSlice(apiClient_t *apiClient, char *name, char *pretty, char *dryRun, int *gracePeriodSeconds, int *orphanDependents, char *propagationPolicy, v1_delete_options_t *body);


// get available resources
//
v1_api_resource_list_t*
ResourceV1alpha2API_getAPIResources(apiClient_t *apiClient);


// list or watch objects of kind PodSchedulingContext
//
v1alpha2_pod_scheduling_context_list_t*
ResourceV1alpha2API_listNamespacedPodSchedulingContext(apiClient_t *apiClient, char *_namespace, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// list or watch objects of kind ResourceClaim
//
v1alpha2_resource_claim_list_t*
ResourceV1alpha2API_listNamespacedResourceClaim(apiClient_t *apiClient, char *_namespace, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// list or watch objects of kind ResourceClaimParameters
//
v1alpha2_resource_claim_parameters_list_t*
ResourceV1alpha2API_listNamespacedResourceClaimParameters(apiClient_t *apiClient, char *_namespace, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// list or watch objects of kind ResourceClaimTemplate
//
v1alpha2_resource_claim_template_list_t*
ResourceV1alpha2API_listNamespacedResourceClaimTemplate(apiClient_t *apiClient, char *_namespace, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// list or watch objects of kind ResourceClassParameters
//
v1alpha2_resource_class_parameters_list_t*
ResourceV1alpha2API_listNamespacedResourceClassParameters(apiClient_t *apiClient, char *_namespace, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// list or watch objects of kind PodSchedulingContext
//
v1alpha2_pod_scheduling_context_list_t*
ResourceV1alpha2API_listPodSchedulingContextForAllNamespaces(apiClient_t *apiClient, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *pretty, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// list or watch objects of kind ResourceClaim
//
v1alpha2_resource_claim_list_t*
ResourceV1alpha2API_listResourceClaimForAllNamespaces(apiClient_t *apiClient, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *pretty, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// list or watch objects of kind ResourceClaimParameters
//
v1alpha2_resource_claim_parameters_list_t*
ResourceV1alpha2API_listResourceClaimParametersForAllNamespaces(apiClient_t *apiClient, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *pretty, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// list or watch objects of kind ResourceClaimTemplate
//
v1alpha2_resource_claim_template_list_t*
ResourceV1alpha2API_listResourceClaimTemplateForAllNamespaces(apiClient_t *apiClient, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *pretty, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// list or watch objects of kind ResourceClass
//
v1alpha2_resource_class_list_t*
ResourceV1alpha2API_listResourceClass(apiClient_t *apiClient, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// list or watch objects of kind ResourceClassParameters
//
v1alpha2_resource_class_parameters_list_t*
ResourceV1alpha2API_listResourceClassParametersForAllNamespaces(apiClient_t *apiClient, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *pretty, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// list or watch objects of kind ResourceSlice
//
v1alpha2_resource_slice_list_t*
ResourceV1alpha2API_listResourceSlice(apiClient_t *apiClient, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// partially update the specified PodSchedulingContext
//
v1alpha2_pod_scheduling_context_t*
ResourceV1alpha2API_patchNamespacedPodSchedulingContext(apiClient_t *apiClient, char *name, char *_namespace, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// partially update status of the specified PodSchedulingContext
//
v1alpha2_pod_scheduling_context_t*
ResourceV1alpha2API_patchNamespacedPodSchedulingContextStatus(apiClient_t *apiClient, char *name, char *_namespace, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// partially update the specified ResourceClaim
//
v1alpha2_resource_claim_t*
ResourceV1alpha2API_patchNamespacedResourceClaim(apiClient_t *apiClient, char *name, char *_namespace, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// partially update the specified ResourceClaimParameters
//
v1alpha2_resource_claim_parameters_t*
ResourceV1alpha2API_patchNamespacedResourceClaimParameters(apiClient_t *apiClient, char *name, char *_namespace, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// partially update status of the specified ResourceClaim
//
v1alpha2_resource_claim_t*
ResourceV1alpha2API_patchNamespacedResourceClaimStatus(apiClient_t *apiClient, char *name, char *_namespace, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// partially update the specified ResourceClaimTemplate
//
v1alpha2_resource_claim_template_t*
ResourceV1alpha2API_patchNamespacedResourceClaimTemplate(apiClient_t *apiClient, char *name, char *_namespace, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// partially update the specified ResourceClassParameters
//
v1alpha2_resource_class_parameters_t*
ResourceV1alpha2API_patchNamespacedResourceClassParameters(apiClient_t *apiClient, char *name, char *_namespace, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// partially update the specified ResourceClass
//
v1alpha2_resource_class_t*
ResourceV1alpha2API_patchResourceClass(apiClient_t *apiClient, char *name, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// partially update the specified ResourceSlice
//
v1alpha2_resource_slice_t*
ResourceV1alpha2API_patchResourceSlice(apiClient_t *apiClient, char *name, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// read the specified PodSchedulingContext
//
v1alpha2_pod_scheduling_context_t*
ResourceV1alpha2API_readNamespacedPodSchedulingContext(apiClient_t *apiClient, char *name, char *_namespace, char *pretty);


// read status of the specified PodSchedulingContext
//
v1alpha2_pod_scheduling_context_t*
ResourceV1alpha2API_readNamespacedPodSchedulingContextStatus(apiClient_t *apiClient, char *name, char *_namespace, char *pretty);


// read the specified ResourceClaim
//
v1alpha2_resource_claim_t*
ResourceV1alpha2API_readNamespacedResourceClaim(apiClient_t *apiClient, char *name, char *_namespace, char *pretty);


// read the specified ResourceClaimParameters
//
v1alpha2_resource_claim_parameters_t*
ResourceV1alpha2API_readNamespacedResourceClaimParameters(apiClient_t *apiClient, char *name, char *_namespace, char *pretty);


// read status of the specified ResourceClaim
//
v1alpha2_resource_claim_t*
ResourceV1alpha2API_readNamespacedResourceClaimStatus(apiClient_t *apiClient, char *name, char *_namespace, char *pretty);


// read the specified ResourceClaimTemplate
//
v1alpha2_resource_claim_template_t*
ResourceV1alpha2API_readNamespacedResourceClaimTemplate(apiClient_t *apiClient, char *name, char *_namespace, char *pretty);


// read the specified ResourceClassParameters
//
v1alpha2_resource_class_parameters_t*
ResourceV1alpha2API_readNamespacedResourceClassParameters(apiClient_t *apiClient, char *name, char *_namespace, char *pretty);


// read the specified ResourceClass
//
v1alpha2_resource_class_t*
ResourceV1alpha2API_readResourceClass(apiClient_t *apiClient, char *name, char *pretty);


// read the specified ResourceSlice
//
v1alpha2_resource_slice_t*
ResourceV1alpha2API_readResourceSlice(apiClient_t *apiClient, char *name, char *pretty);


// replace the specified PodSchedulingContext
//
v1alpha2_pod_scheduling_context_t*
ResourceV1alpha2API_replaceNamespacedPodSchedulingContext(apiClient_t *apiClient, char *name, char *_namespace, v1alpha2_pod_scheduling_context_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// replace status of the specified PodSchedulingContext
//
v1alpha2_pod_scheduling_context_t*
ResourceV1alpha2API_replaceNamespacedPodSchedulingContextStatus(apiClient_t *apiClient, char *name, char *_namespace, v1alpha2_pod_scheduling_context_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// replace the specified ResourceClaim
//
v1alpha2_resource_claim_t*
ResourceV1alpha2API_replaceNamespacedResourceClaim(apiClient_t *apiClient, char *name, char *_namespace, v1alpha2_resource_claim_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// replace the specified ResourceClaimParameters
//
v1alpha2_resource_claim_parameters_t*
ResourceV1alpha2API_replaceNamespacedResourceClaimParameters(apiClient_t *apiClient, char *name, char *_namespace, v1alpha2_resource_claim_parameters_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// replace status of the specified ResourceClaim
//
v1alpha2_resource_claim_t*
ResourceV1alpha2API_replaceNamespacedResourceClaimStatus(apiClient_t *apiClient, char *name, char *_namespace, v1alpha2_resource_claim_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// replace the specified ResourceClaimTemplate
//
v1alpha2_resource_claim_template_t*
ResourceV1alpha2API_replaceNamespacedResourceClaimTemplate(apiClient_t *apiClient, char *name, char *_namespace, v1alpha2_resource_claim_template_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// replace the specified ResourceClassParameters
//
v1alpha2_resource_class_parameters_t*
ResourceV1alpha2API_replaceNamespacedResourceClassParameters(apiClient_t *apiClient, char *name, char *_namespace, v1alpha2_resource_class_parameters_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// replace the specified ResourceClass
//
v1alpha2_resource_class_t*
ResourceV1alpha2API_replaceResourceClass(apiClient_t *apiClient, char *name, v1alpha2_resource_class_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// replace the specified ResourceSlice
//
v1alpha2_resource_slice_t*
ResourceV1alpha2API_replaceResourceSlice(apiClient_t *apiClient, char *name, v1alpha2_resource_slice_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


