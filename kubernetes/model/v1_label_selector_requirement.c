#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_label_selector_requirement.h"



static v1_label_selector_requirement_t *v1_label_selector_requirement_create_internal(
    char *key,
    char *_operator,
    list_t *values
    ) {
    v1_label_selector_requirement_t *v1_label_selector_requirement_local_var = malloc(sizeof(v1_label_selector_requirement_t));
    if (!v1_label_selector_requirement_local_var) {
        return NULL;
    }
    v1_label_selector_requirement_local_var->key = key;
    v1_label_selector_requirement_local_var->_operator = _operator;
    v1_label_selector_requirement_local_var->values = values;

    v1_label_selector_requirement_local_var->_library_owned = 1;
    return v1_label_selector_requirement_local_var;
}

__attribute__((deprecated)) v1_label_selector_requirement_t *v1_label_selector_requirement_create(
    char *key,
    char *_operator,
    list_t *values
    ) {
    return v1_label_selector_requirement_create_internal (
        key,
        _operator,
        values
        );
}

void v1_label_selector_requirement_free(v1_label_selector_requirement_t *v1_label_selector_requirement) {
    if(NULL == v1_label_selector_requirement){
        return ;
    }
    if(v1_label_selector_requirement->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_label_selector_requirement_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_label_selector_requirement->key) {
        free(v1_label_selector_requirement->key);
        v1_label_selector_requirement->key = NULL;
    }
    if (v1_label_selector_requirement->_operator) {
        free(v1_label_selector_requirement->_operator);
        v1_label_selector_requirement->_operator = NULL;
    }
    if (v1_label_selector_requirement->values) {
        list_ForEach(listEntry, v1_label_selector_requirement->values) {
            free(listEntry->data);
        }
        list_freeList(v1_label_selector_requirement->values);
        v1_label_selector_requirement->values = NULL;
    }
    free(v1_label_selector_requirement);
}

cJSON *v1_label_selector_requirement_convertToJSON(v1_label_selector_requirement_t *v1_label_selector_requirement) {
    cJSON *item = cJSON_CreateObject();

    // v1_label_selector_requirement->key
    if (!v1_label_selector_requirement->key) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "key", v1_label_selector_requirement->key) == NULL) {
    goto fail; //String
    }


    // v1_label_selector_requirement->_operator
    if (!v1_label_selector_requirement->_operator) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "operator", v1_label_selector_requirement->_operator) == NULL) {
    goto fail; //String
    }


    // v1_label_selector_requirement->values
    if(v1_label_selector_requirement->values) {
    cJSON *values = cJSON_AddArrayToObject(item, "values");
    if(values == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *valuesListEntry;
    list_ForEach(valuesListEntry, v1_label_selector_requirement->values) {
    if(cJSON_AddStringToObject(values, "", valuesListEntry->data) == NULL)
    {
        goto fail;
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

v1_label_selector_requirement_t *v1_label_selector_requirement_parseFromJSON(cJSON *v1_label_selector_requirementJSON){

    v1_label_selector_requirement_t *v1_label_selector_requirement_local_var = NULL;

    // define the local list for v1_label_selector_requirement->values
    list_t *valuesList = NULL;

    // v1_label_selector_requirement->key
    cJSON *key = cJSON_GetObjectItemCaseSensitive(v1_label_selector_requirementJSON, "key");
    if (cJSON_IsNull(key)) {
        key = NULL;
    }
    if (!key) {
        goto end;
    }

    
    if(!cJSON_IsString(key))
    {
    goto end; //String
    }

    // v1_label_selector_requirement->_operator
    cJSON *_operator = cJSON_GetObjectItemCaseSensitive(v1_label_selector_requirementJSON, "operator");
    if (cJSON_IsNull(_operator)) {
        _operator = NULL;
    }
    if (!_operator) {
        goto end;
    }

    
    if(!cJSON_IsString(_operator))
    {
    goto end; //String
    }

    // v1_label_selector_requirement->values
    cJSON *values = cJSON_GetObjectItemCaseSensitive(v1_label_selector_requirementJSON, "values");
    if (cJSON_IsNull(values)) {
        values = NULL;
    }
    if (values) { 
    cJSON *values_local = NULL;
    if(!cJSON_IsArray(values)) {
        goto end;//primitive container
    }
    valuesList = list_createList();

    cJSON_ArrayForEach(values_local, values)
    {
        if(!cJSON_IsString(values_local))
        {
            goto end;
        }
        list_addElement(valuesList , strdup(values_local->valuestring));
    }
    }


    v1_label_selector_requirement_local_var = v1_label_selector_requirement_create_internal (
        strdup(key->valuestring),
        strdup(_operator->valuestring),
        values ? valuesList : NULL
        );

    return v1_label_selector_requirement_local_var;
end:
    if (valuesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, valuesList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(valuesList);
        valuesList = NULL;
    }
    return NULL;

}
