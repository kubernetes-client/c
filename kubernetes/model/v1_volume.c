#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_volume.h"



v1_volume_t *v1_volume_create(
    v1_aws_elastic_block_store_volume_source_t *aws_elastic_block_store,
    v1_azure_disk_volume_source_t *azure_disk,
    v1_azure_file_volume_source_t *azure_file,
    v1_ceph_fs_volume_source_t *cephfs,
    v1_cinder_volume_source_t *cinder,
    v1_config_map_volume_source_t *config_map,
    v1_csi_volume_source_t *csi,
    v1_downward_api_volume_source_t *downward_api,
    v1_empty_dir_volume_source_t *empty_dir,
    v1_fc_volume_source_t *fc,
    v1_flex_volume_source_t *flex_volume,
    v1_flocker_volume_source_t *flocker,
    v1_gce_persistent_disk_volume_source_t *gce_persistent_disk,
    v1_git_repo_volume_source_t *git_repo,
    v1_glusterfs_volume_source_t *glusterfs,
    v1_host_path_volume_source_t *host_path,
    v1_iscsi_volume_source_t *iscsi,
    char *name,
    v1_nfs_volume_source_t *nfs,
    v1_persistent_volume_claim_volume_source_t *persistent_volume_claim,
    v1_photon_persistent_disk_volume_source_t *photon_persistent_disk,
    v1_portworx_volume_source_t *portworx_volume,
    v1_projected_volume_source_t *projected,
    v1_quobyte_volume_source_t *quobyte,
    v1_rbd_volume_source_t *rbd,
    v1_scale_io_volume_source_t *scale_io,
    v1_secret_volume_source_t *secret,
    v1_storage_os_volume_source_t *storageos,
    v1_vsphere_virtual_disk_volume_source_t *vsphere_volume
    ) {
    v1_volume_t *v1_volume_local_var = malloc(sizeof(v1_volume_t));
    if (!v1_volume_local_var) {
        return NULL;
    }
    v1_volume_local_var->aws_elastic_block_store = aws_elastic_block_store;
    v1_volume_local_var->azure_disk = azure_disk;
    v1_volume_local_var->azure_file = azure_file;
    v1_volume_local_var->cephfs = cephfs;
    v1_volume_local_var->cinder = cinder;
    v1_volume_local_var->config_map = config_map;
    v1_volume_local_var->csi = csi;
    v1_volume_local_var->downward_api = downward_api;
    v1_volume_local_var->empty_dir = empty_dir;
    v1_volume_local_var->fc = fc;
    v1_volume_local_var->flex_volume = flex_volume;
    v1_volume_local_var->flocker = flocker;
    v1_volume_local_var->gce_persistent_disk = gce_persistent_disk;
    v1_volume_local_var->git_repo = git_repo;
    v1_volume_local_var->glusterfs = glusterfs;
    v1_volume_local_var->host_path = host_path;
    v1_volume_local_var->iscsi = iscsi;
    v1_volume_local_var->name = name;
    v1_volume_local_var->nfs = nfs;
    v1_volume_local_var->persistent_volume_claim = persistent_volume_claim;
    v1_volume_local_var->photon_persistent_disk = photon_persistent_disk;
    v1_volume_local_var->portworx_volume = portworx_volume;
    v1_volume_local_var->projected = projected;
    v1_volume_local_var->quobyte = quobyte;
    v1_volume_local_var->rbd = rbd;
    v1_volume_local_var->scale_io = scale_io;
    v1_volume_local_var->secret = secret;
    v1_volume_local_var->storageos = storageos;
    v1_volume_local_var->vsphere_volume = vsphere_volume;

    return v1_volume_local_var;
}


