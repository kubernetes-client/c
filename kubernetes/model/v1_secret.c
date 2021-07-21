#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_secret.h"



v1_secret_t *v1_secret_create(
    char *api_version,
    list_t* data,
    char *kind,
    v1_object_meta_t *metadata,
    list_t* string_data,
    char *type
    ) {
    v1_secret_t *v1_secret_local_var = malloc(sizeof(v1_secret_t));
    if (!v1_secret_local_var) {
        return NULL;
    }
    v1_secret_local_var->api_version = api_version;
    v1_secret_local_var->data = data;
    v1_secret_local_var->kind = kind;
    v1_secret_local_var->metadata = metadata;
    v1_secret_local_var->string_data = string_data;
    v1_secret_local_var->type = type;

    return v1_secret_local_var;
}


void v1_secret_free(v1_secret_t *v1_secret) {
    if(NULL == v1_secret){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_secret->api_version) {
        free(v1_secret->api_version);
        v1_secret->api_version = NULL;
    }
    if (v1_secret->data) {
        list_ForEach(listEntry, v1_secret->data) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_free(v1_secret->data);
        v1_secret->data = NULL;
    }
    if (v1_secret->kind) {
        free(v1_secret->kind);
        v1_secret->kind = NULL;
    }
    if (v1_secret->metadata) {
        v1_object_meta_free(v1_secret->metadata);
        v1_secret->metadata = NULL;
    }
    if (v1_secret->string_data) {
        list_ForEach(listEntry, v1_secret->string_data) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_free(v1_secret->string_data);
        v1_secret->string_data = NULL;
    }
    if (v1_secret->type) {
        free(v1_secret->type);
        v1_secret->type = NULL;
    }
    free(v1_secret);
}

cJSON *v1_secret_convertToJSON(v1_secret_t *v1_secret) {
    cJSON *item = cJSON_CreateObject();

    // v1_secret->api_version
    if(v1_secret->api_version) { 
    if(cJSON_AddStringToObject(item, "apiVersion", v1_secret->api_version) == NULL) {
    goto fail; //String
    }
     } 


    // v1_secret->data
    if(v1_secret->data) { 
    cJSON *data = cJSON_AddObjectToObject(item, "data");
    if(data == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = data;
    listEntry_t *dataListEntry;
    if (v1_secret->data) {
    list_ForEach(dataListEntry, v1_secret->data) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)dataListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
     } 


    // v1_secret->kind
    if(v1_secret->kind) { 
    if(cJSON_AddStringToObject(item, "kind", v1_secret->kind) == NULL) {
    goto fail; //String
    }
     } 


    // v1_secret->metadata
    if(v1_secret->metadata) { 
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1_secret->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
     } 


    // v1_secret->string_data
    if(v1_secret->string_data) { 
    cJSON *string_data = cJSON_AddObjectToObject(item, "stringData");
    if(string_data == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = string_data;
    listEntry_t *string_dataListEntry;
    if (v1_secret->string_data) {
    list_ForEach(string_dataListEntry, v1_secret->string_data) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)string_dataListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
     } 


    // v1_secret->type
    if(v1_secret->type) { 
    if(cJSON_AddStringToObject(item, "type", v1_secret->type) == NULL) {
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

v1_secret_t *v1_secret_parseFromJSON(cJSON *v1_secretJSON){

    v1_secret_t *v1_secret_local_var = NULL;

    // v1_secret->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_secretJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version))
    {
    goto end; //String
    }
    }

    // v1_secret->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(v1_secretJSON, "data");
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

    // v1_secret->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_secretJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind))
    {
    goto end; //String
    }
    }

    // v1_secret->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_secretJSON, "metadata");
    v1_object_meta_t *metadata_local_nonprim = NULL;
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_secret->string_data
    cJSON *string_data = cJSON_GetObjectItemCaseSensitive(v1_secretJSON, "stringData");
    list_t *string_dataList;
    if (string_data) { 
    cJSON *string_data_local_map;
    if(!cJSON_IsObject(string_data)) {
        goto end;//primitive map container
    }
    string_dataList = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(string_data_local_map, string_data)
    {
		cJSON *localMapObject = string_data_local_map;
        if(!cJSON_IsString(localMapObject))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
        list_addElement(string_dataList , localMapKeyPair);
    }
    }

    // v1_secret->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1_secretJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }
    }


    v1_secret_local_var = v1_secret_create (
        api_version ? strdup(api_version->valuestring) : NULL,
        data ? dataList : NULL,
        kind ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        string_data ? string_dataList : NULL,
        type ? strdup(type->valuestring) : NULL
        );

    return v1_secret_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    return NULL;

}
