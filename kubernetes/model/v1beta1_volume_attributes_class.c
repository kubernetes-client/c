#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_volume_attributes_class.h"



v1beta1_volume_attributes_class_t *v1beta1_volume_attributes_class_create(
    char *api_version,
    char *driver_name,
    char *kind,
    v1_object_meta_t *metadata,
    list_t* parameters
    ) {
    v1beta1_volume_attributes_class_t *v1beta1_volume_attributes_class_local_var = malloc(sizeof(v1beta1_volume_attributes_class_t));
    if (!v1beta1_volume_attributes_class_local_var) {
        return NULL;
    }
    v1beta1_volume_attributes_class_local_var->api_version = api_version;
    v1beta1_volume_attributes_class_local_var->driver_name = driver_name;
    v1beta1_volume_attributes_class_local_var->kind = kind;
    v1beta1_volume_attributes_class_local_var->metadata = metadata;
    v1beta1_volume_attributes_class_local_var->parameters = parameters;

    return v1beta1_volume_attributes_class_local_var;
}


void v1beta1_volume_attributes_class_free(v1beta1_volume_attributes_class_t *v1beta1_volume_attributes_class) {
    if(NULL == v1beta1_volume_attributes_class){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_volume_attributes_class->api_version) {
        free(v1beta1_volume_attributes_class->api_version);
        v1beta1_volume_attributes_class->api_version = NULL;
    }
    if (v1beta1_volume_attributes_class->driver_name) {
        free(v1beta1_volume_attributes_class->driver_name);
        v1beta1_volume_attributes_class->driver_name = NULL;
    }
    if (v1beta1_volume_attributes_class->kind) {
        free(v1beta1_volume_attributes_class->kind);
        v1beta1_volume_attributes_class->kind = NULL;
    }
    if (v1beta1_volume_attributes_class->metadata) {
        v1_object_meta_free(v1beta1_volume_attributes_class->metadata);
        v1beta1_volume_attributes_class->metadata = NULL;
    }
    if (v1beta1_volume_attributes_class->parameters) {
        list_ForEach(listEntry, v1beta1_volume_attributes_class->parameters) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1beta1_volume_attributes_class->parameters);
        v1beta1_volume_attributes_class->parameters = NULL;
    }
    free(v1beta1_volume_attributes_class);
}

cJSON *v1beta1_volume_attributes_class_convertToJSON(v1beta1_volume_attributes_class_t *v1beta1_volume_attributes_class) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_volume_attributes_class->api_version
    if(v1beta1_volume_attributes_class->api_version) {
    if(cJSON_AddStringToObject(item, "apiVersion", v1beta1_volume_attributes_class->api_version) == NULL) {
    goto fail; //String
    }
    }


    // v1beta1_volume_attributes_class->driver_name
    if (!v1beta1_volume_attributes_class->driver_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "driverName", v1beta1_volume_attributes_class->driver_name) == NULL) {
    goto fail; //String
    }


    // v1beta1_volume_attributes_class->kind
    if(v1beta1_volume_attributes_class->kind) {
    if(cJSON_AddStringToObject(item, "kind", v1beta1_volume_attributes_class->kind) == NULL) {
    goto fail; //String
    }
    }


    // v1beta1_volume_attributes_class->metadata
    if(v1beta1_volume_attributes_class->metadata) {
    cJSON *metadata_local_JSON = v1_object_meta_convertToJSON(v1beta1_volume_attributes_class->metadata);
    if(metadata_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "metadata", metadata_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // v1beta1_volume_attributes_class->parameters
    if(v1beta1_volume_attributes_class->parameters) {
    cJSON *parameters = cJSON_AddObjectToObject(item, "parameters");
    if(parameters == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = parameters;
    listEntry_t *parametersListEntry;
    if (v1beta1_volume_attributes_class->parameters) {
    list_ForEach(parametersListEntry, v1beta1_volume_attributes_class->parameters) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)parametersListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
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

v1beta1_volume_attributes_class_t *v1beta1_volume_attributes_class_parseFromJSON(cJSON *v1beta1_volume_attributes_classJSON){

    v1beta1_volume_attributes_class_t *v1beta1_volume_attributes_class_local_var = NULL;

    // define the local variable for v1beta1_volume_attributes_class->metadata
    v1_object_meta_t *metadata_local_nonprim = NULL;

    // define the local map for v1beta1_volume_attributes_class->parameters
    list_t *parametersList = NULL;

    // v1beta1_volume_attributes_class->api_version
    cJSON *api_version = cJSON_GetObjectItemCaseSensitive(v1beta1_volume_attributes_classJSON, "apiVersion");
    if (api_version) { 
    if(!cJSON_IsString(api_version) && !cJSON_IsNull(api_version))
    {
    goto end; //String
    }
    }

    // v1beta1_volume_attributes_class->driver_name
    cJSON *driver_name = cJSON_GetObjectItemCaseSensitive(v1beta1_volume_attributes_classJSON, "driverName");
    if (!driver_name) {
        goto end;
    }

    
    if(!cJSON_IsString(driver_name))
    {
    goto end; //String
    }

    // v1beta1_volume_attributes_class->kind
    cJSON *kind = cJSON_GetObjectItemCaseSensitive(v1beta1_volume_attributes_classJSON, "kind");
    if (kind) { 
    if(!cJSON_IsString(kind) && !cJSON_IsNull(kind))
    {
    goto end; //String
    }
    }

    // v1beta1_volume_attributes_class->metadata
    cJSON *metadata = cJSON_GetObjectItemCaseSensitive(v1beta1_volume_attributes_classJSON, "metadata");
    if (metadata) { 
    metadata_local_nonprim = v1_object_meta_parseFromJSON(metadata); //nonprimitive
    }

    // v1beta1_volume_attributes_class->parameters
    cJSON *parameters = cJSON_GetObjectItemCaseSensitive(v1beta1_volume_attributes_classJSON, "parameters");
    if (parameters) { 
    cJSON *parameters_local_map = NULL;
    if(!cJSON_IsObject(parameters) && !cJSON_IsNull(parameters))
    {
        goto end;//primitive map container
    }
    if(cJSON_IsObject(parameters))
    {
        parametersList = list_createList();
        keyValuePair_t *localMapKeyPair;
        cJSON_ArrayForEach(parameters_local_map, parameters)
        {
            cJSON *localMapObject = parameters_local_map;
            if(!cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(parametersList , localMapKeyPair);
        }
    }
    }


    v1beta1_volume_attributes_class_local_var = v1beta1_volume_attributes_class_create (
        api_version && !cJSON_IsNull(api_version) ? strdup(api_version->valuestring) : NULL,
        strdup(driver_name->valuestring),
        kind && !cJSON_IsNull(kind) ? strdup(kind->valuestring) : NULL,
        metadata ? metadata_local_nonprim : NULL,
        parameters ? parametersList : NULL
        );

    return v1beta1_volume_attributes_class_local_var;
end:
    if (metadata_local_nonprim) {
        v1_object_meta_free(metadata_local_nonprim);
        metadata_local_nonprim = NULL;
    }
    if (parametersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, parametersList) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(parametersList);
        parametersList = NULL;
    }
    return NULL;

}
