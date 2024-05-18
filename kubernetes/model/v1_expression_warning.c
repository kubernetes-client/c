#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "v1_expression_warning.h"



v1_expression_warning_t *v1_expression_warning_create(
    char *field_ref,
    char *warning
    ) {
    v1_expression_warning_t *v1_expression_warning_local_var = malloc(sizeof(v1_expression_warning_t));
    if (!v1_expression_warning_local_var) {
        return NULL;
    }
    v1_expression_warning_local_var->field_ref = field_ref;
    v1_expression_warning_local_var->warning = warning;

    return v1_expression_warning_local_var;
}


void v1_expression_warning_free(v1_expression_warning_t *v1_expression_warning) {
    if(NULL == v1_expression_warning){
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

    // v1_expression_warning->field_ref
    cJSON *field_ref = cJSON_GetObjectItemCaseSensitive(v1_expression_warningJSON, "fieldRef");
    if (!field_ref) {
        goto end;
    }

    
    if(!cJSON_IsString(field_ref))
    {
    goto end; //String
    }

    // v1_expression_warning->warning
    cJSON *warning = cJSON_GetObjectItemCaseSensitive(v1_expression_warningJSON, "warning");
    if (!warning) {
        goto end;
    }

    
    if(!cJSON_IsString(warning))
    {
    goto end; //String
    }


    v1_expression_warning_local_var = v1_expression_warning_create (
        strdup(field_ref->valuestring),
        strdup(warning->valuestring)
        );

    return v1_expression_warning_local_var;
end:
    return NULL;

}
