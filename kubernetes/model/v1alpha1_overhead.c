#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1alpha1_overhead.h"



v1alpha1_overhead_t *v1alpha1_overhead_create(
    list_t* pod_fixed
    ) {
    v1alpha1_overhead_t *v1alpha1_overhead_local_var = malloc(sizeof(v1alpha1_overhead_t));
    if (!v1alpha1_overhead_local_var) {
        return NULL;
    }
    v1alpha1_overhead_local_var->pod_fixed = pod_fixed;

    return v1alpha1_overhead_local_var;
}


void v1alpha1_overhead_free(v1alpha1_overhead_t *v1alpha1_overhead) {
    if(NULL == v1alpha1_overhead){
        return ;
    }
    listEntry_t *listEntry;
    if (v1alpha1_overhead->pod_fixed) {
        list_ForEach(listEntry, v1alpha1_overhead->pod_fixed) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_free(v1alpha1_overhead->pod_fixed);
        v1alpha1_overhead->pod_fixed = NULL;
    }
    free(v1alpha1_overhead);
}

cJSON *v1alpha1_overhead_convertToJSON(v1alpha1_overhead_t *v1alpha1_overhead) {
    cJSON *item = cJSON_CreateObject();

    // v1alpha1_overhead->pod_fixed
    if(v1alpha1_overhead->pod_fixed) { 
    cJSON *pod_fixed = cJSON_AddObjectToObject(item, "podFixed");
    if(pod_fixed == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = pod_fixed;
    listEntry_t *pod_fixedListEntry;
    if (v1alpha1_overhead->pod_fixed) {
    list_ForEach(pod_fixedListEntry, v1alpha1_overhead->pod_fixed) {
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

v1alpha1_overhead_t *v1alpha1_overhead_parseFromJSON(cJSON *v1alpha1_overheadJSON){

    v1alpha1_overhead_t *v1alpha1_overhead_local_var = NULL;

    // v1alpha1_overhead->pod_fixed
    cJSON *pod_fixed = cJSON_GetObjectItemCaseSensitive(v1alpha1_overheadJSON, "podFixed");
    list_t *pod_fixedList;
    if (pod_fixed) { 
    cJSON *pod_fixed_local_map;
    if(!cJSON_IsObject(pod_fixed)) {
        goto end;//primitive map container
    }
    pod_fixedList = list_create();
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


    v1alpha1_overhead_local_var = v1alpha1_overhead_create (
        pod_fixed ? pod_fixedList : NULL
        );

    return v1alpha1_overhead_local_var;
end:
    return NULL;

}
