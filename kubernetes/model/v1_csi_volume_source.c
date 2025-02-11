#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_csi_volume_source.h"



static v1_csi_volume_source_t *v1_csi_volume_source_create_internal(
    char *driver,
    char *fs_type,
    v1_local_object_reference_t *node_publish_secret_ref,
    int read_only,
    list_t* volume_attributes
    ) {
    v1_csi_volume_source_t *v1_csi_volume_source_local_var = malloc(sizeof(v1_csi_volume_source_t));
    if (!v1_csi_volume_source_local_var) {
        return NULL;
    }
    v1_csi_volume_source_local_var->driver = driver;
    v1_csi_volume_source_local_var->fs_type = fs_type;
    v1_csi_volume_source_local_var->node_publish_secret_ref = node_publish_secret_ref;
    v1_csi_volume_source_local_var->read_only = read_only;
    v1_csi_volume_source_local_var->volume_attributes = volume_attributes;

    v1_csi_volume_source_local_var->_library_owned = 1;
    return v1_csi_volume_source_local_var;
}

__attribute__((deprecated)) v1_csi_volume_source_t *v1_csi_volume_source_create(
    char *driver,
    char *fs_type,
    v1_local_object_reference_t *node_publish_secret_ref,
    int read_only,
    list_t* volume_attributes
    ) {
    return v1_csi_volume_source_create_internal (
        driver,
        fs_type,
        node_publish_secret_ref,
        read_only,
        volume_attributes
        );
}

void v1_csi_volume_source_free(v1_csi_volume_source_t *v1_csi_volume_source) {
    if(NULL == v1_csi_volume_source){
        return ;
    }
    if(v1_csi_volume_source->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_csi_volume_source_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_csi_volume_source->driver) {
        free(v1_csi_volume_source->driver);
        v1_csi_volume_source->driver = NULL;
    }
    if (v1_csi_volume_source->fs_type) {
        free(v1_csi_volume_source->fs_type);
        v1_csi_volume_source->fs_type = NULL;
    }
    if (v1_csi_volume_source->node_publish_secret_ref) {
        v1_local_object_reference_free(v1_csi_volume_source->node_publish_secret_ref);
        v1_csi_volume_source->node_publish_secret_ref = NULL;
    }
    if (v1_csi_volume_source->volume_attributes) {
        list_ForEach(listEntry, v1_csi_volume_source->volume_attributes) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_csi_volume_source->volume_attributes);
        v1_csi_volume_source->volume_attributes = NULL;
    }
    free(v1_csi_volume_source);
}

