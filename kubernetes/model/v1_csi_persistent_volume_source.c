#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_csi_persistent_volume_source.h"



v1_csi_persistent_volume_source_t *v1_csi_persistent_volume_source_create(
    v1_secret_reference_t *controller_expand_secret_ref,
    v1_secret_reference_t *controller_publish_secret_ref,
    char *driver,
    char *fs_type,
    v1_secret_reference_t *node_publish_secret_ref,
    v1_secret_reference_t *node_stage_secret_ref,
    int read_only,
    list_t* volume_attributes,
    char *volume_handle
    ) {
    v1_csi_persistent_volume_source_t *v1_csi_persistent_volume_source_local_var = malloc(sizeof(v1_csi_persistent_volume_source_t));
    if (!v1_csi_persistent_volume_source_local_var) {
        return NULL;
    }
    v1_csi_persistent_volume_source_local_var->controller_expand_secret_ref = controller_expand_secret_ref;
    v1_csi_persistent_volume_source_local_var->controller_publish_secret_ref = controller_publish_secret_ref;
    v1_csi_persistent_volume_source_local_var->driver = driver;
    v1_csi_persistent_volume_source_local_var->fs_type = fs_type;
    v1_csi_persistent_volume_source_local_var->node_publish_secret_ref = node_publish_secret_ref;
    v1_csi_persistent_volume_source_local_var->node_stage_secret_ref = node_stage_secret_ref;
    v1_csi_persistent_volume_source_local_var->read_only = read_only;
    v1_csi_persistent_volume_source_local_var->volume_attributes = volume_attributes;
    v1_csi_persistent_volume_source_local_var->volume_handle = volume_handle;

    return v1_csi_persistent_volume_source_local_var;
}


void v1_csi_persistent_volume_source_free(v1_csi_persistent_volume_source_t *v1_csi_persistent_volume_source) {
    if(NULL == v1_csi_persistent_volume_source){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_csi_persistent_volume_source->controller_expand_secret_ref) {
        v1_secret_reference_free(v1_csi_persistent_volume_source->controller_expand_secret_ref);
        v1_csi_persistent_volume_source->controller_expand_secret_ref = NULL;
    }
    if (v1_csi_persistent_volume_source->controller_publish_secret_ref) {
        v1_secret_reference_free(v1_csi_persistent_volume_source->controller_publish_secret_ref);
        v1_csi_persistent_volume_source->controller_publish_secret_ref = NULL;
    }
    if (v1_csi_persistent_volume_source->driver) {
        free(v1_csi_persistent_volume_source->driver);
        v1_csi_persistent_volume_source->driver = NULL;
    }
    if (v1_csi_persistent_volume_source->fs_type) {
        free(v1_csi_persistent_volume_source->fs_type);
        v1_csi_persistent_volume_source->fs_type = NULL;
    }
    if (v1_csi_persistent_volume_source->node_publish_secret_ref) {
        v1_secret_reference_free(v1_csi_persistent_volume_source->node_publish_secret_ref);
        v1_csi_persistent_volume_source->node_publish_secret_ref = NULL;
    }
    if (v1_csi_persistent_volume_source->node_stage_secret_ref) {
        v1_secret_reference_free(v1_csi_persistent_volume_source->node_stage_secret_ref);
        v1_csi_persistent_volume_source->node_stage_secret_ref = NULL;
    }
    if (v1_csi_persistent_volume_source->volume_attributes) {
        list_ForEach(listEntry, v1_csi_persistent_volume_source->volume_attributes) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_free(v1_csi_persistent_volume_source->volume_attributes);
        v1_csi_persistent_volume_source->volume_attributes = NULL;
    }
    if (v1_csi_persistent_volume_source->volume_handle) {
        free(v1_csi_persistent_volume_source->volume_handle);
        v1_csi_persistent_volume_source->volume_handle = NULL;
    }
    free(v1_csi_persistent_volume_source);
}

