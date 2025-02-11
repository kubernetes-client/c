#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_resource_quota_status.h"



static v1_resource_quota_status_t *v1_resource_quota_status_create_internal(
    list_t* hard,
    list_t* used
    ) {
    v1_resource_quota_status_t *v1_resource_quota_status_local_var = malloc(sizeof(v1_resource_quota_status_t));
    if (!v1_resource_quota_status_local_var) {
        return NULL;
    }
    v1_resource_quota_status_local_var->hard = hard;
    v1_resource_quota_status_local_var->used = used;

    v1_resource_quota_status_local_var->_library_owned = 1;
    return v1_resource_quota_status_local_var;
}

__attribute__((deprecated)) v1_resource_quota_status_t *v1_resource_quota_status_create(
    list_t* hard,
    list_t* used
    ) {
    return v1_resource_quota_status_create_internal (
        hard,
        used
        );
}

void v1_resource_quota_status_free(v1_resource_quota_status_t *v1_resource_quota_status) {
    if(NULL == v1_resource_quota_status){
        return ;
    }
    if(v1_resource_quota_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_resource_quota_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_resource_quota_status->hard) {
        list_ForEach(listEntry, v1_resource_quota_status->hard) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_resource_quota_status->hard);
        v1_resource_quota_status->hard = NULL;
    }
    if (v1_resource_quota_status->used) {
        list_ForEach(listEntry, v1_resource_quota_status->used) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_resource_quota_status->used);
        v1_resource_quota_status->used = NULL;
    }
    free(v1_resource_quota_status);
}

cJSON *v1_resource_quota_status_convertToJSON(v1_resource_quota_status_t *v1_resource_quota_status) {
    cJSON *item = cJSON_CreateObject();

    // v1_resource_quota_status->hard
    if(v1_resource_quota_status->hard) {
    cJSON *hard = cJSON_AddObjectToObject(item, "hard");
    if(hard == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = hard;
    listEntry_t *hardListEntry;
    if (v1_resource_quota_status->hard) {
    list_ForEach(hardListEntry, v1_resource_quota_status->hard) {
        keyValuePair_t *localKeyValue = hardListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
    }


    // v1_resource_quota_status->used
    if(v1_resource_quota_status->used) {
    cJSON *used = cJSON_AddObjectToObject(item, "used");
    if(used == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = used;
    listEntry_t *usedListEntry;
    if (v1_resource_quota_status->used) {
    list_ForEach(usedListEntry, v1_resource_quota_status->used) {
        keyValuePair_t *localKeyValue = usedListEntry->data;
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

v1_resource_quota_status_t *v1_resource_quota_status_parseFromJSON(cJSON *v1_resource_quota_statusJSON){

    v1_resource_quota_status_t *v1_resource_quota_status_local_var = NULL;

    // define the local map for v1_resource_quota_status->hard
    list_t *hardList = NULL;

    // define the local map for v1_resource_quota_status->used
    list_t *usedList = NULL;

    // v1_resource_quota_status->hard
    cJSON *hard = cJSON_GetObjectItemCaseSensitive(v1_resource_quota_statusJSON, "hard");
    if (cJSON_IsNull(hard)) {
        hard = NULL;
    }
    if (hard) { 
    cJSON *hard_local_map = NULL;
    if(!cJSON_IsObject(hard) && !cJSON_IsNull(hard))
    {
        goto end;//primitive map container
    }
    if(cJSON_IsObject(hard))
    {
        hardList = list_createList();
        keyValuePair_t *localMapKeyPair;
        cJSON_ArrayForEach(hard_local_map, hard)
        {
            cJSON *localMapObject = hard_local_map;
            if(!cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(hardList , localMapKeyPair);
        }
    }
    }

    // v1_resource_quota_status->used
    cJSON *used = cJSON_GetObjectItemCaseSensitive(v1_resource_quota_statusJSON, "used");
    if (cJSON_IsNull(used)) {
        used = NULL;
    }
    if (used) { 
    cJSON *used_local_map = NULL;
    if(!cJSON_IsObject(used) && !cJSON_IsNull(used))
    {
        goto end;//primitive map container
    }
    if(cJSON_IsObject(used))
    {
        usedList = list_createList();
        keyValuePair_t *localMapKeyPair;
        cJSON_ArrayForEach(used_local_map, used)
        {
            cJSON *localMapObject = used_local_map;
            if(!cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(usedList , localMapKeyPair);
        }
    }
    }


    v1_resource_quota_status_local_var = v1_resource_quota_status_create_internal (
        hard ? hardList : NULL,
        used ? usedList : NULL
        );

    return v1_resource_quota_status_local_var;
end:
    if (hardList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, hardList) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(hardList);
        hardList = NULL;
    }
    if (usedList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, usedList) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(usedList);
        usedList = NULL;
    }
    return NULL;

}
