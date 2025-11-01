#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_capacity_requirements.h"



static v1beta2_capacity_requirements_t *v1beta2_capacity_requirements_create_internal(
    list_t* requests
    ) {
    v1beta2_capacity_requirements_t *v1beta2_capacity_requirements_local_var = malloc(sizeof(v1beta2_capacity_requirements_t));
    if (!v1beta2_capacity_requirements_local_var) {
        return NULL;
    }
    v1beta2_capacity_requirements_local_var->requests = requests;

    v1beta2_capacity_requirements_local_var->_library_owned = 1;
    return v1beta2_capacity_requirements_local_var;
}

__attribute__((deprecated)) v1beta2_capacity_requirements_t *v1beta2_capacity_requirements_create(
    list_t* requests
    ) {
    return v1beta2_capacity_requirements_create_internal (
        requests
        );
}

void v1beta2_capacity_requirements_free(v1beta2_capacity_requirements_t *v1beta2_capacity_requirements) {
    if(NULL == v1beta2_capacity_requirements){
        return ;
    }
    if(v1beta2_capacity_requirements->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta2_capacity_requirements_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta2_capacity_requirements->requests) {
        list_ForEach(listEntry, v1beta2_capacity_requirements->requests) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1beta2_capacity_requirements->requests);
        v1beta2_capacity_requirements->requests = NULL;
    }
    free(v1beta2_capacity_requirements);
}

cJSON *v1beta2_capacity_requirements_convertToJSON(v1beta2_capacity_requirements_t *v1beta2_capacity_requirements) {
    cJSON *item = cJSON_CreateObject();

    // v1beta2_capacity_requirements->requests
    if(v1beta2_capacity_requirements->requests) {
    cJSON *requests = cJSON_AddObjectToObject(item, "requests");
    if(requests == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = requests;
    listEntry_t *requestsListEntry;
    if (v1beta2_capacity_requirements->requests) {
    list_ForEach(requestsListEntry, v1beta2_capacity_requirements->requests) {
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

v1beta2_capacity_requirements_t *v1beta2_capacity_requirements_parseFromJSON(cJSON *v1beta2_capacity_requirementsJSON){

    v1beta2_capacity_requirements_t *v1beta2_capacity_requirements_local_var = NULL;

    // define the local map for v1beta2_capacity_requirements->requests
    list_t *requestsList = NULL;

    // v1beta2_capacity_requirements->requests
    cJSON *requests = cJSON_GetObjectItemCaseSensitive(v1beta2_capacity_requirementsJSON, "requests");
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


    v1beta2_capacity_requirements_local_var = v1beta2_capacity_requirements_create_internal (
        requests ? requestsList : NULL
        );

    return v1beta2_capacity_requirements_local_var;
end:
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
