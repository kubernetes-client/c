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
#include "../model/v1alpha3_device_taint_rule.h"
#include "../model/v1alpha3_device_taint_rule_list.h"


// create a DeviceTaintRule
//
v1alpha3_device_taint_rule_t*
ResourceV1alpha3API_createDeviceTaintRule(apiClient_t *apiClient, v1alpha3_device_taint_rule_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// delete collection of DeviceTaintRule
//
v1_status_t*
ResourceV1alpha3API_deleteCollectionDeviceTaintRule(apiClient_t *apiClient, char *pretty, char *_continue, char *dryRun, char *fieldSelector, int *gracePeriodSeconds, int *ignoreStoreReadErrorWithClusterBreakingPotential, char *labelSelector, int *limit, int *orphanDependents, char *propagationPolicy, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, v1_delete_options_t *body);


// delete a DeviceTaintRule
//
v1alpha3_device_taint_rule_t*
ResourceV1alpha3API_deleteDeviceTaintRule(apiClient_t *apiClient, char *name, char *pretty, char *dryRun, int *gracePeriodSeconds, int *ignoreStoreReadErrorWithClusterBreakingPotential, int *orphanDependents, char *propagationPolicy, v1_delete_options_t *body);


// get available resources
//
v1_api_resource_list_t*
ResourceV1alpha3API_getAPIResources(apiClient_t *apiClient);


// list or watch objects of kind DeviceTaintRule
//
v1alpha3_device_taint_rule_list_t*
ResourceV1alpha3API_listDeviceTaintRule(apiClient_t *apiClient, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *sendInitialEvents, int *timeoutSeconds, int *watch);


// partially update the specified DeviceTaintRule
//
v1alpha3_device_taint_rule_t*
ResourceV1alpha3API_patchDeviceTaintRule(apiClient_t *apiClient, char *name, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// read the specified DeviceTaintRule
//
v1alpha3_device_taint_rule_t*
ResourceV1alpha3API_readDeviceTaintRule(apiClient_t *apiClient, char *name, char *pretty);


// replace the specified DeviceTaintRule
//
v1alpha3_device_taint_rule_t*
ResourceV1alpha3API_replaceDeviceTaintRule(apiClient_t *apiClient, char *name, v1alpha3_device_taint_rule_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


