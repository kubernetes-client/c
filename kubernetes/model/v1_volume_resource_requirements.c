#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_volume_resource_requirements.h"



static v1_volume_resource_requirements_t *v1_volume_resource_requirements_create_internal(
    list_t* limits,
    list_t* requests
    ) {
    v1_volume_resource_requirements_t *v1_volume_resource_requirements_local_var = malloc(sizeof(v1_volume_resource_requirements_t));
    if (!v1_volume_resource_requirements_local_var) {
        return NULL;
    }
    v1_volume_resource_requirements_local_var->limits = limits;
    v1_volume_resource_requirements_local_var->requests = requests;

    v1_volume_resource_requirements_local_var->_library_owned = 1;
    return v1_volume_resource_requirements_local_var;
}

__attribute__((deprecated)) v1_volume_resource_requirements_t *v1_volume_resource_requirements_create(
    list_t* limits,
    list_t* requests
    ) {
    return v1_volume_resource_requirements_create_internal (
        limits,
        requests
        );
}

void v1_volume_resource_requirements_free(v1_volume_resource_requirements_t *v1_volume_resource_requirements) {
    if(NULL == v1_volume_resource_requirements){
        return ;
    }
    if(v1_volume_resource_requirements->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_volume_resource_requirements_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_volume_resource_requirements->limits) {
        list_ForEach(listEntry, v1_volume_resource_requirements->limits) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_volume_resource_requirements->limits);
        v1_volume_resource_requirements->limits = NULL;
    }
    if (v1_volume_resource_requirements->requests) {
        list_ForEach(listEntry, v1_volume_resource_requirements->requests) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_volume_resource_requirements->requests);
        v1_volume_resource_requirements->requests = NULL;
    }
    free(v1_volume_resource_requirements);
}

cJSON *v1_volume_resource_requirements_convertToJSON(v1_volume_resource_requirements_t *v1_volume_resource_requirements) {
    cJSON *item = cJSON_CreateObject();

    // v1_volume_resource_requirements->limits
    if(v1_volume_resource_requirements->limits) {
    cJSON *limits = cJSON_AddObjectToObject(item, "limits");
    if(limits == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = limits;
    listEntry_t *limitsListEntry;
    if (v1_volume_resource_requirements->limits) {
    list_ForEach(limitsListEntry, v1_volume_resource_requirements->limits) {
        keyValuePair_t *localKeyValue = limitsListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
    }


    // v1_volume_resource_requirements->requests
    if(v1_volume_resource_requirements->requests) {
    cJSON *requests = cJSON_AddObjectToObject(item, "requests");
    if(requests == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = requests;
    listEntry_t *requestsListEntry;
    if (v1_volume_resource_requirements->requests) {
    list_ForEach(requestsListEntry, v1_volume_resource_requirements->requests) {
        keyValuePair_t *localKeyValue = requestsListEntry->data;
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

v1_volume_resource_requirements_t *v1_volume_resource_requirements_parseFromJSON(cJSON *v1_volume_resource_requirementsJSON){

    v1_volume_resource_requirements_t *v1_volume_resource_requirements_local_var = NULL;

    // define the local map for v1_volume_resource_requirements->limits
    list_t *limitsList = NULL;

    // define the local map for v1_volume_resource_requirements->requests
    list_t *requestsList = NULL;

    // v1_volume_resource_requirements->limits
    cJSON *limits = cJSON_GetObjectItemCaseSensitive(v1_volume_resource_requirementsJSON, "limits");
    if (cJSON_IsNull(limits)) {
        limits = NULL;
    }
    if (limits) { 
    cJSON *limits_local_map = NULL;
    if(!cJSON_IsObject(limits) && !cJSON_IsNull(limits))
    {
        goto end;//primitive map container
    }
    if(cJSON_IsObject(limits))
    {
        limitsList = list_createList();
        keyValuePair_t *localMapKeyPair;
        cJSON_ArrayForEach(limits_local_map, limits)
        {
            cJSON *localMapObject = limits_local_map;
            if(!cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(limitsList , localMapKeyPair);
        }
    }
    }

    // v1_volume_resource_requirements->requests
    cJSON *requests = cJSON_GetObjectItemCaseSensitive(v1_volume_resource_requirementsJSON, "requests");
    if (cJSON_IsNull(requests)) {
        requests = NULL;
    }
    if (requests) { 
    cJSON *requests_local_map = NULL;
    if(!cJSON_IsObject(requests) && !cJSON_IsNull(requests))
    {
        goto end;//primitive map container
    }
    if(cJSON_IsObject(requests))
    {
        requestsList = list_createList();
        keyValuePair_t *localMapKeyPair;
        cJSON_ArrayForEach(requests_local_map, requests)
        {
            cJSON *localMapObject = requests_local_map;
            if(!cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(requestsList , localMapKeyPair);
        }
    }
    }


    v1_volume_resource_requirements_local_var = v1_volume_resource_requirements_create_internal (
        limits ? limitsList : NULL,
        requests ? requestsList : NULL
        );

    return v1_volume_resource_requirements_local_var;
end:
    if (limitsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, limitsList) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(limitsList);
        limitsList = NULL;
    }
    if (requestsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, requestsList) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(requestsList);
        requestsList = NULL;
    }
    return NULL;

}
