#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_status.h"
#include "../model/v1alpha1_pod_preset.h"
#include "../model/v1alpha1_pod_preset_list.h"


// create a PodPreset
//
v1alpha1_pod_preset_t*
SettingsV1alpha1API_createNamespacedPodPreset(apiClient_t *apiClient, char * _namespace , v1alpha1_pod_preset_t * body , char * pretty , char * dryRun , char * fieldManager );


// delete collection of PodPreset
//
v1_status_t*
SettingsV1alpha1API_deleteCollectionNamespacedPodPreset(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete a PodPreset
//
v1_status_t*
SettingsV1alpha1API_deleteNamespacedPodPreset(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// get available resources
//
v1_api_resource_list_t*
SettingsV1alpha1API_getAPIResources(apiClient_t *apiClient);


// list or watch objects of kind PodPreset
//
v1alpha1_pod_preset_list_t*
SettingsV1alpha1API_listNamespacedPodPreset(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind PodPreset
//
v1alpha1_pod_preset_list_t*
SettingsV1alpha1API_listPodPresetForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , int timeoutSeconds , int watch );


// partially update the specified PodPreset
//
v1alpha1_pod_preset_t*
SettingsV1alpha1API_patchNamespacedPodPreset(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// read the specified PodPreset
//
v1alpha1_pod_preset_t*
SettingsV1alpha1API_readNamespacedPodPreset(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , int exact , int _export );


// replace the specified PodPreset
//
v1alpha1_pod_preset_t*
SettingsV1alpha1API_replaceNamespacedPodPreset(apiClient_t *apiClient, char * name , char * _namespace , v1alpha1_pod_preset_t * body , char * pretty , char * dryRun , char * fieldManager );


