#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_overhead.h"



static v1_overhead_t *v1_overhead_create_internal(
    list_t* pod_fixed
    ) {
    v1_overhead_t *v1_overhead_local_var = malloc(sizeof(v1_overhead_t));
    if (!v1_overhead_local_var) {
        return NULL;
    }
    v1_overhead_local_var->pod_fixed = pod_fixed;

    v1_overhead_local_var->_library_owned = 1;
    return v1_overhead_local_var;
}

__attribute__((deprecated)) v1_overhead_t *v1_overhead_create(
    list_t* pod_fixed
    ) {
    return v1_overhead_create_internal (
        pod_fixed
        );
}

void v1_overhead_free(v1_overhead_t *v1_overhead) {
    if(NULL == v1_overhead){
        return ;
    }
    if(v1_overhead->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_overhead_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_overhead->pod_fixed) {
        list_ForEach(listEntry, v1_overhead->pod_fixed) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1_overhead->pod_fixed);
        v1_overhead->pod_fixed = NULL;
    }
    free(v1_overhead);
}

cJSON *v1_overhead_convertToJSON(v1_overhead_t *v1_overhead) {
    cJSON *item = cJSON_CreateObject();

    // v1_overhead->pod_fixed
    if(v1_overhead->pod_fixed) {
    cJSON *pod_fixed = cJSON_AddObjectToObject(item, "podFixed");
    if(pod_fixed == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = pod_fixed;
    listEntry_t *pod_fixedListEntry;
    if (v1_overhead->pod_fixed) {
    list_ForEach(pod_fixedListEntry, v1_overhead->pod_fixed) {
        keyValuePair_t *localKeyValue = pod_fixedListEntry->data;
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

v1_overhead_t *v1_overhead_parseFromJSON(cJSON *v1_overheadJSON){

    v1_overhead_t *v1_overhead_local_var = NULL;

    // define the local map for v1_overhead->pod_fixed
    list_t *pod_fixedList = NULL;

    // v1_overhead->pod_fixed
    cJSON *pod_fixed = cJSON_GetObjectItemCaseSensitive(v1_overheadJSON, "podFixed");
    if (cJSON_IsNull(pod_fixed)) {
        pod_fixed = NULL;
    }
    if (pod_fixed) { 
    cJSON *pod_fixed_local_map = NULL;
    if(!cJSON_IsObject(pod_fixed) && !cJSON_IsNull(pod_fixed))
    {
        goto end;//primitive map container
    }
    if(cJSON_IsObject(pod_fixed))
    {
        pod_fixedList = list_createList();
        keyValuePair_t *localMapKeyPair;
        cJSON_ArrayForEach(pod_fixed_local_map, pod_fixed)
        {
            cJSON *localMapObject = pod_fixed_local_map;
            if(!cJSON_IsString(localMapObject))
            {
                goto end;
            }
            localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
            list_addElement(pod_fixedList , localMapKeyPair);
        }
    }
    }


    v1_overhead_local_var = v1_overhead_create_internal (
        pod_fixed ? pod_fixedList : NULL
        );

    return v1_overhead_local_var;
end:
    if (pod_fixedList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, pod_fixedList) {
            keyValuePair_t *localKeyValue = listEntry->data;
            free(localKeyValue->key);
            localKeyValue->key = NULL;
            free(localKeyValue->value);
            localKeyValue->value = NULL;
            keyValuePair_free(localKeyValue);
            localKeyValue = NULL;
        }
        list_freeList(pod_fixedList);
        pod_fixedList = NULL;
    }
    return NULL;

}
