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
#include "../model/v1alpha1_csi_storage_capacity.h"
#include "../model/v1alpha1_csi_storage_capacity_list.h"
#include "../model/v1alpha1_volume_attachment.h"
#include "../model/v1alpha1_volume_attachment_list.h"


// create a CSIStorageCapacity
//
v1alpha1_csi_storage_capacity_t*
StorageV1alpha1API_createNamespacedCSIStorageCapacity(apiClient_t *apiClient, char * _namespace , v1alpha1_csi_storage_capacity_t * body , char * pretty , char * dryRun , char * fieldManager );


// create a VolumeAttachment
//
v1alpha1_volume_attachment_t*
StorageV1alpha1API_createVolumeAttachment(apiClient_t *apiClient, v1alpha1_volume_attachment_t * body , char * pretty , char * dryRun , char * fieldManager );


// delete collection of CSIStorageCapacity
//
v1_status_t*
StorageV1alpha1API_deleteCollectionNamespacedCSIStorageCapacity(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of VolumeAttachment
//
v1_status_t*
StorageV1alpha1API_deleteCollectionVolumeAttachment(apiClient_t *apiClient, char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , v1_delete_options_t * body );


// delete a CSIStorageCapacity
//
v1_status_t*
StorageV1alpha1API_deleteNamespacedCSIStorageCapacity(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete a VolumeAttachment
//
v1alpha1_volume_attachment_t*
StorageV1alpha1API_deleteVolumeAttachment(apiClient_t *apiClient, char * name , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// get available resources
//
v1_api_resource_list_t*
StorageV1alpha1API_getAPIResources(apiClient_t *apiClient);


// list or watch objects of kind CSIStorageCapacity
//
v1alpha1_csi_storage_capacity_list_t*
StorageV1alpha1API_listCSIStorageCapacityForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , int watch );


// list or watch objects of kind CSIStorageCapacity
//
v1alpha1_csi_storage_capacity_list_t*
StorageV1alpha1API_listNamespacedCSIStorageCapacity(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , int watch );


// list or watch objects of kind VolumeAttachment
//
v1alpha1_volume_attachment_list_t*
StorageV1alpha1API_listVolumeAttachment(apiClient_t *apiClient, char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , int watch );


// partially update the specified CSIStorageCapacity
//
v1alpha1_csi_storage_capacity_t*
StorageV1alpha1API_patchNamespacedCSIStorageCapacity(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update the specified VolumeAttachment
//
v1alpha1_volume_attachment_t*
StorageV1alpha1API_patchVolumeAttachment(apiClient_t *apiClient, char * name , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// read the specified CSIStorageCapacity
//
v1alpha1_csi_storage_capacity_t*
StorageV1alpha1API_readNamespacedCSIStorageCapacity(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// read the specified VolumeAttachment
//
v1alpha1_volume_attachment_t*
StorageV1alpha1API_readVolumeAttachment(apiClient_t *apiClient, char * name , char * pretty );


// replace the specified CSIStorageCapacity
//
v1alpha1_csi_storage_capacity_t*
StorageV1alpha1API_replaceNamespacedCSIStorageCapacity(apiClient_t *apiClient, char * name , char * _namespace , v1alpha1_csi_storage_capacity_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace the specified VolumeAttachment
//
v1alpha1_volume_attachment_t*
StorageV1alpha1API_replaceVolumeAttachment(apiClient_t *apiClient, char * name , v1alpha1_volume_attachment_t * body , char * pretty , char * dryRun , char * fieldManager );


