#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_expression_warning.h"



static v1_expression_warning_t *v1_expression_warning_create_internal(
    char *field_ref,
    char *warning
    ) {
    v1_expression_warning_t *v1_expression_warning_local_var = malloc(sizeof(v1_expression_warning_t));
    if (!v1_expression_warning_local_var) {
        return NULL;
    }
    memset(v1_expression_warning_local_var, 0, sizeof(v1_expression_warning_t));
    v1_expression_warning_local_var->_library_owned = 1;
    v1_expression_warning_local_var->field_ref = field_ref;
    v1_expression_warning_local_var->warning = warning;
    return v1_expression_warning_local_var;
}

__attribute__((deprecated)) v1_expression_warning_t *v1_expression_warning_create(
    char *field_ref,
    char *warning
    ) {
    v1_expression_warning_t *result = v1_expression_warning_create_internal (
        field_ref,
        warning
        );
    if (!result) {
    }
    return result;
}

void v1_expression_warning_free(v1_expression_warning_t *v1_expression_warning) {
    if(NULL == v1_expression_warning){
        return ;
    }
    if(v1_expression_warning->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "v1_expression_warning_free");
        return ;
    }
    listEntry_t *listEntry;
    if (v1_expression_warning->field_ref) {
        free(v1_expression_warning->field_ref);
        v1_expression_warning->field_ref = NULL;
    }
    if (v1_expression_warning->warning) {
        free(v1_expression_warning->warning);
        v1_expression_warning->warning = NULL;
    }
    free(v1_expression_warning);
}

cJSON *v1_expression_warning_convertToJSON(v1_expression_warning_t *v1_expression_warning) {
    cJSON *item = cJSON_CreateObject();

    // v1_expression_warning->field_ref
    if (!v1_expression_warning->field_ref) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "fieldRef", v1_expression_warning->field_ref) == NULL) {
    goto fail; //String
    }


    // v1_expression_warning->warning
    if (!v1_expression_warning->warning) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "warning", v1_expression_warning->warning) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

v1_expression_warning_t *v1_expression_warning_parseFromJSON(cJSON *v1_expression_warningJSON){

    v1_expression_warning_t *v1_expression_warning_local_var = NULL;

    char *field_ref_local_str = NULL;

    char *warning_local_str = NULL;

    // v1_expression_warning->field_ref
    cJSON *field_ref = cJSON_GetObjectItemCaseSensitive(v1_expression_warningJSON, "fieldRef");
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

    // v1_expression_warning->warning
    cJSON *warning = cJSON_GetObjectItemCaseSensitive(v1_expression_warningJSON, "warning");
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


    if (field_ref && !cJSON_IsNull(field_ref)) field_ref_local_str = strdup(field_ref->valuestring);
    if (warning && !cJSON_IsNull(warning)) warning_local_str = strdup(warning->valuestring);

    v1_expression_warning_local_var = v1_expression_warning_create_internal (
        field_ref_local_str,
        warning_local_str
        );

    if (!v1_expression_warning_local_var) {
        goto end;
    }

    return v1_expression_warning_local_var;
end:
    if (field_ref_local_str) {
        free(field_ref_local_str);
        field_ref_local_str = NULL;
    }
    if (warning_local_str) {
        free(warning_local_str);
        warning_local_str = NULL;
    }
    return NULL;

}