void v1_volume_free(v1_volume_t *v1_volume) {
    if(NULL == v1_volume){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_volume->aws_elastic_block_store) {
        v1_aws_elastic_block_store_volume_source_free(v1_volume->aws_elastic_block_store);
        v1_volume->aws_elastic_block_store = NULL;
    }
    if (v1_volume->azure_disk) {
        v1_azure_disk_volume_source_free(v1_volume->azure_disk);
        v1_volume->azure_disk = NULL;
    }
    if (v1_volume->azure_file) {
        v1_azure_file_volume_source_free(v1_volume->azure_file);
        v1_volume->azure_file = NULL;
    }
    if (v1_volume->cephfs) {
        v1_ceph_fs_volume_source_free(v1_volume->cephfs);
        v1_volume->cephfs = NULL;
    }
    if (v1_volume->cinder) {
        v1_cinder_volume_source_free(v1_volume->cinder);
        v1_volume->cinder = NULL;
    }
    if (v1_volume->config_map) {
        v1_config_map_volume_source_free(v1_volume->config_map);
        v1_volume->config_map = NULL;
    }
    if (v1_volume->csi) {
        v1_csi_volume_source_free(v1_volume->csi);
        v1_volume->csi = NULL;
    }
    if (v1_volume->downward_api) {
        v1_downward_api_volume_source_free(v1_volume->downward_api);
        v1_volume->downward_api = NULL;
    }
    if (v1_volume->empty_dir) {
        v1_empty_dir_volume_source_free(v1_volume->empty_dir);
        v1_volume->empty_dir = NULL;
    }
    if (v1_volume->fc) {
        v1_fc_volume_source_free(v1_volume->fc);
        v1_volume->fc = NULL;
    }
    if (v1_volume->flex_volume) {
        v1_flex_volume_source_free(v1_volume->flex_volume);
        v1_volume->flex_volume = NULL;
    }
    if (v1_volume->flocker) {
        v1_flocker_volume_source_free(v1_volume->flocker);
        v1_volume->flocker = NULL;
    }
    if (v1_volume->gce_persistent_disk) {
        v1_gce_persistent_disk_volume_source_free(v1_volume->gce_persistent_disk);
        v1_volume->gce_persistent_disk = NULL;
    }
    if (v1_volume->git_repo) {
        v1_git_repo_volume_source_free(v1_volume->git_repo);
        v1_volume->git_repo = NULL;
    }
    if (v1_volume->glusterfs) {
        v1_glusterfs_volume_source_free(v1_volume->glusterfs);
        v1_volume->glusterfs = NULL;
    }
    if (v1_volume->host_path) {
        v1_host_path_volume_source_free(v1_volume->host_path);
        v1_volume->host_path = NULL;
    }
    if (v1_volume->iscsi) {
        v1_iscsi_volume_source_free(v1_volume->iscsi);
        v1_volume->iscsi = NULL;
    }
    if (v1_volume->name) {
        free(v1_volume->name);
        v1_volume->name = NULL;
    }
    if (v1_volume->nfs) {
        v1_nfs_volume_source_free(v1_volume->nfs);
        v1_volume->nfs = NULL;
    }
    if (v1_volume->persistent_volume_claim) {
        v1_persistent_volume_claim_volume_source_free(v1_volume->persistent_volume_claim);
        v1_volume->persistent_volume_claim = NULL;
    }
    if (v1_volume->photon_persistent_disk) {
        v1_photon_persistent_disk_volume_source_free(v1_volume->photon_persistent_disk);
        v1_volume->photon_persistent_disk = NULL;
    }
    if (v1_volume->portworx_volume) {
        v1_portworx_volume_source_free(v1_volume->portworx_volume);
        v1_volume->portworx_volume = NULL;
    }
    if (v1_volume->projected) {
        v1_projected_volume_source_free(v1_volume->projected);
        v1_volume->projected = NULL;
    }
    if (v1_volume->quobyte) {
        v1_quobyte_volume_source_free(v1_volume->quobyte);
        v1_volume->quobyte = NULL;
    }
    if (v1_volume->rbd) {
        v1_rbd_volume_source_free(v1_volume->rbd);
        v1_volume->rbd = NULL;
    }
    if (v1_volume->scale_io) {
        v1_scale_io_volume_source_free(v1_volume->scale_io);
        v1_volume->scale_io = NULL;
    }
    if (v1_volume->secret) {
        v1_secret_volume_source_free(v1_volume->secret);
        v1_volume->secret = NULL;
    }
    if (v1_volume->storageos) {
        v1_storage_os_volume_source_free(v1_volume->storageos);
        v1_volume->storageos = NULL;
    }
    if (v1_volume->vsphere_volume) {
        v1_vsphere_virtual_disk_volume_source_free(v1_volume->vsphere_volume);
        v1_volume->vsphere_volume = NULL;
    }
    free(v1_volume);
}

