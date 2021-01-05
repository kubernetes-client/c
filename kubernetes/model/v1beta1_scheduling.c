#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_scheduling.h"



v1beta1_scheduling_t *v1beta1_scheduling_create(
    list_t* node_selector,
    list_t *tolerations
    ) {
    v1beta1_scheduling_t *v1beta1_scheduling_local_var = malloc(sizeof(v1beta1_scheduling_t));
    if (!v1beta1_scheduling_local_var) {
        return NULL;
    }
    v1beta1_scheduling_local_var->node_selector = node_selector;
    v1beta1_scheduling_local_var->tolerations = tolerations;

    return v1beta1_scheduling_local_var;
}


void v1beta1_scheduling_free(v1beta1_scheduling_t *v1beta1_scheduling) {
    if(NULL == v1beta1_scheduling){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_scheduling->node_selector) {
        list_ForEach(listEntry, v1beta1_scheduling->node_selector) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_free(v1beta1_scheduling->node_selector);
        v1beta1_scheduling->node_selector = NULL;
    }
    if (v1beta1_scheduling->tolerations) {
        list_ForEach(listEntry, v1beta1_scheduling->tolerations) {
            v1_toleration_free(listEntry->data);
        }
        list_free(v1beta1_scheduling->tolerations);
        v1beta1_scheduling->tolerations = NULL;
    }
    free(v1beta1_scheduling);
}

cJSON *v1beta1_scheduling_convertToJSON(v1beta1_scheduling_t *v1beta1_scheduling) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_scheduling->node_selector
    if(v1beta1_scheduling->node_selector) { 
    cJSON *node_selector = cJSON_AddObjectToObject(item, "nodeSelector");
    if(node_selector == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = node_selector;
    listEntry_t *node_selectorListEntry;
    if (v1beta1_scheduling->node_selector) {
    list_ForEach(node_selectorListEntry, v1beta1_scheduling->node_selector) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)node_selectorListEntry->data;
        if(cJSON_AddStringToObject(localMapObject, localKeyValue->key, (char*)localKeyValue->value) == NULL)
        {
            goto fail;
        }
    }
    }
     } 


    // v1beta1_scheduling->tolerations
    if(v1beta1_scheduling->tolerations) { 
    cJSON *tolerations = cJSON_AddArrayToObject(item, "tolerations");
    if(tolerations == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *tolerationsListEntry;
    if (v1beta1_scheduling->tolerations) {
    list_ForEach(tolerationsListEntry, v1beta1_scheduling->tolerations) {
    cJSON *itemLocal = v1_toleration_convertToJSON(tolerationsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(tolerations, itemLocal);
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

v1beta1_scheduling_t *v1beta1_scheduling_parseFromJSON(cJSON *v1beta1_schedulingJSON){

    v1beta1_scheduling_t *v1beta1_scheduling_local_var = NULL;

    // v1beta1_scheduling->node_selector
    cJSON *node_selector = cJSON_GetObjectItemCaseSensitive(v1beta1_schedulingJSON, "nodeSelector");
    list_t *node_selectorList;
    if (node_selector) { 
    cJSON *node_selector_local_map;
    if(!cJSON_IsObject(node_selector)) {
        goto end;//primitive map container
    }
    node_selectorList = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(node_selector_local_map, node_selector)
    {
		cJSON *localMapObject = node_selector_local_map;
        if(!cJSON_IsString(localMapObject))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
        list_addElement(node_selectorList , localMapKeyPair);
    }
    }

    // v1beta1_scheduling->tolerations
    cJSON *tolerations = cJSON_GetObjectItemCaseSensitive(v1beta1_schedulingJSON, "tolerations");
    list_t *tolerationsList;
    if (tolerations) { 
    cJSON *tolerations_local_nonprimitive;
    if(!cJSON_IsArray(tolerations)){
        goto end; //nonprimitive container
    }

    tolerationsList = list_create();

    cJSON_ArrayForEach(tolerations_local_nonprimitive,tolerations )
    {
        if(!cJSON_IsObject(tolerations_local_nonprimitive)){
            goto end;
        }
        v1_toleration_t *tolerationsItem = v1_toleration_parseFromJSON(tolerations_local_nonprimitive);

        list_addElement(tolerationsList, tolerationsItem);
    }
    }


    v1beta1_scheduling_local_var = v1beta1_scheduling_create (
        node_selector ? node_selectorList : NULL,
        tolerations ? tolerationsList : NULL
        );

    return v1beta1_scheduling_local_var;
end:
    return NULL;

}
