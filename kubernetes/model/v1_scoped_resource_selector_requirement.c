#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_scoped_resource_selector_requirement.h"


char* _operatorv1_scoped_resource_selector_requirement_ToString(kubernetes_v1_scoped_resource_selector_requirement_OPERATOR_e _operator) {
    char* _operatorArray[] =  { "NULL", "DoesNotExist", "Exists", "In", "NotIn" };
	return _operatorArray[_operator];
}

kubernetes_v1_scoped_resource_selector_requirement_OPERATOR_e _operatorv1_scoped_resource_selector_requirement_FromString(char* _operator){
    int stringToReturn = 0;
    char *_operatorArray[] =  { "NULL", "DoesNotExist", "Exists", "In", "NotIn" };
    size_t sizeofArray = sizeof(_operatorArray) / sizeof(_operatorArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(_operator, _operatorArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}
char* scope_namev1_scoped_resource_selector_requirement_ToString(kubernetes_v1_scoped_resource_selector_requirement_SCOPENAME_e scope_name) {
    char* scope_nameArray[] =  { "NULL", "BestEffort", "CrossNamespacePodAffinity", "NotBestEffort", "NotTerminating", "PriorityClass", "Terminating" };
	return scope_nameArray[scope_name];
}

kubernetes_v1_scoped_resource_selector_requirement_SCOPENAME_e scope_namev1_scoped_resource_selector_requirement_FromString(char* scope_name){
    int stringToReturn = 0;
    char *scope_nameArray[] =  { "NULL", "BestEffort", "CrossNamespacePodAffinity", "NotBestEffort", "NotTerminating", "PriorityClass", "Terminating" };
    size_t sizeofArray = sizeof(scope_nameArray) / sizeof(scope_nameArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(scope_name, scope_nameArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

v1_scoped_resource_selector_requirement_t *v1_scoped_resource_selector_requirement_create(
    kubernetes_v1_scoped_resource_selector_requirement_OPERATOR_e _operator,
    kubernetes_v1_scoped_resource_selector_requirement_SCOPENAME_e scope_name,
    list_t *values
    ) {
    v1_scoped_resource_selector_requirement_t *v1_scoped_resource_selector_requirement_local_var = malloc(sizeof(v1_scoped_resource_selector_requirement_t));
    if (!v1_scoped_resource_selector_requirement_local_var) {
        return NULL;
    }
    v1_scoped_resource_selector_requirement_local_var->_operator = _operator;
    v1_scoped_resource_selector_requirement_local_var->scope_name = scope_name;
    v1_scoped_resource_selector_requirement_local_var->values = values;

    return v1_scoped_resource_selector_requirement_local_var;
}


void v1_scoped_resource_selector_requirement_free(v1_scoped_resource_selector_requirement_t *v1_scoped_resource_selector_requirement) {
    if(NULL == v1_scoped_resource_selector_requirement){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_scoped_resource_selector_requirement->values) {
        list_ForEach(listEntry, v1_scoped_resource_selector_requirement->values) {
            free(listEntry->data);
        }
        list_freeList(v1_scoped_resource_selector_requirement->values);
        v1_scoped_resource_selector_requirement->values = NULL;
    }
    free(v1_scoped_resource_selector_requirement);
}

cJSON *v1_scoped_resource_selector_requirement_convertToJSON(v1_scoped_resource_selector_requirement_t *v1_scoped_resource_selector_requirement) {
    cJSON *item = cJSON_CreateObject();

    // v1_scoped_resource_selector_requirement->_operator
    if (kubernetes_v1_scoped_resource_selector_requirement_OPERATOR_NULL == v1_scoped_resource_selector_requirement->_operator) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "operator", _operatorv1_scoped_resource_selector_requirement_ToString(v1_scoped_resource_selector_requirement->_operator)) == NULL)
    {
    goto fail; //Enum
    }


    // v1_scoped_resource_selector_requirement->scope_name
    if (kubernetes_v1_scoped_resource_selector_requirement_SCOPENAME_NULL == v1_scoped_resource_selector_requirement->scope_name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "scopeName", scope_namev1_scoped_resource_selector_requirement_ToString(v1_scoped_resource_selector_requirement->scope_name)) == NULL)
    {
    goto fail; //Enum
    }


    // v1_scoped_resource_selector_requirement->values
    if(v1_scoped_resource_selector_requirement->values) {
    cJSON *values = cJSON_AddArrayToObject(item, "values");
    if(values == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *valuesListEntry;
    list_ForEach(valuesListEntry, v1_scoped_resource_selector_requirement->values) {
    if(cJSON_AddStringToObject(values, "", (char*)valuesListEntry->data) == NULL)
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

v1_scoped_resource_selector_requirement_t *v1_scoped_resource_selector_requirement_parseFromJSON(cJSON *v1_scoped_resource_selector_requirementJSON){

    v1_scoped_resource_selector_requirement_t *v1_scoped_resource_selector_requirement_local_var = NULL;

    // define the local list for v1_scoped_resource_selector_requirement->values
    list_t *valuesList = NULL;

    // v1_scoped_resource_selector_requirement->_operator
    cJSON *_operator = cJSON_GetObjectItemCaseSensitive(v1_scoped_resource_selector_requirementJSON, "operator");
    if (!_operator) {
        goto end;
    }

    kubernetes_v1_scoped_resource_selector_requirement_OPERATOR_e _operatorVariable;
    
    if(!cJSON_IsString(_operator))
    {
    goto end; //Enum
    }
    _operatorVariable = _operatorv1_scoped_resource_selector_requirement_FromString(_operator->valuestring);

    // v1_scoped_resource_selector_requirement->scope_name
    cJSON *scope_name = cJSON_GetObjectItemCaseSensitive(v1_scoped_resource_selector_requirementJSON, "scopeName");
    if (!scope_name) {
        goto end;
    }

    kubernetes_v1_scoped_resource_selector_requirement_SCOPENAME_e scope_nameVariable;
    
    if(!cJSON_IsString(scope_name))
    {
    goto end; //Enum
    }
    scope_nameVariable = scope_namev1_scoped_resource_selector_requirement_FromString(scope_name->valuestring);

    // v1_scoped_resource_selector_requirement->values
    cJSON *values = cJSON_GetObjectItemCaseSensitive(v1_scoped_resource_selector_requirementJSON, "values");
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


    v1_scoped_resource_selector_requirement_local_var = v1_scoped_resource_selector_requirement_create (
        _operatorVariable,
        scope_nameVariable,
        values ? valuesList : NULL
        );

    return v1_scoped_resource_selector_requirement_local_var;
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
