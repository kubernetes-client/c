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
#include "../model/v1beta1_validating_admission_policy.h"
#include "../model/v1beta1_validating_admission_policy_binding.h"
#include "../model/v1beta1_validating_admission_policy_binding_list.h"
#include "../model/v1beta1_validating_admission_policy_list.h"


// create a ValidatingAdmissionPolicyBinding
//
v1beta1_validating_admission_policy_binding_t*
AdmissionregistrationV1beta1API_createValidatingAdmissionPolicyBinding_1(apiClient_t *apiClient, v1beta1_validating_admission_policy_binding_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// create a ValidatingAdmissionPolicy
//
v1beta1_validating_admission_policy_t*
AdmissionregistrationV1beta1API_createValidatingAdmissionPolicy_1(apiClient_t *apiClient, v1beta1_validating_admission_policy_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// delete collection of ValidatingAdmissionPolicyBinding
//
v1_status_t*
AdmissionregistrationV1beta1API_deleteCollectionValidatingAdmissionPolicyBinding_1(apiClient_t *apiClient, char *pretty, char *_continue, char *dryRun, char *fieldSelector, int *gracePeriodSeconds, char *labelSelector, int *limit, int *orphanDependents, char *propagationPolicy, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, v1_delete_options_t *body);


// delete collection of ValidatingAdmissionPolicy
//
v1_status_t*
AdmissionregistrationV1beta1API_deleteCollectionValidatingAdmissionPolicy_1(apiClient_t *apiClient, char *pretty, char *_continue, char *dryRun, char *fieldSelector, int *gracePeriodSeconds, char *labelSelector, int *limit, int *orphanDependents, char *propagationPolicy, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, v1_delete_options_t *body);


// delete a ValidatingAdmissionPolicyBinding
//
v1_status_t*
AdmissionregistrationV1beta1API_deleteValidatingAdmissionPolicyBinding_1(apiClient_t *apiClient, char *name, char *pretty, char *dryRun, int *gracePeriodSeconds, int *orphanDependents, char *propagationPolicy, v1_delete_options_t *body);


// delete a ValidatingAdmissionPolicy
//
v1_status_t*
AdmissionregistrationV1beta1API_deleteValidatingAdmissionPolicy_1(apiClient_t *apiClient, char *name, char *pretty, char *dryRun, int *gracePeriodSeconds, int *orphanDependents, char *propagationPolicy, v1_delete_options_t *body);


// get available resources
//
v1_api_resource_list_t*
AdmissionregistrationV1beta1API_getAPIResources_2(apiClient_t *apiClient);


// list or watch objects of kind ValidatingAdmissionPolicyBinding
//
v1beta1_validating_admission_policy_binding_list_t*
AdmissionregistrationV1beta1API_listValidatingAdmissionPolicyBinding_1(apiClient_t *apiClient, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// list or watch objects of kind ValidatingAdmissionPolicy
//
v1beta1_validating_admission_policy_list_t*
AdmissionregistrationV1beta1API_listValidatingAdmissionPolicy_1(apiClient_t *apiClient, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// partially update the specified ValidatingAdmissionPolicyBinding
//
v1beta1_validating_admission_policy_binding_t*
AdmissionregistrationV1beta1API_patchValidatingAdmissionPolicyBinding_1(apiClient_t *apiClient, char *name, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// partially update status of the specified ValidatingAdmissionPolicy
//
v1beta1_validating_admission_policy_t*
AdmissionregistrationV1beta1API_patchValidatingAdmissionPolicyStatus_1(apiClient_t *apiClient, char *name, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// partially update the specified ValidatingAdmissionPolicy
//
v1beta1_validating_admission_policy_t*
AdmissionregistrationV1beta1API_patchValidatingAdmissionPolicy_1(apiClient_t *apiClient, char *name, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// read the specified ValidatingAdmissionPolicyBinding
//
v1beta1_validating_admission_policy_binding_t*
AdmissionregistrationV1beta1API_readValidatingAdmissionPolicyBinding_1(apiClient_t *apiClient, char *name, char *pretty);


// read status of the specified ValidatingAdmissionPolicy
//
v1beta1_validating_admission_policy_t*
AdmissionregistrationV1beta1API_readValidatingAdmissionPolicyStatus_1(apiClient_t *apiClient, char *name, char *pretty);


// read the specified ValidatingAdmissionPolicy
//
v1beta1_validating_admission_policy_t*
AdmissionregistrationV1beta1API_readValidatingAdmissionPolicy_1(apiClient_t *apiClient, char *name, char *pretty);


// replace the specified ValidatingAdmissionPolicyBinding
//
v1beta1_validating_admission_policy_binding_t*
AdmissionregistrationV1beta1API_replaceValidatingAdmissionPolicyBinding_1(apiClient_t *apiClient, char *name, v1beta1_validating_admission_policy_binding_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// replace status of the specified ValidatingAdmissionPolicy
//
v1beta1_validating_admission_policy_t*
AdmissionregistrationV1beta1API_replaceValidatingAdmissionPolicyStatus_1(apiClient_t *apiClient, char *name, v1beta1_validating_admission_policy_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// replace the specified ValidatingAdmissionPolicy
//
v1beta1_validating_admission_policy_t*
AdmissionregistrationV1beta1API_replaceValidatingAdmissionPolicy_1(apiClient_t *apiClient, char *name, v1beta1_validating_admission_policy_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


