#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_persistent_volume_spec.h"



static v1_persistent_volume_spec_t *v1_persistent_volume_spec_create_internal(
    list_t *access_modes,
    v1_aws_elastic_block_store_volume_source_t *aws_elastic_block_store,
    v1_azure_disk_volume_source_t *azure_disk,
    v1_azure_file_persistent_volume_source_t *azure_file,
    list_t* capacity,
    v1_ceph_fs_persistent_volume_source_t *cephfs,
    v1_cinder_persistent_volume_source_t *cinder,
    v1_object_reference_t *claim_ref,
    v1_csi_persistent_volume_source_t *csi,
    v1_fc_volume_source_t *fc,
    v1_flex_persistent_volume_source_t *flex_volume,
    v1_flocker_volume_source_t *flocker,
    v1_gce_persistent_disk_volume_source_t *gce_persistent_disk,
    v1_glusterfs_persistent_volume_source_t *glusterfs,
    v1_host_path_volume_source_t *host_path,
    v1_iscsi_persistent_volume_source_t *iscsi,
    v1_local_volume_source_t *local,
    list_t *mount_options,
    v1_nfs_volume_source_t *nfs,
    v1_volume_node_affinity_t *node_affinity,
    char *persistent_volume_reclaim_policy,
    v1_photon_persistent_disk_volume_source_t *photon_persistent_disk,
    v1_portworx_volume_source_t *portworx_volume,
    v1_quobyte_volume_source_t *quobyte,
    v1_rbd_persistent_volume_source_t *rbd,
    v1_scale_io_persistent_volume_source_t *scale_io,
    char *storage_class_name,
    v1_storage_os_persistent_volume_source_t *storageos,
    char *volume_attributes_class_name,
    char *volume_mode,
    v1_vsphere_virtual_disk_volume_source_t *vsphere_volume
    ) {
    v1_persistent_volume_spec_t *v1_persistent_volume_spec_local_var = malloc(sizeof(v1_persistent_volume_spec_t));
    if (!v1_persistent_volume_spec_local_var) {
        return NULL;
    }
    v1_persistent_volume_spec_local_var->access_modes = access_modes;
    v1_persistent_volume_spec_local_var->aws_elastic_block_store = aws_elastic_block_store;
    v1_persistent_volume_spec_local_var->azure_disk = azure_disk;
    v1_persistent_volume_spec_local_var->azure_file = azure_file;
    v1_persistent_volume_spec_local_var->capacity = capacity;
    v1_persistent_volume_spec_local_var->cephfs = cephfs;
    v1_persistent_volume_spec_local_var->cinder = cinder;
    v1_persistent_volume_spec_local_var->claim_ref = claim_ref;
    v1_persistent_volume_spec_local_var->csi = csi;
    v1_persistent_volume_spec_local_var->fc = fc;
    v1_persistent_volume_spec_local_var->flex_volume = flex_volume;
    v1_persistent_volume_spec_local_var->flocker = flocker;
    v1_persistent_volume_spec_local_var->gce_persistent_disk = gce_persistent_disk;
    v1_persistent_volume_spec_local_var->glusterfs = glusterfs;
    v1_persistent_volume_spec_local_var->host_path = host_path;
    v1_persistent_volume_spec_local_var->iscsi = iscsi;
    v1_persistent_volume_spec_local_var->local = local;
    v1_persistent_volume_spec_local_var->mount_options = mount_options;
    v1_persistent_volume_spec_local_var->nfs = nfs;
    v1_persistent_volume_spec_local_var->node_affinity = node_affinity;
    v1_persistent_volume_spec_local_var->persistent_volume_reclaim_policy = persistent_volume_reclaim_policy;
    v1_persistent_volume_spec_local_var->photon_persistent_disk = photon_persistent_disk;
    v1_persistent_volume_spec_local_var->portworx_volume = portworx_volume;
    v1_persistent_volume_spec_local_var->quobyte = quobyte;
    v1_persistent_volume_spec_local_var->rbd = rbd;
    v1_persistent_volume_spec_local_var->scale_io = scale_io;
    v1_persistent_volume_spec_local_var->storage_class_name = storage_class_name;
    v1_persistent_volume_spec_local_var->storageos = storageos;
    v1_persistent_volume_spec_local_var->volume_attributes_class_name = volume_attributes_class_name;
    v1_persistent_volume_spec_local_var->volume_mode = volume_mode;
    v1_persistent_volume_spec_local_var->vsphere_volume = vsphere_volume;

    v1_persistent_volume_spec_local_var->_library_owned = 1;
    return v1_persistent_volume_spec_local_var;
}

