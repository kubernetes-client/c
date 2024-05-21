#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_variable.h"



v1_variable_t *v1_variable_create(
    char *expression,
    char *name
    ) {
    v1_variable_t *v1_variable_local_var = malloc(sizeof(v1_variable_t));
    if (!v1_variable_local_var) {
        return NULL;
    }
    v1_variable_local_var->expression = expression;
    v1_variable_local_var->name = name;

    return v1_variable_local_var;
}


void v1_variable_free(v1_variable_t *v1_variable) {
    if(NULL == v1_variable){
        return ;
    }
    listEntry_t *listEntry;
    if (v1_variable->expression) {
        free(v1_variable->expression);
        v1_variable->expression = NULL;
    }
    if (v1_variable->name) {
        free(v1_variable->name);
        v1_variable->name = NULL;
    }
    free(v1_variable);
}

cJSON *v1_variable_convertToJSON(v1_variable_t *v1_variable) {
    cJSON *item = cJSON_CreateObject();

    // v1_variable->expression
    if (!v1_variable->expression) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "expression", v1_variable->expression) == NULL) {
    goto fail; //String
    }


    // v1_variable->name
    if (!v1_variable->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1_variable->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_variable_t *v1_variable_parseFromJSON(cJSON *v1_variableJSON){

    v1_variable_t *v1_variable_local_var = NULL;

    // v1_variable->expression
    cJSON *expression = cJSON_GetObjectItemCaseSensitive(v1_variableJSON, "expression");
    if (!expression) {
        goto end;
    }

    
    if(!cJSON_IsString(expression))
    {
    goto end; //String
    }

    // v1_variable->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1_variableJSON, "name");
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }


    v1_variable_local_var = v1_variable_create (
        strdup(expression->valuestring),
        strdup(name->valuestring)
        );

    return v1_variable_local_var;
end:
    return NULL;

}
