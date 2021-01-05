#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "extensions_v1beta1_scale_status.h"



extensions_v1beta1_scale_status_t *extensions_v1beta1_scale_status_create(
    int replicas,
    list_t* selector,
    char *target_selector
    ) {
    extensions_v1beta1_scale_status_t *extensions_v1beta1_scale_status_local_var = malloc(sizeof(extensions_v1beta1_scale_status_t));
    if (!extensions_v1beta1_scale_status_local_var) {
        return NULL;
    }
    extensions_v1beta1_scale_status_local_var->replicas = replicas;
    extensions_v1beta1_scale_status_local_var->selector = selector;
    extensions_v1beta1_scale_status_local_var->target_selector = target_selector;

    return extensions_v1beta1_scale_status_local_var;
}


void extensions_v1beta1_scale_status_free(extensions_v1beta1_scale_status_t *extensions_v1beta1_scale_status) {
    if(NULL == extensions_v1beta1_scale_status){
        return ;
    }
    listEntry_t *listEntry;
    if (extensions_v1beta1_scale_status->selector) {
        list_ForEach(listEntry, extensions_v1beta1_scale_status->selector) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_free(extensions_v1beta1_scale_status->selector);
        extensions_v1beta1_scale_status->selector = NULL;
    }
    if (extensions_v1beta1_scale_status->target_selector) {
        free(extensions_v1beta1_scale_status->target_selector);
        extensions_v1beta1_scale_status->target_selector = NULL;
    }
    free(extensions_v1beta1_scale_status);
}

cJSON *extensions_v1beta1_scale_status_convertToJSON(extensions_v1beta1_scale_status_t *extensions_v1beta1_scale_status) {
    cJSON *item = cJSON_CreateObject();

    // extensions_v1beta1_scale_status->replicas
    if (!extensions_v1beta1_scale_status->replicas) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "replicas", extensions_v1beta1_scale_status->replicas) == NULL) {
    goto fail; //Numeric
    }


    // extensions_v1beta1_scale_status->selector
    if(extensions_v1beta1_scale_status->selector) { 
    cJSON *selector = cJSON_AddObjectToObject(item, "selector");
    if(selector == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = selector;
    listEntry_t *selectorListEntry;
    if (extensions_v1beta1_scale_status->selector) {
    list_ForEach(selectorListEntry, extensions_v1beta1_scale_status->selector) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)selectorListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
     } 


    // extensions_v1beta1_scale_status->target_selector
    if(extensions_v1beta1_scale_status->target_selector) { 
    if(cJSON_AddStringToObject(item, "targetSelector", extensions_v1beta1_scale_status->target_selector) == NULL) {
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

extensions_v1beta1_scale_status_t *extensions_v1beta1_scale_status_parseFromJSON(cJSON *extensions_v1beta1_scale_statusJSON){

    extensions_v1beta1_scale_status_t *extensions_v1beta1_scale_status_local_var = NULL;

    // extensions_v1beta1_scale_status->replicas
    cJSON *replicas = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_scale_statusJSON, "replicas");
    if (!replicas) {
        goto end;
    }

    
    if(!cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }

    // extensions_v1beta1_scale_status->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_scale_statusJSON, "selector");
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

    // extensions_v1beta1_scale_status->target_selector
    cJSON *target_selector = cJSON_GetObjectItemCaseSensitive(extensions_v1beta1_scale_statusJSON, "targetSelector");
    if (target_selector) { 
    if(!cJSON_IsString(target_selector))
    {
    goto end; //String
    }
    }


    extensions_v1beta1_scale_status_local_var = extensions_v1beta1_scale_status_create (
        replicas->valuedouble,
        selector ? selectorList : NULL,
        target_selector ? strdup(target_selector->valuestring) : NULL
        );

    return extensions_v1beta1_scale_status_local_var;
end:
    return NULL;

}
