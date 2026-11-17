#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_json_patch.h"



static v1_json_patch_t *v1_json_patch_create_internal(
    char *expression
    ) {
    v1_json_patch_t *v1_json_patch_local_var = malloc(sizeof(v1_json_patch_t));
    if (!v1_json_patch_local_var) {
        return NULL;
    }
    memset(v1_json_patch_local_var, 0, sizeof(v1_json_patch_t));
    v1_json_patch_local_var->_library_owned = 1;
    v1_json_patch_local_var->expression = expression;
    return v1_json_patch_local_var;
}

__attribute__((deprecated)) v1_json_patch_t *v1_json_patch_create(
    char *expression
    ) {
    v1_json_patch_t *result = v1_json_patch_create_internal (
        expression
        );
    if (!result) {
    }
    return result;
}

void v1_json_patch_free(v1_json_patch_t *v1_json_patch) {
    if(NULL == v1_json_patch){
        return ;
    }
    if(v1_json_patch->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_json_patch_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_json_patch->expression) {
        free(v1_json_patch->expression);
        v1_json_patch->expression = NULL;
    }
    free(v1_json_patch);
}

cJSON *v1_json_patch_convertToJSON(v1_json_patch_t *v1_json_patch) {
    cJSON *item = cJSON_CreateObject();

    // v1_json_patch->expression
    if(v1_json_patch->expression) {
    if(cJSON_AddStringToObject(item, "expression", v1_json_patch->expression) == NULL) {
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

v1_json_patch_t *v1_json_patch_parseFromJSON(cJSON *v1_json_patchJSON){

    v1_json_patch_t *v1_json_patch_local_var = NULL;

    char *expression_local_str = NULL;

    // v1_json_patch->expression
    cJSON *expression = cJSON_GetObjectItemCaseSensitive(v1_json_patchJSON, "expression");
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

    v1_json_patch_local_var = v1_json_patch_create_internal (
        expression_local_str
        );

    if (!v1_json_patch_local_var) {
        goto end;
    }

    return v1_json_patch_local_var;
end:
    if (expression_local_str) {
        free(expression_local_str);
        expression_local_str = NULL;
    }
    return NULL;

}
