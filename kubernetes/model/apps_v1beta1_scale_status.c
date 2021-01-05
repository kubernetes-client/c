#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "apps_v1beta1_scale_status.h"



apps_v1beta1_scale_status_t *apps_v1beta1_scale_status_create(
    int replicas,
    list_t* selector,
    char *target_selector
    ) {
    apps_v1beta1_scale_status_t *apps_v1beta1_scale_status_local_var = malloc(sizeof(apps_v1beta1_scale_status_t));
    if (!apps_v1beta1_scale_status_local_var) {
        return NULL;
    }
    apps_v1beta1_scale_status_local_var->replicas = replicas;
    apps_v1beta1_scale_status_local_var->selector = selector;
    apps_v1beta1_scale_status_local_var->target_selector = target_selector;

    return apps_v1beta1_scale_status_local_var;
}


void apps_v1beta1_scale_status_free(apps_v1beta1_scale_status_t *apps_v1beta1_scale_status) {
    if(NULL == apps_v1beta1_scale_status){
        return ;
    }
    listEntry_t *listEntry;
    if (apps_v1beta1_scale_status->selector) {
        list_ForEach(listEntry, apps_v1beta1_scale_status->selector) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_free(apps_v1beta1_scale_status->selector);
        apps_v1beta1_scale_status->selector = NULL;
    }
    if (apps_v1beta1_scale_status->target_selector) {
        free(apps_v1beta1_scale_status->target_selector);
        apps_v1beta1_scale_status->target_selector = NULL;
    }
    free(apps_v1beta1_scale_status);
}

cJSON *apps_v1beta1_scale_status_convertToJSON(apps_v1beta1_scale_status_t *apps_v1beta1_scale_status) {
    cJSON *item = cJSON_CreateObject();

    // apps_v1beta1_scale_status->replicas
    if (!apps_v1beta1_scale_status->replicas) {
        goto fail;
    }
    
    if(cJSON_AddNumberToObject(item, "replicas", apps_v1beta1_scale_status->replicas) == NULL) {
    goto fail; //Numeric
    }


    // apps_v1beta1_scale_status->selector
    if(apps_v1beta1_scale_status->selector) { 
    cJSON *selector = cJSON_AddObjectToObject(item, "selector");
    if(selector == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = selector;
    listEntry_t *selectorListEntry;
    if (apps_v1beta1_scale_status->selector) {
    list_ForEach(selectorListEntry, apps_v1beta1_scale_status->selector) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)selectorListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
     } 


    // apps_v1beta1_scale_status->target_selector
    if(apps_v1beta1_scale_status->target_selector) { 
    if(cJSON_AddStringToObject(item, "targetSelector", apps_v1beta1_scale_status->target_selector) == NULL) {
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

apps_v1beta1_scale_status_t *apps_v1beta1_scale_status_parseFromJSON(cJSON *apps_v1beta1_scale_statusJSON){

    apps_v1beta1_scale_status_t *apps_v1beta1_scale_status_local_var = NULL;

    // apps_v1beta1_scale_status->replicas
    cJSON *replicas = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_scale_statusJSON, "replicas");
    if (!replicas) {
        goto end;
    }

    
    if(!cJSON_IsNumber(replicas))
    {
    goto end; //Numeric
    }

    // apps_v1beta1_scale_status->selector
    cJSON *selector = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_scale_statusJSON, "selector");
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

    // apps_v1beta1_scale_status->target_selector
    cJSON *target_selector = cJSON_GetObjectItemCaseSensitive(apps_v1beta1_scale_statusJSON, "targetSelector");
    if (target_selector) { 
    if(!cJSON_IsString(target_selector))
    {
    goto end; //String
    }
    }


    apps_v1beta1_scale_status_local_var = apps_v1beta1_scale_status_create (
        replicas->valuedouble,
        selector ? selectorList : NULL,
        target_selector ? strdup(target_selector->valuestring) : NULL
        );

    return apps_v1beta1_scale_status_local_var;
end:
    return NULL;

}
