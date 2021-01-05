#include <stdlib.h>
#include <stdio.h>
#include "../include/apiClient.h"
#include "../include/list.h"
#include "../external/cJSON.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "../model/v1_api_resource_list.h"
#include "../model/v1_csi_node.h"
#include "../model/v1_csi_node_list.h"
#include "../model/v1_delete_options.h"
#include "../model/v1_status.h"
#include "../model/v1_storage_class.h"
#include "../model/v1_storage_class_list.h"
#include "../model/v1_volume_attachment.h"
#include "../model/v1_volume_attachment_list.h"


// create a CSINode
//
v1_csi_node_t*
StorageV1API_createCSINode(apiClient_t *apiClient, v1_csi_node_t * body , char * pretty , char * dryRun , char * fieldManager );


// create a StorageClass
//
v1_storage_class_t*
StorageV1API_createStorageClass(apiClient_t *apiClient, v1_storage_class_t * body , char * pretty , char * dryRun , char * fieldManager );


// create a VolumeAttachment
//
v1_volume_attachment_t*
StorageV1API_createVolumeAttachment(apiClient_t *apiClient, v1_volume_attachment_t * body , char * pretty , char * dryRun , char * fieldManager );


// delete a CSINode
//
v1_status_t*
StorageV1API_deleteCSINode(apiClient_t *apiClient, char * name , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete collection of CSINode
//
v1_status_t*
StorageV1API_deleteCollectionCSINode(apiClient_t *apiClient, char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of StorageClass
//
v1_status_t*
StorageV1API_deleteCollectionStorageClass(apiClient_t *apiClient, char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete collection of VolumeAttachment
//
v1_status_t*
StorageV1API_deleteCollectionVolumeAttachment(apiClient_t *apiClient, char * pretty , char * _continue , char * dryRun , char * fieldSelector , int gracePeriodSeconds , char * labelSelector , int limit , int orphanDependents , char * propagationPolicy , char * resourceVersion , int timeoutSeconds , v1_delete_options_t * body );


// delete a StorageClass
//
v1_status_t*
StorageV1API_deleteStorageClass(apiClient_t *apiClient, char * name , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// delete a VolumeAttachment
//
v1_status_t*
StorageV1API_deleteVolumeAttachment(apiClient_t *apiClient, char * name , char * pretty , char * dryRun , int gracePeriodSeconds , int orphanDependents , char * propagationPolicy , v1_delete_options_t * body );


// get available resources
//
v1_api_resource_list_t*
StorageV1API_getAPIResources(apiClient_t *apiClient);


// list or watch objects of kind CSINode
//
v1_csi_node_list_t*
StorageV1API_listCSINode(apiClient_t *apiClient, char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind StorageClass
//
v1_storage_class_list_t*
StorageV1API_listStorageClass(apiClient_t *apiClient, char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// list or watch objects of kind VolumeAttachment
//
v1_volume_attachment_list_t*
StorageV1API_listVolumeAttachment(apiClient_t *apiClient, char * pretty , int allowWatchBookmarks , char * _continue , char * fieldSelector , char * labelSelector , int limit , char * resourceVersion , int timeoutSeconds , int watch );


// partially update the specified CSINode
//
v1_csi_node_t*
StorageV1API_patchCSINode(apiClient_t *apiClient, char * name , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update the specified StorageClass
//
v1_storage_class_t*
StorageV1API_patchStorageClass(apiClient_t *apiClient, char * name , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update the specified VolumeAttachment
//
v1_volume_attachment_t*
StorageV1API_patchVolumeAttachment(apiClient_t *apiClient, char * name , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// partially update status of the specified VolumeAttachment
//
v1_volume_attachment_t*
StorageV1API_patchVolumeAttachmentStatus(apiClient_t *apiClient, char * name , object_t * body , char * pretty , char * dryRun , char * fieldManager , int force );


// read the specified CSINode
//
v1_csi_node_t*
StorageV1API_readCSINode(apiClient_t *apiClient, char * name , char * pretty , int exact , int _export );


// read the specified StorageClass
//
v1_storage_class_t*
StorageV1API_readStorageClass(apiClient_t *apiClient, char * name , char * pretty , int exact , int _export );


// read the specified VolumeAttachment
//
v1_volume_attachment_t*
StorageV1API_readVolumeAttachment(apiClient_t *apiClient, char * name , char * pretty , int exact , int _export );


// read status of the specified VolumeAttachment
//
v1_volume_attachment_t*
StorageV1API_readVolumeAttachmentStatus(apiClient_t *apiClient, char * name , char * pretty );


// replace the specified CSINode
//
v1_csi_node_t*
StorageV1API_replaceCSINode(apiClient_t *apiClient, char * name , v1_csi_node_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace the specified StorageClass
//
v1_storage_class_t*
StorageV1API_replaceStorageClass(apiClient_t *apiClient, char * name , v1_storage_class_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace the specified VolumeAttachment
//
v1_volume_attachment_t*
StorageV1API_replaceVolumeAttachment(apiClient_t *apiClient, char * name , v1_volume_attachment_t * body , char * pretty , char * dryRun , char * fieldManager );


// replace status of the specified VolumeAttachment
//
v1_volume_attachment_t*
StorageV1API_replaceVolumeAttachmentStatus(apiClient_t *apiClient, char * name , v1_volume_attachment_t * body , char * pretty , char * dryRun , char * fieldManager );