cJSON *v1_volume_convertToJSON(v1_volume_t *v1_volume) {
    cJSON *item = cJSON_CreateObject();

    // v1_volume->aws_elastic_block_store
    if(v1_volume->aws_elastic_block_store) { 
    cJSON *aws_elastic_block_store_local_JSON = v1_aws_elastic_block_store_volume_source_convertToJSON(v1_volume->aws_elastic_block_store);
    if(aws_elastic_block_store_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "awsElasticBlockStore", aws_elastic_block_store_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_volume->azure_disk
    if(v1_volume->azure_disk) { 
    cJSON *azure_disk_local_JSON = v1_azure_disk_volume_source_convertToJSON(v1_volume->azure_disk);
    if(azure_disk_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "azureDisk", azure_disk_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_volume->azure_file
    if(v1_volume->azure_file) { 
    cJSON *azure_file_local_JSON = v1_azure_file_volume_source_convertToJSON(v1_volume->azure_file);
    if(azure_file_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "azureFile", azure_file_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_volume->cephfs
    if(v1_volume->cephfs) { 
    cJSON *cephfs_local_JSON = v1_ceph_fs_volume_source_convertToJSON(v1_volume->cephfs);
    if(cephfs_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "cephfs", cephfs_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_volume->cinder
    if(v1_volume->cinder) { 
    cJSON *cinder_local_JSON = v1_cinder_volume_source_convertToJSON(v1_volume->cinder);
    if(cinder_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "cinder", cinder_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_volume->config_map
    if(v1_volume->config_map) { 
    cJSON *config_map_local_JSON = v1_config_map_volume_source_convertToJSON(v1_volume->config_map);
    if(config_map_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "configMap", config_map_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_volume->csi
    if(v1_volume->csi) { 
    cJSON *csi_local_JSON = v1_csi_volume_source_convertToJSON(v1_volume->csi);
    if(csi_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "csi", csi_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_volume->downward_api
    if(v1_volume->downward_api) { 
    cJSON *downward_api_local_JSON = v1_downward_api_volume_source_convertToJSON(v1_volume->downward_api);
    if(downward_api_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "downwardAPI", downward_api_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_volume->empty_dir
    if(v1_volume->empty_dir) { 
    cJSON *empty_dir_local_JSON = v1_empty_dir_volume_source_convertToJSON(v1_volume->empty_dir);
    if(empty_dir_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "emptyDir", empty_dir_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_volume->fc
    if(v1_volume->fc) { 
    cJSON *fc_local_JSON = v1_fc_volume_source_convertToJSON(v1_volume->fc);
    if(fc_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "fc", fc_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_volume->flex_volume
    if(v1_volume->flex_volume) { 
    cJSON *flex_volume_local_JSON = v1_flex_volume_source_convertToJSON(v1_volume->flex_volume);
    if(flex_volume_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "flexVolume", flex_volume_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_volume->flocker
    if(v1_volume->flocker) { 
    cJSON *flocker_local_JSON = v1_flocker_volume_source_convertToJSON(v1_volume->flocker);
    if(flocker_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "flocker", flocker_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_volume->gce_persistent_disk
    if(v1_volume->gce_persistent_disk) { 
    cJSON *gce_persistent_disk_local_JSON = v1_gce_persistent_disk_volume_source_convertToJSON(v1_volume->gce_persistent_disk);
    if(gce_persistent_disk_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "gcePersistentDisk", gce_persistent_disk_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_volume->git_repo
    if(v1_volume->git_repo) { 
    cJSON *git_repo_local_JSON = v1_git_repo_volume_source_convertToJSON(v1_volume->git_repo);
    if(git_repo_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "gitRepo", git_repo_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_volume->glusterfs
    if(v1_volume->glusterfs) { 
    cJSON *glusterfs_local_JSON = v1_glusterfs_volume_source_convertToJSON(v1_volume->glusterfs);
    if(glusterfs_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "glusterfs", glusterfs_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_volume->host_path
    if(v1_volume->host_path) { 
    cJSON *host_path_local_JSON = v1_host_path_volume_source_convertToJSON(v1_volume->host_path);
    if(host_path_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "hostPath", host_path_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_volume->iscsi
    if(v1_volume->iscsi) { 
    cJSON *iscsi_local_JSON = v1_iscsi_volume_source_convertToJSON(v1_volume->iscsi);
    if(iscsi_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "iscsi", iscsi_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_volume->name
    if (!v1_volume->name) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "name", v1_volume->name) == NULL) {
    goto fail; //String
    }


    // v1_volume->nfs
    if(v1_volume->nfs) { 
    cJSON *nfs_local_JSON = v1_nfs_volume_source_convertToJSON(v1_volume->nfs);
    if(nfs_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "nfs", nfs_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_volume->persistent_volume_claim
    if(v1_volume->persistent_volume_claim) { 
    cJSON *persistent_volume_claim_local_JSON = v1_persistent_volume_claim_volume_source_convertToJSON(v1_volume->persistent_volume_claim);
    if(persistent_volume_claim_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "persistentVolumeClaim", persistent_volume_claim_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_volume->photon_persistent_disk
    if(v1_volume->photon_persistent_disk) { 
    cJSON *photon_persistent_disk_local_JSON = v1_photon_persistent_disk_volume_source_convertToJSON(v1_volume->photon_persistent_disk);
    if(photon_persistent_disk_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "photonPersistentDisk", photon_persistent_disk_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_volume->portworx_volume
    if(v1_volume->portworx_volume) { 
    cJSON *portworx_volume_local_JSON = v1_portworx_volume_source_convertToJSON(v1_volume->portworx_volume);
    if(portworx_volume_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "portworxVolume", portworx_volume_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_volume->projected
    if(v1_volume->projected) { 
    cJSON *projected_local_JSON = v1_projected_volume_source_convertToJSON(v1_volume->projected);
    if(projected_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "projected", projected_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_volume->quobyte
    if(v1_volume->quobyte) { 
    cJSON *quobyte_local_JSON = v1_quobyte_volume_source_convertToJSON(v1_volume->quobyte);
    if(quobyte_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "quobyte", quobyte_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_volume->rbd
    if(v1_volume->rbd) { 
    cJSON *rbd_local_JSON = v1_rbd_volume_source_convertToJSON(v1_volume->rbd);
    if(rbd_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "rbd", rbd_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_volume->scale_io
    if(v1_volume->scale_io) { 
    cJSON *scale_io_local_JSON = v1_scale_io_volume_source_convertToJSON(v1_volume->scale_io);
    if(scale_io_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "scaleIO", scale_io_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_volume->secret
    if(v1_volume->secret) { 
    cJSON *secret_local_JSON = v1_secret_volume_source_convertToJSON(v1_volume->secret);
    if(secret_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "secret", secret_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_volume->storageos
    if(v1_volume->storageos) { 
    cJSON *storageos_local_JSON = v1_storage_os_volume_source_convertToJSON(v1_volume->storageos);
    if(storageos_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "storageos", storageos_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_volume->vsphere_volume
    if(v1_volume->vsphere_volume) { 
    cJSON *vsphere_volume_local_JSON = v1_vsphere_virtual_disk_volume_source_convertToJSON(v1_volume->vsphere_volume);
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

v1_volume_t *v1_volume_parseFromJSON(cJSON *v1_volumeJSON){

    v1_volume_t *v1_volume_local_var = NULL;

    // v1_volume->aws_elastic_block_store
    cJSON *aws_elastic_block_store = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "awsElasticBlockStore");
    v1_aws_elastic_block_store_volume_source_t *aws_elastic_block_store_local_nonprim = NULL;
    if (aws_elastic_block_store) { 
    aws_elastic_block_store_local_nonprim = v1_aws_elastic_block_store_volume_source_parseFromJSON(aws_elastic_block_store); //nonprimitive
    }

    // v1_volume->azure_disk
    cJSON *azure_disk = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "azureDisk");
    v1_azure_disk_volume_source_t *azure_disk_local_nonprim = NULL;
    if (azure_disk) { 
    azure_disk_local_nonprim = v1_azure_disk_volume_source_parseFromJSON(azure_disk); //nonprimitive
    }

    // v1_volume->azure_file
    cJSON *azure_file = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "azureFile");
    v1_azure_file_volume_source_t *azure_file_local_nonprim = NULL;
    if (azure_file) { 
    azure_file_local_nonprim = v1_azure_file_volume_source_parseFromJSON(azure_file); //nonprimitive
    }

    // v1_volume->cephfs
    cJSON *cephfs = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "cephfs");
    v1_ceph_fs_volume_source_t *cephfs_local_nonprim = NULL;
    if (cephfs) { 
    cephfs_local_nonprim = v1_ceph_fs_volume_source_parseFromJSON(cephfs); //nonprimitive
    }

    // v1_volume->cinder
    cJSON *cinder = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "cinder");
    v1_cinder_volume_source_t *cinder_local_nonprim = NULL;
    if (cinder) { 
    cinder_local_nonprim = v1_cinder_volume_source_parseFromJSON(cinder); //nonprimitive
    }

    // v1_volume->config_map
    cJSON *config_map = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "configMap");
    v1_config_map_volume_source_t *config_map_local_nonprim = NULL;
    if (config_map) { 
    config_map_local_nonprim = v1_config_map_volume_source_parseFromJSON(config_map); //nonprimitive
    }

    // v1_volume->csi
    cJSON *csi = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "csi");
    v1_csi_volume_source_t *csi_local_nonprim = NULL;
    if (csi) { 
    csi_local_nonprim = v1_csi_volume_source_parseFromJSON(csi); //nonprimitive
    }

    // v1_volume->downward_api
    cJSON *downward_api = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "downwardAPI");
    v1_downward_api_volume_source_t *downward_api_local_nonprim = NULL;
    if (downward_api) { 
    downward_api_local_nonprim = v1_downward_api_volume_source_parseFromJSON(downward_api); //nonprimitive
    }

    // v1_volume->empty_dir
    cJSON *empty_dir = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "emptyDir");
    v1_empty_dir_volume_source_t *empty_dir_local_nonprim = NULL;
    if (empty_dir) { 
    empty_dir_local_nonprim = v1_empty_dir_volume_source_parseFromJSON(empty_dir); //nonprimitive
    }

    // v1_volume->fc
    cJSON *fc = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "fc");
    v1_fc_volume_source_t *fc_local_nonprim = NULL;
    if (fc) { 
    fc_local_nonprim = v1_fc_volume_source_parseFromJSON(fc); //nonprimitive
    }

    // v1_volume->flex_volume
    cJSON *flex_volume = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "flexVolume");
    v1_flex_volume_source_t *flex_volume_local_nonprim = NULL;
    if (flex_volume) { 
    flex_volume_local_nonprim = v1_flex_volume_source_parseFromJSON(flex_volume); //nonprimitive
    }

    // v1_volume->flocker
    cJSON *flocker = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "flocker");
    v1_flocker_volume_source_t *flocker_local_nonprim = NULL;
    if (flocker) { 
    flocker_local_nonprim = v1_flocker_volume_source_parseFromJSON(flocker); //nonprimitive
    }

    // v1_volume->gce_persistent_disk
    cJSON *gce_persistent_disk = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "gcePersistentDisk");
    v1_gce_persistent_disk_volume_source_t *gce_persistent_disk_local_nonprim = NULL;
    if (gce_persistent_disk) { 
    gce_persistent_disk_local_nonprim = v1_gce_persistent_disk_volume_source_parseFromJSON(gce_persistent_disk); //nonprimitive
    }

    // v1_volume->git_repo
    cJSON *git_repo = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "gitRepo");
    v1_git_repo_volume_source_t *git_repo_local_nonprim = NULL;
    if (git_repo) { 
    git_repo_local_nonprim = v1_git_repo_volume_source_parseFromJSON(git_repo); //nonprimitive
    }

    // v1_volume->glusterfs
    cJSON *glusterfs = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "glusterfs");
    v1_glusterfs_volume_source_t *glusterfs_local_nonprim = NULL;
    if (glusterfs) { 
    glusterfs_local_nonprim = v1_glusterfs_volume_source_parseFromJSON(glusterfs); //nonprimitive
    }

    // v1_volume->host_path
    cJSON *host_path = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "hostPath");
    v1_host_path_volume_source_t *host_path_local_nonprim = NULL;
    if (host_path) { 
    host_path_local_nonprim = v1_host_path_volume_source_parseFromJSON(host_path); //nonprimitive
    }

    // v1_volume->iscsi
    cJSON *iscsi = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "iscsi");
    v1_iscsi_volume_source_t *iscsi_local_nonprim = NULL;
    if (iscsi) { 
    iscsi_local_nonprim = v1_iscsi_volume_source_parseFromJSON(iscsi); //nonprimitive
    }

    // v1_volume->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // v1_volume->nfs
    cJSON *nfs = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "nfs");
    v1_nfs_volume_source_t *nfs_local_nonprim = NULL;
    if (nfs) { 
    nfs_local_nonprim = v1_nfs_volume_source_parseFromJSON(nfs); //nonprimitive
    }

    // v1_volume->persistent_volume_claim
    cJSON *persistent_volume_claim = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "persistentVolumeClaim");
    v1_persistent_volume_claim_volume_source_t *persistent_volume_claim_local_nonprim = NULL;
    if (persistent_volume_claim) { 
    persistent_volume_claim_local_nonprim = v1_persistent_volume_claim_volume_source_parseFromJSON(persistent_volume_claim); //nonprimitive
    }

    // v1_volume->photon_persistent_disk
    cJSON *photon_persistent_disk = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "photonPersistentDisk");
    v1_photon_persistent_disk_volume_source_t *photon_persistent_disk_local_nonprim = NULL;
    if (photon_persistent_disk) { 
    photon_persistent_disk_local_nonprim = v1_photon_persistent_disk_volume_source_parseFromJSON(photon_persistent_disk); //nonprimitive
    }

    // v1_volume->portworx_volume
    cJSON *portworx_volume = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "portworxVolume");
    v1_portworx_volume_source_t *portworx_volume_local_nonprim = NULL;
    if (portworx_volume) { 
    portworx_volume_local_nonprim = v1_portworx_volume_source_parseFromJSON(portworx_volume); //nonprimitive
    }

    // v1_volume->projected
    cJSON *projected = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "projected");
    v1_projected_volume_source_t *projected_local_nonprim = NULL;
    if (projected) { 
    projected_local_nonprim = v1_projected_volume_source_parseFromJSON(projected); //nonprimitive
    }

    // v1_volume->quobyte
    cJSON *quobyte = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "quobyte");
    v1_quobyte_volume_source_t *quobyte_local_nonprim = NULL;
    if (quobyte) { 
    quobyte_local_nonprim = v1_quobyte_volume_source_parseFromJSON(quobyte); //nonprimitive
    }

    // v1_volume->rbd
    cJSON *rbd = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "rbd");
    v1_rbd_volume_source_t *rbd_local_nonprim = NULL;
    if (rbd) { 
    rbd_local_nonprim = v1_rbd_volume_source_parseFromJSON(rbd); //nonprimitive
    }

    // v1_volume->scale_io
    cJSON *scale_io = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "scaleIO");
    v1_scale_io_volume_source_t *scale_io_local_nonprim = NULL;
    if (scale_io) { 
    scale_io_local_nonprim = v1_scale_io_volume_source_parseFromJSON(scale_io); //nonprimitive
    }

    // v1_volume->secret
    cJSON *secret = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "secret");
    v1_secret_volume_source_t *secret_local_nonprim = NULL;
    if (secret) { 
    secret_local_nonprim = v1_secret_volume_source_parseFromJSON(secret); //nonprimitive
    }

    // v1_volume->storageos
    cJSON *storageos = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "storageos");
    v1_storage_os_volume_source_t *storageos_local_nonprim = NULL;
    if (storageos) { 
    storageos_local_nonprim = v1_storage_os_volume_source_parseFromJSON(storageos); //nonprimitive
    }

    // v1_volume->vsphere_volume
    cJSON *vsphere_volume = cJSON_GetObjectItemCaseSensitive(v1_volumeJSON, "vsphereVolume");
    v1_vsphere_virtual_disk_volume_source_t *vsphere_volume_local_nonprim = NULL;
    if (vsphere_volume) { 
    vsphere_volume_local_nonprim = v1_vsphere_virtual_disk_volume_source_parseFromJSON(vsphere_volume); //nonprimitive
    }


    v1_volume_local_var = v1_volume_create (
        aws_elastic_block_store ? aws_elastic_block_store_local_nonprim : NULL,
        azure_disk ? azure_disk_local_nonprim : NULL,
        azure_file ? azure_file_local_nonprim : NULL,
        cephfs ? cephfs_local_nonprim : NULL,
        cinder ? cinder_local_nonprim : NULL,
        config_map ? config_map_local_nonprim : NULL,
        csi ? csi_local_nonprim : NULL,
        downward_api ? downward_api_local_nonprim : NULL,
        empty_dir ? empty_dir_local_nonprim : NULL,
        fc ? fc_local_nonprim : NULL,
        flex_volume ? flex_volume_local_nonprim : NULL,
        flocker ? flocker_local_nonprim : NULL,
        gce_persistent_disk ? gce_persistent_disk_local_nonprim : NULL,
        git_repo ? git_repo_local_nonprim : NULL,
        glusterfs ? glusterfs_local_nonprim : NULL,
        host_path ? host_path_local_nonprim : NULL,
        iscsi ? iscsi_local_nonprim : NULL,
        strdup(name->valuestring),
        nfs ? nfs_local_nonprim : NULL,
        persistent_volume_claim ? persistent_volume_claim_local_nonprim : NULL,
        photon_persistent_disk ? photon_persistent_disk_local_nonprim : NULL,
        portworx_volume ? portworx_volume_local_nonprim : NULL,
        projected ? projected_local_nonprim : NULL,
        quobyte ? quobyte_local_nonprim : NULL,
        rbd ? rbd_local_nonprim : NULL,
        scale_io ? scale_io_local_nonprim : NULL,
        secret ? secret_local_nonprim : NULL,
        storageos ? storageos_local_nonprim : NULL,
        vsphere_volume ? vsphere_volume_local_nonprim : NULL
        );

    return v1_volume_local_var;
end:
    if (aws_elastic_block_store_local_nonprim) {
        v1_aws_elastic_block_store_volume_source_free(aws_elastic_block_store_local_nonprim);
        aws_elastic_block_store_local_nonprim = NULL;
    }
    if (azure_disk_local_nonprim) {
        v1_azure_disk_volume_source_free(azure_disk_local_nonprim);
        azure_disk_local_nonprim = NULL;
    }
    if (azure_file_local_nonprim) {
        v1_azure_file_volume_source_free(azure_file_local_nonprim);
        azure_file_local_nonprim = NULL;
    }
    if (cephfs_local_nonprim) {
        v1_ceph_fs_volume_source_free(cephfs_local_nonprim);
        cephfs_local_nonprim = NULL;
    }
    if (cinder_local_nonprim) {
        v1_cinder_volume_source_free(cinder_local_nonprim);
        cinder_local_nonprim = NULL;
    }
    if (config_map_local_nonprim) {
        v1_config_map_volume_source_free(config_map_local_nonprim);
        config_map_local_nonprim = NULL;
    }
    if (csi_local_nonprim) {
        v1_csi_volume_source_free(csi_local_nonprim);
        csi_local_nonprim = NULL;
    }
    if (downward_api_local_nonprim) {
        v1_downward_api_volume_source_free(downward_api_local_nonprim);
        downward_api_local_nonprim = NULL;
    }
    if (empty_dir_local_nonprim) {
        v1_empty_dir_volume_source_free(empty_dir_local_nonprim);
        empty_dir_local_nonprim = NULL;
    }
    if (fc_local_nonprim) {
        v1_fc_volume_source_free(fc_local_nonprim);
        fc_local_nonprim = NULL;
    }
    if (flex_volume_local_nonprim) {
        v1_flex_volume_source_free(flex_volume_local_nonprim);
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
    if (git_repo_local_nonprim) {
        v1_git_repo_volume_source_free(git_repo_local_nonprim);
        git_repo_local_nonprim = NULL;
    }
    if (glusterfs_local_nonprim) {
        v1_glusterfs_volume_source_free(glusterfs_local_nonprim);
        glusterfs_local_nonprim = NULL;
    }
    if (host_path_local_nonprim) {
        v1_host_path_volume_source_free(host_path_local_nonprim);
        host_path_local_nonprim = NULL;
    }
    if (iscsi_local_nonprim) {
        v1_iscsi_volume_source_free(iscsi_local_nonprim);
        iscsi_local_nonprim = NULL;
    }
    if (nfs_local_nonprim) {
        v1_nfs_volume_source_free(nfs_local_nonprim);
        nfs_local_nonprim = NULL;
    }
    if (persistent_volume_claim_local_nonprim) {
        v1_persistent_volume_claim_volume_source_free(persistent_volume_claim_local_nonprim);
        persistent_volume_claim_local_nonprim = NULL;
    }
    if (photon_persistent_disk_local_nonprim) {
        v1_photon_persistent_disk_volume_source_free(photon_persistent_disk_local_nonprim);
        photon_persistent_disk_local_nonprim = NULL;
    }
    if (portworx_volume_local_nonprim) {
        v1_portworx_volume_source_free(portworx_volume_local_nonprim);
        portworx_volume_local_nonprim = NULL;
    }
    if (projected_local_nonprim) {
        v1_projected_volume_source_free(projected_local_nonprim);
        projected_local_nonprim = NULL;
    }
    if (quobyte_local_nonprim) {
        v1_quobyte_volume_source_free(quobyte_local_nonprim);
        quobyte_local_nonprim = NULL;
    }
    if (rbd_local_nonprim) {
        v1_rbd_volume_source_free(rbd_local_nonprim);
        rbd_local_nonprim = NULL;
    }
    if (scale_io_local_nonprim) {
        v1_scale_io_volume_source_free(scale_io_local_nonprim);
        scale_io_local_nonprim = NULL;
    }
    if (secret_local_nonprim) {
        v1_secret_volume_source_free(secret_local_nonprim);
        secret_local_nonprim = NULL;
    }
    if (storageos_local_nonprim) {
        v1_storage_os_volume_source_free(storageos_local_nonprim);
        storageos_local_nonprim = NULL;
    }
    if (vsphere_volume_local_nonprim) {
        v1_vsphere_virtual_disk_volume_source_free(vsphere_volume_local_nonprim);
        vsphere_volume_local_nonprim = NULL;
    }
    return NULL;

}
