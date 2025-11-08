#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_container_restart_rule_on_exit_codes.h"



static v1_container_restart_rule_on_exit_codes_t *v1_container_restart_rule_on_exit_codes_create_internal(
    char *_operator,
    list_t *values
    ) {
    v1_container_restart_rule_on_exit_codes_t *v1_container_restart_rule_on_exit_codes_local_var = malloc(sizeof(v1_container_restart_rule_on_exit_codes_t));
    if (!v1_container_restart_rule_on_exit_codes_local_var) {
        return NULL;
    }
    v1_container_restart_rule_on_exit_codes_local_var->_operator = _operator;
    v1_container_restart_rule_on_exit_codes_local_var->values = values;

    v1_container_restart_rule_on_exit_codes_local_var->_library_owned = 1;
    return v1_container_restart_rule_on_exit_codes_local_var;
}

__attribute__((deprecated)) v1_container_restart_rule_on_exit_codes_t *v1_container_restart_rule_on_exit_codes_create(
    char *_operator,
    list_t *values
    ) {
    return v1_container_restart_rule_on_exit_codes_create_internal (
        _operator,
        values
        );
}

void v1_container_restart_rule_on_exit_codes_free(v1_container_restart_rule_on_exit_codes_t *v1_container_restart_rule_on_exit_codes) {
    if(NULL == v1_container_restart_rule_on_exit_codes){
        return ;
    }
    if(v1_container_restart_rule_on_exit_codes->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_container_restart_rule_on_exit_codes_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_container_restart_rule_on_exit_codes->_operator) {
        free(v1_container_restart_rule_on_exit_codes->_operator);
        v1_container_restart_rule_on_exit_codes->_operator = NULL;
    }
    if (v1_container_restart_rule_on_exit_codes->values) {
        list_ForEach(listEntry, v1_container_restart_rule_on_exit_codes->values) {
            free(listEntry->data);
        }
        list_freeList(v1_container_restart_rule_on_exit_codes->values);
        v1_container_restart_rule_on_exit_codes->values = NULL;
    }
    free(v1_container_restart_rule_on_exit_codes);
}

cJSON *v1_container_restart_rule_on_exit_codes_convertToJSON(v1_container_restart_rule_on_exit_codes_t *v1_container_restart_rule_on_exit_codes) {
    cJSON *item = cJSON_CreateObject();

    // v1_container_restart_rule_on_exit_codes->_operator
    if (!v1_container_restart_rule_on_exit_codes->_operator) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "operator", v1_container_restart_rule_on_exit_codes->_operator) == NULL) {
    goto fail; //String
    }


    // v1_container_restart_rule_on_exit_codes->values
    if(v1_container_restart_rule_on_exit_codes->values) {
    cJSON *values = cJSON_AddArrayToObject(item, "values");
    if(values == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *valuesListEntry;
    list_ForEach(valuesListEntry, v1_container_restart_rule_on_exit_codes->values) {
    if(cJSON_AddNumberToObject(values, "", *(double *)valuesListEntry->data) == NULL)
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

v1_container_restart_rule_on_exit_codes_t *v1_container_restart_rule_on_exit_codes_parseFromJSON(cJSON *v1_container_restart_rule_on_exit_codesJSON){

    v1_container_restart_rule_on_exit_codes_t *v1_container_restart_rule_on_exit_codes_local_var = NULL;

    // define the local list for v1_container_restart_rule_on_exit_codes->values
    list_t *valuesList = NULL;

    // v1_container_restart_rule_on_exit_codes->_operator
    cJSON *_operator = cJSON_GetObjectItemCaseSensitive(v1_container_restart_rule_on_exit_codesJSON, "operator");
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

    // v1_container_restart_rule_on_exit_codes->values
    cJSON *values = cJSON_GetObjectItemCaseSensitive(v1_container_restart_rule_on_exit_codesJSON, "values");
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
        if(!cJSON_IsNumber(values_local))
        {
            goto end;
        }
        double *values_local_value = calloc(1, sizeof(double));
        if(!values_local_value)
        {
            goto end;
        }
        *values_local_value = values_local->valuedouble;
        list_addElement(valuesList , values_local_value);
    }
    }


    v1_container_restart_rule_on_exit_codes_local_var = v1_container_restart_rule_on_exit_codes_create_internal (
        strdup(_operator->valuestring),
        values ? valuesList : NULL
        );

    return v1_container_restart_rule_on_exit_codes_local_var;
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
