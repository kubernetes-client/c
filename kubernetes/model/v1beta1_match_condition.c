#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_match_condition.h"



static v1beta1_match_condition_t *v1beta1_match_condition_create_internal(
    char *expression,
    char *name
    ) {
    v1beta1_match_condition_t *v1beta1_match_condition_local_var = malloc(sizeof(v1beta1_match_condition_t));
    if (!v1beta1_match_condition_local_var) {
        return NULL;
    }
    memset(v1beta1_match_condition_local_var, 0, sizeof(v1beta1_match_condition_t));
    v1beta1_match_condition_local_var->_library_owned = 1;
    v1beta1_match_condition_local_var->expression = expression;
    v1beta1_match_condition_local_var->name = name;
    return v1beta1_match_condition_local_var;
}

__attribute__((deprecated)) v1beta1_match_condition_t *v1beta1_match_condition_create(
    char *expression,
    char *name
    ) {
    v1beta1_match_condition_t *result = v1beta1_match_condition_create_internal (
        expression,
        name
        );
    if (!result) {
    }
    return result;
}

void v1beta1_match_condition_free(v1beta1_match_condition_t *v1beta1_match_condition) {
    if(NULL == v1beta1_match_condition){
        return ;
    }
    if(v1beta1_match_condition->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta1_match_condition_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_match_condition->expression) {
        free(v1beta1_match_condition->expression);
        v1beta1_match_condition->expression = NULL;
    }
    if (v1beta1_match_condition->name) {
        free(v1beta1_match_condition->name);
        v1beta1_match_condition->name = NULL;
    }
    free(v1beta1_match_condition);
}

cJSON *v1beta1_match_condition_convertToJSON(v1beta1_match_condition_t *v1beta1_match_condition) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_match_condition->expression
    if (!v1beta1_match_condition->expression) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "expression", v1beta1_match_condition->expression) == NULL) {
    goto fail; //String
    }


    // v1beta1_match_condition->name
    if (!v1beta1_match_condition->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", v1beta1_match_condition->name) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta1_match_condition_t *v1beta1_match_condition_parseFromJSON(cJSON *v1beta1_match_conditionJSON){

    v1beta1_match_condition_t *v1beta1_match_condition_local_var = NULL;

    char *expression_local_str = NULL;

    char *name_local_str = NULL;

    // v1beta1_match_condition->expression
    cJSON *expression = cJSON_GetObjectItemCaseSensitive(v1beta1_match_conditionJSON, "expression");
    if (cJSON_IsNull(expression)) {
        expression = NULL;
    }
    if (!expression) {
        goto end;
    }

    
    if(!cJSON_IsString(expression))
    {
    goto end; //String
    }

    // v1beta1_match_condition->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(v1beta1_match_conditionJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }


    if (expression && !cJSON_IsNull(expression)) expression_local_str = strdup(expression->valuestring);
    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);

    v1beta1_match_condition_local_var = v1beta1_match_condition_create_internal (
        expression_local_str,
        name_local_str
        );

    if (!v1beta1_match_condition_local_var) {
        goto end;
    }

    return v1beta1_match_condition_local_var;
end:
    if (expression_local_str) {
        free(expression_local_str);
        expression_local_str = NULL;
    }
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    return NULL;

}
