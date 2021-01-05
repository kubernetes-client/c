#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_limit_range_item.h"



v1_limit_range_item_t *v1_limit_range_item_create(
    list_t* _default,
    list_t* default_request,
    list_t* max,
    list_t* max_limit_request_ratio,
    list_t* min,
    char *type
    ) {
    v1_limit_range_item_t *v1_limit_range_item_local_var = malloc(sizeof(v1_limit_range_item_t));
    if (!v1_limit_range_item_local_var) {
        return NULL;
    }
    v1_limit_range_item_local_var->_default = _default;
    v1_limit_range_item_local_var->default_request = default_request;
    v1_limit_range_item_local_var->max = max;
    v1_limit_range_item_local_var->max_limit_request_ratio = max_limit_request_ratio;
    v1_limit_range_item_local_var->min = min;
    v1_limit_range_item_local_var->type = type;

    return v1_limit_range_item_local_var;
}


void v1_limit_range_item_free(v1_limit_range_item_t *v1_limit_range_item) {
    if(NULL == v1_limit_range_item){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_limit_range_item->_default) {
        list_ForEach(listEntry, v1_limit_range_item->_default) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_free(v1_limit_range_item->_default);
        v1_limit_range_item->_default = NULL;
    }
    if (v1_limit_range_item->default_request) {
        list_ForEach(listEntry, v1_limit_range_item->default_request) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_free(v1_limit_range_item->default_request);
        v1_limit_range_item->default_request = NULL;
    }
    if (v1_limit_range_item->max) {
        list_ForEach(listEntry, v1_limit_range_item->max) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_free(v1_limit_range_item->max);
        v1_limit_range_item->max = NULL;
    }
    if (v1_limit_range_item->max_limit_request_ratio) {
        list_ForEach(listEntry, v1_limit_range_item->max_limit_request_ratio) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_free(v1_limit_range_item->max_limit_request_ratio);
        v1_limit_range_item->max_limit_request_ratio = NULL;
    }
    if (v1_limit_range_item->min) {
        list_ForEach(listEntry, v1_limit_range_item->min) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_free(v1_limit_range_item->min);
        v1_limit_range_item->min = NULL;
    }
    if (v1_limit_range_item->type) {
        free(v1_limit_range_item->type);
        v1_limit_range_item->type = NULL;
    }
    free(v1_limit_range_item);
}

