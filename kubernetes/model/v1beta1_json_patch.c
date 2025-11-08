#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_json_patch.h"



static v1beta1_json_patch_t *v1beta1_json_patch_create_internal(
    char *expression
    ) {
    v1beta1_json_patch_t *v1beta1_json_patch_local_var = malloc(sizeof(v1beta1_json_patch_t));
    if (!v1beta1_json_patch_local_var) {
        return NULL;
    }
    v1beta1_json_patch_local_var->expression = expression;

    v1beta1_json_patch_local_var->_library_owned = 1;
    return v1beta1_json_patch_local_var;
}

__attribute__((deprecated)) v1beta1_json_patch_t *v1beta1_json_patch_create(
    char *expression
    ) {
    return v1beta1_json_patch_create_internal (
        expression
        );
}

void v1beta1_json_patch_free(v1beta1_json_patch_t *v1beta1_json_patch) {
    if(NULL == v1beta1_json_patch){
        return ;
    }
    if(v1beta1_json_patch->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta1_json_patch_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_json_patch->expression) {
        free(v1beta1_json_patch->expression);
        v1beta1_json_patch->expression = NULL;
    }
    free(v1beta1_json_patch);
}

cJSON *v1beta1_json_patch_convertToJSON(v1beta1_json_patch_t *v1beta1_json_patch) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_json_patch->expression
    if(v1beta1_json_patch->expression) {
    if(cJSON_AddStringToObject(item, "expression", v1beta1_json_patch->expression) == NULL) {
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

v1beta1_json_patch_t *v1beta1_json_patch_parseFromJSON(cJSON *v1beta1_json_patchJSON){

    v1beta1_json_patch_t *v1beta1_json_patch_local_var = NULL;

    // v1beta1_json_patch->expression
    cJSON *expression = cJSON_GetObjectItemCaseSensitive(v1beta1_json_patchJSON, "expression");
    if (cJSON_IsNull(expression)) {
        expression = NULL;
    }
    if (expression) { 
    if(!cJSON_IsString(expression) && !cJSON_IsNull(expression))
    {
    goto end; //String
    }
    }


    v1beta1_json_patch_local_var = v1beta1_json_patch_create_internal (
        expression && !cJSON_IsNull(expression) ? strdup(expression->valuestring) : NULL
        );

    return v1beta1_json_patch_local_var;
end:
    return NULL;

}
