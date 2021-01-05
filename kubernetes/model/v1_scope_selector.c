#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_scope_selector.h"



v1_scope_selector_t *v1_scope_selector_create(
    list_t *match_expressions
    ) {
    v1_scope_selector_t *v1_scope_selector_local_var = malloc(sizeof(v1_scope_selector_t));
    if (!v1_scope_selector_local_var) {
        return NULL;
    }
    v1_scope_selector_local_var->match_expressions = match_expressions;

    return v1_scope_selector_local_var;
}


void v1_scope_selector_free(v1_scope_selector_t *v1_scope_selector) {
    if(NULL == v1_scope_selector){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_scope_selector->match_expressions) {
        list_ForEach(listEntry, v1_scope_selector->match_expressions) {
            v1_scoped_resource_selector_requirement_free(listEntry->data);
        }
        list_free(v1_scope_selector->match_expressions);
        v1_scope_selector->match_expressions = NULL;
    }
    free(v1_scope_selector);
}

cJSON *v1_scope_selector_convertToJSON(v1_scope_selector_t *v1_scope_selector) {
    cJSON *item = cJSON_CreateObject();

    // v1_scope_selector->match_expressions
    if(v1_scope_selector->match_expressions) { 
    cJSON *match_expressions = cJSON_AddArrayToObject(item, "matchExpressions");
    if(match_expressions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *match_expressionsListEntry;
    if (v1_scope_selector->match_expressions) {
    list_ForEach(match_expressionsListEntry, v1_scope_selector->match_expressions) {
    cJSON *itemLocal = v1_scoped_resource_selector_requirement_convertToJSON(match_expressionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(match_expressions, itemLocal);
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

v1_scope_selector_t *v1_scope_selector_parseFromJSON(cJSON *v1_scope_selectorJSON){

    v1_scope_selector_t *v1_scope_selector_local_var = NULL;

    // v1_scope_selector->match_expressions
    cJSON *match_expressions = cJSON_GetObjectItemCaseSensitive(v1_scope_selectorJSON, "matchExpressions");
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
        v1_scoped_resource_selector_requirement_t *match_expressionsItem = v1_scoped_resource_selector_requirement_parseFromJSON(match_expressions_local_nonprimitive);

        list_addElement(match_expressionsList, match_expressionsItem);
    }
    }


    v1_scope_selector_local_var = v1_scope_selector_create (
        match_expressions ? match_expressionsList : NULL
        );

    return v1_scope_selector_local_var;
end:
    return NULL;

}
