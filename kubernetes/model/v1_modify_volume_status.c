#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_modify_volume_status.h"



static v1_modify_volume_status_t *v1_modify_volume_status_create_internal(
    char *status,
    char *target_volume_attributes_class_name
    ) {
    v1_modify_volume_status_t *v1_modify_volume_status_local_var = malloc(sizeof(v1_modify_volume_status_t));
    if (!v1_modify_volume_status_local_var) {
        return NULL;
    }
    memset(v1_modify_volume_status_local_var, 0, sizeof(v1_modify_volume_status_t));
    v1_modify_volume_status_local_var->_library_owned = 1;
    v1_modify_volume_status_local_var->status = status;
    v1_modify_volume_status_local_var->target_volume_attributes_class_name = target_volume_attributes_class_name;
    return v1_modify_volume_status_local_var;
}

__attribute__((deprecated)) v1_modify_volume_status_t *v1_modify_volume_status_create(
    char *status,
    char *target_volume_attributes_class_name
    ) {
    v1_modify_volume_status_t *result = v1_modify_volume_status_create_internal (
        status,
        target_volume_attributes_class_name
        );
    if (!result) {
    }
    return result;
}

void v1_modify_volume_status_free(v1_modify_volume_status_t *v1_modify_volume_status) {
    if(NULL == v1_modify_volume_status){
        return ;
    }
    if(v1_modify_volume_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_modify_volume_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_modify_volume_status->status) {
        free(v1_modify_volume_status->status);
        v1_modify_volume_status->status = NULL;
    }
    if (v1_modify_volume_status->target_volume_attributes_class_name) {
        free(v1_modify_volume_status->target_volume_attributes_class_name);
        v1_modify_volume_status->target_volume_attributes_class_name = NULL;
    }
    free(v1_modify_volume_status);
}

cJSON *v1_modify_volume_status_convertToJSON(v1_modify_volume_status_t *v1_modify_volume_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_modify_volume_status->status
    if (!v1_modify_volume_status->status) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "status", v1_modify_volume_status->status) == NULL) {
    goto fail; //String
    }


    // v1_modify_volume_status->target_volume_attributes_class_name
    if(v1_modify_volume_status->target_volume_attributes_class_name) {
    if(cJSON_AddStringToObject(item, "targetVolumeAttributesClassName", v1_modify_volume_status->target_volume_attributes_class_name) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_modify_volume_status_t *v1_modify_volume_status_parseFromJSON(cJSON *v1_modify_volume_statusJSON){

    v1_modify_volume_status_t *v1_modify_volume_status_local_var = NULL;

    char *status_local_str = NULL;

    char *target_volume_attributes_class_name_local_str = NULL;

    // v1_modify_volume_status->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(v1_modify_volume_statusJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (!status) {
        goto end;
    }

    
    if(!cJSON_IsString(status))
    {
    goto end; //String
    }

    // v1_modify_volume_status->target_volume_attributes_class_name
    cJSON *target_volume_attributes_class_name = cJSON_GetObjectItemCaseSensitive(v1_modify_volume_statusJSON, "targetVolumeAttributesClassName");
    if (cJSON_IsNull(target_volume_attributes_class_name)) {
        target_volume_attributes_class_name = NULL;
    }
    if (target_volume_attributes_class_name) { 
    if(!cJSON_IsString(target_volume_attributes_class_name) && !cJSON_IsNull(target_volume_attributes_class_name))
    {
    goto end; //String
    }
    }


    if (status && !cJSON_IsNull(status)) status_local_str = strdup(status->valuestring);
    if (target_volume_attributes_class_name && !cJSON_IsNull(target_volume_attributes_class_name)) target_volume_attributes_class_name_local_str = strdup(target_volume_attributes_class_name->valuestring);

    v1_modify_volume_status_local_var = v1_modify_volume_status_create_internal (
        status_local_str,
        target_volume_attributes_class_name_local_str
        );

    if (!v1_modify_volume_status_local_var) {
        goto end;
    }

    return v1_modify_volume_status_local_var;
end:
    if (status_local_str) {
        free(status_local_str);
        status_local_str = NULL;
    }
    if (target_volume_attributes_class_name_local_str) {
        free(target_volume_attributes_class_name_local_str);
        target_volume_attributes_class_name_local_str = NULL;
    }
    return NULL;

}
