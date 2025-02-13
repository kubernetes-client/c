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
#include "../model/v1alpha1_mutating_admission_policy.h"
#include "../model/v1alpha1_mutating_admission_policy_binding.h"
#include "../model/v1alpha1_mutating_admission_policy_binding_list.h"
#include "../model/v1alpha1_mutating_admission_policy_list.h"


// create a MutatingAdmissionPolicy
//
v1alpha1_mutating_admission_policy_t*
AdmissionregistrationV1alpha1API_createMutatingAdmissionPolicy(apiClient_t *apiClient, v1alpha1_mutating_admission_policy_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// create a MutatingAdmissionPolicyBinding
//
v1alpha1_mutating_admission_policy_binding_t*
AdmissionregistrationV1alpha1API_createMutatingAdmissionPolicyBinding(apiClient_t *apiClient, v1alpha1_mutating_admission_policy_binding_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// delete collection of MutatingAdmissionPolicy
//
v1_status_t*
AdmissionregistrationV1alpha1API_deleteCollectionMutatingAdmissionPolicy(apiClient_t *apiClient, char *pretty, char *_continue, char *dryRun, char *fieldSelector, int *gracePeriodSeconds, int *ignoreStoreReadErrorWithClusterBreakingPotential, char *labelSelector, int *limit, int *orphanDependents, char *propagationPolicy, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, v1_delete_options_t *body);


// delete collection of MutatingAdmissionPolicyBinding
//
v1_status_t*
AdmissionregistrationV1alpha1API_deleteCollectionMutatingAdmissionPolicyBinding(apiClient_t *apiClient, char *pretty, char *_continue, char *dryRun, char *fieldSelector, int *gracePeriodSeconds, int *ignoreStoreReadErrorWithClusterBreakingPotential, char *labelSelector, int *limit, int *orphanDependents, char *propagationPolicy, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, v1_delete_options_t *body);


// delete a MutatingAdmissionPolicy
//
v1_status_t*
AdmissionregistrationV1alpha1API_deleteMutatingAdmissionPolicy(apiClient_t *apiClient, char *name, char *pretty, char *dryRun, int *gracePeriodSeconds, int *ignoreStoreReadErrorWithClusterBreakingPotential, int *orphanDependents, char *propagationPolicy, v1_delete_options_t *body);


// delete a MutatingAdmissionPolicyBinding
//
v1_status_t*
AdmissionregistrationV1alpha1API_deleteMutatingAdmissionPolicyBinding(apiClient_t *apiClient, char *name, char *pretty, char *dryRun, int *gracePeriodSeconds, int *ignoreStoreReadErrorWithClusterBreakingPotential, int *orphanDependents, char *propagationPolicy, v1_delete_options_t *body);


// get available resources
//
v1_api_resource_list_t*
AdmissionregistrationV1alpha1API_getAPIResources(apiClient_t *apiClient);


// list or watch objects of kind MutatingAdmissionPolicy
//
v1alpha1_mutating_admission_policy_list_t*
AdmissionregistrationV1alpha1API_listMutatingAdmissionPolicy(apiClient_t *apiClient, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// list or watch objects of kind MutatingAdmissionPolicyBinding
//
v1alpha1_mutating_admission_policy_binding_list_t*
AdmissionregistrationV1alpha1API_listMutatingAdmissionPolicyBinding(apiClient_t *apiClient, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// partially update the specified MutatingAdmissionPolicy
//
v1alpha1_mutating_admission_policy_t*
AdmissionregistrationV1alpha1API_patchMutatingAdmissionPolicy(apiClient_t *apiClient, char *name, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// partially update the specified MutatingAdmissionPolicyBinding
//
v1alpha1_mutating_admission_policy_binding_t*
AdmissionregistrationV1alpha1API_patchMutatingAdmissionPolicyBinding(apiClient_t *apiClient, char *name, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// read the specified MutatingAdmissionPolicy
//
v1alpha1_mutating_admission_policy_t*
AdmissionregistrationV1alpha1API_readMutatingAdmissionPolicy(apiClient_t *apiClient, char *name, char *pretty);


// read the specified MutatingAdmissionPolicyBinding
//
v1alpha1_mutating_admission_policy_binding_t*
AdmissionregistrationV1alpha1API_readMutatingAdmissionPolicyBinding(apiClient_t *apiClient, char *name, char *pretty);


// replace the specified MutatingAdmissionPolicy
//
v1alpha1_mutating_admission_policy_t*
AdmissionregistrationV1alpha1API_replaceMutatingAdmissionPolicy(apiClient_t *apiClient, char *name, v1alpha1_mutating_admission_policy_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// replace the specified MutatingAdmissionPolicyBinding
//
v1alpha1_mutating_admission_policy_binding_t*
AdmissionregistrationV1alpha1API_replaceMutatingAdmissionPolicyBinding(apiClient_t *apiClient, char *name, v1alpha1_mutating_admission_policy_binding_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


