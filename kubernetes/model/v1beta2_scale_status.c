#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta2_scale_status.h"



v1beta2_scale_status_t *v1beta2_scale_status_create(
    int replicas,
    list_t* selector,
    char *target_selector
    ) {
    v1beta2_scale_status_t *v1beta2_scale_status_local_var = malloc(sizeof(v1beta2_scale_status_t));
    if (!v1beta2_scale_status_local_var) {
        return NULL;
    }
    v1beta2_scale_status_local_var->replicas = replicas;
    v1beta2_scale_status_local_var->selector = selector;
    v1beta2_scale_status_local_var->target_selector = target_selector;

    return v1beta2_scale_status_local_var;
}


void v1beta2_scale_status_free(v1beta2_scale_status_t *v1beta2_scale_status) {
    if(NULL == v1beta2_scale_status){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta2_scale_status->selector) {
        list_ForEach(listEntry, v1beta2_scale_status->selector) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_free(v1beta2_scale_status->selector);
        v1beta2_scale_status->selector = NULL;
    }
    if (v1beta2_scale_status->target_selector) {
        free(v1beta2_scale_status->target_selector);
        v1beta2_scale_status->target_selector = NULL;
    }
    free(v1beta2_scale_status);
}

cJSON *v1beta2_scale_status_convertToJSON(v1beta2_scale_status_t *v1beta2_scale_status) {
    cJSON *item = cJSON_CreateObject();

    // v1beta2_scale_status->replicas
    if (!v1beta2_scale_status->replicas) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "replicas", v1beta2_scale_status->replicas) == NULL) {
    goto fail; //Numeric
    }


    // v1beta2_scale_status->selector
    if(v1beta2_scale_status->selector) { 
    cJSON *selector = cJSON_AddObjectToObject(item, "selector");
    if(selector == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = selector;
    listEntry_t *selectorListEntry;
    if (v1beta2_scale_status->selector) {
    list_ForEach(selectorListEntry, v1beta2_scale_status->selector) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)selectorListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
     } 


    // v1beta2_scale_status->target_selector
    if(v1beta2_scale_status->target_selector) { 
    if(cJSON_AddStringToObject(item, "targetSelector", v1beta2_scale_status->target_selector) == NULL) {
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

v1beta2_scale_status_t *v1beta2_scale_status_parseFromJSON(cJSON *v1beta2_scale_statusJSON){

    v1beta2_scale_status_t *v1beta2_scale_status_local_var = NULL;

    // v1beta2_scale_status->replicas
    cJSON *replicas = cJSON_GetObjectItemCaseSensitive(v1beta2_scale_statusJSON, "replicas");
    if (!replicas) {
        goto end;
    }

    
    if(!cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }

    // v1beta2_scale_status->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(v1beta2_scale_statusJSON, "selector");
    list_t *selectorList;
    if (selector) { 
    cJSON *selector_local_map;
    if(!cJSON_IsObject(selector)) {
        goto end;//primitive map container
    }
    selectorList = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(selector_local_map, selector)
    {
		cJSON *localMapObject = selector_local_map;
        if(!cJSON_IsString(localMapObject))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
        list_addElement(selectorList , localMapKeyPair);
    }
    }

    // v1beta2_scale_status->target_selector
    cJSON *target_selector = cJSON_GetObjectItemCaseSensitive(v1beta2_scale_statusJSON, "targetSelector");
    if (target_selector) { 
    if(!cJSON_IsString(target_selector))
    {
    goto end; //String
    }
    }


    v1beta2_scale_status_local_var = v1beta2_scale_status_create (
        replicas->valuedouble,
        selector ? selectorList : NULL,
        target_selector ? strdup(target_selector->valuestring) : NULL
        );

    return v1beta2_scale_status_local_var;
end:
    return NULL;

}
