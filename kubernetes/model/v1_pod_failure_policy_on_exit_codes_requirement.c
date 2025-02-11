#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_pod_failure_policy_on_exit_codes_requirement.h"



static v1_pod_failure_policy_on_exit_codes_requirement_t *v1_pod_failure_policy_on_exit_codes_requirement_create_internal(
    char *container_name,
    char *_operator,
    list_t *values
    ) {
    v1_pod_failure_policy_on_exit_codes_requirement_t *v1_pod_failure_policy_on_exit_codes_requirement_local_var = malloc(sizeof(v1_pod_failure_policy_on_exit_codes_requirement_t));
    if (!v1_pod_failure_policy_on_exit_codes_requirement_local_var) {
        return NULL;
    }
    v1_pod_failure_policy_on_exit_codes_requirement_local_var->container_name = container_name;
    v1_pod_failure_policy_on_exit_codes_requirement_local_var->_operator = _operator;
    v1_pod_failure_policy_on_exit_codes_requirement_local_var->values = values;

    v1_pod_failure_policy_on_exit_codes_requirement_local_var->_library_owned = 1;
    return v1_pod_failure_policy_on_exit_codes_requirement_local_var;
}

__attribute__((deprecated)) v1_pod_failure_policy_on_exit_codes_requirement_t *v1_pod_failure_policy_on_exit_codes_requirement_create(
    char *container_name,
    char *_operator,
    list_t *values
    ) {
    return v1_pod_failure_policy_on_exit_codes_requirement_create_internal (
        container_name,
        _operator,
        values
        );
}

void v1_pod_failure_policy_on_exit_codes_requirement_free(v1_pod_failure_policy_on_exit_codes_requirement_t *v1_pod_failure_policy_on_exit_codes_requirement) {
    if(NULL == v1_pod_failure_policy_on_exit_codes_requirement){
        return ;
    }
    if(v1_pod_failure_policy_on_exit_codes_requirement->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_pod_failure_policy_on_exit_codes_requirement_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_pod_failure_policy_on_exit_codes_requirement->container_name) {
        free(v1_pod_failure_policy_on_exit_codes_requirement->container_name);
        v1_pod_failure_policy_on_exit_codes_requirement->container_name = NULL;
    }
    if (v1_pod_failure_policy_on_exit_codes_requirement->_operator) {
        free(v1_pod_failure_policy_on_exit_codes_requirement->_operator);
        v1_pod_failure_policy_on_exit_codes_requirement->_operator = NULL;
    }
    if (v1_pod_failure_policy_on_exit_codes_requirement->values) {
        list_ForEach(listEntry, v1_pod_failure_policy_on_exit_codes_requirement->values) {
            free(listEntry->data);
        }
        list_freeList(v1_pod_failure_policy_on_exit_codes_requirement->values);
        v1_pod_failure_policy_on_exit_codes_requirement->values = NULL;
    }
    free(v1_pod_failure_policy_on_exit_codes_requirement);
}

cJSON *v1_pod_failure_policy_on_exit_codes_requirement_convertToJSON(v1_pod_failure_policy_on_exit_codes_requirement_t *v1_pod_failure_policy_on_exit_codes_requirement) {
    cJSON *item = cJSON_CreateObject();

    // v1_pod_failure_policy_on_exit_codes_requirement->container_name
    if(v1_pod_failure_policy_on_exit_codes_requirement->container_name) {
    if(cJSON_AddStringToObject(item, "containerName", v1_pod_failure_policy_on_exit_codes_requirement->container_name) == NULL) {
    goto fail; //String
    }
    }


    // v1_pod_failure_policy_on_exit_codes_requirement->_operator
    if (!v1_pod_failure_policy_on_exit_codes_requirement->_operator) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "operator", v1_pod_failure_policy_on_exit_codes_requirement->_operator) == NULL) {
    goto fail; //String
    }


    // v1_pod_failure_policy_on_exit_codes_requirement->values
    if (!v1_pod_failure_policy_on_exit_codes_requirement->values) {
        goto fail;
    }
    cJSON *values = cJSON_AddArrayToObject(item, "values");
    if(values == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *valuesListEntry;
    list_ForEach(valuesListEntry, v1_pod_failure_policy_on_exit_codes_requirement->values) {
    if(cJSON_AddNumberToObject(values, "", *(double *)valuesListEntry->data) == NULL)
    {
        goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_pod_failure_policy_on_exit_codes_requirement_t *v1_pod_failure_policy_on_exit_codes_requirement_parseFromJSON(cJSON *v1_pod_failure_policy_on_exit_codes_requirementJSON){

    v1_pod_failure_policy_on_exit_codes_requirement_t *v1_pod_failure_policy_on_exit_codes_requirement_local_var = NULL;

    // define the local list for v1_pod_failure_policy_on_exit_codes_requirement->values
    list_t *valuesList = NULL;

    // v1_pod_failure_policy_on_exit_codes_requirement->container_name
    cJSON *container_name = cJSON_GetObjectItemCaseSensitive(v1_pod_failure_policy_on_exit_codes_requirementJSON, "containerName");
    if (cJSON_IsNull(container_name)) {
        container_name = NULL;
    }
    if (container_name) { 
    if(!cJSON_IsString(container_name) && !cJSON_IsNull(container_name))
    {
    goto end; //String
    }
    }

    // v1_pod_failure_policy_on_exit_codes_requirement->_operator
    cJSON *_operator = cJSON_GetObjectItemCaseSensitive(v1_pod_failure_policy_on_exit_codes_requirementJSON, "operator");
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

    // v1_pod_failure_policy_on_exit_codes_requirement->values
    cJSON *values = cJSON_GetObjectItemCaseSensitive(v1_pod_failure_policy_on_exit_codes_requirementJSON, "values");
    if (cJSON_IsNull(values)) {
        values = NULL;
    }
    if (!values) {
        goto end;
    }

    
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


    v1_pod_failure_policy_on_exit_codes_requirement_local_var = v1_pod_failure_policy_on_exit_codes_requirement_create_internal (
        container_name && !cJSON_IsNull(container_name) ? strdup(container_name->valuestring) : NULL,
        strdup(_operator->valuestring),
        valuesList
        );

    return v1_pod_failure_policy_on_exit_codes_requirement_local_var;
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
