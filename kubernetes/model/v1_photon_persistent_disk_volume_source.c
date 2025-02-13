#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_photon_persistent_disk_volume_source.h"



static v1_photon_persistent_disk_volume_source_t *v1_photon_persistent_disk_volume_source_create_internal(
    char *fs_type,
    char *pd_id
    ) {
    v1_photon_persistent_disk_volume_source_t *v1_photon_persistent_disk_volume_source_local_var = malloc(sizeof(v1_photon_persistent_disk_volume_source_t));
    if (!v1_photon_persistent_disk_volume_source_local_var) {
        return NULL;
    }
    v1_photon_persistent_disk_volume_source_local_var->fs_type = fs_type;
    v1_photon_persistent_disk_volume_source_local_var->pd_id = pd_id;

    v1_photon_persistent_disk_volume_source_local_var->_library_owned = 1;
    return v1_photon_persistent_disk_volume_source_local_var;
}

__attribute__((deprecated)) v1_photon_persistent_disk_volume_source_t *v1_photon_persistent_disk_volume_source_create(
    char *fs_type,
    char *pd_id
    ) {
    return v1_photon_persistent_disk_volume_source_create_internal (
        fs_type,
        pd_id
        );
}

void v1_photon_persistent_disk_volume_source_free(v1_photon_persistent_disk_volume_source_t *v1_photon_persistent_disk_volume_source) {
    if(NULL == v1_photon_persistent_disk_volume_source){
        return ;
    }
    if(v1_photon_persistent_disk_volume_source->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_photon_persistent_disk_volume_source_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_photon_persistent_disk_volume_source->fs_type) {
        free(v1_photon_persistent_disk_volume_source->fs_type);
        v1_photon_persistent_disk_volume_source->fs_type = NULL;
    }
    if (v1_photon_persistent_disk_volume_source->pd_id) {
        free(v1_photon_persistent_disk_volume_source->pd_id);
        v1_photon_persistent_disk_volume_source->pd_id = NULL;
    }
    free(v1_photon_persistent_disk_volume_source);
}

cJSON *v1_photon_persistent_disk_volume_source_convertToJSON(v1_photon_persistent_disk_volume_source_t *v1_photon_persistent_disk_volume_source) {
    cJSON *item = cJSON_CreateObject();

    // v1_photon_persistent_disk_volume_source->fs_type
    if(v1_photon_persistent_disk_volume_source->fs_type) {
    if(cJSON_AddStringToObject(item, "fsType", v1_photon_persistent_disk_volume_source->fs_type) == NULL) {
    goto fail; //String
    }
    }


    // v1_photon_persistent_disk_volume_source->pd_id
    if (!v1_photon_persistent_disk_volume_source->pd_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "pdID", v1_photon_persistent_disk_volume_source->pd_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_photon_persistent_disk_volume_source_t *v1_photon_persistent_disk_volume_source_parseFromJSON(cJSON *v1_photon_persistent_disk_volume_sourceJSON){

    v1_photon_persistent_disk_volume_source_t *v1_photon_persistent_disk_volume_source_local_var = NULL;

    // v1_photon_persistent_disk_volume_source->fs_type
    cJSON *fs_type = cJSON_GetObjectItemCaseSensitive(v1_photon_persistent_disk_volume_sourceJSON, "fsType");
    if (cJSON_IsNull(fs_type)) {
        fs_type = NULL;
    }
    if (fs_type) { 
    if(!cJSON_IsString(fs_type) && !cJSON_IsNull(fs_type))
    {
    goto end; //String
    }
    }

    // v1_photon_persistent_disk_volume_source->pd_id
    cJSON *pd_id = cJSON_GetObjectItemCaseSensitive(v1_photon_persistent_disk_volume_sourceJSON, "pdID");
    if (cJSON_IsNull(pd_id)) {
        pd_id = NULL;
    }
    if (!pd_id) {
        goto end;
    }

    
    if(!cJSON_IsString(pd_id))
    {
    goto end; //String
    }


    v1_photon_persistent_disk_volume_source_local_var = v1_photon_persistent_disk_volume_source_create_internal (
        fs_type && !cJSON_IsNull(fs_type) ? strdup(fs_type->valuestring) : NULL,
        strdup(pd_id->valuestring)
        );

    return v1_photon_persistent_disk_volume_source_local_var;
end:
    return NULL;

}
