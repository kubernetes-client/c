#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_apply_configuration.h"



static v1_apply_configuration_t *v1_apply_configuration_create_internal(
    char *expression
    ) {
    v1_apply_configuration_t *v1_apply_configuration_local_var = malloc(sizeof(v1_apply_configuration_t));
    if (!v1_apply_configuration_local_var) {
        return NULL;
    }
    memset(v1_apply_configuration_local_var, 0, sizeof(v1_apply_configuration_t));
    v1_apply_configuration_local_var->_library_owned = 1;
    v1_apply_configuration_local_var->expression = expression;
    return v1_apply_configuration_local_var;
}

__attribute__((deprecated)) v1_apply_configuration_t *v1_apply_configuration_create(
    char *expression
    ) {
    v1_apply_configuration_t *result = v1_apply_configuration_create_internal (
        expression
        );
    if (!result) {
    }
    return result;
}

void v1_apply_configuration_free(v1_apply_configuration_t *v1_apply_configuration) {
    if(NULL == v1_apply_configuration){
        return ;
    }
    if(v1_apply_configuration->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_apply_configuration_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_apply_configuration->expression) {
        free(v1_apply_configuration->expression);
        v1_apply_configuration->expression = NULL;
    }
    free(v1_apply_configuration);
}

cJSON *v1_apply_configuration_convertToJSON(v1_apply_configuration_t *v1_apply_configuration) {
    cJSON *item = cJSON_CreateObject();

    // v1_apply_configuration->expression
    if(v1_apply_configuration->expression) {
    if(cJSON_AddStringToObject(item, "expression", v1_apply_configuration->expression) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_apply_configuration_t *v1_apply_configuration_parseFromJSON(cJSON *v1_apply_configurationJSON){

    v1_apply_configuration_t *v1_apply_configuration_local_var = NULL;

    char *expression_local_str = NULL;

    // v1_apply_configuration->expression
    cJSON *expression = cJSON_GetObjectItemCaseSensitive(v1_apply_configurationJSON, "expression");
    if (cJSON_IsNull(expression)) {
        expression = NULL;
    }
    if (expression) { 
    if(!cJSON_IsString(expression) && !cJSON_IsNull(expression))
    {
    goto end; //String
    }
    }


    if (expression && !cJSON_IsNull(expression)) expression_local_str = strdup(expression->valuestring);

    v1_apply_configuration_local_var = v1_apply_configuration_create_internal (
        expression_local_str
        );

    if (!v1_apply_configuration_local_var) {
        goto end;
    }

    return v1_apply_configuration_local_var;
end:
    if (expression_local_str) {
        free(expression_local_str);
        expression_local_str = NULL;
    }
    return NULL;

}
