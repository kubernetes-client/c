#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1beta1_expression_warning.h"



static v1beta1_expression_warning_t *v1beta1_expression_warning_create_internal(
    char *field_ref,
    char *warning
    ) {
    v1beta1_expression_warning_t *v1beta1_expression_warning_local_var = malloc(sizeof(v1beta1_expression_warning_t));
    if (!v1beta1_expression_warning_local_var) {
        return NULL;
    }
    v1beta1_expression_warning_local_var->field_ref = field_ref;
    v1beta1_expression_warning_local_var->warning = warning;

    v1beta1_expression_warning_local_var->_library_owned = 1;
    return v1beta1_expression_warning_local_var;
}

__attribute__((deprecated)) v1beta1_expression_warning_t *v1beta1_expression_warning_create(
    char *field_ref,
    char *warning
    ) {
    return v1beta1_expression_warning_create_internal (
        field_ref,
        warning
        );
}

void v1beta1_expression_warning_free(v1beta1_expression_warning_t *v1beta1_expression_warning) {
    if(NULL == v1beta1_expression_warning){
        return ;
    }
    if(v1beta1_expression_warning->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1beta1_expression_warning_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1beta1_expression_warning->field_ref) {
        free(v1beta1_expression_warning->field_ref);
        v1beta1_expression_warning->field_ref = NULL;
    }
    if (v1beta1_expression_warning->warning) {
        free(v1beta1_expression_warning->warning);
        v1beta1_expression_warning->warning = NULL;
    }
    free(v1beta1_expression_warning);
}

cJSON *v1beta1_expression_warning_convertToJSON(v1beta1_expression_warning_t *v1beta1_expression_warning) {
    cJSON *item = cJSON_CreateObject();

    // v1beta1_expression_warning->field_ref
    if (!v1beta1_expression_warning->field_ref) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "fieldRef", v1beta1_expression_warning->field_ref) == NULL) {
    goto fail; //String
    }


    // v1beta1_expression_warning->warning
    if (!v1beta1_expression_warning->warning) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "warning", v1beta1_expression_warning->warning) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1beta1_expression_warning_t *v1beta1_expression_warning_parseFromJSON(cJSON *v1beta1_expression_warningJSON){

    v1beta1_expression_warning_t *v1beta1_expression_warning_local_var = NULL;

    // v1beta1_expression_warning->field_ref
    cJSON *field_ref = cJSON_GetObjectItemCaseSensitive(v1beta1_expression_warningJSON, "fieldRef");
    if (cJSON_IsNull(field_ref)) {
        field_ref = NULL;
    }
    if (!field_ref) {
        goto end;
    }

    
    if(!cJSON_IsString(field_ref))
    {
    goto end; //String
    }

    // v1beta1_expression_warning->warning
    cJSON *warning = cJSON_GetObjectItemCaseSensitive(v1beta1_expression_warningJSON, "warning");
    if (cJSON_IsNull(warning)) {
        warning = NULL;
    }
    if (!warning) {
        goto end;
    }

    
    if(!cJSON_IsString(warning))
    {
    goto end; //String
    }


    v1beta1_expression_warning_local_var = v1beta1_expression_warning_create_internal (
        strdup(field_ref->valuestring),
        strdup(warning->valuestring)
        );

    return v1beta1_expression_warning_local_var;
end:
    return NULL;

}