__attribute__((deprecated)) v1_persistent_volume_spec_t *v1_persistent_volume_spec_create(
    list_t *access_modes,
    v1_aws_elastic_block_store_volume_source_t *aws_elastic_block_store,
    v1_azure_disk_volume_source_t *azure_disk,
    v1_azure_file_persistent_volume_source_t *azure_file,
    list_t* capacity,
    v1_ceph_fs_persistent_volume_source_t *cephfs,
    v1_cinder_persistent_volume_source_t *cinder,
    v1_object_reference_t *claim_ref,
    v1_csi_persistent_volume_source_t *csi,
    v1_fc_volume_source_t *fc,
    v1_flex_persistent_volume_source_t *flex_volume,
    v1_flocker_volume_source_t *flocker,
    v1_gce_persistent_disk_volume_source_t *gce_persistent_disk,
    v1_glusterfs_persistent_volume_source_t *glusterfs,
    v1_host_path_volume_source_t *host_path,
    v1_iscsi_persistent_volume_source_t *iscsi,
    v1_local_volume_source_t *local,
    list_t *mount_options,
    v1_nfs_volume_source_t *nfs,
    v1_volume_node_affinity_t *node_affinity,
    char *persistent_volume_reclaim_policy,
    v1_photon_persistent_disk_volume_source_t *photon_persistent_disk,
    v1_portworx_volume_source_t *portworx_volume,
    v1_quobyte_volume_source_t *quobyte,
    v1_rbd_persistent_volume_source_t *rbd,
    v1_scale_io_persistent_volume_source_t *scale_io,
    char *storage_class_name,
    v1_storage_os_persistent_volume_source_t *storageos,
    char *volume_attributes_class_name,
    char *volume_mode,
    v1_vsphere_virtual_disk_volume_source_t *vsphere_volume
    ) {
    return v1_persistent_volume_spec_create_internal (
        access_modes,
        aws_elastic_block_store,
        azure_disk,
        azure_file,
        capacity,
        cephfs,
        cinder,
        claim_ref,
        csi,
        fc,
        flex_volume,
        flocker,
        gce_persistent_disk,
        glusterfs,
        host_path,
        iscsi,
        local,
        mount_options,
        nfs,
        node_affinity,
        persistent_volume_reclaim_policy,
        photon_persistent_disk,
        portworx_volume,
        quobyte,
        rbd,
        scale_io,
        storage_class_name,
        storageos,
        volume_attributes_class_name,
        volume_mode,
        vsphere_volume
        );
}

void v1_persistent_volume_spec_free(v1_persistent_volume_spec_t *v1_persistent_volume_spec) {
    if(NULL == v1_persistent_volume_spec){
        return ;
    }
    if(v1_persistent_volume_spec->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_persistent_volume_spec_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_persistent_volume_spec->access_modes) {
        list_ForEach(listEntry, v1_persistent_volume_spec->access_modes) {
            free(listEntry->data);
        }
        list_freeList(v1_persistent_volume_spec->access_modes);
        v1_persistent_volume_spec->access_modes = NULL;
    }
    if (v1_persistent_volume_spec->aws_elastic_block_store) {
        v1_aws_elastic_block_store_volume_source_free(v1_persistent_volume_spec->aws_elastic_block_store);
        v1_persistent_volume_spec->aws_elastic_block_store = NULL;
    }
    if (v1_persistent_volume_spec->azure_disk) {
        v1_azure_disk_volume_source_free(v1_persistent_volume_spec->azure_disk);
        v1_persistent_volume_spec->azure_disk = NULL;
    }
    if (v1_persistent_volume_spec->azure_file) {
        v1_azure_file_persistent_volume_source_free(v1_persistent_volume_spec->azure_file);
        v1_persistent_volume_spec->azure_file = NULL;
    }
    if (v1_persistent_volume_spec->capacity) {
        list_ForEach(listEntry, v1_persistent_volume_spec->capacity) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_persistent_volume_spec->capacity);
        v1_persistent_volume_spec->capacity = NULL;
    }
    if (v1_persistent_volume_spec->cephfs) {
        v1_ceph_fs_persistent_volume_source_free(v1_persistent_volume_spec->cephfs);
        v1_persistent_volume_spec->cephfs = NULL;
    }
    if (v1_persistent_volume_spec->cinder) {
        v1_cinder_persistent_volume_source_free(v1_persistent_volume_spec->cinder);
        v1_persistent_volume_spec->cinder = NULL;
    }
    if (v1_persistent_volume_spec->claim_ref) {
        v1_object_reference_free(v1_persistent_volume_spec->claim_ref);
        v1_persistent_volume_spec->claim_ref = NULL;
    }
    if (v1_persistent_volume_spec->csi) {
        v1_csi_persistent_volume_source_free(v1_persistent_volume_spec->csi);
        v1_persistent_volume_spec->csi = NULL;
    }
    if (v1_persistent_volume_spec->fc) {
        v1_fc_volume_source_free(v1_persistent_volume_spec->fc);
        v1_persistent_volume_spec->fc = NULL;
    }
    if (v1_persistent_volume_spec->flex_volume) {
        v1_flex_persistent_volume_source_free(v1_persistent_volume_spec->flex_volume);
        v1_persistent_volume_spec->flex_volume = NULL;
    }
    if (v1_persistent_volume_spec->flocker) {
        v1_flocker_volume_source_free(v1_persistent_volume_spec->flocker);
        v1_persistent_volume_spec->flocker = NULL;
    }
    if (v1_persistent_volume_spec->gce_persistent_disk) {
        v1_gce_persistent_disk_volume_source_free(v1_persistent_volume_spec->gce_persistent_disk);
        v1_persistent_volume_spec->gce_persistent_disk = NULL;
    }
    if (v1_persistent_volume_spec->glusterfs) {
        v1_glusterfs_persistent_volume_source_free(v1_persistent_volume_spec->glusterfs);
        v1_persistent_volume_spec->glusterfs = NULL;
    }
    if (v1_persistent_volume_spec->host_path) {
        v1_host_path_volume_source_free(v1_persistent_volume_spec->host_path);
        v1_persistent_volume_spec->host_path = NULL;
    }
    if (v1_persistent_volume_spec->iscsi) {
        v1_iscsi_persistent_volume_source_free(v1_persistent_volume_spec->iscsi);
        v1_persistent_volume_spec->iscsi = NULL;
    }
    if (v1_persistent_volume_spec->local) {
        v1_local_volume_source_free(v1_persistent_volume_spec->local);
        v1_persistent_volume_spec->local = NULL;
    }
    if (v1_persistent_volume_spec->mount_options) {
        list_ForEach(listEntry, v1_persistent_volume_spec->mount_options) {
            free(listEntry->data);
        }
        list_freeList(v1_persistent_volume_spec->mount_options);
        v1_persistent_volume_spec->mount_options = NULL;
    }
    if (v1_persistent_volume_spec->nfs) {
        v1_nfs_volume_source_free(v1_persistent_volume_spec->nfs);
        v1_persistent_volume_spec->nfs = NULL;
    }
    if (v1_persistent_volume_spec->node_affinity) {
        v1_volume_node_affinity_free(v1_persistent_volume_spec->node_affinity);
        v1_persistent_volume_spec->node_affinity = NULL;
    }
    if (v1_persistent_volume_spec->persistent_volume_reclaim_policy) {
        free(v1_persistent_volume_spec->persistent_volume_reclaim_policy);
        v1_persistent_volume_spec->persistent_volume_reclaim_policy = NULL;
    }
    if (v1_persistent_volume_spec->photon_persistent_disk) {
        v1_photon_persistent_disk_volume_source_free(v1_persistent_volume_spec->photon_persistent_disk);
        v1_persistent_volume_spec->photon_persistent_disk = NULL;
    }
    if (v1_persistent_volume_spec->portworx_volume) {
        v1_portworx_volume_source_free(v1_persistent_volume_spec->portworx_volume);
        v1_persistent_volume_spec->portworx_volume = NULL;
    }
    if (v1_persistent_volume_spec->quobyte) {
        v1_quobyte_volume_source_free(v1_persistent_volume_spec->quobyte);
        v1_persistent_volume_spec->quobyte = NULL;
    }
    if (v1_persistent_volume_spec->rbd) {
        v1_rbd_persistent_volume_source_free(v1_persistent_volume_spec->rbd);
        v1_persistent_volume_spec->rbd = NULL;
    }
    if (v1_persistent_volume_spec->scale_io) {
        v1_scale_io_persistent_volume_source_free(v1_persistent_volume_spec->scale_io);
        v1_persistent_volume_spec->scale_io = NULL;
    }
    if (v1_persistent_volume_spec->storage_class_name) {
        free(v1_persistent_volume_spec->storage_class_name);
        v1_persistent_volume_spec->storage_class_name = NULL;
    }
    if (v1_persistent_volume_spec->storageos) {
        v1_storage_os_persistent_volume_source_free(v1_persistent_volume_spec->storageos);
        v1_persistent_volume_spec->storageos = NULL;
    }
    if (v1_persistent_volume_spec->volume_attributes_class_name) {
        free(v1_persistent_volume_spec->volume_attributes_class_name);
        v1_persistent_volume_spec->volume_attributes_class_name = NULL;
    }
    if (v1_persistent_volume_spec->volume_mode) {
        free(v1_persistent_volume_spec->volume_mode);
        v1_persistent_volume_spec->volume_mode = NULL;
    }
    if (v1_persistent_volume_spec->vsphere_volume) {
        v1_vsphere_virtual_disk_volume_source_free(v1_persistent_volume_spec->vsphere_volume);
        v1_persistent_volume_spec->vsphere_volume = NULL;
    }
    free(v1_persistent_volume_spec);
}

