#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/object.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_csi_driver.h"
#include "../model/v1_csi_driver_list.h"
#include "../model/v1_csi_node.h"
#include "../model/v1_csi_node_list.h"
#include "../model/v1_csi_storage_capacity.h"
#include "../model/v1_csi_storage_capacity_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_status.h"
#include "../model/v1_storage_class.h"
#include "../model/v1_storage_class_list.h"
#include "../model/v1_volume_attachment.h"
#include "../model/v1_volume_attachment_list.h"


// create a CSIDriver
//
v1_csi_driver_t*
StorageV1API_createCSIDriver(apiClient_t *apiClient, v1_csi_driver_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation );


// create a CSINode
//
v1_csi_node_t*
StorageV1API_createCSINode(apiClient_t *apiClient, v1_csi_node_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation );


// create a CSIStorageCapacity
//
v1_csi_storage_capacity_t*
StorageV1API_createNamespacedCSIStorageCapacity(apiClient_t *apiClient, char * _namespace , v1_csi_storage_capacity_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation );


// create a StorageClass
//
v1_storage_class_t*
StorageV1API_createStorageClass(apiClient_t *apiClient, v1_storage_class_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation );


// create a VolumeAttachment
//
v1_volume_attachment_t*
StorageV1API_createVolumeAttachment(apiClient_t *apiClient, v1_volume_attachment_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation );


// delete a CSIDriver
//
v1_csi_driver_t*
StorageV1API_deleteCSIDriver(apiClient_t *apiClient, char * name , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete a CSINode
//
v1_csi_node_t*
StorageV1API_deleteCSINode(apiClient_t *apiClient, char * name , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete collection of CSIDriver
//
v1_status_t*
StorageV1API_deleteCollectionCSIDriver(apiClient_t *apiClient, char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of CSINode
//
v1_status_t*
StorageV1API_deleteCollectionCSINode(apiClient_t *apiClient, char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of CSIStorageCapacity
//
v1_status_t*
StorageV1API_deleteCollectionNamespacedCSIStorageCapacity(apiClient_t *apiClient, char * _namespace , char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of StorageClass
//
v1_status_t*
StorageV1API_deleteCollectionStorageClass(apiClient_t *apiClient, char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of VolumeAttachment
//
v1_status_t*
StorageV1API_deleteCollectionVolumeAttachment(apiClient_t *apiClient, char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , v1_delete_options_t * body );


// delete a CSIStorageCapacity
//
v1_status_t*
StorageV1API_deleteNamespacedCSIStorageCapacity(apiClient_t *apiClient, char * name , char * _namespace , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete a StorageClass
//
v1_storage_class_t*
StorageV1API_deleteStorageClass(apiClient_t *apiClient, char * name , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete a VolumeAttachment
//
v1_volume_attachment_t*
StorageV1API_deleteVolumeAttachment(apiClient_t *apiClient, char * name , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// get available resources
//
v1_api_resource_list_t*
StorageV1API_getAPIResources(apiClient_t *apiClient);


// list or watch objects of kind CSIDriver
//
v1_csi_driver_list_t*
StorageV1API_listCSIDriver(apiClient_t *apiClient, char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , int watch );


// list or watch objects of kind CSINode
//
v1_csi_node_list_t*
StorageV1API_listCSINode(apiClient_t *apiClient, char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , int watch );


// list or watch objects of kind CSIStorageCapacity
//
v1_csi_storage_capacity_list_t*
StorageV1API_listCSIStorageCapacityForAllNamespaces(apiClient_t *apiClient, int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * pretty , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , int watch );


// list or watch objects of kind CSIStorageCapacity
//
v1_csi_storage_capacity_list_t*
StorageV1API_listNamespacedCSIStorageCapacity(apiClient_t *apiClient, char * _namespace , char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , int watch );


// list or watch objects of kind StorageClass
//
v1_storage_class_list_t*
StorageV1API_listStorageClass(apiClient_t *apiClient, char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , int watch );


// list or watch objects of kind VolumeAttachment
//
v1_volume_attachment_list_t*
StorageV1API_listVolumeAttachment(apiClient_t *apiClient, char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , char * resourceVersionMatch , int timeoutSeconds , int watch );


// partially update the specified CSIDriver
//
v1_csi_driver_t*
StorageV1API_patchCSIDriver(apiClient_t *apiClient, char * name , object_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation , int force );


// partially update the specified CSINode
//
v1_csi_node_t*
StorageV1API_patchCSINode(apiClient_t *apiClient, char * name , object_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation , int force );


// partially update the specified CSIStorageCapacity
//
v1_csi_storage_capacity_t*
StorageV1API_patchNamespacedCSIStorageCapacity(apiClient_t *apiClient, char * name , char * _namespace , object_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation , int force );


// partially update the specified StorageClass
//
v1_storage_class_t*
StorageV1API_patchStorageClass(apiClient_t *apiClient, char * name , object_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation , int force );


// partially update the specified VolumeAttachment
//
v1_volume_attachment_t*
StorageV1API_patchVolumeAttachment(apiClient_t *apiClient, char * name , object_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation , int force );


// partially update status of the specified VolumeAttachment
//
v1_volume_attachment_t*
StorageV1API_patchVolumeAttachmentStatus(apiClient_t *apiClient, char * name , object_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation , int force );


// read the specified CSIDriver
//
v1_csi_driver_t*
StorageV1API_readCSIDriver(apiClient_t *apiClient, char * name , char * pretty );


// read the specified CSINode
//
v1_csi_node_t*
StorageV1API_readCSINode(apiClient_t *apiClient, char * name , char * pretty );


// read the specified CSIStorageCapacity
//
v1_csi_storage_capacity_t*
StorageV1API_readNamespacedCSIStorageCapacity(apiClient_t *apiClient, char * name , char * _namespace , char * pretty );


// read the specified StorageClass
//
v1_storage_class_t*
StorageV1API_readStorageClass(apiClient_t *apiClient, char * name , char * pretty );


// read the specified VolumeAttachment
//
v1_volume_attachment_t*
StorageV1API_readVolumeAttachment(apiClient_t *apiClient, char * name , char * pretty );


// read status of the specified VolumeAttachment
//
v1_volume_attachment_t*
StorageV1API_readVolumeAttachmentStatus(apiClient_t *apiClient, char * name , char * pretty );


// replace the specified CSIDriver
//
v1_csi_driver_t*
StorageV1API_replaceCSIDriver(apiClient_t *apiClient, char * name , v1_csi_driver_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation );


// replace the specified CSINode
//
v1_csi_node_t*
StorageV1API_replaceCSINode(apiClient_t *apiClient, char * name , v1_csi_node_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation );


// replace the specified CSIStorageCapacity
//
v1_csi_storage_capacity_t*
StorageV1API_replaceNamespacedCSIStorageCapacity(apiClient_t *apiClient, char * name , char * _namespace , v1_csi_storage_capacity_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation );


// replace the specified StorageClass
//
v1_storage_class_t*
StorageV1API_replaceStorageClass(apiClient_t *apiClient, char * name , v1_storage_class_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation );


// replace the specified VolumeAttachment
//
v1_volume_attachment_t*
StorageV1API_replaceVolumeAttachment(apiClient_t *apiClient, char * name , v1_volume_attachment_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation );


// replace status of the specified VolumeAttachment
//
v1_volume_attachment_t*
StorageV1API_replaceVolumeAttachmentStatus(apiClient_t *apiClient, char * name , v1_volume_attachment_t * body , char * pretty , char * dryRun , char * fieldManager , char * fieldValidation );