cJSON *v1_csi_volume_source_convertToJSON(v1_csi_volume_source_t *v1_csi_volume_source) {
    cJSON *item = cJSON_CreateObject();

    // v1_csi_volume_source->driver
    if (!v1_csi_volume_source->driver) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "driver", v1_csi_volume_source->driver) == NULL) {
    goto fail; //String
    }


    // v1_csi_volume_source->fs_type
    if(v1_csi_volume_source->fs_type) {
    if(cJSON_AddStringToObject(item, "fsType", v1_csi_volume_source->fs_type) == NULL) {
    goto fail; //String
    }
    }


    // v1_csi_volume_source->node_publish_secret_ref
    if(v1_csi_volume_source->node_publish_secret_ref) {
    cJSON *node_publish_secret_ref_local_JSON = v1_local_object_reference_convertToJSON(v1_csi_volume_source->node_publish_secret_ref);
    if(node_publish_secret_ref_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "nodePublishSecretRef", node_publish_secret_ref_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1_csi_volume_source->read_only
    if(v1_csi_volume_source->read_only) {
    if(cJSON_AddBoolToObject(item, "readOnly", v1_csi_volume_source->read_only) == NULL) {
    goto fail; //Bool
    }
    }


    // v1_csi_volume_source->volume_attributes
    if(v1_csi_volume_source->volume_attributes) {
    cJSON *volume_attributes = cJSON_AddObjectToObject(item, "volumeAttributes");
    if(volume_attributes == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = volume_attributes;
    listEntry_t *volume_attributesListEntry;
    if (v1_csi_volume_source->volume_attributes) {
    list_ForEach(volume_attributesListEntry, v1_csi_volume_source->volume_attributes) {
        keyValuePair_t *localKeyValue = volume_attributesListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, localKeyValue->value) == NULL)
        {
            goto fail;
        }
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

v1_csi_volume_source_t *v1_csi_volume_source_parseFromJSON(cJSON *v1_csi_volume_sourceJSON){

    v1_csi_volume_source_t *v1_csi_volume_source_local_var = NULL;

    // define the local variable for v1_csi_volume_source->node_publish_secret_ref
    v1_local_object_reference_t *node_publish_secret_ref_local_nonprim = NULL;

    // define the local map for v1_csi_volume_source->volume_attributes
    list_t *volume_attributesList = NULL;

    // v1_csi_volume_source->driver
    cJSON *driver = cJSON_GetObjectItemCaseSensitive(v1_csi_volume_sourceJSON, "driver");
    if (cJSON_IsNull(driver)) {
        driver = NULL;
    }
    if (!driver) {
        goto end;
    }

    
    if(!cJSON_IsString(driver))
    {
    goto end; //String
    }

    // v1_csi_volume_source->fs_type
    cJSON *fs_type = cJSON_GetObjectItemCaseSensitive(v1_csi_volume_sourceJSON, "fsType");
    if (cJSON_IsNull(fs_type)) {
        fs_type = NULL;
    }
    if (fs_type) { 
    if(!cJSON_IsString(fs_type) && !cJSON_IsNull(fs_type))
    {
    goto end; //String
    }
    }

    // v1_csi_volume_source->node_publish_secret_ref
    cJSON *node_publish_secret_ref = cJSON_GetObjectItemCaseSensitive(v1_csi_volume_sourceJSON, "nodePublishSecretRef");
    if (cJSON_IsNull(node_publish_secret_ref)) {
        node_publish_secret_ref = NULL;
    }
    if (node_publish_secret_ref) { 
    node_publish_secret_ref_local_nonprim = v1_local_object_reference_parseFromJSON(node_publish_secret_ref); //nonprimitive
    }

    // v1_csi_volume_source->read_only
    cJSON *read_only = cJSON_GetObjectItemCaseSensitive(v1_csi_volume_sourceJSON, "readOnly");
    if (cJSON_IsNull(read_only)) {
        read_only = NULL;
    }
    if (read_only) { 
    if(!cJSON_IsBool(read_only))
    {
    goto end; //Bool
    }
    }

    // v1_csi_volume_source->volume_attributes
    cJSON *volume_attributes = cJSON_GetObjectItemCaseSensitive(v1_csi_volume_sourceJSON, "volumeAttributes");
    if (cJSON_IsNull(volume_attributes)) {
        volume_attributes = NULL;
    }
    if (volume_attributes) { 
    cJSON *volume_attributes_local_map = NULL;
    if(!cJSON_IsObject(volume_attributes) && !cJSON_IsNull(volume_attributes))
    {
        goto end;//primitive map container
    }
    if(cJSON_IsObject(volume_attributes))
    {
        volume_attributesList = list_createList();
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
    }


    v1_csi_volume_source_local_var = v1_csi_volume_source_create_internal (
        strdup(driver->valuestring),
        fs_type && !cJSON_IsNull(fs_type) ? strdup(fs_type->valuestring) : NULL,
        node_publish_secret_ref ? node_publish_secret_ref_local_nonprim : NULL,
        read_only ? read_only->valueint : 0,
        volume_attributes ? volume_attributesList : NULL
        );

    return v1_csi_volume_source_local_var;
end:
    if (node_publish_secret_ref_local_nonprim) {
        v1_local_object_reference_free(node_publish_secret_ref_local_nonprim);
        node_publish_secret_ref_local_nonprim = NULL;
    }
    if (volume_attributesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, volume_attributesList) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(volume_attributesList);
        volume_attributesList = NULL;
    }
    return NULL;

}
