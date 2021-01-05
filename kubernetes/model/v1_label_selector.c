#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_label_selector.h"



v1_label_selector_t *v1_label_selector_create(
    list_t *match_expressions,
    list_t* match_labels
    ) {
    v1_label_selector_t *v1_label_selector_local_var = malloc(sizeof(v1_label_selector_t));
    if (!v1_label_selector_local_var) {
        return NULL;
    }
    v1_label_selector_local_var->match_expressions = match_expressions;
    v1_label_selector_local_var->match_labels = match_labels;

    return v1_label_selector_local_var;
}


void v1_label_selector_free(v1_label_selector_t *v1_label_selector) {
    if(NULL == v1_label_selector){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_label_selector->match_expressions) {
        list_ForEach(listEntry, v1_label_selector->match_expressions) {
            v1_label_selector_requirement_free(listEntry->data);
        }
        list_free(v1_label_selector->match_expressions);
        v1_label_selector->match_expressions = NULL;
    }
    if (v1_label_selector->match_labels) {
        list_ForEach(listEntry, v1_label_selector->match_labels) {
            keyValuePair_t *localKeyValue = (keyValuePair_t*) listEntry->data;
            free (localKeyValue->key);
            free (localKeyValue->value);
            keyValuePair_free(localKeyValue);
        }
        list_free(v1_label_selector->match_labels);
        v1_label_selector->match_labels = NULL;
    }
    free(v1_label_selector);
}

cJSON *v1_label_selector_convertToJSON(v1_label_selector_t *v1_label_selector) {
    cJSON *item = cJSON_CreateObject();

    // v1_label_selector->match_expressions
    if(v1_label_selector->match_expressions) { 
    cJSON *match_expressions = cJSON_AddArrayToObject(item, "matchExpressions");
    if(match_expressions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *match_expressionsListEntry;
    if (v1_label_selector->match_expressions) {
    list_ForEach(match_expressionsListEntry, v1_label_selector->match_expressions) {
    cJSON *itemLocal = v1_label_selector_requirement_convertToJSON(match_expressionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(match_expressions, itemLocal);
    }
    }
     } 


    // v1_label_selector->match_labels
    if(v1_label_selector->match_labels) { 
    cJSON *match_labels = cJSON_AddObjectToObject(item, "matchLabels");
    if(match_labels == NULL) {
        goto fail; //primitive map container
    }
    cJSON *localMapObject = match_labels;
    listEntry_t *match_labelsListEntry;
    if (v1_label_selector->match_labels) {
    list_ForEach(match_labelsListEntry, v1_label_selector->match_labels) {
        keyValuePair_t *localKeyValue = (keyValuePair_t*)match_labelsListEntry->data;
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

v1_label_selector_t *v1_label_selector_parseFromJSON(cJSON *v1_label_selectorJSON){

    v1_label_selector_t *v1_label_selector_local_var = NULL;

    // v1_label_selector->match_expressions
    cJSON *match_expressions = cJSON_GetObjectItemCaseSensitive(v1_label_selectorJSON, "matchExpressions");
    list_t *match_expressionsList;
    if (match_expressions) { 
    cJSON *match_expressions_local_nonprimitive;
    if(!cJSON_IsArray(match_expressions)){
        goto end; //nonprimitive container
    }

    match_expressionsList = list_create();

    cJSON_ArrayForEach(match_expressions_local_nonprimitive,match_expressions )
    {
        if(!cJSON_IsObject(match_expressions_local_nonprimitive)){
            goto end;
        }
        v1_label_selector_requirement_t *match_expressionsItem = v1_label_selector_requirement_parseFromJSON(match_expressions_local_nonprimitive);

        list_addElement(match_expressionsList, match_expressionsItem);
    }
    }

    // v1_label_selector->match_labels
    cJSON *match_labels = cJSON_GetObjectItemCaseSensitive(v1_label_selectorJSON, "matchLabels");
    list_t *match_labelsList;
    if (match_labels) { 
    cJSON *match_labels_local_map;
    if(!cJSON_IsObject(match_labels)) {
        goto end;//primitive map container
    }
    match_labelsList = list_create();
    keyValuePair_t *localMapKeyPair;
    cJSON_ArrayForEach(match_labels_local_map, match_labels)
    {
		cJSON *localMapObject = match_labels_local_map;
        if(!cJSON_IsString(localMapObject))
        {
            goto end;
        }
        localMapKeyPair = keyValuePair_create(strdup(localMapObject->string),strdup(localMapObject->valuestring));
        list_addElement(match_labelsList , localMapKeyPair);
    }
    }


    v1_label_selector_local_var = v1_label_selector_create (
        match_expressions ? match_expressionsList : NULL,
        match_labels ? match_labelsList : NULL
        );

    return v1_label_selector_local_var;
end:
    return NULL;

}
