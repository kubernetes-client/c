#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_csi_driver_spec.h"



v1beta1_csi_driver_spec_t *v1beta1_csi_driver_spec_create(
    int attach_required,
    int pod_info_on_mount,
    list_t *volume_lifecycle_modes
    ) {
    v1beta1_csi_driver_spec_t *v1beta1_csi_driver_spec_local_var = malloc(sizeof(v1beta1_csi_driver_spec_t));
    if (!v1beta1_csi_driver_spec_local_var) {
        return NULL;
    }
    v1beta1_csi_driver_spec_local_var->attach_required = attach_required;
    v1beta1_csi_driver_spec_local_var->pod_info_on_mount = pod_info_on_mount;
    v1beta1_csi_driver_spec_local_var->volume_lifecycle_modes = volume_lifecycle_modes;

    return v1beta1_csi_driver_spec_local_var;
}


void v1beta1_csi_driver_spec_free(v1beta1_csi_driver_spec_t *v1beta1_csi_driver_spec) {
    if(NULL == v1beta1_csi_driver_spec){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_csi_driver_spec->volume_lifecycle_modes) {
        list_ForEach(listEntry, v1beta1_csi_driver_spec->volume_lifecycle_modes) {
            free(listEntry->data);
        }
        list_free(v1beta1_csi_driver_spec->volume_lifecycle_modes);
        v1beta1_csi_driver_spec->volume_lifecycle_modes = NULL;
    }
    free(v1beta1_csi_driver_spec);
}

cJSON *v1beta1_csi_driver_spec_convertToJSON(v1beta1_csi_driver_spec_t *v1beta1_csi_driver_spec) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_csi_driver_spec->attach_required
    if(v1beta1_csi_driver_spec->attach_required) { 
    if(cJSON_AddBoolToObject(item, "attachRequired", v1beta1_csi_driver_spec->attach_required) == NULL) {
    goto fail; //Bool
    }
     } 


    // v1beta1_csi_driver_spec->pod_info_on_mount
    if(v1beta1_csi_driver_spec->pod_info_on_mount) { 
    if(cJSON_AddBoolToObject(item, "podInfoOnMount", v1beta1_csi_driver_spec->pod_info_on_mount) == NULL) {
    goto fail; //Bool
    }
     } 


    // v1beta1_csi_driver_spec->volume_lifecycle_modes
    if(v1beta1_csi_driver_spec->volume_lifecycle_modes) { 
    cJSON *volume_lifecycle_modes = cJSON_AddArrayToObject(item, "volumeLifecycleModes");
    if(volume_lifecycle_modes == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *volume_lifecycle_modesListEntry;
    list_ForEach(volume_lifecycle_modesListEntry, v1beta1_csi_driver_spec->volume_lifecycle_modes) {
    if(cJSON_AddStringToObject(volume_lifecycle_modes, "", (char*)volume_lifecycle_modesListEntry->data) == NULL)
    {
        goto fail;
    }
    }
     } 

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta1_csi_driver_spec_t *v1beta1_csi_driver_spec_parseFromJSON(cJSON *v1beta1_csi_driver_specJSON){

    v1beta1_csi_driver_spec_t *v1beta1_csi_driver_spec_local_var = NULL;

    // v1beta1_csi_driver_spec->attach_required
    cJSON *attach_required = cJSON_GetObjectItemCaseSensitive(v1beta1_csi_driver_specJSON, "attachRequired");
    if (attach_required) { 
    if(!cJSON_IsBool(attach_required))
    {
    goto end; //Bool
    }
    }

    // v1beta1_csi_driver_spec->pod_info_on_mount
    cJSON *pod_info_on_mount = cJSON_GetObjectItemCaseSensitive(v1beta1_csi_driver_specJSON, "podInfoOnMount");
    if (pod_info_on_mount) { 
    if(!cJSON_IsBool(pod_info_on_mount))
    {
    goto end; //Bool
    }
    }

    // v1beta1_csi_driver_spec->volume_lifecycle_modes
    cJSON *volume_lifecycle_modes = cJSON_GetObjectItemCaseSensitive(v1beta1_csi_driver_specJSON, "volumeLifecycleModes");
    list_t *volume_lifecycle_modesList;
    if (volume_lifecycle_modes) { 
    cJSON *volume_lifecycle_modes_local;
    if(!cJSON_IsArray(volume_lifecycle_modes)) {
        goto end;//primitive container
    }
    volume_lifecycle_modesList = list_create();

    cJSON_ArrayForEach(volume_lifecycle_modes_local, volume_lifecycle_modes)
    {
        if(!cJSON_IsString(volume_lifecycle_modes_local))
        {
            goto end;
        }
        list_addElement(volume_lifecycle_modesList , strdup(volume_lifecycle_modes_local->valuestring));
    }
    }


    v1beta1_csi_driver_spec_local_var = v1beta1_csi_driver_spec_create (
        attach_required ? attach_required->valueint : 0,
        pod_info_on_mount ? pod_info_on_mount->valueint : 0,
        volume_lifecycle_modes ? volume_lifecycle_modesList : NULL
        );

    return v1beta1_csi_driver_spec_local_var;
end:
    return NULL;

}