cJSON *v1_csi_persistent_volume_source_convertToJSON(v1_csi_persistent_volume_source_t *v1_csi_persistent_volume_source) {
    cJSON *item = cJSON_CreateObject();

    // v1_csi_persistent_volume_source->controller_expand_secret_ref
    if(v1_csi_persistent_volume_source->controller_expand_secret_ref) { 
    cJSON *controller_expand_secret_ref_local_JSON = v1_secret_reference_convertToJSON(v1_csi_persistent_volume_source->controller_expand_secret_ref);
    if(controller_expand_secret_ref_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "controllerExpandSecretRef", controller_expand_secret_ref_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_csi_persistent_volume_source->controller_publish_secret_ref
    if(v1_csi_persistent_volume_source->controller_publish_secret_ref) { 
    cJSON *controller_publish_secret_ref_local_JSON = v1_secret_reference_convertToJSON(v1_csi_persistent_volume_source->controller_publish_secret_ref);
    if(controller_publish_secret_ref_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "controllerPublishSecretRef", controller_publish_secret_ref_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_csi_persistent_volume_source->driver
    if (!v1_csi_persistent_volume_source->driver) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "driver", v1_csi_persistent_volume_source->driver) == NULL) {
    goto fail; //String
    }


    // v1_csi_persistent_volume_source->fs_type
    if(v1_csi_persistent_volume_source->fs_type) { 
    if(cJSON_AddStringToObject(item, "fsType", v1_csi_persistent_volume_source->fs_type) == NULL) {
    goto fail; //String
    }
     } 


    // v1_csi_persistent_volume_source->node_publish_secret_ref
    if(v1_csi_persistent_volume_source->node_publish_secret_ref) { 
    cJSON *node_publish_secret_ref_local_JSON = v1_secret_reference_convertToJSON(v1_csi_persistent_volume_source->node_publish_secret_ref);
    if(node_publish_secret_ref_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "nodePublishSecretRef", node_publish_secret_ref_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_csi_persistent_volume_source->node_stage_secret_ref
    if(v1_csi_persistent_volume_source->node_stage_secret_ref) { 
    cJSON *node_stage_secret_ref_local_JSON = v1_secret_reference_convertToJSON(v1_csi_persistent_volume_source->node_stage_secret_ref);
    if(node_stage_secret_ref_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "nodeStageSecretRef", node_stage_secret_ref_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_csi_persistent_volume_source->read_only
    if(v1_csi_persistent_volume_source->read_only) { 
    if(cJSON_AddBoolToObject(item, "readOnly", v1_csi_persistent_volume_source->read_only) == NULL) {
    goto fail; //Bool
    }
     } 


    // v1_csi_persistent_volume_source->volume_attributes
    if(v1_csi_persistent_volume_source->volume_attributes) { 
    cJSON *volume_attributes = cJSON_AddObjectToObject(item, "volumeAttributes");
    if(volume_attributes == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = volume_attributes;
    listEntry_t *volume_attributesListEntry;
    if (v1_csi_persistent_volume_source->volume_attributes) {
    list_ForEach(volume_attributesListEntry, v1_csi_persistent_volume_source->volume_attributes) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)volume_attributesListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
     } 


    // v1_csi_persistent_volume_source->volume_handle
    if (!v1_csi_persistent_volume_source->volume_handle) {
        goto fail;
    }
    
    if(cJSON_AddStringToObject(item, "volumeHandle", v1_csi_persistent_volume_source->volume_handle) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_csi_persistent_volume_source_t *v1_csi_persistent_volume_source_parseFromJSON(cJSON *v1_csi_persistent_volume_sourceJSON){

    v1_csi_persistent_volume_source_t *v1_csi_persistent_volume_source_local_var = NULL;

    // v1_csi_persistent_volume_source->controller_expand_secret_ref
    cJSON *controller_expand_secret_ref = cJSON_GetObjectItemCaseSensitive(v1_csi_persistent_volume_sourceJSON, "controllerExpandSecretRef");
    v1_secret_reference_t *controller_expand_secret_ref_local_nonprim = NULL;
    if (controller_expand_secret_ref) { 
    controller_expand_secret_ref_local_nonprim = v1_secret_reference_parseFromJSON(controller_expand_secret_ref); //nonprimitive
    }

    // v1_csi_persistent_volume_source->controller_publish_secret_ref
    cJSON *controller_publish_secret_ref = cJSON_GetObjectItemCaseSensitive(v1_csi_persistent_volume_sourceJSON, "controllerPublishSecretRef");
    v1_secret_reference_t *controller_publish_secret_ref_local_nonprim = NULL;
    if (controller_publish_secret_ref) { 
    controller_publish_secret_ref_local_nonprim = v1_secret_reference_parseFromJSON(controller_publish_secret_ref); //nonprimitive
    }

    // v1_csi_persistent_volume_source->driver
    cJSON *driver = cJSON_GetObjectItemCaseSensitive(v1_csi_persistent_volume_sourceJSON, "driver");
    if (!driver) {
        goto end;
    }

    
    if(!cJSON_IsString(driver))
    {
    goto end; //String
    }

    // v1_csi_persistent_volume_source->fs_type
    cJSON *fs_type = cJSON_GetObjectItemCaseSensitive(v1_csi_persistent_volume_sourceJSON, "fsType");
    if (fs_type) { 
    if(!cJSON_IsString(fs_type))
    {
    goto end; //String
    }
    }

    // v1_csi_persistent_volume_source->node_publish_secret_ref
    cJSON *node_publish_secret_ref = cJSON_GetObjectItemCaseSensitive(v1_csi_persistent_volume_sourceJSON, "nodePublishSecretRef");
    v1_secret_reference_t *node_publish_secret_ref_local_nonprim = NULL;
    if (node_publish_secret_ref) { 
    node_publish_secret_ref_local_nonprim = v1_secret_reference_parseFromJSON(node_publish_secret_ref); //nonprimitive
    }

    // v1_csi_persistent_volume_source->node_stage_secret_ref
    cJSON *node_stage_secret_ref = cJSON_GetObjectItemCaseSensitive(v1_csi_persistent_volume_sourceJSON, "nodeStageSecretRef");
    v1_secret_reference_t *node_stage_secret_ref_local_nonprim = NULL;
    if (node_stage_secret_ref) { 
    node_stage_secret_ref_local_nonprim = v1_secret_reference_parseFromJSON(node_stage_secret_ref); //nonprimitive
    }

    // v1_csi_persistent_volume_source->read_only
    cJSON *read_only = cJSON_GetObjectItemCaseSensitive(v1_csi_persistent_volume_sourceJSON, "readOnly");
    if (read_only) { 
    if(!cJSON_IsBool(read_only))
    {
    goto end; //Bool
    }
    }

    // v1_csi_persistent_volume_source->volume_attributes
    cJSON *volume_attributes = cJSON_GetObjectItemCaseSensitive(v1_csi_persistent_volume_sourceJSON, "volumeAttributes");
    list_t *volume_attributesList;
    if (volume_attributes) { 
    cJSON *volume_attributes_local_map;
    if(!cJSON_IsObject(volume_attributes)) {
        goto end;//primitive map container
    }
    volume_attributesList = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(volume_attributes_local_map, volume_attributes)
    {
		cJSON *localMapObject = volume_attributes_local_map;
        if(!cJSON_IsString(localMapObject))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
        list_addElement(volume_attributesList , localMapKeyPair);
    }
    }

    // v1_csi_persistent_volume_source->volume_handle
    cJSON *volume_handle = cJSON_GetObjectItemCaseSensitive(v1_csi_persistent_volume_sourceJSON, "volumeHandle");
    if (!volume_handle) {
        goto end;
    }

    
    if(!cJSON_IsString(volume_handle))
    {
    goto end; //String
    }


    v1_csi_persistent_volume_source_local_var = v1_csi_persistent_volume_source_create (
        controller_expand_secret_ref ? controller_expand_secret_ref_local_nonprim : NULL,
        controller_publish_secret_ref ? controller_publish_secret_ref_local_nonprim : NULL,
        strdup(driver->valuestring),
        fs_type ? strdup(fs_type->valuestring) : NULL,
        node_publish_secret_ref ? node_publish_secret_ref_local_nonprim : NULL,
        node_stage_secret_ref ? node_stage_secret_ref_local_nonprim : NULL,
        read_only ? read_only->valueint : 0,
        volume_attributes ? volume_attributesList : NULL,
        strdup(volume_handle->valuestring)
        );

    return v1_csi_persistent_volume_source_local_var;
end:
    if (controller_expand_secret_ref_local_nonprim) {
        v1_secret_reference_free(controller_expand_secret_ref_local_nonprim);
        controller_expand_secret_ref_local_nonprim = NULL;
    }
    if (controller_publish_secret_ref_local_nonprim) {
        v1_secret_reference_free(controller_publish_secret_ref_local_nonprim);
        controller_publish_secret_ref_local_nonprim = NULL;
    }
    if (node_publish_secret_ref_local_nonprim) {
        v1_secret_reference_free(node_publish_secret_ref_local_nonprim);
        node_publish_secret_ref_local_nonprim = NULL;
    }
    if (node_stage_secret_ref_local_nonprim) {
        v1_secret_reference_free(node_stage_secret_ref_local_nonprim);
        node_stage_secret_ref_local_nonprim = NULL;
    }
    return NULL;

}
