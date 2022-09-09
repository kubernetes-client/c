#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_overhead.h"



v1beta1_overhead_t *v1beta1_overhead_create(
    list_t* pod_fixed
    ) {
    v1beta1_overhead_t *v1beta1_overhead_local_var = malloc(sizeof(v1beta1_overhead_t));
    if (!v1beta1_overhead_local_var) {
        return NULL;
    }
    v1beta1_overhead_local_var->pod_fixed = pod_fixed;

    return v1beta1_overhead_local_var;
}


void v1beta1_overhead_free(v1beta1_overhead_t *v1beta1_overhead) {
    if(NULL == v1beta1_overhead){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_overhead->pod_fixed) {
        list_ForEach(listEntry, v1beta1_overhead->pod_fixed) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_freeList(v1beta1_overhead->pod_fixed);
        v1beta1_overhead->pod_fixed = NULL;
    }
    free(v1beta1_overhead);
}

cJSON *v1beta1_overhead_convertToJSON(v1beta1_overhead_t *v1beta1_overhead) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_overhead->pod_fixed
    if(v1beta1_overhead->pod_fixed) {
    cJSON *pod_fixed = cJSON_AddObjectToObject(item, "podFixed");
    if(pod_fixed == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = pod_fixed;
    listEntry_t *pod_fixedListEntry;
    if (v1beta1_overhead->pod_fixed) {
    list_ForEach(pod_fixedListEntry, v1beta1_overhead->pod_fixed) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)pod_fixedListEntry->data;
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

v1beta1_overhead_t *v1beta1_overhead_parseFromJSON(cJSON *v1beta1_overheadJSON){

    v1beta1_overhead_t *v1beta1_overhead_local_var = NULL;

    // define the local map for v1beta1_overhead->pod_fixed
    list_t *pod_fixedList = NULL;

    // v1beta1_overhead->pod_fixed
    cJSON *pod_fixed = cJSON_GetObjectItemCaseSensitive(v1beta1_overheadJSON, "podFixed");
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


    v1beta1_overhead_local_var = v1beta1_overhead_create (
        pod_fixed ? pod_fixedList : NULL
        );

    return v1beta1_overhead_local_var;
end:
    if (pod_fixedList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, pod_fixedList) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
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
