#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_portworx_volume_source.h"



v1_portworx_volume_source_t *v1_portworx_volume_source_create(
    char *fs_type,
    int read_only,
    char *volume_id
    ) {
    v1_portworx_volume_source_t *v1_portworx_volume_source_local_var = malloc(sizeof(v1_portworx_volume_source_t));
    if (!v1_portworx_volume_source_local_var) {
        return NULL;
    }
    v1_portworx_volume_source_local_var->fs_type = fs_type;
    v1_portworx_volume_source_local_var->read_only = read_only;
    v1_portworx_volume_source_local_var->volume_id = volume_id;

    return v1_portworx_volume_source_local_var;
}


void v1_portworx_volume_source_free(v1_portworx_volume_source_t *v1_portworx_volume_source) {
    if(NULL == v1_portworx_volume_source){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_portworx_volume_source->fs_type) {
        free(v1_portworx_volume_source->fs_type);
        v1_portworx_volume_source->fs_type = NULL;
    }
    if (v1_portworx_volume_source->volume_id) {
        free(v1_portworx_volume_source->volume_id);
        v1_portworx_volume_source->volume_id = NULL;
    }
    free(v1_portworx_volume_source);
}

cJSON *v1_portworx_volume_source_convertToJSON(v1_portworx_volume_source_t *v1_portworx_volume_source) {
    cJSON *item = cJSON_CreateObject();

    // v1_portworx_volume_source->fs_type
    if(v1_portworx_volume_source->fs_type) { 
    if(cJSON_AddStringToObject(item, "fsType", v1_portworx_volume_source->fs_type) == NULL) {
    goto fail; //String
    }
     } 


    // v1_portworx_volume_source->read_only
    if(v1_portworx_volume_source->read_only) { 
    if(cJSON_AddBoolToObject(item, "readOnly", v1_portworx_volume_source->read_only) == NULL) {
    goto fail; //Bool
    }
     } 


    // v1_portworx_volume_source->volume_id
    if (!v1_portworx_volume_source->volume_id) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "volumeID", v1_portworx_volume_source->volume_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_portworx_volume_source_t *v1_portworx_volume_source_parseFromJSON(cJSON *v1_portworx_volume_sourceJSON){

    v1_portworx_volume_source_t *v1_portworx_volume_source_local_var = NULL;

    // v1_portworx_volume_source->fs_type
    cJSON *fs_type = cJSON_GetObjectItemCaseSensitive(v1_portworx_volume_sourceJSON, "fsType");
    if (fs_type) { 
    if(!cJSON_IsString(fs_type))
    {
    goto end; //String
    }
    }

    // v1_portworx_volume_source->read_only
    cJSON *read_only = cJSON_GetObjectItemCaseSensitive(v1_portworx_volume_sourceJSON, "readOnly");
    if (read_only) { 
    if(!cJSON_IsBool(read_only))
    {
    goto end; //Bool
    }
    }

    // v1_portworx_volume_source->volume_id
    cJSON *volume_id = cJSON_GetObjectItemCaseSensitive(v1_portworx_volume_sourceJSON, "volumeID");
    if (!volume_id) {
        goto end;
    }

    
    if(!cJSON_IsString(volume_id))
    {
    goto end; //String
    }


    v1_portworx_volume_source_local_var = v1_portworx_volume_source_create (
        fs_type ? strdup(fs_type->valuestring) : NULL,
        read_only ? read_only->valueint : 0,
        strdup(volume_id->valuestring)
        );

    return v1_portworx_volume_source_local_var;
end:
    return NULL;

}
