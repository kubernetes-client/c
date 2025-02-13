#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_node_selector_term.h"



static v1_node_selector_term_t *v1_node_selector_term_create_internal(
    list_t *match_expressions,
    list_t *match_fields
    ) {
    v1_node_selector_term_t *v1_node_selector_term_local_var = malloc(sizeof(v1_node_selector_term_t));
    if (!v1_node_selector_term_local_var) {
        return NULL;
    }
    v1_node_selector_term_local_var->match_expressions = match_expressions;
    v1_node_selector_term_local_var->match_fields = match_fields;

    v1_node_selector_term_local_var->_library_owned = 1;
    return v1_node_selector_term_local_var;
}

__attribute__((deprecated)) v1_node_selector_term_t *v1_node_selector_term_create(
    list_t *match_expressions,
    list_t *match_fields
    ) {
    return v1_node_selector_term_create_internal (
        match_expressions,
        match_fields
        );
}

void v1_node_selector_term_free(v1_node_selector_term_t *v1_node_selector_term) {
    if(NULL == v1_node_selector_term){
        return ;
    }
    if(v1_node_selector_term->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_node_selector_term_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_node_selector_term->match_expressions) {
        list_ForEach(listEntry, v1_node_selector_term->match_expressions) {
            v1_node_selector_requirement_free(listEntry->data);
        }
        list_freeList(v1_node_selector_term->match_expressions);
        v1_node_selector_term->match_expressions = NULL;
    }
    if (v1_node_selector_term->match_fields) {
        list_ForEach(listEntry, v1_node_selector_term->match_fields) {
            v1_node_selector_requirement_free(listEntry->data);
        }
        list_freeList(v1_node_selector_term->match_fields);
        v1_node_selector_term->match_fields = NULL;
    }
    free(v1_node_selector_term);
}

cJSON *v1_node_selector_term_convertToJSON(v1_node_selector_term_t *v1_node_selector_term) {
    cJSON *item = cJSON_CreateObject();

    // v1_node_selector_term->match_expressions
    if(v1_node_selector_term->match_expressions) {
    cJSON *match_expressions = cJSON_AddArrayToObject(item, "matchExpressions");
    if(match_expressions == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *match_expressionsListEntry;
    if (v1_node_selector_term->match_expressions) {
    list_ForEach(match_expressionsListEntry, v1_node_selector_term->match_expressions) {
    cJSON *itemLocal = v1_node_selector_requirement_convertToJSON(match_expressionsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(match_expressions, itemLocal);
    }
    }
    }


    // v1_node_selector_term->match_fields
    if(v1_node_selector_term->match_fields) {
    cJSON *match_fields = cJSON_AddArrayToObject(item, "matchFields");
    if(match_fields == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *match_fieldsListEntry;
    if (v1_node_selector_term->match_fields) {
    list_ForEach(match_fieldsListEntry, v1_node_selector_term->match_fields) {
    cJSON *itemLocal = v1_node_selector_requirement_convertToJSON(match_fieldsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(match_fields, itemLocal);
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

v1_node_selector_term_t *v1_node_selector_term_parseFromJSON(cJSON *v1_node_selector_termJSON){

    v1_node_selector_term_t *v1_node_selector_term_local_var = NULL;

    // define the local list for v1_node_selector_term->match_expressions
    list_t *match_expressionsList = NULL;

    // define the local list for v1_node_selector_term->match_fields
    list_t *match_fieldsList = NULL;

    // v1_node_selector_term->match_expressions
    cJSON *match_expressions = cJSON_GetObjectItemCaseSensitive(v1_node_selector_termJSON, "matchExpressions");
    if (cJSON_IsNull(match_expressions)) {
        match_expressions = NULL;
    }
    if (match_expressions) { 
    cJSON *match_expressions_local_nonprimitive = NULL;
    if(!cJSON_IsArray(match_expressions)){
        goto end; //nonprimitive container
    }

    match_expressionsList = list_createList();

    cJSON_ArrayForEach(match_expressions_local_nonprimitive,match_expressions )
    {
        if(!cJSON_IsObject(match_expressions_local_nonprimitive)){
            goto end;
        }
        v1_node_selector_requirement_t *match_expressionsItem = v1_node_selector_requirement_parseFromJSON(match_expressions_local_nonprimitive);

        list_addElement(match_expressionsList, match_expressionsItem);
    }
    }

    // v1_node_selector_term->match_fields
    cJSON *match_fields = cJSON_GetObjectItemCaseSensitive(v1_node_selector_termJSON, "matchFields");
    if (cJSON_IsNull(match_fields)) {
        match_fields = NULL;
    }
    if (match_fields) { 
    cJSON *match_fields_local_nonprimitive = NULL;
    if(!cJSON_IsArray(match_fields)){
        goto end; //nonprimitive container
    }

    match_fieldsList = list_createList();

    cJSON_ArrayForEach(match_fields_local_nonprimitive,match_fields )
    {
        if(!cJSON_IsObject(match_fields_local_nonprimitive)){
            goto end;
        }
        v1_node_selector_requirement_t *match_fieldsItem = v1_node_selector_requirement_parseFromJSON(match_fields_local_nonprimitive);

        list_addElement(match_fieldsList, match_fieldsItem);
    }
    }


    v1_node_selector_term_local_var = v1_node_selector_term_create_internal (
        match_expressions ? match_expressionsList : NULL,
        match_fields ? match_fieldsList : NULL
        );

    return v1_node_selector_term_local_var;
end:
    if (match_expressionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, match_expressionsList) {
            v1_node_selector_requirement_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(match_expressionsList);
        match_expressionsList = NULL;
    }
    if (match_fieldsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, match_fieldsList) {
            v1_node_selector_requirement_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(match_fieldsList);
        match_fieldsList = NULL;
    }
    return NULL;

}
