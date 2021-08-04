#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_config_map.h"



v1_config_map_t *v1_config_map_create(
    char *api_version,
    list_t* binary_data,
    list_t* data,
    char *kind,
    v1_object_meta_t *metadata
    ) {
    v1_config_map_t *v1_config_map_local_var = malloc(sizeof(v1_config_map_t));
    if (!v1_config_map_local_var) {
        return NULL;
    }
    v1_config_map_local_var->api_version = api_version;
    v1_config_map_local_var->binary_data = binary_data;
    v1_config_map_local_var->data = data;
    v1_config_map_local_var->kind = kind;
    v1_config_map_local_var->metadata = metadata;

    return v1_config_map_local_var;
}


void v1_config_map_free(v1_config_map_t *v1_config_map) {
    if(NULL == v1_config_map){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_config_map->api_version) {
        free(v1_config_map->api_version);
        v1_config_map->api_version = NULL;
    }
    if (v1_config_map->binary_data) {
        list_ForEach(listEntry, v1_config_map->binary_data) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_free(v1_config_map->binary_data);
        v1_config_map->binary_data = NULL;
    }
    if (v1_config_map->data) {
        list_ForEach(listEntry, v1_config_map->data) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_free(v1_config_map->data);
        v1_config_map->data = NULL;
    }
    if (v1_config_map->kind) {
        free(v1_config_map->kind);
        v1_config_map->kind = NULL;
    }
    if (v1_config_map->metadata) {
        v1_object_meta_free(v1_config_map->metadata);
        v1_config_map->metadata = NULL;
    }
    free(v1_config_map);
}

cJSON *v1_config_map_convertToJSON(v1_config_map_t *v1_config_map) {
    cJSON *item = cJSON_CreateObject();

    // v1_config_map->api_version
    if(v1_config_map->api_version) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_config_map->api_version) == NULL) {
    goto fail; //String
    }
     } 


    // v1_config_map->binary_data
    if(v1_config_map->binary_data) { 
    cJSON *binary_data = cJSON_AddObjectToObject(item, "binaryData");
    if(binary_data == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = binary_data;
    listEntry_t *binary_dataListEntry;
    if (v1_config_map->binary_data) {
    list_ForEach(binary_dataListEntry, v1_config_map->binary_data) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)binary_dataListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
     } 


    // v1_config_map->data
    if(v1_config_map->data) { 
    cJSON *data = cJSON_AddObjectToObject(item, "data");
    if(data == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = data;
    listEntry_t *dataListEntry;
    if (v1_config_map->data) {
    list_ForEach(dataListEntry, v1_config_map->data) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)dataListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
     } 


    // v1_config_map->kind
    if(v1_config_map->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_config_map->kind) == NULL) {
    goto fail; //String
    }
     } 


    // v1_config_map->metadata
    if(v1_config_map->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_config_map->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
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

v1_config_map_t *v1_config_map_parseFromJSON(cJSON *v1_config_mapJSON){

    v1_config_map_t *v1_config_map_local_var = NULL;

    // v1_config_map->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_config_mapJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // v1_config_map->binary_data
    cJSON *binary_data = cJSON_GetObjectItemCaseSensitive(v1_config_mapJSON, "binaryData");
    list_t *binary_dataList;
    if (binary_data) { 
    cJSON *binary_data_local_map;
    if(!cJSON_IsObject(binary_data)) {
        goto end;//primitive map container
    }
    binary_dataList = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(binary_data_local_map, binary_data)
    {
		cJSON *localMapObject = binary_data_local_map;
        if(!cJSON_IsString(localMapObject))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
        list_addElement(binary_dataList , localMapKeyPair);
    }
    }

    // v1_config_map->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(v1_config_mapJSON, "data");
    list_t *dataList;
    if (data) { 
    cJSON *data_local_map;
    if(!cJSON_IsObject(data)) {
        goto end;//primitive map container
    }
    dataList = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(data_local_map, data)
    {
		cJSON *localMapObject = data_local_map;
        if(!cJSON_IsString(localMapObject))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
        list_addElement(dataList , localMapKeyPair);
    }
    }

    // v1_config_map->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_config_mapJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_config_map->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_config_mapJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }


    v1_config_map_local_var = v1_config_map_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        binary_data ? binary_dataList : NULL,
        data ? dataList : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL
        );

    return v1_config_map_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    return NULL;

}
