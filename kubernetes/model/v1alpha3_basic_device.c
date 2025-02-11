#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha3_basic_device.h"



static v1alpha3_basic_device_t *v1alpha3_basic_device_create_internal(
    list_t* attributes,
    list_t* capacity
    ) {
    v1alpha3_basic_device_t *v1alpha3_basic_device_local_var = malloc(sizeof(v1alpha3_basic_device_t));
    if (!v1alpha3_basic_device_local_var) {
        return NULL;
    }
    v1alpha3_basic_device_local_var->attributes = attributes;
    v1alpha3_basic_device_local_var->capacity = capacity;

    v1alpha3_basic_device_local_var->_library_owned = 1;
    return v1alpha3_basic_device_local_var;
}

__attribute__((deprecated)) v1alpha3_basic_device_t *v1alpha3_basic_device_create(
    list_t* attributes,
    list_t* capacity
    ) {
    return v1alpha3_basic_device_create_internal (
        attributes,
        capacity
        );
}

void v1alpha3_basic_device_free(v1alpha3_basic_device_t *v1alpha3_basic_device) {
    if(NULL == v1alpha3_basic_device){
        return ;
    }
    if(v1alpha3_basic_device->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1alpha3_basic_device_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha3_basic_device->attributes) {
        list_ForEach(listEntry, v1alpha3_basic_device->attributes) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1alpha3_basic_device->attributes);
        v1alpha3_basic_device->attributes = NULL;
    }
    if (v1alpha3_basic_device->capacity) {
        list_ForEach(listEntry, v1alpha3_basic_device->capacity) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1alpha3_basic_device->capacity);
        v1alpha3_basic_device->capacity = NULL;
    }
    free(v1alpha3_basic_device);
}

cJSON *v1alpha3_basic_device_convertToJSON(v1alpha3_basic_device_t *v1alpha3_basic_device) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha3_basic_device->attributes
    if(v1alpha3_basic_device->attributes) {
    cJSON *attributes = cJSON_AddObjectToObject(item, "attributes");
    if(attributes == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = attributes;
    listEntry_t *attributesListEntry;
    if (v1alpha3_basic_device->attributes) {
    list_ForEach(attributesListEntry, v1alpha3_basic_device->attributes) {
        keyValuePair_t *localKeyValue = attributesListEntry->data;
    }
    }
    }


    // v1alpha3_basic_device->capacity
    if(v1alpha3_basic_device->capacity) {
    cJSON *capacity = cJSON_AddObjectToObject(item, "capacity");
    if(capacity == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = capacity;
    listEntry_t *capacityListEntry;
    if (v1alpha3_basic_device->capacity) {
    list_ForEach(capacityListEntry, v1alpha3_basic_device->capacity) {
        keyValuePair_t *localKeyValue = capacityListEntry->data;
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

v1alpha3_basic_device_t *v1alpha3_basic_device_parseFromJSON(cJSON *v1alpha3_basic_deviceJSON){

    v1alpha3_basic_device_t *v1alpha3_basic_device_local_var = NULL;

    // define the local map for v1alpha3_basic_device->attributes
    list_t *attributesList = NULL;

    // define the local map for v1alpha3_basic_device->capacity
    list_t *capacityList = NULL;

    // v1alpha3_basic_device->attributes
    cJSON *attributes = cJSON_GetObjectItemCaseSensitive(v1alpha3_basic_deviceJSON, "attributes");
    if (cJSON_IsNull(attributes)) {
        attributes = NULL;
    }
    if (attributes) { 

    // The data type of the elements in v1alpha3_basic_device->attributes is currently not supported.

    }

    // v1alpha3_basic_device->capacity
    cJSON *capacity = cJSON_GetObjectItemCaseSensitive(v1alpha3_basic_deviceJSON, "capacity");
    if (cJSON_IsNull(capacity)) {
        capacity = NULL;
    }
    if (capacity) { 
    cJSON *capacity_local_map = NULL;
    if(!cJSON_IsObject(capacity) && !cJSON_IsNull(capacity))
    {
        goto end;//primitive map container
    }
    if(cJSON_IsObject(capacity))
    {
        capacityList = list_createList();
        keyValuePair_t *localMapKeyPair;
        cJSON_ArrayForEach(capacity_local_map, capacity)
        {
            cJSON *localMapObject = capacity_local_map;
            if(!cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(capacityList , localMapKeyPair);
        }
    }
    }


    v1alpha3_basic_device_local_var = v1alpha3_basic_device_create_internal (
        attributes ? attributesList : NULL,
        capacity ? capacityList : NULL
        );

    return v1alpha3_basic_device_local_var;
end:

    // The data type of the elements in v1alpha3_basic_device->attributes is currently not supported.

    if (capacityList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, capacityList) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(capacityList);
        capacityList = NULL;
    }
    return NULL;

}
