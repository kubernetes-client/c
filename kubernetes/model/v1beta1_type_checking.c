#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_type_checking.h"



v1beta1_type_checking_t *v1beta1_type_checking_create(
    list_t *expression_warnings
    ) {
    v1beta1_type_checking_t *v1beta1_type_checking_local_var = malloc(sizeof(v1beta1_type_checking_t));
    if (!v1beta1_type_checking_local_var) {
        return NULL;
    }
    v1beta1_type_checking_local_var->expression_warnings = expression_warnings;

    return v1beta1_type_checking_local_var;
}


void v1beta1_type_checking_free(v1beta1_type_checking_t *v1beta1_type_checking) {
    if(NULL == v1beta1_type_checking){
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_type_checking->expression_warnings) {
        list_ForEach(listEntry, v1beta1_type_checking->expression_warnings) {
            v1beta1_expression_warning_free(listEntry->data);
        }
        list_freeList(v1beta1_type_checking->expression_warnings);
        v1beta1_type_checking->expression_warnings = NULL;
    }
    free(v1beta1_type_checking);
}

cJSON *v1beta1_type_checking_convertToJSON(v1beta1_type_checking_t *v1beta1_type_checking) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_type_checking->expression_warnings
    if(v1beta1_type_checking->expression_warnings) {
    cJSON *expression_warnings = cJSON_AddArrayToObject(item, "expressionWarnings");
    if(expression_warnings == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *expression_warningsListEntry;
    if (v1beta1_type_checking->expression_warnings) {
    list_ForEach(expression_warningsListEntry, v1beta1_type_checking->expression_warnings) {
    cJSON *itemLocal = v1beta1_expression_warning_convertToJSON(expression_warningsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(expression_warnings, itemLocal);
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

v1beta1_type_checking_t *v1beta1_type_checking_parseFromJSON(cJSON *v1beta1_type_checkingJSON){

    v1beta1_type_checking_t *v1beta1_type_checking_local_var = NULL;

    // define the local list for v1beta1_type_checking->expression_warnings
    list_t *expression_warningsList = NULL;

    // v1beta1_type_checking->expression_warnings
    cJSON *expression_warnings = cJSON_GetObjectItemCaseSensitive(v1beta1_type_checkingJSON, "expressionWarnings");
    if (expression_warnings) { 
    cJSON *expression_warnings_local_nonprimitive = NULL;
    if(!cJSON_IsArray(expression_warnings)){
        goto end; //nonprimitive container
    }

    expression_warningsList = list_createList();

    cJSON_ArrayForEach(expression_warnings_local_nonprimitive,expression_warnings )
    {
        if(!cJSON_IsObject(expression_warnings_local_nonprimitive)){
            goto end;
        }
        v1beta1_expression_warning_t *expression_warningsItem = v1beta1_expression_warning_parseFromJSON(expression_warnings_local_nonprimitive);

        list_addElement(expression_warningsList, expression_warningsItem);
    }
    }


    v1beta1_type_checking_local_var = v1beta1_type_checking_create (
        expression_warnings ? expression_warningsList : NULL
        );

    return v1beta1_type_checking_local_var;
end:
    if (expression_warningsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, expression_warningsList) {
            v1beta1_expression_warning_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(expression_warningsList);
        expression_warningsList = NULL;
    }
    return NULL;

}