cJSON *v1_persistent_volume_spec_convertToJSON(v1_persistent_volume_spec_t *v1_persistent_volume_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1_persistent_volume_spec->access_modes
    if(v1_persistent_volume_spec->access_modes) {
    cJSON *access_modes = cJSON_AddArrayToObject(item, "accessModes");
    if(access_modes == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *access_modesListEntry;
    list_ForEach(access_modesListEntry, v1_persistent_volume_spec->access_modes) {
    if(cJSON_AddStringToObject(access_modes, "", access_modesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_persistent_volume_spec->aws_elastic_block_store
    if(v1_persistent_volume_spec->aws_elastic_block_store) {
    cJSON *aws_elastic_block_store_local_JSON = v1_aws_elastic_block_store_volume_source_convertToJSON(v1_persistent_volume_spec->aws_elastic_block_store);
    if(aws_elastic_block_store_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "awsElasticBlockStore", aws_elastic_block_store_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->azure_disk
    if(v1_persistent_volume_spec->azure_disk) {
    cJSON *azure_disk_local_JSON = v1_azure_disk_volume_source_convertToJSON(v1_persistent_volume_spec->azure_disk);
    if(azure_disk_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "azureDisk", azure_disk_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->azure_file
    if(v1_persistent_volume_spec->azure_file) {
    cJSON *azure_file_local_JSON = v1_azure_file_persistent_volume_source_convertToJSON(v1_persistent_volume_spec->azure_file);
    if(azure_file_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "azureFile", azure_file_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->capacity
    if(v1_persistent_volume_spec->capacity) {
    cJSON *capacity = cJSON_AddObjectToObject(item, "capacity");
    if(capacity == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = capacity;
    listEntry_t *capacityListEntry;
    if (v1_persistent_volume_spec->capacity) {
    list_ForEach(capacityListEntry, v1_persistent_volume_spec->capacity) {
        keyValuePair_t *localKeyValue = capacityListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
    }


    // v1_persistent_volume_spec->cephfs
    if(v1_persistent_volume_spec->cephfs) {
    cJSON *cephfs_local_JSON = v1_ceph_fs_persistent_volume_source_convertToJSON(v1_persistent_volume_spec->cephfs);
    if(cephfs_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "cephfs", cephfs_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->cinder
    if(v1_persistent_volume_spec->cinder) {
    cJSON *cinder_local_JSON = v1_cinder_persistent_volume_source_convertToJSON(v1_persistent_volume_spec->cinder);
    if(cinder_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "cinder", cinder_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->claim_ref
    if(v1_persistent_volume_spec->claim_ref) {
    cJSON *claim_ref_local_JSON = v1_object_reference_convertToJSON(v1_persistent_volume_spec->claim_ref);
    if(claim_ref_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "claimRef", claim_ref_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->csi
    if(v1_persistent_volume_spec->csi) {
    cJSON *csi_local_JSON = v1_csi_persistent_volume_source_convertToJSON(v1_persistent_volume_spec->csi);
    if(csi_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "csi", csi_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->fc
    if(v1_persistent_volume_spec->fc) {
    cJSON *fc_local_JSON = v1_fc_volume_source_convertToJSON(v1_persistent_volume_spec->fc);
    if(fc_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "fc", fc_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->flex_volume
    if(v1_persistent_volume_spec->flex_volume) {
    cJSON *flex_volume_local_JSON = v1_flex_persistent_volume_source_convertToJSON(v1_persistent_volume_spec->flex_volume);
    if(flex_volume_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "flexVolume", flex_volume_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->flocker
    if(v1_persistent_volume_spec->flocker) {
    cJSON *flocker_local_JSON = v1_flocker_volume_source_convertToJSON(v1_persistent_volume_spec->flocker);
    if(flocker_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "flocker", flocker_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->gce_persistent_disk
    if(v1_persistent_volume_spec->gce_persistent_disk) {
    cJSON *gce_persistent_disk_local_JSON = v1_gce_persistent_disk_volume_source_convertToJSON(v1_persistent_volume_spec->gce_persistent_disk);
    if(gce_persistent_disk_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "gcePersistentDisk", gce_persistent_disk_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->glusterfs
    if(v1_persistent_volume_spec->glusterfs) {
    cJSON *glusterfs_local_JSON = v1_glusterfs_persistent_volume_source_convertToJSON(v1_persistent_volume_spec->glusterfs);
    if(glusterfs_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "glusterfs", glusterfs_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->host_path
    if(v1_persistent_volume_spec->host_path) {
    cJSON *host_path_local_JSON = v1_host_path_volume_source_convertToJSON(v1_persistent_volume_spec->host_path);
    if(host_path_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "hostPath", host_path_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->iscsi
    if(v1_persistent_volume_spec->iscsi) {
    cJSON *iscsi_local_JSON = v1_iscsi_persistent_volume_source_convertToJSON(v1_persistent_volume_spec->iscsi);
    if(iscsi_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "iscsi", iscsi_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->local
    if(v1_persistent_volume_spec->local) {
    cJSON *local_local_JSON = v1_local_volume_source_convertToJSON(v1_persistent_volume_spec->local);
    if(local_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "local", local_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->mount_options
    if(v1_persistent_volume_spec->mount_options) {
    cJSON *mount_options = cJSON_AddArrayToObject(item, "mountOptions");
    if(mount_options == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *mount_optionsListEntry;
    list_ForEach(mount_optionsListEntry, v1_persistent_volume_spec->mount_options) {
    if(cJSON_AddStringToObject(mount_options, "", mount_optionsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // v1_persistent_volume_spec->nfs
    if(v1_persistent_volume_spec->nfs) {
    cJSON *nfs_local_JSON = v1_nfs_volume_source_convertToJSON(v1_persistent_volume_spec->nfs);
    if(nfs_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "nfs", nfs_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->node_affinity
    if(v1_persistent_volume_spec->node_affinity) {
    cJSON *node_affinity_local_JSON = v1_volume_node_affinity_convertToJSON(v1_persistent_volume_spec->node_affinity);
    if(node_affinity_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "nodeAffinity", node_affinity_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->persistent_volume_reclaim_policy
    if(v1_persistent_volume_spec->persistent_volume_reclaim_policy) {
    if(cJSON_AddStringToObject(item, "persistentVolumeReclaimPolicy", v1_persistent_volume_spec->persistent_volume_reclaim_policy) == NULL) {
    goto fail; //String
    }
    }


    // v1_persistent_volume_spec->photon_persistent_disk
    if(v1_persistent_volume_spec->photon_persistent_disk) {
    cJSON *photon_persistent_disk_local_JSON = v1_photon_persistent_disk_volume_source_convertToJSON(v1_persistent_volume_spec->photon_persistent_disk);
    if(photon_persistent_disk_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "photonPersistentDisk", photon_persistent_disk_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->portworx_volume
    if(v1_persistent_volume_spec->portworx_volume) {
    cJSON *portworx_volume_local_JSON = v1_portworx_volume_source_convertToJSON(v1_persistent_volume_spec->portworx_volume);
    if(portworx_volume_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "portworxVolume", portworx_volume_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->quobyte
    if(v1_persistent_volume_spec->quobyte) {
    cJSON *quobyte_local_JSON = v1_quobyte_volume_source_convertToJSON(v1_persistent_volume_spec->quobyte);
    if(quobyte_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "quobyte", quobyte_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->rbd
    if(v1_persistent_volume_spec->rbd) {
    cJSON *rbd_local_JSON = v1_rbd_persistent_volume_source_convertToJSON(v1_persistent_volume_spec->rbd);
    if(rbd_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "rbd", rbd_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->scale_io
    if(v1_persistent_volume_spec->scale_io) {
    cJSON *scale_io_local_JSON = v1_scale_io_persistent_volume_source_convertToJSON(v1_persistent_volume_spec->scale_io);
    if(scale_io_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "scaleIO", scale_io_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->storage_class_name
    if(v1_persistent_volume_spec->storage_class_name) {
    if(cJSON_AddStringToObject(item, "storageClassName", v1_persistent_volume_spec->storage_class_name) == NULL) {
    goto fail; //String
    }
    }


    // v1_persistent_volume_spec->storageos
    if(v1_persistent_volume_spec->storageos) {
    cJSON *storageos_local_JSON = v1_storage_os_persistent_volume_source_convertToJSON(v1_persistent_volume_spec->storageos);
    if(storageos_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "storageos", storageos_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_persistent_volume_spec->volume_attributes_class_name
    if(v1_persistent_volume_spec->volume_attributes_class_name) {
    if(cJSON_AddStringToObject(item, "volumeAttributesClassName", v1_persistent_volume_spec->volume_attributes_class_name) == NULL) {
    goto fail; //String
    }
    }


    // v1_persistent_volume_spec->volume_mode
    if(v1_persistent_volume_spec->volume_mode) {
    if(cJSON_AddStringToObject(item, "volumeMode", v1_persistent_volume_spec->volume_mode) == NULL) {
    goto fail; //String
    }
    }


    // v1_persistent_volume_spec->vsphere_volume
    if(v1_persistent_volume_spec->vsphere_volume) {
    cJSON *vsphere_volume_local_JSON = v1_vsphere_virtual_disk_volume_source_convertToJSON(v1_persistent_volume_spec->vsphere_volume);
    if(vsphere_volume_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "vsphereVolume", vsphere_volume_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_persistent_volume_spec_t *v1_persistent_volume_spec_parseFromJSON(cJSON *v1_persistent_volume_specJSON){

    v1_persistent_volume_spec_t *v1_persistent_volume_spec_local_var = NULL;

    // define the local list for v1_persistent_volume_spec->access_modes
    list_t *access_modesList = NULL;

    // define the local variable for v1_persistent_volume_spec->aws_elastic_block_store
    v1_aws_elastic_block_store_volume_source_t *aws_elastic_block_store_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->azure_disk
    v1_azure_disk_volume_source_t *azure_disk_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->azure_file
    v1_azure_file_persistent_volume_source_t *azure_file_local_nonprim = NULL;

    // define the local map for v1_persistent_volume_spec->capacity
    list_t *capacityList = NULL;

    // define the local variable for v1_persistent_volume_spec->cephfs
    v1_ceph_fs_persistent_volume_source_t *cephfs_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->cinder
    v1_cinder_persistent_volume_source_t *cinder_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->claim_ref
    v1_object_reference_t *claim_ref_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->csi
    v1_csi_persistent_volume_source_t *csi_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->fc
    v1_fc_volume_source_t *fc_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->flex_volume
    v1_flex_persistent_volume_source_t *flex_volume_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->flocker
    v1_flocker_volume_source_t *flocker_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->gce_persistent_disk
    v1_gce_persistent_disk_volume_source_t *gce_persistent_disk_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->glusterfs
    v1_glusterfs_persistent_volume_source_t *glusterfs_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->host_path
    v1_host_path_volume_source_t *host_path_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->iscsi
    v1_iscsi_persistent_volume_source_t *iscsi_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->local
    v1_local_volume_source_t *local_local_nonprim = NULL;

    // define the local list for v1_persistent_volume_spec->mount_options
    list_t *mount_optionsList = NULL;

    // define the local variable for v1_persistent_volume_spec->nfs
    v1_nfs_volume_source_t *nfs_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->node_affinity
    v1_volume_node_affinity_t *node_affinity_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->photon_persistent_disk
    v1_photon_persistent_disk_volume_source_t *photon_persistent_disk_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->portworx_volume
    v1_portworx_volume_source_t *portworx_volume_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->quobyte
    v1_quobyte_volume_source_t *quobyte_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->rbd
    v1_rbd_persistent_volume_source_t *rbd_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->scale_io
    v1_scale_io_persistent_volume_source_t *scale_io_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->storageos
    v1_storage_os_persistent_volume_source_t *storageos_local_nonprim = NULL;

    // define the local variable for v1_persistent_volume_spec->vsphere_volume
    v1_vsphere_virtual_disk_volume_source_t *vsphere_volume_local_nonprim = NULL;

    // v1_persistent_volume_spec->access_modes
    cJSON *access_modes = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "accessModes");
    if (cJSON_IsNull(access_modes)) {
        access_modes = NULL;
    }
    if (access_modes) { 
    cJSON *access_modes_local = NULL;
    if(!cJSON_IsArray(access_modes)) {
        goto end;//primitive container
    }
    access_modesList = list_createList();

    cJSON_ArrayForEach(access_modes_local, access_modes)
    {
        if(!cJSON_IsString(access_modes_local))
        {
            goto end;
        }
        list_addElement(access_modesList , strdup(access_modes_local->valuestring));
    }
    }

    // v1_persistent_volume_spec->aws_elastic_block_store
    cJSON *aws_elastic_block_store = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "awsElasticBlockStore");
    if (cJSON_IsNull(aws_elastic_block_store)) {
        aws_elastic_block_store = NULL;
    }
    if (aws_elastic_block_store) { 
    aws_elastic_block_store_local_nonprim = v1_aws_elastic_block_store_volume_source_parseFromJSON(aws_elastic_block_store); //nonprimitive
    }

    // v1_persistent_volume_spec->azure_disk
    cJSON *azure_disk = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "azureDisk");
    if (cJSON_IsNull(azure_disk)) {
        azure_disk = NULL;
    }
    if (azure_disk) { 
    azure_disk_local_nonprim = v1_azure_disk_volume_source_parseFromJSON(azure_disk); //nonprimitive
    }

    // v1_persistent_volume_spec->azure_file
    cJSON *azure_file = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "azureFile");
    if (cJSON_IsNull(azure_file)) {
        azure_file = NULL;
    }
    if (azure_file) { 
    azure_file_local_nonprim = v1_azure_file_persistent_volume_source_parseFromJSON(azure_file); //nonprimitive
    }

    // v1_persistent_volume_spec->capacity
    cJSON *capacity = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "capacity");
    if (cJSON_IsNull(capacity)) {
        capacity = NULL;
    }
    if (capacity) { 
    cJSON *capacity_local_map = NULL;
    if(!cJSON_IsObject(capacity) && !cJSON_IsNull(capacity))
    {
        goto end;//primitive map container
    }
    if(cJSON_IsObject(capacity))
    {
        capacityList = list_createList();
        keyValuePair_t *localMapKeyPair;
        cJSON_ArrayForEach(capacity_local_map, capacity)
        {
            cJSON *localMapObject = capacity_local_map;
            if(!cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(capacityList , localMapKeyPair);
        }
    }
    }

    // v1_persistent_volume_spec->cephfs
    cJSON *cephfs = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "cephfs");
    if (cJSON_IsNull(cephfs)) {
        cephfs = NULL;
    }
    if (cephfs) { 
    cephfs_local_nonprim = v1_ceph_fs_persistent_volume_source_parseFromJSON(cephfs); //nonprimitive
    }

    // v1_persistent_volume_spec->cinder
    cJSON *cinder = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "cinder");
    if (cJSON_IsNull(cinder)) {
        cinder = NULL;
    }
    if (cinder) { 
    cinder_local_nonprim = v1_cinder_persistent_volume_source_parseFromJSON(cinder); //nonprimitive
    }

    // v1_persistent_volume_spec->claim_ref
    cJSON *claim_ref = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "claimRef");
    if (cJSON_IsNull(claim_ref)) {
        claim_ref = NULL;
    }
    if (claim_ref) { 
    claim_ref_local_nonprim = v1_object_reference_parseFromJSON(claim_ref); //nonprimitive
    }

    // v1_persistent_volume_spec->csi
    cJSON *csi = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "csi");
    if (cJSON_IsNull(csi)) {
        csi = NULL;
    }
    if (csi) { 
    csi_local_nonprim = v1_csi_persistent_volume_source_parseFromJSON(csi); //nonprimitive
    }

    // v1_persistent_volume_spec->fc
    cJSON *fc = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "fc");
    if (cJSON_IsNull(fc)) {
        fc = NULL;
    }
    if (fc) { 
    fc_local_nonprim = v1_fc_volume_source_parseFromJSON(fc); //nonprimitive
    }

    // v1_persistent_volume_spec->flex_volume
    cJSON *flex_volume = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "flexVolume");
    if (cJSON_IsNull(flex_volume)) {
        flex_volume = NULL;
    }
    if (flex_volume) { 
    flex_volume_local_nonprim = v1_flex_persistent_volume_source_parseFromJSON(flex_volume); //nonprimitive
    }

    // v1_persistent_volume_spec->flocker
    cJSON *flocker = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "flocker");
    if (cJSON_IsNull(flocker)) {
        flocker = NULL;
    }
    if (flocker) { 
    flocker_local_nonprim = v1_flocker_volume_source_parseFromJSON(flocker); //nonprimitive
    }

    // v1_persistent_volume_spec->gce_persistent_disk
    cJSON *gce_persistent_disk = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "gcePersistentDisk");
    if (cJSON_IsNull(gce_persistent_disk)) {
        gce_persistent_disk = NULL;
    }
    if (gce_persistent_disk) { 
    gce_persistent_disk_local_nonprim = v1_gce_persistent_disk_volume_source_parseFromJSON(gce_persistent_disk); //nonprimitive
    }

    // v1_persistent_volume_spec->glusterfs
    cJSON *glusterfs = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "glusterfs");
    if (cJSON_IsNull(glusterfs)) {
        glusterfs = NULL;
    }
    if (glusterfs) { 
    glusterfs_local_nonprim = v1_glusterfs_persistent_volume_source_parseFromJSON(glusterfs); //nonprimitive
    }

    // v1_persistent_volume_spec->host_path
    cJSON *host_path = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "hostPath");
    if (cJSON_IsNull(host_path)) {
        host_path = NULL;
    }
    if (host_path) { 
    host_path_local_nonprim = v1_host_path_volume_source_parseFromJSON(host_path); //nonprimitive
    }

    // v1_persistent_volume_spec->iscsi
    cJSON *iscsi = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "iscsi");
    if (cJSON_IsNull(iscsi)) {
        iscsi = NULL;
    }
    if (iscsi) { 
    iscsi_local_nonprim = v1_iscsi_persistent_volume_source_parseFromJSON(iscsi); //nonprimitive
    }

    // v1_persistent_volume_spec->local
    cJSON *local = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "local");
    if (cJSON_IsNull(local)) {
        local = NULL;
    }
    if (local) { 
    local_local_nonprim = v1_local_volume_source_parseFromJSON(local); //nonprimitive
    }

    // v1_persistent_volume_spec->mount_options
    cJSON *mount_options = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "mountOptions");
    if (cJSON_IsNull(mount_options)) {
        mount_options = NULL;
    }
    if (mount_options) { 
    cJSON *mount_options_local = NULL;
    if(!cJSON_IsArray(mount_options)) {
        goto end;//primitive container
    }
    mount_optionsList = list_createList();

    cJSON_ArrayForEach(mount_options_local, mount_options)
    {
        if(!cJSON_IsString(mount_options_local))
        {
            goto end;
        }
        list_addElement(mount_optionsList , strdup(mount_options_local->valuestring));
    }
    }

    // v1_persistent_volume_spec->nfs
    cJSON *nfs = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "nfs");
    if (cJSON_IsNull(nfs)) {
        nfs = NULL;
    }
    if (nfs) { 
    nfs_local_nonprim = v1_nfs_volume_source_parseFromJSON(nfs); //nonprimitive
    }

    // v1_persistent_volume_spec->node_affinity
    cJSON *node_affinity = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "nodeAffinity");
    if (cJSON_IsNull(node_affinity)) {
        node_affinity = NULL;
    }
    if (node_affinity) { 
    node_affinity_local_nonprim = v1_volume_node_affinity_parseFromJSON(node_affinity); //nonprimitive
    }

    // v1_persistent_volume_spec->persistent_volume_reclaim_policy
    cJSON *persistent_volume_reclaim_policy = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "persistentVolumeReclaimPolicy");
    if (cJSON_IsNull(persistent_volume_reclaim_policy)) {
        persistent_volume_reclaim_policy = NULL;
    }
    if (persistent_volume_reclaim_policy) { 
    if(!cJSON_IsString(persistent_volume_reclaim_policy) && !cJSON_IsNull(persistent_volume_reclaim_policy))
    {
    goto end; //String
    }
    }

    // v1_persistent_volume_spec->photon_persistent_disk
    cJSON *photon_persistent_disk = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "photonPersistentDisk");
    if (cJSON_IsNull(photon_persistent_disk)) {
        photon_persistent_disk = NULL;
    }
    if (photon_persistent_disk) { 
    photon_persistent_disk_local_nonprim = v1_photon_persistent_disk_volume_source_parseFromJSON(photon_persistent_disk); //nonprimitive
    }

    // v1_persistent_volume_spec->portworx_volume
    cJSON *portworx_volume = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "portworxVolume");
    if (cJSON_IsNull(portworx_volume)) {
        portworx_volume = NULL;
    }
    if (portworx_volume) { 
    portworx_volume_local_nonprim = v1_portworx_volume_source_parseFromJSON(portworx_volume); //nonprimitive
    }

    // v1_persistent_volume_spec->quobyte
    cJSON *quobyte = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "quobyte");
    if (cJSON_IsNull(quobyte)) {
        quobyte = NULL;
    }
    if (quobyte) { 
    quobyte_local_nonprim = v1_quobyte_volume_source_parseFromJSON(quobyte); //nonprimitive
    }

    // v1_persistent_volume_spec->rbd
    cJSON *rbd = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "rbd");
    if (cJSON_IsNull(rbd)) {
        rbd = NULL;
    }
    if (rbd) { 
    rbd_local_nonprim = v1_rbd_persistent_volume_source_parseFromJSON(rbd); //nonprimitive
    }

    // v1_persistent_volume_spec->scale_io
    cJSON *scale_io = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "scaleIO");
    if (cJSON_IsNull(scale_io)) {
        scale_io = NULL;
    }
    if (scale_io) { 
    scale_io_local_nonprim = v1_scale_io_persistent_volume_source_parseFromJSON(scale_io); //nonprimitive
    }

    // v1_persistent_volume_spec->storage_class_name
    cJSON *storage_class_name = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "storageClassName");
    if (cJSON_IsNull(storage_class_name)) {
        storage_class_name = NULL;
    }
    if (storage_class_name) { 
    if(!cJSON_IsString(storage_class_name) && !cJSON_IsNull(storage_class_name))
    {
    goto end; //String
    }
    }

    // v1_persistent_volume_spec->storageos
    cJSON *storageos = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "storageos");
    if (cJSON_IsNull(storageos)) {
        storageos = NULL;
    }
    if (storageos) { 
    storageos_local_nonprim = v1_storage_os_persistent_volume_source_parseFromJSON(storageos); //nonprimitive
    }

    // v1_persistent_volume_spec->volume_attributes_class_name
    cJSON *volume_attributes_class_name = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "volumeAttributesClassName");
    if (cJSON_IsNull(volume_attributes_class_name)) {
        volume_attributes_class_name = NULL;
    }
    if (volume_attributes_class_name) { 
    if(!cJSON_IsString(volume_attributes_class_name) && !cJSON_IsNull(volume_attributes_class_name))
    {
    goto end; //String
    }
    }

    // v1_persistent_volume_spec->volume_mode
    cJSON *volume_mode = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "volumeMode");
    if (cJSON_IsNull(volume_mode)) {
        volume_mode = NULL;
    }
    if (volume_mode) { 
    if(!cJSON_IsString(volume_mode) && !cJSON_IsNull(volume_mode))
    {
    goto end; //String
    }
    }

    // v1_persistent_volume_spec->vsphere_volume
    cJSON *vsphere_volume = cJSON_GetObjectItemCaseSensitive(v1_persistent_volume_specJSON, "vsphereVolume");
    if (cJSON_IsNull(vsphere_volume)) {
        vsphere_volume = NULL;
    }
    if (vsphere_volume) { 
    vsphere_volume_local_nonprim = v1_vsphere_virtual_disk_volume_source_parseFromJSON(vsphere_volume); //nonprimitive
    }


    v1_persistent_volume_spec_local_var = v1_persistent_volume_spec_create_internal (
        access_modes ? access_modesList : NULL,
        aws_elastic_block_store ? aws_elastic_block_store_local_nonprim : NULL,
        azure_disk ? azure_disk_local_nonprim : NULL,
        azure_file ? azure_file_local_nonprim : NULL,
        capacity ? capacityList : NULL,
        cephfs ? cephfs_local_nonprim : NULL,
        cinder ? cinder_local_nonprim : NULL,
        claim_ref ? claim_ref_local_nonprim : NULL,
        csi ? csi_local_nonprim : NULL,
        fc ? fc_local_nonprim : NULL,
        flex_volume ? flex_volume_local_nonprim : NULL,
        flocker ? flocker_local_nonprim : NULL,
        gce_persistent_disk ? gce_persistent_disk_local_nonprim : NULL,
        glusterfs ? glusterfs_local_nonprim : NULL,
        host_path ? host_path_local_nonprim : NULL,
        iscsi ? iscsi_local_nonprim : NULL,
        local ? local_local_nonprim : NULL,
        mount_options ? mount_optionsList : NULL,
        nfs ? nfs_local_nonprim : NULL,
        node_affinity ? node_affinity_local_nonprim : NULL,
        persistent_volume_reclaim_policy && !cJSON_IsNull(persistent_volume_reclaim_policy) ? strdup(persistent_volume_reclaim_policy->valuestring) : NULL,
        photon_persistent_disk ? photon_persistent_disk_local_nonprim : NULL,
        portworx_volume ? portworx_volume_local_nonprim : NULL,
        quobyte ? quobyte_local_nonprim : NULL,
        rbd ? rbd_local_nonprim : NULL,
        scale_io ? scale_io_local_nonprim : NULL,
        storage_class_name && !cJSON_IsNull(storage_class_name) ? strdup(storage_class_name->valuestring) : NULL,
        storageos ? storageos_local_nonprim : NULL,
        volume_attributes_class_name && !cJSON_IsNull(volume_attributes_class_name) ? strdup(volume_attributes_class_name->valuestring) : NULL,
        volume_mode && !cJSON_IsNull(volume_mode) ? strdup(volume_mode->valuestring) : NULL,
        vsphere_volume ? vsphere_volume_local_nonprim : NULL
        );

    return v1_persistent_volume_spec_local_var;
end:
    if (access_modesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, access_modesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(access_modesList);
        access_modesList = NULL;
    }
    if (aws_elastic_block_store_local_nonprim) {
        v1_aws_elastic_block_store_volume_source_free(aws_elastic_block_store_local_nonprim);
        aws_elastic_block_store_local_nonprim = NULL;
    }
    if (azure_disk_local_nonprim) {
        v1_azure_disk_volume_source_free(azure_disk_local_nonprim);
        azure_disk_local_nonprim = NULL;
    }
    if (azure_file_local_nonprim) {
        v1_azure_file_persistent_volume_source_free(azure_file_local_nonprim);
        azure_file_local_nonprim = NULL;
    }
    if (capacityList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, capacityList) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(capacityList);
        capacityList = NULL;
    }
    if (cephfs_local_nonprim) {
        v1_ceph_fs_persistent_volume_source_free(cephfs_local_nonprim);
        cephfs_local_nonprim = NULL;
    }
    if (cinder_local_nonprim) {
        v1_cinder_persistent_volume_source_free(cinder_local_nonprim);
        cinder_local_nonprim = NULL;
    }
    if (claim_ref_local_nonprim) {
        v1_object_reference_free(claim_ref_local_nonprim);
        claim_ref_local_nonprim = NULL;
    }
    if (csi_local_nonprim) {
        v1_csi_persistent_volume_source_free(csi_local_nonprim);
        csi_local_nonprim = NULL;
    }
    if (fc_local_nonprim) {
        v1_fc_volume_source_free(fc_local_nonprim);
        fc_local_nonprim = NULL;
    }
    if (flex_volume_local_nonprim) {
        v1_flex_persistent_volume_source_free(flex_volume_local_nonprim);
        flex_volume_local_nonprim = NULL;
    }
    if (flocker_local_nonprim) {
        v1_flocker_volume_source_free(flocker_local_nonprim);
        flocker_local_nonprim = NULL;
    }
    if (gce_persistent_disk_local_nonprim) {
        v1_gce_persistent_disk_volume_source_free(gce_persistent_disk_local_nonprim);
        gce_persistent_disk_local_nonprim = NULL;
    }
    if (glusterfs_local_nonprim) {
        v1_glusterfs_persistent_volume_source_free(glusterfs_local_nonprim);
        glusterfs_local_nonprim = NULL;
    }
    if (host_path_local_nonprim) {
        v1_host_path_volume_source_free(host_path_local_nonprim);
        host_path_local_nonprim = NULL;
    }
    if (iscsi_local_nonprim) {
        v1_iscsi_persistent_volume_source_free(iscsi_local_nonprim);
        iscsi_local_nonprim = NULL;
    }
    if (local_local_nonprim) {
        v1_local_volume_source_free(local_local_nonprim);
        local_local_nonprim = NULL;
    }
    if (mount_optionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, mount_optionsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(mount_optionsList);
        mount_optionsList = NULL;
    }
    if (nfs_local_nonprim) {
        v1_nfs_volume_source_free(nfs_local_nonprim);
        nfs_local_nonprim = NULL;
    }
    if (node_affinity_local_nonprim) {
        v1_volume_node_affinity_free(node_affinity_local_nonprim);
        node_affinity_local_nonprim = NULL;
    }
    if (photon_persistent_disk_local_nonprim) {
        v1_photon_persistent_disk_volume_source_free(photon_persistent_disk_local_nonprim);
        photon_persistent_disk_local_nonprim = NULL;
    }
    if (portworx_volume_local_nonprim) {
        v1_portworx_volume_source_free(portworx_volume_local_nonprim);
        portworx_volume_local_nonprim = NULL;
    }
    if (quobyte_local_nonprim) {
        v1_quobyte_volume_source_free(quobyte_local_nonprim);
        quobyte_local_nonprim = NULL;
    }
    if (rbd_local_nonprim) {
        v1_rbd_persistent_volume_source_free(rbd_local_nonprim);
        rbd_local_nonprim = NULL;
    }
    if (scale_io_local_nonprim) {
        v1_scale_io_persistent_volume_source_free(scale_io_local_nonprim);
        scale_io_local_nonprim = NULL;
    }
    if (storageos_local_nonprim) {
        v1_storage_os_persistent_volume_source_free(storageos_local_nonprim);
        storageos_local_nonprim = NULL;
    }
    if (vsphere_volume_local_nonprim) {
        v1_vsphere_virtual_disk_volume_source_free(vsphere_volume_local_nonprim);
        vsphere_volume_local_nonprim = NULL;
    }
    return NULL;

}
