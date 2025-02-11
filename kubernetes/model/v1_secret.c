#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_secret.h"



static v1_secret_t *v1_secret_create_internal(
    char *api_version,
    list_t* data,
    int immutable,
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
    v1_secret_local_var->immutable = immutable;
    v1_secret_local_var->kind = kind;
    v1_secret_local_var->metadata = metadata;
    v1_secret_local_var->string_data = string_data;
    v1_secret_local_var->type = type;

    v1_secret_local_var->_library_owned = 1;
    return v1_secret_local_var;
}

__attribute__((deprecated)) v1_secret_t *v1_secret_create(
    char *api_version,
    list_t* data,
    int immutable,
    char *kind,
    v1_object_meta_t *metadata,
    list_t* string_data,
    char *type
    ) {
    return v1_secret_create_internal (
        api_version,
        data,
        immutable,
        kind,
        metadata,
        string_data,
        type
        );
}

void v1_secret_free(v1_secret_t *v1_secret) {
    if(NULL == v1_secret){
        return ;
    }
    if(v1_secret->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_secret_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_secret->api_version) {
        free(v1_secret->api_version);
        v1_secret->api_version = NULL;
    }
    if (v1_secret->data) {
        list_ForEach(listEntry, v1_secret->data) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_secret->data);
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
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_secret->string_data);
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
        keyValuePair_t *localKeyValue = dataListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
    }


    // v1_secret->immutable
    if(v1_secret->immutable) {
    if(cJSON_AddBoolToObject(item, "immutable", v1_secret->immutable) == NULL) {
    goto fail; //Bool
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
        keyValuePair_t *localKeyValue = string_dataListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, localKeyValue->value) == NULL)
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

    // define the local map for v1_secret->data
    list_t *dataList = NULL;

    // define the local variable for v1_secret->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local map for v1_secret->string_data
    list_t *string_dataList = NULL;

    // v1_secret->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1_secretJSON, "apiVersion");
    if (cJSON_IsNull(api_version)) {
        api_version = NULL;
    }
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1_secret->data
    cJSON *data = cJSON_GetObjectItemCaseSensitive(v1_secretJSON, "data");
    if (cJSON_IsNull(data)) {
        data = NULL;
    }
    if (data) { 
    cJSON *data_local_map = NULL;
    if(!cJSON_IsObject(data) && !cJSON_IsNull(data))
    {
        goto end;//primitive map container
    }
    if(cJSON_IsObject(data))
    {
        dataList = list_createList();
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
    }

    // v1_secret->immutable
    cJSON *immutable = cJSON_GetObjectItemCaseSensitive(v1_secretJSON, "immutable");
    if (cJSON_IsNull(immutable)) {
        immutable = NULL;
    }
    if (immutable) { 
    if(!cJSON_IsBool(immutable))
    {
    goto end; //Bool
    }
    }

    // v1_secret->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1_secretJSON, "kind");
    if (cJSON_IsNull(kind)) {
        kind = NULL;
    }
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1_secret->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1_secretJSON, "metadata");
    if (cJSON_IsNull(metadata)) {
        metadata = NULL;
    }
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1_secret->string_data
    cJSON *string_data = cJSON_GetObjectItemCaseSensitive(v1_secretJSON, "stringData");
    if (cJSON_IsNull(string_data)) {
        string_data = NULL;
    }
    if (string_data) { 
    cJSON *string_data_local_map = NULL;
    if(!cJSON_IsObject(string_data) && !cJSON_IsNull(string_data))
    {
        goto end;//primitive map container
    }
    if(cJSON_IsObject(string_data))
    {
        string_dataList = list_createList();
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
    }

    // v1_secret->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1_secretJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }


    v1_secret_local_var = v1_secret_create_internal (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        data ? dataList : NULL,
        immutable ? immutable->valueint : 0,
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        string_data ? string_dataList : NULL,
        type && !cJSON_IsNull(type) ? strdup(type->valuestring) : NULL
        );

    return v1_secret_local_var;
end:
    if (dataList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, dataList) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(dataList);
        dataList = NULL;
    }
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (string_dataList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, string_dataList) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(string_dataList);
        string_dataList = NULL;
    }
    return NULL;

}