cJSON *v1_limit_range_item_convertToJSON(v1_limit_range_item_t *v1_limit_range_item) {
    cJSON *item = cJSON_CreateObject();

    // v1_limit_range_item->_default
    if(v1_limit_range_item->_default) { 
    cJSON *_default = cJSON_AddObjectToObject(item, "default");
    if(_default == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = _default;
    listEntry_t *_defaultListEntry;
    if (v1_limit_range_item->_default) {
    list_ForEach(_defaultListEntry, v1_limit_range_item->_default) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)_defaultListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
     } 


    // v1_limit_range_item->default_request
    if(v1_limit_range_item->default_request) { 
    cJSON *default_request = cJSON_AddObjectToObject(item, "defaultRequest");
    if(default_request == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = default_request;
    listEntry_t *default_requestListEntry;
    if (v1_limit_range_item->default_request) {
    list_ForEach(default_requestListEntry, v1_limit_range_item->default_request) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)default_requestListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
     } 


    // v1_limit_range_item->max
    if(v1_limit_range_item->max) { 
    cJSON *max = cJSON_AddObjectToObject(item, "max");
    if(max == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = max;
    listEntry_t *maxListEntry;
    if (v1_limit_range_item->max) {
    list_ForEach(maxListEntry, v1_limit_range_item->max) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)maxListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
     } 


    // v1_limit_range_item->max_limit_request_ratio
    if(v1_limit_range_item->max_limit_request_ratio) { 
    cJSON *max_limit_request_ratio = cJSON_AddObjectToObject(item, "maxLimitRequestRatio");
    if(max_limit_request_ratio == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = max_limit_request_ratio;
    listEntry_t *max_limit_request_ratioListEntry;
    if (v1_limit_range_item->max_limit_request_ratio) {
    list_ForEach(max_limit_request_ratioListEntry, v1_limit_range_item->max_limit_request_ratio) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)max_limit_request_ratioListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
     } 


    // v1_limit_range_item->min
    if(v1_limit_range_item->min) { 
    cJSON *min = cJSON_AddObjectToObject(item, "min");
    if(min == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = min;
    listEntry_t *minListEntry;
    if (v1_limit_range_item->min) {
    list_ForEach(minListEntry, v1_limit_range_item->min) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)minListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
     } 


    // v1_limit_range_item->type
    if(v1_limit_range_item->type) { 
    if(cJSON_AddStringToObject(item, "type", v1_limit_range_item->type) == NULL) {
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

v1_limit_range_item_t *v1_limit_range_item_parseFromJSON(cJSON *v1_limit_range_itemJSON){

    v1_limit_range_item_t *v1_limit_range_item_local_var = NULL;

    // v1_limit_range_item->_default
    cJSON *_default = cJSON_GetObjectItemCaseSensitive(v1_limit_range_itemJSON, "default");
    list_t *_defaultList;
    if (_default) { 
    cJSON *_default_local_map;
    if(!cJSON_IsObject(_default)) {
        goto end;//primitive map container
    }
    _defaultList = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(_default_local_map, _default)
    {
		cJSON *localMapObject = _default_local_map;
        if(!cJSON_IsString(localMapObject))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
        list_addElement(_defaultList , localMapKeyPair);
    }
    }

    // v1_limit_range_item->default_request
    cJSON *default_request = cJSON_GetObjectItemCaseSensitive(v1_limit_range_itemJSON, "defaultRequest");
    list_t *default_requestList;
    if (default_request) { 
    cJSON *default_request_local_map;
    if(!cJSON_IsObject(default_request)) {
        goto end;//primitive map container
    }
    default_requestList = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(default_request_local_map, default_request)
    {
		cJSON *localMapObject = default_request_local_map;
        if(!cJSON_IsString(localMapObject))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
        list_addElement(default_requestList , localMapKeyPair);
    }
    }

    // v1_limit_range_item->max
    cJSON *max = cJSON_GetObjectItemCaseSensitive(v1_limit_range_itemJSON, "max");
    list_t *maxList;
    if (max) { 
    cJSON *max_local_map;
    if(!cJSON_IsObject(max)) {
        goto end;//primitive map container
    }
    maxList = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(max_local_map, max)
    {
		cJSON *localMapObject = max_local_map;
        if(!cJSON_IsString(localMapObject))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
        list_addElement(maxList , localMapKeyPair);
    }
    }

    // v1_limit_range_item->max_limit_request_ratio
    cJSON *max_limit_request_ratio = cJSON_GetObjectItemCaseSensitive(v1_limit_range_itemJSON, "maxLimitRequestRatio");
    list_t *max_limit_request_ratioList;
    if (max_limit_request_ratio) { 
    cJSON *max_limit_request_ratio_local_map;
    if(!cJSON_IsObject(max_limit_request_ratio)) {
        goto end;//primitive map container
    }
    max_limit_request_ratioList = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(max_limit_request_ratio_local_map, max_limit_request_ratio)
    {
		cJSON *localMapObject = max_limit_request_ratio_local_map;
        if(!cJSON_IsString(localMapObject))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
        list_addElement(max_limit_request_ratioList , localMapKeyPair);
    }
    }

    // v1_limit_range_item->min
    cJSON *min = cJSON_GetObjectItemCaseSensitive(v1_limit_range_itemJSON, "min");
    list_t *minList;
    if (min) { 
    cJSON *min_local_map;
    if(!cJSON_IsObject(min)) {
        goto end;//primitive map container
    }
    minList = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(min_local_map, min)
    {
		cJSON *localMapObject = min_local_map;
        if(!cJSON_IsString(localMapObject))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
        list_addElement(minList , localMapKeyPair);
    }
    }

    // v1_limit_range_item->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(v1_limit_range_itemJSON, "type");
    if (type) { 
    if(!cJSON_IsString(type))
    {
    goto end; //String
    }
    }


    v1_limit_range_item_local_var = v1_limit_range_item_create (
        _default ? _defaultList : NULL,
        default_request ? default_requestList : NULL,
        max ? maxList : NULL,
        max_limit_request_ratio ? max_limit_request_ratioList : NULL,
        min ? minList : NULL,
        type ? strdup(type->valuestring) : NULL
        );

    return v1_limit_range_item_local_var;
end:
    return NULL;

}
