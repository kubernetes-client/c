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


// Creates a cluster scoped Custom object
//
object_t*
CustomObjectsAPI_createClusterCustomObject(apiClient_t *apiClient, char *group, char *version, char *plural, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// Creates a namespace scoped Custom object
//
object_t*
CustomObjectsAPI_createNamespacedCustomObject(apiClient_t *apiClient, char *group, char *version, char *_namespace, char *plural, object_t *body, char *pretty, char *dryRun, char *fieldManager, char *fieldValidation);


// Deletes the specified cluster scoped custom object
//
object_t*
CustomObjectsAPI_deleteClusterCustomObject(apiClient_t *apiClient, char *group, char *version, char *plural, char *name, int *gracePeriodSeconds, int *orphanDependents, char *propagationPolicy, char *dryRun, v1_delete_options_t *body);


// Delete collection of cluster scoped custom objects
//
object_t*
CustomObjectsAPI_deleteCollectionClusterCustomObject(apiClient_t *apiClient, char *group, char *version, char *plural, char *pretty, char *labelSelector, int *gracePeriodSeconds, int *orphanDependents, char *propagationPolicy, char *dryRun, v1_delete_options_t *body);


// Delete collection of namespace scoped custom objects
//
object_t*
CustomObjectsAPI_deleteCollectionNamespacedCustomObject(apiClient_t *apiClient, char *group, char *version, char *_namespace, char *plural, char *pretty, char *labelSelector, int *gracePeriodSeconds, int *orphanDependents, char *propagationPolicy, char *dryRun, char *fieldSelector, v1_delete_options_t *body);


// Deletes the specified namespace scoped custom object
//
object_t*
CustomObjectsAPI_deleteNamespacedCustomObject(apiClient_t *apiClient, char *group, char *version, char *_namespace, char *plural, char *name, int *gracePeriodSeconds, int *orphanDependents, char *propagationPolicy, char *dryRun, v1_delete_options_t *body);


// get available resources
//
v1_api_resource_list_t*
CustomObjectsAPI_getAPIResources(apiClient_t *apiClient, char *group, char *version);


// Returns a cluster scoped custom object
//
object_t*
CustomObjectsAPI_getClusterCustomObject(apiClient_t *apiClient, char *group, char *version, char *plural, char *name);


// read scale of the specified custom object
//
object_t*
CustomObjectsAPI_getClusterCustomObjectScale(apiClient_t *apiClient, char *group, char *version, char *plural, char *name);


// read status of the specified cluster scoped custom object
//
object_t*
CustomObjectsAPI_getClusterCustomObjectStatus(apiClient_t *apiClient, char *group, char *version, char *plural, char *name);


// Returns a namespace scoped custom object
//
object_t*
CustomObjectsAPI_getNamespacedCustomObject(apiClient_t *apiClient, char *group, char *version, char *_namespace, char *plural, char *name);


// read scale of the specified namespace scoped custom object
//
object_t*
CustomObjectsAPI_getNamespacedCustomObjectScale(apiClient_t *apiClient, char *group, char *version, char *_namespace, char *plural, char *name);


// read status of the specified namespace scoped custom object
//
object_t*
CustomObjectsAPI_getNamespacedCustomObjectStatus(apiClient_t *apiClient, char *group, char *version, char *_namespace, char *plural, char *name);


// list or watch cluster scoped custom objects
//
object_t*
CustomObjectsAPI_listClusterCustomObject(apiClient_t *apiClient, char *group, char *version, char *plural, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *timeoutSeconds, int *watch);


// list or watch namespace scoped custom objects
//
object_t*
CustomObjectsAPI_listCustomObjectForAllNamespaces(apiClient_t *apiClient, char *group, char *version, char *resource_plural, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *timeoutSeconds, int *watch);


// list or watch namespace scoped custom objects
//
object_t*
CustomObjectsAPI_listNamespacedCustomObject(apiClient_t *apiClient, char *group, char *version, char *_namespace, char *plural, char *pretty, int *allowWatchBookmarks, char *_continue, char *fieldSelector, char *labelSelector, int *limit, char *resourceVersion, char *resourceVersionMatch, int *timeoutSeconds, int *watch);


// patch the specified cluster scoped custom object
//
object_t*
CustomObjectsAPI_patchClusterCustomObject(apiClient_t *apiClient, char *group, char *version, char *plural, char *name, object_t *body, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// partially update scale of the specified cluster scoped custom object
//
object_t*
CustomObjectsAPI_patchClusterCustomObjectScale(apiClient_t *apiClient, char *group, char *version, char *plural, char *name, object_t *body, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// partially update status of the specified cluster scoped custom object
//
object_t*
CustomObjectsAPI_patchClusterCustomObjectStatus(apiClient_t *apiClient, char *group, char *version, char *plural, char *name, object_t *body, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// patch the specified namespace scoped custom object
//
object_t*
CustomObjectsAPI_patchNamespacedCustomObject(apiClient_t *apiClient, char *group, char *version, char *_namespace, char *plural, char *name, object_t *body, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// partially update scale of the specified namespace scoped custom object
//
object_t*
CustomObjectsAPI_patchNamespacedCustomObjectScale(apiClient_t *apiClient, char *group, char *version, char *_namespace, char *plural, char *name, object_t *body, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// partially update status of the specified namespace scoped custom object
//
object_t*
CustomObjectsAPI_patchNamespacedCustomObjectStatus(apiClient_t *apiClient, char *group, char *version, char *_namespace, char *plural, char *name, object_t *body, char *dryRun, char *fieldManager, char *fieldValidation, int *force);


// replace the specified cluster scoped custom object
//
object_t*
CustomObjectsAPI_replaceClusterCustomObject(apiClient_t *apiClient, char *group, char *version, char *plural, char *name, object_t *body, char *dryRun, char *fieldManager, char *fieldValidation);


// replace scale of the specified cluster scoped custom object
//
object_t*
CustomObjectsAPI_replaceClusterCustomObjectScale(apiClient_t *apiClient, char *group, char *version, char *plural, char *name, object_t *body, char *dryRun, char *fieldManager, char *fieldValidation);


// replace status of the cluster scoped specified custom object
//
object_t*
CustomObjectsAPI_replaceClusterCustomObjectStatus(apiClient_t *apiClient, char *group, char *version, char *plural, char *name, object_t *body, char *dryRun, char *fieldManager, char *fieldValidation);


// replace the specified namespace scoped custom object
//
object_t*
CustomObjectsAPI_replaceNamespacedCustomObject(apiClient_t *apiClient, char *group, char *version, char *_namespace, char *plural, char *name, object_t *body, char *dryRun, char *fieldManager, char *fieldValidation);


// replace scale of the specified namespace scoped custom object
//
object_t*
CustomObjectsAPI_replaceNamespacedCustomObjectScale(apiClient_t *apiClient, char *group, char *version, char *_namespace, char *plural, char *name, object_t *body, char *dryRun, char *fieldManager, char *fieldValidation);


// replace status of the specified namespace scoped custom object
//
object_t*
CustomObjectsAPI_replaceNamespacedCustomObjectStatus(apiClient_t *apiClient, char *group, char *version, char *_namespace, char *plural, char *name, object_t *body, char *dryRun, char *fieldManager, char *fieldValidation);


