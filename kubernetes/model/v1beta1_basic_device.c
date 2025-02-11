#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_basic_device.h"



static v1beta1_basic_device_t *v1beta1_basic_device_create_internal(
    list_t* attributes,
    list_t* capacity
    ) {
    v1beta1_basic_device_t *v1beta1_basic_device_local_var = malloc(sizeof(v1beta1_basic_device_t));
    if (!v1beta1_basic_device_local_var) {
        return NULL;
    }
    v1beta1_basic_device_local_var->attributes = attributes;
    v1beta1_basic_device_local_var->capacity = capacity;

    v1beta1_basic_device_local_var->_library_owned = 1;
    return v1beta1_basic_device_local_var;
}

__attribute__((deprecated)) v1beta1_basic_device_t *v1beta1_basic_device_create(
    list_t* attributes,
    list_t* capacity
    ) {
    return v1beta1_basic_device_create_internal (
        attributes,
        capacity
        );
}

void v1beta1_basic_device_free(v1beta1_basic_device_t *v1beta1_basic_device) {
    if(NULL == v1beta1_basic_device){
        return ;
    }
    if(v1beta1_basic_device->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta1_basic_device_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_basic_device->attributes) {
        list_ForEach(listEntry, v1beta1_basic_device->attributes) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1beta1_basic_device->attributes);
        v1beta1_basic_device->attributes = NULL;
    }
    if (v1beta1_basic_device->capacity) {
        list_ForEach(listEntry, v1beta1_basic_device->capacity) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1beta1_basic_device->capacity);
        v1beta1_basic_device->capacity = NULL;
    }
    free(v1beta1_basic_device);
}

cJSON *v1beta1_basic_device_convertToJSON(v1beta1_basic_device_t *v1beta1_basic_device) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_basic_device->attributes
    if(v1beta1_basic_device->attributes) {
    cJSON *attributes = cJSON_AddObjectToObject(item, "attributes");
    if(attributes == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = attributes;
    listEntry_t *attributesListEntry;
    if (v1beta1_basic_device->attributes) {
    list_ForEach(attributesListEntry, v1beta1_basic_device->attributes) {
        keyValuePair_t *localKeyValue = attributesListEntry->data;
    }
    }
    }


    // v1beta1_basic_device->capacity
    if(v1beta1_basic_device->capacity) {
    cJSON *capacity = cJSON_AddObjectToObject(item, "capacity");
    if(capacity == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = capacity;
    listEntry_t *capacityListEntry;
    if (v1beta1_basic_device->capacity) {
    list_ForEach(capacityListEntry, v1beta1_basic_device->capacity) {
        keyValuePair_t *localKeyValue = capacityListEntry->data;
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

v1beta1_basic_device_t *v1beta1_basic_device_parseFromJSON(cJSON *v1beta1_basic_deviceJSON){

    v1beta1_basic_device_t *v1beta1_basic_device_local_var = NULL;

    // define the local map for v1beta1_basic_device->attributes
    list_t *attributesList = NULL;

    // define the local map for v1beta1_basic_device->capacity
    list_t *capacityList = NULL;

    // v1beta1_basic_device->attributes
    cJSON *attributes = cJSON_GetObjectItemCaseSensitive(v1beta1_basic_deviceJSON, "attributes");
    if (cJSON_IsNull(attributes)) {
        attributes = NULL;
    }
    if (attributes) { 

    // The data type of the elements in v1beta1_basic_device->attributes is currently not supported.

    }

    // v1beta1_basic_device->capacity
    cJSON *capacity = cJSON_GetObjectItemCaseSensitive(v1beta1_basic_deviceJSON, "capacity");
    if (cJSON_IsNull(capacity)) {
        capacity = NULL;
    }
    if (capacity) { 

    // The data type of the elements in v1beta1_basic_device->capacity is currently not supported.

    }


    v1beta1_basic_device_local_var = v1beta1_basic_device_create_internal (
        attributes ? attributesList : NULL,
        capacity ? capacityList : NULL
        );

    return v1beta1_basic_device_local_var;
end:

    // The data type of the elements in v1beta1_basic_device->attributes is currently not supported.


    // The data type of the elements in v1beta1_basic_device->capacity is currently not supported.

    return NULL;

}
