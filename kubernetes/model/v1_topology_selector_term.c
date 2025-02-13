#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_topology_selector_term.h"



static v1_topology_selector_term_t *v1_topology_selector_term_create_internal(
    list_t *match_label_expressions
    ) {
    v1_topology_selector_term_t *v1_topology_selector_term_local_var = malloc(sizeof(v1_topology_selector_term_t));
    if (!v1_topology_selector_term_local_var) {
        return NULL;
    }
    v1_topology_selector_term_local_var->match_label_expressions = match_label_expressions;

    v1_topology_selector_term_local_var->_library_owned = 1;
    return v1_topology_selector_term_local_var;
}

__attribute__((deprecated)) v1_topology_selector_term_t *v1_topology_selector_term_create(
    list_t *match_label_expressions
    ) {
    return v1_topology_selector_term_create_internal (
        match_label_expressions
        );
}

void v1_topology_selector_term_free(v1_topology_selector_term_t *v1_topology_selector_term) {
    if(NULL == v1_topology_selector_term){
        return ;
    }
    if(v1_topology_selector_term->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_topology_selector_term_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_topology_selector_term->match_label_expressions) {
        list_ForEach(listEntry, v1_topology_selector_term->match_label_expressions) {
            v1_topology_selector_label_requirement_free(listEntry->data);
        }
        list_freeList(v1_topology_selector_term->match_label_expressions);
        v1_topology_selector_term->match_label_expressions = NULL;
    }
    free(v1_topology_selector_term);
}

cJSON *v1_topology_selector_term_convertToJSON(v1_topology_selector_term_t *v1_topology_selector_term) {
    cJSON *item = cJSON_CreateObject();

    // v1_topology_selector_term->match_label_expressions
    if(v1_topology_selector_term->match_label_expressions) {
    cJSON *match_label_expressions = cJSON_AddArrayToObject(item, "matchLabelExpressions");
    if(match_label_expressions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *match_label_expressionsListEntry;
    if (v1_topology_selector_term->match_label_expressions) {
    list_ForEach(match_label_expressionsListEntry, v1_topology_selector_term->match_label_expressions) {
    cJSON *itemLocal = v1_topology_selector_label_requirement_convertToJSON(match_label_expressionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(match_label_expressions, itemLocal);
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

v1_topology_selector_term_t *v1_topology_selector_term_parseFromJSON(cJSON *v1_topology_selector_termJSON){

    v1_topology_selector_term_t *v1_topology_selector_term_local_var = NULL;

    // define the local list for v1_topology_selector_term->match_label_expressions
    list_t *match_label_expressionsList = NULL;

    // v1_topology_selector_term->match_label_expressions
    cJSON *match_label_expressions = cJSON_GetObjectItemCaseSensitive(v1_topology_selector_termJSON, "matchLabelExpressions");
    if (cJSON_IsNull(match_label_expressions)) {
        match_label_expressions = NULL;
    }
    if (match_label_expressions) { 
    cJSON *match_label_expressions_local_nonprimitive = NULL;
    if(!cJSON_IsArray(match_label_expressions)){
        goto end; //nonprimitive container
    }

    match_label_expressionsList = list_createList();

    cJSON_ArrayForEach(match_label_expressions_local_nonprimitive,match_label_expressions )
    {
        if(!cJSON_IsObject(match_label_expressions_local_nonprimitive)){
            goto end;
        }
        v1_topology_selector_label_requirement_t *match_label_expressionsItem = v1_topology_selector_label_requirement_parseFromJSON(match_label_expressions_local_nonprimitive);

        list_addElement(match_label_expressionsList, match_label_expressionsItem);
    }
    }


    v1_topology_selector_term_local_var = v1_topology_selector_term_create_internal (
        match_label_expressions ? match_label_expressionsList : NULL
        );

    return v1_topology_selector_term_local_var;
end:
    if (match_label_expressionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, match_label_expressionsList) {
            v1_topology_selector_label_requirement_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(match_label_expressionsList);
        match_label_expressionsList = NULL;
    }
    return NULL;

}
